/*==============================================================================
==
== FILE NAME:
== 		PlotTrace.c
==
== DESCRIPTION:	
== 		COntains the description of curve tracing and software scrolling
==  
== DATE				NAME					REASON
== ----				----					------
== 14Jan2009		Ankit Saxena		   Original
==
==============================================================================*/

#include <avr/io.h>
#include "Line.c"
#include "CoreFunctions.c"
#include "DataTypes.h"


#ifndef PLOTTRACE_C
#define PLOTTRACE_C


U8Bit ucLastPoint=65,ucTime=1;// just to plot the first point on the left-centre of the screen.

/*******************************************************************************
** FUNCTION :
**       vGlcdPlotTrace
********************************************************************************
**
** Description :
**       This function is used to plot the curve on the screen and also porvide software
**		 scrolling.
**	Arguments:
**					NAME	       	TYPE		DESCRIPTION
**			Input:		
**                  ucNewPoint      U8Bit       Contains the value of the new point to be plotted.
**					ucColor         U8Bit 		The colour of the curve. 
**                  
**			Returns:
**					void
**
*******************************************************************************/
void vGlcdPlotTrace(U8Bit ucNewPoint, U8Bit ucColor)
{
	
	ucNewPoint=GRID_TOP-ucNewPoint;				//can be commented out, especially when not using the Screen in the 90deg mode.
	
	if( ucTime <= (RESTART) )
	{
		vGlcdPlotGrid(ucTime+1,(ucTime+(2*TIME_STEP)));
	}	
	else
	{
		ucTime=1;
		vGlcdPlotGrid(ucTime,(ucTime+(TIME_STEP)));
	}	
  
	vGlcdAALine(ucTime,ucLastPoint,ucTime+TIME_STEP,ucNewPoint,ucColor);/*taken the time step as TIME_STEP pixels*/
	ucLastPoint=ucNewPoint;
	ucTime+=TIME_STEP;
  	
}  


#endif  
 