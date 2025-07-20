/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <register_map.h>
 *       Module:  -
 *
 *  Description:  <File for registers mapping.>     
 *  
 *********************************************************************************************************************/


#ifndef __REGISTER_MAP_H
#define __REGISTER_MAP_H

#define	CORE_PERIPH_BASE				0xE000E000UL
#define	SYSTICK_BASE						(CORE_PERIPH_BASE	+	0x0010UL)
#define	NVIC_BASE								(CORE_PERIPH_BASE	+	0x0100UL)
#define	SCB_BASE								(CORE_PERIPH_BASE + 0x0D00UL)

#define	SYSCTL_BASE							0x400FE000UL

#define	BIT_BAND_PERIPH_BASE		0x42000000UL
#define	PERIPH_BASE							0x40000000UL

#define	GPIOA_BASE							0x40004000UL
#define	GPIOB_BASE							0x40005000UL
#define	GPIOC_BASE							0x40006000UL
#define	GPIOD_BASE							0x40007000UL
#define	GPIOE_BASE							0x40024000UL
#define	GPIOF_BASE							0x40025000UL
#define	GPIOA_AHB_BASE					0x40058000UL
#define	GPIOB_AHB_BASE					0x40059000UL
#define	GPIOC_AHB_BASE					0x4005A000UL
#define	GPIOD_AHB_BASE					0x4005B000UL
#define	GPIOE_AHB_BASE					0x4005C000UL
#define	GPIOF_AHB_BASE					0x4005D000UL

#endif

/*End of file*/
