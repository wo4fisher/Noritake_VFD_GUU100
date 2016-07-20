///////////////////////////////////////////////////////////////////////////////////////
//
//  Noritake "Type 1: CU-UW series [Noritake-itron module] like format" (pg. 7)
//  Copyright (c) 2012, 2016 Roger A. Krupski <rakrupski@verizon.net>
//
//  Last update: 15 April 2016
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
///////////////////////////////////////////////////////////////////////////////////////

#ifndef CU_UW_MODE_H
#define CU_UW_MODE_H

#if (defined (PARALLEL_MODE_H) || defined (SPI_MODE_H))
#error >>>>>> ONLY ONE MODE MAY BE DEFINED - EDIT "config.h" <<<<<<
#else

#define SISO 50 //
#define CS 53   // these are MEGA2560 pins
#define SCK 52  // define actual pins here
#define RST 99  //

#define _SISO_PIN portInputRegister (digitalPinToPort (SISO)) // siso read
#define _SISO_DDR portModeRegister (digitalPinToPort (SISO)) // siso ddr
#define _SISO_PORT portOutputRegister (digitalPinToPort (SISO)) // siso write
#define _SISO digitalPinToBitMask (SISO) // siso bit

#define _CS_DDR portModeRegister (digitalPinToPort (CS)) // chip select (STB) ddr
#define _CS_PORT portOutputRegister (digitalPinToPort (CS)) // chip select (STB) write
#define _CS digitalPinToBitMask (CS) // chip select (STB) bit

#define _SCK_DDR portModeRegister (digitalPinToPort (SCK)) // serial clock (SCK) ddr
#define _SCK_PORT portOutputRegister (digitalPinToPort (SCK)) // serial clock (SCK) write
#define _SCK digitalPinToBitMask (SCK) // serial clock (SCK) bit

#define _RST_DDR portModeRegister (digitalPinToPort (RST)) // reset (RST) ddr
#define _RST_PORT portOutputRegister (digitalPinToPort (RST)) // reset (RST) write
#define _RST digitalPinToBitMask (RST) // reset (RST) bit

#define _CS2_BIT _BV (3) // CS2 bit (right side)
#define _CS1_BIT _BV (4) // CS1 bit (left side)

inline void Noritake_VFD_GUU100::_initPort (void)
{
	*_CS_DDR |= _CS; // cs (stb) output
	*_SCK_DDR |= _SCK; // sck output
	*_SISO_DDR &= ~_SISO; // siso input
	// hardware reset
	*_RST_DDR |= _RST;
	*_RST_PORT &= ~_RST;
	_delay_usec (10); // assert reset for minimum 100 nsec (GU128X64E manual pg. 17)
	*_RST_PORT |= _RST;
	_delay_usec (100000); // now wait 100 msec (GU128X64E manual pg. 17)
}

inline void Noritake_VFD_GUU100::_writePort (uint8_t data, uint8_t rs)
{
	uint8_t cmd;
	rs ? cmd = 0xE2 : cmd = 0xE0; // select cmd/data w/rw bit clear
	(_cur_x & _BV (6)) ? cmd |= _CS1_BIT : cmd |= _CS2_BIT;
	*_CS_PORT &= ~_CS; // assert strobe
	_cu_uw_RW (cmd); // send command via CU-UW mode
	_cu_uw_RW (data); // send data via CU-UW mode
	*_CS_PORT |= _CS; // de-assert strobe
}

inline uint8_t Noritake_VFD_GUU100::_readPort (uint8_t rs)
{
	uint8_t cmd;
	uint8_t data;
	rs ? cmd = 0xE6 : cmd = 0xE4; // select cmd/data w/rw bit set
	(_cur_x & _BV (6)) ? cmd |= _CS1_BIT : cmd |= _CS2_BIT;
	*_CS_PORT &= ~_CS; // assert strobe
	_cu_uw_RW (cmd); // send command via CU-UW mode
	data = _cu_uw_RW (0); // read data via CU-UW mode
	*_CS_PORT |= _CS; // de-assert strobe
	return data; // return read data
}

inline uint8_t Noritake_VFD_GUU100::_cu_uw_RW (uint8_t data)
{
	uint8_t bits = 8;

	while (bits--) { // write out bits
		*_SCK_PORT &= ~_SCK; // set sck low
		*_SISO_DDR |= _SISO; // set siso DDR as output
		(data & _BV (bits)) ? *_SISO_PORT |= _SISO : *_SISO_PORT &= ~_SISO; // write bit
		*_SCK_PORT |= _SCK; // set sck high
		*_SISO_DDR &= ~_SISO; // set siso DDR as input
		(*_SISO_PIN & _SISO) ? data |= _BV (bits) : data &= ~_BV (bits); // read bit
	}

	return data;
}

#endif // #if (defined(....

#endif // #ifndef CU_UW_MODE_H

// end cu-uw_mode.h
