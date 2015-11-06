/*==============================================================================
==
== FILE NAME:		CoreFunctions.c 
==
== DESCRIPTION:	Contains the description of the main functions used by every 
==				function. Should be included always. Also includes the initialiazing,
==              command send and data send functions.
==  
== DATE				NAME					REASON
== ----				----					------
==	14Jan2009		Ankit Saxena		    Original
==	
==
==============================================================================*/




#include <avr/io.h>
#include "glcd.h"

#ifndef COREFUNCTIONS_C
#define COREFUNCTIONS_C

/*******************************************************************************
** FUNCTION :
**       vDisplayInit 
********************************************************************************
**
** Description :
**       This funtion initializes the LCD.
**			1. Sets the serial ports of the controller	
**			2. Set the Display ON, Booster ON and sets the LCD in the sleep out mode
**			3. Clear the Display and sets up the color table
**			4. Initializes the memory controller register for normal orientation
**          5. Should always be called in the main before any other instruction is excecuted
*******************************************************************************/
void vGlcdDisplayInit(void)
{
    vGlcdWait(300000);

	LCD_SER_DDR = 0x3C;
	LCD_CTRL_DDR = 0x3C; /*Sets the data direction register of portB so as to define the pins 2,3,4,5 as the output pins*/

	SBI(LCD_CTRL_PORT, LCD_CE);
	vGlcdWait(15000);
	SBI(LCD_CTRL_PORT, LCD_RESET);
	
	SBI(LCD_SER_PORT, LCD_SCL);
	SBI(LCD_SER_PORT, LCD_SDA);
	SBI(LCD_CTRL_PORT, LCD_CE);

	LCD_SPCR = (1<<CPHA) | (0x01 << SPE) | (0x01 << MSTR) | (0x01 << CPOL);  /*Setting the serial port control register*/
	LCD_SPSR = (1<<SPI2X);		/*Setting the serial port status register*/

	vGlcdDisplayCommand(SOFT_RESET);
	vGlcdDisplayCommand(SLEEP_OUT);
	vGlcdDisplayCommand(DISPLAY_ON);                               
	vGlcdDisplayCommand(BOOSTER_ON);
	vGlcdWait(75000);
	
	
	vGlcdDisplayCommand(SET_CONTRAST);/*to set the contrast of the screen to a desired value*/
	vGlcdDisplayData(63);
	
	vGlcdDisplayCommand(COLOR_INTERFACE);
	vGlcdDisplayData(COLOR_8_BIT);   /*choses the 8 bit color mode for the lcd display*/
	
	vGlcdDisplayCommand(COLOR_SET);   /*Color Table*/
	vGlcdDisplayData(0x00);
	vGlcdDisplayData(0x02);
	vGlcdDisplayData(0x04);
	vGlcdDisplayData(0x06);
    vGlcdDisplayData(0x09);
	vGlcdDisplayData(0x0B);
	vGlcdDisplayData(0x0D);
	vGlcdDisplayData(0x0F);

	vGlcdDisplayData(0x00);
	vGlcdDisplayData(0x02);
	vGlcdDisplayData(0x04);
	vGlcdDisplayData(0x06);
	vGlcdDisplayData(0x09);
	vGlcdDisplayData(0x0B);
	vGlcdDisplayData(0x0D);
	vGlcdDisplayData(0x0F);

	vGlcdDisplayData(0x00);
	vGlcdDisplayData(0x04);
	vGlcdDisplayData(0x0B);
	vGlcdDisplayData(0x0F);
	
	
	
    SET_RECT(stGlcdClip, 0, 0, SCREEN_WIDTH-1, SCREEN_HEIGHT-1);    //glcdSetRect() sets the corner points of the clip/window

    SET_RECT(stGlcdWindow, SCREEN_LEFT, SCREEN_TOP, SCREEN_RIGHT, SCREEN_BOTTOM);  //Clip is used for lines and Window is used for fonts.

	vGlcdDisplayCommand(MEM_CONTROL);
	ucGlcdMemCtrl = (1 << MEM_MX) | (0 << MEM_MY) | (0 << MEM_RGB) | (0 << MEM_VW) | (0 << MEM_LAO);
    vGlcdDisplayData(ucGlcdMemCtrl);

    SET_BK_COLOR(SCREEN_COLOR0);     // sets the Background(white)
    SET_FG_COLOR(SCREEN_COLOR1);    // sets the Foreground
    SET_FR_COLOR(SCREEN_COLOR2);    // sets the Frame
    SET_SH_COLOR(SCREEN_COLOR3);   // sets the Shadow
	

	
	vGlcdClearScreen();
}
/*******************************************************************************
** FUNCTION :
**       vGlcdDisplayCommand
********************************************************************************
**
** Description :
**       This function is called to send a command to the LCD screen
**
**	Arguments:
**					NAME		TYPE		DESCRIPTION
**			Input:		
**                  ucCmd       U8Bit       data which is to displayed on the screen/stored
**                  
**			Returns:
**					void
**
*******************************************************************************/
void vGlcdDisplayCommand(U8Bit ucCmd)
{
	LCD_SPCR = 0x00;
	CBI(LCD_PORT, LCD_CE);

	CBI(LCD_SER_PORT, LCD_SCL);
	CBI(LCD_SER_PORT, LCD_SDA);
	SBI(LCD_SER_PORT, LCD_SCL);

	LCD_SPCR = (1<<CPHA) | (0x01 << SPE) | (0x01 << MSTR) | (0x01 << CPOL);
	LCD_SPSR = (1<<SPI2X);
	LCD_SPDR = ucCmd;

	while(!(LCD_SPSR & (0x01 << SPIF)));   /*Checks whether the serial transfer is complete or not*/
	SBI(LCD_PORT, LCD_CE);
}
/*******************************************************************************
** FUNCTION :
**       vGlcdDisplayData
********************************************************************************
**
** Description :
**       This function is called to send data to the LCD which is to be displayed or stored 
**
**	Arguments:
**					NAME		TYPE		DESCRIPTION
**			Input:		
**                  ucData       U8Bit      data which is to displayed on the screen/stored
**                  
**			Returns:
**					void
**
*******************************************************************************/
void vGlcdDisplayData(U8Bit ucData)
{
	LCD_SPCR = 0x00;
	CBI(LCD_PORT, LCD_CE);

	CBI(LCD_SER_PORT, LCD_SCL);
	SBI(LCD_SER_PORT, LCD_SDA);
	SBI(LCD_SER_PORT, LCD_SCL);

	LCD_SPCR = (1<<CPHA) | (0x01 << SPE) | (0x01 << MSTR) | (0x01 << CPOL);
	LCD_SPSR = (1<<SPI2X);
	LCD_SPDR = ucData;

	while(!(LCD_SPSR & (0x01 << SPIF)));   /*Checks whether the serial transfer is complete or not*/
	SBI(LCD_PORT, LCD_CE);
}
/******************************************************************************************************************
** FUNCTION :
**       vGlcdClearScreen
*******************************************************************************************************************
**
** Description :
**       This function is called to clear the screen with the back ground color
**
**	Arguments:
**					NAME		TYPE		DESCRIPTION
**			Input:		
**                  void
**                  
**			Returns:
**					void
**          
**          NOTE: SET_COLORS() should be called to set the background color if the default color is not required
*******************************************************************************************************************/
void vGlcdClearScreen(void)                                        
{
    vGlcdFillRect(0, 0, SCREEN_WIDTH -1, SCREEN_HEIGHT -1, BK_COLOR);
} 
/*******************************************************************************
** FUNCTION :
**       vGlcdWait
********************************************************************************
**
** Description :
**       This function is a delay function
**
**	Arguments:
**					NAME		TYPE		DESCRIPTION
**			Input:		
**                  nMs          S32Bit        number of milli-seconds                  
**			Returns:
**					void
**
*******************************************************************************/
void vGlcdWait(S32Bit nMs)
{
    S32Bit d;
	for(d=0;d<nMs;d++)
	{
		asm("NOP");	
		asm("NOP");	
		asm("NOP");	
		asm("NOP");	
		asm("NOP");	
		asm("NOP");	
	}
}
/*******************************************************************************
** FUNCTION :
**       vGlcdSetOrientation
********************************************************************************
**
** Description :
**       This function is called to change the orientation of the display. 
**
**	Arguments:
**					NAME		     TYPE	   DESCRIPTION
**			Input:		
**                  ucOrientation    U8Bit     0->   0°   
**                                             1->  90°                             
**                                             2-> 180° 
**                                             3-> 270° 
**			Returns:
**					void
**
*******************************************************************************/
void vGlcdSetOrientation(U8Bit ucOrientation) 
{

  vGlcdDisplayCommand(MEM_CONTROL);
  ucGlcdMemCtrl &= ~((1 << MEM_90) | (1 << MEM_VW) | (1 << MEM_MX) | (1 << MEM_MY));   //Clearing the Memory access control register
  
  if (ucOrientation & 1) 
  {
    ucGlcdMemCtrl |= (1 << MEM_90) | (1 << MEM_VW) | (1 << MEM_MX);   /* setting the Memory Access control to display a 90° rotation on the screen*/
  }
  if (ucOrientation & 2) 
  {
    ucGlcdMemCtrl ^= (1 << MEM_MY);   /* setting the Memory Access control to display a 180° rotation on the screen*/
  } else 
  {
    ucGlcdMemCtrl ^= (1 << MEM_MX);   /* setting the Memory Access control to display a 270° rotation on the screen*/
  }
  vGlcdDisplayData(ucGlcdMemCtrl);
}
/*******************************************************************************
** FUNCTION :
**       vGlcdDoFillRect
********************************************************************************
**
** Description :
**       This function performs the operation of filling a rectangular area with a specified color
**
**	Arguments:
**					NAME		TYPE		DESCRIPTION
**			Input:		
**					ucX1	      U8Bit	     starting x-coordinate of the rectangle
**					ucY1          U8Bit      starting y-coordinate of the rectangle
**                  ucX2          U8Bit      ending x-coordinate of the rectangle
**                  ucY2          U8Bit      ending y-coordinate of the rectangle
**                  ucColor       U8Bit      color with which the area is to be filled
**                  
**			Returns:
**					void
**
*******************************************************************************/
void vGlcdDoFillRect(U8Bit ucX1, U8Bit ucY1, U8Bit ucX2, U8Bit ucY2, U8Bit ucColor) 
{
    U8Bit x, y;
    if ((ucX1 > stGlcdClip.X2) | (ucX2 < stGlcdClip.X1) | (ucY1 > stGlcdClip.Y2) | (ucY2 < stGlcdClip.Y1)) 
	{
	 return;
	}
    if (ucX1 < stGlcdClip.X1) {ucX1 = stGlcdClip.X1;}
    if (ucY1 < stGlcdClip.Y1) {ucY1 = stGlcdClip.Y1;}
    if (ucX2 > stGlcdClip.X2) {ucX2 = stGlcdClip.X2;}
    if (ucY2 > stGlcdClip.Y2) {ucY2 = stGlcdClip.Y2;}
    if ((ucX1 <= ucX2) & (ucY1 <= ucY2)) 
	{
      vGlcdSetAddr(ucX1, ucY1, ucX2, ucY2);
      for (y = ucY1; y <= ucY2; y++) 
	  {
        for (x = ucX1; x <= ucX2; x++) 
		{
          vGlcdPutPixel(ucColor);
        }
      }
    }
}
/*******************************************************************************
** FUNCTION :
**       vGlcdFillRect
********************************************************************************
**
** Description :
**       This function is called to fill a rectangular area with a specified color. It checks the coordinates
**       and calls a function which performs the filling operation
**	Arguments:
**					NAME		TYPE		DESCRIPTION
**			Input:		
**					ucX1          U8Bit	     starting x-coordinate of the rectangle
**					ucY1          U8Bit      starting y-coordinate of the rectangle
**                  ucX2          U8Bit      ending x-coordinate of the rectangle
**                  ucY2          U8Bit      ending y-coordinate of the rectangle
**                  ucColor       U8Bit      color with which the area is to be filled
**                  
**			Returns:
**					void
**
*******************************************************************************/
void vGlcdFillRect(U8Bit ucX1, U8Bit ucY1, U8Bit ucX2, U8Bit ucY2, U8Bit ucColor) 
{

    CHECK_COORD(ucX1, ucX2);         //Compares two U8Bit values and assings the first parameter,in the function call(ucX1), the lesser value
    CHECK_COORD(ucY1, ucY2);
    vGlcdDoFillRect(ucX1, ucY1, ucX2, ucY2, ucColor);
}


/*******************************************************************************
** FUNCTION :
**       vGlcdSetAddr
********************************************************************************
**
** Description :
**       This function is called to set the row and the column addresses and must be called before any function which requires  
**       pixels(or pixel) to be plotted on the LCD screen
**	Arguments:
**					NAME		TYPE		DESCRIPTION
**			Input:		
**					ucX1          U8Bit	     starting x-address
**					ucY1          U8Bit      starting y-address
**                  ucX2          U8Bit      ending x-address
**                  ucY2          U8Bit      ending y-address
**
**                  
**			Returns:
**					void
**
*******************************************************************************/
void vGlcdSetAddr(U8Bit ucX1, U8Bit ucY1, U8Bit ucX2, U8Bit ucY2)          
{

   if (ucGlcdMemCtrl & (1 << MEM_90)) //checks whether the orientation has been changed or not.
    {
      SWAP_COORD(ucX1, ucY1);   //swaps the two input parameter(U8Bit values)
      SWAP_COORD(ucX2, ucY2);
    }
    vGlcdDisplayCommand(SET_X_ADDR);
    vGlcdDisplayData(ucX1);
    vGlcdDisplayData(ucX2);
    vGlcdDisplayCommand(SET_Y_ADDR);
    vGlcdDisplayData(ucY1);
    vGlcdDisplayData(ucY2);
    vGlcdDisplayCommand(MEM_WRITE);
}
/*******************************************************************************
** FUNCTION :
**       vGlcdPutPixel
********************************************************************************
**
** Description :
**       This function is to send the data to the LCD to plot a pixel
**
**	Arguments:
**					NAME		TYPE		DESCRIPTION
**			Input:		
**                  ucColor       U8Bit       the color of the pixel
**
**                  
**			Returns:
**					void
**
*******************************************************************************/
void vGlcdPutPixel(U8Bit ucColor)               
{ 
    vGlcdDisplayData(ucColor);
}
/*******************************************************************************
** FUNCTION :
**       vGlcdSetPixel
********************************************************************************
**
** Description :
**       This function is called to draw a pixel at location (x,y)
**
**	Arguments:
**					NAME		TYPE		DESCRIPTION
**			Input:		
**					ucX	        U8Bit		x-coordinate of the pixel
**					ucY         U8Bit       y-coordinate of the pixel
**                  ucColor     U8Bit       the color of the pixel
**
**                  
**			Returns:
**					void
**
*******************************************************************************/
void vGlcdSetPixel(U8Bit ucX, U8Bit ucY, U8Bit ucColor) 
{
	
    if ((ucX >= stGlcdClip.X1) & (ucX <= stGlcdClip.X2) & (ucY >= stGlcdClip.Y1) & (ucY <= stGlcdClip.Y2)) 
	{
      vGlcdSetAddr(ucX, ucY, SCREEN_WIDTH -1, SCREEN_HEIGHT -1);
      vGlcdPutPixel(ucColor);
    }
}

#endif