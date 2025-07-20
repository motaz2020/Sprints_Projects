/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <STK_program.c>
 *       Module:  -
 *
 *  Description:  <Source File for Systick Module Driver.>     
 *  
 *********************************************************************************************************************/



/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


#include "../Inc/systick.h"


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/* Global pointer to function used to point upper layer functions
 * to be used in Call Back */
static Callback_function SysTick_callback = NULL;

static SysTick_ClockSrcType clockSrc = SYSTICK_CLOCK_SRC;



/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
 * \Syntax             : void SysTick_Handler(void)
 * \Description        : Interrupt Service Routine for SysTick .
 * \Sync\Async         : Synchronous
 * \Reentrancy         : Reentrant
 * \Parameters (in)    : None.
 * \Parameters (inout) : None
 * \Parameters (out)   : None
 * \Return value       : None
 *******************************************************************************/
void SysTick_Handler(void)
{
	/* Check if the SysTick_setCallBack is already called */
	if (SysTick_callback != NULL)
	{
		/* call the function using call-back concept */
		SysTick_callback();
	}
	else
    {
        /* Configurations Successfully */
        /* No Action Required */
    }
}


/******************************************************************************
* \Syntax          : SysTick_RegisterCallback(Callback_function callback_ptr)
* \Description     : Registers the callback function to the systick ISR                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Value                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

void SysTick_RegisterCallback(void(*Callback)(void))
{
	SysTick_callback = Callback;
}


/******************************************************************************
 * \Syntax             : void SysTick_Init(const SysTick_ConfigType* ConfigPtr)
 * \Description        : Function to Intialize the SysTick Module.
 * \Sync\Async         : Synchronous.
 * \Reentrancy         : NonReentrant.
 * \Parameters (in)    : ConfigPtr - Configuration of SysTick module.
 * \Parameters (inout) : None.
 * \Parameters (out)   : None.
 * \Return value:      : None.
 *******************************************************************************/
void SysTick_Init(void)
{
	/* Set STRELOAD */
//	SYSTICK->STRELOAD = MAXIMUM_TICKS-1;
	/* Clear STCURRENT by writing any value to it */
	SYSTICK->STCURRENT = 0UL;
	/* Configure STCTRL */
	SYSTICK->STCTRL |= (uint32_t)clockSrc << SYSTICK_STCTRL_CLK_SRC_OFFSET;
}

void SysTick_StopTimer(void)
{
	/* Clear ENABLE bit in STCTRL register (datasheet p.139) */
	SYSTICK->STCTRL &= ~(1UL << SYSTICK_STCTRL_ENABLE_OFFSET);
}

void SysTick_StartTimer(SysTick_ValueType Value)
{
	if (Value > 0 && Value <= MAXIMUM_TICKS)
	{
		SYSTICK->STRELOAD = Value - 1;
		SYSTICK->STCURRENT = 0UL;
		SYSTICK->STCTRL |= 1UL << SYSTICK_STCTRL_ENABLE_OFFSET;
	}
}

