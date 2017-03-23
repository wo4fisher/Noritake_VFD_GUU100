///////////////////////////////////////////////////////////////////////////////////////
//
//  Noritake "Type 2: SPI [Serial Peripheral Interface] format" (pg. 8)
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

#ifndef SPI_MODE_H
#define SPI_MODE_H

#if (defined (PARALLEL_MODE_H) || defined (CU_UW_MODE_H))
#error >>>>>> ONLY ONE MODE MAY BE DEFINED - EDIT "config.h" <<<<<<
#else

#define C_DDR DDRF // PORT F
#define C_PORT PORTF // pins A0-A2
#define RST digitalPinToBitMask (A0) // RST = pin A0
#define CS2 digitalPinToBitMask (A1) // CS2 = pin A1
#define CS1 digitalPinToBitMask (A2) // CS1 = pin A2

//#define C_DDR DDRK // PORT K
//#define C_PORT PORTK // pins A8-A10
//#define RST digitalPinToBitMask (A8) // RST = pin A8
//#define CS2 digitalPinToBitMask (A9) // CS2 = pin A9
//#define CS1 digitalPinToBitMask (A10) // CS1 = pin A10

#define SPI_DDR DDRB // SPI uses
#define SPI_PORT PORTB // PORT B
#define _MISO digitalPinToBitMask (50) // MISO = pin 50 (MEGA2560)
#define _MOSI digitalPinToBitMask (51) // MOSI = pin 51
#define _SCK digitalPinToBitMask (52) // SCK = pin 52
#define _SS digitalPinToBitMask (53) // SS = pin 53

inline void Noritake_VFD_GUU100::_initPort (void)
{
	// setup SPI control pins
	C_PORT |= (RST | CS1 | CS2);
	C_DDR |= (RST | CS1 | CS2);

	// setup SPI pins
	SPI_DDR &= ~_MISO; // MISO is input
	SPI_DDR |= (_SCK | _MOSI | _SS); // SCK, MOSI & SS are outputs

	// SPI enable, master mode, mode 3
	SPCR = (_BV (SPE) | _BV (MSTR) | _BV (CPOL) | _BV (CPHA));

	// SPI 2X speed is flakey above 16 mhz on the VFD... try it if you want.
#if (! (F_CPU > 16000000UL))
	SPSR |= _BV (SPI2X); // double speed SPI
#endif

	// 100 msec delay after powerup (GU128X64E manual pg. 17)
	// (doubled to 200 msec for good luck)
	__builtin_avr_delay_cycles ((F_CPU / 1e3) * 200);

	// assert HW reset for minimum 250 nsec (GU128X64E manual pg. 17)
	// (doubled to 500 nsec for good luck)
	C_PORT &= ~RST;
	__builtin_avr_delay_cycles ((F_CPU / 1e9) * 500);
	C_PORT |= RST;
}

inline uint8_t Noritake_VFD_GUU100::_spiTransfer (uint8_t data)
{
	SPDR = data; // write to SPI data register
	while (! (SPSR & _BV (SPIF))); // wait for all of it to be shifted
	return SPDR; // return read data
}

inline uint8_t Noritake_VFD_GUU100::_readPort (uint8_t rs)
{
	uint8_t data;
	C_PORT &= (_cur_x < (_displayWidth / 2)) ? ~CS1 : ~CS2; // assert active low CS1 or CS2
	_spiTransfer (SPI_RCMD | (rs << 1)); // send read command w/register select
	data = _spiTransfer (0); // read data
	C_PORT |= (CS1 | CS2); // de-assert both CS pins
	return data;
}

inline void Noritake_VFD_GUU100::_writePort (uint8_t data, uint8_t rs)
{
	C_PORT &= (_cur_x < (_displayWidth / 2)) ? ~CS1 : ~CS2; // assert active low CS1 or CS2
	_spiTransfer (SPI_WCMD | (rs << 1)); // send write command w/register select
	_spiTransfer (data); // send data
	C_PORT |= (CS1 | CS2); // de-assert both CS pins
}

#endif // #if (defined(....
#endif // #ifndef SPI_MODE_H

// end spi_mode.h
