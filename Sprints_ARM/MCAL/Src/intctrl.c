/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <NVIC.c>
 *       Module:  NVIC
 *
 *  Description:  <Source File for NVIC Module Driver.>     
 *  
 *********************************************************************************************************************/



/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "intctrl.h"




/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
 * \Syntax          : void IntCrtl_Init(void)
 * \Description     : initialize IntCrtl Module .
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/

void IntCtrl_init(void)
{
	/* TODO set the PRIMASK, FAULTMASK, and BASEPRI registers (datasheet p.85)	*/
	
	/*	Write to APINT to set the priority level */
	SCB->APINT	=		APINT_KEY_MASK	|	(PRIORITY_GROUPING	<<	8U);
	
	/*	Loop over all the interrupts in NVIC_Config									*/
	for ( uint8_t i = 0; i < IRQn_count; i++)
	{
		uint32_t tempPri;
		if 		(NVIC_Config[i].IRQn 	== 	MEM_MGMT_IRQn)
		{
			/* Set interrupt priority	*/
			/* Get PRI register				*/
			tempPri = SCB->SYSPRI1;
			/* Clear IRQn priority		*/
			tempPri &= ~(0x7UL << 5);
			/* Set new IRQn priority	*/
			tempPri |=	(uint32_t)NVIC_Config[i].priority << 5;
			SCB->SYSPRI1 = tempPri;
			
			/*	Enable or disable interrupt	 */
			if ( NVIC_Config[i].enable == IRQn_DISABLE )
			{
				/**
				 * Disable the memory management fault exception (datasheet p.174)
				 */
				SCB->SYSHNDCTRL	&=	~(SCB_SYSHNDCTRL_MEM);
			}
			
			else if ( NVIC_Config[i].enable == IRQn_ENABLE )
			{
				/*	Enable the memory management fault exception (datasheet p.174)	*/
				SCB->SYSHNDCTRL	|=	SCB_SYSHNDCTRL_MEM;
			}
		}
		
		else if	(NVIC_Config[i].IRQn 	== 	BUS_FAULT_IRQn)
		{
			/* Set interrupt priority	*/
			/* Get PRI register				*/
			tempPri = SCB->SYSPRI1;
			/* Clear IRQn priority		*/
			tempPri &= ~(0x7UL << 13);
			/* Set new IRQn priority	*/
			tempPri |=	(uint32_t)NVIC_Config[i].priority << 13;
			SCB->SYSPRI1 = tempPri;
			
			/*	Enable or disable interrupt																*/
			if ( NVIC_Config[i].enable == IRQn_DISABLE )
			{
				/*	Disable the bus fault exception (datasheet p.173)	*/
				SCB->SYSHNDCTRL	&=	~(SCB_SYSHNDCTRL_BUS);
			}
			
			else if ( NVIC_Config[i].enable == IRQn_ENABLE )
			{
				/*	Enable the bus fault exception (datasheet p.173)	*/
				SCB->SYSHNDCTRL	|=	SCB_SYSHNDCTRL_BUS;
			}
		}
		
		else if (NVIC_Config[i].IRQn 	== 	USAGE_FAULT_IRQn)
		{
			/* Set interrupt priority	*/
			/* Get PRI register				*/
			tempPri = SCB->SYSPRI1;
			/* Clear IRQn priority		*/
			tempPri &= ~(0x7UL << 21);
			/* Set new IRQn priority	*/
			tempPri |=	(uint32_t)NVIC_Config[i].priority << 21;
			SCB->SYSPRI1 = tempPri;
			
			/*	Enable or disable interrupt																*/
			if ( NVIC_Config[i].enable == IRQn_DISABLE )
			{
				/*	Disable the usage fault exception (datasheet p.173)	*/
				SCB->SYSHNDCTRL	&=	~(SCB_SYSHNDCTRL_USAGE);
			}
			
			else if ( NVIC_Config[i].enable == IRQn_ENABLE )
			{
				/*	Enable the usage fault exception (datasheet p.173)	*/
				SCB->SYSHNDCTRL	|=	SCB_SYSHNDCTRL_USAGE;
			}
		}
		
		else if (NVIC_Config[i].IRQn 	== 	SVCALL_IRQn)
		{
			/* No enable/disable, only handling priority programming */
			/* Set interrupt priority	*/
			/* Get PRI register				*/
			tempPri = SCB->SYSPRI2;
			/* Clear IRQn priority		*/
			tempPri &= ~(0x7UL << 29);
			/* Set new IRQn priority	*/
			tempPri |=	(uint32_t)NVIC_Config[i].priority << 29;
			SCB->SYSPRI2 = tempPri;
		}
			
		else if (NVIC_Config[i].IRQn 	== 	DEBUG_MONITOR_IRQn)
		{
			/* No enable/disable, only handling priority programming */
			/* Set interrupt priority	*/
			/* Get PRI register				*/
			tempPri = SCB->SYSPRI3;
			/* Clear IRQn priority		*/
			tempPri &= ~(0x7UL << 5);
			/* Set new IRQn priority	*/
			tempPri |=	(uint32_t)NVIC_Config[i].priority << 5;
			SCB->SYSPRI3 = tempPri;
		}
			
		else if (NVIC_Config[i].IRQn 	== 	PENDSV_IRQn)
		{
			/* No enable/disable, only handling priority programming */
			/* Set interrupt priority	*/
			/* Get PRI register				*/
			tempPri = SCB->SYSPRI3;
			/* Clear IRQn priority		*/
			tempPri &= ~(0x7UL << 21);
			/* Set new IRQn priority	*/
			tempPri |= (uint32_t)NVIC_Config[i].priority << 21;
			SCB->SYSPRI3 = tempPri;
		}
		
		else if (NVIC_Config[i].IRQn 	== 	SYSTICK_IRQn)
		{
			/* Set interrupt priority	*/
			/* Get PRI register				*/
			tempPri = SCB->SYSPRI3;
			/* Clear IRQn priority		*/
			tempPri &= ~(0x7UL << 29);
			/* Set new IRQn priority	*/
			tempPri |=	(uint32_t)NVIC_Config[i].priority << 29;
			SCB->SYSPRI3 = tempPri;
			
			/*	Enable or disable interrupt																*/
			if ( NVIC_Config[i].enable == IRQn_DISABLE )
			{
				/*	Disable the SysTick interrupt generation (datasheet p.139)	*/
				SYSTICK->STCTRL	|=	SYSTICK_STCTRL_INTEN;
			}
			
			else if ( NVIC_Config[i].enable == IRQn_ENABLE )
			{
				/*	Enable the SysTick interrupt generation (datasheet p.139)	*/
				SYSTICK->STCTRL	|=	SYSTICK_STCTRL_INTEN;
			}
		}
		
		/* ___________ Peripheral Interrupts ___________*/
		else if (NVIC_Config[i].IRQn 	>= 	0)
		{
			/* Get PRI register				*/
			tempPri	= NVIC->PRI[NVIC_Config[i].IRQn/4];
			/* Clear IRQn priority		*/
			tempPri	&= ~(0x7UL << (((NVIC_Config[i].IRQn & 3) * 8) + 5));
			/* Set new IRQn priority	*/
			tempPri |=	(uint32_t)NVIC_Config[i].priority << (((NVIC_Config[i].IRQn & 3) * 8) + 5);
			NVIC->PRI[NVIC_Config[i].IRQn/4] = tempPri;
			
			/*	Enable or disable interrupt																*/
			if ( NVIC_Config[i].enable == IRQn_DISABLE )
			{
				/*	Set the DISx register for the interrupt type (datasheet p.144)	*/
				NVIC->DIS[NVIC_Config[i].IRQn/32]	=	1UL	<<	(NVIC_Config[i].IRQn	&	31);
			}
			
			else if ( NVIC_Config[i].enable == IRQn_ENABLE )
			{
				/*	Set the ENx register for the interrupt type (datasheet p.142)	*/
				NVIC->EN[NVIC_Config[i].IRQn/32]	=	1UL	<<	(NVIC_Config[i].IRQn	&	31);
			}
		}
	}
}
