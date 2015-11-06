/*==============================================================================
==
== FILE NAME:		SendString.c 
==
== DESCRIPTION:	Containg the description of functions used for writing anti-aliased
==				fonts on the screen.
==  
== DATE				NAME					REASON
== ----				----					------
==	14Jan2009		Ankit Saxena		    Original
==	
==	31Jul2009		Ankit Saxena			Added some new functions
==
==============================================================================*/
#include <avr/io.h>
#include "glcd.h"
#include "CoreFunctions.c"
#include "AntiAliasing.c"






#ifndef SENDSTRING_C
#define SENDSTRING_C





 




/*******************************************************************************
** FUNCTION :
**       vGlcdSelectFont
********************************************************************************
**
** Description :
**       This function is defined by the user to select a font of choice. It determines the 
**       font width,height and whether the font is compressed or not.
**	Arguments:
**					NAME		TYPE		DESCRIPTION
**			Input:		
**					pData         pointer	 points to the font data in the flash memory
**					Callback            
**                                    
**			Returns:
**					void
**
**          NOTE: The font being called should be included.
*******************************************************************************/
void vGlcdSelectFont(PGM_VOID_P pData, ucGlcdFontFunc Callback) 
{

    unGlcdFontData = (U16Bit)(pData);    /*the pointer to the font data*/
    ucGlcdFontRead = Callback;            /*Its used to call the function which reads from the progmem(flash)*/
    ucGlcdFontWidth = ucGlcdFontRead(unGlcdFontData + 2);    /*Extracts the width of the font from the included header file*/
    ucGlcdFontHeight = ucGlcdFontRead(unGlcdFontData + 3);   /*Extracts the height of the font from the included header file*/
    ucGlcdFontBitsPixel = ucGlcdFontRead(unGlcdFontData + 4);/*Extracts the BitsPixel of the font from the included header file*/
    ucGlcdFontFirstChar = ucGlcdFontRead(unGlcdFontData + 5);/*Extracts the first character of the font from the included header file*/
    ucGlcdFontLastChar = ucGlcdFontRead(unGlcdFontData + 6); /*Extracts the last charcter of the font from the included header file*/
}
/*******************************************************************************
** FUNCTION :
**       ucGlcdFontDataRead
********************************************************************************
**
** Description :
**       This function reads from the flash and returns the read value
**
**	Arguments:
**					NAME		TYPE		DESCRIPTION
**			Input:		
**                  unIndex     U16Bit      Address of the information to be retrieved
**
**                  
**			Returns:
**					read information
**
*******************************************************************************/
U8Bit ucGlcdFontDataRead(U16Bit unIndex) 
{

    return(PRG_RDB(unIndex));
}
/*******************************************************************************
** FUNCTION :
**       vGlcdNewLine
********************************************************************************
**
** Description :
**       This function is used to tranfer the cursor to the next line when it reaches the
**		 end of the screen.
**	Arguments:
**					NAME		TYPE		DESCRIPTION
**			Input:		
**                  void
**
**                  
**			Returns:
**					void
**
**			NOTE: When cursor reaches bottom the screen will be cleared(see vGlcdClearScreen(void))
*******************************************************************************/
void vGlcdNewLine(void) 
{

    stGlcdCursor.X = stGlcdWindow.X1;
    stGlcdCursor.Y += ucGlcdFontHeight;
    if (stGlcdCursor.Y + ucGlcdFontHeight > stGlcdWindow.Y2) 
	{
   	  stGlcdCursor.Y = stGlcdWindow.Y1;
	  vGlcdClearScreen();
    }
}
/*******************************************************************************
** FUNCTION :
**       ucGlcdDrawChar
********************************************************************************
**
** Description :
**       This function draws a single character to the screen.
**
**	Arguments:
**					NAME		TYPE		DESCRIPTION
**			Input:		
**                  ucChar      U8Bit      character to be drawn
**
**                  
**			Returns:
**					ucWidth     U8Bit 	   Width of the character if painted
**
*******************************************************************************/
U8Bit ucGlcdDrawChar(U8Bit ucChar) 
{

    if (ucChar == '\n') 
	{
      vGlcdNewLine();
      return(0);
    }
  // the character is defined in the font and a font selected?
    if ((ucChar < ucGlcdFontFirstChar) | (ucChar > ucGlcdFontLastChar) | (unGlcdFontData == 0)) 
	{
      return(0);
    }

  // The characters in the font declared but not defined?
    U8Bit ucCharwidth = ucGlcdFontRead(unGlcdFontData + FONT_HEADER_SIZE + ucChar - ucGlcdFontFirstChar);
    if (ucCharwidth == 0) 
	{
	  return(0);
	}

  // all the characters of small # 128 have an implicit right Blank column
    U8Bit ucWidth = ucCharwidth;
    if (ucChar < 128) 
	{
	  ucWidth++;
	}

  // if we change the character set with a fixed width draw will then set the Width line
    if ((stGlcdFlags.FixedFont == 1) & (ucWidth <= ucGlcdFontWidth)) 
	{
      ucWidth = ucGlcdFontWidth;
    }



 
    if ((stGlcdCursor.X > stGlcdClip.X2) | (stGlcdCursor.Y > stGlcdClip.Y2)) 
	{
      return(0);
    }

    U8Bit ucX = stGlcdCursor.X;  /*stores the previous value of the cursor position*/
    U8Bit ucY = stGlcdCursor.Y;
    stGlcdCursor.X += ucWidth;

    if ((ucX > stGlcdClip.X2) | (ucY + ucGlcdFontHeight < stGlcdClip.Y1)) 
	{
      return(0);
    }

    U8Bit i = 0;

  // FixedFont if the characters within ucGlcdFontWidth centered, but only
  // If the character is narrower than ucGlcdFontWidth. We will also fill the right
  // And the left side of the sign, only when the background color is not transparent.
    if ((stGlcdFlags.FixedFont == 1) & (ucWidth > ucCharwidth)) 
	{
      i = (ucWidth - ucCharwidth) / 2;
      if (BK_COLOR != NONE) 
	  {
        vGlcdDoFillRect(ucX, ucY, ucX + i -1, ucY + ucGlcdFontHeight -1, BK_COLOR);
      }
      ucX += i;
    }
    i = ucWidth - ucCharwidth - i;
    if ((i > 0) & (BK_COLOR != NONE)) 
	{
      vGlcdDoFillRect(ucX + ucCharwidth, ucY, ucX + ucCharwidth + i -1, ucY + ucGlcdFontHeight -1, BK_COLOR);
    }

  // must sign the actual data are drawn?
    if ((ucX > stGlcdClip.X2) | (ucX + ucCharwidth < stGlcdClip.X1)) 
	{
      return(ucWidth);
    }

    U16Bit unData;                                       //  pointer to Font data
    U8Bit ucBitsPixel = ucGlcdFontBitsPixel & 0x7F;             // Bits per pixel
    U8Bit ucBitsMask = 0xFF >> (8 - ucBitsPixel);                //Bitmask for Color
    uint16_t unBits;                                             // contains the actual bits of the sign
    U8Bit ucBitsCount;                                         // current number of bits in bits
    U8Bit ucTable[4];                                          // RLE lengths table

  // ALL reads in the font memory are arranged so that they entire blocks of
  // uint8_ts done sequentially.

    if (ucGlcdFontBitsPixel & 0x80) 
	{
    // compressed fonts

    // Get the 8Bit Padding the RLE length table and compute the data to the unit8_tindex.
    // This reading has an additional overhead of 4 unit8_t's for compressed fonts.

      unData = unGlcdFontData + FONT_HEADER_SIZE + ucGlcdFontLastChar - ucGlcdFontFirstChar +1;
      U8Bit ucPadding = ucGlcdFontRead(unData++);
      ucTable[0] = 1;
      ucTable[1] = ucGlcdFontRead(unData++);
      ucTable[2] = ucGlcdFontRead(unData++);
      ucTable[3] = ucGlcdFontRead(unData++);
      U32Bit Index = 0;
      for (i = ucGlcdFontFirstChar; i < ucChar; i++) 
	  {
        Index += ucGlcdFontRead(unData++);
      }
      Index *= ucPadding;
      unData = unGlcdFontData + FONT_HEADER_SIZE + (ucGlcdFontLastChar - ucGlcdFontFirstChar +3) * 2 + Index;
      unBits = ucGlcdFontRead(unData++);
      ucBitsCount = 8;
    } 
	else
    {
     //uncompressed Font
     
     // Now calculate the Bit index to Bit data in the font
      unData = unGlcdFontData + FONT_HEADER_SIZE;
      U32Bit Index = 0;
      for (i = ucGlcdFontFirstChar; i < ucChar; i++) 
	  {
        Index += ucGlcdFontRead(unData++);
      }
    // Left clipping take into account only when possible uncompressed fonts
      if (ucX < stGlcdClip.X1) 
	  {
        U8Bit t = stGlcdClip.X1 - ucX;
        Index += t;
        ucCharwidth -= t;
        ucX = stGlcdClip.X1;
      }
      Index *= ucGlcdFontHeight * ucBitsPixel;

    // data's position at first unit8_t with Fontdata to sign and get the first bits
      ucBitsCount = Index % 8;
      Index /= 8;
      unData = unGlcdFontData + FONT_HEADER_SIZE + ucGlcdFontLastChar - ucGlcdFontFirstChar +1 + Index;
      unBits = ucGlcdFontRead(unData++) >> ucBitsCount;
      ucBitsCount = 8 - ucBitsCount;
    }

  // we send the Bitdata of each pixel of each column in the Y direction

	

    U8Bit ucPixelCount = 0;                                 // Number of pixels to be determined
    U8Bit ucPixelColor;                                 // to be set pixel color
    U8Bit ucClipInvalid = 1;                                // Validity of the address pointer in PCF8833
    U8Bit ucClipY = 0;                                  // Y-set final address in PCF8833
    U8Bit ucStopY = stGlcdCursor.Y + ucGlcdFontHeight -1; // bottom row of pixels mark
    U8Bit ucStopX = ucX + ucCharwidth -1;

  
    if (ucStopX > stGlcdClip.X2) 
	{
      ucStopX = stGlcdClip.X2;
    }

    for (; ucX <= ucStopX; ucX++) 
	{
      if (ucClipY |= stGlcdCursor.Y) 
	  {
        ucClipInvalid = 1;
      }
      for (ucY = stGlcdCursor.Y; ucY <= ucStopY; ucY++) 
	  {
        if (ucPixelCount == 0) 
		{
          if (ucBitsCount <= 8) 
		  {
            unBits |= ucGlcdFontRead(unData++) << ucBitsCount;
            ucBitsCount += 8;
          }
          if (ucGlcdFontBitsPixel & 0x80) /*only for compressed fonts.*/
		  {               
            ucPixelCount = ucTable[unBits & 3];
            unBits >>= 2;
            ucBitsCount -= 2;
          } 
		  else 
		  {
            ucPixelCount++;
          }
          if (ucBitsPixel <= COLOR_TABLE_BITS) 
		  {
            ucPixelColor = ucGlcdColors[unBits & ucBitsMask];
          } 
		  else 
		  {
            ucPixelColor = unBits & ucBitsMask;
          }
          unBits >>= ucBitsPixel;
          ucBitsCount -= ucBitsPixel;
        }
        ucPixelCount--;
        if ((ucPixelColor != NONE) & (ucY >= stGlcdClip.Y1) & (ucY <= stGlcdClip.Y2) & (ucX >= stGlcdClip.X1)) 
		{
          if (ucClipInvalid) 
		  {
            vGlcdSetAddr(ucX, ucY, stGlcdCursor.X, ucStopY);
            ucClipY = ucY;
            ucClipInvalid = 0;
          }
          vGlcdPutPixel(ucPixelColor);
        } 
		else 
		{
          ucClipInvalid = 1;
        }
      }
    }



    return(ucWidth);
}

/*****************************************************************************************************
** FUNCTION :
**       vGlcdSendStrXY
******************************************************************************************************
**
** Description :
**       This function prints an anti-aliased string on the screen at a position (x,y), within the confinements 
**       of stGlcdWindow
**       
**	Arguments:
**					NAME		TYPE		DESCRIPTION
**			Input:		
**                  pucData     *U8Bit      input string
**					ucX			U8Bit		x coordinate of the string start
**                  ucY			U8Bit		y coordinate of the string start
**					Color		U8Bit		color of the string
**
**                  
**			Returns:
**					void    
**
**
**			NOTE: The string will be printed only within the Window. Thus SET_RECT maybe called
**				  before to set the Window otherwise the default Window is the entire screen.
**				  Also vGlcdSelectFont() must be called before this function(see vGlcdSelectFont())
*******************************************************************************************************/
void vGlcdSendStrXY(U8Bit *pucData, U8Bit ucX, U8Bit ucY,U8Bit ucColor)
{
  
	stGlcdWindow.X1=ucX;
	stGlcdCursor.Y=ucY;
	stGlcdCursor.X=stGlcdWindow.X1;
	
	SET_FG_COLOR(ucColor);
	
    USHORT usIntensity=ucGlcdFontRead(unGlcdFontData);    //for f10x14a usIntensity=0x7D and for Font, BigFont its 0x96
	vGlcdSetOrientation(3);
	
	U8Bit ucR = ucGetRValue( FG_COLOR );
    U8Bit ucG = ucGetGValue( FG_COLOR );
    U8Bit ucB = ucGetBValue( FG_COLOR );
    FLOAT8 dGrayl = ucR * 0.299 + ucG * 0.587 + ucB * 0.114;
	
	U8Bit ucRb = ucGetRValue( BK_COLOR );
    U8Bit ucGb = ucGetGValue( BK_COLOR );
    U8Bit ucBb = ucGetBValue( BK_COLOR );
    FLOAT8 dGrayb = ucR * 0.299 + ucG * 0.587 + ucB * 0.114;
	

	 SET_SH_COLOR(ucGlcdCalcColorValue(ucR,ucRb,ucG,ucGb,ucB,ucBb,dGrayl,dGrayb,usIntensity,1));
	 SET_FR_COLOR(ucGlcdCalcColorValue(ucR,ucRb,ucG,ucGb,ucB,ucBb,dGrayl,dGrayb,usIntensity,0));

	while (*pucData)
	{
		
		if((stGlcdCursor.X+ucGlcdCharWidth(*pucData)) <= stGlcdWindow.X2)
		{
			ucGlcdDrawChar(*pucData);
		}
		else
		{
		    vGlcdNewLine();
			pucData--;
		}	
		pucData++;
		
	}
}
/*******************************************************************************
** FUNCTION :
**       ucGlcdCharWidth
********************************************************************************
**
** Description :
**       This function returns the width of a single character.
**
**	Arguments:
**					NAME		TYPE		DESCRIPTION
**			Input:		
**                  ucChar      U8Bit      character whose width is to be
**										   determined.
**                  
**			Returns:
**					ucWidth     U8Bit 	   Width of the character
**
*******************************************************************************/
U8Bit ucGlcdCharWidth(U8Bit ucChar)                                 
{
	U8Bit ucWidth = ucGlcdFontRead(unGlcdFontData + FONT_HEADER_SIZE + ucChar - ucGlcdFontFirstChar);
	if(ucChar<128)
		ucWidth++;
	
	return( ucWidth );
}
/*******************************************************************************
** FUNCTION :
**       ucGlcdStringWidth
********************************************************************************
**
** Description :
**       This function returns the width of a string.
**
**	Arguments:
**					NAME		TYPE		DESCRIPTION
**			Input:		
**                  ucChar      U8Bit      input string
**
**                  
**			Returns:
**					ucWidth     U8Bit 	   Width of the string 
**
*******************************************************************************/
U8Bit ucGlcdStringWidth(U8Bit *pucData)
{
	U8Bit ucStringWidth=0;
	while(*pucData)
	{	
		ucStringWidth+= ucGlcdCharWidth(*pucData);
		pucData++;
	}	
	return( ucStringWidth );
	
}
#endif