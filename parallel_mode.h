///////////////////////////////////////////////////////////////////////////////////////
//
//  Noritake "Type 0: PARALLEL [Parallel Interface] format" (pg. 10)
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

#ifndef PARALLEL_MODE_H
#define PARALLEL_MODE_H

#if (defined (CU_UW_MODE_H) || defined (SPI_MODE_H))
#error >>>>>> ONLY ONE MODE MAY BE DEFINED - EDIT "config.h" <<<<<<
#else

#define D_PIN PINA // data port is...
#define D_DDR DDRA // ...PORT A
#define D_PORT PORTA // ...pins 22-29

#define C_DDR DDRC // control port is...
#define C_PORT PORTC // ...PORT C pins 30-35

#define RS  digitalPinToBitMask (30) // register select pin 30
#define CS1 digitalPinToBitMask (31) // chip select 1 pin 31
#define RW  digitalPinToBitMask (32) // read / write pin 32
#define CS2 digitalPinToBitMask (33) // chip select 2 pin 33
#define EN  digitalPinToBitMask (34) // chip enable pin 34
#define RST digitalPinToBitMask (35) // reset pin 35

inline void Noritake_VFD_GUU100::_initPort (void)
{
	// setup PARALLEL control pins
	C_PORT &= ~ (RS | RW | EN | CS1 | CS2); // all low
	C_PORT |= RST; // except reset

	C_DDR |= (RS | RW | EN | CS1 | CS2 | RST); // all outputs
	D_DDR = 0xFF; // set data port as outputs

	// hardware reset
	C_PORT &= ~RST;
	_delay_usec (1000); // assert reset for minimum 100 nsec (GU128X64E manual pg. 17)
	C_PORT |= RST;
	_delay_usec (100000); // now wait 100 msec (GU128X64E manual pg. 17)
}

inline uint8_t Noritake_VFD_GUU100::_readPort (uint8_t rs)
{
	uint8_t data;
	uint8_t chip = (_cur_x & _BV (6)); // select left or right side
	D_DDR = 0x00; // parallel data port as an input
	// set proper cs1/2 and pulse EN (dummy read - GU128X64E manual pg. 16)
	C_PORT |= ((chip ? CS2 : CS1) | (rs ? RS : 0) | RW | EN);
	C_PORT &= ~ ((chip ? CS1 : CS2) | (rs ? 0 : RS) | EN);
	D_DDR = 0x00; // parallel data port as an input
	C_PORT |= EN; // assert enable (data available on the rising edge)

	////////////////////////////////////////////////////////////////////////
	// The setup and hold delay is shorter than the specs require to get
	// maximum performance. If glitches appear during screen drawing
	// (especially lines and circles, and if you have long data wires),
	// then add one "NOP" at a time until it works properly.
	////////////////////////////////////////////////////////////////////////
	__asm__ __volatile__ ( // setup & hold delay
#if ( F_CPU > 8000000UL )
		" nop\n"
#endif
#if ( F_CPU > 16000000UL )
		" nop\n"
#endif
		// " nop\n" // <-- add them here
		" nop\n"
	);
	data = D_PIN; // read a byte from VFD->AVR
	C_PORT &= ~EN; // de-assert enable
	// we set the data port back to outputs so that _writePort doesn't have to do it every
	// time - writes occur about 9 times for every read so it makes things run a lot faster.
	D_DDR = 0xFF; // parallel data port as an output
	return data;
}

inline void Noritake_VFD_GUU100::_writePort (uint8_t data, uint8_t rs)
{
	uint8_t chip = (_cur_x & _BV (6)); // select left or right side
	// set proper cs1/2 and pulse EN (dummy read - GU128X64E manual pg. 16)
	C_PORT |= ((chip ? CS2 : CS1) | (rs ? RS : 0));
	C_PORT &= ~ ((chip ? CS1 : CS2) | (rs ? 0 : RS) | RW);
	C_PORT |= EN; // assert enable
	D_PORT = data; // write a byte from AVR->VFD (no need for DDR since read pre-set it)
#if ( F_CPU > 16000000UL )
	__asm__ __volatile__ (
		" nop\n" // setup & hold delay
		// " nop\n" // <-- add more NOP's here if necessary
	);
#endif
	C_PORT &= ~EN; // de-assert enable (latch data to vfd on falling edge)
}

#endif // #if (defined(....

#endif // #ifndef PARALLEL_MODE_H

// end parallel_mode.h
