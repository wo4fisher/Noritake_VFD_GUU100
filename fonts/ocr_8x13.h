///////////////////////////////////////////////////////////////////////////////
//
//  Font "OCR_8X13.H" for the Noritake GU128X64E-U100 VFD display
//  Copyright (c) 2012, 2015 Roger A. Krupski <rakrupski@verizon.net>
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

#ifndef OCR_8X13_H
#define OCR_8X13_H

#define ocr_8x13 pgm_get_far_address(_ocr_8x13)

static const uint8_t _ocr_8x13[] PROGMEM = {

	0x08, // width (base + 0)
	0x0d, // height (base + 1)
	0x00, // horizontal gap (base + 2)
	0x00, // vertical gap (base + 3)
	0x30, // first char (base + 4)
	0x10, // bytes per char (base + 5)

	0xfc, 0xfe, 0x06, 0x06, 0x06, 0xfe, 0xfc, 0x00,
	0x07, 0x0f, 0x0c, 0x0c, 0x0c, 0x0f, 0x07, 0x00,
	0x06, 0x06, 0xfe, 0xfe, 0x00, 0x80, 0x80, 0x00,
	0x0c, 0x0c, 0x0f, 0x0f, 0x0c, 0x0f, 0x0f, 0x00,
	0xc6, 0xe6, 0x66, 0x66, 0x66, 0x7e, 0x3c, 0x00,
	0x0f, 0x0f, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x00,
	0x06, 0x66, 0x66, 0x66, 0x66, 0xfe, 0xfc, 0x00,
	0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0f, 0x07, 0x00,
	0xfe, 0xfe, 0x80, 0x80, 0xfc, 0xfc, 0x80, 0x00,
	0x01, 0x01, 0x01, 0x01, 0x0f, 0x0f, 0x01, 0x00,
	0x00, 0x7e, 0x7e, 0x66, 0x66, 0xe6, 0xc6, 0x00,
	0x0e, 0x0c, 0x0c, 0x0c, 0x0c, 0x0f, 0x07, 0x00,
	0xfc, 0xfe, 0xc6, 0xc0, 0xc0, 0xc0, 0x80, 0x00,
	0x07, 0x0f, 0x0c, 0x0c, 0x0c, 0x0f, 0x07, 0x00,
	0x0e, 0x0e, 0x86, 0xc6, 0xe6, 0x7e, 0x3e, 0x00,
	0x00, 0x00, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00,
	0xc0, 0xfc, 0xfe, 0xc6, 0xfe, 0xfc, 0xc0, 0x00,
	0x07, 0x0f, 0x0c, 0x0c, 0x0c, 0x0f, 0x07, 0x00,
	0x3c, 0x7e, 0x66, 0x66, 0x66, 0xfe, 0xfc, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x0c, 0x0f, 0x07, 0x00,
	0x00, 0x00, 0x38, 0x38, 0x38, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00,
};

#endif

