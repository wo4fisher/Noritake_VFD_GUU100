///////////////////////////////////////////////////////////////////////////////
//
//  Font "FREEDOS_16.H" for the Noritake GU128X64E-U100 VFD display
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

#ifndef FREEDOS_16_H
#define FREEDOS_16_H

#define freedos_16 pgm_get_far_address(_freedos_16)

static const uint8_t _freedos_16[] PROGMEM = {

	0x08, // width (base + 0)
	0x10, // height (base + 1)
	0x00, // horizontal gap (base + 2)
	0x00, // vertical gap (base + 3)
	0x20, // first char (base + 4)
	0x10, // bytes per char (base + 5)

	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x70, 0xf8, 0xf8, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1b, 0x1b, 0x00, 0x00, 0x00,
	0x00, 0x0e, 0x1e, 0x00, 0x00, 0x1e, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x40, 0xf0, 0xf0, 0x40, 0xf0, 0xf0, 0x40, 0x00, 0x04, 0x1f, 0x1f, 0x04, 0x1f, 0x1f, 0x04, 0x00,
	0x70, 0xf8, 0x88, 0x8e, 0x8e, 0x98, 0x30, 0x00, 0x0c, 0x18, 0x10, 0x70, 0x70, 0x1f, 0x0f, 0x00,
	0x60, 0x60, 0x00, 0x00, 0x80, 0xc0, 0x60, 0x00, 0x18, 0x0c, 0x06, 0x03, 0x01, 0x18, 0x18, 0x00,
	0x00, 0xb0, 0xf8, 0xc8, 0x78, 0xb0, 0x80, 0x00, 0x0f, 0x1f, 0x10, 0x11, 0x0f, 0x1f, 0x10, 0x00,
	0x00, 0x40, 0x78, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xe0, 0xf0, 0x18, 0x08, 0x00, 0x00, 0x00, 0x00, 0x07, 0x0f, 0x18, 0x10, 0x00, 0x00,
	0x00, 0x00, 0x08, 0x18, 0xf0, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x10, 0x18, 0x0f, 0x07, 0x00, 0x00,
	0x00, 0x40, 0xc0, 0x80, 0x80, 0xc0, 0x40, 0x00, 0x01, 0x05, 0x07, 0x03, 0x03, 0x07, 0x05, 0x01,
	0x00, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x07, 0x07, 0x01, 0x01, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x78, 0x38, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x60, 0x00, 0x18, 0x0c, 0x06, 0x03, 0x01, 0x00, 0x00, 0x00,
	0xe0, 0xf0, 0x18, 0x88, 0x18, 0xf0, 0xe0, 0x00, 0x07, 0x0f, 0x18, 0x11, 0x18, 0x0f, 0x07, 0x00,
	0x00, 0x20, 0x30, 0xf8, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x1f, 0x1f, 0x10, 0x10, 0x00,
	0x10, 0x18, 0x08, 0x88, 0xc8, 0x78, 0x30, 0x00, 0x1c, 0x1e, 0x13, 0x11, 0x10, 0x18, 0x18, 0x00,
	0x10, 0x18, 0x88, 0x88, 0x88, 0xf8, 0x70, 0x00, 0x08, 0x18, 0x10, 0x10, 0x10, 0x1f, 0x0f, 0x00,
	0x80, 0xc0, 0x60, 0x30, 0xf8, 0xf8, 0x00, 0x00, 0x01, 0x01, 0x01, 0x11, 0x1f, 0x1f, 0x11, 0x00,
	0xf8, 0xf8, 0x88, 0x88, 0x88, 0x88, 0x08, 0x00, 0x08, 0x18, 0x10, 0x10, 0x10, 0x1f, 0x0f, 0x00,
	0xe0, 0xf0, 0x98, 0x88, 0x88, 0x80, 0x00, 0x00, 0x0f, 0x1f, 0x10, 0x10, 0x10, 0x1f, 0x0f, 0x00,
	0x18, 0x18, 0x08, 0x08, 0x88, 0xf8, 0x78, 0x00, 0x00, 0x00, 0x1e, 0x1f, 0x01, 0x00, 0x00, 0x00,
	0x70, 0xf8, 0x88, 0x88, 0x88, 0xf8, 0x70, 0x00, 0x0f, 0x1f, 0x10, 0x10, 0x10, 0x1f, 0x0f, 0x00,
	0x70, 0xf8, 0x88, 0x88, 0x88, 0xf8, 0xf0, 0x00, 0x00, 0x10, 0x10, 0x10, 0x18, 0x0f, 0x07, 0x00,
	0x00, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x38, 0x18, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x80, 0xc0, 0x60, 0x30, 0x10, 0x00, 0x00, 0x01, 0x03, 0x06, 0x0c, 0x18, 0x10, 0x00,
	0x00, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x00, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00,
	0x00, 0x10, 0x30, 0x60, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x10, 0x18, 0x0c, 0x06, 0x03, 0x01, 0x00,
	0x30, 0x38, 0x08, 0x88, 0xc8, 0x78, 0x30, 0x00, 0x00, 0x00, 0x00, 0x1b, 0x1b, 0x00, 0x00, 0x00,
	0xe0, 0xf0, 0x10, 0x90, 0x90, 0xf0, 0xe0, 0x00, 0x0f, 0x1f, 0x10, 0x17, 0x17, 0x17, 0x03, 0x00,
	0xc0, 0xe0, 0x30, 0x18, 0x30, 0xe0, 0xc0, 0x00, 0x1f, 0x1f, 0x01, 0x01, 0x01, 0x1f, 0x1f, 0x00,
	0x08, 0xf8, 0xf8, 0x88, 0x88, 0xf8, 0x70, 0x00, 0x10, 0x1f, 0x1f, 0x10, 0x10, 0x1f, 0x0f, 0x00,
	0xe0, 0xf0, 0x18, 0x08, 0x08, 0x18, 0x30, 0x00, 0x07, 0x0f, 0x18, 0x10, 0x10, 0x18, 0x0c, 0x00,
	0x08, 0xf8, 0xf8, 0x08, 0x18, 0xf0, 0xe0, 0x00, 0x10, 0x1f, 0x1f, 0x10, 0x18, 0x0f, 0x07, 0x00,
	0x08, 0xf8, 0xf8, 0x88, 0xc8, 0x18, 0x38, 0x00, 0x10, 0x1f, 0x1f, 0x10, 0x11, 0x18, 0x1c, 0x00,
	0x08, 0xf8, 0xf8, 0x88, 0xc8, 0x18, 0x38, 0x00, 0x10, 0x1f, 0x1f, 0x10, 0x01, 0x00, 0x00, 0x00,
	0xe0, 0xf0, 0x18, 0x08, 0x08, 0x18, 0x30, 0x00, 0x07, 0x0f, 0x18, 0x11, 0x11, 0x0f, 0x1f, 0x00,
	0xf8, 0xf8, 0x80, 0x80, 0x80, 0xf8, 0xf8, 0x00, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x00,
	0x00, 0x00, 0x08, 0xf8, 0xf8, 0x08, 0x00, 0x00, 0x00, 0x00, 0x10, 0x1f, 0x1f, 0x10, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x08, 0xf8, 0xf8, 0x08, 0x00, 0x0e, 0x1e, 0x10, 0x10, 0x1f, 0x0f, 0x00, 0x00,
	0x08, 0xf8, 0xf8, 0x80, 0xc0, 0x78, 0x38, 0x00, 0x10, 0x1f, 0x1f, 0x01, 0x03, 0x1e, 0x1c, 0x00,
	0x08, 0xf8, 0xf8, 0x08, 0x00, 0x00, 0x00, 0x00, 0x10, 0x1f, 0x1f, 0x10, 0x10, 0x18, 0x1c, 0x00,
	0xf8, 0xf8, 0x70, 0xe0, 0x70, 0xf8, 0xf8, 0x00, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x00,
	0xf8, 0xf8, 0x70, 0xe0, 0xc0, 0xf8, 0xf8, 0x00, 0x1f, 0x1f, 0x00, 0x00, 0x01, 0x1f, 0x1f, 0x00,
	0xf0, 0xf8, 0x08, 0x08, 0x08, 0xf8, 0xf0, 0x00, 0x0f, 0x1f, 0x10, 0x10, 0x10, 0x1f, 0x0f, 0x00,
	0x08, 0xf8, 0xf8, 0x88, 0x88, 0xf8, 0x70, 0x00, 0x10, 0x1f, 0x1f, 0x10, 0x00, 0x00, 0x00, 0x00,
	0xf0, 0xf8, 0x08, 0x08, 0x08, 0xf8, 0xf0, 0x00, 0x0f, 0x1f, 0x10, 0x1c, 0x78, 0x7f, 0x4f, 0x00,
	0x08, 0xf8, 0xf8, 0x88, 0x88, 0xf8, 0x70, 0x00, 0x10, 0x1f, 0x1f, 0x00, 0x01, 0x1f, 0x1e, 0x00,
	0x30, 0x78, 0xc8, 0x88, 0x88, 0x38, 0x30, 0x00, 0x0c, 0x1c, 0x10, 0x10, 0x11, 0x1f, 0x0e, 0x00,
	0x00, 0x38, 0x18, 0xf8, 0xf8, 0x18, 0x38, 0x00, 0x00, 0x00, 0x10, 0x1f, 0x1f, 0x10, 0x00, 0x00,
	0xf8, 0xf8, 0x00, 0x00, 0x00, 0xf8, 0xf8, 0x00, 0x0f, 0x1f, 0x10, 0x10, 0x10, 0x1f, 0x0f, 0x00,
	0xf8, 0xf8, 0x00, 0x00, 0x00, 0xf8, 0xf8, 0x00, 0x03, 0x07, 0x0c, 0x18, 0x0c, 0x07, 0x03, 0x00,
	0xf8, 0xf8, 0x00, 0x80, 0x00, 0xf8, 0xf8, 0x00, 0x0f, 0x1f, 0x1c, 0x07, 0x1c, 0x1f, 0x0f, 0x00,
	0x18, 0x78, 0xe0, 0xc0, 0xe0, 0x78, 0x18, 0x00, 0x18, 0x1e, 0x07, 0x03, 0x07, 0x1e, 0x18, 0x00,
	0x00, 0x78, 0xf8, 0x80, 0x80, 0xf8, 0x78, 0x00, 0x00, 0x00, 0x10, 0x1f, 0x1f, 0x10, 0x00, 0x00,
	0x38, 0x18, 0x08, 0x88, 0xc8, 0x78, 0x38, 0x00, 0x1c, 0x1e, 0x13, 0x11, 0x10, 0x18, 0x1c, 0x00,
	0x00, 0x00, 0xf8, 0xf8, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x10, 0x10, 0x00, 0x00,
	0x70, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0e, 0x1c, 0x00,
	0x00, 0x00, 0x08, 0x08, 0xf8, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x1f, 0x1f, 0x00, 0x00,
	0x00, 0x02, 0x03, 0x01, 0x03, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
	0x00, 0x00, 0x01, 0x03, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x40, 0x40, 0x40, 0xc0, 0x80, 0x00, 0x00, 0x0e, 0x1f, 0x11, 0x11, 0x0f, 0x1f, 0x10, 0x00,
	0x08, 0xf8, 0xf8, 0x40, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x10, 0x10, 0x1f, 0x0f, 0x00,
	0x80, 0xc0, 0x40, 0x40, 0x40, 0xc0, 0x80, 0x00, 0x0f, 0x1f, 0x10, 0x10, 0x10, 0x18, 0x08, 0x00,
	0x00, 0x80, 0xc0, 0x48, 0xf8, 0xf8, 0x00, 0x00, 0x0f, 0x1f, 0x10, 0x10, 0x0f, 0x1f, 0x10, 0x00,
	0x80, 0xc0, 0x40, 0x40, 0x40, 0xc0, 0x80, 0x00, 0x0f, 0x1f, 0x11, 0x11, 0x11, 0x19, 0x09, 0x00,
	0x00, 0x80, 0xf0, 0xf8, 0x88, 0x18, 0x30, 0x00, 0x00, 0x10, 0x1f, 0x1f, 0x10, 0x00, 0x00, 0x00,
	0x80, 0xc0, 0x40, 0x40, 0x80, 0xc0, 0x40, 0x00, 0x4f, 0xdf, 0x90, 0x90, 0xff, 0x7f, 0x00, 0x00,
	0x08, 0xf8, 0xf8, 0x80, 0x40, 0xc0, 0x80, 0x00, 0x10, 0x1f, 0x1f, 0x00, 0x00, 0x1f, 0x1f, 0x00,
	0x00, 0x00, 0x40, 0xd8, 0xd8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x1f, 0x1f, 0x10, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x40, 0xd8, 0xd8, 0x00, 0x00, 0x60, 0xe0, 0x80, 0x80, 0xff, 0x7f, 0x00,
	0x08, 0xf8, 0xf8, 0x00, 0x80, 0xc0, 0x40, 0x00, 0x10, 0x1f, 0x1f, 0x03, 0x07, 0x1c, 0x18, 0x00,
	0x00, 0x00, 0x08, 0xf8, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x1f, 0x1f, 0x10, 0x00, 0x00,
	0xc0, 0xc0, 0xc0, 0x80, 0xc0, 0xc0, 0x80, 0x00, 0x1f, 0x1f, 0x00, 0x0f, 0x00, 0x1f, 0x1f, 0x00,
	0x40, 0xc0, 0x80, 0x40, 0x40, 0xc0, 0x80, 0x00, 0x00, 0x1f, 0x1f, 0x00, 0x00, 0x1f, 0x1f, 0x00,
	0x80, 0xc0, 0x40, 0x40, 0x40, 0xc0, 0x80, 0x00, 0x0f, 0x1f, 0x10, 0x10, 0x10, 0x1f, 0x0f, 0x00,
	0x40, 0xc0, 0x80, 0x40, 0x40, 0xc0, 0x80, 0x00, 0x80, 0xff, 0xff, 0x90, 0x10, 0x1f, 0x0f, 0x00,
	0x80, 0xc0, 0x40, 0x40, 0x80, 0xc0, 0x40, 0x00, 0x0f, 0x1f, 0x10, 0x90, 0xff, 0xff, 0x80, 0x00,
	0x40, 0xc0, 0x80, 0xc0, 0x40, 0xc0, 0x80, 0x00, 0x10, 0x1f, 0x1f, 0x10, 0x00, 0x01, 0x01, 0x00,
	0x80, 0xc0, 0x40, 0x40, 0x40, 0xc0, 0x80, 0x00, 0x08, 0x19, 0x13, 0x12, 0x16, 0x1c, 0x08, 0x00,
	0x40, 0x40, 0xf0, 0xf8, 0x40, 0x40, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x1f, 0x10, 0x18, 0x08, 0x00,
	0xc0, 0xc0, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00, 0x0f, 0x1f, 0x10, 0x10, 0x0f, 0x1f, 0x10, 0x00,
	0xc0, 0xc0, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x07, 0x0f, 0x18, 0x10, 0x18, 0x0f, 0x07, 0x00,
	0xc0, 0xc0, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x0f, 0x1f, 0x18, 0x0f, 0x18, 0x1f, 0x0f, 0x00,
	0x40, 0xc0, 0x80, 0x00, 0x80, 0xc0, 0x40, 0x00, 0x10, 0x18, 0x0f, 0x07, 0x0f, 0x18, 0x10, 0x00,
	0xc0, 0xc0, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x8f, 0x9f, 0x90, 0x90, 0xd0, 0x7f, 0x3f, 0x00,
	0xc0, 0xc0, 0x40, 0x40, 0xc0, 0xc0, 0x40, 0x00, 0x18, 0x1c, 0x16, 0x13, 0x11, 0x18, 0x18, 0x00,
	0x00, 0x80, 0x80, 0xf0, 0x78, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x1f, 0x10, 0x10, 0x00,
	0x00, 0x00, 0x00, 0xf8, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x00, 0x00, 0x00,
	0x00, 0x08, 0x08, 0x78, 0xf0, 0x80, 0x80, 0x00, 0x00, 0x10, 0x10, 0x1f, 0x0f, 0x00, 0x00, 0x00,
	0x02, 0x03, 0x01, 0x03, 0x02, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xd8, 0xd8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x1f, 0x1f, 0x0e, 0x00, 0x00,
	0xc0, 0xe0, 0x20, 0x38, 0x38, 0x60, 0x40, 0x00, 0x03, 0x07, 0x04, 0x1c, 0x1c, 0x06, 0x02, 0x00,
	0x80, 0xf0, 0xf8, 0x88, 0x18, 0x30, 0x00, 0x00, 0x10, 0x1f, 0x1f, 0x10, 0x10, 0x18, 0x08, 0x00,
	0xa0, 0xe0, 0x40, 0x40, 0x40, 0xe0, 0xa0, 0x00, 0x17, 0x1f, 0x08, 0x08, 0x08, 0x1f, 0x17, 0x00,
	0x00, 0x98, 0xb8, 0xe0, 0xe0, 0xb8, 0x98, 0x00, 0x00, 0x02, 0x02, 0x1f, 0x1f, 0x02, 0x02, 0x00,
	0x00, 0x00, 0x00, 0x3e, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x00, 0x00, 0x00,
	0xc4, 0xee, 0x3a, 0x12, 0x32, 0xe6, 0xc4, 0x00, 0x08, 0x19, 0x13, 0x12, 0x17, 0x1d, 0x08, 0x00,
	0x02, 0x02, 0x00, 0x00, 0x00, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0xf0, 0x08, 0xc8, 0x28, 0x28, 0x08, 0xf0, 0x00, 0x0f, 0x10, 0x13, 0x14, 0x14, 0x10, 0x0f, 0x00,
	0x00, 0x30, 0x78, 0x48, 0x38, 0x78, 0x40, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x0e, 0x1b, 0x15, 0x0e, 0x1b, 0x11, 0x00,
	0x40, 0x40, 0x40, 0x40, 0x40, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00,
	0xf0, 0x08, 0xe8, 0x28, 0xc8, 0x08, 0xf0, 0x00, 0x0f, 0x10, 0x17, 0x11, 0x16, 0x10, 0x0f, 0x00,
	0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x30, 0x78, 0x48, 0x78, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x40, 0x40, 0xf0, 0xf0, 0x40, 0x40, 0x00, 0x00, 0x08, 0x08, 0x09, 0x09, 0x08, 0x08, 0x00,
	0x00, 0x10, 0x98, 0xc8, 0x68, 0x38, 0x90, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00,
	0x00, 0x08, 0x28, 0x28, 0x28, 0xf8, 0xd0, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x02, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xc0, 0xc0, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x80, 0xff, 0x7f, 0x10, 0x10, 0x1f, 0x0f, 0x00,
	0x70, 0xf8, 0x88, 0xf8, 0xf8, 0x08, 0xf8, 0xf8, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x00, 0x1f, 0x1f,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xa0, 0xe0, 0x40, 0x00, 0x00,
	0x00, 0x00, 0x10, 0xf8, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00,
	0x00, 0x30, 0x78, 0x48, 0x78, 0x30, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x1b, 0x0e, 0x15, 0x1b, 0x0e, 0x04, 0x00,
	0x04, 0x3e, 0xbe, 0xc0, 0x60, 0x30, 0x18, 0x00, 0x06, 0x03, 0x09, 0x0c, 0x0e, 0x3b, 0x3f, 0x08,
	0x04, 0x3e, 0xbe, 0xc0, 0x60, 0x30, 0x18, 0x00, 0x06, 0x03, 0x21, 0x32, 0x3a, 0x2e, 0x24, 0x00,
	0x22, 0x2a, 0xbe, 0xd4, 0x60, 0x30, 0x18, 0x00, 0x06, 0x03, 0x09, 0x0c, 0x0e, 0x3b, 0x3f, 0x08,
	0x00, 0x00, 0xd8, 0xd8, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x1f, 0x11, 0x10, 0x10, 0x1c, 0x0c, 0x00,
	0xc0, 0xe1, 0x33, 0x1a, 0x30, 0xe0, 0xc0, 0x00, 0x1f, 0x1f, 0x01, 0x01, 0x01, 0x1f, 0x1f, 0x00,
	0xc0, 0xe0, 0x30, 0x1a, 0x33, 0xe1, 0xc0, 0x00, 0x1f, 0x1f, 0x01, 0x01, 0x01, 0x1f, 0x1f, 0x00,
	0xc0, 0xe2, 0x33, 0x19, 0x33, 0xe2, 0xc0, 0x00, 0x1f, 0x1f, 0x01, 0x01, 0x01, 0x1f, 0x1f, 0x00,
	0xc2, 0xe3, 0x31, 0x1b, 0x32, 0xe3, 0xc1, 0x00, 0x1f, 0x1f, 0x01, 0x01, 0x01, 0x1f, 0x1f, 0x00,
	0xc2, 0xe2, 0x30, 0x18, 0x30, 0xe2, 0xc2, 0x00, 0x1f, 0x1f, 0x01, 0x01, 0x01, 0x1f, 0x1f, 0x00,
	0xc0, 0xe2, 0x37, 0x1d, 0x37, 0xe2, 0xc0, 0x00, 0x1f, 0x1f, 0x01, 0x01, 0x01, 0x1f, 0x1f, 0x00,
	0xe0, 0xf0, 0x98, 0x88, 0xf8, 0xf8, 0x88, 0x00, 0x1f, 0x1f, 0x00, 0x00, 0x1f, 0x1f, 0x10, 0x00,
	0xe0, 0xf0, 0x18, 0x08, 0x08, 0x18, 0x30, 0x00, 0x07, 0x8f, 0x98, 0xb0, 0xf0, 0x58, 0x0c, 0x00,
	0x08, 0xf8, 0xf9, 0x8b, 0xca, 0x18, 0x38, 0x00, 0x10, 0x1f, 0x1f, 0x10, 0x11, 0x18, 0x1c, 0x00,
	0x08, 0xf8, 0xf8, 0x8a, 0xcb, 0x19, 0x38, 0x00, 0x10, 0x1f, 0x1f, 0x10, 0x11, 0x18, 0x1c, 0x00,
	0x08, 0xfa, 0xfb, 0x89, 0xcb, 0x1a, 0x38, 0x00, 0x10, 0x1f, 0x1f, 0x10, 0x11, 0x18, 0x1c, 0x00,
	0x0a, 0xfa, 0xf8, 0x88, 0xc8, 0x1a, 0x3a, 0x00, 0x10, 0x1f, 0x1f, 0x10, 0x11, 0x18, 0x1c, 0x00,
	0x00, 0x00, 0x09, 0xfb, 0xfa, 0x08, 0x00, 0x00, 0x00, 0x00, 0x10, 0x1f, 0x1f, 0x10, 0x00, 0x00,
	0x00, 0x00, 0x08, 0xfa, 0xfb, 0x09, 0x00, 0x00, 0x00, 0x00, 0x10, 0x1f, 0x1f, 0x10, 0x00, 0x00,
	0x00, 0x02, 0x0b, 0xf9, 0xf9, 0x0b, 0x02, 0x00, 0x00, 0x00, 0x10, 0x1f, 0x1f, 0x10, 0x00, 0x00,
	0x00, 0x02, 0x0a, 0xf8, 0xf8, 0x0a, 0x02, 0x00, 0x00, 0x00, 0x10, 0x1f, 0x1f, 0x10, 0x00, 0x00,
	0x88, 0xf8, 0xf8, 0x88, 0x18, 0xf0, 0xe0, 0x00, 0x10, 0x1f, 0x1f, 0x10, 0x18, 0x0f, 0x07, 0x00,
	0xfa, 0xfb, 0x71, 0xe3, 0xc2, 0xfb, 0xf9, 0x00, 0x1f, 0x1f, 0x00, 0x00, 0x01, 0x1f, 0x1f, 0x00,
	0xf0, 0xf8, 0x09, 0x0b, 0x0a, 0xf8, 0xf0, 0x00, 0x0f, 0x1f, 0x10, 0x10, 0x10, 0x1f, 0x0f, 0x00,
	0xf0, 0xf8, 0x08, 0x0a, 0x0b, 0xf9, 0xf0, 0x00, 0x0f, 0x1f, 0x10, 0x10, 0x10, 0x1f, 0x0f, 0x00,
	0xf0, 0xfa, 0x0b, 0x09, 0x0b, 0xfa, 0xf0, 0x00, 0x0f, 0x1f, 0x10, 0x10, 0x10, 0x1f, 0x0f, 0x00,
	0xf2, 0xfb, 0x09, 0x0b, 0x0a, 0xfb, 0xf1, 0x00, 0x0f, 0x1f, 0x10, 0x10, 0x10, 0x1f, 0x0f, 0x00,
	0xf2, 0xfa, 0x08, 0x08, 0x08, 0xfa, 0xf2, 0x00, 0x0f, 0x1f, 0x10, 0x10, 0x10, 0x1f, 0x0f, 0x00,
	0x20, 0x60, 0xc0, 0x80, 0xc0, 0x60, 0x20, 0x00, 0x04, 0x06, 0x03, 0x01, 0x03, 0x06, 0x04, 0x00,
	0xf0, 0xf8, 0x08, 0xc8, 0x38, 0xfc, 0xf0, 0x00, 0x0f, 0x3f, 0x1c, 0x13, 0x10, 0x1f, 0x0f, 0x00,
	0xf8, 0xf8, 0x01, 0x03, 0x02, 0xf8, 0xf8, 0x00, 0x0f, 0x1f, 0x10, 0x10, 0x10, 0x1f, 0x0f, 0x00,
	0xf8, 0xf8, 0x00, 0x02, 0x03, 0xf9, 0xf8, 0x00, 0x0f, 0x1f, 0x10, 0x10, 0x10, 0x1f, 0x0f, 0x00,
	0xf8, 0xfa, 0x03, 0x01, 0x03, 0xfa, 0xf8, 0x00, 0x0f, 0x1f, 0x10, 0x10, 0x10, 0x1f, 0x0f, 0x00,
	0xfa, 0xfa, 0x00, 0x00, 0x00, 0xfa, 0xfa, 0x00, 0x0f, 0x1f, 0x10, 0x10, 0x10, 0x1f, 0x0f, 0x00,
	0x00, 0x78, 0xf8, 0x82, 0x83, 0xf9, 0x78, 0x00, 0x00, 0x00, 0x10, 0x1f, 0x1f, 0x10, 0x00, 0x00,
	0x08, 0xf8, 0xf8, 0x28, 0x20, 0xe0, 0xc0, 0x00, 0x10, 0x1f, 0x1f, 0x14, 0x04, 0x07, 0x03, 0x00,
	0xf0, 0xf8, 0x08, 0x88, 0xf8, 0x70, 0x00, 0x00, 0x1f, 0x1f, 0x00, 0x00, 0x11, 0x1f, 0x0e, 0x00,
	0x04, 0x4c, 0x58, 0x50, 0xc0, 0x80, 0x00, 0x00, 0x0e, 0x1f, 0x11, 0x11, 0x0f, 0x1f, 0x10, 0x00,
	0x00, 0x40, 0x50, 0x58, 0xcc, 0x84, 0x00, 0x00, 0x0e, 0x1f, 0x11, 0x11, 0x0f, 0x1f, 0x10, 0x00,
	0x00, 0x50, 0x58, 0x4c, 0xd8, 0x90, 0x00, 0x00, 0x0e, 0x1f, 0x11, 0x11, 0x0f, 0x1f, 0x10, 0x00,
	0x10, 0x58, 0x48, 0x58, 0xd0, 0x98, 0x08, 0x00, 0x0e, 0x1f, 0x11, 0x11, 0x0f, 0x1f, 0x10, 0x00,
	0x10, 0x50, 0x40, 0x40, 0xd0, 0x90, 0x00, 0x00, 0x0e, 0x1f, 0x11, 0x11, 0x0f, 0x1f, 0x10, 0x00,
	0x00, 0x48, 0x5c, 0x54, 0xdc, 0x88, 0x00, 0x00, 0x0e, 0x1f, 0x11, 0x11, 0x0f, 0x1f, 0x10, 0x00,
	0x40, 0x40, 0xc0, 0x80, 0x40, 0xc0, 0x80, 0x00, 0x0c, 0x1e, 0x13, 0x0f, 0x1e, 0x13, 0x13, 0x00,
	0x80, 0xc0, 0x40, 0x40, 0x40, 0xc0, 0x80, 0x00, 0x0f, 0x9f, 0x90, 0xb0, 0xf0, 0x58, 0x08, 0x00,
	0x80, 0xc4, 0x4c, 0x58, 0x50, 0xc0, 0x80, 0x00, 0x0f, 0x1f, 0x11, 0x11, 0x11, 0x19, 0x09, 0x00,
	0x80, 0xc0, 0x40, 0x50, 0x58, 0xcc, 0x84, 0x00, 0x0f, 0x1f, 0x11, 0x11, 0x11, 0x19, 0x09, 0x00,
	0x80, 0xd0, 0x58, 0x4c, 0x58, 0xd0, 0x80, 0x00, 0x0f, 0x1f, 0x11, 0x11, 0x11, 0x19, 0x09, 0x00,
	0x90, 0xd0, 0x40, 0x40, 0x40, 0xd0, 0x90, 0x00, 0x0f, 0x1f, 0x11, 0x11, 0x11, 0x19, 0x09, 0x00,
	0x00, 0x04, 0x4c, 0xd8, 0xd0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x1f, 0x1f, 0x10, 0x00, 0x00,
	0x00, 0x00, 0x40, 0xd0, 0xd8, 0x0c, 0x04, 0x00, 0x00, 0x00, 0x10, 0x1f, 0x1f, 0x10, 0x00, 0x00,
	0x00, 0x10, 0x58, 0xcc, 0xcc, 0x18, 0x10, 0x00, 0x00, 0x00, 0x10, 0x1f, 0x1f, 0x10, 0x00, 0x00,
	0x00, 0x10, 0x50, 0xc0, 0xc0, 0x10, 0x10, 0x00, 0x00, 0x00, 0x10, 0x1f, 0x1f, 0x10, 0x00, 0x00,
	0x00, 0x00, 0xa8, 0x98, 0xb0, 0xe8, 0xc0, 0x00, 0x00, 0x0f, 0x1f, 0x10, 0x10, 0x1f, 0x0f, 0x00,
	0x50, 0xd8, 0x88, 0x58, 0x50, 0xd8, 0x88, 0x00, 0x00, 0x1f, 0x1f, 0x00, 0x00, 0x1f, 0x1f, 0x00,
	0x80, 0xc4, 0x4c, 0x58, 0x50, 0xc0, 0x80, 0x00, 0x0f, 0x1f, 0x10, 0x10, 0x10, 0x1f, 0x0f, 0x00,
	0x80, 0xc0, 0x40, 0x50, 0x58, 0xcc, 0x84, 0x00, 0x0f, 0x1f, 0x10, 0x10, 0x10, 0x1f, 0x0f, 0x00,
	0x80, 0xd0, 0x58, 0x4c, 0x58, 0xd0, 0x80, 0x00, 0x0f, 0x1f, 0x10, 0x10, 0x10, 0x1f, 0x0f, 0x00,
	0x90, 0xd8, 0x48, 0x58, 0x50, 0xd8, 0x88, 0x00, 0x0f, 0x1f, 0x10, 0x10, 0x10, 0x1f, 0x0f, 0x00,
	0x90, 0xd0, 0x40, 0x40, 0x40, 0xd0, 0x90, 0x00, 0x0f, 0x1f, 0x10, 0x10, 0x10, 0x1f, 0x0f, 0x00,
	0x00, 0x80, 0x80, 0xa0, 0xa0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x00, 0x00, 0x00,
	0x80, 0xc0, 0x40, 0x40, 0xc0, 0xe0, 0x80, 0x00, 0x0f, 0x3f, 0x18, 0x17, 0x10, 0x1f, 0x0f, 0x00,
	0xc4, 0xcc, 0x18, 0x10, 0xc0, 0xc0, 0x00, 0x00, 0x0f, 0x1f, 0x10, 0x10, 0x0f, 0x1f, 0x10, 0x00,
	0xc0, 0xc0, 0x10, 0x18, 0xcc, 0xc4, 0x00, 0x00, 0x0f, 0x1f, 0x10, 0x10, 0x0f, 0x1f, 0x10, 0x00,
	0xd0, 0xd8, 0x0c, 0x0c, 0xd8, 0xd0, 0x00, 0x00, 0x0f, 0x1f, 0x10, 0x10, 0x0f, 0x1f, 0x10, 0x00,
	0xd0, 0xd0, 0x00, 0x00, 0xd0, 0xd0, 0x00, 0x00, 0x0f, 0x1f, 0x10, 0x10, 0x0f, 0x1f, 0x10, 0x00,
	0xc0, 0xc0, 0x00, 0x10, 0x18, 0xcc, 0xc4, 0x00, 0x8f, 0x9f, 0x90, 0x90, 0xd0, 0x7f, 0x3f, 0x00,
	0x08, 0xf8, 0xf8, 0x40, 0x40, 0xc0, 0x80, 0x00, 0x80, 0xff, 0xff, 0x90, 0x10, 0x1f, 0x0f, 0x00,
	0xd0, 0xd0, 0x00, 0x00, 0x00, 0xd0, 0xd0, 0x00, 0x8f, 0x9f, 0x90, 0x90, 0xd0, 0x7f, 0x3f, 0x00,
	0xc2, 0xe2, 0x32, 0x1a, 0x32, 0xe2, 0xc2, 0x00, 0x1f, 0x1f, 0x01, 0x01, 0x01, 0x1f, 0x1f, 0x00,
	0x10, 0x50, 0x50, 0x50, 0xd0, 0x90, 0x10, 0x00, 0x0e, 0x1f, 0x11, 0x11, 0x0f, 0x1f, 0x10, 0x00,
	0xc1, 0xe3, 0x32, 0x1a, 0x32, 0xe3, 0xc1, 0x00, 0x1f, 0x1f, 0x01, 0x01, 0x01, 0x1f, 0x1f, 0x00,
	0x08, 0x58, 0x50, 0x50, 0xd0, 0x98, 0x08, 0x00, 0x0e, 0x1f, 0x11, 0x11, 0x0f, 0x1f, 0x10, 0x00,
	0xc0, 0xe0, 0x30, 0x18, 0x30, 0xe0, 0xc0, 0x00, 0x1f, 0x1f, 0x41, 0xe1, 0xa1, 0x9f, 0x9f, 0x00,
	0x00, 0x40, 0x40, 0x40, 0xc0, 0x80, 0x00, 0x00, 0x0e, 0x1f, 0x51, 0xf1, 0xaf, 0x9f, 0x90, 0x00,
	0xe0, 0xf0, 0x18, 0x0a, 0x0b, 0x19, 0x30, 0x00, 0x07, 0x0f, 0x18, 0x10, 0x10, 0x18, 0x0c, 0x00,
	0x80, 0xc0, 0x40, 0x50, 0x58, 0xcc, 0x84, 0x00, 0x0f, 0x1f, 0x10, 0x10, 0x10, 0x18, 0x08, 0x00,
	0xe0, 0xf2, 0x1b, 0x09, 0x09, 0x1b, 0x32, 0x00, 0x07, 0x0f, 0x18, 0x10, 0x10, 0x18, 0x0c, 0x00,
	0x80, 0xd0, 0x58, 0x4c, 0x58, 0xd0, 0x80, 0x00, 0x0f, 0x1f, 0x10, 0x10, 0x10, 0x18, 0x08, 0x00,
	0xe0, 0xf0, 0x18, 0x0b, 0x0b, 0x18, 0x30, 0x00, 0x07, 0x0f, 0x18, 0x10, 0x10, 0x18, 0x0c, 0x00,
	0x80, 0xc0, 0x40, 0x58, 0x58, 0xc0, 0x80, 0x00, 0x0f, 0x1f, 0x10, 0x10, 0x10, 0x18, 0x08, 0x00,
	0xe0, 0xf0, 0x19, 0x0b, 0x0a, 0x1b, 0x31, 0x00, 0x07, 0x0f, 0x18, 0x10, 0x10, 0x18, 0x0c, 0x00,
	0x80, 0xc4, 0x4c, 0x58, 0x4c, 0xc4, 0x80, 0x00, 0x0f, 0x1f, 0x10, 0x10, 0x10, 0x18, 0x08, 0x00,
	0x08, 0xf9, 0xfb, 0x0a, 0x1b, 0xf1, 0xe0, 0x00, 0x10, 0x1f, 0x1f, 0x10, 0x18, 0x0f, 0x07, 0x00,
	0x80, 0xc0, 0x48, 0xf8, 0xf8, 0x00, 0x28, 0x18, 0x0f, 0x1f, 0x10, 0x0f, 0x1f, 0x10, 0x00, 0x00,
	0x88, 0xf8, 0xf8, 0x88, 0x18, 0xf0, 0xe0, 0x00, 0x10, 0x1f, 0x1f, 0x10, 0x18, 0x0f, 0x07, 0x00,
	0x00, 0x90, 0xd0, 0x50, 0xf8, 0xf8, 0x10, 0x00, 0x0f, 0x1f, 0x10, 0x10, 0x0f, 0x1f, 0x10, 0x00,
	0x0a, 0xfa, 0xfa, 0x8a, 0xca, 0x1a, 0x3a, 0x00, 0x10, 0x1f, 0x1f, 0x10, 0x11, 0x18, 0x1c, 0x00,
	0x90, 0xd0, 0x50, 0x50, 0x50, 0xd0, 0x90, 0x00, 0x0f, 0x1f, 0x11, 0x11, 0x11, 0x19, 0x09, 0x00,
	0x09, 0xfb, 0xfa, 0x8a, 0xca, 0x1b, 0x39, 0x00, 0x10, 0x1f, 0x1f, 0x10, 0x11, 0x18, 0x1c, 0x00,
	0x88, 0xd8, 0x50, 0x50, 0x50, 0xd8, 0x88, 0x00, 0x0f, 0x1f, 0x11, 0x11, 0x11, 0x19, 0x09, 0x00,
	0x08, 0xf8, 0xf8, 0x8b, 0xcb, 0x18, 0x38, 0x00, 0x10, 0x1f, 0x1f, 0x10, 0x11, 0x18, 0x1c, 0x00,
	0x80, 0xc0, 0x40, 0x58, 0x58, 0xc0, 0x80, 0x00, 0x0f, 0x1f, 0x11, 0x11, 0x11, 0x19, 0x09, 0x00,
	0x08, 0xf8, 0xf8, 0x88, 0xc8, 0x18, 0x38, 0x00, 0x10, 0x1f, 0x5f, 0xf0, 0xb1, 0x98, 0x9c, 0x00,
	0x80, 0xc0, 0x40, 0x40, 0x40, 0xc0, 0x80, 0x00, 0x0f, 0x1f, 0x51, 0xf1, 0xb1, 0x99, 0x89, 0x00,
	0x08, 0xf9, 0xfb, 0x8a, 0xcb, 0x19, 0x38, 0x00, 0x10, 0x1f, 0x1f, 0x10, 0x11, 0x18, 0x1c, 0x00,
	0x80, 0xc4, 0x4c, 0x58, 0x4c, 0xc4, 0x80, 0x00, 0x0f, 0x1f, 0x11, 0x11, 0x11, 0x19, 0x09, 0x00,
	0xe0, 0xf2, 0x1b, 0x09, 0x09, 0x1b, 0x32, 0x00, 0x07, 0x0f, 0x18, 0x11, 0x11, 0x0f, 0x1f, 0x00,
	0x80, 0xd0, 0x58, 0x4c, 0x98, 0xd0, 0x40, 0x00, 0x4f, 0xdf, 0x90, 0x90, 0xff, 0x7f, 0x00, 0x00,
	0xe1, 0xf3, 0x1a, 0x0a, 0x0a, 0x1b, 0x31, 0x00, 0x07, 0x0f, 0x18, 0x11, 0x11, 0x0f, 0x1f, 0x00,
	0x88, 0xd8, 0x50, 0x50, 0x90, 0xd8, 0x48, 0x00, 0x4f, 0xdf, 0x90, 0x90, 0xff, 0x7f, 0x00, 0x00,
	0xe0, 0xf0, 0x18, 0x0b, 0x0b, 0x18, 0x30, 0x00, 0x07, 0x0f, 0x18, 0x11, 0x11, 0x0f, 0x1f, 0x00,
};

#endif
