///////////////////////////////////////////////////////////////////////////////
//
//  Font "FONT_6X8X.H" for the Noritake GU128X64E-U100 VFD display
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

#ifndef FONT_6X8X_H
#define FONT_6X8X_H

#define font_6x8x pgm_get_far_address(_font_6x8x)

static const uint8_t _font_6x8x[] PROGMEM = {

	0x06, // width (base + 0)
	0x08, // height (base + 1)
	0x00, // horizontal gap (base + 2)
	0x00, // vertical gap (base + 3)
	0x00, // first char (base + 4)
	0x06, // bytes per char (base + 5)

	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x3e, 0x45, 0x51, 0x45, 0x3e,
	0x00, 0x3e, 0x6b, 0x6f, 0x6b, 0x3e,
	0x00, 0x1c, 0x3e, 0x7c, 0x3e, 0x1c,
	0x00, 0x00, 0x1c, 0x38, 0x1c, 0x00,
	0x00, 0x30, 0x36, 0x7f, 0x36, 0x30,
	0x00, 0x18, 0x5c, 0x7e, 0x5c, 0x18,
	0x00, 0x00, 0x18, 0x18, 0x00, 0x00,
	0xff, 0xff, 0xe7, 0xe7, 0xff, 0xff,
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00,
	0xff, 0xc3, 0xdb, 0xdb, 0xc3, 0xff,
	0x00, 0x30, 0x48, 0x4a, 0x36, 0x0e,
	0x00, 0x06, 0x29, 0x79, 0x29, 0x06,
	0x00, 0x60, 0x70, 0x3f, 0x02, 0x04,
	0x00, 0x60, 0x7e, 0x0a, 0x35, 0x3f,
	0x00, 0x18, 0x24, 0x24, 0x24, 0x18,
	0x00, 0x00, 0x7f, 0x3e, 0x1c, 0x08,
	0x00, 0x08, 0x1c, 0x3e, 0x7f, 0x00,
	0x00, 0x7e, 0x7e, 0x00, 0x7e, 0x7e,
	0x00, 0x3c, 0x3c, 0x3c, 0x3c, 0x00,
	0x00, 0x50, 0x5c, 0x5f, 0x5c, 0x50,
	0x00, 0x7f, 0x3e, 0x1c, 0x08, 0x7f,
	0x00, 0x7f, 0x08, 0x1c, 0x3e, 0x7f,
	0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
	0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0,
	0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0,
	0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0,
	0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8,
	0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc,
	0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x06, 0x5f, 0x06, 0x00,
	0x00, 0x07, 0x03, 0x00, 0x07, 0x03,
	0x00, 0x24, 0x7e, 0x24, 0x7e, 0x24,
	0x00, 0x24, 0x2a, 0x6b, 0x12, 0x00,
	0x00, 0x63, 0x13, 0x08, 0x64, 0x63,
	0x00, 0x36, 0x49, 0x56, 0x20, 0x50,
	0x00, 0x00, 0x07, 0x03, 0x00, 0x00,
	0x00, 0x00, 0x3e, 0x41, 0x00, 0x00,
	0x00, 0x00, 0x41, 0x3e, 0x00, 0x00,
	0x00, 0x08, 0x3e, 0x1c, 0x3e, 0x08,
	0x00, 0x08, 0x08, 0x3e, 0x08, 0x08,
	0x00, 0x00, 0xe0, 0x60, 0x00, 0x00,
	0x00, 0x08, 0x08, 0x08, 0x08, 0x08,
	0x00, 0x00, 0x60, 0x60, 0x00, 0x00,
	0x00, 0x20, 0x10, 0x08, 0x04, 0x02,
	0x00, 0x3e, 0x51, 0x49, 0x45, 0x3e,
	0x00, 0x00, 0x42, 0x7f, 0x40, 0x00,
	0x00, 0x62, 0x51, 0x49, 0x49, 0x46,
	0x00, 0x22, 0x49, 0x49, 0x49, 0x36,
	0x00, 0x18, 0x14, 0x12, 0x7f, 0x10,
	0x00, 0x2f, 0x49, 0x49, 0x49, 0x31,
	0x00, 0x3c, 0x4a, 0x49, 0x49, 0x30,
	0x00, 0x01, 0x71, 0x09, 0x05, 0x03,
	0x00, 0x36, 0x49, 0x49, 0x49, 0x36,
	0x00, 0x06, 0x49, 0x49, 0x29, 0x1e,
	0x00, 0x00, 0x36, 0x36, 0x00, 0x00,
	0x00, 0x00, 0xec, 0x6c, 0x00, 0x00,
	0x00, 0x08, 0x14, 0x22, 0x41, 0x00,
	0x00, 0x24, 0x24, 0x24, 0x24, 0x24,
	0x00, 0x00, 0x41, 0x22, 0x14, 0x08,
	0x00, 0x02, 0x01, 0x59, 0x09, 0x06,
	0x00, 0x3e, 0x41, 0x5d, 0x55, 0x1e,
	0x00, 0x7e, 0x11, 0x11, 0x11, 0x7e,
	0x00, 0x7f, 0x49, 0x49, 0x49, 0x36,
	0x00, 0x3e, 0x41, 0x41, 0x41, 0x22,
	0x00, 0x7f, 0x41, 0x41, 0x41, 0x3e,
	0x00, 0x7f, 0x49, 0x49, 0x49, 0x41,
	0x00, 0x7f, 0x09, 0x09, 0x09, 0x01,
	0x00, 0x3e, 0x41, 0x49, 0x49, 0x7a,
	0x00, 0x7f, 0x08, 0x08, 0x08, 0x7f,
	0x00, 0x00, 0x41, 0x7f, 0x41, 0x00,
	0x00, 0x30, 0x40, 0x40, 0x40, 0x3f,
	0x00, 0x7f, 0x08, 0x14, 0x22, 0x41,
	0x00, 0x7f, 0x40, 0x40, 0x40, 0x40,
	0x00, 0x7f, 0x02, 0x04, 0x02, 0x7f,
	0x00, 0x7f, 0x02, 0x04, 0x08, 0x7f,
	0x00, 0x3e, 0x41, 0x41, 0x41, 0x3e,
	0x00, 0x7f, 0x09, 0x09, 0x09, 0x06,
	0x00, 0x3e, 0x41, 0x51, 0x21, 0x5e,
	0x00, 0x7f, 0x09, 0x09, 0x19, 0x66,
	0x00, 0x26, 0x49, 0x49, 0x49, 0x32,
	0x00, 0x01, 0x01, 0x7f, 0x01, 0x01,
	0x00, 0x3f, 0x40, 0x40, 0x40, 0x3f,
	0x00, 0x1f, 0x20, 0x40, 0x20, 0x1f,
	0x00, 0x3f, 0x40, 0x3c, 0x40, 0x3f,
	0x00, 0x63, 0x14, 0x08, 0x14, 0x63,
	0x00, 0x07, 0x08, 0x70, 0x08, 0x07,
	0x00, 0x71, 0x49, 0x45, 0x43, 0x00,
	0x00, 0x00, 0x7f, 0x41, 0x41, 0x00,
	0x00, 0x02, 0x04, 0x08, 0x10, 0x20,
	0x00, 0x00, 0x41, 0x41, 0x7f, 0x00,
	0x00, 0x04, 0x02, 0x01, 0x02, 0x04,
	0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
	0x00, 0x00, 0x03, 0x07, 0x00, 0x00,
	0x00, 0x20, 0x54, 0x54, 0x54, 0x78,
	0x00, 0x7f, 0x44, 0x44, 0x44, 0x38,
	0x00, 0x38, 0x44, 0x44, 0x44, 0x28,
	0x00, 0x38, 0x44, 0x44, 0x44, 0x7f,
	0x00, 0x38, 0x54, 0x54, 0x54, 0x08,
	0x00, 0x08, 0x7e, 0x09, 0x09, 0x00,
	0x00, 0x18, 0xa4, 0xa4, 0xa4, 0x7c,
	0x00, 0x7f, 0x04, 0x04, 0x78, 0x00,
	0x00, 0x00, 0x00, 0x7d, 0x40, 0x00,
	0x00, 0x40, 0x80, 0x84, 0x7d, 0x00,
	0x00, 0x7f, 0x10, 0x28, 0x44, 0x00,
	0x00, 0x00, 0x00, 0x7f, 0x40, 0x00,
	0x00, 0x7c, 0x04, 0x18, 0x04, 0x78,
	0x00, 0x7c, 0x04, 0x04, 0x78, 0x00,
	0x00, 0x38, 0x44, 0x44, 0x44, 0x38,
	0x00, 0xfc, 0x44, 0x44, 0x44, 0x38,
	0x00, 0x38, 0x44, 0x44, 0x44, 0xfc,
	0x00, 0x44, 0x78, 0x44, 0x04, 0x08,
	0x00, 0x08, 0x54, 0x54, 0x54, 0x20,
	0x00, 0x04, 0x3e, 0x44, 0x24, 0x00,
	0x00, 0x3c, 0x40, 0x20, 0x7c, 0x00,
	0x00, 0x1c, 0x20, 0x40, 0x20, 0x1c,
	0x00, 0x3c, 0x60, 0x30, 0x60, 0x3c,
	0x00, 0x6c, 0x10, 0x10, 0x6c, 0x00,
	0x00, 0x9c, 0xa0, 0x60, 0x3c, 0x00,
	0x00, 0x64, 0x54, 0x54, 0x4c, 0x00,
	0x00, 0x08, 0x3e, 0x41, 0x41, 0x00,
	0x00, 0x00, 0x00, 0xff, 0x00, 0x00,
	0x00, 0x00, 0x41, 0x41, 0x3e, 0x08,
	0x00, 0x02, 0x01, 0x02, 0x01, 0x00,
	0x00, 0x80, 0x80, 0x80, 0x80, 0x00,
	0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0x00,
	0x00, 0xe0, 0xe0, 0xe0, 0xe0, 0x00,
	0x00, 0xf0, 0xf0, 0xf0, 0xf0, 0x00,
	0x00, 0xf8, 0xf8, 0xf8, 0xf8, 0x00,
	0x00, 0xfc, 0xfc, 0xfc, 0xfc, 0x00,
	0x00, 0xfe, 0xfe, 0xfe, 0xfe, 0x00,
	0x00, 0xff, 0xff, 0xff, 0xff, 0x00,
	0x3c, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x3c, 0x3c, 0x00, 0x00, 0x00, 0x00,
	0x3c, 0x3c, 0x3c, 0x00, 0x00, 0x00,
	0x3c, 0x3c, 0x3c, 0x3c, 0x00, 0x00,
	0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x00,
	0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0x00, 0x22, 0x55, 0x59, 0x30, 0x00,
	0x00, 0x1c, 0x2a, 0x2a, 0x2a, 0x00,
	0x00, 0x02, 0x7e, 0x02, 0x7e, 0x02,
	0x00, 0x18, 0x24, 0x24, 0x1c, 0x04,
	0x00, 0x08, 0x04, 0x78, 0x04, 0x00,
	0x00, 0x18, 0x24, 0x7e, 0x24, 0x18,
	0x00, 0x18, 0x24, 0x18, 0x24, 0x18,
	0x00, 0x7f, 0x01, 0x01, 0x03, 0x00,
	0x00, 0x3e, 0x49, 0x49, 0x3e, 0x00,
	0x00, 0x08, 0x55, 0x77, 0x55, 0x08,
	0x00, 0x4c, 0x72, 0x02, 0x72, 0x4c,
	0xfc, 0x8c, 0x8c, 0x94, 0x94, 0xa4,
	0xa4, 0x94, 0x94, 0x8c, 0x8c, 0xfc,
	0x00, 0x08, 0x1c, 0x2a, 0x08, 0x08,
	0x00, 0x04, 0x02, 0x7f, 0x02, 0x04,
	0x00, 0x08, 0x08, 0x2a, 0x1c, 0x08,
	0x00, 0x10, 0x20, 0x7f, 0x20, 0x10,
	0x08, 0x1c, 0x2a, 0x2a, 0x1c, 0x08,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x30, 0x7d, 0x30, 0x00,
	0x00, 0x18, 0x24, 0x7e, 0x24, 0x00,
	0x00, 0x48, 0x3e, 0x49, 0x49, 0x62,
	0x00, 0x38, 0x54, 0x54, 0x44, 0x28,
	0x00, 0x29, 0x2a, 0x7c, 0x2a, 0x29,
	0x00, 0x48, 0x55, 0x56, 0x55, 0x24,
	0x00, 0x22, 0x4d, 0x55, 0x59, 0x22,
	0x00, 0x08, 0x55, 0x56, 0x55, 0x20,
	0x00, 0x38, 0x7c, 0x6c, 0x44, 0x38,
	0x00, 0x08, 0x55, 0x55, 0x55, 0x5e,
	0x00, 0x08, 0x14, 0x00, 0x08, 0x14,
	0x04, 0x04, 0x04, 0x04, 0x04, 0x1c,
	0x00, 0x08, 0x08, 0x08, 0x08, 0x08,
	0x00, 0x38, 0x7c, 0x5c, 0x74, 0x38,
	0x00, 0x01, 0x01, 0x01, 0x01, 0x01,
	0x00, 0x06, 0x09, 0x09, 0x09, 0x06,
	0x00, 0x24, 0x24, 0x3f, 0x24, 0x24,
	0x00, 0x09, 0x0d, 0x0a, 0x00, 0x00,
	0x00, 0x15, 0x15, 0x0a, 0x00, 0x00,
	0x00, 0x65, 0x56, 0x4e, 0x45, 0x00,
	0x00, 0xfc, 0x20, 0x20, 0x1c, 0x00,
	0x00, 0x06, 0x09, 0x7f, 0x01, 0x7f,
	0x00, 0x00, 0x18, 0x18, 0x00, 0x00,
	0x00, 0x65, 0x56, 0x56, 0x4d, 0x00,
	0x00, 0x12, 0x1f, 0x10, 0x00, 0x00,
	0x00, 0x4e, 0x51, 0x51, 0x4e, 0x00,
	0x00, 0x14, 0x08, 0x00, 0x14, 0x08,
	0x00, 0x7f, 0x41, 0x7f, 0x49, 0x49,
	0x00, 0x7c, 0x44, 0x7c, 0x54, 0x48,
	0x00, 0x04, 0x09, 0x70, 0x09, 0x04,
	0x00, 0x30, 0x48, 0x4d, 0x40, 0x20,
	0x00, 0x70, 0x29, 0x25, 0x2a, 0x70,
	0x00, 0x70, 0x2a, 0x25, 0x29, 0x70,
	0x00, 0x70, 0x2a, 0x25, 0x2a, 0x70,
	0x00, 0x72, 0x29, 0x26, 0x29, 0x70,
	0x00, 0x70, 0x29, 0x24, 0x29, 0x70,
	0x00, 0x78, 0x2f, 0x25, 0x2f, 0x78,
	0x00, 0x7e, 0x09, 0x7f, 0x49, 0x49,
	0x00, 0x1e, 0xa1, 0xe1, 0x21, 0x12,
	0x00, 0x7c, 0x55, 0x55, 0x56, 0x46,
	0x00, 0x7c, 0x56, 0x56, 0x55, 0x45,
	0x00, 0x7e, 0x55, 0x55, 0x56, 0x44,
	0x00, 0x7c, 0x55, 0x54, 0x54, 0x45,
	0x00, 0x00, 0x45, 0x7d, 0x46, 0x00,
	0x00, 0x00, 0x46, 0x7d, 0x45, 0x00,
	0x00, 0x00, 0x46, 0x7d, 0x46, 0x00,
	0x00, 0x00, 0x45, 0x7c, 0x45, 0x00,
	0x00, 0x7f, 0x49, 0x49, 0x41, 0x3e,
	0x00, 0x7a, 0x11, 0x22, 0x79, 0x00,
	0x00, 0x39, 0x45, 0x46, 0x38, 0x00,
	0x00, 0x38, 0x46, 0x45, 0x39, 0x00,
	0x00, 0x38, 0x46, 0x45, 0x3a, 0x00,
	0x00, 0x3a, 0x45, 0x46, 0x39, 0x00,
	0x00, 0x39, 0x44, 0x44, 0x39, 0x00,
	0x00, 0x28, 0x10, 0x10, 0x28, 0x00,
	0x00, 0x3e, 0x61, 0x5d, 0x43, 0x3e,
	0x00, 0x3c, 0x41, 0x41, 0x3e, 0x00,
	0x00, 0x3c, 0x42, 0x41, 0x3d, 0x00,
	0x00, 0x38, 0x42, 0x41, 0x3a, 0x00,
	0x00, 0x3c, 0x41, 0x40, 0x3d, 0x00,
	0x00, 0x04, 0x0a, 0x71, 0x09, 0x04,
	0x00, 0xff, 0x44, 0x44, 0x44, 0x38,
	0x00, 0x7e, 0x0a, 0x4a, 0x34, 0x00,
	0x00, 0x20, 0x55, 0x55, 0x56, 0x78,
	0x00, 0x20, 0x56, 0x55, 0x55, 0x78,
	0x00, 0x20, 0x56, 0x55, 0x56, 0x78,
	0x00, 0x20, 0x56, 0x55, 0x56, 0x79,
	0x00, 0x20, 0x55, 0x54, 0x55, 0x78,
	0x00, 0x20, 0x57, 0x55, 0x57, 0x78,
	0x00, 0x34, 0x54, 0x7c, 0x54, 0x58,
	0x00, 0x1c, 0xa2, 0xe2, 0x22, 0x14,
	0x00, 0x38, 0x55, 0x55, 0x56, 0x08,
	0x00, 0x38, 0x54, 0x56, 0x55, 0x09,
	0x00, 0x38, 0x56, 0x55, 0x56, 0x08,
	0x00, 0x38, 0x55, 0x54, 0x55, 0x08,
	0x00, 0x00, 0x01, 0x7d, 0x42, 0x00,
	0x00, 0x00, 0x02, 0x7d, 0x41, 0x00,
	0x00, 0x00, 0x02, 0x79, 0x42, 0x00,
	0x00, 0x00, 0x01, 0x7c, 0x41, 0x00,
	0x00, 0x39, 0x47, 0x45, 0x45, 0x3e,
	0x00, 0x7a, 0x09, 0x0a, 0x71, 0x00,
	0x00, 0x39, 0x45, 0x46, 0x38, 0x00,
	0x00, 0x38, 0x46, 0x45, 0x39, 0x00,
	0x00, 0x38, 0x46, 0x45, 0x3a, 0x00,
	0x00, 0x3a, 0x45, 0x46, 0x39, 0x00,
	0x00, 0x38, 0x45, 0x44, 0x39, 0x00,
	0x00, 0x08, 0x08, 0x2a, 0x08, 0x08,
	0x00, 0xb8, 0x64, 0x54, 0x4c, 0x3a,
	0x00, 0x3d, 0x41, 0x22, 0x7c, 0x00,
	0x00, 0x3c, 0x42, 0x21, 0x7d, 0x00,
	0x00, 0x38, 0x42, 0x21, 0x7a, 0x00,
	0x00, 0x3c, 0x41, 0x20, 0x7d, 0x00,
	0x00, 0x9c, 0xa2, 0x61, 0x3d, 0x00,
	0x00, 0xff, 0x48, 0x48, 0x48, 0x30,
	0x00, 0x9c, 0xa1, 0x60, 0x3d, 0x00,
};

#endif

