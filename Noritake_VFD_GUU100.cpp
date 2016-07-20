///////////////////////////////////////////////////////////////////////////////
//
//  Noritake GU128X64E-U100 VFD Display Driver Library for Arduino
//  Copyright (c) 2012, 2015 Roger A. Krupski <rakrupski@verizon.net>
//
//  Last update: 19 July 2016
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program. If not, see <http://www.gnu.org/licenses/>.
//
///////////////////////////////////////////////////////////////////////////////

#include <Noritake_VFD_GUU100.h>

// init driver variables and setup display
void Noritake_VFD_GUU100::init (void)
{
	init (128, 64);
}

// init driver variables and setup display
void Noritake_VFD_GUU100::init (uint8_t width, uint8_t height)
{
	_delay_usec (250000); // 250 msec time delay after powerup (GU128X64E manual pg. 17)
	_initPort(); // initialize the I/O port (set in .h file)
	_displayWidth = width; // init display...
	_displayHeight = height; // ... dimensions
	_firstChar = 0; // zero out font info
	_fontWidth = 0; // font bare pixel width
	_fontHeight = 0; // font bare pixel height
	_fontHGap = 0; // inter-char gap (horizontal)
	_fontVGap = 0; // inter-char gap (vertical)
	_bytesPerChar = 0; // how many bytes in each char image
	_cur_x = 0; // current X position
	_cur_y = 0; // current Y position
	_cur_z = 0; // current scroll offset
	_save_x = 0; // saved X position
	_save_y = 0; // saved Y position
	_next_x = 0; // x size of character cell
	_next_y = 0; // y size of character cell
	_invert = 0; // display invert yes/no
	_fontData = 0; // invalidate font address pointer
	_fontStart = 0; // invalidate font start pointer
	setDisplay (1); // turn display on
	setBrightness (100); // default brightness and cathode on
	clearScreen(); // clear screen
}

// turn display on or off (filament stays on)
void Noritake_VFD_GUU100::setDisplay (uint8_t on)
{
	_writeDisplay (SETDISP | (on ? 0x01 : 0x00));
}

// set the display brightness to one of 8 levels:
// note: zero percent turns off the VFD filament to save power
uint8_t Noritake_VFD_GUU100::setBrightness (uint8_t percent)
{
	// brightness calculation multiplies all numbers
	// by 10 so that we can do fractional math (i.e.
	// 125 is really 12.5)
	uint16_t i = 1000; // 100 * 10
	percent = (percent > 100) ? 100 : percent;
	_displayBright = 7;

	while ((i -= 125) && _displayBright) {
		if ((percent * 10) > (i + 5)) { // 0.5 rounding
			_displayBright--;
		}
	}

	// brightness 0 turns off the filament
	_writePort (FUNC_SET, 0); // function set
	_writePort (percent ? (_displayBright | SETBRITE | CATHODE) : ((_displayBright | SETBRITE) & ~CATHODE), 0); // send brightness command
	return _displayBright;
}

// set scroll (vertical roll) offset
void Noritake_VFD_GUU100::setScroll (int z)
{
	_setScroll (z);
}

// get scroll (vertical roll) offset
int Noritake_VFD_GUU100::getScroll (void)
{
	return (_cur_z);
}

// set cursor position to a (possibly fractional) column and line
void Noritake_VFD_GUU100::setLine (double x, double y)
{
	_setCursor (((x * _next_x) + 0.5), ((y * _next_y) + 0.5));
}

// get cursor position as a (possibly fractional) column and line
void Noritake_VFD_GUU100::getLine (double &x, double &y)
{
	x = (double) (_cur_x / _next_x);
	y = (double) (_cur_y / _next_y);
}

// set cursor coordinates to X,Y
void Noritake_VFD_GUU100::setCursor (int x, int y)
{
	_setCursor (x, y);
}

// get current cursor X,Y coordinates
void Noritake_VFD_GUU100::getCursor (int &x, int &y)
{
	x = _cur_x;
	y = _cur_y;
}

void Noritake_VFD_GUU100::pushCursor (void)
{
	getCursor (_save_x, _cur_x);
}

void Noritake_VFD_GUU100::popCursor (void)
{
	setCursor (_save_x, _save_y);
}

// set dot at absolute address 0...8191
void Noritake_VFD_GUU100::setPixel (uint16_t addr, uint8_t on)
{
	int x;
	int y;
	y = (addr / _displayWidth);
	x = (addr - (y * _displayWidth));
	_setDot (x, y, on ? 1 : 0);
}

// get state of dot at absolute address 0...8191
uint8_t Noritake_VFD_GUU100::getPixel (uint16_t addr)
{
	int x;
	int y;
	y = (addr / _displayWidth);
	x = (addr - (y * _displayWidth));
	return getDot (x, y) ? 1 : 0;
}

// set dot at X,Y on or off
void Noritake_VFD_GUU100::setDot (int x, int y, uint8_t on)
{
	_setDot (x, y, on);
}

// get state of dot at X,Y
uint8_t Noritake_VFD_GUU100::getDot (int x, int y)
{
	return (_getBits (x, y) & (1UL << (y % 8))) ? 1 : 0;
}

// get byte at X,Y
uint8_t Noritake_VFD_GUU100::getByte (int x, int y)
{
	_setCursor (x, y);
	return _readData();
}

// set byte at X,Y
void Noritake_VFD_GUU100::setByte (int x, int y, uint8_t c)
{
	_setCursor (x, y);
	_writeData (c);
}

// this makes drawing normal or inverted (negative)
void Noritake_VFD_GUU100::setInvert (uint8_t inv)
{
	_invert = inv ? 1 : 0;
}

// this inverts (negative) the entire screen
// kinda corny, but someone may need it.
void Noritake_VFD_GUU100::invertScreen (void)
{
	int x, y;
	uint8_t c;
	uint16_t n = (_displayWidth * (_displayHeight / 8));

	while (n--) {
		x = _cur_x;
		y = _cur_y;
		c = ~_readData(); // read a byte and flip it
		_setCursor (x, y); // set cursor
		_writeData (c); // write it back flipped
	}
}

uint8_t Noritake_VFD_GUU100::clear (void)
{
	return clearScreen (0);
}

uint8_t Noritake_VFD_GUU100::clearScreen (void)
{
	return clearScreen (0);
}

// clear the screen by filling it with 0x00.
// note the fill char can be optionally specified in
// order to create special(?) effects.
uint8_t Noritake_VFD_GUU100::clearScreen (uint8_t pattern)
{
	uint16_t n = (_displayWidth * (_displayHeight / 8));
	_setScroll (0);
	_setCursor (0, 0);

	while (n--) {
		_writeData (pattern); // erase screen
	}

	return pattern;
}

// get screen block at X,Y starting at (X, Y)
uint16_t Noritake_VFD_GUU100::getBlock (uint8_t *data, int x1, int y1, uint8_t width, uint8_t height)
{
	uint8_t *ptr;
	int x2, y2;
	y1 &= ~0b111; // mask bottom 3 bits
	ptr = data;

	if (((height - y1) > _displayHeight) || ((width - x1) > _displayWidth)) {
		return -1;
	}

	for (y2 = y1; y2 < (height - y1); y2 += 8) {
		for (x2 = x1; x2 < (width - x1); x2++) {
			*ptr++ = getByte (x2, y2); // get data
		}
	}

	return (ptr - data);
}

// draw an image pointed to by a 16 bit POINTER to data in PROGMEM
void Noritake_VFD_GUU100::drawImage (const uint8_t *data, int x, int y, uint8_t width, uint8_t height)
{
	drawImage (((uint32_t) data), x, y, width, height);
}

// draw an image pointed to by an absolute 32 bit address of data in PROGMEM
// (this address is obtained by using "pgm_get_far_address()" of the data in
// PROGMEM at compile time (i.e. static)). See the font files for examples on
// how "pgm_get_far_address()" is used. (You CANNOT pass it a runtime pointer,
// it only works with static compile-time objects - which sucks).
void Noritake_VFD_GUU100::drawImage (uint32_t data, int x, int y, uint8_t width, uint8_t height)
{
	uint8_t mask, mix;
	int ix, iy, y2;
	uint16_t src; // must be 16 bit because of "<< 8" operations
	uint32_t end;
	y2 = (y + height);

	if (_clip (y) == _clip (y2)) {
		mask = _bitsBetween (y, y2);

		for (ix = 0; ix < width; ix++) {
			mix = _getBits (x + ix, _clip (y));
			src = PGM_READ_BYTE (data + ix);
			src <<= (y % 8);
			src = (mix & ~mask) | (src & mask);
			_writeData (src);
		}

	} else {
		if (y == _clip (y)) {
			for (iy = y; iy < _clip (y2); iy += 8) {
				setCursor (x, iy);

				for (ix = 0; ix < width; ix++) {
					src = PGM_READ_BYTE (data + ix);
					_writeData (src);
				}

				data += width;
			}

			if (y2 != _clip (y2)) {
				mask = _bitsBetween (_clip (y2), y2);

				for (ix = 0; ix < width; ix++) {
					mix = _getBits (x + ix, _clip (y2));
					src = PGM_READ_BYTE (data + ix);
					src = (mix & ~mask) | (src & mask);
					_writeData (src);
				}
			}

		} else {
			mask = _bitsBetween (y, _align (y));
			end = ((width * height) + data);

			for (ix = 0; ix < width; ix++) {
				mix = _getBits ((x + ix), _clip (y));
				src = PGM_READ_BYTE (data + ix);
				src <<= (y % 8);
				src = (mix & ~mask) | (src & mask);
				_writeData (src);
			}

			if (_align (y) < _clip (y2)) {
				for (iy = _align (y); iy < _clip (y2); iy += 8) {
					setCursor (x, iy);

					for (ix = 0; ix < width; ix++) {
						src = PGM_READ_BYTE (data + ix) + ((data + ix < end) ? (PGM_READ_BYTE (data + ix + width) << 8) : 0);
						src >>= (_align (y) - y);
						_writeData (src);
					}

					data += width;
				}
			}

			if (_clip (y2) != y2) {
				mask = _bitsBetween (_clip (y2), y2);

				for (ix = 0; ix < width; ix++) {
					mix = _getBits (x + ix, _clip (y2));
					src = PGM_READ_BYTE (data + ix) + ((data + ix < end) ? (PGM_READ_BYTE (data + ix + width) << 8) : 0);
					src >>= (_align (y) - y);
					src = (mix & ~mask) | (src & mask);
					_writeData (src);
				}
			}
		}
	}
}

////////////////////////////////////////////////////////////////////////
// draw a polygon of any number of sides, rotated by any "angle"
// note angle "0" degrees is straight up (i.e. a triangle is
// drawn like this: /\
//                 /__\
// and the angle goes clockwise so that an angle of 90 degrees
// points the apex to the 3:00 o'clock position.
//
// TONS of thanks to Arduino forum user ROBTILLAART for helping
// me figure out a subtle problem and speeding up the code too!
// Reference: http://forum.arduino.cc/index.php?topic=343198
////////////////////////////////////////////////////////////////////////
void Noritake_VFD_GUU100::drawPolygon (int x, int y, uint8_t radius, int angle, uint8_t sides, uint8_t on)
{
	int x1, y1, x2, y2;
	double theta, inc, start;

	if (sides < 3) { // polygon must be at least 3 sides!
		return;
	}

	if (sides > 31) { // too many sides is slow and just makes a circle anyway...
		drawCircle (x, y, radius, on);
		return;
	}

	// starting angle (in radians)
	start = rad (angle - 90); // make 0 degrees straight up
	theta = start; // first vertex is at the start (of course)
	inc = ((M_PI * 2.0) / sides); // increment (in radians) to next vertex
	x2 = round ((cos (theta) * radius) + x); // get first vertex
	y2 = round ((sin (theta) * radius) + y);

	while (sides--) {
		x1 = x2; // old vertex is...
		y1 = y2; // ...the new startpoint
		theta = ((sides * inc) + start); // increment to the next vertex
		x2 = round ((cos (theta) * radius) + x); // get next vertex
		y2 = round ((sin (theta) * radius) + y);
		drawLine (x1, y1, x2, y2, on); // draw side
	}
}

// draw a vector from X,Y with radius and angle as specified. this is
// useful for drawing "analog" meters, gauges, etc...
// angle 0 degrees is straight up. increasing angles go clockwise
// (that is, 90 degrees points to the 3:00 o'clock position).
void Noritake_VFD_GUU100::drawVector (int x, int y, uint8_t radius, int angle, uint8_t on)
{
	double theta = rad (angle - 90);
	drawLine (x, y, round (cos (theta) * radius) + x, round (sin (theta) * radius) + y, on);
}

// draw a line from X1,Y1 to X2,Y2
// http://www.roguebasin.com/index.php?title=Bresenham%27s_Line_Algorithm
void Noritake_VFD_GUU100::drawLine (int x1, int y1, int x2, int y2, uint8_t on)
{
	int delta_x, delta_y, ix, iy, error;
	delta_x = (x2 - x1);
	// if x1 == x2, then it does not matter what we set here
	ix = ((delta_x > 0) - (delta_x < 0));
	delta_x = (abs (delta_x) << 1);
	delta_y = (y2 - y1);
	// if y1 == y2, then it does not matter what we set here
	iy = ((delta_y > 0) - (delta_y < 0));
	delta_y = (abs (delta_y) << 1);
	_setDot (x1, y1, on);

	if (delta_x >= delta_y) {
		// error may go below zero
		error = (delta_y - (delta_x >> 1));

		while (x1 != x2) {
			if ((error >= 0) && (error || (ix > 0))) {
				error -= delta_x;
				y1 += iy;
			}

			// else do nothing
			error += delta_y;
			x1 += ix;
			_setDot (x1, y1, on);
		}

	} else {
		// error may go below zero
		error = (delta_x - (delta_y >> 1));

		while (y1 != y2) {
			if ((error >= 0) && (error || (iy > 0))) {
				error -= delta_y;
				x1 += ix;
			}

			// else do nothing
			error += delta_x;
			y1 += iy;
			_setDot (x1, y1, on);
		}
	}
}

// draw a rectangle starting at X,Y with width and height as specified
void Noritake_VFD_GUU100::drawRect (int x1, int y1, uint8_t width, uint8_t height, uint8_t on)
{
	// draw a rectangle from 4 lines
	int x2 = (x1 + width);
	int y2 = (y1 + height);
	drawLine (x1, y1, x2, y1, on);
	drawLine (x2, y1, x2, y2, on);
	drawLine (x2, y2, x1, y2, on);
	drawLine (x1, y2, x1, y1, on);
}

// draw a rectangle, then fill it
void Noritake_VFD_GUU100::fillRect (int x1, int y1, uint8_t width, uint8_t height, uint8_t on)
{
	int x2 = (x1 + width);
	int y2 = (y1 + height);

	for (x1 = x1; x1 < x2; x1++) {
		drawLine (x1, y1, x1, y2, on);
	}
}

// draw a rectangle with rounded corners of "radius" pixels
void Noritake_VFD_GUU100::drawRoundRect (int cx, int cy, uint8_t width, uint8_t height, uint8_t radius, uint8_t on)
{
	int x;
	int y;
	int16_t tSwitch;
	x = 0;
	y = radius;
	tSwitch = 3 - (2 * radius);

	while (x <= y) {
		on ? _setDot (cx + radius - x, cy + radius - y, 1) : _setDot (cx + radius - x, cy + radius - y, 0);
		on ? _setDot (cx + radius - y, cy + radius - x, 1) : _setDot (cx + radius - y, cy + radius - x, 0);
		on ? _setDot (cx + width - radius + x, cy + radius - y, 1) : _setDot (cx + width - radius + x, cy + radius - y, 0);
		on ? _setDot (cx + width - radius + y, cy + radius - x, 1) : _setDot (cx + width - radius + y, cy + radius - x, 0);
		on ? _setDot (cx + width - radius + x, cy + height - radius + y, 1) : _setDot (cx + width - radius + x, cy + height - radius + y, 0);
		on ? _setDot (cx + width - radius + y, cy + height - radius + x, 1) : _setDot (cx + width - radius + y, cy + height - radius + x, 0);
		on ? _setDot (cx + radius - x, cy + height - radius + y, 1) : _setDot (cx + radius - x, cy + height - radius + y, 0);
		on ? _setDot (cx + radius - y, cy + height - radius + x, 1) : _setDot (cx + radius - y, cy + height - radius + x, 0);

		if (tSwitch < 0) {
			tSwitch += 2 * (x);

		} else {
			tSwitch += 2 * (x - y);
			y--;
		}

		x++;
	}

	drawLine (cx + radius, cy, (cx + radius) + (width - (2 * radius)), cy, on);
	drawLine (cx + radius, cy + height, (cx + radius) + (width - (2 * radius)), cy + height, on);
	drawLine (cx, cy + radius, cx, (cy + radius) + (height - (2 * radius)), on);
	drawLine (cx + width, cy + radius, cx + width, (cy + radius) + (height - (2 * radius)), on);
}

// draw an elipse from centered at X,Y with width and height as specified
void Noritake_VFD_GUU100::drawEllipse (int x, int y, uint8_t width, uint8_t height, uint8_t on)
{
	long x1 = -width, y1 = 0; /* II. quadrant from bottom left to top right */
	long e2 = height, dx = (1 + 2 * x1) * e2 * e2; /* error increment */
	long dy = x1 * x1, err = dx + dy; /* error of 1 step */

	do {
		on ? _setDot (x - x1, y + y1, 1) : _setDot (x - x1, y + y1, 0); /* I. Quadrant */
		on ? _setDot (x + x1, y + y1, 1) : _setDot (x + x1, y + y1, 0); /* II. Quadrant */
		on ? _setDot (x + x1, y - y1, 1) : _setDot (x + x1, y - y1, 0); /* III. Quadrant */
		on ? _setDot (x - x1, y - y1, 1) : _setDot (x - x1, y - y1, 0); /* IV. Quadrant */
		e2 = 2 * err;

		if (e2 >= dx) {
			x1++;
			err += dx += 2 * (long) height * height;
		} /* x1 step */

		if (e2 <= dy) {
			y1++;
			err += dy += 2 * (long) width * width;
		} /* y1 step */
	} while (x1 <= 0);

	while (y1++ < height) { /* too early stop for flat ellipses with width=1, */
		on ? _setDot (x, y + y1, 1) : _setDot (x, y + y1, 0); /* -> finish tip of ellipse */
		on ? _setDot (x, y - y1, 1) : _setDot (x, y - y1, 0);
	}
}

// draw a circle centered at X,Y with a radius as specified
void Noritake_VFD_GUU100::drawCircle (int cx, int cy, uint8_t radius, uint8_t on)
{
	///////////////////////////////////////////////////////////
	// Stefan Gustavson (stegu@itn.liu.se) 2003-08-20
	// webstaff.itn.liu.se/~stegu/circle/circlealgorithm.pdf
	///////////////////////////////////////////////////////////
	int x = 0;
	int y = radius;
	int d = (5 - (4 * radius));
	int dA = 12;
	int dB = (20 - (8 * radius));

	while (x <= y) {
		on ? _setDot (cx - x, cy - y, 1) : _setDot (cx - x, cy - y, 0);
		on ? _setDot (cx - x, cy + y, 1) : _setDot (cx - x, cy + y, 0);
		on ? _setDot (cx + x, cy - y, 1) : _setDot (cx + x, cy - y, 0);
		on ? _setDot (cx + x, cy + y, 1) : _setDot (cx + x, cy + y, 0);
		on ? _setDot (cx - y, cy - x, 1) : _setDot (cx - y, cy - x, 0);
		on ? _setDot (cx - y, cy + x, 1) : _setDot (cx - y, cy + x, 0);
		on ? _setDot (cx + y, cy - x, 1) : _setDot (cx + y, cy - x, 0);
		on ? _setDot (cx + y, cy + x, 1) : _setDot (cx + y, cy + x, 0);

		if (d < 0) {
			d += dA;
			dB += 8;

		} else {
			y--;
			d += dB;
			dB += 16;
		}

		x++;
		dA += 8;
	}
}

// draw a circle, then fill it (actually we just fill in a circular area
void Noritake_VFD_GUU100::fillCircle (int x, int y, uint8_t radius, uint8_t on)
{
	int f = 1 - radius;
	int ddF_x = 1;
	int ddF_y = -2 * radius;
	int x1;
	int y1;
	x1 = 0;
	y1 = radius;

	while (x1 < y1) {
		if (f >= 0) {
			y1--;
			ddF_y += 2;
			f += ddF_y;
		}

		x1++;
		ddF_x += 2;
		f += ddF_x;
		drawLine (x + x1, y + y1, x + x1, y - y1, on);
		drawLine (x + y1, y + x1, x + y1, y - x1, on);
		drawLine (x - x1, y + y1, x - x1, y - y1, on);
		drawLine (x - y1, y + x1, x - y1, y - x1, on);
	}

	drawLine (x, (y - radius), x, (y + radius), on); // center vertical line
}

void Noritake_VFD_GUU100::drawArc (int org_x, int org_y, uint8_t radius, int st_angle, int en_angle, uint8_t on)
{
	drawArc (org_x, org_y, radius, radius, st_angle, en_angle, on);
}

void Noritake_VFD_GUU100::drawArc (int org_x, int org_y, uint8_t x_rad, uint8_t y_rad, int st_angle, int en_angle, uint8_t on)
{
	int angle, z;
	int x, y;
	double theta;
	z = ((st_angle %= 360) < (en_angle %= 360)) ? 1 : -1;

	for (angle = st_angle; angle != en_angle; angle += z) {
		theta = rad (angle - 90);
		x = round ((cos (theta) * x_rad) + org_x);
		y = round ((sin (theta) * y_rad) + org_y);
		_setDot (x, y, on);
	}
}

void Noritake_VFD_GUU100::screenSave (void)
{
	char c;
	char buf[2];

	while (1) {
		c = (rand() % (_lastChar + 1));

		if (! ((c < _firstChar) || (c > _lastChar))) {
			buf[0] = c;
			buf[1] = 0;
			break;
		}
	}

	screenSave (buf);
}

void Noritake_VFD_GUU100::screenSave (const char *str)
{
	int x, y, z, x_max, y_max;
	static const uint8_t stl_msg[] PROGMEM = {
		0x01, 0x01, 0x7f, 0x01, 0x01, 0x00, // T
		0x3e, 0x41, 0x41, 0x41, 0x3e, 0x00, // O
		0x3e, 0x41, 0x41, 0x41, 0x3e, 0x00, // O
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // SPACE
		0x7f, 0x40, 0x40, 0x40, 0x40, 0x00, // L
		0x3e, 0x41, 0x41, 0x41, 0x3e, 0x00, // O
		0x7f, 0x04, 0x08, 0x10, 0x7f, 0x00, // N
		0x3e, 0x41, 0x41, 0x51, 0x32, 0x00, // G
	};
	setInvert (0); // insure normal pixel polarity
	setBrightness (100); // be sure cathode is on and display is bright
	clearScreen(); // clear any graphics off screen before message

	// print "TOO LONG" if custom string won't fit on one line
	if ((strlen (str) * _next_x) > _displayWidth) {
		x = ((_displayWidth - sizeof (stl_msg)) / 2); // center message left/right
		y = ((_displayHeight - 8) / 2); // center message top/bot
		z = (sizeof (stl_msg) / sizeof (*stl_msg)); // how many chars in message
		drawImage (stl_msg, x, y, z, 8); // draw entire message as one graphic block
		return;

	} else {
		x_max = ((_displayWidth - 1) - (strlen (str) * _next_x)); // get max x size
		y_max = ((_displayHeight - 1) - _next_y); // get max y size

		while ((x = (rand() % (_displayWidth - 1))) > x_max); // get random x within bounds

		while ((y = (rand() % (_displayHeight - 1))) > y_max); // get random y within bounds

		_setCursor (x, y); // set cursor
		print (str); // print default or user string
		return; // done
	}
}

void Noritake_VFD_GUU100::setFont (const uint8_t *fontPtr)
{
	setFont ((uint32_t) fontPtr, 0, 0);
}

// set the font to use for generating text (16 bit ptr)
void Noritake_VFD_GUU100::setFont (const uint8_t *fontPtr, int h_gap, int v_gap)
{
	// accept a 16 bit PROGMEM pointer
	setFont ((uint32_t) fontPtr, h_gap, v_gap);
}

void Noritake_VFD_GUU100::setFont (uint32_t fontPtr)
{
	setFont (fontPtr, 0, 0);
}

// set the font to use for generating text (32 bit uint)
void Noritake_VFD_GUU100::setFont (uint32_t fontPtr, int h_gap, int v_gap)
{
	// accept a flat 32 bit pointer address
	_fontData = _fontStart = fontPtr;

	if (fontPtr) {
		_fontWidth = PGM_READ_BYTE (_fontData++);
		_fontHeight = PGM_READ_BYTE (_fontData++);
		_fontHGap = PGM_READ_BYTE (_fontData++);
		_fontVGap = PGM_READ_BYTE (_fontData++);
		_firstChar = PGM_READ_BYTE (_fontData++);
		_lastChar = PGM_READ_BYTE (_fontData++);
		_bytesPerChar = PGM_READ_BYTE (_fontData++);
		_next_x = _fontWidth + _fontHGap + h_gap;
		_next_y = _fontHeight + _fontVGap + v_gap;

	} else {
		_fontData = _fontStart = 0;
	}

	// now global "_fontData" points to the first byte of font DATA
	// and "_fontStart" points to the first byte of font itself
	// (used to save and reload a font)
}

// get address of loaded font (useful for saving what was previously
// loaded, then loading a new one, then restoring the original one).
uint32_t Noritake_VFD_GUU100::getFont (void)
{
	return _fontStart;
}

uint8_t Noritake_VFD_GUU100::getCharWidth (void)
{
	return _fontStart ? _next_x : 0; // character width
}

uint8_t Noritake_VFD_GUU100::getCharHeight (void)
{
	return _fontStart ? _next_y : 0; // character height
}

uint8_t Noritake_VFD_GUU100::getMaxChars (void)
{
	return _fontStart ? (_displayWidth / _next_x) : 0; // max chars per line
}

uint8_t Noritake_VFD_GUU100::getMaxLines (void)
{
	return _fontStart ? (_displayHeight / _next_y) : 0; // max lines
}

void Noritake_VFD_GUU100::home (void)
{
	home (0);
}

// set cursor home. optionally zero the Z scroll also (if "s" is non-zero)
void Noritake_VFD_GUU100::home (uint8_t s)
{
	// optional reset scroll (default=no)
	if (s) {
		_setScroll (0);
	}

	_setCursor (0, 0);
}

// dummies for stream compatability
int Noritake_VFD_GUU100::available (void)
{
	return 0;
}

// dummy for stream compatability
int Noritake_VFD_GUU100::peek (void)
{
	return 0;
}

int Noritake_VFD_GUU100::read (void)
{
	return 0;
}

void Noritake_VFD_GUU100::flush (void)
{
	return;
}

Noritake_VFD_GUU100::operator bool (void)
{
	return true;
}

// write any character on the screen from a loaded font.
// the cursor is automatically updated to the next character
// cell based on the width and height of that character.
inline size_t Noritake_VFD_GUU100::write (uint8_t c)
{
	int _tmp_x, _tmp_y;
	_tmp_x = _cur_x; // get a working copy of cursor pos.
	_tmp_y = _cur_y;

	// if no font is loaded and you try to print
	// the display will say "NO FONT LOADED"
	if (! _fontData) {
		return _noFont();
	}

	switch (c) {
			// backup one space, erase last char
		case 0x08: {
				return _backSpace();
			}

			// tabs are 4 spaces (maybe useful for lining stuff up?)
		case 0x09: {
				return _doTabs (4);
			}

			// drop down to the next line (column position remains
			// unchanged). For newline you need CR and LF
		case 0x0A: {
				return _lineFeed();
			}

			// erase the screen (fill with spaces)
		case 0x0C: {
				return clearScreen();
			}

			// restore the cursor to the lefthand most position
			// (line position remains unchanged)
		case 0x0D: {
				return _carriageReturn();
			}

			// anything else is a printable ascii character
		default: {
				break;
			}
	}

	// check this AFTER so that control codes always
	// work, even if they are not in the font file.
	if ((c < _firstChar) || (c > _lastChar)) {
		return 0;
	}

	c -= _firstChar; // normalize char to index

	if (_fontHGap) { // clear any horizontal gap space
		fillRect (_tmp_x + _fontWidth, _tmp_y, _fontHGap, _next_y, 0);
	}

	if (_fontVGap) { // clear any vertical gap space
		fillRect (_tmp_x, _tmp_y + _fontHeight, _next_x, _fontVGap, 0);
	}

	drawImage (_fontData + (c * _bytesPerChar), _tmp_x, _tmp_y, _fontWidth, _fontHeight); // draw new char

	if ((_tmp_x + _next_x + _next_x) <= _displayWidth) {
		_tmp_x += _next_x; // if room, move to next char space

	} else {
		if ((_tmp_y + _next_y + _next_y) <= _displayHeight) {
			_tmp_x = 0; // no room for next char, if next line...
			_tmp_y += _next_y; // ...is available, then go to it

		} else {
			_tmp_x = 0; // loop back from the beginning
			_tmp_y = 0;
		}
	}

	_setCursor (_tmp_x, _tmp_y);
	return 1;
}

// set cursor to left column (line not changed)
inline size_t Noritake_VFD_GUU100::_carriageReturn (void)
{
	_setCursor (0, _cur_y); // cursor X position to 0
	return 0;
}

// set cursor to next line (column not changed)
inline size_t Noritake_VFD_GUU100::_lineFeed (void)
{
	_cur_y += _next_y;

	if ((_cur_y + _next_y) >= _displayHeight) {
		_cur_y = 0;
	}

	setCursor (_cur_x, _cur_y);
	return 0;
}

// backup one character position, erase backspaced cheracter
inline size_t Noritake_VFD_GUU100::_backSpace (void)
{
	int _tmp_x, _tmp_y;
	_tmp_x = _cur_x;
	_tmp_y = _cur_y;

	if ((_tmp_x + _next_x) > _next_x) {
		// backup 1 char
		_tmp_x -= _next_x;

	} else {
		if ((_tmp_y + _next_y) > _next_y) {
			_tmp_x = ((_displayWidth - _next_x) - (_displayWidth % _next_x));
			_tmp_y -= _next_y;

		} else {
			_tmp_x = ((_displayWidth - _next_x) - (_displayWidth % _next_x));
			_tmp_y = ((_displayHeight - _next_y) - (_displayHeight % _next_y));
		}
	}

	_setCursor (_tmp_x, _tmp_y);
	write (0x20);
	_setCursor (_tmp_x, _tmp_y);
	return 0;
}

// move cursor to next tab stop (4 places = 1 "tab")
inline size_t Noritake_VFD_GUU100::_doTabs (uint8_t _tab_size)
{
	size_t n = 0;

	if (! (_cur_x % (_next_x * _tab_size))) {
		n += write (0x20);
	}

	while (_cur_x % (_next_x * _tab_size)) {
		n += write (0x20);
	}

	return n;
}

void Noritake_VFD_GUU100::_delay_usec (uint32_t delay)
{
	while (delay--) {
		__asm__ __volatile__ (
			" nop\n" " nop\n" " nop\n" " nop\n" " nop\n"
#if ( F_CPU > 8000000UL )
			" nop\n" " nop\n" " nop\n" " nop\n" " nop\n"
#endif
#if ( F_CPU > 16000000UL )
			" nop\n" " nop\n" " nop\n" " nop\n" " nop\n"
#endif
		);
	}
}

// when called this prints "NO FONT LOADED" on the VFD
// screen, centered left-right and top-bottom.
size_t Noritake_VFD_GUU100::_noFont (void)
{
	int _tmp_x, _tmp_y, _tmp_z;
	static const uint8_t msg[] PROGMEM = {
		0x7F, 0x04, 0x08, 0x10, 0x7F, 0x00, // "N"
		0x3E, 0x41, 0x41, 0x41, 0x3E, 0x00, // "O"
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // SPACE
		0x7F, 0x09, 0x09, 0x09, 0x01, 0x00, // "F"
		0x3E, 0x41, 0x41, 0x41, 0x3E, 0x00, // "O"
		0x7F, 0x04, 0x08, 0x10, 0x7F, 0x00, // "N"
		0x01, 0x01, 0x7F, 0x01, 0x01, 0x00, // "T"
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // SPACE
		0x7F, 0x40, 0x40, 0x40, 0x40, 0x00, // "L"
		0x3E, 0x41, 0x41, 0x41, 0x3E, 0x00, // "O"
		0x7E, 0x11, 0x11, 0x11, 0x7E, 0x00, // "A"
		0x7F, 0x41, 0x41, 0x22, 0x1C, 0x00, // "D"
		0x7F, 0x49, 0x49, 0x49, 0x41, 0x00, // "E"
		0x7F, 0x41, 0x41, 0x22, 0x1C, 0x00, // "D"
	};
	_tmp_x = ((_displayWidth - sizeof (msg)) / 2); // center left/right
	_tmp_y = ((_displayHeight - 8) / 2); // center top/bot
	_tmp_z = (sizeof (msg) / sizeof (*msg)); // how many chars
	setInvert (0); // insure normal pixel polarity
	setBrightness (100); // be sure cathode is on and display is bright
	clearScreen(); // clear any graphics off screen before message
	drawImage (msg, _tmp_x, _tmp_y, _tmp_z, 8); // draw entire message as one graphic block
	_delay_usec (1000000); // time 1 second for it to show in case of fast printing
	return 0;
}

// send a command to both "chips" with one call
void Noritake_VFD_GUU100::_writeDisplay (uint8_t cmd)
{
	int _tmp_x, _tmp_y;
	_tmp_x = _cur_x;
	_tmp_y = _cur_y;
	_cur_x = 0;
	_cur_y = 0;
	_writePort (cmd, 0);
	_cur_x = 64;
	_cur_y = 0;
	_writePort (cmd, 0);
	_setCursor (_tmp_x, _tmp_y);
}

// align data (usually text) that crosses chip boundaries
inline uint8_t Noritake_VFD_GUU100::_bitsBetween (uint8_t a, uint8_t b)
{
	if ((a / 8) != (b / 8)) {
		return ~ ((1UL << (a % 8)) - 1);

	} else {
		a = (a % 8);
		b = (b % 8);
	}

	return ~ ((1UL << a) - 1) & ((1UL << b) - 1);
}

// write one byte of data to the VFD and update the cursor info
inline void Noritake_VFD_GUU100::_writeData (uint8_t data)
{
	_writePort (_invert ? ~data : data, 1);
	_increment();
}

// read one byte of data from the VFD and update the cursor info
inline uint8_t Noritake_VFD_GUU100::_readData (void)
{
	uint8_t data = (_invert ? ~_readPort (1) : _readPort (1));
	_increment();
	return data;
}

// send data with RS set to "COMMAND" (i.e. send a VFD command)
inline void Noritake_VFD_GUU100::_writeCmd (uint8_t cmd)
{
	_writePort (cmd, 0);
}

// update cursor position info
inline void Noritake_VFD_GUU100::_increment (void)
{
	_cur_x++;

	if (_cur_x < _displayWidth) { // if next col position doesn't hit the end...
		// nothing
	} else {
		_cur_x = 0;
		_cur_y += 8;

		if (_cur_y < _displayHeight) { // if can set next line...
			// nothing
		} else {
			_cur_x = 0;
			_cur_y = 0;
		}
	}

	_setCursor (_cur_x, _cur_y);
}

// set dot at X,Y on or off (fast inline mode)
inline void Noritake_VFD_GUU100::_setDot (int x, int y, uint8_t on)
{
	if ((x >= 0) && (y >= 0) && (x < _displayWidth) && (y < _displayHeight)) {
		uint8_t data = on ? _getBits (x, y) | (1UL << (y % 8)) : _getBits (x, y) & ~ (1UL << (y % 8));
		_writeData (data);
	}
}

// set cursor position (both soft info and hardware registers)
inline void Noritake_VFD_GUU100::_setCursor (int x, int y)
{
	_cur_x = (x % _displayWidth); // update x and y...
	_cur_y = (y % _displayHeight); // ...cursor position
	_writeCmd (SETADDR | _cur_x); // set...
	_writeCmd (SETPAGE | (_cur_y / 8) % 8); //...display
}

// set vertical offset position (both soft info and hardware registers)
inline void Noritake_VFD_GUU100::_setScroll (int z)
{
	_cur_z = (z % _displayHeight);
	_writeDisplay (SETLINE | _cur_z); // set it
}

// read a byte at X,Y (preserve cursor location)
inline uint8_t Noritake_VFD_GUU100::_getBits (int x, int y)
{
	uint8_t data;
	_setCursor (x, y);
	data = _readData();
	_setCursor (x, y);
	return data;
}

// align text at "chip" boundaries
inline uint8_t Noritake_VFD_GUU100::_align (uint8_t x)
{
	return (((x + 7) / 8) * 8);
}

// remove bits that don't belong to this "chip"
inline uint8_t Noritake_VFD_GUU100::_clip (uint8_t x)
{
	return ((x / 8) * 8);
}

//////// end of Noritake_GUU100.cpp ////////
