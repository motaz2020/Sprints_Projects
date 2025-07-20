/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <PORT_program.c>
 *       Module:  -
 *
 *  Description:  <Source File for Port Module Driver.>     
 *  
 *********************************************************************************************************************/



/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "port_driver.h"



/******************************************************************************
* \Syntax          : void Port_Init(const Port_ConfigType* ConfigPtr)     
* \Description     : Function to Initialize Port Module.                                                                                                              
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr - Pointer to configuration data                    
* \Parameters (out): None                                                      
* \Return value:   : None                                  
*******************************************************************************/
void Port_Init(const Port_ConfigType* ConfigPtr)
{
	/* TODO check for special ports that require lock and unlock */
	uint32_t i;
	for (i = 0; i < Port_count; i++)
	{
		uint8_t		pinOffset = ConfigPtr[i].PortChannelID & 7;
		uint8_t		portIndex = ConfigPtr[i].PortChannelID >> 3;
		GPIO_Type*	port      = Port_GPIO[portIndex];
		
		/* Enable clock for GPIO port in RCGCGPIO */

		BIT_BAND_PERIPH_SET(SYSCTL->RCGCGPIO, portIndex);
		
		/* Set the direction for the pin in GPIODIR, 1 OUTPUT, 0 INPUT */

		BIT_BAND_PERIPH(port->DIR, pinOffset) = (uint32_t)ConfigPtr[i].PortPinDirection;
				
		/* Configure GPIOAFSEL to program as GPIO or alternate pin */

		BIT_BAND_PERIPH(port->AFSEL, pinOffset) = (uint32_t)ConfigPtr[i].PortPinMode;
		
		/* Set drive strength through GPIODR2R, GPIODR4R, and GPIODR8R */
		switch(ConfigPtr[i].PortPinOutputCurrent)
		{
			case STRENGTH_2MA:

				BIT_BAND_PERIPH_SET(port->DR2R, pinOffset);
				break;
			case STRENGTH_4MA:

				BIT_BAND_PERIPH_SET(port->DR4R, pinOffset);
				break;
			case STRENGTH_8MA:

				BIT_BAND_PERIPH_SET(port->DR8R, pinOffset);
				break;
			case STRENGTH_8MA_SR:

				BIT_BAND_PERIPH_SET(port->DR8R, pinOffset);
				BIT_BAND_PERIPH_SET(port->SLR, pinOffset);
				break;
		}
		
		/* pull-up, pull-down, or open drain functionality through
		 * the GPIOPUR, GPIOPDR, GPIOODR
		 */
		switch(ConfigPtr[i].PortPinInternalAttach)
		{
			case PULL_UP:
//				port->PUR |= 1UL << pinOffset;
				BIT_BAND_PERIPH_SET(port->PUR, pinOffset);
				break;
			case PULL_DOWN:
//				port->PDR |= 1UL << pinOffset;
				BIT_BAND_PERIPH_SET(port->PDR, pinOffset);
				break;
			case OPEN_DRAIN:
//				port->ODR |= 1UL << pinOffset;
				BIT_BAND_PERIPH_SET(port->ODR, pinOffset);
				break;
		}
		
		/* Set the digital enable for the pin in GPIODEN */
		BIT_BAND_PERIPH(port->DEN, pinOffset) = 1UL;
		
		/* In case of output GPIO, set the output level */
		if (ConfigPtr[i].PortPinDirection && !ConfigPtr[i].PortPinMode)
		{
			#ifdef BITMASKING
			BIT_BAND_PERIPH(port->DATA_MAP[1UL<<pinOffset], pinOffset) = ConfigPtr[i].PortPinLevelValue;
			#else
			BIT_BAND_PERIPH(port->DATA, pinOffset) = ConfigPtr[i].PortPinLevelValue;
			#endif
		}
	}
}
