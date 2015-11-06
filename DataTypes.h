/*---------------------------------------------------*/
/* Integer type definitions for Graphic LCD  module */
/*-------------------------------------------------*/
/*===========================================================================
==
== FILE NAME:		integer.h
==
== DESCRIPTION:	    This file contains the datatype definitions for the 
==					Nokia(6610) Color LCD Graphic Screen.
==					
==					Changes  by Ankit Saxena
==					
==					 
==					
==					
==  
== DATE				NAME					REASON
== ----				----					------
==	14 Jan,2009		Ankit Saxena		   NPL convention
==
=============================================================================*/



#ifndef _INTEGER

				   
/* The following datatype definitions have been added for the 
   file glcdnew.c                                        */

typedef int				S16Bit;
typedef unsigned int	U16Bit;

typedef short			SHORT;
typedef unsigned short	USHORT;

typedef signed char		S8Bit;
typedef unsigned char	U8Bit;
typedef unsigned char	BOOLEAN;


typedef long			S32Bit;

typedef unsigned long	U32Bit;

typedef double			FLOAT8;
typedef float			FLOAT4;

                         // default SCREEN_COLOR background
#define SCREEN_COLOR0               WHITE

                         // default foreground color
#define SCREEN_COLOR1               BLACK

                         // default frame color
#define SCREEN_COLOR2               GRAY

                         // default shadow color
#define SCREEN_COLOR3               SILVER


#define SCREEN_COLOR                SCREEN_COLOR0

#define SCREEN_WIDTH                132   // Nokia 6100, only (1,1,130,130) are visible, but we need full access

#define SCREEN_HEIGHT               132   // to (0,0,131,131) to support hardware scrolling and splitting of display


#define SCREEN_LEFT                 1


#define SCREEN_TOP                  1


#define SCREEN_RIGHT                (SCREEN_WIDTH -2)


#define SCREEN_BOTTOM               (SCREEN_HEIGHT -2)

#define RESTART						129

#define COLOR_TABLE_BITS            2

#define FONT_HEADER_SIZE            7

#define TIME_STEP                   1

#define MINOR_GRID                  (10*TIME_STEP)

#define SUBDIV						10			//number of minor grids that make up one major grid.

#define MAJOR_GRID                  (SUBDIV*MINOR_GRID)

#define MAJOR_GRID_COLOR			GRID

#define MINOR_GRID_COLOR			GRAY

#define GRID_BOTTOM					12

#define GRID_TOP					115


#define _INTEGER
#endif
