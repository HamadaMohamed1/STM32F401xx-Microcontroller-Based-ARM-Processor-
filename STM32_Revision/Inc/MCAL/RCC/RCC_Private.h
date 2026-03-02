/*
 * RCC_Private.h
 *
 *  Created on: Mar 1, 2026
 *      Author: Hamada
 */

#ifndef MCAL_RCC_RCC_PRIVATE_H_
#define MCAL_RCC_RCC_PRIVATE_H_


						/*APB1ENR Register*/
#define RCC_APB1ENR_USART2_POS		 (17UL)

#define RCC_APB1ENR_SPI3_POS 		 (15UL)
#define RCC_APB1ENR_SPI2_POS 		 (14UL)

#define RCC_APB1ENR_I2C1_POS 		 (21UL)
#define RCC_APB1ENR_I2C2_POS 		 (22UL)
#define RCC_APB1ENR_I2C3_POS 		 (23UL)


						/*APB2ENR Register*/
#define RCC_APB2ENR_SYSCFG_POS 		(14UL)

#define RCC_APB2ENR_USART1_POS 		(4UL)
#define RCC_APB2ENR_USART6_POS 		(5UL)



#define RCC_APB2ENR_SPI1_POS 		(12UL)
#define RCC_APB2ENR_SPI4_POS 		(13UL)

/*******************AHB1ENR Register*******************/
#define RCC_AHB1ENR_GPIOA_POS 		(0UL)
#define RCC_AHB1ENR_GPIOB_POS 		(1UL)
#define RCC_AHB1ENR_GPIOC_POS 		(2UL)
#define RCC_AHB1ENR_GPIOD_POS 		(3UL)
#define RCC_AHB1ENR_GPIOE_POS 		(4UL)
#define RCC_AHB1ENR_GPIOH_POS 		(7UL)

/*******************Oscillator type*******************/

#define RCC_OSCILLATORTYPE_HSE		(0X00000001UL)
#define RCC_OSCILLATORTYPE_HSI		(0X00000002UL)
#define RCC_OSCILLATORTYPE_PLL		(0X00000004UL)




#define RCC_HSE_OFF					(0x00)
#define RCC_HSE_ON					(0x01)

#define RCC_HSI_OFF					(0x00)
#define RCC_HSI_ON					(0x01)

#define RCC_PLL_OFF					(0x00)
#define RCC_PLL_ON					(0x01)


/*******************RCC_CR Register*******************/
#define RCC_CR_HSEON_POS 		    (16UL)
#define RCC_CR_HSE_READY_POS	    (17UL)

#define RCC_CR_HSION_POS 		    (0UL)
#define RCC_CR_HSI_READY_POS	    (1UL)

#define RCC_CR_PLLON_POS 		    (24UL)
#define RCC_CR_PLL_READY_POS 	    (25UL)

/*******************RCC_CFGR Register*******************/


#define RCC_CFGR_SW0_POS 		    (0U)
#define RCC_CFGR_SW1_POS 		    (1U)

#define RCC_CFGR_HPRE_POS 		    (4U)
#define RCC_CFGR_HPRE_MASK 		    (0xF << RCC_CFGR_HPRE_POS)

#define RCC_CFGR_PPRE1_POS 		    (10U)
#define RCC_CFGR_PPRE1_MASK 		(0xF << RCC_CFGR_PPRE1_POS)

#define RCC_CFGR_PPRE2_POS 		    (13U)
#define RCC_CFGR_PPRE2_MASK 		(0xF << RCC_CFGR_PPRE2_POS)


/*******************PLL_CFGR Register*******************/
#define RCC_PLLM_CFGR_POS 		    (0U)
#define RCC_PLLM_CFGR_MASK			(0xF << RCC_PLLM_CFGR_POS)


#define RCC_PLLN_CFGR_POS 		    (6U)
#define RCC_PLLN_CFGR_MASK			(0xF << RCC_PLLN_CFGR_POS)

#define RCC_PLLP_CFGR_POS 		    (16U)
#define RCC_PLLP_CFGR_MASK			(0xF << RCC_PLLP_CFGR_POS)

#define RCC_PLL_SRC_CFGR_POS 	    (22U)

/*******************AHB Prescaler Values*******************/
#define RCC_CFGR_HPRE_DIV1			(0x00000000UL)
#define RCC_CFGR_HPRE_DIV2			(0x00000080UL)
#define RCC_CFGR_HPRE_DIV4			(0x00000090UL)
#define RCC_CFGR_HPRE_DIV8			(0x000000A0UL)
#define RCC_CFGR_HPRE_DIV16			(0x000000B0UL)
#define RCC_CFGR_HPRE_DIV64			(0x000000C0UL)
#define RCC_CFGR_HPRE_DIV128		(0x000000D0UL)
#define RCC_CFGR_HPRE_DIV256		(0x000000E0UL)
#define RCC_CFGR_HPRE_DIV512		(0x000000F0UL)

/*******************APB1 Prescaler Values*******************/
#define RCC_CFGR_PPRE1_DIV1			(0x00000000UL)
#define RCC_CFGR_PPRE1_DIV2	   		(0x00001000UL)
#define RCC_CFGR_PPRE1_DIV4			(0x00001400UL)
#define RCC_CFGR_PPRE1_DIV8			(0x00001800UL)
#define RCC_CFGR_PPRE1_DIV16		(0x00001C00UL)

/*******************APB2 Prescaler Values*******************/
#define RCC_CFGR_PPRE2_DIV1			(0x00000000UL)
#define RCC_CFGR_PPRE2_DIV2	   		(0x00008000UL)
#define RCC_CFGR_PPRE2_DIV4			(0x0000A000UL)
#define RCC_CFGR_PPRE2_DIV8			(0x0000C000UL)
#define RCC_CFGR_PPRE2_DIV16		(0x0000E000UL)

/*******************PLL source MUX Values*******************/
#define RCC_PLL_SRC_HSI				(0x00000000UL)	/*0000 0000 0-00 0000 0000 0000 0000 0000*/
#define RCC_PLL_SRC_HSE				(0x00400000UL)


/*******************PLLM Prescaler Values*******************/



#define RCC_PLLCFGR_PLLM_DIV2		(0x00000002UL)   /*0000 0000 0000 0000 0000 0000 00-- ----*/
#define RCC_PLLCFGR_PLLM_DIV3		(0x00000003UL)	 /*0000 0000 0000 0000 0000 0000 0000 1000*/
#define RCC_PLLCFGR_PLLM_DIV4		(0x00000004UL)
#define RCC_PLLCFGR_PLLM_DIV5		(0x00000005UL)
#define RCC_PLLCFGR_PLLM_DIV6		(0x00000006UL)
#define RCC_PLLCFGR_PLLM_DIV7		(0x00000007UL)
#define RCC_PLLCFGR_PLLM_DIV8		(0x00000008UL)
/*						.
 * 						.
 * 						.
 * */
#define RCC_PLLCFGR_PLLM_DIV63		(0x0000003FUL)

/*******************PLLP Prescaler Values*******************/
#define RCC_PLLCFGR_PLLP_DIV2		(0x00000000UL)   /*0000 0000 0000 00-- 0000 0000 0000 0000*/
#define RCC_PLLCFGR_PLLP_DIV4		(0x00010000UL)	 /*0000 0000 0000 0011 0000 0000 0000 0000*/
#define RCC_PLLCFGR_PLLP_DIV6		(0x00020000UL)
#define RCC_PLLCFGR_PLLP_DIV8		(0x00030000UL)

/*******************PLLN Multiplication Factor Values*******************/
#define RCC_PLLCFGR_PLLN_TIMES_50	(0x00000C80UL)   /*0000 0000 0000 0000 0--- ---- --00 0000*/
#define RCC_PLLCFGR_PLLN_TIMES_51	(0x00000CC0UL)	 /*0000 0000 0000 0000 0001 0101 0000 0000*/
/*						.
 * 						.
 * 						.
 * */
#define RCC_PLLCFGR_PLLN_TIMES_62	(0x00000F80UL)
#define RCC_PLLCFGR_PLLN_TIMES_63	(0x00000FC0UL)
/*						.
 * 						.
 * 						.
 * */
#define RCC_PLLCFGR_PLLN_TIMES_84	(0x00001500UL)
/*						.
 * 						.
 * 						.
 * */
#define RCC_PLLCFGR_PLLN_TIMES_432	(0x00006C00UL)







#endif /* MCAL_RCC_RCC_PRIVATE_H_ */
