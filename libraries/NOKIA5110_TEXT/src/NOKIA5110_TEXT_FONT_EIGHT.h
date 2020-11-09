// ASCII font file : huge  16 by 24 

// Define the ASCII table as Data array
// cols left to right, 0x00 is off, 0xFF is all on
// Each character is 16 bits wide,  3 byte height. 

//Numbers + . : only. type / for a space 


#ifndef NOKIA5110_TEXT_FONT_EIGHT_H
#define NOKIA5110_TEXT_FONT_EIGHT_H

const PROGMEM uint32_t ASCII_EIGHT[13][16] = {
			{0x000000,0x000000,0x000000,0x000000,0x000000,0x1FC000,0x3FE000,0x3FE000,0x3FE000,0x3FE000,0x3FE000,0x1FC000,0x000000,0x000000,0x000000,0x000000}, // .
			{0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000}, // /
			{0x000000,0x3FFFFC,0x7FFFFE,0x7FFFFE,0x7FFFFE,0x7FFFFE,0x7C003E,0x7C003E,0x7C003E,0x7C003E,0x7FFFFE,0x7FFFFE,0x7FFFFE,0x7FFFFE,0x3FFFFC,0x000000}, // 0
			{0x000000,0x000060,0x300070,0x380078,0x3C007C,0x3C001E,0x3C000E,0x3FFFFE,0x3FFFFE,0x3FFFFE,0x3FFFFE,0x3FFFFC,0x3C0000,0x3C0000,0x380000,0x000000}, // 1
			{0x000000,0x3FF81C,0x7FFC1E,0x7FFC1E,0x783C1E,0x783C1E,0x783C1E,0x783C1E,0x783C1E,0x783C1E,0x783C3E,0x781FFE,0x781FFE,0x381FFC,0x000000,0x000000}, // 2
			{0x000000,0x30000C,0x78181E,0x783C1E,0x783C1E,0x783C1E,0x783C1E,0x783C1E,0x783C1E,0x783C1E,0x7FFC3E,0x7FFFFE,0x7FFFFE,0x3FFFFC,0x000000,0x000000}, // 3
			{0x000000,0x001FFC,0x003FFE,0x003FFE,0x003FFC,0x003C00,0x003C00,0x003C00,0x003C00,0x003C00,0x3FFFFE,0x7FFFFE,0x7FFFFE,0x3FFFFC,0x000000,0x000000}, // 4
			{0x000000,0x380FFC,0x7C1FFE,0x7C1FFE,0x7C1FFE,0x7C1E1E,0x7C1E1E,0x7C1E1E,0x7C1E1E,0x7C1E1E,0x7FFE1E,0x7FFE1E,0x7FFE1E,0x3FFC1C,0x000000,0x000000}, // 5
			{0x000000,0x3FFFFC,0x7FFFFE,0x7FFFFE,0x7FFFFE,0x7E3E1E,0x7C1E1E,0x7C1E1E,0x7C1E1E,0x7C1E1E,0x7FFE1E,0x7FFE1E,0x7FFE1E,0x3FFC1C,0x000000,0x000000}, // 6
			{0x000000,0x00001C,0x00001E,0x00001E,0x00001E,0x00001E,0x000C1E,0x001E1E,0x001E1E,0x001E1E,0x3FFFFE,0x7FFFFE,0x7FFFFE,0x3FFFFC,0x000000,0x000000}, // 7
			{0x000000,0x3FFFFC,0x7FFFFE,0x7FFFFE,0x7FFFFE,0x7C1E1E,0x7C1E1E,0x7C1E1E,0x7C1E1E,0x7C1E1E,0x7FFFFE,0x7FFFFE,0x7FFFFE,0x3FFFFC,0x000000,0x000000}, // 8
			{0x000000,0x300FFC,0x7C1FFE,0x7C1FFE,0x7C1FFE,0x7C1E1E,0x7C1E1E,0x7C1E1E,0x7C1E1E,0x7C1E1E,0x7FFFFE,0x7FFFFE,0x7FFFFE,0x3FFFFC,0x000000,0x000000}, // 9
			{0x000000,0x000000,0x000000,0x000000,0x000000,0x1F81F8,0x3FC3FC,0x3FC3FC,0x3FC3FC,0x3FC3FC,0x3FC3FC,0x1F81F8,0x000000,0x000000,0x000000,0x000000} // :
};

#endif

