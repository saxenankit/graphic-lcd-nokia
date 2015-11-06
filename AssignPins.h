/*==============================================================================
==
== FILE NAME:		AssignPins.h 
==
== DESCRIPTION:	Pin assignments of various ports of AVRMeg8 and avr include
==				files.
==  
== DATE				NAME					REASON
== ----				----					------
==	14Jan2009		Ankit Saxena		    Original
==	
==
==============================================================================*/

#ifndef __AssignPins_h__
#define __AssignPins_h__
  
  
#define F_CPU 12000000UL 
  
// -------------------- PORT B ---------------

// This port is used for LCD

  #define   LCD_PORT                PORTB
  #define   LCD_PIN                 PINB
  #define   LCD_DDR                 (DDRB)
  #define   LCD_CS                  PINB2   // SS/CE
  #define   LCD_SDA                 PINB3   // MOSI
  #define   LCD_RESET               PINB4   // MISO
  #define   LCD_SCL                 PINB5   // SCK
  #define   LCD_CE                  PINB2
  #define   LCD_SER_PORT            (PORTB)
  #define   LCD_CTRL_PORT           (PORTB)
  #define   LCD_SER_DDR             (DDRB)
  #define   LCD_CTRL_DDR            (DDRB)
  

/*Definition all the control registers */
#define LCD_SPCR                    (SPCR)
#define LCD_SPDR                    (SPDR)
#define LCD_SPSR                    (SPSR)



#endif // __AssignPins_h__