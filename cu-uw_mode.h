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
#define CS   53 // these are MEGA2560 pins
#define SCK  52 // define actual pins used here
#define RST  99 //

#define SISO_PIN portInputRegister (digitalPinToPort (SISO)) // siso read
#define SISO_DDR portModeRegister (digitalPinToPort (SISO)) // siso ddr
#define SISO_PORT portOutputRegister (digitalPinToPort (SISO)) // siso write
#define SISO_BIT digitalPinToBitMask (SISO) // siso bit

#define CS_DDR portModeRegister (digitalPinToPort (CS)) // chip select (STB) ddr
#define CS_PORT portOutputRegister (digitalPinToPort (CS)) // chip select (STB) write
#define CS_BIT digitalPinToBitMask (CS) // chip select (STB) bit

#define SCK_DDR portModeRegister (digitalPinToPort (SCK)) // serial clock (SCK) ddr
#define SCK_PORT portOutputRegister (digitalPinToPort (SCK)) // serial clock (SCK) write
#define SCK_BIT digitalPinToBitMask (SCK) // serial clock (SCK) bit

#define RST_DDR portModeRegister (digitalPinToPort (RST)) // reset (RST) ddr
#define RST_PORT portOutputRegister (digitalPinToPort (RST)) // reset (RST) write
#define RST_BIT digitalPinToBitMask (RST) // reset (RST) bit

#define CS2_BIT _BV (3) // CS2 bit (right side)
#define CS1_BIT _BV (4) // CS1 bit (left side)

inline void Noritake_VFD_GUU100::_initPort (void)
{
	// config I/O pins
	*CS_PORT |= CS_BIT; // cs (stb) default high
	*SCK_PORT |= SCK_BIT; // sck default high
	*SISO_PORT &= ~SISO_BIT; // siso default low
	*RST_PORT |= RST_BIT; // reset default high

	// config I/O ddr's
	*CS_DDR |= CS_BIT; // cs (stb) output
	*SCK_DDR |= SCK_BIT; // sck output
	*SISO_DDR &= ~SISO_BIT; // siso input
	*RST_DDR |= RST_BIT; // reset output

	// 100 msec delay after powerup (GU128X64E manual pg. 17)
	// (doubled to 200 msec for good luck)
	__builtin_avr_delay_cycles ((F_CPU / 1e3) * 200);

	// assert HW reset for minimum 250 nsec (GU128X64E manual pg. 17)
	// (doubled to 500 nsec for good luck)
	*RST_PORT &= ~RST_BIT;
	__builtin_avr_delay_cycles ((F_CPU / 1e9) * 500);
	*RST_PORT |= RST_BIT;
}

inline void Noritake_VFD_GUU100::_writePort (uint8_t data, uint8_t rs)
{
	uint8_t cmd;
	rs ? cmd = 0xE2 : cmd = 0xE0; // select cmd/data w/rw bit clear
	(_cur_x & _BV (6)) ? cmd |= CS1_BIT : cmd |= CS2_BIT;
	*CS_PORT &= ~CS_BIT; // assert strobe
	_cu_uw_RW (cmd); // send command via CU-UW mode
	_cu_uw_RW (data); // send data via CU-UW mode
	*CS_PORT |= CS_BIT; // de-assert strobe
}

inline uint8_t Noritake_VFD_GUU100::_readPort (uint8_t rs)
{
	uint8_t cmd;
	uint8_t data;
	rs ? cmd = 0xE6 : cmd = 0xE4; // select cmd/data w/rw bit set
	(_cur_x & _BV (6)) ? cmd |= CS1_BIT : cmd |= CS2_BIT;
	*CS_PORT &= ~CS_BIT; // assert strobe
	_cu_uw_RW (cmd); // send command via CU-UW mode
	data = _cu_uw_RW (0); // read data via CU-UW mode
	*CS_PORT |= CS_BIT; // de-assert strobe
	return data; // return read data
}

inline uint8_t Noritake_VFD_GUU100::_cu_uw_RW (uint8_t data)
{
	uint8_t bits = 8;

	while (bits--) { // write out bits
		*SCK_PORT &= ~SCK_BIT; // set sck low
		*SISO_DDR |= SISO_BIT; // set siso DDR as output
		(data & _BV (bits)) ? *SISO_PORT |= SISO_BIT : *SISO_PORT &= ~SISO_BIT; // write bit
		*SCK_PORT |= SCK_BIT; // set sck high
		*SISO_DDR &= ~SISO_BIT; // set siso DDR as input
		(*SISO_PIN & SISO_BIT) ? data |= _BV (bits) : data &= ~_BV (bits); // read bit
	}

	return data;
}

#endif // #if (defined(....
#endif // #ifndef CU_UW_MODE_H

// end cu-uw_mode.h
