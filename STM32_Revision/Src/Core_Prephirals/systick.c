/*
 * systick.c
 *
 *  Created on: Mar 5, 2026
 *      Author: Hamada
 */


/************************************** 	Includes                   		**************************************/
#include "../../Inc/Core_Prephirals/systick_interface.h"
/************************************** 	Function Definition 	   		**************************************/
/**
 * @brief  : Initialize the Systick timer
 * @param  :
 * @return :
 * 			(RET_OK) : The function done successfully
 * 			(RET_ERROR) : The function has a problem to perform this action
 */
Std_RetType_t systick_init(void)
{
	Std_RetType_t ret = RET_OK;
	uint32_t NO_Tick = 0x00ffffff;
	if(NO_Tick > (STSTICK_LOAD_VALUE_POS << STSTICK_LOAD_VALUE_ACCESS)) /*resolution = 2^n = 2^24 = 16,777,216 = 1<<24*/
	{
		ret = RET_ERROR;
	}
	else
	{
		/*Disable the SYSTICK counter*/
		(SYSTICK->CSR) &=~ (SYSTICK_CSR_ENABLE_MASK << SYSTICK_CSR_ENABLE_POS);
		/*load the value into SYST_RVR in the range 0x00000001-0x00FFFFFF*/
		(SYSTICK->RVR)  = NO_Tick;
		/*clear the SYSTICK counter value*/
		(SYSTICK->CVR)  = 0;
		/*Indicates the clock source: (0) = external clock , (1) = processor clock*/
#if SYSTICK_CLOCK_SOURCE==SYSTICK_CLOCK_SOURCE_DIV_1
		(SYSTICK->CSR) |= (SYSTICK_CSR_CLOCK_MASK << SYSTICK_CSR_CLOCK_POS);
#elif SYSTICK_CLOCK_SOURCE==SYSTICK_CLOCK_SOURCE_DIV_8
		(SYSTICK->CSR) &=~ (SYSTICK_CSR_CLOCK_MASK << SYSTICK_CSR_CLOCK_POS);
#else
#endif

	}
	return ret;
}

/**
 * @brief  : systick_wait_blocking
 * @param  : (no_ticks) : number of ticks
 * @return :
 * 			(RET_OK) : The function done successfully
 * 			(RET_ERROR) : The function has a problem to perform this action
 */
Std_RetType_t systick_wait_blocking(uint32_t no_ticks)
{
	Std_RetType_t ret = RET_OK;
	if(no_ticks > (STSTICK_LOAD_VALUE_POS << STSTICK_LOAD_VALUE_ACCESS)) /*resolution = 2^n = 2^24 = 16,777,216 = 1<<24*/
	{
		ret = RET_ERROR;
	}
	else
	{
		/*load the value into SYST_RVR in the range 0x00000001-0x00FFFFFF*/
		(SYSTICK->RVR)  = no_ticks;
		/*Enable the SYSTICK counter*/
		(SYSTICK->CSR) |= (SYSTICK_CSR_ENABLE_MASK << SYSTICK_CSR_ENABLE_POS);
		/*COUNTFLAG Returns 1 if timer counted to 0 since last time this was read*/
		while(!READ_BIT(SYSTICK->CSR,SYSTICK_CSR_COUNTFLAG_POS));
		/*clear the SYSTICK counter value*/
		SYSTICK->CVR = 0;
	}

	return ret;
}

/**
 * @brief  : Delay with Blocking
 * @param  : (ms) : number of Millie seconds
 * @return :
 *
 */
void delay_ms(uint32_t ms)
{
	if(0 >= ms)
	{
		/*Nothing*/
	}
	else
	{
		uint32_t delay_in_ms = ms;
		while(delay_in_ms > 0)
		{
			systick_wait_blocking(TICKS_PER_MS);
			delay_in_ms--;
		}
	}
}
/**
 * @brief  : Delay with Blocking
 * @param  : (us) : number of micro seconds
 * @return :
 *
 */
void delay_us(uint32_t us)
{
	if (us == 0)
	{
		/* Nothing */
	}
	else
	{
		/* Handle full 10µs chunks */
		uint32_t chunks = us / 10;
		while (chunks > 0)
		{
			systick_wait_blocking(TICKS_PER_10US);  // 159 ✅
			chunks--;
		}

		/* Handle remaining µs (0–9) */
		uint32_t remainder = us % 10;
		while (remainder > 0)
		{
			systick_wait_blocking(TICKS_PER_US);    // 15 ✅
			remainder--;
		}
	}
}
