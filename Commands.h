/*==============================================================================
==
== FILE NAME:		Commands.h 
==
== DESCRIPTION:	Defines the set of commands for the Nokia Graphic LCD 6610 and 
==				compatible.
==  
== DATE				NAME					REASON
== ----				----					------
==	14Jan2009		Ankit Saxena		    Original
==	
==
==============================================================================*/

#ifndef __Commands_h__
#define __Commands_h__



#define     NO_OPERATION            0x00
#define     SOFT_RESET              0x01
#define     BOOSTER_OFF             0x02
#define     BOOSTER_ON              0x03
#define     DISPLAY_INFO            0x04
#define     DISPLAY_STATUS          0x09
#define     SLEEP_IN                0x10
#define     SLEEP_OUT               0x11
#define     PARTIAL_MODE_ON         0x12
#define     NORMAL_MODE_ON          0x13
#define     INVERSION_OFF           0x20
#define     INVERSION_ON            0x21
#define     PIXELS_OFF              0x22
#define     PIXELS_ON               0x23
#define     SET_CONTRAST            0x25
#define     DISPLAY_OFF             0x28
#define     DISPLAY_ON              0x29
#define     SET_X_ADDR              0x2A
#define     SET_Y_ADDR              0x2B
#define     MEM_WRITE               0x2C
#define     COLOR_SET               0x2D
#define     PARTIAL_AREA            0x30
#define     SCROLL_DEFINITON        0x33
#define     SET_SCROLL              0x37
#define     MEM_CONTROL             0x36
  #define   MEM_90                  0               // virtual flag for orientation, does not exist in PCF8833
  #define   MEM_180                 1               // virtual flag for orientation
  #define   MEM_RGB                 3
  #define   MEM_LAO                 4
  #define   MEM_VW                  5
  #define   MEM_MX                  6
  #define   MEM_MY                  7
#define     IDLE_OFF                0x38
#define     IDLE_ON                 0x39
#define     COLOR_INTERFACE         0x3A
  #define   COLOR_8_BIT             0x02
  #define   COLOR_12_BIT            0x03
  #define   COLOR_16_BIT            0x05
#define     SET_VOP                 0xB0
#define     BOTTOM_ROW_SWAP_OFF     0xB4
#define     BOTTOM_ROW_SWAP_ON      0xB5
#define     TOP_ROW_SWAP_OFF        0xB6
#define     TOP_ROW_SWAP_ON         0xB7
#define     SUPER_FRAME_INV_OFF     0xB8
#define     SUPER_FRAME_INV_ON      0xB9
#define     DATA_ORDER_MSB          0xBA
#define     DATA_ORDER_LSB          0xBB
#define     TEMP_READ               0xC8

#endif//__Commands_h__