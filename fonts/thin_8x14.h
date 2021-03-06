///////////////////////////////////////////////////////////////////////////////
//
//  Font "THIN_8X14.H" for the Noritake GU128X64E-U100 VFD display
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

#ifndef THIN_8X14_H
#define THIN_8X14_H

#define thin_8x14 pgm_get_far_address(_thin_8x14)

static const uint8_t _thin_8x14[] PROGMEM = {

	0x08, // width (base + 0)
	0x0e, // height (base + 1)
	0x00, // horizontal gap (base + 2)
	0x00, // vertical gap (base + 3)
	0x00, // first char (base + 4)
	0x7f, // last char (base + 5)
	0x10, // bytes per char (base + 6)

	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0xf8, 0x04, 0x94, 0x84, 0x84, 0x94, 0x04, 0xf8, 0x03, 0x04, 0x04, 0x05, 0x05, 0x04, 0x04, 0x03,
	0xf8, 0xfc, 0x6c, 0x7c, 0x7c, 0x6c, 0xfc, 0xf8, 0x03, 0x07, 0x07, 0x06, 0x06, 0x07, 0x07, 0x03,
	0xf0, 0xf8, 0xf8, 0xf0, 0xf8, 0xf8, 0xf0, 0x00, 0x00, 0x01, 0x03, 0x07, 0x03, 0x01, 0x00, 0x00,
	0x40, 0xe0, 0xf0, 0xf8, 0xf0, 0xe0, 0x40, 0x00, 0x00, 0x00, 0x01, 0x03, 0x01, 0x00, 0x00, 0x00,
	0xe0, 0xe0, 0xf8, 0x1c, 0x1c, 0xf8, 0xe0, 0xe0, 0x00, 0x00, 0x04, 0x07, 0x07, 0x04, 0x00, 0x00,
	0x60, 0xf0, 0xf8, 0xfc, 0xfc, 0xf8, 0xf0, 0x60, 0x00, 0x00, 0x04, 0x07, 0x07, 0x04, 0x00, 0x00,
	0x00, 0x00, 0xc0, 0xe0, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00,
	0xff, 0xff, 0x3f, 0x1f, 0x1f, 0x3f, 0xff, 0xff, 0x3f, 0x3f, 0x3f, 0x3e, 0x3e, 0x3f, 0x3f, 0x3f,
	0x00, 0xe0, 0x30, 0x10, 0x10, 0x30, 0xe0, 0x00, 0x00, 0x01, 0x03, 0x02, 0x02, 0x03, 0x01, 0x00,
	0xff, 0x1f, 0xcf, 0xef, 0xef, 0xcf, 0x1f, 0xff, 0x3f, 0x3e, 0x3c, 0x3d, 0x3d, 0x3c, 0x3e, 0x3f,
	0x80, 0x40, 0x60, 0x54, 0x4c, 0x84, 0x3c, 0x00, 0x03, 0x04, 0x04, 0x04, 0x04, 0x03, 0x00, 0x00,
	0x00, 0x38, 0x44, 0xc4, 0x44, 0x44, 0x38, 0x00, 0x00, 0x01, 0x01, 0x07, 0x01, 0x01, 0x00, 0x00,
	0x00, 0x00, 0xfc, 0x14, 0x14, 0x14, 0x14, 0x1c, 0x06, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xfc, 0x14, 0x14, 0x14, 0x14, 0x14, 0xfc, 0x0e, 0x07, 0x00, 0x00, 0x00, 0x00, 0x07, 0x03,
	0x50, 0x50, 0xe0, 0xbc, 0xbc, 0xe0, 0x50, 0x50, 0x01, 0x01, 0x00, 0x07, 0x07, 0x00, 0x01, 0x01,
	0xfc, 0xf8, 0xf0, 0xe0, 0xe0, 0x40, 0x40, 0x00, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x40, 0x40, 0xe0, 0xe0, 0xf0, 0xf8, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x00,
	0x00, 0x10, 0x18, 0xfc, 0x18, 0x10, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x03, 0x01, 0x00, 0x00,
	0x00, 0xfc, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00,
	0x38, 0x44, 0x44, 0x44, 0xfc, 0x04, 0x04, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x07,
	0xc4, 0x2a, 0x12, 0x12, 0x02, 0x22, 0xc4, 0x00, 0x08, 0x11, 0x12, 0x12, 0x12, 0x15, 0x08, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x00,
	0x00, 0x10, 0x18, 0xfc, 0x18, 0x10, 0x00, 0x00, 0x00, 0x09, 0x0b, 0x0f, 0x0b, 0x09, 0x00, 0x00,
	0x00, 0x10, 0x18, 0xfc, 0x18, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x03, 0x01, 0x00, 0x00,
	0x40, 0x40, 0x40, 0x40, 0x50, 0xe0, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
	0x40, 0xe0, 0x50, 0x40, 0x40, 0x40, 0x40, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
	0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00,
	0x40, 0xe0, 0x50, 0x40, 0x50, 0xe0, 0x40, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00,
	0x00, 0xc0, 0xf0, 0xf8, 0xf0, 0xc0, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00,
	0x18, 0x78, 0xf8, 0xf8, 0xf8, 0x78, 0x18, 0x00, 0x00, 0x00, 0x01, 0x03, 0x01, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x38, 0xfc, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x10, 0x10, 0xfc, 0x10, 0xfc, 0x10, 0x10, 0x00, 0x01, 0x01, 0x07, 0x01, 0x07, 0x01, 0x01, 0x00,
	0x38, 0x44, 0x44, 0x47, 0x44, 0x44, 0x98, 0x00, 0x03, 0x04, 0x04, 0x1c, 0x04, 0x04, 0x03, 0x00,
	0x30, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x00, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x06, 0x00,
	0x80, 0x58, 0x24, 0x64, 0x24, 0xd8, 0x40, 0x00, 0x03, 0x04, 0x04, 0x04, 0x00, 0x07, 0x04, 0x00,
	0x00, 0x00, 0x10, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xf0, 0x08, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x04, 0x08, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x02, 0x01, 0x00, 0x00,
	0x40, 0x40, 0x50, 0xe0, 0xe0, 0x50, 0x40, 0x40, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00,
	0x40, 0x40, 0x40, 0xf0, 0x40, 0x40, 0x40, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x07, 0x00, 0x00, 0x00,
	0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x08, 0x00, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0xf8, 0x04, 0x84, 0x44, 0x24, 0x14, 0xf8, 0x00, 0x03, 0x05, 0x04, 0x04, 0x04, 0x04, 0x03, 0x00,
	0x00, 0x10, 0x08, 0x04, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x07, 0x04, 0x04, 0x00,
	0x08, 0x04, 0x04, 0x84, 0x44, 0x24, 0x18, 0x00, 0x04, 0x06, 0x05, 0x04, 0x04, 0x04, 0x06, 0x00,
	0x08, 0x04, 0x44, 0x44, 0x44, 0x44, 0xb8, 0x00, 0x02, 0x04, 0x04, 0x04, 0x04, 0x04, 0x03, 0x00,
	0xc0, 0xa0, 0x90, 0x88, 0x84, 0xfc, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x07, 0x04, 0x00,
	0x7c, 0x44, 0x44, 0x44, 0x44, 0x44, 0x84, 0x00, 0x02, 0x04, 0x04, 0x04, 0x04, 0x04, 0x03, 0x00,
	0xf0, 0x48, 0x44, 0x44, 0x44, 0x40, 0x80, 0x00, 0x03, 0x04, 0x04, 0x04, 0x04, 0x04, 0x03, 0x00,
	0x0c, 0x04, 0x04, 0x84, 0x44, 0x24, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00,
	0xb8, 0x44, 0x44, 0x44, 0x44, 0x44, 0xb8, 0x00, 0x03, 0x04, 0x04, 0x04, 0x04, 0x04, 0x03, 0x00,
	0x38, 0x44, 0x44, 0x44, 0x44, 0x44, 0xf8, 0x00, 0x00, 0x04, 0x04, 0x04, 0x04, 0x02, 0x01, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x03, 0x00, 0x00, 0x00,
	0x00, 0x40, 0xa0, 0x10, 0x08, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x00, 0x00,
	0x00, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00,
	0x00, 0x00, 0x04, 0x08, 0x10, 0xa0, 0x40, 0x00, 0x00, 0x00, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00,
	0x18, 0x04, 0x04, 0x04, 0xc4, 0x24, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00,
	0xf8, 0x04, 0x04, 0xe4, 0x24, 0x24, 0xf8, 0x00, 0x03, 0x04, 0x04, 0x05, 0x05, 0x05, 0x00, 0x00,
	0xe0, 0x90, 0x88, 0x84, 0x88, 0x90, 0xe0, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00,
	0x04, 0xfc, 0x44, 0x44, 0x44, 0x44, 0xb8, 0x00, 0x04, 0x07, 0x04, 0x04, 0x04, 0x04, 0x03, 0x00,
	0xf0, 0x08, 0x04, 0x04, 0x04, 0x04, 0x18, 0x00, 0x01, 0x02, 0x04, 0x04, 0x04, 0x04, 0x03, 0x00,
	0x04, 0xfc, 0x04, 0x04, 0x04, 0x08, 0xf0, 0x00, 0x04, 0x07, 0x04, 0x04, 0x04, 0x02, 0x01, 0x00,
	0x04, 0xfc, 0x44, 0x44, 0xe4, 0x04, 0x1c, 0x00, 0x04, 0x07, 0x04, 0x04, 0x04, 0x04, 0x07, 0x00,
	0x04, 0xfc, 0x44, 0x44, 0xe4, 0x04, 0x1c, 0x00, 0x04, 0x07, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
	0xf0, 0x08, 0x04, 0x84, 0x84, 0x84, 0x98, 0x00, 0x01, 0x02, 0x04, 0x04, 0x04, 0x02, 0x07, 0x00,
	0xfc, 0x40, 0x40, 0x40, 0x40, 0x40, 0xfc, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00,
	0x00, 0x00, 0x04, 0xfc, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x07, 0x04, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x04, 0xfc, 0x04, 0x00, 0x00, 0x03, 0x04, 0x04, 0x04, 0x03, 0x00, 0x00, 0x00,
	0x04, 0xfc, 0x40, 0x40, 0x40, 0xa0, 0x1c, 0x00, 0x04, 0x07, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00,
	0x04, 0xfc, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x07, 0x04, 0x04, 0x04, 0x04, 0x07, 0x00,
	0xfc, 0x08, 0x10, 0x20, 0x10, 0x08, 0xfc, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00,
	0xfc, 0x08, 0x10, 0x20, 0x40, 0x80, 0xfc, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00,
	0xf0, 0x08, 0x04, 0x04, 0x04, 0x08, 0xf0, 0x00, 0x01, 0x02, 0x04, 0x04, 0x04, 0x02, 0x01, 0x00,
	0x04, 0xfc, 0x44, 0x44, 0x44, 0x44, 0x38, 0x00, 0x04, 0x07, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
	0xf0, 0x08, 0x04, 0x04, 0x04, 0x08, 0xf0, 0x00, 0x01, 0x02, 0x04, 0x06, 0x04, 0x0a, 0x01, 0x00,
	0x04, 0xfc, 0x44, 0x44, 0x44, 0xc4, 0x38, 0x00, 0x04, 0x07, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00,
	0x38, 0x44, 0x44, 0x44, 0x44, 0x44, 0x98, 0x00, 0x03, 0x04, 0x04, 0x04, 0x04, 0x04, 0x03, 0x00,
	0x1c, 0x04, 0x04, 0xfc, 0x04, 0x04, 0x1c, 0x00, 0x00, 0x00, 0x04, 0x07, 0x04, 0x00, 0x00, 0x00,
	0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x03, 0x04, 0x04, 0x04, 0x04, 0x04, 0x03, 0x00,
	0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x00, 0x01, 0x02, 0x04, 0x02, 0x01, 0x00, 0x00,
	0xfc, 0x00, 0x00, 0x80, 0x00, 0x00, 0xfc, 0x00, 0x07, 0x02, 0x01, 0x00, 0x01, 0x02, 0x07, 0x00,
	0x0c, 0x10, 0xa0, 0x40, 0xa0, 0x10, 0x0c, 0x00, 0x06, 0x01, 0x00, 0x00, 0x00, 0x01, 0x06, 0x00,
	0x00, 0x3c, 0x40, 0xc0, 0x40, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x04, 0x07, 0x04, 0x00, 0x00, 0x00,
	0x1c, 0x04, 0x84, 0x44, 0x24, 0x14, 0x0c, 0x00, 0x06, 0x05, 0x04, 0x04, 0x04, 0x04, 0x07, 0x00,
	0x00, 0x00, 0xfc, 0x04, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x07, 0x04, 0x04, 0x04, 0x00, 0x00,
	0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x00,
	0x00, 0x00, 0x04, 0x04, 0x04, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x04, 0x07, 0x00, 0x00,
	0x08, 0x04, 0x02, 0x01, 0x02, 0x04, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
	0x00, 0x00, 0x03, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xa0, 0xa0, 0xa0, 0xa0, 0xc0, 0x00, 0x00, 0x03, 0x04, 0x04, 0x04, 0x02, 0x07, 0x04, 0x00,
	0x04, 0xfc, 0x20, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x07, 0x04, 0x04, 0x04, 0x04, 0x03, 0x00,
	0xc0, 0x20, 0x20, 0x20, 0x20, 0x20, 0x40, 0x00, 0x03, 0x04, 0x04, 0x04, 0x04, 0x04, 0x02, 0x00,
	0x80, 0x40, 0x20, 0x24, 0x24, 0xfc, 0x00, 0x00, 0x03, 0x04, 0x04, 0x04, 0x02, 0x07, 0x04, 0x00,
	0xc0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xc0, 0x00, 0x03, 0x04, 0x04, 0x04, 0x04, 0x04, 0x02, 0x00,
	0x40, 0xf8, 0x44, 0x04, 0x04, 0x18, 0x00, 0x00, 0x04, 0x07, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
	0xc0, 0x20, 0x20, 0x20, 0x00, 0xe0, 0x20, 0x00, 0x09, 0x12, 0x12, 0x12, 0x12, 0x0f, 0x00, 0x00,
	0x04, 0xfc, 0x40, 0x20, 0x20, 0x20, 0xc0, 0x00, 0x04, 0x07, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00,
	0x00, 0x00, 0x00, 0x20, 0xec, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x07, 0x04, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0xec, 0x00, 0x00, 0x0c, 0x10, 0x10, 0x10, 0x10, 0x0f, 0x00,
	0x04, 0xfc, 0x80, 0x80, 0x80, 0x40, 0x20, 0x00, 0x04, 0x07, 0x00, 0x00, 0x00, 0x01, 0x06, 0x00,
	0x00, 0x00, 0x04, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x07, 0x04, 0x00, 0x00, 0x00,
	0xe0, 0x20, 0x20, 0xc0, 0x20, 0x20, 0xc0, 0x00, 0x07, 0x00, 0x00, 0x07, 0x00, 0x00, 0x07, 0x00,
	0x20, 0xe0, 0x00, 0x20, 0x20, 0x20, 0xc0, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00,
	0xc0, 0x20, 0x20, 0x20, 0x20, 0x20, 0xc0, 0x00, 0x03, 0x04, 0x04, 0x04, 0x04, 0x04, 0x03, 0x00,
	0x20, 0xe0, 0x00, 0x20, 0x20, 0x20, 0xc0, 0x00, 0x10, 0x1f, 0x12, 0x02, 0x02, 0x02, 0x01, 0x00,
	0xc0, 0x20, 0x20, 0x20, 0x00, 0xe0, 0x20, 0x00, 0x01, 0x02, 0x02, 0x02, 0x12, 0x1f, 0x10, 0x00,
	0x20, 0xe0, 0x20, 0x20, 0x20, 0x20, 0xc0, 0x00, 0x04, 0x07, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x40, 0x20, 0xa0, 0x20, 0x20, 0x20, 0x40, 0x00, 0x02, 0x04, 0x04, 0x04, 0x05, 0x04, 0x02, 0x00,
	0x00, 0x20, 0x20, 0xfc, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x04, 0x02, 0x00,
	0xe0, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x03, 0x04, 0x04, 0x04, 0x02, 0x07, 0x04, 0x00,
	0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x01, 0x02, 0x04, 0x04, 0x02, 0x01, 0x00,
	0xe0, 0x00, 0x00, 0x80, 0x00, 0x00, 0xe0, 0x00, 0x07, 0x02, 0x01, 0x00, 0x01, 0x02, 0x07, 0x00,
	0x20, 0x40, 0x80, 0x00, 0x80, 0x40, 0x20, 0x00, 0x04, 0x02, 0x00, 0x01, 0x00, 0x02, 0x04, 0x00,
	0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x11, 0x12, 0x12, 0x12, 0x12, 0x0a, 0x07, 0x00,
	0x60, 0x20, 0x20, 0xa0, 0x20, 0x60, 0x20, 0x00, 0x06, 0x04, 0x05, 0x04, 0x04, 0x04, 0x06, 0x00,
	0x00, 0x40, 0x40, 0xf8, 0x04, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x04, 0x04, 0x00,
	0x00, 0x00, 0x00, 0xbc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x04, 0x04, 0x04, 0xf8, 0x40, 0x40, 0x00, 0x00, 0x04, 0x04, 0x04, 0x03, 0x00, 0x00, 0x00,
	0x08, 0x0c, 0x04, 0x0c, 0x08, 0x0c, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x80, 0x40, 0x20, 0x10, 0x20, 0x40, 0x80, 0x00, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 0x00,
	/****
		0xf0, 0x08, 0x04, 0x04, 0x04, 0x04, 0x98, 0x00, 0x00, 0x11, 0x12, 0x12, 0x12, 0x16, 0x09, 0x00,
		0xec, 0x00, 0x00, 0x00, 0x00, 0xec, 0x00, 0x00, 0x03, 0x04, 0x04, 0x04, 0x00, 0x07, 0x04, 0x00,
		0xc0, 0xa0, 0xa0, 0xa8, 0xa4, 0xa2, 0xc0, 0x00, 0x03, 0x04, 0x04, 0x04, 0x04, 0x04, 0x02, 0x00,
		0x00, 0xa8, 0xa4, 0xa2, 0xa4, 0xc8, 0x00, 0x00, 0x03, 0x04, 0x04, 0x04, 0x00, 0x07, 0x04, 0x00,
		0x0c, 0xa0, 0xa0, 0xa0, 0xa0, 0xcc, 0x00, 0x00, 0x03, 0x04, 0x04, 0x04, 0x00, 0x07, 0x04, 0x00,
		0x00, 0xa0, 0xa2, 0xa4, 0xa8, 0xc0, 0x00, 0x00, 0x03, 0x04, 0x04, 0x04, 0x00, 0x07, 0x04, 0x00,
		0x00, 0xa4, 0xaa, 0xaa, 0xaa, 0xc4, 0x00, 0x00, 0x03, 0x04, 0x04, 0x04, 0x00, 0x07, 0x04, 0x00,
		0x00, 0xe0, 0x10, 0x10, 0x10, 0x10, 0xa0, 0x00, 0x00, 0x00, 0x09, 0x09, 0x09, 0x0b, 0x04, 0x00,
		0xc0, 0xa8, 0xa4, 0xa2, 0xa4, 0xa8, 0xc0, 0x00, 0x03, 0x04, 0x04, 0x04, 0x04, 0x04, 0x02, 0x00,
		0xcc, 0xa0, 0xa0, 0xa0, 0xa0, 0xac, 0xc0, 0x00, 0x03, 0x04, 0x04, 0x04, 0x04, 0x04, 0x02, 0x00,
		0xc0, 0xa0, 0xa2, 0xa4, 0xa8, 0xa0, 0xc0, 0x00, 0x03, 0x04, 0x04, 0x04, 0x04, 0x04, 0x02, 0x00,
		0x00, 0x0c, 0x00, 0x20, 0xe0, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x04, 0x07, 0x04, 0x00, 0x00,
		0x00, 0x08, 0x24, 0xe2, 0x04, 0x08, 0x00, 0x00, 0x00, 0x00, 0x04, 0x07, 0x04, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x02, 0x24, 0xe8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x07, 0x04, 0x00, 0x00,
		0xc0, 0x22, 0x10, 0x08, 0x10, 0x22, 0xc0, 0x00, 0x07, 0x01, 0x01, 0x01, 0x01, 0x01, 0x07, 0x00,
		0xc0, 0x22, 0x15, 0x0d, 0x15, 0x22, 0xc0, 0x00, 0x07, 0x01, 0x01, 0x01, 0x01, 0x01, 0x07, 0x00,
		0x08, 0xfc, 0x4a, 0x49, 0x48, 0x48, 0x18, 0x00, 0x04, 0x07, 0x04, 0x04, 0x04, 0x04, 0x06, 0x00,
		0x10, 0x90, 0xa0, 0xe0, 0x90, 0x90, 0xe0, 0x00, 0x03, 0x04, 0x04, 0x03, 0x07, 0x04, 0x04, 0x00,
		0xf0, 0x48, 0x44, 0x44, 0x44, 0xfc, 0x44, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x07, 0x04, 0x00,
		0xc0, 0x28, 0x24, 0x22, 0x24, 0x28, 0xc0, 0x00, 0x03, 0x04, 0x04, 0x04, 0x04, 0x04, 0x03, 0x00,
		0xc0, 0x2c, 0x20, 0x20, 0x20, 0x2c, 0xc0, 0x00, 0x03, 0x04, 0x04, 0x04, 0x04, 0x04, 0x03, 0x00,
		0xc0, 0x20, 0x22, 0x24, 0x28, 0x20, 0xc0, 0x00, 0x03, 0x04, 0x04, 0x04, 0x04, 0x04, 0x03, 0x00,
		0xe8, 0x04, 0x02, 0x02, 0x04, 0xe8, 0x00, 0x00, 0x03, 0x04, 0x04, 0x04, 0x02, 0x07, 0x04, 0x00,
		0xe0, 0x00, 0x02, 0x04, 0x08, 0xe0, 0x00, 0x00, 0x03, 0x04, 0x04, 0x04, 0x02, 0x07, 0x04, 0x00,
		0xec, 0x00, 0x00, 0x00, 0x00, 0x00, 0xec, 0x00, 0x01, 0x12, 0x12, 0x12, 0x12, 0x0a, 0x07, 0x00,
		0xe0, 0x12, 0x08, 0x08, 0x08, 0x12, 0xe0, 0x00, 0x01, 0x02, 0x04, 0x04, 0x04, 0x02, 0x01, 0x00,
		0xfa, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfa, 0x00, 0x03, 0x04, 0x04, 0x04, 0x04, 0x04, 0x03, 0x00,
		0x00, 0xf0, 0x08, 0x0e, 0x08, 0x08, 0x90, 0x00, 0x00, 0x00, 0x01, 0x07, 0x01, 0x01, 0x00, 0x00,
		0x20, 0xfc, 0x22, 0x02, 0x02, 0x0c, 0x00, 0x00, 0x06, 0x07, 0x04, 0x04, 0x04, 0x04, 0x02, 0x00,
		0x00, 0x4c, 0x50, 0xf0, 0x50, 0x4c, 0x00, 0x00, 0x00, 0x01, 0x01, 0x07, 0x01, 0x01, 0x00, 0x00,
		0xfe, 0x12, 0x12, 0x12, 0x92, 0xcc, 0x80, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x00,
		0x00, 0x40, 0x40, 0xfc, 0x42, 0x42, 0x04, 0x00, 0x08, 0x10, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00,
		0x00, 0xa8, 0xa4, 0xa2, 0xa0, 0xc0, 0x00, 0x00, 0x03, 0x04, 0x04, 0x04, 0x00, 0x07, 0x04, 0x00,
		0x00, 0x00, 0x28, 0xe4, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x07, 0x04, 0x00, 0x00, 0x00,
		0xc0, 0x20, 0x28, 0x24, 0x22, 0x20, 0xc0, 0x00, 0x03, 0x04, 0x04, 0x04, 0x04, 0x04, 0x03, 0x00,
		0xe0, 0x08, 0x04, 0x02, 0x00, 0xe0, 0x00, 0x00, 0x03, 0x04, 0x04, 0x04, 0x00, 0x07, 0x04, 0x00,
		0x28, 0xec, 0x04, 0x2c, 0x28, 0x2c, 0xc4, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00,
		0xfa, 0x13, 0x21, 0x43, 0x82, 0x03, 0xf9, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x00,
		0x00, 0x4c, 0x52, 0x52, 0x52, 0x5e, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x4c, 0x52, 0x52, 0x52, 0x4c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x80, 0x6c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x04, 0x04, 0x04, 0x04, 0x03, 0x00,
		0xc0, 0xc0, 0x40, 0x40, 0x40, 0x40, 0x40, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x40, 0x40, 0x40, 0x40, 0x40, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00,
		0x00, 0x3e, 0x80, 0x40, 0x20, 0x10, 0x08, 0x00, 0x02, 0x01, 0x10, 0x19, 0x15, 0x13, 0x10, 0x00,
		0x00, 0x3e, 0x80, 0x40, 0x20, 0x90, 0x88, 0x00, 0x02, 0x01, 0x04, 0x06, 0x05, 0x04, 0x1f, 0x00,
		0x00, 0x00, 0x00, 0xec, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x03, 0x00, 0x00, 0x00,
		0x40, 0xa0, 0x10, 0x00, 0x40, 0xa0, 0x10, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00,
		0x10, 0xa0, 0x40, 0x00, 0x10, 0xa0, 0x40, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
		0x00, 0xaa, 0x00, 0x55, 0x00, 0xaa, 0x00, 0x55, 0x00, 0x2a, 0x00, 0x15, 0x00, 0x2a, 0x00, 0x15,
		0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0x2a, 0x15, 0x2a, 0x15, 0x2a, 0x15, 0x2a, 0x15,
		0x55, 0xff, 0xaa, 0xff, 0x55, 0xff, 0xaa, 0xff, 0x15, 0x3f, 0x2a, 0x3f, 0x15, 0x3f, 0x2a, 0x3f,
		0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x00, 0x00, 0x00,
		0x80, 0x80, 0x80, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x00, 0x00, 0x00,
		0xa0, 0xa0, 0xa0, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x00, 0x00, 0x00,
		0x80, 0x80, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x00, 0x3f, 0x3f, 0x00,
		0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x00, 0x3f, 0x3f, 0x00,
		0xa0, 0xa0, 0xa0, 0xe0, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x00, 0x00, 0x00,
		0xa0, 0xa0, 0xbf, 0xbf, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x00, 0x3f, 0x3f, 0x00,
		0x00, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x00, 0x3f, 0x3f, 0x00,
		0xa0, 0xa0, 0xa0, 0xa0, 0x20, 0xe0, 0xe0, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x00, 0x3f, 0x3f, 0x00,
		0xa0, 0xa0, 0xbf, 0xbf, 0x80, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x80, 0x80, 0xff, 0xff, 0x80, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0xa0, 0xa0, 0xa0, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xff, 0xff, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x80, 0x80, 0x80, 0xff, 0xff, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xff, 0xff, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x00, 0x00, 0x00,
		0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x80, 0x80, 0x80, 0xff, 0xff, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xff, 0xff, 0xa0, 0xa0, 0xa0, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x00, 0x00, 0x00,
		0x00, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x80, 0x00, 0x00, 0x3f, 0x3f, 0x00, 0x3f, 0x3f, 0x00,
		0x00, 0x00, 0xff, 0xff, 0x80, 0xbf, 0xbf, 0xa0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0xe0, 0xe0, 0x20, 0xa0, 0xa0, 0xa0, 0x00, 0x00, 0x3f, 0x3f, 0x00, 0x3f, 0x3f, 0x00,
		0xa0, 0xa0, 0xbf, 0xbf, 0x80, 0xbf, 0xbf, 0xa0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0xa0, 0xa0, 0xa0, 0xa0, 0x20, 0xa0, 0xa0, 0xa0, 0x00, 0x00, 0x3f, 0x3f, 0x00, 0x3f, 0x3f, 0x00,
		0x00, 0x00, 0xff, 0xff, 0x00, 0xbf, 0xbf, 0xa0, 0x00, 0x00, 0x3f, 0x3f, 0x00, 0x3f, 0x3f, 0x00,
		0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0xa0, 0xa0, 0xbf, 0xbf, 0x00, 0xbf, 0xbf, 0xa0, 0x00, 0x00, 0x3f, 0x3f, 0x00, 0x3f, 0x3f, 0x00,
		0xa0, 0xa0, 0xa0, 0xbf, 0xbf, 0xa0, 0xa0, 0xa0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x80, 0x80, 0xff, 0xff, 0x80, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x00, 0x00, 0x00,
		0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x3f, 0x3f, 0x00, 0x3f, 0x3f, 0x00,
		0x00, 0x00, 0xff, 0xff, 0x80, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xff, 0xff, 0xa0, 0xa0, 0xa0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xe0, 0xe0, 0xa0, 0xa0, 0xa0, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x3f, 0x3f, 0x00, 0x3f, 0x3f, 0x00,
		0x80, 0x80, 0xff, 0xff, 0x80, 0xff, 0xff, 0x80, 0x00, 0x00, 0x3f, 0x3f, 0x00, 0x3f, 0x3f, 0x00,
		0xa0, 0xa0, 0xa0, 0xff, 0xff, 0xa0, 0xa0, 0xa0, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x00, 0x00, 0x00,
		0x80, 0x80, 0x80, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x00, 0x00, 0x00,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f,
		0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f,
		0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f,
		0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0xc0, 0x20, 0x20, 0x20, 0xc0, 0x20, 0x20, 0x00, 0x03, 0x04, 0x04, 0x04, 0x03, 0x06, 0x04, 0x00,
		0xf8, 0x04, 0x24, 0x24, 0x24, 0x58, 0x80, 0x00, 0x07, 0x00, 0x02, 0x02, 0x02, 0x02, 0x01, 0x00,
		0xfc, 0x04, 0x04, 0x04, 0x04, 0x04, 0x1c, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x10, 0xf0, 0x10, 0x10, 0x10, 0xf0, 0x10, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00,
		0x0c, 0x14, 0xa4, 0x44, 0x04, 0x04, 0x0c, 0x00, 0x06, 0x05, 0x04, 0x04, 0x04, 0x04, 0x06, 0x00,
		0xc0, 0x20, 0x20, 0x20, 0xe0, 0x20, 0x20, 0x00, 0x03, 0x04, 0x04, 0x04, 0x03, 0x00, 0x00, 0x00,
		0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x08, 0x0f, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00,
		0x20, 0x10, 0x10, 0xe0, 0x20, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00,
		0x00, 0xe4, 0x14, 0x1c, 0x14, 0xe4, 0x00, 0x00, 0x00, 0x04, 0x05, 0x07, 0x05, 0x04, 0x00, 0x00,
		0xf0, 0x48, 0x44, 0x44, 0x44, 0x48, 0xf0, 0x00, 0x01, 0x02, 0x04, 0x04, 0x04, 0x02, 0x01, 0x00,
		0x70, 0x88, 0x04, 0x04, 0x04, 0x88, 0x70, 0x00, 0x00, 0x04, 0x07, 0x00, 0x07, 0x04, 0x00, 0x00,
		0x00, 0x80, 0x48, 0x44, 0x54, 0x64, 0xc4, 0x00, 0x00, 0x03, 0x04, 0x04, 0x04, 0x04, 0x03, 0x00,
		0xc0, 0x20, 0x20, 0xe0, 0x20, 0x20, 0xc0, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00,
		0xe0, 0x10, 0x90, 0x50, 0x30, 0x10, 0xe8, 0x04, 0x04, 0x03, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00,
		0x00, 0xf0, 0x48, 0x44, 0x44, 0x44, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x04, 0x04, 0x00, 0x00,
		0xf0, 0x08, 0x08, 0x08, 0x08, 0x08, 0xf0, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00,
		0x48, 0x48, 0x48, 0x48, 0x48, 0x48, 0x48, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00,
		0x00, 0x20, 0x20, 0xf8, 0x20, 0x20, 0x00, 0x00, 0x00, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x00,
		0x00, 0x00, 0x00, 0x04, 0x88, 0x50, 0x20, 0x00, 0x00, 0x04, 0x04, 0x05, 0x04, 0x04, 0x04, 0x00,
		0x00, 0x20, 0x50, 0x88, 0x04, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x04, 0x05, 0x04, 0x04, 0x00,
		0x00, 0x00, 0x00, 0xf8, 0x04, 0x04, 0x18, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x40, 0x40, 0x58, 0x40, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
		0x20, 0xb0, 0x90, 0xb0, 0x20, 0xb0, 0x90, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00,
		0x00, 0x0c, 0x12, 0x12, 0x12, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x80, 0x80, 0x00, 0x00, 0xfe, 0x02, 0x02, 0x00, 0x00, 0x01, 0x02, 0x04, 0x07, 0x00, 0x00, 0x00,
		0x02, 0x7e, 0x00, 0x02, 0x02, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x44, 0x62, 0x52, 0x4a, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	****/
};

#endif

