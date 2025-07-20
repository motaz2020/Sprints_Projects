/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <MCU_HW.h>
 *       Module:  -
 *
 *  Description:  <File for registers definition.>     
 *  
 *********************************************************************************************************************/


#ifndef __MCU_HW_H
#define __MCU_HW_H



/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

#include <stdint.h>
#include "register_map.h"

#define __IO volatile

#define PIOSC_FREQUENCY			16000000UL
#define SYSCLOCK_FREQUENCY	16000000UL

#define	APINT_KEY				0x05FAUL
#define APINT_KEY_POS		16
#define	APINT_KEY_MASK	(APINT_KEY	<<	APINT_KEY_POS)

/* Structure to define SysTick Registers*/
typedef struct
{
  __IO	uint32_t	STCTRL;
	__IO	uint32_t	STRELOAD;
	__IO	uint32_t	STCURRENT;
} SYSTICK_Type;


/* Bit Fields of SysTick Control and Status Register*/
#define	SYSTICK_STCTRL_ENABLE						0x0001UL
#define SYSTICK_STCTRL_ENABLE_OFFSET		0x0000UL
#define	SYSTICK_STCTRL_INTEN						0x0002UL
#define	SYSTICK_STCTRL_INTEN_OFFSET			0x0001UL
#define	SYSTICK_STCTRL_CLK_SRC					0x0004UL
#define	SYSTICK_STCTRL_CLK_SRC_OFFSET		0x0002UL


/* Structure to define System Handler Priority 1 Registers*/
typedef struct
{
  __IO	uint32_t	CPUID;
  __IO	uint32_t	INTCTRL;
  __IO	uint32_t	VTABLE;
  __IO	uint32_t	APINT;
  __IO	uint32_t	SYSCTRL;
  __IO	uint32_t	CFGCTRL;
  __IO	uint32_t	SYSPRI1;
	__IO	uint32_t	SYSPRI2;
	__IO	uint32_t	SYSPRI3;
  __IO	uint32_t	SYSHNDCTRL;
  __IO	uint32_t	FAULTSTAT;
  __IO	uint32_t	HFAULTSTAT;
  __IO	uint32_t	RESERVED0;
  __IO	uint32_t	MMADDR;
  __IO	uint32_t	FAULTADDR;
} SCB_Type;


/* Bit Fields of System Handler Priority 1 Register*/
#define SCB_SYSHNDCTRL_MEM		0x00010000UL
#define SCB_SYSHNDCTRL_BUS		0x00020000UL
#define SCB_SYSHNDCTRL_USAGE	0x00040000UL


/* Structure to define NVIC Registers*/
typedef struct
{
	__IO	uint32_t	EN[5];
	__IO	uint32_t	RESERVED0[27];
	__IO	uint32_t	DIS[5];
	__IO	uint32_t	RESERVED1[27];
	__IO	uint32_t	PEND[5];
	__IO	uint32_t	RESERVED2[27];
	__IO	uint32_t	UNPEND[5];
	__IO	uint32_t	RESERVED3[27];
	__IO	uint32_t	ACTIVE[5];
	__IO	uint32_t	RESERVED4[59];
	__IO	uint32_t	PRI[35];
	__IO	uint32_t	RESERVED5[669];
	__IO	uint32_t	SWTRIG;
} NVIC_Type;


/* Structure to define GPIO Registers*/
typedef struct
{
	__IO	uint32_t	DATA_MAP[255];							/* DATA virtual map	*/
	__IO	uint32_t	DATA;
	__IO	uint32_t	DIR;
	__IO	uint32_t	IS;
	__IO	uint32_t	IBE;
	__IO	uint32_t	IEW;
	__IO	uint32_t	IM;
	__IO	uint32_t	RIS;
	__IO	uint32_t	MIS;
	__IO	uint32_t	ICR;
	__IO	uint32_t	AFSEL;
	__IO	uint32_t	RESERVED2[55];							/*	(0x500 - 0x424)/4	*/
	__IO	uint32_t	DR2R;
	__IO	uint32_t	DR4R;
	__IO	uint32_t	DR8R;
	__IO	uint32_t	ODR;
	__IO	uint32_t	PUR;
	__IO	uint32_t	PDR;
	__IO	uint32_t	SLR;
	__IO	uint32_t	DEN;
	__IO	uint32_t	LOCK;
	__IO	uint32_t	CR;
	__IO	uint32_t	AMSEL;
	__IO	uint32_t	PCTL;
	__IO	uint32_t	ADCCTL;
	__IO	uint32_t	DMACTL;
} GPIO_Type;



typedef struct
{
	__IO	uint32_t	TODO[24];
	__IO	uint32_t	RCC;
	__IO	uint32_t	RESERVED[2];
	__IO	uint32_t	GPIOHBCTL;
	__IO	uint32_t	RCC2;
	__IO	uint32_t	TODO2[357];
	__IO	uint32_t	RCGCGPIO;
	__IO	uint32_t	TODO3[255];
	__IO	uint32_t	PRGPIO;
	__IO	uint32_t	TODO4[20];
} SYSCTL_Type;


/* Base Addresses of General-Purpose Input/Output Ports*/
#define	GPIOA				((GPIO_Type			*)	GPIOA_BASE)
#define	GPIOB				((GPIO_Type			*)	GPIOB_BASE)
#define	GPIOC				((GPIO_Type			*)	GPIOC_BASE)
#define	GPIOD				((GPIO_Type			*)	GPIOD_BASE)
#define	GPIOE				((GPIO_Type			*)	GPIOE_BASE)
#define	GPIOF				((GPIO_Type			*)	GPIOF_BASE)
#define	GPIOA_AHB		((GPIO_Type			*)	GPIOA_AHB_BASE)
#define	GPIOB_AHB		((GPIO_Type			*)	GPIOB_AHB_BASE)
#define	GPIOC_AHB		((GPIO_Type			*)	GPIOC_AHB_BASE)
#define	GPIOD_AHB		((GPIO_Type			*)	GPIOD_AHB_BASE)
#define	GPIOE_AHB		((GPIO_Type			*)	GPIOE_AHB_BASE)
#define	GPIOF_AHB		((GPIO_Type			*)	GPIOF_AHB_BASE)


/* Base Addresse of SYSCTL*/
#define SYSCTL			((SYSCTL_Type		*)	SYSCTL_BASE)


/* Base Addresse of SYSTICK*/
#define	SYSTICK			((SYSTICK_Type	*)	SYSTICK_BASE)

/* Base Addresse of SCB*/
#define	SCB					((SCB_Type			*)	SCB_BASE)

/* Base Addresse NVIC*/
#define	NVIC				((NVIC_Type			*)	NVIC_BASE)


 /*===========================================================*
 *            		Bit Banding Macros                        *
 *============================================================*/
#define	BIT_BAND_PERIPH(BIT_BAND_ADDRESS, BIT)			(*((uint32_t*)(BIT_BAND_PERIPH_BASE + ((((uint32_t)&BIT_BAND_ADDRESS - PERIPH_BASE) << 5) + ((uint32_t)BIT << 2)))))
#define BIT_BAND_PERIPH_SET(BIT_BAND_ADDRESS, BIT)	BIT_BAND_PERIPH(BIT_BAND_ADDRESS, BIT) = 1UL

#endif

/*End of File*/
