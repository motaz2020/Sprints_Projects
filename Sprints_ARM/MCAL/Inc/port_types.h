/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <port_types.h>
 *       Module:  -
 *
 *  Description:  <File for API Types Of MC. Port.>     
 *  
 *********************************************************************************************************************/

#ifndef __PORT_TYPES_H
#define __PORT_TYPES_H



/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include <stdint.h>
#include "../../LIB/Common/Inc/mcu_hw.h"

typedef enum
{
	PA0,
	PA1,
	PA2,
	PA3,
	PA4,
	PA5,
	PA6,
	PA7,
	
	PB0,
	PB1,
	PB2,
	PB3,
	PB4,
	PB5,
	PB6,
	PB7,
	
	PC0,
	PC1,
	PC2,
	PC3,
	PC4,
	PC5,
	PC6,
	PC7,
	
	PD0,
	PD1,
	PD2,
	PD3,
	PD4,
	PD5,
	PD6,
	PD7,
	
	PE0,
	PE1,
	PE2,
	PE3,
	PE4,
	PE5,
	
	PF0 = 40,
	PF1,
	PF2,
	PF3,
	PF4,
} Port_ChannelType;

typedef enum
{
	GPIO,
	ALT
} Port_PinModeType;

typedef enum
{
	LOW,
	HIGH
} Port_PinLevelType;

typedef enum
{
	INPUT,
	OUTPUT
}	Port_PinDirectionType;

typedef enum
{
	PULL_UP,
	PULL_DOWN,
	OPEN_DRAIN
} Port_PinInternalAttachType;

typedef enum
{
	STRENGTH_2MA,
	STRENGTH_4MA,
	STRENGTH_8MA,
	STRENGTH_8MA_SR
} Port_PinOutputCurrentType;

typedef struct
{
	Port_ChannelType						PortChannelID;
	Port_PinModeType						PortPinMode;
	Port_PinLevelType						PortPinLevelValue;
	Port_PinDirectionType				PortPinDirection;
	Port_PinInternalAttachType	PortPinInternalAttach;
	Port_PinOutputCurrentType		PortPinOutputCurrent;
} Port_ConfigType;

static GPIO_Type* Port_GPIO[] = 
{
	GPIOA,
	GPIOB,
	GPIOC,
	GPIOD,
	GPIOE,
	GPIOF
};

extern Port_ConfigType portConfig[];
extern uint32_t Port_count;

#endif
