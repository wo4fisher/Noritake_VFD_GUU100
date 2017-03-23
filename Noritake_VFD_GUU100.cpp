///////////////////////////////////////////////////////////////////////////////
//
//  Noritake GU128X64E-U100 VFD Display Driver Library for Arduino
//  Copyright (c) 2012, 2016 Roger A. Krupski <rakrupski@verizon.net>
//
//  Last update: 16 December 2016
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
	_initPort(); // initialize the I/O port (set in config.h)
	_displayWidth = VFD_WIDTH; // init display...
	_displayHeight = VFD_HEIGHT; // ... dimensions
	_firstChar = 0; // zero out font info
	_fontWidth = 0; // font bare pixel width
	_fontHeight = 0; // font bare pixel height
	_fontHGap = 0; // inter-char gap in pixels (horizontal)
	_fontVGap = 0; // inter-char gap in pixels (vertical)
	_bytesPerChar = 0; // how many bytes in each char image
	_cur_x = 0; // current X cursor position
	_cur_y = 0; // current Y cursor position
	_cur_z = 0; // current scroll offset (lines)
	_save_cur_x = 0; // saved X cursor position
	_save_cur_y = 0; // saved Y cursor position
	_save_cur_z = 0; // saved scroll offset (lines)
	_next_x = 0; // x size of character cell in pixels
	_next_y = 0; // y size of character cell in pixels
	_hofs = 0; // horizontal offset
	_vofs = 0; // vertical offset
	_saveHofs = 0; // horizontal offset save
	_saveVofs = 0; // vertical offset save
	_inv = 0; // display invert yes/no
	_fontData = 0; // invalidate font address pointer
	_fontStart = 0; // invalidate font start pointer
	_fontSave = 0; // clear out push/pop storage
	_charWidth =  0; // character width
	_charHeight = 0; // character height
	_maxChars = 0; // max chars per line
	_maxLines = 0; // max lines
	setDisplay (1); // turn display on
	setBrightness (100); // default brightness and cathode on
	clearScreen(); // clear screen
	_setCursor (0, 0); // zero cursor
	_setScroll (0); // zero scroll
}

// turn display on or off (filament stays on)
void Noritake_VFD_GUU100::setDisplay (uint8_t on)
{
	_cur_x = 64; // turn on right side
	_writeCmd (SETDISP | (on ? 0x01 : 0x00));
	_cur_x = 0; // turn on left side
	_writeCmd (SETDISP | (on ? 0x01 : 0x00));
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
	_writeCmd (FUNC_SET); // function set
	_writeCmd (percent ? (_displayBright | SETBRITE | CATHODE) : ((_displayBright | SETBRITE) & ~CATHODE));
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
	_setCursor ((x * _next_x), (y * _next_y));
}

// get cursor position as a (possibly fractional) column and line
void Noritake_VFD_GUU100::getLine (double &x, double &y)
{
	x = (double)(_cur_x / _next_x);
	y = (double)(_cur_y / _next_y);
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

// for user only - do not use inside driver
void Noritake_VFD_GUU100::pushCursor (void)
{
	_save_cur_x = _cur_x;
	_save_cur_y = _cur_y;
	_save_cur_z = _cur_z;
}

// for user only - do not use inside driver
void Noritake_VFD_GUU100::popCursor (void)
{
	_setScroll (_save_cur_z);
	_setCursor (_save_cur_x, _save_cur_y);
}

// set dot at X,Y on or off
void Noritake_VFD_GUU100::setDot (int x, int y, uint8_t on)
{
	_setDot (x, y, on);
}

// get state of dot at X,Y
uint8_t Noritake_VFD_GUU100::getDot (int x, int y)
{
	uint8_t z;
	z = (_getBits (x, y) & (1 << y % 8)) ? 1 : 0;
	return z;
}

// this makes drawing normal or inverted (negative)
void Noritake_VFD_GUU100::setInvert (uint8_t inv)
{
	_inv = inv ? 1 : 0;
}

uint8_t Noritake_VFD_GUU100::clearScreen (void)
{
	return clearScreen (0);
}

// clear the screen by filling it with 0x00.
// note the fill char can be optionally specified in
// order to create special (?) effects.
uint8_t Noritake_VFD_GUU100::clearScreen (uint8_t pattern)
{
	uint16_t n = (_displayWidth * (_displayHeight / 8));
	_setCursor (0, 0);
	_setScroll (0);

	while (n--) {
		_writeData (pattern); // erase screen
	}

	return pattern;
}

// draw an image pointed to by a 16 bit POINTER to data in PROGMEM
void Noritake_VFD_GUU100::drawImage (const uint8_t *data, int x, int y, uint8_t width, uint8_t height)
{
	drawImage (((uint32_t) data), x, y, width, height);
}

void Noritake_VFD_GUU100::drawImage (uint8_t *data, int x, int y, uint8_t width, uint8_t height)
{
	uint8_t mask, mix;
	uint16_t src; // must be 16 bit because of "<< 8" operations
	int16_t ix, iy, y2, end;

	y2 = (y + height);

	if (_clip (y) == _clip (y2)) {
		mask = _bitsBetween (y, y2);

		for (ix = 0; ix < width; ix++) {
			mix = _getBits (x + ix, _clip (y));
			src = data[ix];
			src <<= (y % 8);
			src = (mix & ~mask) | (src & mask);
			_writeData (src);
		}

	} else {
		if (y == _clip (y)) {
			for (iy = y; iy < _clip (y2); iy += 8) {
				setCursor (x, iy);

				for (ix = 0; ix < width; ix++) {
					src = data[ix];
					_writeData (src);
				}

				data += width;
			}

			if (y2 != _clip (y2)) {
				mask = _bitsBetween (_clip (y2), y2);

				for (ix = 0; ix < width; ix++) {
					mix = _getBits (x + ix, _clip (y2));
					src = data[ix];
					src = (mix & ~mask) | (src & mask);
					_writeData (src);
				}
			}

		} else {
			mask = _bitsBetween (y, _align (y));
			end = (width * height);

			for (ix = 0; ix < width; ix++) {
				mix = _getBits ((x + ix), _clip (y));
				src = data[ix];
				src <<= (y % 8);
				src = (mix & ~mask) | (src & mask);
				_writeData (src);
			}

			if (_align (y) < _clip (y2)) {
				for (iy = _align (y); iy < _clip (y2); iy += 8) {
					setCursor (x, iy);

					for (ix = 0; ix < width; ix++) {
						src = data[ix + (ix < end) ? data[ix + width] << 8 : 0];
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
					src = data[ix + (ix < end) ? data[ix + width] << 8 : 0];
					src >>= (_align (y) - y);
					src = (mix & ~mask) | (src & mask);
					_writeData (src);
				}
			}
		}
	}
}

// draw an image pointed to by an absolute 32 bit address of data in PROGMEM
// (this address is obtained by using "pgm_get_far_address ()" of the data in
// PROGMEM at compile time (i.e. static)). See the font files for examples on
// how "pgm_get_far_address ()" is used. (You CANNOT pass it a runtime pointer,
// it only works with static compile-time objects - which sucks).
void Noritake_VFD_GUU100::drawImage (uint32_t data, int x, int y, uint8_t width, uint8_t height)
{
	uint8_t mask, mix;
	uint16_t src; // must be 16 bit because of "<< 8" operations
	int16_t ix, iy, y2, end;

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
						src = PGM_READ_BYTE (data + ix) + ((data + ix < end) ?
							(PGM_READ_BYTE (data + ix + width) << 8) : 0);
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
					src = PGM_READ_BYTE (data + ix) + ((data + ix < end) ?
						(PGM_READ_BYTE (data + ix + width) << 8) : 0);
					src >>= (_align (y) - y);
					src = (mix & ~mask) | (src & mask);
					_writeData (src);
				}
			}
		}
	}
}

/*** stops the "multi-line comment" compiler warning.
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
***/
void Noritake_VFD_GUU100::drawPolygon (int x, int y, uint8_t radius, int angle, uint8_t sides, uint8_t on)
{
	int x1, y1, x2, y2;
	double th, inc, start;

	if (sides < 3) { // polygon must be at least 3 sides!
		return;
	}

	if (sides > 16) { // too many sides is slow and just makes a circle anyway...
		drawCircle (x, y, radius, on);
		return;
	}

	// starting angle (in radians)
	start = rad ((angle - 90) % 360); // make 0 degrees straight up
	th = start; // first vertex is at the start (of course)
	inc = ((M_PI * 2.0) / sides); // increment (in radians) to next vertex
	x2 = round ((cos (th) * radius) + x); // get first vertex
	y2 = round ((sin (th) * radius) + y);

	while (sides--) {
		x1 = x2; // old vertex is...
		y1 = y2; // ...the new startpoint
		th = ((sides * inc) + start); // increment to the next vertex
		x2 = round ((cos (th) * radius) + x); // get next vertex
		y2 = round ((sin (th) * radius) + y);
		drawLine (x1, y1, x2, y2, on); // draw side
	}
}

// draw a vector from X,Y with start and end radius and angle as specified.
// this is useful for drawing "analog" meters, gauges, etc...
// angle 0 degrees is straight up. increasing angles go clockwise
// (that is, 90 degrees points to the 3:00 o'clock position).
void Noritake_VFD_GUU100::drawVector (int x, int y, int sr, int er, int angle, uint8_t on)
{
	double th = rad (angle - 90);
	double s = sin (th);
	double c = cos (th);
	drawLine (
		round ((c * sr) + x),
		round ((s * sr) + y),
		round ((c * er) + x),
		round ((s * er) + y),
		on
	);
}

void Noritake_VFD_GUU100::drawLine (int x0, int y0, int x1, int y1, uint8_t on)
{
	int dx = abs (x1 - x0), sx = x0 < x1 ? 1 : -1;
	int dy = abs (y1 - y0), sy = y0 < y1 ? 1 : -1;
	int err = (dx > dy ? dx : -dy) / 2, e2;

	while (1) {
		_setDot (x0, y0, on);
		if (x0 == x1 && y0 == y1) {
			break;
		}
		e2 = err;
		if (e2 > -dx) { err -= dy; x0 += sx; }
		if (e2 < dy) { err += dx; y0 += sy; }
	}
}

// draw a rectangle from x1 to x2 and y1 to y2
void Noritake_VFD_GUU100::drawRect (int x1, int y1, int x2, int y2, uint8_t on)
{
	// draw a rectangle from 4 lines
	drawLine (x1, y1, x2, y1, on);
	drawLine (x2, y1, x2, y2, on);
	drawLine (x2, y2, x1, y2, on);
	drawLine (x1, y2, x1, y1, on);
}

// draw a rectangle, then fill it
void Noritake_VFD_GUU100::fillRect (int x1, int y1, int x2, int y2, uint8_t on)
{
	// swap () is defined in "Noritake_VFD_GUU100.h"
	if (x1 > x2) {
		swap (x1, x2);
	}

	if (y1 > y2) {
		swap (y1, y2);
	}

	for (x1 = x1; x1 <= x2; x1++) {
		drawLine (x1, y1, x1, y2, on);
	}
}

// draw a rectangle with rounded corners of "radius" pixels
void Noritake_VFD_GUU100::drawRoundRect (int x1, int y1, int x2, int y2, uint8_t radius, uint8_t on)
{
	int x, y, tSwitch;

	// swap () is defined in "Noritake_VFD_GUU100.h"
	if (x1 > x2) {
		swap (x1, x2);
	}

	if (y1 > y2) {
		swap (y1, y2);
	}

	x = 0;
	y = radius;
	tSwitch = 3 - (2 * radius);

	while (y > x) {
		_setDot (x1 - x + radius, y1 - y + radius, on);
		_setDot (x1 - y + radius, y1 - x + radius, on);
		_setDot (x2 + x - radius, y1 - y + radius, on);
		_setDot (x2 + y - radius, y1 - x + radius, on);
		_setDot (x2 + x - radius, y2 + y - radius, on);
		_setDot (x2 + y - radius, y2 + x - radius, on);
		_setDot (x1 - x + radius, y2 + y - radius, on);
		_setDot (x1 - y + radius, y2 + x - radius, on);

		if (tSwitch < 0) {
			tSwitch += 2 * (x);

		} else {
			tSwitch += 2 * (x - y);
			y--;
		}

		x++;
	}

	x = x2 + radius - (2 * radius);
	y = y2 + radius - (2 * radius);
	drawLine (x1 + radius, y1, x, y1, on);
	drawLine (x1 + radius, y2, x, y2, on);
	drawLine (x1, y1 + radius, x1, y, on);
	drawLine (x2, y1 + radius, x2, y, on);
}

// draw an elipse from centered at X,Y with width and height as specified
void Noritake_VFD_GUU100::drawEllipse (int x, int y, uint8_t width, uint8_t height, uint8_t on)
{
	long x1 = -width, y1 = 0; // II quadrant from bottom left to top right
	long e2 = height, dx = (1 + 2 * x1) * e2 * e2; // error increment
	long dy = x1 * x1, err = dx + dy; // error of 1 step

	do {
		_setDot (x - x1, y + y1, on); // I Quadrant
		_setDot (x + x1, y + y1, on); // II Quadrant
		_setDot (x + x1, y - y1, on); // III Quadrant
		_setDot (x - x1, y - y1, on); // IV Quadrant
		e2 = 2 * err;

		if (e2 >= dx) {
			x1++;
			err += dx += 2 * (long) height * height;
		} // x1 step

		if (e2 <= dy) {
			y1++;
			err += dy += 2 * (long) width * width;
		} // y1 step
	} while (x1 <= 0);

	while (y1++ < height) { // too early stop for flat ellipses with width=1
		_setDot (x, y + y1, on); // -> finish tip of ellipse
		_setDot (x, y - y1, on);
	}
}

// draw a circle centered at X,Y with a radius as specified
void Noritake_VFD_GUU100::drawCircle (int x1, int y1, uint8_t radius, uint8_t on)
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
		_setDot (x1 - x, y1 - y, on);
		_setDot (x1 - x, y1 + y, on);
		_setDot (x1 + x, y1 - y, on);
		_setDot (x1 + x, y1 + y, on);
		_setDot (x1 - y, y1 - x, on);
		_setDot (x1 - y, y1 + x, on);
		_setDot (x1 + y, y1 - x, on);
		_setDot (x1 + y, y1 + x, on);

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

// draw a circle, then fill it (actually we just fill in a circular area)
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

void Noritake_VFD_GUU100::drawArc (int org_x, int org_y, uint8_t radius, int start_angle, int end_angle, uint8_t on)
{
	drawArc (org_x, org_y, radius, radius, start_angle, end_angle, on);
}

void Noritake_VFD_GUU100::drawArc (int org_x, int org_y, uint8_t x_rad, uint8_t y_rad, int start_angle, int end_angle, uint8_t on)
{
	int angle, x, y, sa, ea;
	double th;

	if (start_angle < end_angle) {
		sa = start_angle;
		ea = end_angle;

	} else {
		sa = end_angle;
		ea = start_angle;
	}

	for (angle = sa; angle < ea; angle++) {
		th = rad (angle - 90);
		x = round ((cos (th) * x_rad) + org_x);
		y = round ((sin (th) * y_rad) + org_y);
		_setDot (x, y, on);
	}
}

// screen saver draws random polygons
void Noritake_VFD_GUU100::screenSave (void)
{
	int x, y, angle;
	uint8_t radius, tworad, sides;

	radius = (MIN_RADIUS + (rand() % (MAX_RADIUS - MIN_RADIUS)));
	tworad = (radius * 2);
	x = (radius + (rand() % ((_displayWidth - 1) - tworad)));
	y = (radius + (rand() % ((_displayHeight - 1) - tworad)));
	sides = (MIN_SIDES + (rand() % (1 + (MAX_SIDES - MIN_SIDES))));
	angle = (rand() % 360);
	setInvert (0); // insure normal pixel polarity
	setBrightness (100); // max brightness
	setDisplay (1); // display on
	clearScreen(); // clear screen drawing polygon
	drawPolygon (x, y, radius, angle, sides, 1);
}

// screensaver prints text at random locations
void Noritake_VFD_GUU100::screenSave (const char *str)
{
	int s, x, y, x_max, y_max;

	setInvert (0); // insure normal pixel polarity
	setBrightness (100); // max brightness
	setDisplay (1); // display on
	clearScreen(); // clear screen before message

	s = strlen (str);
	x_max = ((_displayWidth - 1) - (s * _next_x));
	y_max = ((_displayHeight - 1) - _next_y);
	x = (rand() % x_max);
	y = (rand() % y_max);

	_setCursor (x, y); // set cursor
	print (str); // print default or user string
}

// save currently loaded font for use later
void Noritake_VFD_GUU100::pushFont (void)
{
	if (_fontStart) {
		_fontSave = _fontStart;
		_saveHofs = _hofs;
		_saveVofs = _vofs;
	}
}

// restore previously saved font
void Noritake_VFD_GUU100::popFont (void)
{
	if (_fontSave) {
		setFont (_fontSave, _saveHofs, _saveVofs);
	}
}

// set the font to use for generating text (16 bit ptr)
void Noritake_VFD_GUU100::setFont (const uint8_t *fontPtr, int8_t hofs, int8_t vofs)
{
	// accept a 16 bit PROGMEM pointer
	setFont ((uint32_t) fontPtr, hofs, vofs);
}

// set the font to use for generating text (32 bit uint)
void Noritake_VFD_GUU100::setFont (uint32_t fontPtr, int8_t hofs, int8_t vofs)
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
		_next_x = _fontWidth + _fontHGap + hofs;
		_next_y = _fontHeight + _fontVGap + vofs;
		_charWidth = _fontStart ? _next_x : 0;
		_charHeight = _fontStart ? _next_y : 0;
		_maxChars = _fontStart ? (_displayWidth / _next_x) : 0;
		_maxLines = _fontStart ? (_displayHeight / _next_y) : 0;
		_hofs = hofs;
		_vofs = vofs;

	} else {
		_fontData = _fontStart = 0;
	}
}

// get address of loaded font (useful for saving what was previously
// loaded, then loading a new one, then restoring the original one).
uint32_t Noritake_VFD_GUU100::getFont (void)
{
	return _fontStart;
}

uint8_t Noritake_VFD_GUU100::getCharWidth (void)
{
	return _charWidth;
}

uint8_t Noritake_VFD_GUU100::getCharHeight (void)
{
	return _charHeight;
}

uint8_t Noritake_VFD_GUU100::getMaxChars (void)
{
	return _maxChars;
}

uint8_t Noritake_VFD_GUU100::getMaxLines (void)
{
	return _maxLines;
}

void Noritake_VFD_GUU100::home (void)
{
	home (0);
}

// set cursor home. optionally zero the Z scroll also (if "z" is non-zero)
void Noritake_VFD_GUU100::home (uint8_t z)
{
	// optional reset scroll (default=no)
	if (z) {
		_setScroll (z % _displayHeight);
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

	if (! _fontData) {
		return 0;
	}

	_tmp_x = _cur_x; // get a working copy of cursor pos.
	_tmp_y = _cur_y;

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

		// set the cursor to the lefthand most position
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
		fillRect ((_tmp_x + _fontWidth), _tmp_y, ((_tmp_x - 1) + _next_x), ((_tmp_y - 1) + _next_y), 0);
	}

	if (_fontVGap) { // clear any vertical gap space
		fillRect (_tmp_x, (_tmp_y + _fontHeight), ((_tmp_x - 1) + _next_x), ((_tmp_y - 1) + _next_y), 0);
	}

	drawImage (_fontData + (c * _bytesPerChar), _tmp_x, _tmp_y, _fontWidth, _fontHeight); // draw new char

	if ((_cur_x + _next_x) < _displayWidth) {
		_tmp_x += _next_x; // if room, move to next char space

	} else {
		if ((_cur_y + _next_y) < _displayHeight) {
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
	if ((_cur_y + _next_y) < (getMaxLines() * _next_y)) {
		_cur_y += _next_y;

	} else {
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

	if ((_tmp_x - _next_x) >= 0) {
		// backup 1 char if we can
		_tmp_x -= _next_x;

	} else {
		if ((_tmp_y - _next_y) >= 0) {
			_tmp_x = ((getMaxChars() - 1) * _next_x);
			_tmp_y -= _next_y;

		} else {
			_tmp_x = ((getMaxChars() - 1) * _next_x);
			_tmp_y = ((getMaxLines() - 1) * _next_y);
		}
	}

	_setCursor (_tmp_x, _tmp_y);
	write ((uint8_t) ' ');
	_setCursor (_tmp_x, _tmp_y);
	return 0;
}

// move cursor to next tab stop (4 places = 1 "tab")
inline size_t Noritake_VFD_GUU100::_doTabs (uint8_t _tab_size)
{
	size_t n = 0;

	if (! (_cur_x % (_next_x * _tab_size))) {
		n += write ((uint8_t) ' ');
	}

	while (_cur_x % (_next_x * _tab_size)) {
		n += write ((uint8_t) ' ');
	}

	return n;
}

// align data (usually text) that crosses chip boundaries
inline uint8_t Noritake_VFD_GUU100::_bitsBetween (uint8_t x, uint8_t y)
{
	if ((x / 8) != (y / 8)) {
		return ~((1 << ((x % 8))) - 1);

	} else {
		return ~(((1 << (x % 8))) - 1) & (((1 << (y % 8))) - 1);
	}
}

// write one byte of data to the VFD and update the cursor info
inline void Noritake_VFD_GUU100::_writeData (uint8_t data)
{
	_writePort (_inv ? ~data : data, 1);
	_increment();
}

// read one byte of data from the VFD and update the cursor info
inline uint8_t Noritake_VFD_GUU100::_readData (void)
{
	uint8_t data = (_inv ? ~_readPort (1) : _readPort (1));
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
	_cur_x += 1;

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
	if (_checkXY (x, y)) {
		on ? _writeData (_getBits (x, y) | (1 << (y % 8))) : _writeData (_getBits (x, y) & ~(1 << (y % 8)));
	}
}

// set cursor position (both soft info and hardware registers)
inline void Noritake_VFD_GUU100::_setCursor (int x, int y)
{
	if (_checkXY (x, y)) {
		_cur_x = x; // update x and y...
		_cur_y = y; // ...cursor position
		_writeCmd (SETADDR | _cur_x); // set...
		_writeCmd (SETPAGE | (_cur_y / 8) % 8); //...display
	}
}

// set vertical offset position (both soft info and hardware registers)
inline void Noritake_VFD_GUU100::_setScroll (uint8_t z)
{
	_cur_z = (z % _displayHeight);
	_cur_x = 64; // set right side
	_writeCmd (SETLINE | _cur_z);
	_cur_x = 0; // set left side
	_writeCmd (SETLINE | _cur_z);
}

// read a byte at X,Y (preserve cursor location)
inline uint8_t Noritake_VFD_GUU100::_getBits (int x, int y)
{
	uint8_t data = 0;

	if (_checkXY (x, y)) {
		_setCursor (x, y);
		data = _readData();
		_setCursor (x, y);
	}

	return data;
}

// check that x and y are legal
inline uint8_t Noritake_VFD_GUU100::_checkXY (int x, int y)
{
	return ((x < (_displayWidth - 1)) && (y < (_displayHeight - 1)) && (x > -1) && (y > -1));
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
