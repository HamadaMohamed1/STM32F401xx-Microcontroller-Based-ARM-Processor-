/*
 * nvic.c
 *
 *  Created on: Mar 9, 2026
 *      Author: Hamada
 */

/************************************** 	Includes                   		**************************************/
#include "../../../Inc/Core_Prephirals/NVIC/nvic_interface.h"
/************************************** 	Function Definition	   			**************************************/
/**
 * @brief  : Enable interrupt from NVIC
 * @param  : (IRQNum) interrupt request number  @ref IRQn_Type
 * @return :
 * 			(RET_OK) : The function done successfully
 * 			(RET_ERROR) : The function has a problem to perform this action
 */
Std_RetType_t nvic_enable(IRQn_Type IRQNum)
{
	Std_RetType_t ret= RET_OK;
	uint8_t reg_number = 0;
	uint8_t bit_number = 0;
	if(IRQNum > SPI4_IRQn)  /*SPI4_IRQn is a higher IRQ number = 84*/
	{
		ret = RET_ERROR;
	}
	else
	{
		reg_number = (IRQNum / 32);
		bit_number = (IRQNum % 32);
		NVIC->ISER[reg_number] = (1 << bit_number);
	}
	return ret;
}
/**
 * @brief  : Disable interrupt from NVIC
 * @param  : (IRQNum) interrupt request number  @ref IRQn_Type
 * @return :
 * 			(RET_OK) : The function done successfully
 * 			(RET_ERROR) : The function has a problem to perform this action
 */
Std_RetType_t nvic_disable(IRQn_Type IRQNum)
{
	Std_RetType_t ret= RET_OK;
	uint8_t reg_number = 0;
	uint8_t bit_number = 0;
	if(IRQNum > SPI4_IRQn)  /*SPI4_IRQn is a higher IRQ number = 84*/
	{
		ret = RET_ERROR;
	}
	else
	{
		reg_number = (IRQNum / 32);
		bit_number = (IRQNum % 32);
		NVIC->ICER[reg_number] = (1 << bit_number);
	}
	return ret;
}
/**
 * @brief  : Set pending flag of interrupt from NVIC
 * @param  : (IRQNum) interrupt request number  @ref IRQn_Type
 * @return :
 * 			(RET_OK) : The function done successfully
 * 			(RET_ERROR) : The function has a problem to perform this action
 */
Std_RetType_t nvic_set_pending_flag(IRQn_Type IRQNum)
{
	Std_RetType_t ret= RET_OK;
	uint8_t reg_number = 0;
	uint8_t bit_number = 0;
	if(IRQNum > SPI4_IRQn)  /*SPI4_IRQn is a higher IRQ number = 84*/
	{
		ret = RET_ERROR;
	}
	else
	{
		reg_number = (IRQNum / 32);
		bit_number = (IRQNum % 32);
		NVIC->ISPR[reg_number] = (1 << bit_number);
	}
	return ret;
}
/**
 * @brief  : Clear pending flag of interrupt from NVIC
 * @param  : (IRQNum) interrupt request number  @ref IRQn_Type
 * @return :
 * 			(RET_OK) : The function done successfully
 * 			(RET_ERROR) : The function has a problem to perform this action
 */
Std_RetType_t nvic_clear_pending_flag(IRQn_Type IRQNum)
{
	Std_RetType_t ret= RET_OK;
	uint8_t reg_number = 0;
	uint8_t bit_number = 0;
	if(IRQNum > SPI4_IRQn)  /*SPI4_IRQn is a higher IRQ number = 84*/
	{
		ret = RET_ERROR;
	}
	else
	{
		reg_number = (IRQNum / 32);
		bit_number = (IRQNum % 32);
		NVIC->ICPR[reg_number] = (1 << bit_number);
	}
	return ret;
}
/**
 * @brief  : Set priority of interrupt from NVIC
 * @param  : (IRQNum) interrupt request number  @ref IRQn_Type
 * @return :
 * 			(RET_OK) : The function done successfully
 * 			(RET_ERROR) : The function has a problem to perform this action
 */
Std_RetType_t nvic_set_priority(IRQn_Type IRQNum,uint8_t priority)
{
	Std_RetType_t ret= RET_OK;
	if((IRQNum > SPI4_IRQn) || (0))  /*SPI4_IRQn is a higher IRQ number = 84*/
	{
		ret = RET_ERROR;
	}
	else
	{

	}
	return ret;
}
/**
 * @brief  : Get active flag of interrupt from NVIC
 * @param  : (IRQNum) interrupt request number  @ref IRQn_Type
 * @param  : (active_value) pointer to store active flag value @ref (INTERRUPT_NOT_ACTIVE , INTERRUPT_ACTIVE)
 * @return :
 * 			(RET_OK) : The function done successfully
 * 			(RET_ERROR) : The function has a problem to perform this action
 */
Std_RetType_t nvic_get_active_flag(IRQn_Type IRQNum , uint8_t *active_value)
{
	Std_RetType_t ret= RET_OK;
	uint8_t reg_number = 0;
	uint8_t bit_number = 0;
	if((IRQNum > SPI4_IRQn) || (NULL == active_value))  /*SPI4_IRQn is a higher IRQ number = 84*/
	{
		ret = RET_ERROR;
	}
	else
	{
		reg_number = (IRQNum / 32);
		bit_number = (IRQNum % 32);
		*active_value = READ_BIT(NVIC->IABR[reg_number],bit_number);
	}
	return ret;
}


