///////////////////////////////////////////////////////////////////////////////
//
//  Noritake GU128X64E-U100 VFD Display Driver Library for Arduino
//  Copyright (c) 2012, 2015 Roger A. Krupski <rakrupski@verizon.net>
//
//  Last update: 18 June 2015
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

#ifndef NORITAKE_VFD_GUU_H
#define NORITAKE_VFD_GUU_H

#define GUU_MODE 0 // parallel interface
//#define GUU_MODE 1 // serial (SPI mode 3) interface

#if ARDUINO < 100
	#include <WProgram.h>
#else
	#include <Arduino.h>
#endif

#include <util/delay.h> // for _delay_ms ()

// VFD commands (GU128X64E manual pg. 14..16)
#define SETDISP   0b00111110 // display on/off (cathode not affected)
#define SETADDR   0b01000000 // horizontal byte select 0..63
#define SETPAGE   0b10111000 // vertical byte select 0..7
#define SETLINE   0b11000000 // display line start offset 0..63
#define SETBRITE  0b00100000 // set display brightness 0bx000:max, 0bx111:min
#define FILAMENT  0b00001000 // filament power on/off bit for setbrightness command. LO=off, HI=on
#define FUNC_SET  0b00100000 // function set req'd before brightness & cathode commands
#define SPI_READ  0b11111100 // SPI control bits, R/W (bit3) = HI (GU128X64E manual pg. 8)
#define SPI_WRITE 0b11111000 // SPI control bits, R/W (bit3) = LO (GU128X64E manual pg. 8)

#define _DISPLAY_WIDTH 128 // change these if you need to...
#define _DISPLAY_HEIGHT 64 // ...for some odd reason.

#if defined(pgm_read_byte_far)
	#define PGM_READ pgm_read_byte_far
#else
	#define PGM_READ pgm_read_byte_near
#endif

//
// Edit these defines if you want to use different pins. Note
// that the parallel interface MUST be all on ONE PORT.
//
// Port addresses for the ATMEGA_328P _SFR_IO8 (0xNN)
// NAME    PIN (input)   DDR (data dir)   PORT (write)
// ====    ===========   ==============   ============
//  B         0x03           0x04             0x05
//  C         0x06           0x07             0x08
//  D         0x09           0x0A             0x0B
//
// Port addresses for the ATMEGA_2560 _SFR_IO8 (0xNN)
// NAME    PIN (input)   DDR (data dir)   PORT (write)
// ====    ===========   ==============   ============
//  A         0x00           0x01             0x02
//  B         0x03           0x04             0x05
//  C         0x06           0x07             0x08
//  D         0x09           0x0A             0x0B
//  E         0x0C           0x0D             0x0E
//  F         0x0F           0x10             0x11
//  G         0x12           0x13             0x14
//

#if GUU_MODE == 1 // serial (SPI) mode (slower)
	#if ((defined(__AVR_ATmega2560__) || defined(__AVR_ATmega2561__)))
		// MEGA control port for SPI
		#define C_DDR  _SFR_IO8(0x10) // control port is
		#define C_PORT _SFR_IO8(0x11) // PORT F
		#define RST digitalPinToBitMask (A0) // reset pin A0
		#define CS2 digitalPinToBitMask (A1) // chip select 2 pin A1
		#define CS1 digitalPinToBitMask (A2) // chip select 1 pin A2
		// MEGA SPI port
		#define SPI_DDR  _SFR_IO8(0x04) // SPI port is
		#define SPI_PORT _SFR_IO8(0x05) // PORT B
		#define _MISO digitalPinToBitMask (50) // MISO pin 50
		#define _MOSI digitalPinToBitMask (51) // MOSI pin 51
		#define _SCK  digitalPinToBitMask (52) // SCK pin 52
		#define _SS   digitalPinToBitMask (53) // SS pin 53
	#else
		// UNO control port for SPI
		#define C_DDR  _SFR_IO8(0x07) // control port is
		#define C_PORT _SFR_IO8(0x08) // PORT C
		#define RST digitalPinToBitMask (A0) // reset pin A0
		#define CS2 digitalPinToBitMask (A1) // chip select 2 pin A1
		#define CS1 digitalPinToBitMask (A2) // chip select 1 pin A2
		// UNO SPI port
		#define SPI_DDR  _SFR_IO8(0x04) // SPI port is
		#define SPI_PORT _SFR_IO8(0x05) // PORT B
		#define _SS   digitalPinToBitMask (10) // SS pin 10
		#define _MOSI digitalPinToBitMask (11) // MOSI pin 11
		#define _MISO digitalPinToBitMask (12) // MISO pin 12
		#define _SCK  digitalPinToBitMask (13) // SCK pin 13
	#endif
#else // parallel mode
	#if ((defined(__AVR_ATmega2560__) || defined(__AVR_ATmega2561__)))
		// MEGA control port for PARALLEL
		#define D_PIN  _SFR_IO8(0x00) // data port is
		#define D_DDR  _SFR_IO8(0x01) // PORT A
		#define D_PORT _SFR_IO8(0x02) // pins 22...29
		#define C_DDR  _SFR_IO8(0x07) // control port is
		#define C_PORT _SFR_IO8(0x08) // PORT C
		#define RST digitalPinToBitMask (35) // reset pin 35
		#define CS2 digitalPinToBitMask (33) // chip select 2 pin 33
		#define CS1 digitalPinToBitMask (31) // chip select 1 pin 31
		#define EN  digitalPinToBitMask (34) // chip enable pin 34
		#define RW  digitalPinToBitMask (32) // read / write pin 32
		#define RS  digitalPinToBitMask (30) // register select pin 30
	#else
		// UNO control port for PARALLEL
		#define D_PIN  _SFR_IO8(0x09) // data port is
		#define D_DDR  _SFR_IO8(0x0A) // PORT D
		#define D_PORT _SFR_IO8(0x0B) // pins 0...7
		#define C_DDR  _SFR_IO8(0x07) // control port is
		#define C_PORT _SFR_IO8(0x08) // PORT C
		#define RST digitalPinToBitMask (A0) // reset pin A0
		#define CS2 digitalPinToBitMask (A1) // chip select 2 pin A1
		#define CS1 digitalPinToBitMask (A2) // chip select 1 pin A2
		#define EN  digitalPinToBitMask (A3) // chip enable pin A3
		#define RW  digitalPinToBitMask (A4) // read / write pin A4
		#define RS  digitalPinToBitMask (A5) // register select pin A5
	#endif
#endif

class Noritake_VFD_GUU100 : public Stream {
	public:
		void init (void);
		void setDisplay (uint8_t);
		uint8_t setBrightness (uint8_t);
		void setScroll (uint8_t);
		uint8_t getScroll (void);
		void setLine (float, float);
		void getLine (float &, float &);
		void setCursor (uint8_t, uint8_t);
		void getCursor (uint8_t &, uint8_t &);
		void setPixel (uint16_t, uint8_t);
		uint8_t getPixel (uint16_t);
		void setDot (uint8_t, uint8_t, uint8_t);
		uint8_t getDot (uint8_t, uint8_t);
		void setInvert (uint8_t);
		void clearScreen (uint8_t = 0);
		void drawImage (const uint8_t *, uint8_t, uint8_t, uint8_t, uint8_t);
		void drawImage (uint32_t, uint8_t, uint8_t, uint8_t, uint8_t);
		void drawVect (uint8_t, uint8_t, uint8_t, long int, uint8_t);
		void drawLine (uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
		void drawRect (uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
		void fillRect (uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
		void drawRoundRect (uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
		void drawEllipse (uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
		void drawCircle (uint8_t, uint8_t, uint8_t, uint8_t);
		void fillCircle (uint8_t, uint8_t, uint8_t, uint8_t);
		void setFont (const uint8_t *);
		void setFont (uint32_t);
		uint32_t getFont (void);
		void getFontDat (void *);
		void home (uint8_t = 0);
		virtual int available (void);
		virtual int peek (void);
		virtual int read (void);
		virtual void flush (void);
		inline virtual size_t write (uint8_t);
		using Print::write;
	private:
		// variables
		uint32_t _font;
		uint32_t _fontStart;
		uint8_t _cur_x;
		uint8_t _cur_y;
		uint8_t _cur_z;
		uint8_t _tmp_x;
		uint8_t _tmp_y;
		uint8_t _tmp_z;
		uint8_t _displayHeight;
		uint8_t _displayWidth;
		uint8_t _displayBright;
		uint8_t _firstChar;
		uint8_t _fontWidth;
		uint8_t _fontHeight;
		uint8_t _fontHGap;
		uint8_t _fontVGap;
		uint8_t _bytesPerChar;
		uint8_t _invert;
		uint8_t _fontsrc;
		uint8_t _next_x;
		uint8_t _next_y;
		// functions
		size_t _noFont (void);
		void _writeDisplay (uint8_t);
		inline uint8_t _bitsBetween (uint8_t, uint8_t);
		inline void _writeData (uint8_t);
		inline uint8_t _readData (void);
		inline void _writeCmd (uint8_t);
		inline void _increment (void);
		inline void _setDot (uint8_t, uint8_t, uint8_t);
		inline void _setCursor (uint8_t, uint8_t);
		inline void _setScroll (uint8_t);
		inline uint8_t _getBits (uint8_t, uint8_t);
		inline uint8_t _align (uint8_t);
		inline uint8_t _clip (uint8_t);
		inline size_t _carriageReturn (void);
		inline size_t _lineFeed (void);
		inline size_t _backSpace (void);
		inline size_t _doTabs (uint8_t);
		inline void _initPort (void);
		inline uint8_t _readPort (uint8_t);
		inline void _writePort (uint8_t, uint8_t);
		inline uint8_t _spiTransfer (uint8_t = 0);
};

#endif
