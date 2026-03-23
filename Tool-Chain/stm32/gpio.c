/*
 * gpio.c
 *
 *  Created on: Mar 4, 2026
 *      Author: Hamada
 */

/************************************** 	Includes                   		**************************************/
#include "gpio_interface.h"
/*****************************************************************************************************************/
static GPIO_RegDef_t* GPIO_PORT[GPIO_PEREPHIRAL_MAX_NUM] = {GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOH};
/************************************** 	Function Definition          	**************************************/
/**
 * @brief  : Initialize the GPIO Pin
 * @param  : (pinConfig) Pointer to the configuration @ref PinConfig_t
 * @return :
 * 			(RET_OK) : The function done successfully
 * 			(RET_ERROR) : The function has a problem to perform this action
 */
Std_RetType_t gpio_pin_init(const PinConfig_t* pinConfig)
{
	Std_RetType_t ret = RET_OK;
	if(NULL == pinConfig)
	{
		ret = RET_ERROR;
	}
	else
	{
		/* Select gpio pin mode*/
		/*clear the mode bits*/
		(GPIO_PORT[pinConfig->port]->MODER) &=~ (MODER_MASK << (pinConfig->pin*MODER_PIN_ACCESS));
		/*set the mode bits*/
		(GPIO_PORT[pinConfig->port]->MODER) |=  ((pinConfig->mode) << (pinConfig->pin*MODER_PIN_ACCESS));


		/* Select gpio pull state */
		/*clear the PUPDR bits*/
		(GPIO_PORT[pinConfig->port]->PUPDR) &=~ (PUPDR_MASK << (pinConfig->pin*PUPDR_PIN_ACCESS));
		/*set the PUPDR bits*/
		(GPIO_PORT[pinConfig->port]->PUPDR) |=  ((pinConfig->pullType) << (pinConfig->pin*PUPDR_PIN_ACCESS));

		/*select output type & output speed in case of output or alternate function*/
		if(OUTPUT == pinConfig->mode || ALTERNATE_FUNCTION == pinConfig->mode)
		{
			/*select output type {push pull , open drain}*/
			/*clear the OTYPER bits*/
			(GPIO_PORT[pinConfig->port]->OTYPER) &=~ (OTYPER_MASK << (pinConfig->pin));
			/*set the OTYPER bits*/
			(GPIO_PORT[pinConfig->port]->OTYPER) |=  (pinConfig->outType << (pinConfig->pin));

			/*select output speed {low , medium , high , very high}*/
			/*clear the OSPEEDR bits*/
			(GPIO_PORT[pinConfig->port]->OSPEEDR) &=~ (OSPEEDR_MASK << (pinConfig->pin*OSPEEDR_PIN_ACCESS));
			/*set the OSPEEDR bits*/
			(GPIO_PORT[pinConfig->port]->OSPEEDR) |= (pinConfig->speed << (pinConfig->pin*OSPEEDR_PIN_ACCESS));

			if(ALTERNATE_FUNCTION == pinConfig->mode)
			{
				/*select the pin alternate function*/
				uint8_t l_reg_num = pinConfig->pin / AFR_PIN_SHIFTING;   /*calculate the register number (0 or 1)*/
				uint8_t l_bit_num = pinConfig->pin % AFR_PIN_SHIFTING;   /*calculate the bit number */
				/*clear the AFR bits*/
				(GPIO_PORT[pinConfig->port]->AFR[l_reg_num]) &=~(AFR_MASK << (l_bit_num *AFR_PIN_ACCESS));
				/*set the AFR bits*/
				(GPIO_PORT[pinConfig->port]->AFR[l_reg_num]) |= ((pinConfig->alternateFunction) << (l_bit_num *AFR_PIN_ACCESS));
			}
		}

	}
	return ret;
}
/**
 * @brief  : Set the GPIO Pin Value
 * @param  : port      : the pin in which port       @ref Port_t
 * 		   : pin  	   : pin number			         @ref Pin_t
 * 		   : pin_value : value to be written on pin  @ref PinValue_t
 * @return :
 * 			(RET_OK) : The function done successfully
 * 			(RET_ERROR) : The function has a problem to perform this action
 */
Std_RetType_t gpio_set_pin_value(Port_t port ,Pin_t pin ,const PinValue_t pin_value)
{
	Std_RetType_t ret = RET_OK;
	if((PORTH < port) | (PIN15 < pin))
	{
		ret = RET_ERROR;
	}
	else
	{
		if(PIN_LOW == pin_value)
		{
			GPIO_PORT[port]->ODR &=~ (1 << pin);
			/*GPIO_PORT[port]->BSRR = 1<< (pin +16);  faster*/
		}
		else if(PIN_HIGH == pin_value)
		{
			GPIO_PORT[port]->ODR |= (1 << pin);
			/*GPIO_PORT[port]->BSRR = (1<<pin);  faster*/
		}
	}
	return ret;
}
/**
 * @brief  : Toggle the GPIO Pin value
 * @param  : port      : the pin in which port       					@ref Port_t
 * 		   : pin  	   : pin number			         					@ref Pin_t
 * @return :
 * 			(RET_OK) : The function done successfully
 * 			(RET_ERROR) : The function has a problem to perform this action
 */
Std_RetType_t gpio_toggle_pin_value(Port_t port ,Pin_t pin)
{
	Std_RetType_t ret = RET_OK;
	if((PORTH < port) | (PIN15 < pin))
	{
		ret = RET_ERROR;
	}
	else
	{
		GPIO_PORT[port]->ODR ^= (1 << pin);
	}
	return ret;
}
/**
 * @brief  : Set the GPIO Port value
 * @param  : port      : the pin in which port   		@ref Port_t
 * 		   : pin_value : value to be written on port    @ref PinValue_t
 * @return :
 * 			(RET_OK) : The function done successfully
 * 			(RET_ERROR) : The function has a problem to perform this action
 */
Std_RetType_t gpio_set_port_value(Port_t port ,const uint32_t port_value)
{
	Std_RetType_t ret = RET_OK;
	if(PORTH < port)
	{
		ret = RET_ERROR;
	}
	else
	{
		GPIO_PORT[port]->ODR = port_value;
	}
	return ret;
}
/**
 * @brief  : Get the GPIO Pin value
 * @param  : port      : the pin in which port       					@ref Port_t
 * 		   : pin  	   : pin number			         					@ref Pin_t
 * 		   : pin_value : pointer to variable value for store pin value  @ref PinValue_t
 * @return :
 * 			(RET_OK) : The function done successfully
 * 			(RET_ERROR) : The function has a problem to perform this action
 */
Std_RetType_t gpio_get_pin_value(Port_t port ,Pin_t pin ,PinValue_t* pin_value)
{
	Std_RetType_t ret = RET_OK;
	if((PORTH < port)|(PIN15 < pin)|(NULL == pin_value))
	{
		ret = RET_ERROR;
	}
	else
	{
		if((GPIO_PORT[port]->IDR & (1<<pin)))
		{
			*pin_value = PIN_HIGH;
		}
		else
		{
			*pin_value = PIN_LOW;
		}
	}
	return ret;
}
/**
 * @brief  : Get the GPIO Port value
 * @param  : port      : the pin in which port   		@ref Port_t
 * 		   : pin_value : pointer to variable for store the port value
 * @return :
 * 			(RET_OK) : The function done successfully
 * 			(RET_ERROR) : The function has a problem to perform this action
 */
Std_RetType_t gpio_get_port_value(Port_t port ,uint32_t* port_value)
{
	Std_RetType_t ret = RET_OK;
	if((PORTH < port) |(NULL == port_value))
	{
		ret = RET_ERROR;
	}
	else
	{
		*port_value = GPIO_PORT[port]->IDR;
	}
	return ret;
}
