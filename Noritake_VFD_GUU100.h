/////////////////////////////////////////////////////////////////////////////////////
//
//  Noritake GU128X64E-U100 VFD Display Driver Library for Arduino
//  Copyright (c) 2012, 2015 Roger A. Krupski <rakrupski@verizon.net>
//
//  Last update: 24 December 2015
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
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//  Configure the ports and pins to your liking if these are not suitable. For     //
//  example, the UNO could use PORT D (pins 0 thru 7) for parallel data and maybe  //
//  3 pins from PORT C (the analog input pins 0 thru 5) for the control port.      //
//  Be sure to configure _GUU_MODE below for 0 (parallel) or 1 (serial SPI) mode.  //
/////////////////////////////////////////////////////////////////////////////////////
//                                                                                 //
//       This library is currently setup for an Arduino MEGA 2560 board            //
//                                                                                 //
/////////////////////////////////////////////////////////////////////////////////////

#ifndef NORITAKE_VFD_GUU100_H
#define NORITAKE_VFD_GUU100_H

#if ARDUINO < 100
#include <WProgram.h>
#else
#include <Arduino.h>
#endif

#define _GUU_MODE 0 // parallel
//#define _GUU_MODE 1 // serial

// VFD commands (GU128X64E manual pg. 14..16)
#define SETDISP  0b00111110 // display on/off (cathode not affected)
#define SETADDR  0b01000000 // horizontal byte select 0..63 (X)
#define SETPAGE  0b10111000 // vertical byte select 0..7 (Y)
#define SETLINE  0b11000000 // display line start offset 0..63 (Z)
#define SETBRITE 0b00100000 // set display brightness 0bx000:max, 0bx111:min
#define CATHODE  0b00001000 // filament power on/off bit for set brightness command. LO=off, HI=on
#define FUNC_SET 0b00100000 // function set req'd before brightness & cathode commands
#define SPI_RCMD 0b11111100 // SPI control bits, R/W (bit3) = HI (GU128X64E manual pg. 8)
#define SPI_WCMD 0b11111000 // SPI control bits, R/W (bit3) = LO (GU128X64E manual pg. 8)

class Noritake_VFD_GUU100 : public Stream {
public:
	void init (void);
	void setDisplay (uint8_t);
	uint8_t setBrightness (uint8_t);
	void setScroll (uint8_t);
	uint8_t getScroll (void);
	void setLine (double, double);
	void getLine (double &, double &);
	void setCursor (uint8_t, uint8_t);
	void getCursor (uint8_t &, uint8_t &);
	void setPixel (uint16_t, uint8_t);
	uint8_t getPixel (uint16_t);
	void setDot (uint8_t, uint8_t, uint8_t);
	uint8_t getDot (uint8_t, uint8_t);
	void setInvert (uint8_t);
	void invertScreen (void);
	void clear (void);
	void clearScreen (uint8_t = 0); // optional fill pattern
	void drawImage (const uint8_t *, uint8_t, uint8_t, uint8_t, uint8_t);
	void drawImage (uint32_t, uint8_t, uint8_t, uint8_t, uint8_t);
	void drawPolygon (uint8_t, uint8_t, uint8_t, int, uint8_t, uint8_t);
	void drawVector (uint8_t, uint8_t, uint8_t, int, uint8_t);
	void drawLine (uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
	void drawRect (uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
	void fillRect (uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
	void drawRoundRect (uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
	void drawEllipse (uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
	void drawCircle (uint8_t, uint8_t, uint8_t, uint8_t);
	void fillCircle (uint8_t, uint8_t, uint8_t, uint8_t);
	void screenSave (void);
	void screenSave (const char *);
	void drawArc (uint8_t, uint8_t, uint8_t, int, int, uint8_t);
	void drawArc (uint8_t, uint8_t, uint8_t, uint8_t, int, int, uint8_t);
	void setFont (const uint8_t *, uint8_t = 0, uint8_t = 0);
	void setFont (uint32_t, uint8_t = 0, uint8_t = 0);
	uint32_t getFont (void);
	void getFontDat (void *);
	void home (uint8_t = 0); // optional 1 = reset scroll also

	virtual int available (void);
	virtual int peek (void);
	virtual int read (void);
	virtual void flush (void);
	operator bool (void);

	virtual size_t write (uint8_t);
	using Print::write;
private:
	// private variables
	#ifdef pgm_read_byte_far
	#define PGM_R pgm_read_byte_far
	#else
	#define PGM_R pgm_read_byte_near
	#endif
	uint32_t _font;
	uint32_t _fontStart;
	uint8_t _cur_x;
	uint8_t _cur_y;
	uint8_t _cur_z;
	uint8_t _displayHeight;
	uint8_t _displayWidth;
	uint8_t _displayBright;
	uint8_t _firstChar;
	uint8_t _lastChar;
	uint8_t _fontWidth;
	uint8_t _fontHeight;
	uint8_t _fontHGap;
	uint8_t _fontVGap;
	uint8_t _bytesPerChar;
	uint8_t _invert;
	uint8_t _fontsrc;
	uint8_t _next_x;
	uint8_t _next_y;
	// private functions
	void _delay_usec (uint32_t);
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
	inline uint8_t _spiTransfer (uint8_t);
	inline uint8_t _readPort (uint8_t);
	inline void _writePort (uint8_t, uint8_t);
};

#endif
//////// end of Noritake_GUU100.h ////////
