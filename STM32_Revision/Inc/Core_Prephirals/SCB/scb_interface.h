/*
 * scb_interface.h
 *
 *  Created on: Mar 8, 2026
 *      Author: Hamada
 */

#ifndef CORE_PREPHIRALS_SCB_SCB_INTERFACE_H_
#define CORE_PREPHIRALS_SCB_SCB_INTERFACE_H_

/************************************** 	Includes                   		**************************************/
#include  "scb_private.h"
/************************************** 	Macro Declaration          		**************************************/
/************************************** 	Macro Function Declaration 		**************************************/
/************************************** 	Data Type Declaration      		**************************************/
/************************************** 	Function Declaration	   		**************************************/
/**
 * @brief  : Set priority group from SCB
 * @param  : (priority_group)
 * @return :
 * 			(RET_OK) : The function done successfully
 * 			(RET_ERROR) : The function has a problem to perform this action
 */
Std_RetType_t scb_set_priority_group(uint32_t priority_group);

#endif /* CORE_PREPHIRALS_SCB_SCB_INTERFACE_H_ */
