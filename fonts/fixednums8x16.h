////////////////////////////////////////////////////////////
// 8 by 16 pixel font (digits only) from GLCD
////////////////////////////////////////////////////////////

static const uint8_t fixednums8x16[] PROGMEM = {

	0x08, // width (base + 0)
	0x10, // height (base + 1)
	0x02, // horizontal gap (base + 2)
	0x00, // vertical gap (base + 3)
	0x20, // first char (base + 4)
	0x10, // bytes per char (base + 5)

	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

	0x80, 0x80, 0x80, 0xe0, 0xe0, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, // char '+'
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb0, 0x70, 0x00, 0x00, 0x00, // char ','
	0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // char '-'
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00, 0x00, 0x00, // char '.'
	0x00, 0x00, 0x00, 0xc0, 0xf0, 0x3c, 0x0f, 0x03, 0x30, 0x3c, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00, // char '/'
	0xfc, 0xfe, 0x03, 0x81, 0x61, 0x1b, 0xfe, 0xfc, 0x0f, 0x1f, 0x36, 0x21, 0x20, 0x30, 0x1f, 0x0f, // char '0'
	0x04, 0x04, 0x06, 0xff, 0xff, 0x00, 0x00, 0x00, 0x20, 0x20, 0x20, 0x3f, 0x3f, 0x20, 0x20, 0x20, // char '1'
	0x0c, 0x0e, 0x03, 0x01, 0x81, 0xc3, 0x7e, 0x3c, 0x38, 0x3c, 0x26, 0x23, 0x21, 0x20, 0x20, 0x20, // char '2'
	0x0c, 0x0e, 0x43, 0x41, 0x41, 0x43, 0xfe, 0xbc, 0x0c, 0x1c, 0x30, 0x20, 0x20, 0x30, 0x1f, 0x0f, // char '3'
	0x00, 0xe0, 0xfc, 0x1f, 0x83, 0x80, 0x00, 0x00, 0x0f, 0x0f, 0x08, 0x08, 0x3f, 0x3f, 0x08, 0x08, // char '4'
	0x3f, 0x3f, 0x21, 0x21, 0x21, 0x61, 0xc1, 0x81, 0x0c, 0x1c, 0x30, 0x20, 0x20, 0x30, 0x1f, 0x0f, // char '5'
	0xe0, 0xf8, 0x5c, 0x46, 0x43, 0xc1, 0x81, 0x01, 0x0f, 0x1f, 0x30, 0x20, 0x20, 0x30, 0x1f, 0x0f, // char '6'
	0x01, 0x01, 0x01, 0x01, 0x81, 0xf1, 0x7f, 0x0f, 0x00, 0x00, 0x00, 0x3c, 0x3f, 0x03, 0x00, 0x00, // char '7'
	0x1c, 0xbe, 0xe3, 0x41, 0x41, 0xe3, 0xbe, 0x1c, 0x0f, 0x1f, 0x30, 0x20, 0x20, 0x30, 0x1f, 0x0f, // char '8'
	0x3c, 0x7e, 0xc3, 0x81, 0x81, 0x83, 0xfe, 0xfc, 0x20, 0x20, 0x20, 0x30, 0x18, 0x0e, 0x07, 0x01, // char '9'
	0x00, 0x00, 0x00, 0x60, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00, 0x00, 0x00  // char ':
};
