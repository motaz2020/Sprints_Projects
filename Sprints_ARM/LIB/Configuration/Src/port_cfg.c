/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <PORT_Lcfg.c>
 *       Module:  Port
 *
 *  Description:  <Source File for Port modules configurations.>     
 *  
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "../../../MCAL/Inc/port_types.h"


/*
 * PB structure used with Port_Init API
 * Struct format: { Channel ID, Mode (GPIO|ALT), Output Level (HIGH|LOW), 
 *									Direction (INPUT|OUTPUT), ATTACHEMENT (PULL_DOWN|PULL_UP|OPEN_DRAIN) 
 *									Output current (STRENGTH_2MA|STRENGTH_4MA|STRENGTH_8MA|STRENGTH_8MA_SR)} 
*/

Port_ConfigType portConfig[] =
	{
		{PF1,	GPIO,	LOW,	OUTPUT,	OPEN_DRAIN,	STRENGTH_2MA},
		{PF4,	GPIO,	LOW,	INPUT,	PULL_UP,	STRENGTH_2MA},
		{PF0,	GPIO,	LOW,	INPUT,	PULL_UP,	STRENGTH_2MA}
	};
		

/* Calculating the size of the array */
uint32_t Port_count = sizeof(portConfig)/sizeof(portConfig[0]);


/**********************************************************************************************************************
 *  									END OF FILE
 *********************************************************************************************************************/
