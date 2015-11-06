/*==============================================================================
==
== FILE NAME:		AntiAliasing.c
==
== DESCRIPTION:	Contains the main anti-aliasing functions used to calculate the  
==				colour values.
==  
== DATE				NAME					REASON
== ----				----					------
==	14Jan2009		Ankit Saxena		    Original
==	
==
==============================================================================*/


#include "glcd.h"
#include <math.h>

#ifndef ANTIALIASING_C
#define ANTIALIASING_C



/*********************************************************************************************************************************************
** FUNCTION :
**       ucGlcdCalcColorValue,ucGlcdColorValue
**********************************************************************************************************************************************
**
** Description :
**       This function is used to calculated the intensity of the bracketing pixels for the
**       Anti-Aliased line
**
**	Arguments:
**					NAME		  TYPE		  DESCRIPTION
**			Input:		
**					ucRl	      U8Bit		  the red component line color
**					ucGl          U8Bit       the green component line color
**                  ucBl          U8Bit       the blue component line color
**                  dGrayl        FLOAT8      it a calculated RBG component which is used as a decision parameter for deciding the weighting
**                  usWeighting   USHORT      it is the value which is derectly proportional to the pixel intesity
**                  sToggle       SHORT       it is a decsion parameter used to choose whether the pixel intensity to be plotted should be 
**                                            complemented or not
**			Returns:
**					ucColor       U8Bit       the calculated RGB value
**
**********************************************************************************************************************************************/
U8Bit ucGlcdCalcColorValue(U8Bit ucRl,U8Bit ucRb,U8Bit ucGl,U8Bit ucGb,U8Bit ucBl,U8Bit ucBb,FLOAT8 dGrayl,FLOAT8 dGrayb,USHORT usWeighting,SHORT sToggle)
{
    
	
	if(sToggle==1)
	{
	    SWAP_DOUBLE(dGrayl,dGrayb);
	}	
	
	U8Bit red= ucGlcdColorValue(ucRl,ucRb,usWeighting,dGrayl,dGrayb);
    
	U8Bit green=ucGlcdColorValue(ucGl,ucGb,usWeighting,dGrayl,dGrayb);
	
    U8Bit blue=ucGlcdColorValue(ucBl,ucBb,usWeighting,dGrayl,dGrayb);
	
	U8Bit ucColor=RGB(red,green,blue);
	return (ucColor);
}

U8Bit ucGlcdColorValue(U8Bit ucCl,U8Bit ucCb,USHORT usWeighting,FLOAT8 dGrayl,FLOAT8 dGrayb)
{
U8Bit ucColor=( ( U8Bit )( ( ( FLOAT8 )( dGrayl<dGrayb?usWeighting:(usWeighting ^ 0xFF)) ) 
		/ 255.0 * ( ucCb - ucCl ) + ucCl ) ) ;
	
	return(ucColor);	
}

/*******************************************************************************
** FUNCTION :
**       ucGetRValue(),ucGetGValue() and ucGetBValue()
********************************************************************************
**
** Description :
**       These functions returns the respective Red,Green or Blue value for a given input color
**
**	Arguments:
**					NAME	        TYPE		DESCRIPTION
**			Input:		
**                  ucColor         U8Bit       color
**
**                  
**			Returns:
**					ucRed,ucGreen   U8Bit       respective color
**                  or ucBlue
*******************************************************************************/
U8Bit ucGetRValue(U8Bit ucColor)
{
    U8Bit ucRed;
	ucRed=(ucColor&0xE0);
	return ucRed;
}

U8Bit ucGetGValue(U8Bit ucColor)
{
    U8Bit ucGreen;
    ucGreen= ((ucColor<<3)&0xE0);
	return ucGreen;
}

U8Bit ucGetBValue(U8Bit ucColor)
{
    U8Bit ucBlue;
    ucBlue=(ucColor<<6)	;
	return ucBlue;
}	

#endif