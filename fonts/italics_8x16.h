///////////////////////////////////////////////////////////////////////////////
//
//  Font "ITALICS_8X16.H" for the Noritake GU128X64E-U100 VFD display
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

#ifndef ITALICS_8X16_H
#define ITALICS_8X16_H

#define italics_8x16 pgm_get_far_address(_italics_8x16)

static const uint8_t _italics_8x16[] PROGMEM = {

	0x08, // width (base + 0)
	0x10, // height (base + 1)
	0x00, // horizontal gap (base + 2)
	0x00, // vertical gap (base + 3)
	0x00, // first char (base + 4)
	0x7f, // last char (base + 5)
	0x10, // bytes per char (base + 6)

	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0xf0, 0x08, 0x94, 0x84, 0x84, 0x94, 0x04, 0xfc, 0x0f, 0x08, 0x08, 0x09, 0x09, 0x08, 0x04, 0x03,
	0xf0, 0xf8, 0x6c, 0x7c, 0x7c, 0x6c, 0xfc, 0xfc, 0x0f, 0x0f, 0x0f, 0x0e, 0x0e, 0x0f, 0x07, 0x03,
	0xe0, 0xf0, 0xf0, 0xe0, 0xf0, 0xf0, 0xf0, 0x60, 0x00, 0x03, 0x0f, 0x07, 0x03, 0x01, 0x00, 0x00,
	0x80, 0xc0, 0xe0, 0xf0, 0xf0, 0xc0, 0x80, 0x00, 0x00, 0x01, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00,
	0x80, 0xc0, 0xf0, 0x38, 0x38, 0xf8, 0xc0, 0xc0, 0x01, 0x09, 0x0b, 0x0e, 0x0e, 0x03, 0x01, 0x00,
	0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xf8, 0xf0, 0xe0, 0x00, 0x09, 0x0d, 0x0f, 0x0b, 0x01, 0x01, 0x00,
	0x00, 0x00, 0x80, 0x80, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00,
	0xff, 0xff, 0x7f, 0x7f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xfc, 0xfe, 0xfe, 0xff, 0xff,
	0x00, 0xc0, 0x60, 0x20, 0x20, 0x60, 0xe0, 0x00, 0x00, 0x07, 0x06, 0x04, 0x04, 0x06, 0x03, 0x00,
	0xff, 0x3f, 0x9f, 0xdf, 0xdf, 0xdf, 0x1f, 0xff, 0xff, 0xf8, 0xfb, 0xfb, 0xfb, 0xf9, 0xfc, 0xff,
	0x00, 0x80, 0x40, 0x60, 0xf4, 0x9c, 0x0c, 0x3c, 0x07, 0x0f, 0x0c, 0x0c, 0x07, 0x03, 0x00, 0x00,
	0x00, 0xf0, 0xbc, 0x84, 0x84, 0xf4, 0x7c, 0x00, 0x04, 0x02, 0x0a, 0x0f, 0x07, 0x02, 0x03, 0x00,
	0x00, 0x00, 0xfc, 0xfc, 0x14, 0x16, 0x12, 0x1e, 0x0c, 0x0e, 0x0f, 0x07, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xf8, 0xfc, 0x14, 0x14, 0x16, 0xf2, 0xfe, 0x1c, 0x1f, 0x0f, 0x00, 0x00, 0x0e, 0x0f, 0x07,
	0xa0, 0xa0, 0xc0, 0x78, 0x78, 0xc8, 0xa0, 0xa0, 0x02, 0x02, 0x09, 0x0f, 0x0f, 0x01, 0x02, 0x02,
	0x00, 0xfc, 0xfe, 0xf0, 0xe0, 0xe0, 0x40, 0x40, 0x0c, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00,
	0x40, 0x40, 0xe0, 0xe0, 0xf0, 0xf8, 0xfc, 0x06, 0x00, 0x00, 0x00, 0x00, 0x01, 0x0f, 0x07, 0x00,
	0x00, 0x00, 0x90, 0xd8, 0x7c, 0x3c, 0x18, 0x10, 0x01, 0x03, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00,
	0x00, 0xe0, 0xfc, 0x1c, 0x00, 0xe0, 0xfc, 0x1c, 0x0c, 0x0d, 0x01, 0x00, 0x0c, 0x0d, 0x01, 0x00,
	0x38, 0x7c, 0x44, 0xfc, 0xfc, 0x04, 0xfc, 0xfc, 0x00, 0x0c, 0x0f, 0x03, 0x0c, 0x0f, 0x03, 0x00,
	0x00, 0xc0, 0xe8, 0x3c, 0x16, 0x32, 0xe6, 0xce, 0x1c, 0x18, 0x11, 0x1b, 0x0e, 0x07, 0x01, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x07, 0x00,
	0x00, 0x00, 0x90, 0xd8, 0x7c, 0x3c, 0x18, 0x10, 0x09, 0x0b, 0x0f, 0x0f, 0x0b, 0x09, 0x00, 0x00,
	0x00, 0x10, 0x98, 0xfc, 0x7c, 0x18, 0x10, 0x00, 0x00, 0x0c, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x80, 0xf0, 0x7c, 0x0c, 0x00, 0x00, 0x02, 0x06, 0x0f, 0x0f, 0x06, 0x02, 0x00,
	0x00, 0x00, 0x80, 0xa0, 0xe0, 0xc0, 0x80, 0x00, 0x01, 0x01, 0x01, 0x02, 0x03, 0x01, 0x00, 0x00,
	0x80, 0xc0, 0xe0, 0xa0, 0xc0, 0x40, 0x40, 0x00, 0x00, 0x01, 0x03, 0x02, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x02, 0x02, 0x03, 0x01, 0x01, 0x00,
	0x80, 0xc0, 0xe0, 0x80, 0x40, 0xf0, 0xe0, 0x40, 0x00, 0x01, 0x03, 0x00, 0x00, 0x01, 0x00, 0x00,
	0x00, 0x80, 0xe0, 0xf0, 0xf8, 0xc0, 0x00, 0x00, 0x06, 0x07, 0x07, 0x07, 0x07, 0x07, 0x06, 0x00,
	0x30, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0x30, 0x00, 0x00, 0x01, 0x0f, 0x07, 0x03, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x80, 0xf8, 0x7c, 0x3c, 0x18, 0x00, 0x00, 0x00, 0x0d, 0x0d, 0x00, 0x00, 0x00, 0x00,
	0x0c, 0x1e, 0x02, 0x00, 0x1c, 0x0e, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x20, 0xe0, 0xf8, 0x38, 0xe0, 0xf8, 0x38, 0x02, 0x0e, 0x0f, 0x03, 0x0e, 0x0f, 0x03, 0x00,
	0x00, 0x20, 0x78, 0x5c, 0x44, 0x47, 0xc7, 0x8c, 0x06, 0x0c, 0x08, 0x38, 0x38, 0x0f, 0x07, 0x00,
	0x20, 0x30, 0x10, 0x80, 0xc0, 0x60, 0x30, 0x10, 0x0c, 0x06, 0x03, 0x01, 0x00, 0x08, 0x0c, 0x04,
	0x00, 0x80, 0xc0, 0x78, 0xfc, 0xa4, 0xdc, 0x58, 0x07, 0x0f, 0x08, 0x08, 0x07, 0x0f, 0x08, 0x00,
	0x00, 0x00, 0x10, 0x1c, 0x0e, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xe0, 0xf0, 0x18, 0x0c, 0x04, 0x00, 0x00, 0x03, 0x07, 0x0c, 0x08, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x04, 0xec, 0xf8, 0x10, 0x00, 0x00, 0x08, 0x0c, 0x07, 0x03, 0x00, 0x00, 0x00,
	0x80, 0xa0, 0xe0, 0xc0, 0xe0, 0xe0, 0xa0, 0x80, 0x00, 0x02, 0x03, 0x03, 0x01, 0x03, 0x02, 0x00,
	0x00, 0x80, 0x80, 0xc0, 0xe0, 0xa0, 0x80, 0x00, 0x00, 0x00, 0x02, 0x03, 0x01, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x1c, 0x0e, 0x02, 0x00, 0x00,
	0x80, 0x80, 0x80, 0xc0, 0x40, 0x40, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x0c, 0x0c, 0x04, 0x00, 0x00,
	0x00, 0x00, 0x80, 0xc0, 0x60, 0x30, 0x18, 0x00, 0x06, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
	0xf0, 0xf8, 0x0c, 0xc4, 0xc4, 0x04, 0xfc, 0xf8, 0x07, 0x0f, 0x08, 0x08, 0x08, 0x0c, 0x07, 0x03,
	0x00, 0x00, 0x10, 0xf8, 0xfc, 0x1c, 0x00, 0x00, 0x08, 0x08, 0x0f, 0x0f, 0x08, 0x08, 0x00, 0x00,
	0x00, 0x08, 0x0c, 0x84, 0xc4, 0x7c, 0x38, 0x00, 0x0c, 0x0e, 0x0b, 0x09, 0x0c, 0x0c, 0x00, 0x00,
	0x00, 0x08, 0x4c, 0x44, 0xc4, 0xfc, 0x38, 0x00, 0x04, 0x0c, 0x08, 0x0c, 0x07, 0x03, 0x00, 0x00,
	0x80, 0xc0, 0xe0, 0xb0, 0x98, 0xec, 0xfc, 0x9c, 0x00, 0x00, 0x08, 0x0c, 0x0f, 0x03, 0x00, 0x00,
	0x00, 0x60, 0x78, 0x5c, 0xc4, 0x84, 0x04, 0x0c, 0x04, 0x0c, 0x08, 0x0c, 0x07, 0x03, 0x00, 0x00,
	0x00, 0xe0, 0xf0, 0x58, 0x4c, 0xc4, 0x8c, 0x08, 0x07, 0x0f, 0x08, 0x08, 0x0c, 0x07, 0x03, 0x00,
	0x00, 0x0c, 0x0c, 0x84, 0xc4, 0x64, 0x3c, 0x1c, 0x00, 0x0c, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xb0, 0xf8, 0x4c, 0xe4, 0xfc, 0x1c, 0x00, 0x0f, 0x0f, 0x08, 0x0c, 0x07, 0x03, 0x00, 0x00,
	0x30, 0x78, 0x4c, 0x44, 0x44, 0xfc, 0xf8, 0x00, 0x08, 0x08, 0x08, 0x0c, 0x07, 0x03, 0x01, 0x00,
	0x00, 0x00, 0x00, 0x20, 0x30, 0x30, 0x10, 0x00, 0x00, 0x04, 0x06, 0x06, 0x02, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x20, 0x30, 0x30, 0x10, 0x00, 0x10, 0x18, 0x0e, 0x06, 0x02, 0x00, 0x00, 0x00,
	0x80, 0xc0, 0x40, 0x20, 0x30, 0x18, 0x08, 0x00, 0x00, 0x03, 0x07, 0x0c, 0x08, 0x00, 0x00, 0x00,
	0x00, 0x20, 0x20, 0xa0, 0xb0, 0x90, 0x10, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x08, 0x18, 0x70, 0xe0, 0x80, 0x00, 0x08, 0x0c, 0x06, 0x02, 0x01, 0x01, 0x00, 0x00,
	0x00, 0x18, 0x1c, 0xc4, 0xe4, 0x3c, 0x1c, 0x00, 0x00, 0x00, 0x0d, 0x0d, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xc0, 0xf0, 0x38, 0x88, 0xc8, 0xc8, 0xf8, 0x06, 0x0f, 0x09, 0x0a, 0x0b, 0x0b, 0x01, 0x00,
	0x00, 0x00, 0xe0, 0xf8, 0x9c, 0x84, 0xfc, 0xfc, 0x0c, 0x0f, 0x03, 0x00, 0x0c, 0x0f, 0x03, 0x00,
	0x00, 0x00, 0xe4, 0xfc, 0x5c, 0xc4, 0xfc, 0x3c, 0x08, 0x0f, 0x0f, 0x08, 0x0e, 0x07, 0x01, 0x00,
	0x00, 0xc0, 0xf0, 0x38, 0x0c, 0x04, 0x04, 0x1c, 0x07, 0x0f, 0x08, 0x0c, 0x06, 0x03, 0x00, 0x00,
	0x00, 0x00, 0xe4, 0xfc, 0x1c, 0x04, 0xfc, 0xf8, 0x08, 0x0f, 0x0f, 0x08, 0x0c, 0x07, 0x03, 0x00,
	0x00, 0x00, 0xe4, 0xfc, 0x5c, 0xc4, 0x64, 0x0c, 0x08, 0x0e, 0x0f, 0x09, 0x0c, 0x0e, 0x00, 0x00,
	0x00, 0x00, 0xe4, 0xfc, 0x5c, 0xc4, 0x64, 0x0c, 0x08, 0x0e, 0x0f, 0x09, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xe0, 0xf8, 0x1c, 0x84, 0x84, 0x84, 0x1c, 0x07, 0x0f, 0x08, 0x08, 0x06, 0x0f, 0x01, 0x00,
	0x00, 0xe0, 0xfc, 0x5c, 0x40, 0xe0, 0xfc, 0x1c, 0x0e, 0x0f, 0x01, 0x00, 0x0e, 0x0f, 0x01, 0x00,
	0x00, 0x00, 0x00, 0xe4, 0xfc, 0x1c, 0x04, 0x00, 0x00, 0x08, 0x0e, 0x0f, 0x09, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xe4, 0xfc, 0x1c, 0x04, 0x06, 0x0f, 0x08, 0x0e, 0x07, 0x01, 0x00, 0x00,
	0x00, 0x00, 0xe4, 0xfc, 0xdc, 0xe0, 0x3c, 0x1c, 0x08, 0x0f, 0x0f, 0x00, 0x01, 0x0f, 0x0e, 0x00,
	0x00, 0x00, 0xe4, 0xfc, 0x1c, 0x04, 0x00, 0x00, 0x08, 0x0e, 0x0f, 0x09, 0x08, 0x0c, 0x0e, 0x00,
	0x00, 0xf0, 0xfc, 0x0c, 0x78, 0x08, 0xfc, 0xfc, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x00,
	0x00, 0xe0, 0xfc, 0x1c, 0xf8, 0xe0, 0xfc, 0x1c, 0x0e, 0x0f, 0x01, 0x00, 0x0e, 0x0f, 0x01, 0x00,
	0xc0, 0xf0, 0x38, 0x0c, 0x04, 0x04, 0xfc, 0xf8, 0x07, 0x0f, 0x08, 0x08, 0x0c, 0x07, 0x03, 0x00,
	0x00, 0x00, 0xe4, 0xfc, 0x5c, 0x44, 0x7c, 0x38, 0x08, 0x0e, 0x0f, 0x09, 0x00, 0x00, 0x00, 0x00,
	0xc0, 0xf0, 0x38, 0x0c, 0x04, 0x04, 0xfc, 0xf8, 0x07, 0x0f, 0x08, 0x3e, 0x3c, 0x27, 0x03, 0x00,
	0x00, 0x00, 0xe4, 0xfc, 0x5c, 0xc4, 0xfc, 0x38, 0x08, 0x0e, 0x0f, 0x01, 0x00, 0x0f, 0x0f, 0x00,
	0x00, 0x30, 0x78, 0x4c, 0xc4, 0x84, 0x1c, 0x18, 0x06, 0x0e, 0x08, 0x08, 0x0c, 0x07, 0x03, 0x00,
	0x1c, 0x0c, 0xe4, 0xfc, 0x1c, 0x04, 0x0c, 0x1c, 0x08, 0x0e, 0x0f, 0x09, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xe0, 0xfc, 0x1c, 0x00, 0xe0, 0xfc, 0x1c, 0x07, 0x0f, 0x08, 0x08, 0x0f, 0x07, 0x00, 0x00,
	0xe0, 0xfc, 0x1c, 0x00, 0xc0, 0xf0, 0x3c, 0x0c, 0x0f, 0x0f, 0x06, 0x03, 0x01, 0x00, 0x00, 0x00,
	0xc0, 0xfc, 0x3c, 0x80, 0x00, 0xc0, 0xfc, 0x3c, 0x0f, 0x0f, 0x02, 0x01, 0x0e, 0x0f, 0x03, 0x00,
	0x00, 0x0c, 0x3c, 0xf0, 0xe0, 0x30, 0x1c, 0x0c, 0x0c, 0x0e, 0x03, 0x01, 0x03, 0x0f, 0x0c, 0x00,
	0x00, 0x3c, 0x7c, 0xc0, 0xc0, 0x60, 0x3c, 0x1c, 0x00, 0x08, 0x0e, 0x0f, 0x09, 0x00, 0x00, 0x00,
	0x00, 0x1c, 0x0c, 0x84, 0xc4, 0x64, 0x3c, 0x1c, 0x0c, 0x0e, 0x0b, 0x09, 0x08, 0x0c, 0x0e, 0x00,
	0x00, 0x00, 0xe0, 0xfc, 0x1c, 0x04, 0x04, 0x00, 0x00, 0x0e, 0x0f, 0x09, 0x08, 0x00, 0x00, 0x00,
	0x38, 0x70, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0e, 0x00,
	0x00, 0x00, 0x00, 0x04, 0xe4, 0xfc, 0x1c, 0x00, 0x00, 0x08, 0x08, 0x0e, 0x0f, 0x01, 0x00, 0x00,
	0x08, 0x0c, 0x06, 0x03, 0x06, 0x0c, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x30, 0x10, 0x10, 0x10,
	0x00, 0x00, 0x03, 0x07, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x80, 0xa0, 0xa0, 0xe0, 0xe0, 0x00, 0x06, 0x0f, 0x09, 0x08, 0x07, 0x0f, 0x08, 0x00,
	0x00, 0x00, 0xe4, 0xfc, 0x3c, 0x60, 0xc0, 0x80, 0x08, 0x0e, 0x0f, 0x09, 0x08, 0x0e, 0x07, 0x01,
	0x00, 0xc0, 0xe0, 0x20, 0x20, 0x60, 0x40, 0x00, 0x07, 0x0f, 0x08, 0x08, 0x0c, 0x04, 0x00, 0x00,
	0x00, 0x80, 0xc0, 0x60, 0x20, 0xe4, 0xfc, 0x1c, 0x07, 0x0f, 0x08, 0x08, 0x07, 0x0f, 0x08, 0x00,
	0x00, 0xc0, 0xe0, 0xa0, 0xa0, 0xa0, 0xe0, 0x40, 0x07, 0x0f, 0x08, 0x08, 0x0c, 0x04, 0x00, 0x00,
	0x00, 0x40, 0xe0, 0xf8, 0x5c, 0x44, 0x0c, 0x18, 0x08, 0x0e, 0x0f, 0x09, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xc0, 0xe0, 0x20, 0x20, 0xc0, 0xe0, 0x20, 0x27, 0x6f, 0x48, 0x78, 0x3f, 0x0f, 0x00, 0x00,
	0x00, 0x00, 0xe4, 0xfc, 0x5c, 0x20, 0xe0, 0xc0, 0x08, 0x0e, 0x0f, 0x01, 0x00, 0x0e, 0x0f, 0x01,
	0x00, 0x00, 0x00, 0x20, 0xec, 0xec, 0x00, 0x00, 0x00, 0x08, 0x0c, 0x0f, 0x0b, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0xa0, 0xec, 0x6c, 0x20, 0x70, 0x40, 0x70, 0x3e, 0x0f, 0x01, 0x00,
	0x00, 0x00, 0xe4, 0xfc, 0x9c, 0xc0, 0x60, 0x20, 0x08, 0x0e, 0x0f, 0x01, 0x01, 0x0f, 0x0e, 0x00,
	0x00, 0x00, 0x00, 0xe4, 0xfc, 0x1c, 0x00, 0x00, 0x00, 0x08, 0x0e, 0x0f, 0x09, 0x00, 0x00, 0x00,
	0x00, 0xe0, 0xe0, 0x60, 0xc0, 0x60, 0xe0, 0xc0, 0x0e, 0x0f, 0x01, 0x0e, 0x01, 0x0e, 0x0f, 0x01,
	0x00, 0xa0, 0xe0, 0x40, 0x20, 0xa0, 0xe0, 0x40, 0x0e, 0x0f, 0x01, 0x00, 0x0e, 0x0f, 0x01, 0x00,
	0x00, 0xc0, 0xe0, 0x20, 0x20, 0x20, 0xe0, 0xc0, 0x07, 0x0f, 0x08, 0x08, 0x08, 0x0e, 0x07, 0x01,
	0x00, 0x20, 0xe0, 0xc0, 0x20, 0x20, 0xe0, 0xc0, 0x60, 0x7e, 0x5f, 0x09, 0x08, 0x0e, 0x07, 0x01,
	0x00, 0xc0, 0xe0, 0x20, 0x20, 0xc0, 0xe0, 0x20, 0x06, 0x0f, 0x49, 0x68, 0x7e, 0x5f, 0x01, 0x00,
	0x00, 0x20, 0xe0, 0xc0, 0x60, 0x20, 0xe0, 0xc0, 0x0c, 0x0f, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x40, 0xe0, 0xa0, 0x20, 0x60, 0x40, 0x00, 0x04, 0x0c, 0x08, 0x09, 0x0f, 0x06, 0x00, 0x00,
	0x00, 0x20, 0xa0, 0xf0, 0x78, 0x2c, 0x20, 0x00, 0x00, 0x06, 0x0f, 0x09, 0x0c, 0x04, 0x00, 0x00,
	0x00, 0xe0, 0xe0, 0x00, 0x00, 0xe0, 0xe0, 0x00, 0x07, 0x0f, 0x08, 0x08, 0x07, 0x0f, 0x08, 0x00,
	0xe0, 0xe0, 0x00, 0x00, 0xc0, 0xe0, 0x20, 0x00, 0x0f, 0x0f, 0x06, 0x03, 0x01, 0x00, 0x00, 0x00,
	0x00, 0xe0, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0xe0, 0x0f, 0x0f, 0x04, 0x07, 0x0c, 0x0f, 0x07, 0x00,
	0x00, 0x20, 0xe0, 0xc0, 0x80, 0xc0, 0x60, 0x20, 0x08, 0x0c, 0x06, 0x03, 0x07, 0x0e, 0x08, 0x00,
	0x00, 0xe0, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0xe0, 0x46, 0x4f, 0x49, 0x68, 0x38, 0x1e, 0x0f, 0x01,
	0x00, 0x60, 0x60, 0x20, 0xa0, 0xe0, 0x60, 0x20, 0x08, 0x0c, 0x0e, 0x0b, 0x09, 0x0c, 0x0c, 0x00,
	0x00, 0x40, 0x40, 0xe0, 0xb8, 0x1c, 0x04, 0x04, 0x00, 0x00, 0x07, 0x0f, 0x08, 0x08, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xb0, 0xbc, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x0f, 0x01, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x04, 0xa4, 0xfc, 0x58, 0x40, 0x00, 0x08, 0x08, 0x0f, 0x07, 0x00, 0x00, 0x00, 0x00,
	0x08, 0x0c, 0x04, 0x0c, 0x08, 0x0c, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x80, 0xc0, 0x60, 0x30, 0x60, 0xc0, 0x80, 0x06, 0x07, 0x05, 0x04, 0x04, 0x06, 0x03, 0x01,
	/****
		0x00, 0xc0, 0xf0, 0x38, 0x0c, 0x04, 0x04, 0x1c, 0x23, 0x27, 0x24, 0x2c, 0x3e, 0x13, 0x00, 0x00,
		0x00, 0xe4, 0xe4, 0x00, 0x00, 0xe4, 0xe4, 0x00, 0x07, 0x0f, 0x08, 0x08, 0x07, 0x0f, 0x08, 0x00,
		0x00, 0xc0, 0xe0, 0xa8, 0xac, 0xa6, 0xe2, 0x40, 0x07, 0x0f, 0x08, 0x08, 0x0c, 0x04, 0x00, 0x00,
		0x00, 0x00, 0x80, 0xa8, 0xac, 0xe6, 0xec, 0x08, 0x06, 0x0f, 0x09, 0x08, 0x07, 0x0f, 0x08, 0x00,
		0x00, 0x00, 0x84, 0xa4, 0xa0, 0xe0, 0xe4, 0x04, 0x06, 0x0f, 0x09, 0x08, 0x07, 0x0f, 0x08, 0x00,
		0x00, 0x00, 0x80, 0xa2, 0xa6, 0xec, 0xe8, 0x00, 0x06, 0x0f, 0x09, 0x08, 0x07, 0x0f, 0x08, 0x00,
		0x00, 0x00, 0x80, 0xa4, 0xae, 0xea, 0xee, 0x04, 0x06, 0x0f, 0x09, 0x08, 0x07, 0x0f, 0x08, 0x00,
		0x00, 0x80, 0xe0, 0x70, 0x10, 0x10, 0x30, 0x20, 0x00, 0x11, 0x13, 0x16, 0x1e, 0x0b, 0x01, 0x00,
		0x00, 0xc0, 0xe8, 0xac, 0xa6, 0xac, 0xe8, 0x40, 0x07, 0x0f, 0x08, 0x08, 0x0c, 0x04, 0x00, 0x00,
		0x00, 0xc4, 0xe4, 0xa0, 0xa0, 0xa0, 0xe4, 0x44, 0x07, 0x0f, 0x08, 0x08, 0x0c, 0x04, 0x00, 0x00,
		0x00, 0xc0, 0xe2, 0xa6, 0xac, 0xa8, 0xe0, 0x40, 0x07, 0x0f, 0x08, 0x08, 0x0c, 0x04, 0x00, 0x00,
		0x00, 0x00, 0x04, 0x24, 0xe0, 0xe0, 0x04, 0x04, 0x00, 0x08, 0x0c, 0x0f, 0x0b, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x08, 0x2c, 0xe6, 0xe6, 0x0c, 0x08, 0x00, 0x08, 0x0c, 0x0f, 0x0b, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x02, 0x26, 0xec, 0xe8, 0x00, 0x00, 0x00, 0x08, 0x0c, 0x0f, 0x0b, 0x00, 0x00, 0x00,
		0x00, 0x00, 0xc2, 0xf2, 0x38, 0x08, 0xfa, 0xfa, 0x0c, 0x0f, 0x03, 0x01, 0x0d, 0x0f, 0x03, 0x00,
		0x00, 0x80, 0xe0, 0x72, 0x17, 0xf5, 0xf7, 0x02, 0x0e, 0x0f, 0x01, 0x01, 0x0f, 0x0f, 0x01, 0x00,
		0x00, 0x10, 0xf0, 0xf4, 0x96, 0x93, 0x31, 0x30, 0x08, 0x0e, 0x0f, 0x09, 0x08, 0x08, 0x0c, 0x00,
		0x00, 0x00, 0x60, 0xe0, 0xc0, 0x20, 0xe0, 0xe0, 0x0e, 0x0f, 0x09, 0x07, 0x0f, 0x0d, 0x09, 0x00,
		0x80, 0xf0, 0xf8, 0x4c, 0xc4, 0xfc, 0x7c, 0x44, 0x0f, 0x0f, 0x00, 0x00, 0x0f, 0x0f, 0x08, 0x00,
		0x00, 0xc0, 0xe8, 0x2c, 0x26, 0x2c, 0xe8, 0xc0, 0x07, 0x0f, 0x08, 0x08, 0x08, 0x0e, 0x07, 0x01,
		0x00, 0xc4, 0xe4, 0x20, 0x20, 0x20, 0xe4, 0xc4, 0x07, 0x0f, 0x08, 0x08, 0x08, 0x0e, 0x07, 0x01,
		0x00, 0xc0, 0xe2, 0x26, 0x2c, 0x28, 0xe0, 0xc0, 0x07, 0x0f, 0x08, 0x08, 0x08, 0x0e, 0x07, 0x01,
		0x00, 0xe8, 0xec, 0x06, 0x06, 0xec, 0xe8, 0x00, 0x07, 0x0f, 0x08, 0x08, 0x07, 0x0f, 0x08, 0x00,
		0x00, 0xe0, 0xe2, 0x06, 0x0c, 0xe8, 0xe0, 0x00, 0x07, 0x0f, 0x08, 0x08, 0x07, 0x0f, 0x08, 0x00,
		0x00, 0xe4, 0xe4, 0x00, 0x00, 0x00, 0xe4, 0xe4, 0x46, 0x4f, 0x49, 0x68, 0x38, 0x1e, 0x0f, 0x01,
		0x80, 0xe2, 0x72, 0x18, 0x08, 0x08, 0xfa, 0xf2, 0x07, 0x0f, 0x08, 0x08, 0x0c, 0x07, 0x03, 0x00,
		0x00, 0xe0, 0xfa, 0x1a, 0x00, 0xe0, 0xfa, 0x1a, 0x07, 0x0f, 0x08, 0x08, 0x0f, 0x07, 0x00, 0x00,
		0xe0, 0xf0, 0x18, 0x08, 0x0e, 0x8e, 0x98, 0x10, 0x01, 0x03, 0x0e, 0x0e, 0x02, 0x03, 0x01, 0x00,
		0x00, 0x20, 0xf0, 0xfc, 0x2e, 0x02, 0x06, 0x0c, 0x0c, 0x0f, 0x0f, 0x08, 0x08, 0x0c, 0x04, 0x00,
		0x40, 0x44, 0x4c, 0xd8, 0xf0, 0x70, 0x5c, 0x4c, 0x01, 0x01, 0x0f, 0x0f, 0x01, 0x01, 0x01, 0x00,
		0x00, 0xe2, 0xfe, 0x1e, 0x92, 0xd2, 0xfe, 0x8c, 0x0f, 0x0f, 0x08, 0x00, 0x06, 0x0f, 0x09, 0x00,
		0x00, 0x40, 0x40, 0xe0, 0xfc, 0x5e, 0x42, 0x06, 0x30, 0x20, 0x3c, 0x1f, 0x03, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x80, 0xa8, 0xac, 0xe6, 0xe2, 0x00, 0x06, 0x0f, 0x09, 0x08, 0x07, 0x0f, 0x08, 0x00,
		0x00, 0x00, 0x00, 0x28, 0xec, 0xe6, 0x02, 0x00, 0x00, 0x08, 0x0c, 0x0f, 0x0b, 0x00, 0x00, 0x00,
		0x00, 0xc0, 0xe8, 0x2c, 0x26, 0x22, 0xe0, 0xc0, 0x07, 0x0f, 0x08, 0x08, 0x08, 0x0e, 0x07, 0x01,
		0x00, 0xe0, 0xe8, 0x0c, 0x06, 0xe2, 0xe0, 0x00, 0x07, 0x0f, 0x08, 0x08, 0x07, 0x0f, 0x08, 0x00,
		0x00, 0xa8, 0xec, 0x44, 0x2c, 0xa8, 0xec, 0x44, 0x0e, 0x0f, 0x01, 0x00, 0x0e, 0x0f, 0x01, 0x00,
		0x00, 0xc2, 0xfb, 0x39, 0xf3, 0xc2, 0xfb, 0x39, 0x0e, 0x0f, 0x01, 0x00, 0x0f, 0x0f, 0x01, 0x00,
		0x00, 0x4c, 0x5e, 0x52, 0x4e, 0x5c, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x4c, 0x5e, 0x52, 0x5e, 0x4c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x80, 0xec, 0x6c, 0x00, 0x00, 0x00, 0x06, 0x0f, 0x09, 0x08, 0x0e, 0x06, 0x00, 0x00,
		0x00, 0xc0, 0xc0, 0x40, 0x40, 0x40, 0x40, 0x40, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x40, 0x40, 0x40, 0x40, 0x40, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x00, 0x00,
		0x30, 0x3e, 0x0e, 0x80, 0xc0, 0x60, 0x30, 0x10, 0x0c, 0x06, 0x23, 0x21, 0x34, 0x3a, 0x2e, 0x06,
		0x30, 0x3e, 0x0e, 0x80, 0xc0, 0x60, 0x30, 0x10, 0x0c, 0x06, 0x03, 0x09, 0x2c, 0x3a, 0x1f, 0x0f,
		0x00, 0x00, 0x00, 0x80, 0xec, 0x6c, 0x00, 0x00, 0x00, 0x06, 0x0f, 0x0f, 0x07, 0x00, 0x00, 0x00,
		0x80, 0xc0, 0x60, 0xa0, 0xc0, 0x60, 0x20, 0x00, 0x00, 0x01, 0x03, 0x02, 0x01, 0x03, 0x02, 0x00,
		0x20, 0x60, 0xc0, 0xa0, 0x60, 0xc0, 0x80, 0x00, 0x02, 0x03, 0x01, 0x02, 0x03, 0x01, 0x00, 0x00,
		0x00, 0xaa, 0x00, 0x55, 0x00, 0xaa, 0x00, 0x55, 0x00, 0xaa, 0x00, 0x55, 0x00, 0xaa, 0x00, 0x55,
		0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55,
		0x55, 0xff, 0xaa, 0xff, 0x55, 0xff, 0xaa, 0xff, 0x55, 0xff, 0xaa, 0xff, 0x55, 0xff, 0xaa, 0xff,
		0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00,
		0x80, 0x80, 0x80, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00,
		0xa0, 0xa0, 0xa0, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00,
		0x80, 0x80, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00,
		0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00,
		0xa0, 0xa0, 0xa0, 0xe0, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00,
		0xa0, 0xa0, 0xbf, 0xbf, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00,
		0x00, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00,
		0xa0, 0xa0, 0xa0, 0xa0, 0x20, 0xe0, 0xe0, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00,
		0xa0, 0xa0, 0xbf, 0xbf, 0x80, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x80, 0x80, 0xff, 0xff, 0x80, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0xa0, 0xa0, 0xa0, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xff, 0xff, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x80, 0x80, 0x80, 0xff, 0xff, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xff, 0xff, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00,
		0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x80, 0x80, 0x80, 0xff, 0xff, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xff, 0xff, 0xa0, 0xa0, 0xa0, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00,
		0x00, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x80, 0x00, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00,
		0x00, 0x00, 0xff, 0xff, 0x80, 0xbf, 0xbf, 0xa0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0xe0, 0xe0, 0x20, 0xa0, 0xa0, 0xa0, 0x00, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00,
		0xa0, 0xa0, 0xbf, 0xbf, 0x80, 0xbf, 0xbf, 0xa0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0xa0, 0xa0, 0xa0, 0xa0, 0x20, 0xa0, 0xa0, 0xa0, 0x00, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00,
		0x00, 0x00, 0xff, 0xff, 0x00, 0xbf, 0xbf, 0xa0, 0x00, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00,
		0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0xa0, 0xa0, 0xbf, 0xbf, 0x00, 0xbf, 0xbf, 0xa0, 0x00, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00,
		0xa0, 0xa0, 0xa0, 0xbf, 0xbf, 0xa0, 0xa0, 0xa0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x80, 0x80, 0xff, 0xff, 0x80, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00,
		0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00,
		0x00, 0x00, 0xff, 0xff, 0x80, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xff, 0xff, 0xa0, 0xa0, 0xa0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xe0, 0xe0, 0xa0, 0xa0, 0xa0, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00,
		0x80, 0x80, 0xff, 0xff, 0x80, 0xff, 0xff, 0x80, 0x00, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00,
		0xa0, 0xa0, 0xa0, 0xff, 0xff, 0xa0, 0xa0, 0xa0, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00,
		0x80, 0x80, 0x80, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
		0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x80, 0xc0, 0x60, 0x20, 0xe0, 0xc0, 0x60, 0x20, 0x0f, 0x0f, 0x08, 0x0f, 0x07, 0x0c, 0x08, 0x00,
		0x00, 0xe0, 0xf8, 0x1c, 0x44, 0xe4, 0xbc, 0x18, 0x0f, 0x0f, 0x00, 0x08, 0x0c, 0x07, 0x03, 0x00,
		0x80, 0xfc, 0x7c, 0x04, 0x04, 0x04, 0x1c, 0x1c, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0xd0, 0xf0, 0x30, 0xd0, 0xf0, 0x30, 0x10, 0x0e, 0x0f, 0x01, 0x0e, 0x0f, 0x01, 0x00, 0x00,
		0x00, 0x18, 0x78, 0xe8, 0x88, 0x08, 0x18, 0x18, 0x0c, 0x0e, 0x0b, 0x09, 0x0c, 0x0c, 0x00, 0x00,
		0x00, 0xc0, 0xe0, 0x20, 0xe0, 0xe0, 0x20, 0x20, 0x0f, 0x0f, 0x08, 0x0f, 0x07, 0x00, 0x00, 0x00,
		0x00, 0x80, 0xf0, 0x70, 0x00, 0x80, 0xf0, 0x70, 0x18, 0x0f, 0x07, 0x02, 0x02, 0x03, 0x01, 0x00,
		0x00, 0x20, 0x30, 0x90, 0xf0, 0x60, 0x30, 0x10, 0x00, 0x00, 0x0e, 0x0f, 0x01, 0x00, 0x00, 0x00,
		0x00, 0xc0, 0xe8, 0x28, 0x38, 0xf8, 0xc8, 0x08, 0x08, 0x09, 0x0f, 0x0e, 0x0a, 0x0b, 0x01, 0x00,
		0xc0, 0xe0, 0xb0, 0x98, 0x88, 0xf8, 0xf0, 0x00, 0x07, 0x0f, 0x08, 0x0c, 0x06, 0x03, 0x01, 0x00,
		0x60, 0xf0, 0x98, 0x0c, 0x84, 0xcc, 0x78, 0x30, 0x0e, 0x0f, 0x01, 0x0e, 0x0f, 0x09, 0x00, 0x00,
		0x00, 0x80, 0xc0, 0x48, 0x7c, 0xf4, 0xc4, 0x04, 0x06, 0x0f, 0x09, 0x08, 0x0e, 0x07, 0x01, 0x00,
		0xc0, 0xe0, 0x20, 0xa0, 0xe0, 0x20, 0xe0, 0xc0, 0x01, 0x03, 0x02, 0x03, 0x02, 0x02, 0x03, 0x01,
		0xc0, 0xe0, 0x20, 0xa0, 0xe0, 0x20, 0xf0, 0xd8, 0x0d, 0x07, 0x03, 0x03, 0x02, 0x02, 0x03, 0x01,
		0x00, 0xe0, 0xf0, 0x58, 0x4c, 0x44, 0x04, 0x00, 0x03, 0x07, 0x0c, 0x08, 0x08, 0x00, 0x00, 0x00,
		0x00, 0xf0, 0xf8, 0x08, 0x08, 0x08, 0xf8, 0xf0, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x00,
		0x90, 0x90, 0x90, 0xd8, 0x48, 0x48, 0x48, 0x00, 0x04, 0x04, 0x04, 0x06, 0x02, 0x02, 0x02, 0x00,
		0x00, 0x40, 0x40, 0xe0, 0xf0, 0x50, 0x40, 0x00, 0x08, 0x08, 0x09, 0x09, 0x0c, 0x04, 0x04, 0x04,
		0x00, 0x00, 0x00, 0x08, 0xb8, 0xf0, 0x40, 0x00, 0x08, 0x0a, 0x0b, 0x09, 0x09, 0x08, 0x00, 0x00,
		0x00, 0x40, 0xf0, 0xb8, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x09, 0x09, 0x0b, 0x0a, 0x08,
		0x00, 0x00, 0x00, 0xf8, 0xfc, 0x04, 0x1c, 0x18, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x07, 0x0f, 0x08, 0x0f, 0x07, 0x00, 0x00, 0x00,
		0x00, 0x80, 0x80, 0xa0, 0xb0, 0x90, 0x80, 0x00, 0x00, 0x00, 0x04, 0x06, 0x02, 0x00, 0x00, 0x00,
		0x40, 0x40, 0x60, 0x20, 0x60, 0x40, 0x60, 0x20, 0x02, 0x02, 0x03, 0x01, 0x03, 0x02, 0x03, 0x01,
		0x00, 0x1c, 0x1e, 0x12, 0x1e, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
		0x80, 0x80, 0x00, 0x00, 0xe0, 0xfe, 0x1e, 0x02, 0x03, 0x07, 0x0c, 0x0f, 0x0f, 0x00, 0x00, 0x00,
		0x60, 0x7a, 0x1e, 0x64, 0x7a, 0x1e, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x60, 0x74, 0x5a, 0x6e, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0xe0, 0xf0, 0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07, 0x03, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	****/
};

#endif

