/*==============================================================================
==
== FILE NAME:		Colors.h 
==
== DESCRIPTION:	Defines the RGB component of all the colors and convert them into 
==				the 8Bit color mode which is required by color LCD 6610.
==  
== DATE				NAME					REASON
== ----				----					------
==	14Jan2009		Ankit Saxena		    Original
==	
==
==============================================================================*/

#ifndef __Colors_h__
#define __Colors_h__

#define RGB(r,g,b)                ((r & 0xE0) | ((g & 0xE0) >> 3) | (b >> 6))


#define NONE                        RGB(0x00, 0x20, 0x00)  // == tansparent, one green color reduced !!
#define BLACK                       RGB(0x00, 0x00, 0x00)  // for  8 bit colors R,G,B  3,3,2 Bits
#define WHITE                       RGB(0xFF, 0xFF, 0xFF)  // for 16 bit colors R,G,B  5,6,5 bits
#define RED                         RGB(0xFF, 0x00, 0x00)
#define GREEN                       RGB(0x00, 0xFF, 0x00)
#define BLUE                        RGB(0x00, 0x00, 0xFF)
#define YELLOW                      RGB(0xFF, 0xFF, 0x00)
#define MAGENTA                     RGB(0xFF, 0x00, 0xFF)
#define CYAN                        RGB(0x00, 0xFF, 0xFF)
#define GRAY                        RGB(0x80, 0x80, 0x40)
#define SILVER                      RGB(0xA0, 0xA0, 0x80)
#define GOLD                        RGB(0xA0, 0xA0, 0x40)
#define GRID						RGB(205,210,254)
#define TRACE						RGB(245,5,30)


#endif