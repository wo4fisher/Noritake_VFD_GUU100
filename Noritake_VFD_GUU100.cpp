///////////////////////////////////////////////////////////////////////////////
//
//  Noritake GU128X64E-U100 VFD Display Driver Library for Arduino
//  Copyright (c) 2012, 2015 Roger A. Krupski <rakrupski@verizon.net>
//
//  Last update: 18 June 2015
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
	_initPort();  // initialize the SPI or parallel port
	_displayWidth = 128; // init display...
	_displayHeight = 64; // ... dimensions
	_firstChar = 0; // zero out font info
	_fontWidth = 0; // font bare pixel width
	_fontHeight = 0; // font bare pixel height
	_fontHGap = 0; // inter-char gap (horizontal)
	_fontVGap = 0; // inter-char gap (vertical)
	_bytesPerChar = 0; // how many bytes in each char image
	_cur_x = 0; // current X position
	_cur_y = 0; // current Y position
	_cur_z = 0; // current scroll offset
	_next_x = 0; // x size of character cell
	_next_y = 0; // y size of character cell
	_invert = 0; // display invert yes/no
	_font = 0; // invalidate font address pointer
	_fontStart = 0; // invalidate font start pointer
	clearScreen();  // clear screen
	home (1); // home cursor x/y and reset scroll
	setBrightness (100); // default screen brightness = 100
	setDisplay (1); // turn display on
}

void Noritake_VFD_GUU100::setDisplay (uint8_t on)
{
	_writeDisplay (SETDISP | (on ? 0x01 : 0x00));
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
	_writeDisplay (FUNC_SET);
	_writeDisplay ((percent ? (SETBRITE | FILAMENT) : (SETBRITE & ~FILAMENT)) | _displayBright);
	_writeDisplay (FUNC_SET);
	_writeDisplay ((percent ? (SETBRITE | FILAMENT) : (SETBRITE & ~FILAMENT)) | _displayBright);
	return _displayBright;
}

void Noritake_VFD_GUU100::setScroll (uint8_t z)
{
	_setScroll (z);
}

uint8_t Noritake_VFD_GUU100::getScroll (void)
{
	return (_cur_z % 64);
}

void Noritake_VFD_GUU100::setLine (float x, float y)
{
	_setCursor (((x * _next_x) + 0.5), ((y * _next_y) + 0.5));
}

void Noritake_VFD_GUU100::getLine (float &x, float &y)
{
	x = (float) (_cur_x / _next_x);
	y = (float) (_cur_y / _next_y);
}

void Noritake_VFD_GUU100::setCursor (uint8_t x, uint8_t y)
{
	_setCursor (x, y);
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
	y = (addr / _displayWidth);
	x = (addr - (y * _displayWidth));
	on ? _setDot (x, y, 1) : _setDot (x, y, 1);
}

uint8_t Noritake_VFD_GUU100::getPixel (uint16_t addr)
{
	uint8_t x;
	uint8_t y;
	y = (addr / _displayWidth);
	x = (addr - (y * _displayWidth));
	return getDot (x, y) ? 1 : 0;
}

void Noritake_VFD_GUU100::setDot (uint8_t x, uint8_t y, uint8_t on)
{
	_setDot (x, y, on);
}

uint8_t Noritake_VFD_GUU100::getDot (uint8_t x, uint8_t y)
{
	return (_getBits (x, y) & (1 << (y % 8))) ? 1 : 0;
}

void Noritake_VFD_GUU100::setInvert (uint8_t inv)
{
	_invert = inv ? 1 : 0;
}

void Noritake_VFD_GUU100::clearScreen (uint8_t pattern)
{
	uint16_t n = (_displayWidth * (_displayHeight / 8));

	while (n--) {
		_writeData (pattern); // erase screen
	}

	_setCursor (0, 0); // home cursor
}

void Noritake_VFD_GUU100::drawImage (uint32_t data, uint8_t x, uint8_t y, uint8_t width, uint8_t height)
{
	uint8_t mask, mix, ix, iy, y2;
	uint16_t src;
	uint32_t end;

	if ((x < _displayWidth) && (y < _displayHeight)) {
		y2 = (y + height);

		if (_clip (y) == _clip (y2)) {
			mask = _bitsBetween (y, y2);

			for (ix = 0; ix < width; ix++) {
				mix = _getBits (x + ix, _clip (y));
				src = PGM_READ (data + ix);
				src <<= (y % 8);
				src = (mix & ~mask) | (src & mask);
				_writeData (src);
			}

		} else {
			if (y == _clip (y)) {
				for (iy = y; iy < _clip (y2); iy += 8) {
					setCursor (x, iy);

					for (ix = 0; ix < width; ix++) {
						src = PGM_READ (data + ix);
						_writeData (src);
					}

					data += width;
				}

				if (y2 != _clip (y2)) {
					mask = _bitsBetween (_clip (y2), y2);

					for (ix = 0; ix < width; ix++) {
						mix = _getBits (x + ix, _clip (y2));
						src = PGM_READ (data + ix);
						src = (mix & ~mask) | (src & mask);
						_writeData (src);
					}
				}

			} else {
				mask = _bitsBetween (y, _align (y));
				end = ((width * height) + data);

				for (ix = 0; ix < width; ix++) {
					mix = _getBits ((x + ix), _clip (y));
					src = PGM_READ (data + ix);
					src <<= (y % 8);
					src = (mix & ~mask) | (src & mask);
					_writeData (src);
				}

				if (_align (y) < _clip (y2)) {
					for (iy = _align (y); iy < _clip (y2); iy += 8) {
						setCursor (x, iy);

						for (ix = 0; ix < width; ix++) {
							src = PGM_READ (data + ix) + ((data + ix < end) ? (PGM_READ (data + ix + width) << 8) : 0);
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
						src = PGM_READ (data + ix) + ((data + ix < end) ? (PGM_READ (data + ix + width) << 8) : 0);
						src >>= (_align (y) - y);
						src = (mix & ~mask) | (src & mask);
						_writeData (src);
					}
				}
			}
		}
	}
}

void Noritake_VFD_GUU100::drawVect (uint8_t x, uint8_t y, uint8_t radius, long int theta, uint8_t on)
{
	uint8_t x1 = cos (rad (theta - 90.0)) * radius + x + 0.5;
	uint8_t y1 = sin (rad (theta - 90.0)) * radius + y + 0.5;
	drawLine (x, y, x1, y1, on);
}

void Noritake_VFD_GUU100::drawLine (uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t on)
{
	int dx, dy, sx, sy, er, e2;
	x0 < x1 ? (dx = x1 - x0, sx = 1) : (dx = x0 - x1, sx = -1);
	y0 < y1 ? (dy = y1 - y0, sy = 1) : (dy = y0 - y1, sy = -1);
	er = dx - dy;

	while (! (x0 == x1 && y0 == y1)) {
		on ? _setDot (x0, y0, 1) : _setDot (x0, y0, 0);
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
	drawLine (x, y, x1, y, on);
	drawLine (x1, y, x1, y1, on);
	drawLine (x1, y1, x, y1, on);
	drawLine (x, y1, x, y, on);
}

void Noritake_VFD_GUU100::fillRect (uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint8_t on)
{
	uint8_t x1 = (x + width);
	uint8_t y1 = (y + height);

	for (x = x; x < x1; x++) {
		drawLine (x, y, x, y1, on);
	}
}

void Noritake_VFD_GUU100::drawRoundRect (uint8_t cx, uint8_t cy, uint8_t width, uint8_t height, uint8_t radius, uint8_t on)
{
	uint8_t x;
	uint8_t y;
	int16_t tSwitch;
	x = 0;
	y = radius;
	tSwitch = 3 - 2 * radius;

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
		on ? _setDot (xm - x, ym + y, 1) : _setDot (xm - x, ym + y, 0); /* I. Quadrant */
		on ? _setDot (xm + x, ym + y, 1) : _setDot (xm + x, ym + y, 0); /* II. Quadrant */
		on ? _setDot (xm + x, ym - y, 1) : _setDot (xm + x, ym - y, 0); /* III. Quadrant */
		on ? _setDot (xm - x, ym - y, 1) : _setDot (xm - x, ym - y, 0); /* IV. Quadrant */
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
		on ? _setDot (xm, ym + y, 1) : _setDot (xm, ym + y, 0); /* -> finish tip of ellipse */
		on ? _setDot (xm, ym - y, 1) : _setDot (xm, ym - y, 0);
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

void Noritake_VFD_GUU100::setFont (uint32_t fontPtr)
{
	_font = _fontStart = fontPtr;

	if (fontPtr) {
		_fontWidth = PGM_READ (_font++);
		_fontHeight = PGM_READ (_font++);
		_fontHGap = PGM_READ (_font++);
		_fontVGap = PGM_READ (_font++);
		_firstChar = PGM_READ (_font++);
		_bytesPerChar = PGM_READ (_font++);
		_next_x = _fontWidth + _fontHGap;
		_next_y = _fontHeight + _fontVGap;
	}

	// now global "_font" points to the first byte of font DATA
	// and "_fontStart" points to the first byte of font itself
	// (used to save and reload a font)
}

uint32_t Noritake_VFD_GUU100::getFont (void)
{
	return _fontStart;
}

void Noritake_VFD_GUU100::getFontDat (void *data)
{
	*((uint8_t *) (data + charWidth)) = _fontStart ? _next_x : 0;
	*((uint8_t *) (data + charHeight)) = _fontStart ? _next_y : 0;
	*((uint8_t *) (data + maxChars)) = _fontStart ? _displayWidth / _next_x : 0;
	*((uint8_t *) (data + maxLines)) = _fontStart ? _displayHeight / _next_y : 0;
}

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

inline size_t Noritake_VFD_GUU100::write (uint8_t c)
{
	size_t n = 0;
	_tmp_x = _cur_x; // save current cursor location
	_tmp_y = _cur_y;

	if (!_font) {
		return _noFont();
	}

	switch (c) {
		case '\b': {
				return _backSpace();
			}

		case '\t': {
				return _doTabs (4); // tabs are 4 spaces
			}

		case '\n': {
				return _lineFeed();
			}

		case '\f': {
				clearScreen();
				return n;
			}

		case '\r': {
				return _carriageReturn();
			}

		default: {
				break;
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
		_setCursor (_tmp_x + _next_x, _tmp_y); // move it right, keep same row

	} else {
		if ((_cur_y + _next_y) < _displayHeight) { // if can set next line...
			_setCursor (0, _tmp_y + _next_y); // reset col to 0 and go to next line

		} else {
			_setCursor (0, 0); // otherwise, home 0,0
		}
	}

	return n;
}

////// private functions begin here
size_t Noritake_VFD_GUU100::_noFont (void)
{
	static const uint8_t msg[] PROGMEM = {
		0x7F, 0x04, 0x08, 0x10, 0x7F, 0x00, // "N"
		0x3E, 0x41, 0x41, 0x41, 0x3E, 0x00, // "O"
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // " "
		0x7F, 0x09, 0x09, 0x09, 0x01, 0x00, // "F"
		0x3E, 0x41, 0x41, 0x41, 0x3E, 0x00, // "O"
		0x7F, 0x04, 0x08, 0x10, 0x7F, 0x00, // "N"
		0x01, 0x01, 0x7F, 0x01, 0x01, 0x00, // "T"
	};
	_tmp_x = ((_displayWidth - sizeof (msg)) / 2); // center left/right
	_tmp_y = ((_displayHeight - 8) / 2); // center top/bot
	_tmp_z = (sizeof (msg) / sizeof (*msg)); // how many chars
	clearScreen();  // clear any graphics off screen before message
	home (1); // reset cursor x/y and zero scroll
	drawImage (pgm_get_far_address (msg), _tmp_x, _tmp_y, _tmp_z, 8); // draw entire message as one graphic block
	return 0;
}

void Noritake_VFD_GUU100::_writeDisplay (uint8_t cmd)
{
	uint8_t _old_x = _cur_x;
	_cur_x = 0;
	_writePort (cmd, 0);
	_cur_x = 64;
	_writePort (cmd, 0);
	_cur_x = _old_x;
}

inline uint8_t Noritake_VFD_GUU100::_bitsBetween (uint8_t a, uint8_t b)
{
	if (a / 8 != b / 8) {
		return ~ ((1 << (a % 8)) - 1);

	} else {
		a = (a % 8);
		b = (b % 8);
	}

	return ~ ((1 << a) - 1) & ((1 << b) - 1);
}

inline void Noritake_VFD_GUU100::_writeData (uint8_t data)
{
	_writePort (data ^ (_invert ? 0xFF : 0x00), 1);
	_increment();
}

inline uint8_t Noritake_VFD_GUU100::_readData (void)
{
	uint8_t data = (_readPort (1) ^ (_invert ? 0xFF : 0x00));
	_increment();
	return data;
}

inline void Noritake_VFD_GUU100::_writeCmd (uint8_t cmd)
{
	_writePort (cmd, 0);
}

inline void Noritake_VFD_GUU100::_increment (void)
{
	_cur_x++;

	if (_cur_x >= _displayWidth) {
		_cur_x = 0; // zero X axis
		_cur_y += 8; // next line

		if (_cur_y >= _displayHeight) {
			_cur_y = 0; // if at bottom, revert to top
		}
	}

	_setCursor (_cur_x, _cur_y);
}

inline void Noritake_VFD_GUU100::_setDot (uint8_t x, uint8_t y, uint8_t on)
{
	if (x < _displayWidth && y < _displayHeight) {
		uint8_t data = on ? _getBits (x, y) | (1 << (y % 8)) : _getBits (x, y) & ~ (1 << (y % 8));
		_writeData (data);
	}
}

inline void Noritake_VFD_GUU100::_setCursor (uint8_t x, uint8_t y)
{
	_cur_x = x; // update x and y...
	_cur_y = y; // ...cursor position
	_writeCmd (SETADDR | _cur_x); // set...
	_writeCmd (SETPAGE | (_cur_y / 8) % 8); //...display
}

inline void Noritake_VFD_GUU100::_setScroll (uint8_t z)
{
	_cur_z = z;
	_writeDisplay (SETLINE | _cur_z); // set it
}

inline uint8_t Noritake_VFD_GUU100::_getBits (uint8_t x, uint8_t y)
{
	_setCursor (x, y);
	uint8_t data = (_readPort (1) ^ (_invert ? 0xFF : 0x00));
	_setCursor (x, y);
	return data;
}

inline uint8_t Noritake_VFD_GUU100::_align (uint8_t x)
{
	return (((x + 7) / 8) * 8);
}

inline uint8_t Noritake_VFD_GUU100::_clip (uint8_t x)
{
	return ((x / 8) * 8);
}

inline size_t Noritake_VFD_GUU100::_carriageReturn (void)
{
	_setCursor (0, _cur_y); // cursor X position to 0
	return (size_t) 1;
}

inline size_t Noritake_VFD_GUU100::_lineFeed (void)
{
	if ((_cur_y + _next_y) > _displayHeight) {
		_setCursor (_cur_x, 0); // wrap bottom back to top

	} else {
		_setCursor (_cur_x, (_cur_y + _next_y)); // cursor down one line
	}

	return (size_t) 1;
}

inline size_t Noritake_VFD_GUU100::_backSpace (void)
{
	_tmp_x = _cur_x;
	_tmp_y = _cur_y;

	if (_cur_x >= _next_x) {
		// backup 1 char
		_setCursor ((_tmp_x - _next_x), _tmp_y);
		write (0x20);
		_setCursor ((_tmp_x - _next_x), _tmp_y);

	} else {
		if (_tmp_y >= _next_y) {
			_setCursor ((_displayWidth - _next_x) - (_displayWidth % _next_x), (_tmp_y - _next_y));
			write (0x20);
			_setCursor ((_displayWidth - _next_x) - (_displayWidth % _next_x), (_tmp_y - _next_y));

		} else {
			_setCursor ((_displayWidth - _next_x) - (_displayWidth % _next_x), (_displayHeight - _next_y));
			write (0x20);
			_setCursor ((_displayWidth - _next_x) - (_displayWidth % _next_x), (_displayHeight - _next_y));
		}
	}

	return (size_t) - 1;
}

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

inline void Noritake_VFD_GUU100::_initPort (void)
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
	#if (! (F_CPU > 16000000UL))
		SPSR |= _BV (SPI2X); // double speed SPI if F_CPU 16 or less
	#endif
#else // parallel mode
	// setup control pins
	C_PORT &= ~ (RS | RW | EN | CS1 | CS2); // all low
	C_PORT |= RST; // except reset
	C_DDR |= (RS | RW | EN | CS1 | CS2 | RST); // all outputs
	D_DDR = 0b11111111; // set data port as outputs
#endif
	// hardware reset - common to both spi and parallel
	_delay_ms (250); // time delay after powerup (GU128X64E manual pg. 17)
	C_PORT &= ~RST;
	_delay_ms (10); // assert reset for 10 msec
	C_PORT |= RST;
	_delay_ms (100); // required delay (GU128X64E manual pg. 10)
}

inline uint8_t Noritake_VFD_GUU100::_readPort (uint8_t rs)
{
	uint8_t data;
	uint8_t chip = (_cur_x > 63);
#if GUU_MODE == 1 // SPI mode
	C_PORT &= chip ? ~CS2 : ~CS1; // assert active low CS1 or CS2
	_spiTransfer (SPI_READ | (rs << 1)); // send read command w/register select
	data = _spiTransfer();  // read data
	C_PORT |= CS1 | CS2; // de-assert both CS pins
	return data;
#else // parallel mode
	// set parallel data port as inputs
	D_DDR = 0b00000000;
	// set proper cs1/2 and pulse EN (dummy read - GU128X64E manual pg. 16)
	C_PORT |= ((chip ? CS2 : CS1) | (rs ? RS : 0) | RW | EN);
	C_PORT &= ~ ((chip ? CS1 : CS2) | (rs ? 0 : RS) | EN);
	C_PORT |= EN; // assert enable
	// parallel EN -> data valid delay (320 ns) - GU128X64E manual pg. 10
	asm volatile (
		"\tnop\n"
		"\tnop\n"
		"\tnop\n" // 375 ns @ 8 MHz.
	#if F_CPU > 8000000UL
			"\tnop\n"
			"\tnop\n"
			"\tnop\n" // 375 ns @ 16 MHz.
		#if F_CPU > 16000000UL
				"\tnop\n"
				"\tnop\n" // 400 ns @ 20+ MHz.
		#endif
	#endif
	);
	data = D_PIN; // read a byte from VFD
	C_PORT &= ~EN; // de-assert enable
	// we set the data port back to outputs so that _writePort
	// doesn't have to do it every time - and writes occur about
	// 9 times for every read so it makes things a lot faster.
	D_DDR = 0b11111111;
	return data;
#endif
}

inline void Noritake_VFD_GUU100::_writePort (uint8_t data, uint8_t rs)
{
	uint8_t chip = (_cur_x > 63);
#if GUU_MODE == 1 // SPI mode
	C_PORT &= chip ? ~CS2 : ~CS1; // assert active low CS1 or CS2
	_spiTransfer (SPI_WRITE | (rs << 1)); // send write command w/register select
	_spiTransfer (data); // send data
	C_PORT |= CS1 | CS2; // de-assert both CS pins
#else // parallel mode
	// set proper cs1/2
	C_PORT |= ((chip ? CS2 : CS1) | (rs ? RS : 0));
	C_PORT &= ~ ((chip ? CS1 : CS2) | (rs ? 0 : RS) | RW);
	C_PORT |= EN; // assert enable
	D_PORT = data; // write data to data port
	C_PORT &= ~EN; // de-assert enable (latch data to vfd on falling edge)
#endif
}

#if GUU_MODE == 1 // SPI mode
inline uint8_t Noritake_VFD_GUU100::_spiTransfer (uint8_t data)
{
	SPDR = data; // write to SPI data register
	while (! (SPSR & _BV (SPIF))); // wait for all of it to be shifted
	return SPDR; // return read data
}

#endif
//////// end of Noritake_VFD_GUU100.cpp ////////
