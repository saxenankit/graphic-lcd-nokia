/*==============================================================================
==
== FILE NAME:
== 		PlotGrid.c
==
== DESCRIPTION:	
== 		Contains the function to plot the grid between two points.
==  
== DATE				NAME					REASON
== ----				----					------
== 14Jan2009		Ankit Saxena		   Original
==
== 10Jul2009		Ankit Saxena		   Modifications for better efficiency
==
==============================================================================*/
#include <avr/io.h>
#include "Line.c"
#include "CoreFunctions.c"
#include "DataTypes.h"
#include "glcd.h"

#ifndef PLOTGRID_C
#define PLOTGRID_C

/*******************************************************************************
** FUNCTION :
**       vGlcdPlotGrid
********************************************************************************
**
** Description :
**       This function is used to plot the grid on the screen
**
**	Arguments:
**					NAME		TYPE		DESCRIPTION
**			Input:		
**                  ucStart     U8Bit       The starting point of the grid
**					ucEnd		U8Bit		The end point of the gird
**                  
**			Returns:
**					void
**
*******************************************************************************/
void vGlcdPlotGrid(U8Bit ucStart,U8Bit ucEnd)
{
	U8Bit ucColor,ucTemp,ucSubDiv=0;
	ucTemp = ucStart;
	S16Bit sNearGrid=ucStart;
   
	vGlcdFillRect(ucStart,GRID_BOTTOM,ucEnd,GRID_TOP,BK_COLOR);//Clear the Area before plotting the Grid
	
	while( sNearGrid>0 )
	{
		sNearGrid-= MINOR_GRID;
		ucSubDiv++;
	}
   
	ucStart-= sNearGrid;		//setting the start to the nearest grid position
	
	if( ucSubDiv==0 )
		ucSubDiv=SUBDIV;
		
		
   //For Vertical Grid
  
	while( ucStart<=ucEnd )
	{	
		if( ucSubDiv == SUBDIV )
		{
			ucColor = MAJOR_GRID_COLOR;
			ucSubDiv = 0;
		}	
		else	
			ucColor = MINOR_GRID_COLOR;
		
		vGlcdFillRect(ucStart,GRID_BOTTOM,ucStart,GRID_TOP,ucColor);	
		
		ucStart+= MINOR_GRID;
		ucSubDiv++;
	}	
   
   //For Horizontal Grid
   
   ucSubDiv = SUBDIV;
   ucStart=GRID_BOTTOM;
   
   while ( ucStart<=GRID_TOP )
   {
		if( ucSubDiv == SUBDIV )
		{
			ucColor = MAJOR_GRID_COLOR;
			ucSubDiv = 0;
		}	
		else	
			ucColor = MINOR_GRID_COLOR;
		
		vGlcdFillRect(ucTemp,ucStart,ucEnd,ucStart,ucColor);
		
		ucStart+= MINOR_GRID;
		ucSubDiv++;
   }
	
}
#endif
