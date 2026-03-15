/*
 * exti.c
 *
 *  Created on: Mar 15, 2026
 *      Author: Hamada
 */


/************************************** 	Includes                   	**************************************/
#include "../../../Inc/MCAL/EXTI/exti_interface.h"
/************************************** 	static global variables  	**************************************/
static void (* exti_handlers[EXTI_MAX_NUMBER])(void) = {NULL};
static EXTI_source_t exti_source;
/************************************** 	Function Definition	   		**************************************/
/**
 * @brief  : Initialize the external interrupt pin
 * @param  : (EXTI_object) pointer to configuration @ref EXTI_config_t
 * @return :
 * 			(RET_OK) : The function done successfully
 * 			(RET_ERROR) : The function has a problem to perform this action
 */
Std_RetType_t exti_initialize(const exti_config_t* EXTI_object)
{
	Std_RetType_t ret = RET_OK;
	if(NULL == EXTI_object)
	{
		ret = RET_ERROR;
	}
	else
	{
		/******** select edge trigger  ********/
		switch(EXTI_object->edge)
		{
			case RISING_EDGE :
				EXTI->RTSR |=  (1 << EXTI_object->source);
				EXTI->FTSR &= ~(1 << EXTI_object->source);
			break;
			case FALLING_EDGE :
				EXTI->FTSR |=  (1 << EXTI_object->source);
				EXTI->RTSR &= ~(1 << EXTI_object->source);
			break;
			case RISING_FALLING_EDGE:
				EXTI->RTSR |=  (1 << EXTI_object->source);
				EXTI->FTSR |=  (1 << EXTI_object->source);
			break;
			default :
				ret = RET_ERROR;
			break;
		}
		// initiate call back
		exti_handlers[EXTI_object->source] = EXTI_object->exti_handler;
		// initiate exti_source
		//exti_source = EXTI_object->source;
	}
	return ret;
}

/**
 * @brief  : Enable interrupt to specific pin
 * @param  : (EXTI_source) interrupt source pin @ref EXTI_source_t
 * @return :
 * 			(RET_OK) : The function done successfully
 * 			(RET_ERROR) : The function has a problem to perform this action
 */
Std_RetType_t exti_enable(EXTI_source_t EXTI_source)
{
	EXTI->IMR |= (1 << EXTI_source);
	return RET_OK;
}
/**
 * @brief  : Disable interrupt to specific pin
 * @param  : (EXTI_source) interrupt source pin @ref EXTI_source_t
 * @return :
 * 			(RET_OK) : The function done successfully
 * 			(RET_ERROR) : The function has a problem to perform this action
 */
Std_RetType_t exti_disable(EXTI_source_t EXTI_source)
{
	EXTI->IMR &= ~(1 << EXTI_source);
	return RET_OK;
}
/**
 * @brief  : Set pending flag of external interrupt
 * @param  : (EXTI_source) interrupt source pin @ref EXTI_source_t
 * @return :
 * 			(RET_OK) : The function done successfully
 * 			(RET_ERROR) : The function has a problem to perform this action
 */
Std_RetType_t exti_set_pending_flag(EXTI_source_t EXTI_source)
{
	EXTI->SWIER |= (1 << EXTI_source);
	return RET_OK;
}
/**
 * @brief  : Clear pending flag of external interrupt
 * @param  : (EXTI_source) interrupt source pin @ref EXTI_source_t
 * @return :
 * 			(RET_OK) : The function done successfully
 * 			(RET_ERROR) : The function has a problem to perform this action
 */
Std_RetType_t exti_clear_pending_flag(EXTI_source_t EXTI_source)
{
	/* clearing pending flag is done by programming the bit to '1'*/
	EXTI->PR |= (1 << EXTI_source);
	return RET_OK;
}
/**
 * @brief  : Read pending flag of external interrupt
 * @param  : (EXTI_source) interrupt source pin @ref EXTI_source_t
 * @param  : (pending_flag) pointer to store the flag's value , @ref pending_flag_t
 * @return :
 * 			(RET_OK) : The function done successfully
 * 			(RET_ERROR) : The function has a problem to perform this action
 */
Std_RetType_t exti_read_pending_flag(EXTI_source_t EXTI_source, pending_flag_t* pending_flag)
{
	Std_RetType_t ret = RET_OK;
	if(NULL == pending_flag)
	{
		ret = RET_ERROR;
	}
	else
	{
		*pending_flag = EXTI->PR & (1 << EXTI_source) ? INT_TRIGGERED : INT_NOT_TRIGGERED;
	}
	return ret;
}
/**************************************** EXTI ISRs ********************************************************/
/**
 * @brief  : (ISR)Interrupt service routine for (External interrupt # 0)
 * @param  : void
 * @return : void
 *
 */
void EXTI0_IRQHandler(void)
{
	exti_clear_pending_flag(EXTI_0);
	if(NULL != exti_handlers[0])
	{
		exti_handlers[EXTI_0]();
	}
}

/**
 * @brief  : (ISR)Interrupt service routine for (External interrupt # 1)
 * @param  : void
 * @return : void
 *
 */
void EXTI1_IRQHandler(void)
{
	exti_clear_pending_flag(EXTI_1);
	if(NULL != exti_handlers[EXTI_1])
	{
		exti_handlers[EXTI_1]();
	}
}
/**
 * @brief  : (ISR)Interrupt service routine for (External interrupt # 2)
 * @param  : void
 * @return : void
 *
 */
void EXTI2_IRQHandler(void)
{
	exti_clear_pending_flag(EXTI_2);
	if(NULL != exti_handlers[EXTI_2])
	{
		exti_handlers[EXTI_2]();
	}
}
/**
 * @brief  : (ISR)Interrupt service routine for (External interrupt # 3)
 * @param  : void
 * @return : void
 *
 */
void EXTI3_IRQHandler(void)
{
	exti_clear_pending_flag(EXTI_3);
	if(NULL != exti_handlers[EXTI_3])
	{
		exti_handlers[EXTI_3]();
	}
}
/**
 * @brief  : (ISR)Interrupt service routine for (External interrupt # 4)
 * @param  : void
 * @return : void
 *
 */
void EXTI4_IRQHandler(void)
{
	exti_clear_pending_flag(EXTI_4);
	if(NULL != exti_handlers[EXTI_4])
	{
		exti_handlers[EXTI_4]();
	}
}
/**
 * @brief  : (ISR)Interrupt service routine for (External interrupt # 5 : 9)
 * @param  : void
 * @return : void
 *
 */
void EXTI9_5_IRQHandler(void)
{
	pending_flag_t flag = INT_NOT_TRIGGERED;
	exti_read_pending_flag(EXTI_5,&flag);
	if(INT_TRIGGERED == flag)
	{
		exti_clear_pending_flag(EXTI_5);
		if(NULL != exti_handlers[EXTI_5])
		{
			exti_handlers[EXTI_5]();
		}
		flag = INT_NOT_TRIGGERED;
	}
	exti_read_pending_flag(EXTI_6,&flag);
	if(INT_TRIGGERED == flag)
	{
		exti_clear_pending_flag(EXTI_6);
		if(NULL != exti_handlers[EXTI_6])
		{
			exti_handlers[EXTI_6]();
		}
		flag = INT_NOT_TRIGGERED;
	}
	exti_read_pending_flag(EXTI_7,&flag);
	if(INT_TRIGGERED == flag)
	{
		exti_clear_pending_flag(EXTI_7);
		if(NULL != exti_handlers[EXTI_7])
		{
			exti_handlers[EXTI_7]();
		}
		flag = INT_NOT_TRIGGERED;
	}
	exti_read_pending_flag(EXTI_8,&flag);
	if(INT_TRIGGERED == flag)
	{
		exti_clear_pending_flag(EXTI_8);
		if(NULL != exti_handlers[EXTI_8])
		{
			exti_handlers[EXTI_8]();
		}
		flag = INT_NOT_TRIGGERED;
	}
	exti_read_pending_flag(EXTI_9,&flag);
	if(INT_TRIGGERED == flag)
	{
		exti_clear_pending_flag(EXTI_9);
		if(NULL != exti_handlers[EXTI_9])
		{
			exti_handlers[EXTI_9]();
		}
		flag = INT_NOT_TRIGGERED;
	}
}
/**
 * @brief  : (ISR)Interrupt service routine for (External interrupt # 5 : 9)
 * @param  : void
 * @return : void
 *
 */
void EXTI15_10_IRQHandler(void)
{
	pending_flag_t flag = INT_NOT_TRIGGERED;
	exti_read_pending_flag(EXTI_10,&flag);
	if(INT_TRIGGERED == flag)
	{
		exti_clear_pending_flag(EXTI_10);
		if(NULL != exti_handlers[EXTI_10])
		{
			exti_handlers[EXTI_10]();
		}
		flag = INT_NOT_TRIGGERED;
	}
	exti_read_pending_flag(EXTI_11,&flag);
	if(INT_TRIGGERED == flag)
	{
		exti_clear_pending_flag(EXTI_11);
		if(NULL != exti_handlers[EXTI_11])
		{
			exti_handlers[EXTI_11]();
		}
		flag = INT_NOT_TRIGGERED;
	}
	exti_read_pending_flag(EXTI_12,&flag);
	if(INT_TRIGGERED == flag)
	{
		exti_clear_pending_flag(EXTI_12);
		if(NULL != exti_handlers[EXTI_12])
		{
			exti_handlers[EXTI_12]();
		}
		flag = INT_NOT_TRIGGERED;
	}
	exti_read_pending_flag(EXTI_13,&flag);
	if(INT_TRIGGERED == flag)
	{
		exti_clear_pending_flag(EXTI_13);
		if(NULL != exti_handlers[EXTI_13])
		{
			exti_handlers[EXTI_13]();
		}
		flag = INT_NOT_TRIGGERED;
	}
	exti_read_pending_flag(EXTI_14,&flag);
	if(INT_TRIGGERED == flag)
	{
		exti_clear_pending_flag(EXTI_14);
		if(NULL != exti_handlers[EXTI_14])
		{
			exti_handlers[EXTI_14]();
		}
		flag = INT_NOT_TRIGGERED;
	}
	exti_read_pending_flag(EXTI_15,&flag);
	if(INT_TRIGGERED == flag)
	{
		exti_clear_pending_flag(EXTI_15);
		if(NULL != exti_handlers[EXTI_15])
		{
			exti_handlers[EXTI_15]();
		}
		flag = INT_NOT_TRIGGERED;
	}
}
/**
 * @brief  : (ISR)Interrupt service routine for (External interrupt #16)
 * @param  : void
 * @return : void
 *
 */
void EXTI16_PVD_IRQHandler(void)
{
	exti_clear_pending_flag(EXTI_16);
	if(NULL != exti_handlers[EXTI_16])
	{
		exti_handlers[EXTI_16]();
	}
}
/**
 * @brief  : EXTI Line 17 interrupt / RTC Alarms (A and B) through EXTI line interrupt
 * @param  : void
 * @return : void
 *
 */
void EXTI17_RTC_Alarm_IRQHandler(void)
{
	exti_clear_pending_flag(EXTI_17);
	if(NULL != exti_handlers[EXTI_17])
	{
		exti_handlers[EXTI_17]();
	}
}
/**
 * @brief  : EXTI Line 18 interrupt / USBUSB On-The-Go FS Wakeup through EXTI line interrupt
 * @param  : void
 * @return : void
 *
 */
void EXTI18_OTG_FS_WKUP_IRQHandler(void)
{
	exti_clear_pending_flag(EXTI_18);
	if(NULL != exti_handlers[EXTI_18])
	{
		exti_handlers[EXTI_18]();
	}
}


/*	EXTI19 & EXTI20 are reserved*/


/**
 * @brief  : EXTI Line 22 interrupt /RTC Wakeup interrupt through the EXTI line
 * @param  : void
 * @return : void
 *
 */
void EXTI22_RTC_WKUP_IRQHandler(void)
{
	exti_clear_pending_flag(EXTI_22);
	if(NULL != exti_handlers[EXTI_22])
	{
		exti_handlers[EXTI_22]();
	}
}



