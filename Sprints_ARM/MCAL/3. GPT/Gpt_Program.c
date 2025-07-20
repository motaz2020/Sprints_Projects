/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Gpt_Program.c
 *        \brief  General purpose timer
 *
 *      \details  The Driver Configure All MCU Timers for specific usage
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Common_Macros.h"
#include "Gpt_Interface.h"
#include "Gpt_Private.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

void (*PtrToCallBackFunctionTimer0)(void);

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : void Gpt_Init(const GPT_ConfigType *configPtr)                                    
* \Description     : initialize Gpt Module for the specified timer used                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : configPtr - Pointer to GPT configuration data                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpt_Init(const GPT_ConfigType *configPtr)
{
    switch (configPtr->GPT_Id)
    {
    case TIMER0:
      SYSCTL_RCGCTIMER_R |= 0x01;
      SET_BIT(TIMER0_CFG_R, 2);
    	SET_BIT(TIMER0_TAMR_R, 4);

        if(configPtr->GPT_mode == CONTINUOUS )
        {
			SET_BIT(TIMER0_TAMR_R, 1);
		}
        else if(configPtr->GPT_mode == ONESHOT)
        {
			SET_BIT(TIMER0_TAMR_R, 0);
		}

        TIMER0_TAPR_R = (16000000/configPtr->GPT_TickFrequency);
        PtrToCallBackFunctionTimer0 = configPtr ->callBackFn;
        break;
    
    case TIMER1:
        break; 
    default:
        break;
    }
}

/******************************************************************************
* \Syntax          : void Gpt_EnableNotification(GPT_ChannelId id)                                    
* \Description     : Enabling interrupt notification for GPT module                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : id - Used Timer Id                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpt_EnableIntNotification(GPT_ChannelId id)
{
    switch(id)
    {
    case TIMER0:
        SET_BIT(TIMER0_IMR_R, 0);
        break;
    
    default:
        break;
    }
}

/******************************************************************************
* \Syntax          : void Gpt_DisableNotification(GPT_ChannelId id)                                   
* \Description     : Disabling interrupt notification for GPT module                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : id - Used Timer Id                      
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpt_DisableIntNotification(GPT_ChannelId id)
{
    switch (id)
    {
    case TIMER0:
        CLEAR_BIT(TIMER0_IMR_R, 0);
        break;
    
    default:
        break;
    }
}

/******************************************************************************
* \Syntax          : void Gpt_StartTimer(GPT_ChannelId id, GPT_ValueType val)                                    
* \Description     : start the timer operation                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : id - Used Timer Id  
*                    val - Value that timer reaches 

* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpt_StartTimer(GPT_ChannelId id, GPT_ValueType val)
{
    switch (id)
    {
    case TIMER0:
        TIMER0_CTL_R = 0x0;
        TIMER0_TAILR_R = val;
        TIMER0_TAPR_R = 0x02;
        TIMER0_ICR_R = 0x1; 
        TIMER0_CTL_R |= 0x03;
        /* while ((TIMER0_RIS_R & 0x1) == 0); */
        break;
    
    default:
        break;
    }
}

/******************************************************************************
* \Syntax          : void Gpt_StopTimer(GPT_ChannelId id)                                    
* \Description     : Stop the timer operation                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : id  - Used Timer Id 
                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpt_StopTimer(GPT_ChannelId id)
{
    switch(id)
    {
	case TIMER0:
    	CLEAR_BIT(TIMER0_CTL_R, 0);
		break;
	}
}

/******************************************************************************
* \Syntax          : void TIMER0A_Handler(void)                                    
* \Description     : Timer0 channel"A" ISR                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void TIMER0A_Handler(void)
{
    PtrToCallBackFunctionTimer0();
}

/**********************************************************************************************************************
 *  END OF FILE: Gpt_Program.c
 *********************************************************************************************************************/
