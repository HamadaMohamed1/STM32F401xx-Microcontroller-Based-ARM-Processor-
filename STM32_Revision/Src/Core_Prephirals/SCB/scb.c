/*
 * scb.c
 *
 *  Created on: Mar 8, 2026
 *      Author: Hamada
 */

/************************************** 	Includes                   		**************************************/
#include  "../../../Inc/Core_Prephirals/SCB/scb_interface.h"
/************************************** 	Macro Declaration          		**************************************/
/************************************** 	Macro Function Declaration 		**************************************/
/************************************** 	Data Type Declaration      		**************************************/
/************************************** 	Function Definition  	   		**************************************/
/**
 * @brief  : Set priority group from SCB
 * @param  : (priority_group)	@ref GROUP_PRIORITIES..
 * @return :
 * 			(RET_OK) : The function done successfully
 * 			(RET_ERROR) : The function has a problem to perform this action
 */
Std_RetType_t scb_set_priority_group(uint32_t priority_group)
{
	Std_RetType_t ret = RET_OK;
	if((GROUP_PRIORITIES_16_SUB_PRIORITIES_NONE == priority_group) || (GROUP_PRIORITIES_8_SUB_PRIORITIES_2 == priority_group) ||
		   (GROUP_PRIORITIES_4_SUB_PRIORITIES_4 == priority_group) || (GROUP_PRIORITIES_2_SUB_PRIORITIES_8 == priority_group) ||
		   (GROUP_PRIORITIES_1_SUB_PRIORITIES_16== priority_group))
	{
		SCB->AIRCR = priority_group;
	}
	else
	{
		ret = RET_ERROR;
	}
	return ret;
}
