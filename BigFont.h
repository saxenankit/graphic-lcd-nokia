/*
    created with FontEditor written by H. Reddmann
    HaReddmann at t-online dot de

    File Name           : BigFont.h
    Date                : 6/1/2009
    Font size in bytes  : 0x0720, 1824
    Font width          : 14
    Font height         : 16
    Font first char     : 0x20
    Font last char      : 0x7E
    Font bits per pixel : 2
    Font is compressed  : true

    The font data are defined as

    struct _FONT_ {
     // common shared fields
       uint16_t   font_Size_in_Bytes_over_all_included_Size_it_self;
       uint8_t    font_Width_in_Pixel_for_fixed_drawing;
       uint8_t    font_Height_in_Pixel_for_all_Characters;
       uint8_t    font_Bits_per_Pixels;
                    // if MSB are set then font is a compressed font
       uint8_t    font_First_Char;
       uint8_t    font_Last_Char;
       uint8_t    font_Char_Widths[font_Last_Char - font_First_Char +1];
                    // for each character the separate width in pixels,
                    // characters < 128 have an implicit virtual right empty row
                    // characters with font_Char_Widths[] == 0 are undefined

     // if compressed font then additional fields
       uint8_t    font_Byte_Padding;
                    // each Char in the table are aligned in size to this value
       uint8_t    font_RLE_Table[3];
                    // Run Length Encoding Table for Decompression
       uint8_t    font_Char_Size_in_Bytes[font_Last_Char - font_First_Char +1];
                    // for each char the size in (bytes / font_Byte_Padding) are stored,
                    // this get us the table to seek to the right beginning of each char
                    // in the font_data[]. Withhelp of font_Byte_Padding we ensure that
                    // one byte is suitable to store character sizes greater 255

     // for compressed and uncompressed fonts
       uint8_t    font_data[];
                    // bit field of all characters
    }
*/

#include <inttypes.h>
#include <avr/pgmspace.h>

#ifndef BigFont_H
#define BigFont_H

#define BigFont_WIDTH 14
#define BigFont_HEIGHT 16

static uint8_t __attribute__ ((progmem)) BigFont[] = {
    0x96, 0x20, 0x0E, 0x10, 0x82, 0x20, 0x7E,
    0x05, 0x01, 0x03, 0x07, 0x05, 0x0A, 0x07, 0x01, 0x03, 0x03, 0x05, 0x05, 0x02, 0x04, 0x01, 0x04, 
    0x05, 0x03, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x01, 0x02, 0x05, 0x05, 0x05, 0x05, 
    0x0C, 0x09, 0x07, 0x08, 0x08, 0x07, 0x07, 0x08, 0x08, 0x01, 0x05, 0x07, 0x06, 0x09, 0x08, 0x08, 
    0x08, 0x08, 0x09, 0x07, 0x09, 0x08, 0x09, 0x0D, 0x08, 0x09, 0x06, 0x03, 0x04, 0x03, 0x05, 0x07, 
    0x02, 0x07, 0x06, 0x06, 0x06, 0x06, 0x03, 0x06, 0x05, 0x01, 0x02, 0x06, 0x01, 0x09, 0x05, 0x06, 
    0x06, 0x06, 0x03, 0x05, 0x03, 0x05, 0x07, 0x09, 0x06, 0x07, 0x04, 0x05, 0x01, 0x05, 0x07, 
    0x01, 0x02, 0x03, 0x07, 
    0x06, 0x03, 0x06, 0x13, 0x16, 0x25, 0x19, 0x03, 0x0A, 0x0A, 0x0F, 0x0B, 0x06, 0x08, 0x03, 0x0D, 
    0x11, 0x06, 0x16, 0x16, 0x0F, 0x15, 0x15, 0x0F, 0x18, 0x15, 0x04, 0x07, 0x10, 0x0F, 0x10, 0x11, 
    0x34, 0x1C, 0x1C, 0x1F, 0x19, 0x19, 0x14, 0x1F, 0x10, 0x02, 0x0C, 0x14, 0x0C, 0x18, 0x14, 0x20, 
    0x19, 0x21, 0x1D, 0x1E, 0x13, 0x13, 0x18, 0x1F, 0x19, 0x17, 0x18, 0x08, 0x0C, 0x08, 0x0C, 0x0E, 
    0x05, 0x18, 0x12, 0x13, 0x12, 0x16, 0x08, 0x17, 0x0B, 0x03, 0x05, 0x12, 0x02, 0x13, 0x0B, 0x13, 
    0x13, 0x11, 0x06, 0x11, 0x08, 0x0B, 0x14, 0x15, 0x15, 0x17, 0x0F, 0x10, 0x02, 0x10, 0x10, 
    0x33, 0x33, 0x33, 0x33, 0x33, 0x23, 0x72, 0x04, 0x24, 0x62, 0x34, 0x33, 0x63, 0x34, 0x01, 0x13, 
    0x34, 0x12, 0x14, 0x46, 0x13, 0x46, 0x13, 0x46, 0x61, 0x34, 0x61, 0x34, 0x61, 0x14, 0x34, 0x12, 
    0x34, 0x01, 0x12, 0x4C, 0x1C, 0xC4, 0x03, 0x8C, 0x80, 0x1C, 0xC8, 0x22, 0x67, 0x24, 0xC2, 0x18, 
    0x8C, 0x80, 0x3C, 0xC0, 0x14, 0x4C, 0x2C, 0x00, 0x82, 0x85, 0x23, 0x41, 0x41, 0x02, 0x4C, 0x22, 
    0x14, 0x24, 0x8C, 0x83, 0x85, 0xC1, 0x38, 0x22, 0x84, 0x23, 0xC2, 0x38, 0x12, 0xC8, 0x18, 0x58, 
    0x28, 0x82, 0x2C, 0x40, 0x41, 0x22, 0x24, 0x41, 0x41, 0x23, 0x81, 0x85, 0x01, 0x13, 0x4C, 0x3C, 
    0x58, 0x0C, 0x8C, 0x80, 0x2C, 0x42, 0xC2, 0x02, 0x24, 0x42, 0xC2, 0x24, 0x24, 0x82, 0xC5, 0x51, 
    0xC8, 0x33, 0x34, 0x43, 0x40, 0x02, 0x62, 0x34, 0x01, 0x12, 0x7C, 0x2C, 0xC2, 0x38, 0xC8, 0x02, 
    0x84, 0x13, 0x48, 0x42, 0x38, 0x81, 0x24, 0xC0, 0x38, 0xC8, 0x22, 0x7C, 0x1C, 0x02, 0x04, 0x48, 
    0x23, 0x91, 0x3C, 0x12, 0xD4, 0x33, 0xC9, 0x23, 0x42, 0x80, 0x34, 0x00, 0x03, 0x34, 0x03, 0x34, 
    0x22, 0x56, 0x23, 0x42, 0x33, 0x40, 0x03, 0x23, 0x41, 0xC0, 0x23, 0x42, 0x1C, 0x03, 0x34, 0x03, 
    0x34, 0x03, 0x34, 0x03, 0x34, 0x23, 0x41, 0x02, 0x23, 0x81, 0x4C, 0x13, 0xD8, 0xC4, 0x03, 0x4D, 
    0x8C, 0x13, 0xC4, 0x38, 0x02, 0x02, 0x6C, 0xC6, 0xC3, 0x28, 0x82, 0x2C, 0x42, 0x03, 0x24, 0xC2, 
    0x28, 0x82, 0x3C, 0x6C, 0xC6, 0x02, 0x02, 0x34, 0x03, 0x34, 0x73, 0x26, 0x02, 0x4C, 0x82, 0x5C, 
    0x22, 0x8C, 0x82, 0x1C, 0x24, 0x42, 0x02, 0x24, 0x24, 0xC2, 0x08, 0xC8, 0x02, 0x34, 0x4C, 0x2C, 
    0x41, 0x02, 0x02, 0x4C, 0x02, 0xC4, 0xC3, 0x28, 0x82, 0x2C, 0x42, 0x42, 0x02, 0x24, 0xC2, 0x08, 
    0xC8, 0x18, 0xC8, 0xC3, 0xC4, 0xC0, 0xC5, 0x02, 0x03, 0x4C, 0x23, 0xC2, 0x48, 0x23, 0x80, 0x84, 
    0x40, 0x23, 0x8C, 0x42, 0x13, 0x67, 0x02, 0x62, 0xC5, 0x40, 0x3C, 0x24, 0x8C, 0x81, 0x2C, 0x42, 
    0x42, 0x02, 0x24, 0x42, 0xC2, 0x18, 0xC8, 0x22, 0x24, 0xC0, 0xC5, 0x02, 0x02, 0x6C, 0xC6, 0xC3, 
    0x18, 0x48, 0x81, 0x2C, 0x42, 0x42, 0x02, 0x24, 0xC2, 0x18, 0x8C, 0x81, 0x3C, 0x4C, 0xC1, 0xC5, 
    0x02, 0x42, 0x33, 0x40, 0x02, 0x6D, 0x22, 0x14, 0x9D, 0x13, 0x04, 0x8C, 0x23, 0x51, 0x38, 0x02, 
    0x02, 0x4C, 0x0C, 0x5C, 0x3C, 0x8C, 0x80, 0x8C, 0x81, 0x2C, 0x42, 0x42, 0x02, 0x24, 0xC2, 0x08, 
    0xC8, 0x18, 0xC8, 0xC3, 0xC4, 0xC0, 0xC5, 0x02, 0x02, 0x5C, 0x1C, 0xC4, 0xC3, 0x18, 0xC8, 0x81, 
    0x2C, 0x42, 0x02, 0x24, 0x24, 0xC2, 0x18, 0x84, 0x81, 0x3C, 0x6C, 0xC6, 0x02, 0x22, 0x24, 0x41, 
    0x02, 0x23, 0x41, 0xC0, 0x43, 0x12, 0xC4, 0x01, 0x03, 0x34, 0xC3, 0xC8, 0x23, 0xC1, 0x08, 0xC8, 
    0x23, 0x8C, 0x82, 0x3C, 0x40, 0x28, 0x81, 0x24, 0x43, 0x40, 0x23, 0x42, 0x40, 0x23, 0x42, 0x40, 
    0x23, 0x42, 0x40, 0x23, 0x42, 0x40, 0x22, 0x02, 0x84, 0x12, 0x48, 0x03, 0x8C, 0x82, 0x3C, 0xC2, 
    0x08, 0xC8, 0x23, 0xC1, 0xC8, 0x33, 0x34, 0x02, 0x4C, 0x23, 0xC2, 0x38, 0x43, 0x82, 0x5C, 0x40, 
    0x22, 0x8C, 0x80, 0x3C, 0x12, 0x4C, 0x3C, 0x01, 0x02, 0xC8, 0x46, 0x8C, 0x83, 0x2C, 0xC2, 0x28, 
    0x81, 0x3C, 0xC0, 0x28, 0xC0, 0x23, 0x2C, 0x40, 0x02, 0x4C, 0x2C, 0x24, 0x40, 0xC2, 0x08, 0xC8, 
    0x41, 0x02, 0x24, 0x24, 0x14, 0x24, 0x40, 0x42, 0xC1, 0x42, 0x02, 0x2C, 0x86, 0x1C, 0x24, 0x80, 
    0x2C, 0x42, 0x80, 0x2C, 0x81, 0x2C, 0x80, 0x0C, 0x3C, 0xC8, 0xC6, 0x22, 0x23, 0xC0, 0x34, 0x02, 
    0x4D, 0x38, 0xC2, 0x84, 0x3C, 0xD1, 0x84, 0x41, 0x13, 0x84, 0x02, 0x34, 0xD1, 0x84, 0x41, 0x23, 
    0xC1, 0x84, 0x3C, 0xD3, 0x84, 0x33, 0xC0, 0x24, 0x72, 0x26, 0x42, 0x42, 0x02, 0x24, 0x42, 0x42, 
    0x02, 0x24, 0x42, 0x42, 0x02, 0x24, 0x42, 0x42, 0x02, 0x24, 0xC2, 0x08, 0xC8, 0x18, 0xC8, 0xC3, 
    0xC4, 0xC0, 0xC5, 0x02, 0x02, 0x68, 0x86, 0x83, 0x84, 0x02, 0x48, 0x28, 0x42, 0x28, 0x82, 0x24, 
    0x42, 0x03, 0x24, 0x42, 0x03, 0x24, 0x42, 0x28, 0x82, 0x24, 0x82, 0x84, 0x02, 0x48, 0x38, 0x48, 
    0x02, 0x84, 0x02, 0x72, 0x26, 0x42, 0x03, 0x24, 0x42, 0x03, 0x24, 0x42, 0x03, 0x24, 0x42, 0x03, 
    0x24, 0xC2, 0x28, 0x82, 0x3C, 0x8C, 0x02, 0xC8, 0x13, 0x6C, 0xC4, 0x12, 0x72, 0x26, 0x42, 0x42, 
    0x02, 0x24, 0x42, 0x42, 0x02, 0x24, 0x42, 0x42, 0x02, 0x24, 0x42, 0x42, 0x02, 0x24, 0x42, 0x42, 
    0x02, 0x24, 0x42, 0x03, 0x24, 0x72, 0x26, 0x42, 0x42, 0x23, 0x40, 0x42, 0x23, 0x40, 0x42, 0x23, 
    0x40, 0x42, 0x23, 0x40, 0x42, 0x23, 0x40, 0x23, 0x01, 0x02, 0x68, 0x86, 0x83, 0x84, 0x02, 0x48, 
    0x28, 0x42, 0x28, 0x82, 0x24, 0x42, 0x03, 0x24, 0x42, 0x03, 0x24, 0x42, 0x28, 0x14, 0xC8, 0x22, 
    0x48, 0x18, 0x14, 0x3C, 0x80, 0x14, 0x56, 0x02, 0x72, 0x36, 0x42, 0x33, 0x40, 0x33, 0x40, 0x33, 
    0x40, 0x33, 0x40, 0x33, 0x40, 0x23, 0x70, 0x26, 0x72, 0x26, 0x23, 0xC4, 0x33, 0x80, 0x3C, 0x03, 
    0x34, 0x83, 0x2C, 0x72, 0xC4, 0x02, 0x72, 0x36, 0x81, 0x84, 0x23, 0x81, 0x0C, 0x8C, 0x23, 0x48, 
    0x42, 0x38, 0xD0, 0x12, 0x8C, 0x43, 0x43, 0x3C, 0x03, 0x24, 0x72, 0x36, 0x03, 0x34, 0x03, 0x34, 
    0x03, 0x34, 0x03, 0x34, 0x03, 0x24, 0x42, 0x7C, 0x34, 0x48, 0x3D, 0x93, 0xC4, 0x33, 0x80, 0xC4, 
    0x33, 0x58, 0x23, 0x81, 0xC4, 0x23, 0x49, 0x3C, 0x82, 0xD4, 0x23, 0x40, 0x7C, 0x24, 0x72, 0x26, 
    0xC2, 0x84, 0x33, 0x58, 0x33, 0xC0, 0xC4, 0x33, 0x48, 0x3C, 0x03, 0x48, 0x38, 0x83, 0xC4, 0x22, 
    0x67, 0x02, 0x02, 0xC8, 0x46, 0x8C, 0x83, 0x8C, 0x02, 0xC8, 0x28, 0xC2, 0x28, 0x82, 0x2C, 0x42, 
    0x03, 0x24, 0x42, 0x03, 0x24, 0xC2, 0x28, 0x82, 0x2C, 0x82, 0x8C, 0x02, 0xC8, 0x38, 0xC8, 0x46, 
    0x8C, 0x02, 0x72, 0x26, 0x42, 0x02, 0x34, 0x42, 0x02, 0x34, 0x42, 0x02, 0x34, 0x42, 0x02, 0x34, 
    0x42, 0x18, 0x48, 0x23, 0x48, 0x49, 0x38, 0x02, 0x58, 0x38, 0x00, 0x02, 0xC8, 0x46, 0x8C, 0x83, 
    0x8C, 0x02, 0xC8, 0x28, 0xC2, 0x28, 0x82, 0x2C, 0x42, 0x03, 0x24, 0x42, 0x03, 0x24, 0xC2, 0x28, 
    0x41, 0xC8, 0x22, 0xC8, 0x28, 0x80, 0x34, 0x80, 0x6C, 0xC4, 0x40, 0x02, 0x72, 0x26, 0x42, 0x02, 
    0x34, 0x42, 0x02, 0x34, 0x42, 0x02, 0x34, 0x42, 0x02, 0x34, 0x42, 0x18, 0x48, 0x23, 0x48, 0x49, 
    0x8C, 0x23, 0x58, 0x08, 0x4C, 0x3C, 0x03, 0x48, 0x02, 0x02, 0x4C, 0x2C, 0xC4, 0xC3, 0x08, 0xC8, 
    0x82, 0x2C, 0x42, 0x82, 0x02, 0x24, 0x42, 0xC2, 0x02, 0x24, 0x42, 0x82, 0x2C, 0x24, 0xC2, 0x28, 
    0x8C, 0x80, 0x3C, 0x4C, 0xC2, 0xC4, 0x02, 0x42, 0x33, 0x40, 0x33, 0x40, 0x33, 0x40, 0x33, 0x70, 
    0x26, 0x42, 0x33, 0x40, 0x33, 0x40, 0x33, 0x40, 0x23, 0x01, 0x72, 0x8C, 0x33, 0xC8, 0x38, 0x83, 
    0x3C, 0x03, 0x34, 0x03, 0x34, 0x83, 0x3C, 0x22, 0xC8, 0x28, 0x72, 0x8C, 0x02, 0x42, 0x3C, 0x03, 
    0x48, 0x3D, 0x93, 0xC4, 0x33, 0x80, 0xC4, 0x33, 0x49, 0x23, 0x81, 0xC4, 0x23, 0x49, 0x3C, 0x82, 
    0xD4, 0x23, 0x40, 0x3C, 0x02, 0x42, 0x3D, 0x93, 0xD4, 0x33, 0x49, 0x3D, 0x93, 0x34, 0x92, 0xD4, 
    0x03, 0x49, 0x3D, 0x42, 0x3D, 0x93, 0xD4, 0x33, 0x49, 0x3D, 0x93, 0x34, 0x92, 0xD4, 0x03, 0x49, 
    0x3D, 0x42, 0x3D, 0x02, 0x42, 0x03, 0x34, 0x8C, 0x02, 0xC8, 0x13, 0xC8, 0xC1, 0x38, 0x12, 0x4C, 
    0x33, 0xC4, 0x23, 0x81, 0x1C, 0xC8, 0x13, 0x8C, 0x02, 0xC8, 0x43, 0x03, 0x24, 0x42, 0x38, 0x03, 
    0x8C, 0x33, 0x80, 0x3C, 0x03, 0x48, 0x33, 0x80, 0x56, 0x13, 0x48, 0x23, 0x82, 0x3C, 0x22, 0x8C, 
    0x23, 0x42, 0x38, 0x02, 0x42, 0xC3, 0x24, 0x42, 0x12, 0x48, 0x48, 0x22, 0x24, 0x40, 0x1C, 0x24, 
    0x42, 0xC1, 0x24, 0x40, 0x22, 0x84, 0x84, 0x12, 0x24, 0x42, 0x3C, 0x24, 0x72, 0x66, 0x42, 0x23, 
    0x40, 0x42, 0x23, 0x40, 0x42, 0x8C, 0x33, 0xD0, 0xC4, 0x38, 0x83, 0x4D, 0x8C, 0x33, 0xC8, 0x04, 
    0x42, 0x23, 0x40, 0x42, 0x23, 0x40, 0x72, 0x66, 0x82, 0x34, 0x22, 0xC8, 0x33, 0x34, 0x03, 0xC8, 
    0x33, 0x80, 0x34, 0x02, 0x33, 0x34, 0x03, 0x34, 0x03, 0x34, 0x03, 0x34, 0x03, 0x34, 0x03, 0x34, 
    0x03, 0x04, 0x42, 0x38, 0x03, 0x34, 0x02, 0xC3, 0xC0, 0xC4, 0x23, 0x8C, 0x8C, 0x80, 0x3C, 0x41, 
    0x40, 0x42, 0x13, 0x04, 0x24, 0x34, 0xC1, 0x48, 0x81, 0x3C, 0xC2, 0xC6, 0x33, 0x41, 0x02, 0x72, 
    0x36, 0x81, 0x2C, 0x8C, 0x13, 0x2C, 0xC1, 0x13, 0x24, 0x41, 0x13, 0x8C, 0x82, 0x3C, 0xC2, 0xC6, 
    0x02, 0xC3, 0xC6, 0x23, 0x8C, 0x82, 0x3C, 0x41, 0x12, 0x34, 0x41, 0x12, 0x34, 0xC1, 0x28, 0xC8, 
    0x23, 0x2C, 0x2C, 0x00, 0xC3, 0xC6, 0x23, 0x8C, 0x82, 0x3C, 0x41, 0x12, 0x34, 0xC1, 0x12, 0x3C, 
    0x81, 0x2C, 0x8C, 0x22, 0x67, 0x02, 0xC3, 0xC6, 0x23, 0x8C, 0x40, 0x80, 0x3C, 0x41, 0x41, 0x41, 
    0x13, 0x14, 0x14, 0x34, 0xC1, 0x08, 0x04, 0xC8, 0x23, 0x5C, 0xC0, 0x02, 0x22, 0x34, 0x12, 0x78, 
    0x25, 0x42, 0x41, 0x13, 0xC3, 0xC6, 0x23, 0x8C, 0x82, 0x1C, 0x24, 0x42, 0x12, 0x14, 0x24, 0xC2, 
    0x12, 0x1C, 0x24, 0x82, 0x2C, 0x8C, 0x80, 0x2C, 0x72, 0xC4, 0x00, 0x72, 0x36, 0x81, 0x3C, 0xC3, 
    0x33, 0xC0, 0x38, 0x03, 0x6C, 0x25, 0x42, 0x71, 0x02, 0x33, 0x40, 0x42, 0x71, 0x85, 0x72, 0x36, 
    0x02, 0x4C, 0x23, 0xC2, 0x48, 0x3C, 0x02, 0x8C, 0x81, 0x3C, 0x41, 0x28, 0x80, 0x3C, 0x03, 0x24, 
    0x72, 0x26, 0x22, 0x37, 0xC2, 0x33, 0x3C, 0x03, 0x8C, 0x33, 0xC0, 0x56, 0x23, 0x3C, 0xC3, 0x33, 
    0xC0, 0x38, 0x03, 0x6C, 0x25, 0x22, 0x37, 0xC2, 0x33, 0x3C, 0x03, 0x8C, 0x33, 0xC0, 0x56, 0x02, 
    0xC3, 0xC6, 0x23, 0x8C, 0x82, 0x3C, 0x41, 0x12, 0x34, 0x41, 0x12, 0x34, 0xC1, 0x28, 0xC8, 0x23, 
    0x6C, 0x2C, 0x00, 0x22, 0x67, 0x22, 0xC8, 0xC2, 0x38, 0xC1, 0x12, 0x3C, 0x41, 0x12, 0x34, 0xC1, 
    0x28, 0xC8, 0x23, 0x6C, 0x2C, 0x00, 0xC3, 0xC6, 0x23, 0x8C, 0x82, 0x3C, 0x41, 0x12, 0x34, 0xC1, 
    0x12, 0x3C, 0x81, 0x2C, 0x8C, 0x13, 0x67, 0x22, 0x37, 0xC2, 0x33, 0x3C, 0x01, 0xD3, 0xC1, 0x23, 
    0x9C, 0x0C, 0xC8, 0x13, 0x14, 0x14, 0x34, 0xC1, 0x08, 0x9C, 0x3C, 0xC2, 0xD1, 0x02, 0x22, 0x34, 
    0x22, 0x47, 0x38, 0x41, 0x12, 0x24, 0x22, 0x56, 0x3C, 0x03, 0xC8, 0x33, 0xC0, 0x33, 0x3C, 0x72, 
    0x02, 0x22, 0x84, 0x33, 0xC0, 0xC4, 0x33, 0x80, 0xC4, 0x33, 0x80, 0x34, 0x12, 0x48, 0x3C, 0x02, 
    0x4C, 0x3C, 0x12, 0x84, 0x03, 0x22, 0xD4, 0x33, 0x49, 0x3D, 0x93, 0x34, 0x92, 0xD4, 0x23, 0xD4, 
    0x33, 0x49, 0x3D, 0x93, 0x34, 0x92, 0xD4, 0x23, 0xD4, 0x03, 0x22, 0x84, 0x82, 0x34, 0xC2, 0x08, 
    0xC8, 0x23, 0xC1, 0x48, 0x23, 0x42, 0xC8, 0x23, 0xC1, 0x08, 0xC8, 0x23, 0x84, 0x82, 0x24, 0x22, 
    0x84, 0x43, 0xC3, 0xC4, 0x02, 0xC8, 0x03, 0x49, 0x0C, 0xC8, 0x38, 0x02, 0x58, 0x23, 0x49, 0x3C, 
    0x02, 0x4C, 0x3C, 0x12, 0x84, 0x03, 0x22, 0x24, 0xC8, 0x34, 0x41, 0xD1, 0x40, 0x13, 0x04, 0x1D, 
    0x34, 0x41, 0x8C, 0x42, 0x02, 0x13, 0x34, 0x83, 0x8C, 0x13, 0x6C, 0x0C, 0x6C, 0x2C, 0xC0, 0x38, 
    0x81, 0x2C, 0x34, 0x02, 0x04, 0x72, 0x66, 0x42, 0x23, 0x40, 0xC2, 0x38, 0x81, 0x2C, 0xC0, 0xC6, 
    0xC0, 0xC6, 0x13, 0xC8, 0x38, 0x43, 0x22, 0x02, 0x4C, 0x23, 0xC2, 0x38, 0x43, 0x33, 0x41, 0x33, 
    0x41, 0x33, 0xC8, 0x23, 0x42, 0x3C, 0x02
};

#endif
