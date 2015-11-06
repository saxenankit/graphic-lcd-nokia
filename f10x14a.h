/*
    created with FontEditor written by H. Reddmann
    HaReddmann at t-online dot de

    File Name           : f10x14a.h
    Date                : 6/1/2009
    Font size in bytes  : 0x08AE, 2222
    Font width          : 15
    Font height         : 15
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

#ifndef f10x14a_H
#define f10x14a_H

#define f10x14a_WIDTH 15
#define f10x14a_HEIGHT 15

static uint8_t __attribute__ ((progmem)) f10x14a[] = {
    0x7D, 0xAE, 0x0F, 0x0F, 0x82, 0x20, 0x7E,
    0x05, 0x02, 0x05, 0x09, 0x08, 0x0C, 0x0A, 0x02, 0x03, 0x03, 0x06, 0x08, 0x03, 0x06, 0x02, 0x05, 
    0x07, 0x04, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x02, 0x03, 0x08, 0x08, 0x08, 0x07, 
    0x0E, 0x0A, 0x09, 0x0A, 0x0A, 0x09, 0x08, 0x0B, 0x0A, 0x02, 0x07, 0x0A, 0x07, 0x0C, 0x0A, 0x0B, 
    0x09, 0x0B, 0x0B, 0x09, 0x08, 0x0A, 0x0A, 0x0E, 0x0A, 0x0A, 0x08, 0x04, 0x05, 0x04, 0x08, 0x0A, 
    0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x06, 0x07, 0x07, 0x02, 0x03, 0x07, 0x02, 0x0C, 0x07, 0x07, 
    0x07, 0x07, 0x05, 0x07, 0x05, 0x07, 0x08, 0x0C, 0x08, 0x08, 0x07, 0x04, 0x02, 0x04, 0x08, 
    0x01, 0x02, 0x04, 0x07, 
    0x06, 0x06, 0x0B, 0x16, 0x22, 0x2E, 0x27, 0x04, 0x0A, 0x0A, 0x13, 0x0D, 0x08, 0x09, 0x05, 0x0E, 
    0x13, 0x0A, 0x1C, 0x1E, 0x11, 0x1F, 0x20, 0x14, 0x1D, 0x20, 0x05, 0x0A, 0x1B, 0x1C, 0x1B, 0x19, 
    0x46, 0x1C, 0x1E, 0x21, 0x1B, 0x19, 0x12, 0x2A, 0x11, 0x04, 0x10, 0x1E, 0x0C, 0x1C, 0x1A, 0x22, 
    0x17, 0x24, 0x1D, 0x25, 0x0D, 0x18, 0x19, 0x27, 0x2A, 0x1A, 0x20, 0x09, 0x0F, 0x09, 0x15, 0x14, 
    0x06, 0x1B, 0x13, 0x14, 0x14, 0x18, 0x0F, 0x1A, 0x0F, 0x06, 0x0A, 0x15, 0x04, 0x18, 0x0F, 0x14, 
    0x13, 0x13, 0x0C, 0x1A, 0x0D, 0x0F, 0x14, 0x22, 0x1D, 0x17, 0x19, 0x0E, 0x03, 0x0E, 0x11, 
    0x33, 0x33, 0x33, 0x33, 0x33, 0x02, 0x70, 0x04, 0x25, 0x47, 0x50, 0x01, 0x50, 0x34, 0x02, 0x45, 
    0x33, 0x23, 0x51, 0x34, 0x02, 0x45, 0x23, 0x42, 0x01, 0x34, 0x01, 0x14, 0x60, 0x73, 0x24, 0x47, 
    0x63, 0x01, 0x36, 0x47, 0x72, 0x34, 0x16, 0x40, 0x13, 0x40, 0x01, 0x24, 0x01, 0xC1, 0xC4, 0x42, 
    0x2C, 0xC0, 0x45, 0x1C, 0x80, 0xC4, 0x42, 0x08, 0x58, 0x01, 0x48, 0x01, 0x67, 0x15, 0x67, 0x15, 
    0x40, 0x18, 0x50, 0x08, 0x48, 0xC2, 0x84, 0x01, 0x5C, 0xC4, 0x02, 0x4C, 0xC2, 0xC4, 0x02, 0xC1, 
    0xC5, 0x13, 0xC0, 0xC6, 0x13, 0x84, 0x81, 0x14, 0xC0, 0x24, 0x84, 0x81, 0x14, 0x5C, 0xC2, 0xC6, 
    0x45, 0x28, 0xC1, 0xC5, 0x85, 0x13, 0x80, 0xC5, 0xC5, 0x12, 0x58, 0xC4, 0xC6, 0x52, 0x1C, 0x84, 
    0x81, 0x24, 0xC4, 0x01, 0x84, 0x81, 0x34, 0xC1, 0xC6, 0x13, 0xC0, 0xC5, 0x02, 0xC3, 0xC5, 0x12, 
    0x4C, 0x0C, 0x6C, 0x2C, 0x5C, 0xC4, 0x84, 0x81, 0x24, 0x84, 0x80, 0x25, 0x24, 0x84, 0x80, 0x85, 
    0x81, 0x24, 0x5C, 0xD4, 0x84, 0x80, 0x24, 0xC0, 0xC4, 0xC1, 0x45, 0x38, 0x01, 0x36, 0x42, 0x08, 
    0x4C, 0x33, 0x14, 0x00, 0x60, 0x23, 0x36, 0x01, 0x84, 0x23, 0x48, 0x5C, 0x38, 0x58, 0x1C, 0x7C, 
    0xC5, 0x01, 0xC1, 0x57, 0x1C, 0x5C, 0x38, 0x58, 0x4C, 0x38, 0x82, 0x04, 0x41, 0x80, 0x34, 0x42, 
    0x48, 0x38, 0x01, 0x45, 0x38, 0x52, 0x84, 0x23, 0x40, 0x48, 0x38, 0x42, 0x80, 0x34, 0x01, 0x12, 
    0x34, 0x43, 0x33, 0x34, 0x72, 0x03, 0x37, 0x42, 0x33, 0x34, 0x43, 0x03, 0x23, 0x80, 0x34, 0x52, 
    0xC4, 0x23, 0xC5, 0x01, 0x43, 0x33, 0x34, 0x43, 0x33, 0x34, 0x43, 0x33, 0x34, 0x13, 0x50, 0x23, 
    0x51, 0x01, 0x13, 0xC8, 0x34, 0x81, 0x6C, 0x12, 0x68, 0x38, 0x45, 0x3D, 0x01, 0xC4, 0x23, 0x00, 
    0xC1, 0xC7, 0x02, 0x7C, 0xC5, 0x42, 0x38, 0x48, 0x42, 0x13, 0x24, 0x84, 0x83, 0x24, 0x7C, 0xC5, 
    0x02, 0x7C, 0x2C, 0x01, 0x34, 0x12, 0x4C, 0x23, 0xC0, 0x57, 0x24, 0x67, 0x01, 0xC1, 0x24, 0x51, 
    0xC2, 0x25, 0x50, 0x24, 0x84, 0x02, 0x4C, 0x48, 0x42, 0x02, 0xC4, 0x41, 0x42, 0x18, 0x80, 0x14, 
    0x40, 0xC2, 0x46, 0x42, 0x02, 0x5C, 0x2C, 0x40, 0x01, 0xC1, 0x24, 0x40, 0x2C, 0xC0, 0x84, 0x02, 
    0x48, 0x2C, 0x84, 0x01, 0x14, 0x80, 0x24, 0x24, 0x24, 0x24, 0x84, 0x81, 0x84, 0x81, 0x24, 0x6C, 
    0x6C, 0x2C, 0xC0, 0xC5, 0xC0, 0xC5, 0x02, 0x12, 0x58, 0x23, 0x4C, 0x48, 0x13, 0x48, 0x1C, 0x34, 
    0x40, 0x2C, 0x34, 0x67, 0x72, 0x36, 0x42, 0x12, 0xC1, 0x45, 0x1C, 0xC4, 0x02, 0x5C, 0xC4, 0x14, 
    0xC5, 0x42, 0x18, 0x84, 0x01, 0x48, 0x42, 0x01, 0x24, 0x40, 0x42, 0x01, 0x84, 0x01, 0x48, 0x42, 
    0x01, 0x6C, 0xC4, 0x42, 0xC2, 0x45, 0x2C, 0xC1, 0x45, 0x5C, 0xC4, 0x02, 0x5C, 0xC4, 0x46, 0x2C, 
    0x84, 0x41, 0x18, 0x80, 0x24, 0x14, 0x40, 0x02, 0x24, 0x84, 0x41, 0x18, 0x80, 0x24, 0x4C, 0x08, 
    0x6C, 0xC4, 0x02, 0x4C, 0xC1, 0x45, 0x2C, 0x40, 0x33, 0x34, 0x43, 0x12, 0x58, 0x24, 0x14, 0x80, 
    0x56, 0x42, 0x80, 0xC5, 0x38, 0x50, 0xC4, 0x23, 0xC4, 0x23, 0x00, 0xC1, 0xC5, 0xC0, 0xC5, 0x02, 
    0x6C, 0x6C, 0x2C, 0x84, 0x81, 0x84, 0x81, 0x24, 0x24, 0x24, 0x24, 0x84, 0x81, 0x84, 0x81, 0x24, 
    0x6C, 0x6C, 0x2C, 0xC0, 0xC5, 0xC0, 0xC5, 0x02, 0xC1, 0x45, 0x1C, 0xC4, 0x02, 0x6C, 0xC4, 0x80, 
    0xC4, 0x42, 0x18, 0x80, 0x14, 0x48, 0x42, 0x02, 0x14, 0x40, 0x42, 0x18, 0x80, 0x14, 0x48, 0xC2, 
    0x46, 0x5C, 0xC4, 0x02, 0x5C, 0xC4, 0x45, 0x2C, 0x52, 0x52, 0x53, 0x52, 0x01, 0x23, 0x80, 0x24, 
    0x50, 0x52, 0xC4, 0x02, 0x25, 0xC5, 0x01, 0x12, 0x34, 0x12, 0x48, 0x38, 0x02, 0x04, 0x34, 0x82, 
    0x04, 0x84, 0x13, 0x40, 0x18, 0x34, 0x81, 0x14, 0x40, 0x38, 0x40, 0x18, 0x80, 0x34, 0x40, 0x02, 
    0x24, 0x00, 0x42, 0x01, 0x34, 0x01, 0x14, 0x40, 0x13, 0x40, 0x01, 0x34, 0x01, 0x14, 0x40, 0x13, 
    0x40, 0x01, 0x34, 0x01, 0x14, 0x40, 0x13, 0x40, 0x01, 0x34, 0x01, 0x14, 0x40, 0x12, 0x01, 0x24, 
    0x40, 0x03, 0x84, 0x01, 0x48, 0x03, 0x48, 0x01, 0x84, 0x13, 0x84, 0x80, 0x34, 0x01, 0x48, 0x40, 
    0x38, 0x42, 0x48, 0x23, 0x80, 0x84, 0x23, 0x41, 0x03, 0xC1, 0x34, 0x02, 0x8C, 0x34, 0x02, 0x84, 
    0x01, 0x58, 0x50, 0x42, 0x01, 0x58, 0x04, 0x25, 0x84, 0x80, 0x84, 0x13, 0x8C, 0x85, 0x23, 0x4C, 
    0x3C, 0x01, 0xC2, 0xC7, 0x02, 0x4C, 0x4B, 0x1C, 0xC0, 0x84, 0x83, 0xC4, 0xC0, 0x84, 0xC0, 0x46, 
    0x81, 0x04, 0x84, 0xC0, 0xA4, 0x48, 0x41, 0x40, 0x41, 0x28, 0x40, 0x41, 0x40, 0x41, 0x12, 0x14, 
    0x04, 0x14, 0x24, 0x80, 0x14, 0x04, 0x14, 0x24, 0x48, 0x1C, 0x04, 0x14, 0x4C, 0x59, 0x4C, 0x41, 
    0x40, 0x08, 0xC4, 0xC5, 0x41, 0x41, 0xC0, 0x84, 0x02, 0x48, 0x0C, 0x48, 0xC1, 0x84, 0x45, 0x48, 
    0x0C, 0x48, 0x1C, 0xC0, 0x46, 0x1C, 0xC4, 0x00, 0x13, 0x5C, 0x13, 0x6D, 0xD3, 0xC5, 0x38, 0x5C, 
    0xC4, 0x40, 0x53, 0x2C, 0x34, 0xC5, 0x42, 0x03, 0x5C, 0xC4, 0x40, 0x13, 0xD0, 0xC5, 0x38, 0xD2, 
    0x36, 0x02, 0x5C, 0x01, 0x70, 0x26, 0x67, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 
    0x42, 0x42, 0x42, 0x42, 0x08, 0x58, 0x18, 0x48, 0xC2, 0x45, 0x4D, 0x4D, 0x2C, 0xC0, 0xC4, 0xC1, 
    0xC5, 0x02, 0x01, 0x5D, 0xD4, 0xC3, 0xC7, 0x02, 0x4C, 0x28, 0x80, 0xC4, 0x42, 0x38, 0x48, 0x42, 
    0x13, 0x24, 0x34, 0x41, 0x42, 0x13, 0x24, 0x84, 0x83, 0x24, 0x4C, 0x28, 0x80, 0xC4, 0x02, 0x4C, 
    0x02, 0xC4, 0x02, 0x70, 0x26, 0x67, 0x42, 0x13, 0x24, 0x34, 0x41, 0x42, 0x13, 0x24, 0x34, 0x41, 
    0x42, 0x3C, 0x4C, 0xC2, 0xC4, 0x02, 0x4C, 0x2C, 0xC0, 0xC7, 0xC3, 0x46, 0x2C, 0x00, 0x70, 0x26, 
    0x67, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 
    0x42, 0x42, 0x42, 0x42, 0x13, 0x14, 0x00, 0x70, 0x26, 0x67, 0x42, 0x42, 0x13, 0x24, 0x34, 0x41, 
    0x42, 0x13, 0x24, 0x34, 0x41, 0x42, 0x13, 0x34, 0x12, 0x01, 0x5D, 0xD4, 0xC3, 0xC7, 0x02, 0x4C, 
    0x28, 0x80, 0xC4, 0x42, 0x38, 0x48, 0x42, 0x13, 0x24, 0x24, 0x40, 0x01, 0x24, 0x24, 0x40, 0x01, 
    0x24, 0x84, 0x42, 0x81, 0x24, 0x4C, 0x18, 0x40, 0x80, 0xC4, 0x02, 0x4C, 0x01, 0x45, 0x3C, 0x1C, 
    0x60, 0x14, 0x00, 0x70, 0x26, 0x67, 0x13, 0x34, 0x43, 0x33, 0x34, 0x43, 0x33, 0x34, 0x43, 0x13, 
    0x67, 0x72, 0x16, 0x00, 0x70, 0x26, 0x67, 0x01, 0x13, 0xC4, 0x23, 0x51, 0x3C, 0x12, 0x48, 0x33, 
    0x34, 0x12, 0x48, 0x72, 0x45, 0x2C, 0x57, 0x2C, 0x70, 0x26, 0x67, 0x13, 0x35, 0x02, 0x48, 0x23, 
    0x80, 0x85, 0x13, 0x80, 0x94, 0x84, 0x03, 0x48, 0x18, 0x48, 0x28, 0x51, 0x28, 0x48, 0x28, 0x40, 
    0x28, 0x81, 0x35, 0x12, 0x48, 0x01, 0x70, 0x26, 0x67, 0x33, 0x34, 0x43, 0x33, 0x34, 0x43, 0x33, 
    0x14, 0x00, 0x70, 0x26, 0x67, 0x82, 0xC5, 0x23, 0x81, 0x45, 0x3D, 0x92, 0xC5, 0x23, 0x91, 0x35, 
    0x92, 0x35, 0x90, 0xC5, 0x03, 0x58, 0xD4, 0x83, 0xC5, 0x23, 0x67, 0x72, 0x16, 0x00, 0x70, 0x26, 
    0x67, 0xC2, 0xC4, 0x38, 0x02, 0x5C, 0x8C, 0x23, 0xC8, 0x85, 0x23, 0xD0, 0xC4, 0x38, 0x02, 0x5C, 
    0x38, 0x02, 0x4D, 0x2C, 0x67, 0x72, 0x16, 0x00, 0x01, 0x5D, 0xD4, 0xC3, 0xC7, 0x02, 0x4C, 0x28, 
    0x80, 0xC4, 0x42, 0x38, 0x48, 0x42, 0x13, 0x24, 0x34, 0x41, 0x42, 0x13, 0x24, 0x84, 0x83, 0x24, 
    0x4C, 0x28, 0x80, 0xC4, 0x02, 0x7C, 0x3C, 0x5D, 0xD4, 0x02, 0x70, 0x26, 0x67, 0x42, 0x42, 0x13, 
    0x24, 0x34, 0x41, 0x42, 0x13, 0x24, 0x34, 0x41, 0x18, 0x48, 0x13, 0x6C, 0x3C, 0x01, 0x5C, 0x3C, 
    0x01, 0x01, 0x5D, 0xD4, 0xC3, 0xC7, 0x02, 0x4C, 0x28, 0x80, 0xC4, 0x42, 0x38, 0x48, 0x42, 0x13, 
    0x24, 0x34, 0x04, 0x24, 0x34, 0x45, 0x42, 0x38, 0x48, 0xC2, 0x84, 0x02, 0x58, 0x02, 0x7C, 0x5C, 
    0x02, 0x5D, 0xD4, 0x41, 0x01, 0x70, 0x26, 0x67, 0x42, 0x42, 0x13, 0x24, 0x34, 0x41, 0x42, 0x13, 
    0x24, 0x34, 0x41, 0x18, 0x58, 0x03, 0x6C, 0x5C, 0x3C, 0x5C, 0x1C, 0x58, 0x3C, 0x12, 0x48, 0x33, 
    0x14, 0x00, 0xC1, 0xC5, 0x01, 0xC4, 0x02, 0x6C, 0x1C, 0x48, 0x2C, 0x84, 0x81, 0x14, 0x80, 0x24, 
    0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x84, 0x01, 0x84, 0x81, 0x24, 0x4C, 0x18, 
    0x6C, 0x2C, 0xC0, 0x14, 0xC0, 0xC5, 0x02, 0x40, 0x33, 0x34, 0x43, 0x33, 0x67, 0x72, 0x26, 0x34, 
    0x43, 0x33, 0x34, 0x12, 0x70, 0xC4, 0x12, 0x57, 0x3C, 0x12, 0x48, 0x3C, 0x12, 0x48, 0x33, 0x34, 
    0x43, 0x23, 0x81, 0x34, 0x02, 0x48, 0x2C, 0x57, 0x2C, 0x70, 0xC4, 0x02, 0x50, 0x3C, 0x02, 0xD6, 
    0x23, 0x5D, 0x3D, 0x02, 0x5C, 0xC4, 0x23, 0xC1, 0x35, 0x02, 0x5C, 0x13, 0x5C, 0xC4, 0xD3, 0xD5, 
    0x63, 0x3C, 0x01, 0xC5, 0x23, 0x50, 0xCD, 0x13, 0x60, 0xD5, 0x3C, 0x82, 0x45, 0x3D, 0x02, 0x58, 
    0x13, 0x58, 0xD4, 0x02, 0x68, 0xCD, 0x12, 0xD5, 0x23, 0xD5, 0x23, 0x80, 0xD6, 0x3C, 0x82, 0x45, 
    0x3D, 0x02, 0x58, 0x13, 0x58, 0xD4, 0x62, 0xD5, 0x2C, 0x51, 0xCD, 0x13, 0x40, 0x38, 0x48, 0x82, 
    0x84, 0x02, 0x48, 0x28, 0x80, 0x84, 0x01, 0x48, 0x38, 0x48, 0x08, 0x48, 0x38, 0x81, 0xC4, 0x84, 
    0x13, 0x80, 0xC4, 0x84, 0x13, 0x48, 0x08, 0x48, 0x38, 0x48, 0x18, 0x80, 0x84, 0x02, 0x48, 0x28, 
    0x80, 0x84, 0x42, 0x38, 0x48, 0x01, 0x40, 0x38, 0x12, 0x48, 0x3C, 0x12, 0x48, 0x3C, 0x12, 0x48, 
    0x3C, 0x12, 0x78, 0x83, 0x27, 0x81, 0xC4, 0x23, 0x48, 0x3C, 0x82, 0xC4, 0x23, 0x40, 0x38, 0x02, 
    0x40, 0xC3, 0x25, 0x24, 0x80, 0x85, 0x24, 0x24, 0x48, 0x1C, 0x24, 0x14, 0x80, 0xC4, 0x01, 0x24, 
    0x14, 0x4C, 0x2C, 0x24, 0x04, 0x4C, 0x28, 0x40, 0x42, 0x4C, 0x28, 0x41, 0x52, 0x38, 0x14, 0x00, 
    0x70, 0x07, 0x77, 0x40, 0x23, 0x40, 0x40, 0x23, 0x40, 0x40, 0x3C, 0x12, 0x45, 0x3D, 0x02, 0x68, 
    0x38, 0x02, 0xC8, 0x36, 0x02, 0xC8, 0x14, 0x00, 0x40, 0x23, 0x40, 0x40, 0x23, 0x40, 0x70, 0x07, 
    0x77, 0x02, 0x4C, 0x23, 0x5D, 0x13, 0xC0, 0x85, 0x13, 0x50, 0x38, 0x02, 0x85, 0x23, 0xC1, 0x85, 
    0x23, 0xD0, 0x35, 0x12, 0x4C, 0x03, 0x23, 0x51, 0x23, 0x51, 0x23, 0x51, 0x23, 0x51, 0x23, 0x51, 
    0x23, 0x51, 0x23, 0x51, 0x23, 0x51, 0x23, 0x51, 0x23, 0x51, 0x40, 0x33, 0x48, 0x33, 0x34, 0x02, 
    0x02, 0x14, 0x4C, 0x3C, 0x40, 0x08, 0x5C, 0xC4, 0x43, 0x41, 0x08, 0x48, 0x43, 0x41, 0x01, 0x34, 
    0x84, 0x40, 0x08, 0x48, 0xC3, 0x56, 0x3C, 0xC0, 0xC6, 0x14, 0x00, 0x70, 0x26, 0x45, 0x68, 0x85, 
    0x43, 0x28, 0x48, 0x43, 0x12, 0x34, 0x84, 0x82, 0x34, 0x6C, 0xC5, 0x03, 0x6C, 0x2C, 0x02, 0x6C, 
    0x3C, 0xC0, 0x56, 0x3C, 0x84, 0x82, 0x34, 0x24, 0x41, 0x43, 0x12, 0x34, 0x84, 0x82, 0x34, 0x40, 
    0x42, 0x02, 0x02, 0x6C, 0x3C, 0xC0, 0x56, 0x3C, 0x84, 0x82, 0x34, 0x24, 0x41, 0x43, 0x28, 0x48, 
    0x52, 0x84, 0x56, 0x28, 0x67, 0x01, 0x02, 0x6C, 0x3C, 0xC0, 0x56, 0x3C, 0x84, 0x40, 0x81, 0x34, 
    0x14, 0x14, 0x40, 0x43, 0x41, 0x01, 0x34, 0x84, 0x40, 0x81, 0x34, 0x50, 0x14, 0x24, 0x42, 0x23, 
    0xC0, 0x57, 0xC2, 0x57, 0x24, 0x84, 0x40, 0x23, 0x14, 0x34, 0x42, 0x23, 0x01, 0x02, 0x6C, 0x1C, 
    0x24, 0xC0, 0x56, 0x0C, 0x48, 0x42, 0x28, 0x48, 0x41, 0x42, 0x12, 0x14, 0x24, 0x84, 0x82, 0x04, 
    0x48, 0x82, 0x56, 0x58, 0x2C, 0x57, 0x0C, 0x70, 0x26, 0x67, 0x43, 0x38, 0x12, 0x34, 0x43, 0x38, 
    0x12, 0x7C, 0x03, 0x6C, 0x15, 0x00, 0x50, 0x70, 0x24, 0x05, 0x47, 0x01, 0x23, 0x81, 0x04, 0x05, 
    0x57, 0xC4, 0x50, 0x70, 0xC5, 0x00, 0x70, 0x26, 0x67, 0x13, 0x50, 0x23, 0x80, 0x85, 0x13, 0x80, 
    0x94, 0x84, 0x03, 0x48, 0x18, 0x48, 0x38, 0x84, 0x82, 0x14, 0x00, 0x70, 0x26, 0x67, 0x01, 0x72, 
    0x34, 0x78, 0x43, 0x38, 0x12, 0x34, 0x43, 0x38, 0x12, 0x78, 0x83, 0x37, 0x84, 0x23, 0x41, 0x33, 
    0x84, 0x23, 0xC1, 0x37, 0xC0, 0x56, 0x01, 0x72, 0x34, 0x78, 0x43, 0x38, 0x12, 0x34, 0x43, 0x38, 
    0x12, 0x7C, 0x03, 0x6C, 0x15, 0x00, 0x02, 0x6C, 0x3C, 0xC0, 0x56, 0x3C, 0x84, 0x82, 0x34, 0x24, 
    0x41, 0x43, 0x28, 0x40, 0xC3, 0x56, 0x3C, 0xC0, 0xC6, 0x02, 0x72, 0x26, 0x68, 0x85, 0x45, 0x42, 
    0x28, 0x48, 0x43, 0x12, 0x34, 0x84, 0x82, 0x34, 0x6C, 0xC5, 0x03, 0x6C, 0x2C, 0x02, 0x6C, 0x3C, 
    0xC0, 0x56, 0x3C, 0x84, 0x82, 0x34, 0x24, 0x41, 0x43, 0x28, 0x48, 0x83, 0x56, 0x58, 0x24, 0x67, 
    0x72, 0x34, 0xC0, 0x56, 0x83, 0x34, 0x12, 0x84, 0x23, 0x41, 0x13, 0x00, 0x02, 0x4C, 0x01, 0x34, 
    0xC0, 0x45, 0x81, 0x34, 0x94, 0x1C, 0x40, 0x43, 0x41, 0x1C, 0x34, 0x14, 0xC0, 0x49, 0x43, 0x18, 
    0x45, 0x3C, 0x40, 0x01, 0xC4, 0x02, 0x42, 0x23, 0x70, 0xC4, 0x12, 0x57, 0x3C, 0x24, 0x80, 0x34, 
    0x24, 0x41, 0x01, 0x62, 0xC5, 0x03, 0xC7, 0x23, 0x81, 0x34, 0x43, 0x23, 0x81, 0x34, 0x87, 0x73, 
    0x14, 0x00, 0x42, 0x3D, 0x02, 0xD6, 0x23, 0x80, 0xC5, 0x23, 0x81, 0x35, 0x02, 0x58, 0x13, 0x80, 
    0xC5, 0x03, 0xD6, 0x13, 0xD4, 0x03, 0x52, 0xD4, 0x23, 0x59, 0xC4, 0x23, 0x81, 0x35, 0x02, 0x58, 
    0x03, 0xC8, 0x45, 0x3C, 0x50, 0x84, 0x23, 0x45, 0x38, 0x02, 0xC8, 0x45, 0x3C, 0x12, 0x58, 0x23, 
    0x80, 0x35, 0x90, 0x45, 0x3C, 0x50, 0xD4, 0x12, 0x42, 0x2C, 0x4C, 0x83, 0xC4, 0xC1, 0x84, 0x03, 
    0x48, 0x4D, 0x38, 0x01, 0x58, 0x38, 0x82, 0x85, 0x13, 0x80, 0xD4, 0x84, 0x03, 0x48, 0x1C, 0x4C, 
    0x38, 0xC4, 0xC2, 0x14, 0x00, 0x42, 0x3C, 0x12, 0xD5, 0x12, 0x24, 0x80, 0xD5, 0x01, 0x48, 0x83, 
    0x56, 0x3C, 0x58, 0xC4, 0x38, 0x58, 0x3D, 0x51, 0x3D, 0x42, 0x3C, 0x01, 0x42, 0x02, 0x4C, 0x43, 
    0xC2, 0x35, 0x14, 0xC0, 0x84, 0x34, 0x14, 0x4C, 0x08, 0x34, 0x04, 0x4C, 0x18, 0x34, 0xC4, 0x84, 
    0x01, 0x34, 0x85, 0x42, 0x01, 0x12, 0x48, 0x38, 0x82, 0x84, 0x84, 0x12, 0x46, 0x08, 0x68, 0x04, 
    0x84, 0x23, 0x48, 0x70, 0x07, 0x77, 0x84, 0x23, 0x48, 0x60, 0x84, 0x80, 0x46, 0x12, 0x48, 0x48, 
    0x38, 0x82, 0x84, 0x12, 0x43, 0x23, 0x41, 0x38, 0x12, 0x34, 0x43, 0x38, 0x12, 0x48, 0x33, 0x34, 
    0x12, 0x48, 0x23, 0x41, 0x03
};

#endif

