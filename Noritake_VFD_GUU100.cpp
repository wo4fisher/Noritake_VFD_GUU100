///////////////////////////////////////////////////////////////////////////////
//
//  Noritake GU128X64E-U100 VFD Display Driver Library for Arduino
//  Copyright (c) 2012, 2014 Roger A. Krupski <rakrupski@verizon.net>
//
//  Last update: 29 December 2014
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

#include "Noritake_VFD_GUU100.h"

void Noritake_VFD_GUU100::init (void)
{
	_initPort (); // initialize the SPI or parallel port
	_displayWidth = _vfd_width; // init display...
	_displayHeight = _vfd_height; // ... dimensions
	_firstChar = 0; // zero out font info
	_fontWidth = 0; // font bare pixel width
	_fontHeight = 0; // font bare pixel height
	_fontHGap = 0; // inter-char gap (horizontal)
	_fontVGap = 0; // inter-char gap (vertical)
	_bytesPerChar = 0; // how many bytes in each char image
	_cur_x = 0; // current X position
	_cur_y = 0; // current Y position
	_cur_z = 0; // current scroll offset
	_next_x = 0; // x size of character
	_next_y = 0; // y size of character
	_invert = 0; // invert yes/no
	_font = NULL; // invalidate font data pointer
	_fontStart = NULL; // invalidate font start pointer
	clearScreen (); // clear screen & home cursor
	setBrightness (); // default screen brightness = 100
	setDisplay (1); // turn display on
}

void Noritake_VFD_GUU100::setDisplay (uint8_t on)
{
	_writeCmd (SETDISP | (on ? 0x01 : 0x00), 0);
	_writeCmd (SETDISP | (on ? 0x01 : 0x00), 1);
}

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
	_writeCmd (FUNC_SET, 0);
	_writeCmd ((percent ? (SETBRITE | FILAMENT) : (SETBRITE & ~FILAMENT)) | _displayBright, 0);
	_writeCmd (FUNC_SET, 1);
	_writeCmd ((percent ? (SETBRITE | FILAMENT) : (SETBRITE & ~FILAMENT)) | _displayBright, 1);

	return _displayBright;
}

void Noritake_VFD_GUU100::setStart (uint8_t z)
{
	_cur_z = (z % 64);
	_writeCmd (SETLINE | _cur_z, 0);
	_writeCmd (SETLINE | _cur_z, 1);
}

uint8_t Noritake_VFD_GUU100::getStart (void)
{
	return (_cur_z % 64);
}

void Noritake_VFD_GUU100::setLine (float x, float y)
{
	setCursor (((x * _next_x) + 0.5), ((y * _next_y) + 0.5));
}

void Noritake_VFD_GUU100::getLine (float &x, float &y)
{
	x = (float) (_cur_x / _next_x);
	y = (float) (_cur_y / _next_y);
}

void Noritake_VFD_GUU100::setCursor (uint8_t x, uint8_t y)
{
	uint8_t chip = (bool) (x > 63);
	_cur_x = x;
	_cur_y = y;
	_writeCmd (SETADDR | _cur_x, chip);
	_writeCmd (SETPAGE | ((_cur_y / 8) % 8), chip);
}

void Noritake_VFD_GUU100::getCursor (uint8_t &x, uint8_t &y)
{
	x = _cur_x;
	y = _cur_y;
}

void Noritake_VFD_GUU100::setPixel (uint16_t addr, uint8_t on)
{
	uint8_t x;
	uint8_t y;

	if (addr < (_displayWidth * _displayHeight)) {
		y = (addr / _displayWidth);
		x = (addr - (y * _displayWidth));
		setDot (x, y, on ? 1 : 0);
	}
}

uint8_t Noritake_VFD_GUU100::getPixel (uint16_t addr)
{
	uint8_t x;
	uint8_t y;

	if (addr < (_displayWidth * _displayHeight)) {
		y = (addr / _displayWidth);
		x = (addr - (y * _displayWidth));
		return getDot (x, y) ? 1 : 0;
	}

	return 0xFF;
}

void Noritake_VFD_GUU100::setDot (uint8_t x, uint8_t y, uint8_t on)
{
	uint8_t data = _peek (x, y);
	uint8_t bits = (1 << (y % 8));

	if ((x < _displayWidth) && (y < _displayHeight)) {
		_writeData (on ? (data | bits) : (data & ~bits));
	}
}

uint8_t Noritake_VFD_GUU100::getDot (uint8_t x, uint8_t y)
{
	if ((x < _displayWidth) && (y < _displayHeight)) {
		return (_peek (x, y) & (1 << (y % 8))) ? 1 : 0;
	}
	return 0;
}

void Noritake_VFD_GUU100::setInvert (uint8_t inv)
{
	_invert = inv ? 1 : 0;
}

void Noritake_VFD_GUU100::clearScreen (uint8_t pattern)
{
	uint16_t n = (_displayWidth * (_displayHeight / 8));

	setStart (0);
	setCursor (0, 0);

	while (n--) {
		_writeData (pattern); // erase screen
	}

	setStart (0);
	setCursor (0, 0);
}

void Noritake_VFD_GUU100::drawImage (const uint8_t *data, uint8_t x, uint8_t y, uint8_t width, uint8_t height)
{
	uint8_t mask, mix, ix, iy, y2;
	uint16_t src;
	const uint8_t *end;

	if ((x < _displayWidth) && (y < _displayHeight)) {

		y2 = (y + height);

		if (_clip (y) == _clip (y2)) {

			mask = _bitsBetween (y, y2);

			for (ix = 0; ix < width; ix++) {
				mix = _peek (x + ix, _clip (y));
				src = pgm_read_byte (data + ix);
				src <<= (y % 8);
				src = (mix & ~mask) | (src & mask);
				_writeData (src);
			}

		} else {

			if (y == _clip (y)) {

				for (iy = y; iy < _clip (y2); iy += 8) {
					setCursor (x, iy);

					for (ix = 0; ix < width; ix++) {
						src = pgm_read_byte (data + ix);
						_writeData (src);
					}

					data += width;
				}

				if (y2 != _clip (y2)) {

					mask = _bitsBetween (_clip (y2), y2);

					for (ix = 0; ix < width; ix++) {
						mix = _peek (x + ix, _clip (y2));
						src = pgm_read_byte (data + ix);
						src = (mix & ~mask) | (src & mask);
						_writeData (src);
					}
				}

			} else {

				mask = _bitsBetween (y, _align (y));
				end = ((width * height) + data);

				for (ix = 0; ix < width; ix++) {
					mix = _peek ((x + ix), _clip (y));
					src = pgm_read_byte (data + ix);
					src <<= (y % 8);
					src = (mix & ~mask) | (src & mask);
					_writeData (src);
				}

				if (_align (y) < _clip (y2)) {

					for (iy = _align (y); iy < _clip (y2); iy += 8) {
						setCursor (x, iy);

						for (ix = 0; ix < width; ix++) {
							src = pgm_read_byte (data + ix) + ((data + ix < end) ? (pgm_read_byte (data + ix + width) << 8) : 0);
							src >>= (_align (y) - y);
							_writeData (src);
						}

						data += width;
					}
				}

				if (_clip (y2) != y2) {

					mask = _bitsBetween (_clip (y2), y2);

					for (ix = 0; ix < width; ix++) {
						mix = _peek (x + ix, _clip (y2));
						src = pgm_read_byte (data + ix) + ((data + ix < end) ? (pgm_read_byte (data + ix + width) << 8) : 0);
						src >>= (_align (y) - y);
						src = (mix & ~mask) | (src & mask);
						_writeData (src);
					}
				}
			}
		}
	}
}

void Noritake_VFD_GUU100::drawLine (uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t on)
{
	int dx, dy, sx, sy, er, e2;

	x0 < x1 ? (dx = x1 - x0, sx = 1) : (dx = x0 - x1, sx = -1);
	y0 < y1 ? (dy = y1 - y0, sy = 1) : (dy = y0 - y1, sy = -1);

	er = dx - dy;

	while (x0 != x1 || y0 != y1) {

		setDot (x0, y0, on);

		e2 = (2 * er);

		if (e2 > -dy) {
			er -= dy;
			x0 += sx;
		}

		if (e2 < dx) {
			er += dx;
			y0 += sy;
		}
	}
}

void Noritake_VFD_GUU100::drawRect (uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint8_t on)
{
	// draw a rectangle from 4 lines
	uint8_t x1;
	uint8_t y1;

	x1 = (x + width);
	y1 = (y + height);

	drawLine (x,  y, x1,  y, on);
	drawLine (x1, y, x1, y1, on);
	drawLine (x1, y1, x, y1, on);
	drawLine (x,  y1, x,  y, on);
}

void Noritake_VFD_GUU100::fillRect (uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint8_t on)
{
	uint8_t x1;
	uint8_t y1;

	x1 = (x + width);
	y1 = (y + height);

	while (y != y1) {
		drawLine (x, y, x1, y, on);
		y++;
	}
}

void Noritake_VFD_GUU100::drawRoundRect (uint8_t cx, uint8_t cy, uint8_t width, uint8_t height, uint8_t radius, uint8_t on)
{
	uint8_t x;
	uint8_t y;
	int16_t tSwitch;

	radius = radius < 1 ? 1 :
			radius > ((width - cx) / 2) ? ((width - cx) / 2) :
			radius > ((height - cy) / 2) ? ((height - cy) / 2) :
			radius;
	x = 0;
	y = radius;
	tSwitch = 3 - 2 * radius;

	while (x <= y) {
		setDot (cx + radius - x, cy + radius - y, on);
		setDot (cx + radius - y, cy + radius - x, on);
		setDot (cx + width - radius + x, cy + radius - y, on);
		setDot (cx + width - radius + y, cy + radius - x, on);
		setDot (cx + width - radius + x, cy + height - radius + y, on);
		setDot (cx + width - radius + y, cy + height - radius + x, on);
		setDot (cx + radius - x, cy + height - radius + y, on);
		setDot (cx + radius - y, cy + height - radius + x, on);

		if (tSwitch < 0) {
			tSwitch += 4 * (x);

		} else {
			tSwitch += 4 * (x - y);
			y--;
		}

		x++;
	}

	drawLine (cx + radius, cy, (cx + radius) + (width - (2 * radius)), cy, on);
	drawLine (cx + radius, cy + height, (cx + radius) + (width - (2 * radius)), cy + height, on);
	drawLine (cx, cy + radius, cx, (cy + radius) + (height - (2 * radius)), on);
	drawLine (cx + width, cy + radius, cx + width, (cy + radius) + (height - (2 * radius)), on);
}

void Noritake_VFD_GUU100::drawEllipse (uint8_t xm, uint8_t ym, uint8_t a, uint8_t b, uint8_t on)
{
	long x = -a, y = 0; /* II. quadrant from bottom left to top right */
	long e2 = b, dx = (1 + 2 * x) * e2 * e2; /* error increment */
	long dy = x * x, err = dx + dy; /* error of 1 step */

	do {
		setDot (xm - x, ym + y, on); /* I. Quadrant */
		setDot (xm + x, ym + y, on); /* II. Quadrant */
		setDot (xm + x, ym - y, on); /* III. Quadrant */
		setDot (xm - x, ym - y, on); /* IV. Quadrant */
		e2 = 2 * err;

		if (e2 >= dx) {
			x++;
			err += dx += 2 * (long) b * b;
		} /* x step */

		if (e2 <= dy) {
			y++;
			err += dy += 2 * (long) a * a;
		} /* y step */
	} while (x <= 0);

	while (y++ < b) { /* too early stop for flat ellipses with a=1, */
		setDot (xm, ym + y, on); /* -> finish tip of ellipse */
		setDot (xm, ym - y, on);
	}
}

void Noritake_VFD_GUU100::drawCircle (uint8_t cx, uint8_t cy, uint8_t radius, uint8_t on)
{
	///////////////////////////////////////////////////////////
	// Stefan Gustavson (stegu@itn.liu.se) 2003-08-20        //
	// webstaff.itn.liu.se/~stegu/circle/circlealgorithm.pdf //
	///////////////////////////////////////////////////////////

	int x = 0;
	int y = radius;
	int d = (5 - (4 * radius));
	int dA = 12;
	int dB = (20 - (8 * radius));

	while (x <= y) {

		setDot (cx - x, cy - y, on);
		setDot (cx - x, cy + y, on);
		setDot (cx + x, cy - y, on);
		setDot (cx + x, cy + y, on);
		setDot (cx - y, cy - x, on);
		setDot (cx - y, cy + x, on);
		setDot (cx + y, cy - x, on);
		setDot (cx + y, cy + x, on);

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

void Noritake_VFD_GUU100::fillCircle (uint8_t cx, uint8_t cy, uint8_t radius, uint8_t on)
{
	int f = 1 - radius;
	int ddF_x = 1;
	int ddF_y = -2 * radius;
	uint8_t x;
	uint8_t y;

	x = 0;
	y = radius;
	drawLine (cx, cy - radius, cx, cy + radius, on);

	while (x < y) {
		if (f >= 0) {
			y--;
			ddF_y += 2;
			f += ddF_y;
		}

		x++;
		ddF_x += 2;
		f += ddF_x;
		drawLine (cx + x, cy + y, cx + x, cy - y, on);
		drawLine (cx - x, cy + y, cx - x, cy - y, on);
		drawLine (cx + y, cy + x, cx + y, cy - x, on);
		drawLine (cx - y, cy + x, cx - y, cy - x, on);
	}
}

void Noritake_VFD_GUU100::setFont (const uint8_t *fontPtr)
{
	if (fontPtr != NULL) {
		_font = _fontStart = fontPtr;
		_fontWidth =    pgm_read_byte (_font++);
		_fontHeight =   pgm_read_byte (_font++);
		_fontHGap =     pgm_read_byte (_font++);
		_fontVGap =     pgm_read_byte (_font++);
		_firstChar =    pgm_read_byte (_font++);
		_bytesPerChar = pgm_read_byte (_font++);
		_next_x =       _fontWidth  + _fontHGap;
		_next_y =       _fontHeight + _fontVGap;
	}
	// now global "_font" points to the first byte of font DATA
	// and "_fontStart" points to the first byte of font itself
	// (used to save and reload a font)
}

const uint8_t *Noritake_VFD_GUU100::getFont (void)
{
	uint8_t w, h;
	return getFont (w, h);
}

const uint8_t *Noritake_VFD_GUU100::getFont (uint8_t &w, uint8_t &h)
{
	w = _fontStart ? _next_x : 0;
	h = _fontStart ? _next_y : 0;
	return _fontStart;
}

size_t Noritake_VFD_GUU100::write (uint8_t c)
{
	size_t n = 0;

	uint8_t _tmp_x = _cur_x;
	uint8_t _tmp_y = _cur_y;

	if (!_font) {
		return _noFont ();
	}

	switch (c) {

		case '\r': {
				return _carriageReturn ();
			}

		case '\n': {
				return _lineFeed ();
			}

		case '\b': {
				return _backSpace ();
			}

		case '\t': {
				if (! (_cur_x % (_next_x * _tab_size))) {
					n += write (0x20);
				}

				while (_cur_x % (_next_x * _tab_size)) {
					n += write (0x20);
				}

				return n;
			}

		default: {
				if (c < _firstChar) {
					return n;
				}
			}

	}

	c -= _firstChar; // normalize char to index
	n++; // count char

	if (_fontHGap) { // clear any horizontal gap space
		fillRect (_tmp_x + _fontWidth, _tmp_y, _fontHGap, _next_y, 0);
	}

	if (_fontVGap) { // clear any vertical gap space
		fillRect (_tmp_x, _tmp_y + _fontHeight, _next_x, _fontVGap, 0);
	}

	drawImage (_font + (c * _bytesPerChar), _tmp_x, _tmp_y, _fontWidth, _fontHeight); // draw new char

	if ((_cur_x + _next_x) < _displayWidth) { // if next col position doesn't hit the end...
		setCursor (_tmp_x + _next_x, _tmp_y); // move it right, keep same row

	} else {
		if ((_cur_y + _next_y) < _displayHeight) { // if can set next line...
			setCursor (0, _tmp_y + _next_y); // reset col to 0 and go to next line

		} else {
			setCursor (0, 0); // otherwise, home 0,0
		}
	}

	return n;
}

////// private functions begin here
uint8_t Noritake_VFD_GUU100::_bitsBetween (uint8_t a, uint8_t b)
{
	if (a / 8 != b / 8) {
		return ~ ((1 << (a % 8)) - 1);

	} else {
		a = (a % 8);
		b = (b % 8);
	}

	return ~ ((1 << a) - 1) & ((1 << b) - 1);
}

size_t Noritake_VFD_GUU100::_noFont (void)
{
	static const uint8_t msg[] PROGMEM = {
		0x7F, 0x04, 0x08, 0x10, 0x7F, 0x00, // 0x4E "N"
		0x3E, 0x41, 0x41, 0x41, 0x3E, 0x00, // 0x4F "O"
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0x20 " "
		0x7F, 0x09, 0x09, 0x09, 0x01, 0x00, // 0x46 "F"
		0x3E, 0x41, 0x41, 0x41, 0x3E, 0x00, // 0x4F "O"
		0x7F, 0x04, 0x08, 0x10, 0x7F, 0x00, // 0x4E "N"
		0x01, 0x01, 0x7F, 0x01, 0x01, 0x00, // 0x54 "T"
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0x20 " "
		0x7F, 0x40, 0x40, 0x40, 0x40, 0x00, // 0x4C "L"
		0x3E, 0x41, 0x41, 0x41, 0x3E, 0x00, // 0x4F "O"
		0x7E, 0x11, 0x11, 0x11, 0x7E, 0x00, // 0x41 "A"
		0x7F, 0x41, 0x41, 0x22, 0x1C, 0x00, // 0x44 "D"
		0x7F, 0x49, 0x49, 0x49, 0x41, 0x00, // 0x45 "E"
		0x7F, 0x41, 0x41, 0x22, 0x1C, 0x00, // 0x44 "D"
	};

	uint8_t x = ((_displayWidth - sizeof (msg)) / 2); // center left/right
	uint8_t y = ((_displayHeight - 8) / 2); // center top/bot

	drawImage (msg, x, y, (sizeof (msg) / sizeof (*msg)), 8);

	return (size_t) 0;
}

void Noritake_VFD_GUU100::_writeData (uint8_t data)
{
	_writePort (data ^ (_invert ? 0xFF : 0x00), 1, (bool) (_cur_x > 63));
	_increment ();
}

uint8_t Noritake_VFD_GUU100::_readData (uint8_t inc)
{
	uint8_t data = (_readPort (1, (bool) (_cur_x > 63)) ^ (_invert ? 0xFF : 0x00));
	inc ? _increment () : setCursor (_cur_x, _cur_y);
	return data;
}

void Noritake_VFD_GUU100::_writeCmd (uint8_t cmd, uint8_t chip)
{
	_writePort (cmd, 0, chip);
}

void Noritake_VFD_GUU100::_increment (void)
{
	_cur_x++;

	if (_cur_x >= _displayWidth) {
		_cur_x = 0;
		_cur_y += 8;

		if (_cur_y >= _displayHeight) {
			_cur_y = 0;
		}
	}

	setCursor (_cur_x, _cur_y);
}

uint8_t Noritake_VFD_GUU100::_peek (uint8_t x, uint8_t y)
{
	uint8_t data;

	if ((x < _displayWidth) && (y < _displayHeight)) {
		setCursor (x, y);
		data = _readData (0);

	} else {
		data = 0;
	}

	return data;
}

uint8_t Noritake_VFD_GUU100::_align (uint8_t x)
{
	return (((x + 7) / 8) * 8);
}

uint8_t Noritake_VFD_GUU100::_clip (uint8_t x)
{
	return ((x / 8) * 8);
}

size_t Noritake_VFD_GUU100::_carriageReturn (void)
{
	setCursor (0, _cur_y); // cursor X position to 0
	return (size_t) 1;
}

size_t Noritake_VFD_GUU100::_lineFeed (void)
{
	if ((_cur_y + _next_y) > _displayHeight) {
		setCursor (_cur_x, 0); // wrap bottom back to top

	} else {
		setCursor (_cur_x, (_cur_y + _next_y)); // cursor down one line
	}

	return (size_t) 1;
}

size_t Noritake_VFD_GUU100::_backSpace (void)
{
	if (_cur_x >= _next_x) {
		// backup 1 char
		setCursor (_cur_x - _next_x, _cur_y);

	} else {
		if (_cur_y >= _next_y) {
			setCursor (_displayWidth - _next_x - (_displayWidth % _next_x), _cur_y - _next_y);

		} else {
			setCursor (_displayWidth - _next_x - (_displayWidth % _next_x), _displayHeight - _next_y);
		}
	}

	return (size_t) -1;
}

void Noritake_VFD_GUU100::_initPort (void)
{
#if GUU_MODE == 1 // SPI mode

	// setup control pins
	C_PORT |= RST | CS1 | CS2;
	C_DDR |= RST | CS1 | CS2;

	// setup SPI pins
	SPI_DDR &= ~_MISO; // MISO is input
	SPI_DDR |= _SCK | _MOSI | _SS; // SCK, MOSI & SS are outputs

	// SPI enable, master mode, mode 3
	SPCR = _BV (SPE) | _BV (MSTR) | _BV (CPOL) | _BV (CPHA);

/////////////////////////////////////////////////////////////////////////////////////////
// at 20 mHz, SPI 2X is flakey on some modules (that is, the timing is close
// to the limit). Experiment. If YOUR module works at 2X speed and 20 mHz, use it.
#if F_CPU > 16000000UL
	SPSR &= ~_BV (SPI2X);
#else
	SPSR |= _BV (SPI2X);
#endif
/////////////////////////////////////////////////////////////////////////////////////////

#else // parallel mode

	// setup control pins
	C_PORT &= ~ (RS | RW | EN | CS1 | CS2); // all low
	C_PORT |= RST; // except reset
	C_DDR |= (RS | RW | EN | CS1 | CS2 | RST); // all outputs

#endif

	// hardware reset - common to both spi and parallel
	_delay_ms (250); // time delay after powerup (GU128X64E manual pg. 17)
	C_PORT &= ~RST;
	_delay_ms (1); // assert reset for 1 msec
	C_PORT |= RST;
	_delay_ms (100); // required delay (GU128X64E manual pg. 10)
}

uint8_t Noritake_VFD_GUU100::_readPort (uint8_t rs, uint8_t chip)
{
	uint8_t data;

#if GUU_MODE == 1 // SPI mode

	C_PORT &= chip ? ~CS2 : ~CS1; // assert active low CS1 or CS2
	_spiTransfer (SPI_READ | (rs << 1)); // send read command w/register select
	data = _spiTransfer (); // read data
	C_PORT |= CS1 | CS2; // de-assert both CS pins
	return data;

#else // parallel mode

	// setup control pins
	// this also pulses EN (dummy read - GU128X64E manual pg. 16)
	C_PORT |= ((chip ? CS2 : CS1) | (rs ? RS : 0) | RW | EN);
	C_PORT &= ~ ((chip ? CS1 : CS2) | (rs ? 0 : RS) | EN);

	// set port as inputs
	D_DDR = 0b00000000;

	// strobe vfd data to avr
	C_PORT |= EN;

	// delay (GU128X64E manual pg. 10) says ~300 ns, but 250 is way good enough
	// experiment: remove a few NOPs and see if your module is stable, if so go with it.
	asm volatile (
		"\tnop\n" // for 8.0 MHz clock, 250 ns delay
		"\tnop\n"
#if F_CPU > 8000000UL
		"\tnop\n" // for 16.0 MHz clock, 250 ns delay
		"\tnop\n"
#if F_CPU > 16000000UL
		"\tnop\n" // for 20.0 MHz clock, 250 ns delay
#endif
#endif
	);

	// read data from VFD
	data = D_PIN;

	// de-assert enable
	C_PORT &= ~EN;

	return data;

#endif
}

void Noritake_VFD_GUU100::_writePort (uint8_t data, uint8_t rs, uint8_t chip)
{
#if GUU_MODE == 1 // SPI mode

	C_PORT &= chip ? ~CS2 : ~CS1; // assert active low CS1 or CS2
	_spiTransfer (SPI_WRITE | (rs << 1)); // send write command w/register select
	_spiTransfer (data); // send data
	C_PORT |= CS1 | CS2; // de-assert both CS pins

#else // parallel mode

	// setup control pins
	C_PORT |= ((chip ? CS2 : CS1) | (rs ? RS : 0));
	C_PORT &= ~ ((chip ? CS1 : CS2) | (rs ? 0 : RS) | RW);

	// set port as outputs
	D_DDR = 0b11111111;

	// put data on the bus avr -> vfd
	D_PORT = data;

	// strobe it in to the vfd
	C_PORT |= EN;
	C_PORT &= ~EN;

#endif
}

#if GUU_MODE == 1 // SPI mode
// you can also use a bit-bang SPI, but it's terribly S-L-O-W
uint8_t Noritake_VFD_GUU100::_spiTransfer (uint8_t data)
{
	SPDR = data; // write to SPI data register
	while (! (SPSR & _BV (SPIF))); // wait for all of it to be shifted
	return SPDR; // return read data
}

#endif

//////// end of Noritake_VFD_GUU100.cpp ////////
