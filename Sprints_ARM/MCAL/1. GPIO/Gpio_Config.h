/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Gpio_Config.h
 *       Module:  -
 *
 *  Description:  Configuration file for Gpio Module    
 *  
 *********************************************************************************************************************/
#ifndef GPIO_CONFIG_H
#define GPIO_CONFIG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define NUM_OF_PORTS		                     	6

#define NUM_OF_PINS_PER_PORTA	                8
#define NUM_OF_PINS_PER_PORTB	                8
#define NUM_OF_PINS_PER_PORTC	                8
#define NUM_OF_PINS_PER_PORTD	                8
#define NUM_OF_PINS_PER_PORTE	                6
#define NUM_OF_PINS_PER_PORTF	                6

#define PORTA_ID				                      0
#define PORTB_ID				                      1
#define PORTC_ID				                      2
#define PORTD_ID				                      3
#define PORTE_ID				                      4
#define PORTF_ID				                      5

#define PIN0_ID					                      0
#define PIN1_ID					                      1
#define PIN2_ID					                      2
#define PIN3_ID					                      3
#define PIN4_ID					                      4
#define PIN5_ID					                      5
#define PIN6_ID					                      6
#define PIN7_ID					                      7

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
  PIN_INPUT, PIN_OUTPUT
}GPIO_PinDirectionType;

typedef enum
{
  PORT_INPUT, PORTF_OUTPUT=0x1F, PORTE_OUTPUT=0x3F, PORTA_OUTPUT=0xFF, PORTB_OUTPUT=0xFF, PORTC_OUTPUT=0xFF, PORTD_OUTPUT=0xFF  
}GPIO_PortDirectionType;

typedef enum
{
  NO_PULL, PULL_DOWN, PULL_UP
}GPIO_PullType;

 
#endif  /* GPIO_CONFIG_H */

/**********************************************************************************************************************
 *  END OF FILE: Gpio_Config.h
 *********************************************************************************************************************/
