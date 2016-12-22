///////////////////////////////////////////////////////////////////////////////
//
//  Font "GLCDFONT.H" for the Noritake GU128X64E-U100 VFD display
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

#ifndef GLCDFONT_H
#define GLCDFONT_H

#define glcdfont pgm_get_far_address(_glcdfont)

static const uint8_t _glcdfont[] PROGMEM = {

	0x06, // width (base + 0)
	0x08, // height (base + 1)
	0x00, // horizontal gap (base + 2)
	0x00, // vertical gap (base + 3)
	0x00, // first char (base + 4)
	0x7f, // last char (base + 5)
	0x06, // bytes per char (base + 6)

	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0x00
	0x3e, 0x5b, 0x4f, 0x5b, 0x3e, 0x00,
	0x3e, 0x6b, 0x4f, 0x6b, 0x3e, 0x00,
	0x1c, 0x3e, 0x7c, 0x3e, 0x1c, 0x00,
	0x18, 0x3c, 0x7e, 0x3c, 0x18, 0x00,
	0x1c, 0x57, 0x7d, 0x57, 0x1c, 0x00,
	0x1c, 0x5e, 0x7f, 0x5e, 0x1c, 0x00,
	0x00, 0x18, 0x3c, 0x18, 0x00, 0x00,
	0xff, 0xe7, 0xc3, 0xe7, 0xff, 0x00,
	0x00, 0x18, 0x24, 0x18, 0x00, 0x00,
	0xff, 0xe7, 0xdb, 0xe7, 0xff, 0x00,
	0x30, 0x48, 0x3a, 0x06, 0x0e, 0x00,
	0x26, 0x29, 0x79, 0x29, 0x26, 0x00,
	0x40, 0x7f, 0x05, 0x05, 0x07, 0x00,
	0x40, 0x7f, 0x05, 0x25, 0x3f, 0x00,
	0x5a, 0x3c, 0xe7, 0x3c, 0x5a, 0x00,
	0x7f, 0x3e, 0x1c, 0x1c, 0x08, 0x00, // 0x10
	0x08, 0x1c, 0x1c, 0x3e, 0x7f, 0x00,
	0x14, 0x22, 0x7f, 0x22, 0x14, 0x00,
	0x5f, 0x5f, 0x00, 0x5f, 0x5f, 0x00,
	0x06, 0x09, 0x7f, 0x01, 0x7f, 0x00,
	0x00, 0x66, 0x89, 0x95, 0x6a, 0x00,
	0x60, 0x60, 0x60, 0x60, 0x60, 0x00,
	0x94, 0xa2, 0xff, 0xa2, 0x94, 0x00,
	0x08, 0x04, 0x7e, 0x04, 0x08, 0x00,
	0x10, 0x20, 0x7e, 0x20, 0x10, 0x00,
	0x08, 0x08, 0x2a, 0x1c, 0x08, 0x00,
	0x08, 0x1c, 0x2a, 0x08, 0x08, 0x00,
	0x1e, 0x10, 0x10, 0x10, 0x10, 0x00,
	0x0c, 0x1e, 0x0c, 0x1e, 0x0c, 0x00,
	0x30, 0x38, 0x3e, 0x38, 0x30, 0x00,
	0x06, 0x0e, 0x3e, 0x0e, 0x06, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0x20
	0x00, 0x00, 0x5f, 0x00, 0x00, 0x00,
	0x00, 0x07, 0x00, 0x07, 0x00, 0x00,
	0x14, 0x7f, 0x14, 0x7f, 0x14, 0x00,
	0x24, 0x2a, 0x7f, 0x2a, 0x12, 0x00,
	0x23, 0x13, 0x08, 0x64, 0x62, 0x00,
	0x36, 0x49, 0x56, 0x20, 0x50, 0x00,
	0x00, 0x08, 0x07, 0x03, 0x00, 0x00,
	0x00, 0x1c, 0x22, 0x41, 0x00, 0x00,
	0x00, 0x41, 0x22, 0x1c, 0x00, 0x00,
	0x2a, 0x1c, 0x7f, 0x1c, 0x2a, 0x00,
	0x08, 0x08, 0x3e, 0x08, 0x08, 0x00,
	0x00, 0x80, 0x70, 0x30, 0x00, 0x00,
	0x08, 0x08, 0x08, 0x08, 0x08, 0x00,
	0x00, 0x00, 0x60, 0x60, 0x00, 0x00,
	0x20, 0x10, 0x08, 0x04, 0x02, 0x00,
	0x3e, 0x51, 0x49, 0x45, 0x3e, 0x00, // 0x30
	0x00, 0x42, 0x7f, 0x40, 0x00, 0x00,
	0x72, 0x49, 0x49, 0x49, 0x46, 0x00,
	0x21, 0x41, 0x49, 0x4d, 0x33, 0x00,
	0x18, 0x14, 0x12, 0x7f, 0x10, 0x00,
	0x27, 0x45, 0x45, 0x45, 0x39, 0x00,
	0x3c, 0x4a, 0x49, 0x49, 0x31, 0x00,
	0x41, 0x21, 0x11, 0x09, 0x07, 0x00,
	0x36, 0x49, 0x49, 0x49, 0x36, 0x00,
	0x46, 0x49, 0x49, 0x29, 0x1e, 0x00,

	//////////////////////////////////////////                           _ _ _ _ _ _
	//	0x00, 0x00, 0x14, 0x00, 0x00, 0x00, // original colon 0x3A      |_|_|_|_|_|_|  1
	//	                                                                |_|_|_|_|_|_|  2
	//	                                                                |_|_|*|_|_|_|  4
	//	                                                                |_|_|_|_|_|_|  8
	//	                                                                |_|_|*|_|_|_| 10
	//	                                                                |_|_|_|_|_|_| 20
	//	                                                                |_|_|_|_|_|_| 40
	//	                                                                |_|_|_|_|_|_| 80
	//////////////////////////////////////////

	//////////////////////////////////////////                           _ _ _ _ _ _
	0x00, 0x00, 0x36, 0x36, 0x00, 0x00, // improved colon 0x3A      |_|_|_|_|_|_|  1
	//	                                                                |_|_|*|*|_|_|  2
	//	                                                                |_|_|*|*|_|_|  4
	//	                                                                |_|_|_|_|_|_|  8
	//	                                                                |_|_|*|*|_|_| 10
	//	                                                                |_|_|*|*|_|_| 20
	//	                                                                |_|_|_|_|_|_| 40
	//	                                                                |_|_|_|_|_|_| 80
	//////////////////////////////////////////

	0x00, 0x40, 0x34, 0x00, 0x00, 0x00,
	0x00, 0x08, 0x14, 0x22, 0x41, 0x00,
	0x14, 0x14, 0x14, 0x14, 0x14, 0x00,
	0x00, 0x41, 0x22, 0x14, 0x08, 0x00,
	0x02, 0x01, 0x59, 0x09, 0x06, 0x00,
	0x3e, 0x41, 0x5d, 0x59, 0x4e, 0x00, // 0x40
	0x7c, 0x12, 0x11, 0x12, 0x7c, 0x00,
	0x7f, 0x49, 0x49, 0x49, 0x36, 0x00,
	0x3e, 0x41, 0x41, 0x41, 0x22, 0x00,
	0x7f, 0x41, 0x41, 0x41, 0x3e, 0x00,
	0x7f, 0x49, 0x49, 0x49, 0x41, 0x00,
	0x7f, 0x09, 0x09, 0x09, 0x01, 0x00,
	0x3e, 0x41, 0x41, 0x51, 0x73, 0x00,
	0x7f, 0x08, 0x08, 0x08, 0x7f, 0x00,
	0x00, 0x41, 0x7f, 0x41, 0x00, 0x00,
	0x20, 0x40, 0x41, 0x3f, 0x01, 0x00,
	0x7f, 0x08, 0x14, 0x22, 0x41, 0x00,
	0x7f, 0x40, 0x40, 0x40, 0x40, 0x00,
	0x7f, 0x02, 0x1c, 0x02, 0x7f, 0x00,
	0x7f, 0x04, 0x08, 0x10, 0x7f, 0x00,
	0x3e, 0x41, 0x41, 0x41, 0x3e, 0x00,
	0x7f, 0x09, 0x09, 0x09, 0x06, 0x00, // 0x50
	0x3e, 0x41, 0x51, 0x21, 0x5e, 0x00,
	0x7f, 0x09, 0x19, 0x29, 0x46, 0x00,
	0x26, 0x49, 0x49, 0x49, 0x32, 0x00,
	0x03, 0x01, 0x7f, 0x01, 0x03, 0x00,
	0x3f, 0x40, 0x40, 0x40, 0x3f, 0x00,
	0x1f, 0x20, 0x40, 0x20, 0x1f, 0x00,
	0x3f, 0x40, 0x38, 0x40, 0x3f, 0x00,
	0x63, 0x14, 0x08, 0x14, 0x63, 0x00,
	0x03, 0x04, 0x78, 0x04, 0x03, 0x00,
	0x61, 0x59, 0x49, 0x4d, 0x43, 0x00,
	0x00, 0x7f, 0x41, 0x41, 0x41, 0x00,
	0x02, 0x04, 0x08, 0x10, 0x20, 0x00,
	0x00, 0x41, 0x41, 0x41, 0x7f, 0x00,
	0x04, 0x02, 0x01, 0x02, 0x04, 0x00,
	0x40, 0x40, 0x40, 0x40, 0x40, 0x00,
	0x00, 0x03, 0x07, 0x08, 0x00, 0x00, // 0x60
	0x20, 0x54, 0x54, 0x78, 0x40, 0x00,
	0x7f, 0x28, 0x44, 0x44, 0x38, 0x00,
	0x38, 0x44, 0x44, 0x44, 0x28, 0x00,
	0x38, 0x44, 0x44, 0x28, 0x7f, 0x00,
	0x38, 0x54, 0x54, 0x54, 0x18, 0x00,
	0x00, 0x08, 0x7e, 0x09, 0x02, 0x00,
	0x18, 0xa4, 0xa4, 0x9c, 0x78, 0x00,
	0x7f, 0x08, 0x04, 0x04, 0x78, 0x00,
	0x00, 0x44, 0x7d, 0x40, 0x00, 0x00,
	0x20, 0x40, 0x40, 0x3d, 0x00, 0x00,
	0x7f, 0x10, 0x28, 0x44, 0x00, 0x00,
	0x00, 0x41, 0x7f, 0x40, 0x00, 0x00,
	0x7c, 0x04, 0x78, 0x04, 0x78, 0x00,
	0x7c, 0x08, 0x04, 0x04, 0x78, 0x00,
	0x38, 0x44, 0x44, 0x44, 0x38, 0x00,
	0xfc, 0x18, 0x24, 0x24, 0x18, 0x00, // 0x70
	0x18, 0x24, 0x24, 0x18, 0xfc, 0x00,
	0x7c, 0x08, 0x04, 0x04, 0x08, 0x00,
	0x48, 0x54, 0x54, 0x54, 0x24, 0x00,
	0x04, 0x04, 0x3f, 0x44, 0x24, 0x00,
	0x3c, 0x40, 0x40, 0x20, 0x7c, 0x00,
	0x1c, 0x20, 0x40, 0x20, 0x1c, 0x00,
	0x3c, 0x40, 0x30, 0x40, 0x3c, 0x00,
	0x44, 0x28, 0x10, 0x28, 0x44, 0x00,
	0x4c, 0x90, 0x90, 0x90, 0x7c, 0x00,
	0x44, 0x64, 0x54, 0x4c, 0x44, 0x00,
	0x00, 0x08, 0x36, 0x41, 0x00, 0x00,
	0x00, 0x00, 0x77, 0x00, 0x00, 0x00,
	0x00, 0x41, 0x36, 0x08, 0x00, 0x00,
	0x02, 0x01, 0x02, 0x04, 0x02, 0x00,
	0x3c, 0x26, 0x23, 0x26, 0x3c, 0x00,
	/****
		0x1e, 0xa1, 0xa1, 0x61, 0x12, 0x00, // 0x80
		0x3a, 0x40, 0x40, 0x20, 0x7a, 0x00,
		0x38, 0x54, 0x54, 0x55, 0x59, 0x00,
		0x21, 0x55, 0x55, 0x79, 0x41, 0x00,
		0x21, 0x54, 0x54, 0x78, 0x41, 0x00,
		0x21, 0x55, 0x54, 0x78, 0x40, 0x00,
		0x20, 0x54, 0x55, 0x79, 0x40, 0x00,
		0x0c, 0x1e, 0x52, 0x72, 0x12, 0x00,
		0x39, 0x55, 0x55, 0x55, 0x59, 0x00,
		0x39, 0x54, 0x54, 0x54, 0x59, 0x00,
		0x39, 0x55, 0x54, 0x54, 0x58, 0x00,
		0x00, 0x00, 0x45, 0x7c, 0x41, 0x00,
		0x00, 0x02, 0x45, 0x7d, 0x42, 0x00,
		0x00, 0x01, 0x45, 0x7c, 0x40, 0x00,
		0xf0, 0x29, 0x24, 0x29, 0xf0, 0x00,
		0xf0, 0x28, 0x25, 0x28, 0xf0, 0x00,
		0x7c, 0x54, 0x55, 0x45, 0x00, 0x00, // 0x90
		0x20, 0x54, 0x54, 0x7c, 0x54, 0x00,
		0x7c, 0x0a, 0x09, 0x7f, 0x49, 0x00,
		0x32, 0x49, 0x49, 0x49, 0x32, 0x00,
		0x32, 0x48, 0x48, 0x48, 0x32, 0x00,
		0x32, 0x4a, 0x48, 0x48, 0x30, 0x00,
		0x3a, 0x41, 0x41, 0x21, 0x7a, 0x00,
		0x3a, 0x42, 0x40, 0x20, 0x78, 0x00,
		0x00, 0x9d, 0xa0, 0xa0, 0x7d, 0x00,
		0x39, 0x44, 0x44, 0x44, 0x39, 0x00,
		0x3d, 0x40, 0x40, 0x40, 0x3d, 0x00,
		0x3c, 0x24, 0xff, 0x24, 0x24, 0x00,
		0x48, 0x7e, 0x49, 0x43, 0x66, 0x00,
		0x2b, 0x2f, 0xfc, 0x2f, 0x2b, 0x00,
		0xff, 0x09, 0x29, 0xf6, 0x20, 0x00,
		0xc0, 0x88, 0x7e, 0x09, 0x03, 0x00,
		0x20, 0x54, 0x54, 0x79, 0x41, 0x00, // 0xA0
		0x00, 0x00, 0x44, 0x7d, 0x41, 0x00,
		0x30, 0x48, 0x48, 0x4a, 0x32, 0x00,
		0x38, 0x40, 0x40, 0x22, 0x7a, 0x00,
		0x00, 0x7a, 0x0a, 0x0a, 0x72, 0x00,
		0x7d, 0x0d, 0x19, 0x31, 0x7d, 0x00,
		0x26, 0x29, 0x29, 0x2f, 0x28, 0x00,
		0x26, 0x29, 0x29, 0x29, 0x26, 0x00,
		0x30, 0x48, 0x4d, 0x40, 0x20, 0x00,
		0x38, 0x08, 0x08, 0x08, 0x08, 0x00,
		0x08, 0x08, 0x08, 0x08, 0x38, 0x00,
		0x2f, 0x10, 0xc8, 0xac, 0xba, 0x00,
		0x2f, 0x10, 0x28, 0x34, 0xfa, 0x00,
		0x00, 0x00, 0x7b, 0x00, 0x00, 0x00,
		0x08, 0x14, 0x2a, 0x14, 0x22, 0x00,
		0x22, 0x14, 0x2a, 0x14, 0x08, 0x00,
		0xaa, 0x00, 0x55, 0x00, 0xaa, 0x00, // 0xB0
		0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x00,
		0x00, 0x00, 0x00, 0xff, 0x00, 0x00,
		0x10, 0x10, 0x10, 0xff, 0x00, 0x00,
		0x14, 0x14, 0x14, 0xff, 0x00, 0x00,
		0x10, 0x10, 0xff, 0x00, 0xff, 0x00,
		0x10, 0x10, 0xf0, 0x10, 0xf0, 0x00,
		0x14, 0x14, 0x14, 0xfc, 0x00, 0x00,
		0x14, 0x14, 0xf7, 0x00, 0xff, 0x00,
		0x00, 0x00, 0xff, 0x00, 0xff, 0x00,
		0x14, 0x14, 0xf4, 0x04, 0xfc, 0x00,
		0x14, 0x14, 0x17, 0x10, 0x1f, 0x00,
		0x10, 0x10, 0x1f, 0x10, 0x1f, 0x00,
		0x14, 0x14, 0x14, 0x1f, 0x00, 0x00,
		0x10, 0x10, 0x10, 0xf0, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x1f, 0x10, 0x00,
		0x10, 0x10, 0x10, 0x1f, 0x10, 0x00, // 0xC0
		0x10, 0x10, 0x10, 0xf0, 0x10, 0x00,
		0x00, 0x00, 0x00, 0xff, 0x10, 0x00,
		0x10, 0x10, 0x10, 0x10, 0x10, 0x00,
		0x10, 0x10, 0x10, 0xff, 0x10, 0x00,
		0x00, 0x00, 0x00, 0xff, 0x14, 0x00,
		0x00, 0x00, 0xff, 0x00, 0xff, 0x00,
		0x00, 0x00, 0x1f, 0x10, 0x17, 0x00,
		0x00, 0x00, 0xfc, 0x04, 0xf4, 0x00,
		0x14, 0x14, 0x17, 0x10, 0x17, 0x00,
		0x14, 0x14, 0xf4, 0x04, 0xf4, 0x00,
		0x00, 0x00, 0xff, 0x00, 0xf7, 0x00,
		0x14, 0x14, 0x14, 0x14, 0x14, 0x00,
		0x14, 0x14, 0xf7, 0x00, 0xf7, 0x00,
		0x14, 0x14, 0x14, 0x17, 0x14, 0x00,
		0x10, 0x10, 0x1f, 0x10, 0x1f, 0x00,
		0x14, 0x14, 0x14, 0xf4, 0x14, 0x00, // 0xD0
		0x10, 0x10, 0xf0, 0x10, 0xf0, 0x00,
		0x00, 0x00, 0x1f, 0x10, 0x1f, 0x00,
		0x00, 0x00, 0x00, 0x1f, 0x14, 0x00,
		0x00, 0x00, 0x00, 0xfc, 0x14, 0x00,
		0x00, 0x00, 0xf0, 0x10, 0xf0, 0x00,
		0x10, 0x10, 0xff, 0x10, 0xff, 0x00,
		0x14, 0x14, 0x14, 0xff, 0x14, 0x00,
		0x10, 0x10, 0x10, 0x1f, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xf0, 0x10, 0x00,
		0xff, 0xff, 0xff, 0xff, 0xff, 0x00,
		0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0x00,
		0xff, 0xff, 0xff, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xff, 0xff, 0x00,
		0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x00,
		0x38, 0x44, 0x44, 0x38, 0x44, 0x00,
		0x7c, 0x2a, 0x2a, 0x3e, 0x14, 0x00, // 0xE0
		0x7e, 0x02, 0x02, 0x06, 0x06, 0x00,
		0x02, 0x7e, 0x02, 0x7e, 0x02, 0x00,
		0x63, 0x55, 0x49, 0x41, 0x63, 0x00,
		0x38, 0x44, 0x44, 0x3c, 0x04, 0x00,
		0x40, 0x7e, 0x20, 0x1e, 0x20, 0x00,
		0x06, 0x02, 0x7e, 0x02, 0x02, 0x00,
		0x99, 0xa5, 0xe7, 0xa5, 0x99, 0x00,
		0x1c, 0x2a, 0x49, 0x2a, 0x1c, 0x00,
		0x4c, 0x72, 0x01, 0x72, 0x4c, 0x00,
		0x30, 0x4a, 0x4d, 0x4d, 0x30, 0x00,
		0x30, 0x48, 0x78, 0x48, 0x30, 0x00,
		0xbc, 0x62, 0x5a, 0x46, 0x3d, 0x00,
		0x3e, 0x49, 0x49, 0x49, 0x00, 0x00,
		0x7e, 0x01, 0x01, 0x01, 0x7e, 0x00,
		0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 0x00,
		0x44, 0x44, 0x5f, 0x44, 0x44, 0x00, // 0xF0
		0x40, 0x51, 0x4a, 0x44, 0x40, 0x00,
		0x40, 0x44, 0x4a, 0x51, 0x40, 0x00,
		0x00, 0x00, 0xff, 0x01, 0x03, 0x00,
		0xe0, 0x80, 0xff, 0x00, 0x00, 0x00,
		0x08, 0x08, 0x6b, 0x6b, 0x08, 0x00,
		0x36, 0x12, 0x36, 0x24, 0x36, 0x00,
		0x06, 0x0f, 0x09, 0x0f, 0x06, 0x00,

	//////////////////////////////////////////                           _ _ _ _ _ _
	//	0x00, 0x00, 0x18, 0x18, 0x00, 0x00, // original 0xF8 <--------- |_|_|_|_|_|_|  1
	//	                                                                |_|_|_|_|_|_|  2
	//	                                                                |_|_|_|_|_|_|  4
	//	                                                                |_|_|*|*|_|_|  8
	//	                                                                |_|_|*|*|_|_| 10
	//	                                                                |_|_|_|_|_|_| 20
	//	                                                                |_|_|_|_|_|_| 40
	//	                                                                |_|_|_|_|_|_| 80
	//////////////////////////////////////////

	//////////////////////////////////////////                           _ _ _ _ _ _
		0x06, 0x09, 0x09, 0x06, 0x00, 0x00, // new 0xF8 (degree symbol) |_|*|*|_|_|_|  1
	//	                                                                |*|_|_|*|_|_|  2
	//	                                                                |*|_|_|*|_|_|  4
	//	                                                                |_|*|*|_|_|_|  8
	//	                                                                |_|_|_|_|_|_| 10
	//	                                                                |_|_|_|_|_|_| 20
	//	                                                                |_|_|_|_|_|_| 40
	//	                                                                |_|_|_|_|_|_| 80
	//////////////////////////////////////////

		0x00, 0x00, 0x10, 0x10, 0x00, 0x00,
		0x30, 0x40, 0xff, 0x01, 0x01, 0x00,
		0x00, 0x1f, 0x01, 0x01, 0x1e, 0x00,
		0x00, 0x19, 0x1d, 0x17, 0x12, 0x00,
		0x00, 0x3c, 0x3c, 0x3c, 0x3c, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x7f, 0x7f, 0x7f, 0x7f, 0x00, // 0xFF
	****/
};

#endif

