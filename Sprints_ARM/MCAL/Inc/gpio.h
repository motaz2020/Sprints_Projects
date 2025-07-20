/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <DIO.h>
 *       Module:  DIO
 *
 *  Description:  <File for DIO Module.>     
 *  
 *********************************************************************************************************************/


#ifndef __GPIO_H
#define __GPIO_H


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "port_driver.h"




/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/* Type definition for Dio_ChannelType used by the DIO APIs */
typedef Port_ChannelType Dio_ChannelType;

/* Type definition for Dio_PortType used by the DIO APIs */
typedef uint8_t Dio_PortType;

/* Type definition for Dio_LevelType used by the DIO APIs */
typedef Port_PinLevelType Dio_LevelType;

/* Type definition for Dio_PortLevelType used by the DIO APIs */
typedef uint8_t Dio_PortLevelType;



/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/******************************************************************************
 * \Syntax          : Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
 * \Description     : Function to return the value of the specified DIO channel.
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : ChannelId - ID of DIO channel.
 * \Parameters (out): None
 * \Return value:   : Dio_LevelType - the value of the specified DIO channel .
 *******************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);


/******************************************************************************
 * \Syntax          : void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
 * \Description     : Function to set a level of a channel .
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : ChannelId - ID of DIO channel.
 *                    Level - Value to be written.
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/

void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);



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

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);


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
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);



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
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);

#endif
/*End of file*/
