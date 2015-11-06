/*
 Copyright:      Hagen Reddmann  mailto HaReddmann at T-Online dot de
 Author:         Hagen Reddmann
 Remarks:        this Copyright must be included
 known Problems: none
 Version:        2.1. 2004
 Description:    Grafic Library for Nokia 6100 Display and compatible
*/
/*==============================================================================
==
== FILE NAME:		glcdnew.h 
==
== DESCRIPTION:	Contains the header file description and prototypes of various 
==				functions
==  
== DATE				NAME					REASON
== ----				----					------
==	14Jan2009		Ankit Saxena		    Original
==	
==
==============================================================================*/

#include <avr/io.h>
#include "DataTypes.h"
#include "AssignPins.h"
#include "Colors.h"
#include "Commands.h"
#include <avr/pgmspace.h>



#ifndef GLCD_H
#define GLCD_H

U8Bit ucGlcdColors[]={SCREEN_COLOR0,SCREEN_COLOR1,SCREEN_COLOR2,SCREEN_COLOR3};

struct {
    U8Bit X1;
    U8Bit Y1;
    U8Bit X2;
    U8Bit Y2;
}stGlcdClip,stGlcdWindow;

struct {
    U8Bit X;
    U8Bit Y;
} stGlcdCursor;

union {
    U8Bit All;
    struct {
    U8Bit AutoLineFeed:1,          // font routines should use implizit linefeed and wrap around glcd_Window
            FixedFont:1,             // == 0 fonts painted proportional, == 1 fonts painted in fixed pitch
            Clipping:1;              // activate clipping
    };        
} stGlcdFlags;






typedef U8Bit (*ucGlcdFontFunc)(U16Bit unIndex); // custom font data read callback, thus we can support ae. I2C EEPROM


/*List of variables used for drawing characters*/
 U8Bit           ucGlcdFontFirstChar=0x00;   // first defined chararcter in selected font
 U8Bit           ucGlcdFontLastChar=0x00;    // last defined chararcter in selected font
 U8Bit           ucGlcdFontWidth=0x00;       // character width for fixed pitch of selected font
 U8Bit           ucGlcdFontHeight=0x00;      // character height of selected font
 U8Bit           ucGlcdFontBitsPixel=0x00;   // color depth of selected font, if MSB is set the font is compressed
 ucGlcdFontFunc  ucGlcdFontRead=0x00;        // user definied read callback of font data, if NULL it's assumed font is stored in flash
 U16Bit          unGlcdFontData=0x0000;        // pointer to font data, a read callback can store own values here
                                             // the lib access trough this pointer ONLY if ucGlcdFontRead == NULL to flash
                                             // otherwise this value is a paramter to the user callback



 U8Bit         ucGlcdMemCtrl=0x00;  // display RAM access and degree of rotation



/*Prototypes and variable used*/
extern void vGlcdDisplayCommand(U8Bit ucCmd); // send a command to display
extern void vGlcdDisplayData(U8Bit ucData);   // send data to display
extern void vGlcdSetAddr(U8Bit ucX1, U8Bit ucY1, U8Bit ucX2, U8Bit ucY2);   // set RAM access pointer of display
extern void vGlcdPutPixel(U8Bit color);      // put a pixel, glcdSetAddr() MUST be prior called
extern void vGlcdDoFillRect(U8Bit ucX1, U8Bit ucY1, U8Bit ucX2, U8Bit ucY2, U8Bit Color); 
extern U8Bit ucGlcdCalcColorValue(U8Bit ucRl,U8Bit ucRb,U8Bit ucGl,U8Bit ucGb,U8Bit ucBl,U8Bit ucBb,FLOAT8 dGrayl,FLOAT8 dGrayb,USHORT usWeighting,SHORT sToggle);
extern U8Bit ucGetRValue(U8Bit ucColor);
extern U8Bit ucGetGValue(U8Bit ucColor);
extern U8Bit ucGetBValue(U8Bit ucColor);
extern U8Bit ucGlcdColorValue(U8Bit ucCl,U8Bit ucCb,USHORT usWeighting,FLOAT8 dGrayl,FLOAT8 dGrayb);
extern U8Bit ucGlcdFontDataRead(U16Bit unIndex);


/*User Defined Function Prototypes*/
extern void vGlcdWait(S32Bit nMs);           // wait some milliseconds, XTAL must be correct defined
extern void vGlcdDisplayInit(void);       // initialize the display, MUST be normaly NEVER called, it's automaticaly called by the initialization code
extern void vGlcdClearScreen(void);//Clears the screen to the background color
extern void vGlcdSetOrientation(U8Bit ucOrientation); // degree 0°,90°,180°,270° -> 0,1,2,3
extern void vGlcdSetPixel(U8Bit ucX, U8Bit ucY, U8Bit Color);  // set a pixel
extern void vGlcdFillRect(U8Bit ucX1, U8Bit ucY1, U8Bit ucX2, U8Bit ucY2, U8Bit Color);//Fills a rectangular area with a specified color
extern void vGlcdLine(U8Bit ucX1, U8Bit ucY1, U8Bit ucX2, U8Bit ucY2,U8Bit ucColor);//draws an aliased line with the Foreground color
extern void vGlcdSendStrXY(U8Bit *pucData, U8Bit ucX, U8Bit ucY,U8Bit ucColor);//Sends a string of data to the display
extern void vGlcdNewLine(void) ;  // <CR><LF> in glcd_Window of glcd_Cursor
extern void vGlcdAALine(SHORT sX1, SHORT sY1, SHORT sX2, SHORT sY2, U8Bit ucColorLine);// draws an anti-aliased line of a specified color
extern void vGlcdPlotGrid(U8Bit ucStart,U8Bit ucEnd);		//plots the grid between a starting and an end point.
extern void vGlcdPlotTrace(U8Bit ucNewPoint, U8Bit ucColor);		//used for plotting the trace.
extern U8Bit ucGlcdDrawChar(U8Bit ucChar);                                  // draw a character, returns width of char, if any painted
extern void vGlcdSelectFont(PGM_VOID_P Data, ucGlcdFontFunc callback) ;    // select a font
extern U8Bit ucGlcdCharWidth(U8Bit ucChar);                                 // return with of char
extern U8Bit ucGlcdStringWidth(U8Bit *pucData);						//returns the width of the string
/*End of User defined Functions*/




/*User defined Macros*/
#define SET_BK_COLOR(color) {SET_COLOR(0, color);}/*Sets the Background color*/
#define SET_FG_COLOR(color) {SET_COLOR(1, color);}/*Sets the Foreground color*/
#define SET_FR_COLOR(color) {SET_COLOR(2, color);}/*Sets the Frame color*/
#define SET_SH_COLOR(color) {SET_COLOR(3, color);}/*Sets the Shadow color*/
#define SET_COLORS(fgColor, bkColor) {SET_FG_COLOR(fgColor); SET_BK_COLOR(bkColor);}/*Sets the background and the foreground colors*/
#define MOVE_CURSOR_TO(x,y) {stGlcdCursor.X = x; stGlcdCursor.Y = y;}/*Moves the Cursor to (x,y) postion*/
/*Internally used Macros*/
#define SWAP_DOUBLE(x,y) {FLOAT8 t=x; x=y; y=t;}             /*Swaps two double values*/
#define CHECK_COORD(x, y) {if (x > y) {SWAP_COORD(x, y);}}/*Checks whether x>y and assigns x the lesser value*/
#define SET_RECT(r,x1,y1,x2,y2) {r.X1 = x1; r.Y1 = y1; r.X2 = x2; r.Y2 = y2;}/*Initializes a Clip/Window structure*/
#define SWAP_COORD(x, y) {U8Bit t = x; x = y; y = t;}/*Swaps two 8Bit values*/
#define PRG_RDB(addr)	pgm_read_byte(addr)
#define SBI(port, bit)	(port) |= (1 << (bit))   /*this is the set bit instruction it set a perticular pin for a given port*/
#define CBI(port, bit)	(port) &= ~(1 << (bit))  /*this is the clear bit instruction it clears a perticular pin for a given port*/
#define BK_COLOR ucGlcdColors[0]         /*Background color*/
#define FG_COLOR ucGlcdColors[1]			/*Foreground color*/
#define FR_COLOR ucGlcdColors[2]			/*Frame color*/
#define SH_COLOR ucGlcdColors[3]			/*Shadow color*/
#define SET_COLOR(index, color) {ucGlcdColors[index] = color;}  /*Macro to set all the colors*/





#endif