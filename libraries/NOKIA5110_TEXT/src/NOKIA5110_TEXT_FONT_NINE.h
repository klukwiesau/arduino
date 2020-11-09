// ASCII font file : Mega 16 by 32 

// Define the ASCII table as Data array
// cols left to right, 0x00 is off, 0xFF is all on
// Each character is 16 bits wide 4 byte height. 

// Numbers only + : . /

#ifndef NOKIA5110_TEXT_FONT_NINE_H
#define NOKIA5110_TEXT_FONT_NINE_H

const PROGMEM uint32_t ASCII_NINE[13][16] = {
			{0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x1FC00000,0x3FE00000,0x3FE00000,0x3FE00000,0x3FE00000,0x3FE00000,0x1FC00000,0x00000000,0x00000000,0x00000000,0x00000000}, // .
			{0x00000000,0x00000000,0x00000000,0x1E000000,0x07800000,0x01E00000,0x00780000,0x001E0000,0x00078000,0x0001E000,0x00007800,0x00001E00,0x00000780,0x000001E0,0x00000078,0x00000000}, // / 
			{0x00000000,0x3FFFFFF8,0x7FFFFFFC,0x7FFFFFFC,0x7FFFFFFC,0x7E0000FC,0x7C00007C,0x7C00007C,0x7C00007C,0x7C00007C,0x7E0000FC,0x7FFFFFFC,0x7FFFFFFC,0x7FFFFFFC,0x3FFFFFF8,0x00000000}, // 0
			{0x00000000,0x00000000,0x40000000,0x600000C0,0x70000060,0x70000070,0x70000038,0x7FFFFFF8,0x7FFFFFFC,0x7FFFFFFC,0x7FFFFFFC,0x7FFFFFF8,0x60000000,0x40000000,0x00000000,0x00000000}, // 1
			{0x00000000,0x3FFF8038,0x7FFFC07C,0x7FFFC07C,0x7FFFC07C,0x7FFFC07C,0x7C0FC07C,0x7C07C07C,0x7C07C07C,0x7C07C07C,0x7C07E0FC,0x7C07FFFC,0x7C07FFFC,0x7C07FFFC,0x3803FFF8,0x00000000}, // 2
			{0x00000000,0x38038038,0x7C07C07C,0x7C07C07C,0x7C07C07C,0x7C07C07C,0x7C07C07C,0x7C07C07C,0x7C07C07C,0x7C07C07C,0x7E0FE0FC,0x7FFFFFFC,0x7FFFFFFC,0x7FFFFFFC,0x3FFFFFF8,0x00000000}, // 3
			{0x00000000,0x0003FFF0,0x0007FFF8,0x0007FFF8,0x0007FFF0,0x0007C000,0x0007C000,0x0007C000,0x0007C000,0x0007C000,0x000FE000,0x3FFFFFF8,0x7FFFFFFC,0x7FFFFFFC,0x3FFFFFF8,0x00000000}, // 4
			{0x00000000,0x3803FFF8,0x7C07FFFC,0x7C07FFFC,0x7C07FFFC,0x7C07E0FC,0x7C07C07C,0x7C07C07C,0x7C07C07C,0x7C07C07C,0x7E0FC07C,0x7FFFC07C,0x7FFFC07C,0x7FFFC07C,0x3FFF8038,0x00000000}, // 5
			{0x00000000,0x3FFFFFF8,0x7FFFFFFC,0x7FFFFFFC,0x7FFFFFFC,0x7FFFE0FC,0x7C07C07C,0x7C07C07C,0x7C07C07C,0x7C07C07C,0x7E0FC07C,0x7FFFC07C,0x7FFFC07C,0x7FFFC07C,0x3FFF8038,0x00000000}, // 6
			{0x00000000,0x00000000,0x00000038,0x0000007C,0x0000007C,0x0000007C,0x0000607C,0x0000F07C,0x0000F07C,0x0000F07C,0x0000F07C,0x3FFFFFFC,0x7FFFFFFC,0x7FFFFFFC,0x3FFFFFF8,0x00000000}, // 7
			{0x00000000,0x3FFFFFF8,0x7FFFFFFC,0x7FFFFFFC,0x7FFFFFFC,0x7C07C07C,0x7C07C07C,0x7C07C07C,0x7C07C07C,0x7C07C07C,0x7C07C07C,0x7FFFFFFC,0x7FFFFFFC,0x7FFFFFFC,0x3FFFFFF8,0x00000000}, // 8
			{0x00000000,0x3803FFF8,0x7C07FFFC,0x7C07FFFC,0x7C07FFFC,0x7C07C07C,0x7C07C07C,0x7C07C07C,0x7C07C07C,0x7C07C07C,0x7E0FC07C,0x7FFFFFFC,0x7FFFFFFC,0x7FFFFFFC,0x3FFFFFF8,0x00000000}, // 9
			{0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x1F81F800,0x3FC3FC00,0x3FC3FC00,0x3FC3FC00,0x3FC3FC00,0x3FC3FC00,0x1F81F800,0x00000000,0x00000000,0x00000000,0x00000000} // :
};

#endif
