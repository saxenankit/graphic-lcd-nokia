/*==============================================================================
==
== FILE NAME:		Line.c 
==
== DESCRIPTION:	Contains the description of the function that draws an anti-aliased
==				line.
==  
== DATE				NAME					REASON
== ----				----					------
==	14Jan2009		Ankit Saxena		    Original
==	
==  31Jul2009		Ankit Saxena			MOdifications in the algorithm
==
==============================================================================*/


#include "AntiAliasing.c"
#include "glcd.h"
#include "CoreFunctions.c"

#ifndef LINE_C
#define LINE_C


/*******************************************************************************
** FUNCTION :
**       vGlcdAALine
********************************************************************************
**
** Description :
**       This function is called to draw an Anti-Aliased Line
**
**	Arguments:
**					NAME		  TYPE		DESCRIPTION
**			Input:		
**					sX1	          SHORT		 starting x-coordinate of the line
**					sY1           SHORT      starting y-coordinate of the line
**                  sX2           SHORT      ending x-coordinate of the line
**                  sY2           SHORT      ending y-coordinate of the line
**                  ucColorLine   U8Bit      the Color of the line
**
**                  
**			Returns:
**					void
**
**          NOTE:
**                  the line should not be made to traverse different areas of the screen 
**                  where the background color is different from the one stored in BK_COLOR 
*******************************************************************************/
void vGlcdAALine(SHORT sX1, SHORT sY1, SHORT sX2, SHORT sY2, U8Bit ucColorLine)
{
    
   
  U8Bit ucXDir=1,ucDeltaX,ucDeltaY,ucSwap=0,ucColor;
   
  if( sY1 > sY2 )
	{	
		ucDeltaY = sY1 - sY2;
	}	
	else
	{	
		ucDeltaY = sY2 - sY1;
	}	
 
	
	if( sX1 > sX2 )
	{	
		ucDeltaX = sX1 - sX2;
	}	
	else
	{	
		ucDeltaX = sX2 - sX1;
	}	
	
	if( ucDeltaX > ucDeltaY )			//if X-major line
	{
		SWAP_COORD(ucDeltaX,ucDeltaY);
		ucSwap=1 ;
		SWAP_COORD(sX1,sY1);
		SWAP_COORD(sX2,sY2);
	}
	if( sY1 > sY2 )
	{
		SWAP_COORD(sY1,sY2);//make sure the line runs from top to bottom
		SWAP_COORD(sX1,sX2);
	}	
	if( sX1 > sX2 )
		ucXDir = -1;
	
		
	/* Draw the initial pixel, which is always exactly intersected by
    the line and so needs no weighting */
    if(ucSwap)
	 vGlcdSetPixel( sY1,sX1 , ucColorLine );
	else
	 vGlcdSetPixel( sX1, sY1, ucColorLine );
	
	/* Draw the final pixel, which is always exactly intersected by the line
        and so needs no weighting */
    if(ucSwap)
	 vGlcdSetPixel( sY2,sX2 , ucColorLine );
	else
	 vGlcdSetPixel( sX2, sY2, ucColorLine );
	
    /* Special-case horizontal, vertical, and diagonal lines, which
    require no weighting because they go right through the center of
    every pixel */
    
    if ((ucDeltaY == 0)||(ucDeltaX == 0))
    {
        /* Horizontal line or Vertical line */
        if(ucSwap)
		 vGlcdFillRect(sY1,sX1,sY2,sX2,ucColorLine);
		else
		 vGlcdFillRect(sX1,sY1,sX2,sY2,ucColorLine);
        return;
    }
    if (ucDeltaX == ucDeltaY)
    {
        /*Diagonal line*/  
		
        do
        {
            sX1 += ucXDir;
            sY1++;
            if(ucSwap)
			 vGlcdSetPixel( sY1, sX1, ucColorLine );
			else
			 vGlcdSetPixel( sX1, sY1, ucColorLine );
        } while (--ucDeltaY != 0);
        return;
    }
	

    /* Line is not horizontal, diagonal, or vertical */
    USHORT usErrorAdj;
    USHORT usErrorAccTemp, usWeighting;
	
    
    
    USHORT usErrorAcc = 0;  /* initialize the line error accumulator to 0 */
    
    U8Bit ucRl = ucGetRValue( ucColorLine );
    U8Bit ucGl = ucGetGValue( ucColorLine );
    U8Bit ucBl = ucGetBValue( ucColorLine );
    FLOAT8 dGrayl = ucRl * 0.299 + ucGl * 0.587 + ucBl * 0.114;
	
	U8Bit clrBackGround = BK_COLOR;
    U8Bit ucRb = ucGetRValue( clrBackGround );
    U8Bit ucGb = ucGetGValue( clrBackGround );
    U8Bit ucBb = ucGetBValue( clrBackGround );
    FLOAT8 dGrayb = ucRb * 0.299 + ucGb * 0.587 + ucBb * 0.114;
	
	if( dGrayb > dGrayl )
	   SWAP_DOUBLE(dGrayb,dGrayl);
	
	
	
    
    /* Y-major & X-Major line; calculate 16-bit fixed-point fractional part of a
    pixel that X advances each time Y advances 1 pixel, truncating the
        result so that we won't overrun the endpoint along the X axis */
        usErrorAdj = ((U32Bit) ucDeltaX << 16) / (U32Bit) ucDeltaY;
        /* Draw all pixels other than the first and last */
		ucDeltaY = ucDeltaY >> 1;
		
        while (ucDeltaY--) 
		{
            usErrorAccTemp = usErrorAcc;   /* remember currrent accumulated error */
            usErrorAcc += usErrorAdj;      /* calculate error for next pixel */
            if (usErrorAcc <= usErrorAccTemp) 
			{
                /* The error accumulator turned over, so advance the X coord */
                sX1 += ucXDir;
				sX2 -= ucXDir;
            }
            sY1++; 
			sY2--; /* Y-major, so always advance Y */
                  /* The IntensityBits most significant bits of usErrorAcc give us the
                  intensity weighting for this pixel, and the complement of the
            weighting for the paired pixel */
            usWeighting = usErrorAcc >> 8;
            
            
			ucColor=ucGlcdCalcColorValue(ucRl,ucRb,ucGl,ucGb,ucBl,ucBb,dGrayl,dGrayb,usWeighting,1);
            if(ucSwap)
			{	
				vGlcdSetPixel( sY1, sX1, ucColor );
				vGlcdSetPixel( sY2, sX2, ucColor );
			}				
			else
			{
				vGlcdSetPixel( sX1, sY1, ucColor );
				vGlcdSetPixel( sX2, sY2, ucColor );
			}	
            
            ucColor=ucGlcdCalcColorValue(ucRl,ucRb,ucGl,ucGb,ucBl,ucBb,dGrayl,dGrayb,usWeighting,0);
            if(ucSwap)
			{
				vGlcdSetPixel( sY1,sX1 + ucXDir , ucColor );
				vGlcdSetPixel( sY2, sX2 - ucXDir, ucColor );
			}	
			else
			{
				vGlcdSetPixel( sX1 + ucXDir, sY1, ucColor );
				vGlcdSetPixel( sX2 - ucXDir, sY2, ucColor );
			}	
        }
        
     
}
#endif