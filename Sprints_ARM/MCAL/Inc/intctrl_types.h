/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <intctrl_types.h>
 *       Module:  -
 *
 *  Description:  <File for API Types Of NVIC module.>     
 *  
 *********************************************************************************************************************/



#ifndef __INTCTRL_TYPES_H
#define __INTCTRL_TYPES_H

typedef enum
{
	/* Exceptions */
	RESET_IRQn					=-15,
	NMI_IRQn					=-14,
	HARD_FAULT_IRQn				=-13,
	MEM_MGMT_IRQn				=-12,
	BUS_FAULT_IRQn				=-11,
	USAGE_FAULT_IRQn			=-10,
	SVCALL_IRQn					=-5,
	DEBUG_MONITOR_IRQn			=-4,
	PENDSV_IRQn					=-2,
	SYSTICK_IRQn				=-1,
	
	/* Interrupts */
	GPIOA_IRQn					=	0,
	GPIOB_IRQn					=	1,
	GPIOC_IRQn					=	2,
	GPIOD_IRQn					=	3,
	GPIOE_IRQn					=	4,
	UART0_IRQn					=	5,
	UART1_IRQn					=	6,
	SSI0_IRQn					=	7,
	I2C0_IRQn					=	8,
	PWM0_FAULT_IRQn				=	9,
	PWM0_GEN0_IRQn				=	10,
	PWM0_GEN1_IRQn				=	11,
	PWM0_GEN2_IRQn				=	12,
	QEI0_IRQn					=	13,
	ADC0_SEQ0_IRQn				=	14,
	ADC0_SEQ1_IRQn				=	15,
	ADC0_SEQ2_IRQn				=	16,
	ADC0_SEQ3_IRQn				=	17,
	WDT0_IRQn					=	18,
	TIMER0A_IRQn				=	19,
	TIMER0B_IRQn				=	20,
	TIMER1A_IRQn				=	21,
	TIMER1B_IRQn				=	22,
	TIMER2A_IRQn				=	23,
	TIMER2B_IRQn				=	24,
	ACOMP0_IRQn					=	25,
	ACOMP1_IRQn					=	26,
	SYSCTL_IRQn					=	28,
	FLASH_MEMCTL_IRQn			=	29,
	GPIOF_IRQn					=	30,
	UART2_IRQn					=	33,
	SSI1_IRQn					=	34,
	TIMER3A_IRQn				=	35,
	TIMER3B_IRQn				=	36,
	I2C1_IRQn					=	37,
	QEI1_IRQn					=	38,
	CAN0_IRQn					=	39,
	CAN1_IRQn					=	40,
	HIB_IRQn					=	43,
  USB0_IRQn						=	44,
  PWM0_GEN3_IRQn			=	45,
  UDMA_IRQn					=	46,
  UDMA_ERR_IRQn				=	47,
  ADC1_SEQ0_IRQn			=	48,
  ADC1_SEQ1_IRQn			=	49,
  ADC1_SEQ2_IRQn			=	50,
  ADC1_SEQ3_IRQn			=	51,
  SSI2_IRQn					=	57,
  SSI3_IRQn					=	58,
  UART3_IRQn				=	59,
  UART4_IRQn				=	60,
  UART5_IRQn				=	61,
  UART6_IRQn				=	62,
  UART7_IRQn				=	63,
  I2C2_IRQn					=	68,
  I2C3_IRQn					=	69,
  TIMER4A_IRQn				=	70,
  TIMER4B_IRQn				=	71,
  TIMER5A_IRQn				=	92,
  TIMER5B_IRQn				=	93,
  WTIMER0A_IRQn				=	94,
  WTIMER0B_IRQn				=	95,
  WTIMER1A_IRQn				=	96,
  WTIMER1B_IRQn				=	97,
  WTIMER2A_IRQn				=	98,
  WTIMER2B_IRQn				=	99,
  WTIMER3A_IRQn				=	100,
  WTIMER3B_IRQn				=	101,
  WTIMER4A_IRQn				=	102,
  WTIMER4B_IRQn				=	103,
  WTIMER5A_IRQn				=	104,
  WTIMER5B_IRQn				=	105,
  SYSEXC_IRQn				=	106,
  PWM1_0_IRQn				=	134,
  PWM1_1_IRQn				=	135,
  PWM1_2_IRQn				=	136,
  PWM1_3_IRQn				=	137,
  PWM1_FAULT_IRQn			=	138 
} IntCtrl_InterruptType;

typedef enum
{
	IRQn_DISABLE,
	IRQn_ENABLE
}	IntCtrl_EnableType;

typedef enum
{
	IRQn_PRI_0,
	IRQn_PRI_1,
	IRQn_PRI_2,
	IRQn_PRI_3,
	IRQn_PRI_4,
	IRQn_PRI_5,
	IRQn_PRI_6,
	IRQn_PRI_7
}	IntCtrl_PriorityLevelType;



/* Type definition for NVIC_ConfigType used by the NVIC APIs */
typedef struct
{
	IntCtrl_InterruptType				IRQn;
	IntCtrl_EnableType					enable;
	IntCtrl_PriorityLevelType		priority;
} NVIC_ConfigType;


/* Groups Priority*/
#define	PRIGROUP_8_1	0UL
#define	PRIGROUP_4_2	5UL
#define	PRIGROUP_2_4	6UL
#define	PRIGROUP_1_8	7UL

#endif
