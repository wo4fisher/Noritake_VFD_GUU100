///////////////////////////////////////////////////////////////////////////////
//
//  Noritake GU128X64E-U100 VFD Display Driver Library for Arduino
//  Copyright (c) 2012, 2015 Roger A. Krupski <rakrupski@verizon.net>
//
//  Last update: 01 August 2015
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

#ifndef NORITAKE_VFD_GUU100_H
#define NORITAKE_VFD_GUU100_H

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

#ifdef pgm_read_byte_far
	#define PGM_READ pgm_read_byte_far
#else
	#define PGM_READ pgm_read_byte_near
#endif

class Noritake_VFD_GUU100 : public Stream {
	public:
		void init (uint8_t = 0); // optional 1 = SPI mode
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
		void clearScreen (uint8_t = 0); // optional fill pattern
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
		void home (uint8_t = 0); // optional 1 = reset scroll also
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
		uint8_t _guu_mode;
		// functions
		size_t _noFont (void);
		void _initIO (uint8_t);
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
		inline uint8_t _spiTransfer (uint8_t = 0); // dummy param for reads
};

#endif

//////// end of Noritake_VFD_GUU100.h ////////
