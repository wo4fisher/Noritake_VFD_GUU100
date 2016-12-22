///////////////////////////////////////////////////////////////////////////////
//
//  Font "THIN_8X8.H" for the Noritake GU128X64E-U100 VFD display
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

#ifndef THIN_8X8_H
#define THIN_8X8_H

#define thin_8x8 pgm_get_far_address(_thin_8x8)

static const uint8_t _thin_8x8[] PROGMEM = {

	0x08, // width (base + 0)
	0x08, // height (base + 1)
	0x00, // horizontal gap (base + 2)
	0x00, // vertical gap (base + 3)
	0x00, // first char (base + 4)
	0x7f, // last char (base + 5)
	0x08, // bytes per char (base + 6)

	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x7e, 0x81, 0x95, 0xb1, 0xb1, 0x95, 0x81, 0x7e,
	0x7e, 0xff, 0xeb, 0xcf, 0xcf, 0xeb, 0xff, 0x7e,
	0x0e, 0x1f, 0x3f, 0x7e, 0x3f, 0x1f, 0x0e, 0x00,
	0x08, 0x1c, 0x3e, 0x7f, 0x3e, 0x1c, 0x08, 0x00,
	0x18, 0x9a, 0x8f, 0xff, 0x8f, 0x9a, 0x18, 0x00,
	0x10, 0xb8, 0xbc, 0xff, 0xbc, 0xb8, 0x10, 0x00,
	0x00, 0x00, 0x18, 0x3c, 0x3c, 0x18, 0x00, 0x00,
	0xff, 0xff, 0xe7, 0xc3, 0xc3, 0xe7, 0xff, 0xff,
	0x00, 0x3c, 0x66, 0x42, 0x42, 0x66, 0x3c, 0x00,
	0xff, 0xc3, 0x99, 0xbd, 0xbd, 0x99, 0xc3, 0xff,
	0x70, 0x88, 0x88, 0x89, 0x89, 0x7d, 0x03, 0x0f,
	0x00, 0x0e, 0x51, 0x51, 0xf1, 0x51, 0x51, 0x0e,
	0x80, 0xc0, 0x7f, 0x05, 0x05, 0x05, 0x05, 0x07,
	0x80, 0xc0, 0x7f, 0x05, 0x05, 0x45, 0x65, 0x3f,
	0x99, 0x5a, 0x3c, 0xe7, 0xe7, 0x3c, 0x5a, 0x99,
	0x7f, 0x3e, 0x3e, 0x1c, 0x1c, 0x08, 0x08, 0x00,
	0x08, 0x08, 0x1c, 0x1c, 0x3e, 0x3e, 0x7f, 0x00,
	0x00, 0x24, 0x66, 0xff, 0x66, 0x24, 0x00, 0x00,
	0x00, 0x00, 0x5f, 0x00, 0x00, 0x5f, 0x00, 0x00,
	0x06, 0x09, 0x09, 0x7f, 0x01, 0x01, 0x7f, 0x01,
	0x40, 0x9a, 0xa7, 0xa5, 0xe5, 0x59, 0x01, 0x02,
	0x00, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x00,
	0x80, 0x94, 0xb6, 0xff, 0xb6, 0x94, 0x80, 0x00,
	0x00, 0x04, 0x06, 0x7f, 0x06, 0x04, 0x00, 0x00,
	0x00, 0x10, 0x30, 0x7f, 0x30, 0x10, 0x00, 0x00,
	0x08, 0x08, 0x08, 0x08, 0x2a, 0x1c, 0x08, 0x00,
	0x08, 0x1c, 0x2a, 0x08, 0x08, 0x08, 0x08, 0x00,
	0x3c, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00,
	0x08, 0x1c, 0x3e, 0x08, 0x08, 0x3e, 0x1c, 0x08,
	0x30, 0x38, 0x3c, 0x3e, 0x3e, 0x3c, 0x38, 0x30,
	0x06, 0x0e, 0x1e, 0x3e, 0x3e, 0x1e, 0x0e, 0x06,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x06, 0x5f, 0x06, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x07, 0x00, 0x00, 0x07, 0x00, 0x00,
	0x14, 0x14, 0x7f, 0x14, 0x14, 0x7f, 0x14, 0x14,
	0x24, 0x2a, 0x2a, 0x6b, 0x2a, 0x12, 0x00, 0x00,
	0x46, 0x66, 0x30, 0x18, 0x0c, 0x66, 0x62, 0x00,
	0x30, 0x4a, 0x45, 0x4d, 0x05, 0x7a, 0x48, 0x00,
	0x00, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x1c, 0x22, 0x41, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x41, 0x22, 0x1c, 0x00, 0x00, 0x00,
	0x08, 0x2a, 0x1c, 0x1c, 0x1c, 0x2a, 0x08, 0x00,
	0x08, 0x08, 0x08, 0x3e, 0x08, 0x08, 0x08, 0x00,
	0x00, 0x00, 0x80, 0x60, 0x00, 0x00, 0x00, 0x00,
	0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00,
	0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 0x00,
	0x3e, 0x61, 0x51, 0x49, 0x45, 0x43, 0x3e, 0x00,
	0x00, 0x44, 0x42, 0x7f, 0x40, 0x40, 0x00, 0x00,
	0x42, 0x61, 0x51, 0x49, 0x45, 0x62, 0x00, 0x00,
	0x22, 0x41, 0x49, 0x49, 0x49, 0x36, 0x00, 0x00,
	0x10, 0x18, 0x14, 0x52, 0x7f, 0x50, 0x10, 0x00,
	0x27, 0x45, 0x45, 0x45, 0x45, 0x39, 0x00, 0x00,
	0x3c, 0x4a, 0x49, 0x49, 0x49, 0x30, 0x00, 0x00,
	0x03, 0x01, 0x71, 0x09, 0x05, 0x03, 0x00, 0x00,
	0x36, 0x49, 0x49, 0x49, 0x49, 0x36, 0x00, 0x00,
	0x06, 0x49, 0x49, 0x49, 0x29, 0x1e, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x66, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x80, 0x66, 0x00, 0x00, 0x00, 0x00,
	0x08, 0x14, 0x22, 0x41, 0x00, 0x00, 0x00, 0x00,
	0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x00, 0x00,
	0x00, 0x00, 0x41, 0x22, 0x14, 0x08, 0x00, 0x00,
	0x02, 0x01, 0x01, 0x51, 0x09, 0x06, 0x00, 0x00,
	0x3e, 0x41, 0x41, 0x5d, 0x55, 0x15, 0x1e, 0x00,
	0x7c, 0x12, 0x11, 0x11, 0x12, 0x7c, 0x00, 0x00,
	0x41, 0x7f, 0x49, 0x49, 0x49, 0x49, 0x36, 0x00,
	0x1c, 0x22, 0x41, 0x41, 0x41, 0x41, 0x22, 0x00,
	0x41, 0x7f, 0x41, 0x41, 0x41, 0x22, 0x1c, 0x00,
	0x41, 0x7f, 0x49, 0x49, 0x5d, 0x41, 0x63, 0x00,
	0x41, 0x7f, 0x49, 0x09, 0x1d, 0x01, 0x03, 0x00,
	0x1c, 0x22, 0x41, 0x41, 0x51, 0x51, 0x72, 0x00,
	0x7f, 0x08, 0x08, 0x08, 0x08, 0x7f, 0x00, 0x00,
	0x00, 0x00, 0x41, 0x7f, 0x41, 0x00, 0x00, 0x00,
	0x00, 0x30, 0x40, 0x40, 0x41, 0x3f, 0x01, 0x00,
	0x41, 0x7f, 0x08, 0x08, 0x04, 0x12, 0x61, 0x00,
	0x41, 0x7f, 0x41, 0x40, 0x40, 0x40, 0x60, 0x00,
	0x7f, 0x02, 0x04, 0x08, 0x04, 0x02, 0x7f, 0x00,
	0x7f, 0x02, 0x04, 0x08, 0x10, 0x20, 0x7f, 0x00,
	0x1c, 0x22, 0x41, 0x41, 0x41, 0x22, 0x1c, 0x00,
	0x41, 0x7f, 0x49, 0x09, 0x09, 0x09, 0x06, 0x00,
	0x1c, 0x22, 0x41, 0x61, 0x41, 0xa2, 0x1c, 0x00,
	0x41, 0x7f, 0x09, 0x09, 0x09, 0x19, 0x66, 0x00,
	0x26, 0x49, 0x49, 0x49, 0x49, 0x32, 0x00, 0x00,
	0x03, 0x01, 0x41, 0x7f, 0x41, 0x01, 0x03, 0x00,
	0x7f, 0x40, 0x40, 0x40, 0x40, 0x7f, 0x00, 0x00,
	0x1f, 0x20, 0x40, 0x40, 0x20, 0x1f, 0x00, 0x00,
	0x7f, 0x20, 0x10, 0x08, 0x10, 0x20, 0x7f, 0x00,
	0x41, 0x22, 0x14, 0x08, 0x14, 0x22, 0x41, 0x00,
	0x01, 0x02, 0x44, 0x78, 0x44, 0x02, 0x01, 0x00,
	0x47, 0x61, 0x51, 0x49, 0x45, 0x43, 0x71, 0x00,
	0x00, 0x7f, 0x41, 0x41, 0x41, 0x00, 0x00, 0x00,
	0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x00,
	0x00, 0x41, 0x41, 0x41, 0x7f, 0x00, 0x00, 0x00,
	0x08, 0x04, 0x02, 0x01, 0x02, 0x04, 0x08, 0x00,
	0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
	0x00, 0x00, 0x03, 0x04, 0x00, 0x00, 0x00, 0x00,
	0x20, 0x54, 0x54, 0x54, 0x14, 0x78, 0x40, 0x00,
	0x41, 0x7f, 0x04, 0x44, 0x44, 0x44, 0x38, 0x00,
	0x38, 0x44, 0x44, 0x44, 0x44, 0x28, 0x00, 0x00,
	0x38, 0x44, 0x44, 0x44, 0x05, 0x7f, 0x40, 0x00,
	0x38, 0x54, 0x54, 0x54, 0x54, 0x18, 0x00, 0x00,
	0x48, 0x7e, 0x49, 0x01, 0x01, 0x02, 0x00, 0x00,
	0x98, 0xa4, 0xa4, 0xa4, 0xa0, 0x7c, 0x04, 0x00,
	0x41, 0x7f, 0x08, 0x00, 0x04, 0x04, 0x78, 0x00,
	0x00, 0x00, 0x44, 0x7d, 0x40, 0x00, 0x00, 0x00,
	0x60, 0x80, 0x80, 0x80, 0x80, 0x7d, 0x00, 0x00,
	0x41, 0x7f, 0x10, 0x10, 0x10, 0x28, 0x44, 0x00,
	0x00, 0x00, 0x41, 0x7f, 0x40, 0x00, 0x00, 0x00,
	0x7c, 0x04, 0x04, 0x38, 0x04, 0x04, 0x78, 0x00,
	0x7c, 0x04, 0x04, 0x04, 0x04, 0x78, 0x00, 0x00,
	0x38, 0x44, 0x44, 0x44, 0x44, 0x38, 0x00, 0x00,
	0x84, 0xfc, 0xa0, 0x24, 0x24, 0x24, 0x18, 0x00,
	0x18, 0x24, 0x24, 0x24, 0xa0, 0xfc, 0x84, 0x00,
	0x44, 0x7c, 0x48, 0x04, 0x04, 0x04, 0x08, 0x00,
	0x48, 0x54, 0x54, 0x54, 0x54, 0x24, 0x00, 0x00,
	0x00, 0x04, 0x04, 0x3f, 0x44, 0x44, 0x20, 0x00,
	0x3c, 0x40, 0x40, 0x40, 0x00, 0x7c, 0x40, 0x00,
	0x1c, 0x20, 0x40, 0x40, 0x20, 0x1c, 0x00, 0x00,
	0x7c, 0x20, 0x10, 0x08, 0x10, 0x20, 0x7c, 0x00,
	0x44, 0x28, 0x10, 0x10, 0x28, 0x44, 0x00, 0x00,
	0x9c, 0xa0, 0xa0, 0xa0, 0xa0, 0x7c, 0x00, 0x00,
	0x4c, 0x64, 0x54, 0x54, 0x4c, 0x64, 0x00, 0x00,
	0x08, 0x08, 0x36, 0x41, 0x41, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x77, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x41, 0x41, 0x36, 0x08, 0x08, 0x00, 0x00,
	0x02, 0x01, 0x01, 0x02, 0x02, 0x01, 0x00, 0x00,
	0x70, 0x48, 0x44, 0x42, 0x44, 0x48, 0x70, 0x00,
	/****
		0x0e, 0x91, 0x91, 0xb1, 0xb1, 0x4a, 0x00, 0x00,
		0x3a, 0x40, 0x40, 0x40, 0x40, 0x3a, 0x40, 0x00,
		0x38, 0x54, 0x54, 0x54, 0x55, 0x19, 0x00, 0x00,
		0x02, 0x21, 0x55, 0x55, 0x55, 0x55, 0x39, 0x42,
		0x21, 0x54, 0x54, 0x54, 0x54, 0x39, 0x40, 0x00,
		0x21, 0x55, 0x54, 0x54, 0x54, 0x38, 0x40, 0x00,
		0x20, 0x54, 0x57, 0x54, 0x54, 0x38, 0x40, 0x00,
		0x18, 0x24, 0xa4, 0xa4, 0xa4, 0x40, 0x00, 0x00,
		0x02, 0x39, 0x55, 0x55, 0x55, 0x55, 0x19, 0x02,
		0x39, 0x54, 0x54, 0x54, 0x54, 0x19, 0x00, 0x00,
		0x38, 0x55, 0x55, 0x54, 0x54, 0x18, 0x00, 0x00,
		0x00, 0x01, 0x44, 0x7c, 0x41, 0x00, 0x00, 0x00,
		0x02, 0x01, 0x45, 0x7d, 0x41, 0x01, 0x02, 0x00,
		0x00, 0x01, 0x45, 0x7c, 0x40, 0x00, 0x00, 0x00,
		0x79, 0x14, 0x12, 0x12, 0x12, 0x14, 0x79, 0x00,
		0x78, 0x14, 0x11, 0x13, 0x10, 0x14, 0x78, 0x00,
		0x42, 0x7e, 0x4a, 0x4a, 0x4b, 0x43, 0x00, 0x00,
		0x20, 0x54, 0x54, 0x78, 0x38, 0x54, 0x54, 0x5c,
		0x7c, 0x0a, 0x09, 0x09, 0x7f, 0x49, 0x49, 0x49,
		0x3a, 0x45, 0x45, 0x45, 0x45, 0x3a, 0x00, 0x00,
		0x39, 0x44, 0x44, 0x44, 0x44, 0x39, 0x00, 0x00,
		0x39, 0x45, 0x44, 0x44, 0x44, 0x38, 0x00, 0x00,
		0x02, 0x3d, 0x41, 0x41, 0x41, 0x41, 0x3d, 0x02,
		0x00, 0x3c, 0x41, 0x42, 0x40, 0x40, 0x3c, 0x00,
		0x9d, 0xa0, 0xa0, 0xa0, 0xa0, 0x7d, 0x00, 0x00,
		0x00, 0x19, 0x24, 0x42, 0x42, 0x24, 0x19, 0x00,
		0x3d, 0x40, 0x40, 0x40, 0x40, 0x3d, 0x00, 0x00,
		0x18, 0x24, 0x24, 0xe7, 0x24, 0x24, 0x24, 0x00,
		0x68, 0x5e, 0x49, 0x41, 0x41, 0x46, 0x20, 0x00,
		0x00, 0x29, 0x2a, 0xfc, 0x2a, 0x29, 0x00, 0x00,
		0xff, 0x09, 0x09, 0x09, 0x09, 0x26, 0xf0, 0xa0,
		0x40, 0x80, 0x88, 0x7e, 0x09, 0x01, 0x02, 0x00,
		0x20, 0x54, 0x54, 0x55, 0x55, 0x39, 0x40, 0x00,
		0x00, 0x00, 0x44, 0x7d, 0x41, 0x00, 0x00, 0x00,
		0x38, 0x44, 0x44, 0x46, 0x45, 0x38, 0x00, 0x00,
		0x3c, 0x40, 0x40, 0x42, 0x41, 0x3c, 0x40, 0x00,
		0x7e, 0x09, 0x05, 0x06, 0x06, 0x79, 0x00, 0x00,
		0x7e, 0x01, 0x09, 0x12, 0x02, 0x7d, 0x00, 0x00,
		0x00, 0x26, 0x29, 0x29, 0x29, 0x27, 0x28, 0x00,
		0x00, 0x26, 0x29, 0x29, 0x29, 0x26, 0x00, 0x00,
		0x30, 0x48, 0x45, 0x40, 0x40, 0x20, 0x00, 0x00,
		0x38, 0x38, 0x08, 0x08, 0x08, 0x08, 0x00, 0x00,
		0x08, 0x08, 0x08, 0x08, 0x38, 0x38, 0x00, 0x00,
		0x40, 0x3f, 0x10, 0x08, 0x94, 0xca, 0xa9, 0x90,
		0x40, 0x3f, 0x10, 0x08, 0x64, 0x52, 0x49, 0xf8,
		0x00, 0x00, 0x30, 0x7b, 0x30, 0x00, 0x00, 0x00,
		0x08, 0x14, 0x22, 0x00, 0x08, 0x14, 0x22, 0x00,
		0x00, 0x22, 0x14, 0x08, 0x00, 0x22, 0x14, 0x08,
		0xaa, 0x00, 0x55, 0x00, 0xaa, 0x00, 0x55, 0x00,
		0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55,
		0xdd, 0xff, 0xaa, 0x77, 0xdd, 0xaa, 0xff, 0x77,
		0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00,
		0x10, 0x10, 0x10, 0xff, 0xff, 0x00, 0x00, 0x00,
		0x14, 0x14, 0x14, 0xff, 0xff, 0x00, 0x00, 0x00,
		0x10, 0x10, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00,
		0x10, 0x10, 0xf0, 0xf0, 0x10, 0xf0, 0xf0, 0x00,
		0x14, 0x14, 0x14, 0xfc, 0xfc, 0x00, 0x00, 0x00,
		0x14, 0x14, 0xf7, 0xf7, 0x00, 0xff, 0xff, 0x00,
		0x00, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00,
		0x14, 0x14, 0xf4, 0xf4, 0x04, 0xfc, 0xfc, 0x00,
		0x14, 0x14, 0x17, 0x17, 0x10, 0x1f, 0x1f, 0x00,
		0x10, 0x10, 0x1f, 0x1f, 0x10, 0x1f, 0x1f, 0x00,
		0x14, 0x14, 0x14, 0x1f, 0x1f, 0x00, 0x00, 0x00,
		0x10, 0x10, 0x10, 0xf0, 0xf0, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x1f, 0x1f, 0x10, 0x10, 0x10,
		0x10, 0x10, 0x10, 0x1f, 0x1f, 0x10, 0x10, 0x10,
		0x10, 0x10, 0x10, 0xf0, 0xf0, 0x10, 0x10, 0x10,
		0x00, 0x00, 0x00, 0xff, 0xff, 0x10, 0x10, 0x10,
		0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
		0x10, 0x10, 0x10, 0xff, 0xff, 0x10, 0x10, 0x10,
		0x00, 0x00, 0x00, 0xff, 0xff, 0x14, 0x14, 0x14,
		0x00, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x10,
		0x00, 0x00, 0x1f, 0x1f, 0x10, 0x17, 0x17, 0x14,
		0x00, 0x00, 0xfc, 0xfc, 0x04, 0xf4, 0xf4, 0x14,
		0x14, 0x14, 0x17, 0x17, 0x10, 0x17, 0x17, 0x14,
		0x14, 0x14, 0xf4, 0xf4, 0x04, 0xf4, 0xf4, 0x14,
		0x00, 0x00, 0xff, 0xff, 0x00, 0xf7, 0xf7, 0x14,
		0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14,
		0x14, 0x14, 0xf7, 0xf7, 0x00, 0xf7, 0xf7, 0x14,
		0x14, 0x14, 0x14, 0x17, 0x17, 0x14, 0x14, 0x14,
		0x10, 0x10, 0x1f, 0x1f, 0x10, 0x1f, 0x1f, 0x10,
		0x14, 0x14, 0x14, 0xf4, 0xf4, 0x14, 0x14, 0x14,
		0x10, 0x10, 0xf0, 0xf0, 0x10, 0xf0, 0xf0, 0x10,
		0x00, 0x00, 0x1f, 0x1f, 0x10, 0x1f, 0x1f, 0x10,
		0x00, 0x00, 0x00, 0x1f, 0x1f, 0x14, 0x14, 0x14,
		0x00, 0x00, 0x00, 0xfc, 0xfc, 0x14, 0x14, 0x14,
		0x00, 0x00, 0xf0, 0xf0, 0x10, 0xf0, 0xf0, 0x10,
		0x10, 0x10, 0xff, 0xff, 0x10, 0xff, 0xff, 0x10,
		0x14, 0x14, 0x14, 0xff, 0xff, 0x14, 0x14, 0x14,
		0x10, 0x10, 0x10, 0x1f, 0x1f, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xf0, 0xf0, 0x10, 0x10, 0x10,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0,
		0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
		0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
		0x38, 0x44, 0x44, 0x28, 0x10, 0x28, 0x44, 0x00,
		0xfc, 0x2a, 0x2a, 0x2a, 0x2a, 0x14, 0x00, 0x00,
		0x7e, 0x02, 0x02, 0x02, 0x02, 0x06, 0x00, 0x00,
		0x02, 0x02, 0x7e, 0x02, 0x7e, 0x02, 0x02, 0x00,
		0x63, 0x55, 0x49, 0x41, 0x41, 0x63, 0x00, 0x00,
		0x38, 0x44, 0x44, 0x44, 0x3c, 0x04, 0x04, 0x00,
		0x80, 0x7e, 0x20, 0x20, 0x20, 0x20, 0x1e, 0x00,
		0x04, 0x02, 0x02, 0x02, 0x7c, 0x02, 0x02, 0x00,
		0x99, 0xa5, 0xe7, 0xa5, 0x99, 0x00, 0x00, 0x00,
		0x1c, 0x2a, 0x49, 0x49, 0x49, 0x2a, 0x1c, 0x00,
		0x0c, 0x42, 0x71, 0x01, 0x71, 0x42, 0x0c, 0x00,
		0x30, 0x48, 0x48, 0x4b, 0x4d, 0x39, 0x00, 0x00,
		0x18, 0x24, 0x24, 0x3c, 0x24, 0x24, 0x18, 0x00,
		0x98, 0x64, 0x24, 0x34, 0x2c, 0x26, 0x25, 0x18,
		0x1c, 0x2a, 0x49, 0x49, 0x49, 0x00, 0x00, 0x00,
		0x7e, 0x01, 0x01, 0x01, 0x01, 0x7e, 0x00, 0x00,
		0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 0x00, 0x00,
		0x44, 0x44, 0x5f, 0x44, 0x44, 0x44, 0x00, 0x00,
		0x40, 0x51, 0x4a, 0x44, 0x40, 0x40, 0x00, 0x00,
		0x40, 0x44, 0x4a, 0x51, 0x40, 0x40, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xfe, 0x01, 0x01, 0x01, 0x06,
		0x60, 0x80, 0x80, 0x80, 0x7f, 0x00, 0x00, 0x00,
		0x08, 0x08, 0x6b, 0x08, 0x08, 0x00, 0x00, 0x00,
		0x24, 0x12, 0x12, 0x24, 0x24, 0x12, 0x00, 0x00,
		0x00, 0x06, 0x09, 0x09, 0x09, 0x06, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x10, 0x10, 0x00, 0x00, 0x00,
		0x00, 0x10, 0x30, 0x40, 0xc0, 0xff, 0x01, 0x01,
		0x00, 0x1f, 0x00, 0x01, 0x01, 0x1e, 0x00, 0x00,
		0x00, 0x12, 0x19, 0x15, 0x12, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x3c, 0x3c, 0x3c, 0x3c, 0x00, 0x00,
		0x18, 0xa8, 0x48, 0x00, 0x10, 0xa0, 0x40, 0x00,
	****/
};

#endif

