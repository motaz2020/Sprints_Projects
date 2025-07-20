/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <main.c>
 *       Module:  --
 * 
 *       Author: Esraa Ahmad 
 * 
 *  Description:  <main application (program entry)>     
 *  
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "../Inc/main.h"


/**********************************************************************************************************************
 *  GLOBAL VARIABLES
 *********************************************************************************************************************/

/* Time to turn ON/OFF in seconds */
float timeOn = 1;
float timeOff = 1;



/******************************************************************************
 * \Syntax             : int main (void)
 * \Description        : The Application Entry Point
 * \Sync\Async         : Synchronous
 * \Reentrancy         : Non Reentrant
 * \Parameters (in)    : None
 * \Parameters (inout) : None
 * \Parameters (out)   : None
 * \Return value:      : Std_ReturnType  E_OK
 *                                    E_NOT_OK
 *******************************************************************************/
int main(void)
{
	Port_PinLevelType SW1_lastState = HIGH;
	Port_PinLevelType SW2_lastState = HIGH;
	
	SysTick_Init();
	Port_Init( portConfig );
	IntCtrl_init();
	
	
	while(1)
	{
		Port_PinLevelType SW1_presentState = Dio_ReadChannel( PF4 );
		Port_PinLevelType SW2_presentState = Dio_ReadChannel( PF0 );
		
		/* Check for falling edge on SW1 */
		if( SW1_presentState == LOW && SW1_lastState != LOW )
		{
			SW1_lastState = LOW;
			
			timeOn = timeOn + 2;
			timeOff--;

			simulatedPWM_init( timeOn, timeOff );
		}
		else if( SW1_presentState == HIGH && SW1_lastState != HIGH )
		{
			SW1_lastState = HIGH;
		}

		/* Check for falling edge on SW2 */
		if( SW2_presentState == LOW && SW2_lastState != LOW )
		{
			SW2_lastState = LOW;
			timeOff = timeOff +2;
			timeOn--;

			simulatedPWM_init( timeOn, timeOff );
		}
		else if( SW2_presentState == HIGH && SW2_lastState != HIGH )
		{
			SW2_lastState = HIGH;
		}
		
	}
}
