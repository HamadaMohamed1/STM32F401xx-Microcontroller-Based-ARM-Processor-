/*
 * nvic_interface.h
 *
 *  Created on: Mar 9, 2026
 *      Author: Hamada
 */

#ifndef CORE_PREPHIRALS_NVIC_NVIC_INTERFACE_H_
#define CORE_PREPHIRALS_NVIC_NVIC_INTERFACE_H_
/************************************** 	Includes                   		**************************************/
#include "nvic_private.h"
/************************************** 	Macro Declaration          		**************************************/
/************************************** 	Macro Function Declaration 		**************************************/
/************************************** 	Data Type Declaration      		**************************************/
/************************************** 	Function Declaration	   		**************************************/
/**
 * @brief  : Enable interrupt from NVIC
 * @param  : (IRQNum) interrupt request number  @ref IRQn_Type
 * @return :
 * 			(RET_OK) : The function done successfully
 * 			(RET_ERROR) : The function has a problem to perform this action
 */
Std_RetType_t nvic_enable(IRQn_Type IRQNum);
/**
 * @brief  : Disable interrupt from NVIC
 * @param  : (IRQNum) interrupt request number  @ref IRQn_Type
 * @return :
 * 			(RET_OK) : The function done successfully
 * 			(RET_ERROR) : The function has a problem to perform this action
 */
Std_RetType_t nvic_disable(IRQn_Type IRQNum);
/**
 * @brief  : Set pending flag of interrupt from NVIC
 * @param  : (IRQNum) interrupt request number  @ref IRQn_Type
 * @return :
 * 			(RET_OK) : The function done successfully
 * 			(RET_ERROR) : The function has a problem to perform this action
 */
Std_RetType_t nvic_set_pending_flag(IRQn_Type IRQNum);
/**
 * @brief  : Clear pending flag of interrupt from NVIC
 * @param  : (IRQNum) interrupt request number  @ref IRQn_Type
 * @return :
 * 			(RET_OK) : The function done successfully
 * 			(RET_ERROR) : The function has a problem to perform this action
 */
Std_RetType_t nvic_clear_pending_flag(IRQn_Type IRQNum);
/**
 * @brief  : Set priority of interrupt from NVIC
 * @param  : (IRQNum) interrupt request number  @ref IRQn_Type
 * @return :
 * 			(RET_OK) : The function done successfully
 * 			(RET_ERROR) : The function has a problem to perform this action
 */
Std_RetType_t nvic_set_priority(IRQn_Type IRQNum,uint8_t priority);
/**
 * @brief  : Get active flag of interrupt from NVIC
 * @param  : (IRQNum) interrupt request number  @ref IRQn_Type
 * @param  : (active_value) pointer to store active flag value @ref (INTERRUPT_NOT_ACTIVE , INTERRUPT_ACTIVE)
 * @return :
 * 			(RET_OK) : The function done successfully
 * 			(RET_ERROR) : The function has a problem to perform this action
 */
Std_RetType_t nvic_get_active_flag(IRQn_Type IRQNum , uint8_t *active_value);


#endif /* CORE_PREPHIRALS_NVIC_NVIC_INTERFACE_H_ */
