///////////////////////////////////////////////////////////////////////////////////////
//
//  Noritake GU128X64E-U100 VFD Display Driver Library for Arduino
//  Copyright (c) 2012, 2015 Roger A. Krupski <rakrupski@verizon.net>
//
//  Last update: 19 July 2016
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

#ifndef NORITAKE_VFD_GUU100_H
#define NORITAKE_VFD_GUU100_H

#if ARDUINO < 100
#include <WProgram.h>
#else
#include <Arduino.h>
#endif

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
	void init (uint8_t, uint8_t);
	void setDisplay (uint8_t);
	uint8_t setBrightness (uint8_t);
	void setScroll (int);
	int getScroll (void);
	void setLine (double, double);
	void getLine (double &, double &);
	void setCursor (int, int);
	void getCursor (int &, int &);
	void pushCursor (void);
	void popCursor (void);
	void setPixel (uint16_t, uint8_t);
	uint8_t getPixel (uint16_t);
	void setDot (int, int, uint8_t);
	uint8_t getByte (int, int);
	void setByte (int, int, uint8_t);
	uint8_t getDot (int, int);
	void setInvert (uint8_t);
	void invertScreen (void);
	uint8_t clear (void);
	uint8_t clearScreen (void);
	uint8_t clearScreen (uint8_t);
	uint16_t getBlock (uint8_t *, int, int, uint8_t, uint8_t);
	void drawImage (const uint8_t *, int, int, uint8_t, uint8_t);
	void drawImage (uint32_t, int, int, uint8_t, uint8_t);
	void drawPolygon (int, int, uint8_t, int, uint8_t, uint8_t);
	void drawVector (int, int, uint8_t, int, uint8_t);
	void drawLine (int, int, int, int, uint8_t);
	void drawRect (int, int, uint8_t, uint8_t, uint8_t);
	void fillRect (int, int, uint8_t, uint8_t, uint8_t);
	void drawRoundRect (int, int, uint8_t, uint8_t, uint8_t, uint8_t);
	void drawEllipse (int, int, uint8_t, uint8_t, uint8_t);
	void drawCircle (int, int, uint8_t, uint8_t);
	void fillCircle (int, int, uint8_t, uint8_t);
	void screenSave (void);
	void screenSave (const char *);
	void drawArc (int, int, uint8_t, int, int, uint8_t);
	void drawArc (int, int, uint8_t, uint8_t, int, int, uint8_t);
	void setFont (const uint8_t *);
	void setFont (const uint8_t *, int, int);
	void setFont (uint32_t);
	void setFont (uint32_t, int, int);
	uint32_t getFont (void);
	uint8_t getCharWidth (void);
	uint8_t getCharHeight (void);
	uint8_t getMaxChars (void);
	uint8_t getMaxLines (void);
	void home (void);
	void home (uint8_t);
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
	#define PGM_READ_BYTE pgm_read_byte_far
	#else
	#define PGM_READ_BYTE pgm_read_byte_near
	#endif
	uint32_t _fontData;
	uint32_t _fontStart;
	uint8_t _next_x;
	uint8_t _next_y;
	int _save_x;
	int _save_y;
	int _cur_x;
	int _cur_y;
	int _cur_z;
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
	// private functions
	void _delay_usec (uint32_t);
	size_t _noFont (void);
	void _writeDisplay (uint8_t);
	inline size_t _carriageReturn (void);
	inline size_t _lineFeed (void);
	inline size_t _backSpace (void);
	inline size_t _doTabs (uint8_t);
	inline uint8_t _bitsBetween (uint8_t, uint8_t);
	inline void _writeData (uint8_t);
	inline uint8_t _readData (void);
	inline void _writeCmd (uint8_t);
	inline void _increment (void);
	inline void _setDot (int, int, uint8_t);
	inline void _setCursor (int, int);
	inline void _setScroll (int);
	inline uint8_t _getBits (int, int);
	inline uint8_t _align (uint8_t);
	inline uint8_t _clip (uint8_t);
	// these are in the IO config files
	inline void _initPort (void);
	inline uint8_t _spiTransfer (uint8_t);
	inline uint8_t _readPort (uint8_t);
	inline void _writePort (uint8_t, uint8_t);
	inline uint8_t _cu_uw_RW (uint8_t);
};

#include "config.h"

#endif

//////// end of Noritake_GUU100.h ////////

