/*
 * RCC.c
 *
 *  Created on: Mar 1, 2026
 *      Author: Hamada
 */
#include "../../../Inc/MCAL/RCC/RCC.h"

Std_RetType_t HALL_RCC_OscConfig(RCC_OscInitTypedef *RCC_OscInitStruct)
{
	Std_RetType_t ret = RET_OK;
	if(NULL == RCC_OscInitStruct)
	{
		ret = RET_ERROR;
	}
	else
	{
		if(RCC_OSCILLATORTYPE_HSE == RCC_OscInitStruct->OscillatorType)
		{
			/*HSE oscillator ON*/
			SET_BIT(RCC->CR,RCC_CR_HSEON_POS);
			/*wait till HSE ready*/
			while(! READ_BIT(RCC->CR,RCC_CR_HSE_READY_POS) );
			/*select HSE oscillator as system clock*/
			SET_BIT(RCC->CFGR , RCC_CFGR_SW0_POS);
			CLEAR_BIT(RCC->CFGR,RCC_CFGR_SW1_POS);
			/*HSI OFF*/
			CLEAR_BIT(RCC->CR,RCC_CR_HSION_POS);

		}
		else if(RCC_OSCILLATORTYPE_HSI == RCC_OscInitStruct->OscillatorType)
		{
			//HSI oscillator ON
			SET_BIT(RCC->CR,RCC_CR_HSION_POS);
			/*wait till HSI ready*/
			while(! READ_BIT(RCC->CR,RCC_CR_HSI_READY_POS) );
			//HSI oscillator selected as system clock
			CLEAR_BIT(RCC->CFGR,RCC_CFGR_SW0_POS);
			CLEAR_BIT(RCC->CFGR,RCC_CFGR_SW1_POS);

			/*HSE oscillator OFF*/
			CLEAR_BIT(RCC->CR,RCC_CR_HSEON_POS);
		}
		else if(RCC_OSCILLATORTYPE_PLL == RCC_OscInitStruct->OscillatorType)
		{
			/* 1. Enable HSI */
			SET_BIT(RCC->CR,RCC_CR_HSION_POS);
			while(!READ_BIT(RCC->CR,RCC_CR_HSI_READY_POS));

			/* 2. Switch SYSCLK to HSI */
			CLEAR_BIT(RCC->CFGR,RCC_CFGR_SW0_POS);
			CLEAR_BIT(RCC->CFGR,RCC_CFGR_SW1_POS);
			while((RCC->CFGR & (3<<2)) != (0<<2));

			/* 3. Disable PLL */
			CLEAR_BIT(RCC->CR,RCC_CR_PLLON_POS);
			while(READ_BIT(RCC->CR,RCC_CR_PLL_READY_POS));

			/* 4. Select PLL source */
			if(RCC_PLL_SRC_HSE == RCC_OscInitStruct->PLL_Source_MUX)
			{
				SET_BIT(RCC->CR,RCC_CR_HSEON_POS);
				while(! READ_BIT(RCC->CR,RCC_CR_HSE_READY_POS) );

				SET_BIT(RCC->PLLCFGR,RCC_PLL_SRC_CFGR_POS);
			}
			else
			{
				CLEAR_BIT(RCC->PLLCFGR,RCC_PLL_SRC_CFGR_POS);
			}

			/* 5. Configure PLL factors */
			MODIFY_REG(RCC->PLLCFGR ,RCC_PLLM_CFGR_MASK ,  RCC_OscInitStruct->PLLMClkDivider);
			MODIFY_REG(RCC->PLLCFGR ,RCC_PLLN_CFGR_MASK ,  RCC_OscInitStruct->PLLNMultiplicationFactor);
			MODIFY_REG(RCC->PLLCFGR ,RCC_PLLP_CFGR_MASK ,  RCC_OscInitStruct->PLLPClkDivider);

			/* 6. Configure Flash latency (84MHz) */
			#define FLASH_ACR_REG   (*(volatile unsigned int*)0x40023C00)

			/* Clear LATENCY bits [2:0] */
			FLASH_ACR_REG &= ~(0x7);

			/* Set 2 wait states */
			FLASH_ACR_REG |= 0x2;

			/* 7. Enable PLL */
			SET_BIT(RCC->CR,RCC_CR_PLLON_POS);
			while(!READ_BIT(RCC->CR,RCC_CR_PLL_READY_POS));

			/* 8. Select PLL as SYSCLK */
			CLEAR_BIT(RCC->CFGR,RCC_CFGR_SW0_POS);
			SET_BIT(RCC->CFGR,RCC_CFGR_SW1_POS);
			while((RCC->CFGR & (3<<2)) != (2<<2));

		}
		else
		{
			/*Nothing*/
			ret = RET_ERROR;
		}
	}
	return ret;
}

Std_RetType_t HALL_RCC_ClockConfig(RCC_ClkInitTypedef *RCC_ClockInitStruct)
{
	Std_RetType_t ret = RET_OK;
	if(NULL == RCC_ClockInitStruct)
	{
		ret = RET_ERROR;
	}
	else
	{
		MODIFY_REG(RCC->CFGR ,RCC_CFGR_HPRE_MASK,  RCC_ClockInitStruct->AHBClkDivider);
		MODIFY_REG(RCC->CFGR ,RCC_CFGR_PPRE1_MASK, RCC_ClockInitStruct->APB1ClkDivider);
		MODIFY_REG(RCC->CFGR ,RCC_CFGR_PPRE2_MASK, RCC_ClockInitStruct->APB2ClkDivider);

	}
	return ret;
}

