/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <DIO.c>
 *       Module:  -
 *
 *  Description:  <Source File for DIO Module Driver.>     
 *  
 *********************************************************************************************************************/



/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


#include "../Inc/gpio.h"



/******************************************************************************
 * \Syntax          : Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
 * \Description     : Function to return the value of the specified DIO channel.
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : ChannelId - ID of DIO channel.
 * \Parameters (out): None
 * \Return value:   : Dio_LevelType(High-Low-Error) - the value of the specified DIO channel .
 *******************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
	uint8_t			pinOffset = ChannelId & 7;
	uint8_t			portIndex = ChannelId >> 3;
	GPIO_Type*	port      = Port_GPIO[portIndex];
	
	return BIT_BAND_PERIPH(port->DATA, pinOffset) ? HIGH : LOW;
	
}


/******************************************************************************
 * \Syntax          : void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
 * \Description     : Function to set a level of a channel .
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : ChannelId - ID of DIO channel.
 *                    Level - Value to be written.
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
	uint8_t			pinOffset = ChannelId & 7;
	uint8_t			portIndex = ChannelId >> 3;
	GPIO_Type*	port      = Port_GPIO[portIndex];
	
	
	/* Bit-Banding write to single channel */	
	
	BIT_BAND_PERIPH(port->DATA, pinOffset) = Level;
	
}



/******************************************************************************
 * \Syntax          : Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
 * \Description     : Function to return the value of the specified Port ID Level .
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : PortId - ID of Port.
 * \Parameters (out): None
 * \Return value:   : Dio_PortLevelType - Level of Port .
 *******************************************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
	return (Dio_PortLevelType) Port_GPIO[PortId]->DATA;
}



/******************************************************************************
 * \Syntax          : void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
 * \Description     : Function to set a level of a Port .
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : PortId - ID of Port.
 *                    Level - Level to be written.
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
	Port_GPIO[PortId]->DATA = Level;
}



/******************************************************************************
 * \Syntax          : Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
 * \Description     : Function to flip the level of a channel and return the level of the channel after flip.
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : ChannelId - ID of DIO channel.
 * \Parameters (out): None
 * \Return value:   : Dio_LevelType - Level of the specified channel after toggle .
 *******************************************************************************/
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
	uint8_t			pinOffset = ChannelId & 7;
	uint8_t			portIndex = ChannelId >> 3;
	GPIO_Type*	port      = Port_GPIO[portIndex];
	
	
	BIT_BAND_PERIPH(port->DATA, pinOffset) ^= 1UL;
	
	return BIT_BAND_PERIPH(port->DATA, pinOffset) ? HIGH : LOW;
}
