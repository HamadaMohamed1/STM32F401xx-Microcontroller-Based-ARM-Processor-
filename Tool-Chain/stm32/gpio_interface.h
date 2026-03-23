/*
 * gpio_interface.h
 *
 *  Created on: Mar 4, 2026
 *      Author: Hamada
 */

#ifndef MCAL_GPIO_GPIO_INTERFACE_H_
#define MCAL_GPIO_GPIO_INTERFACE_H_

/************************************** 	Includes                   		**************************************/
#include "gpio_private.h"
/************************************** 	Data Type Declaration      		**************************************/
typedef struct
{
	Pin_t  					pin;
	Port_t 					port;
	PinMode_t 				mode;
	PinOutputType_t 		outType;
	PinOutputSpeed_t 		speed;
	PinPullupPulldown_t 	pullType;
	PinAlternateFunction_t  alternateFunction;

}PinConfig_t;
/************************************** 	Function Declaration	   		**************************************/
/**
 * @brief  : Initialize the GPIO Pin
 * @param  : (pinConfig) Pointer to the configuration @ref PinConfig_t
 * @return :
 * 			(RET_OK) : The function done successfully
 * 			(RET_ERROR) : The function has a problem to perform this action
 */
Std_RetType_t gpio_pin_init(const PinConfig_t* pinConfig);
/**
 * @brief  : Set the GPIO Pin Value
 * @param  : port      : the pin in which port       @ref Port_t
 * 		   : pin  	   : pin number			         @ref Pin_t
 * 		   : pin_value : value to be written on pin  @ref PinValue_t
 * @return :
 * 			(RET_OK) : The function done successfully
 * 			(RET_ERROR) : The function has a problem to perform this action
 */
Std_RetType_t gpio_set_pin_value(Port_t port ,Pin_t pin ,const PinValue_t pin_value);
/**
 * @brief  : Get the GPIO Pin value
 * @param  : port      : the pin in which port       					@ref Port_t
 * 		   : pin  	   : pin number			         					@ref Pin_t
 * 		   : pin_value : pointer to variable value for store pin value  @ref PinValue_t
 * @return :
 * 			(RET_OK) : The function done successfully
 * 			(RET_ERROR) : The function has a problem to perform this action
 */
Std_RetType_t gpio_get_pin_value(Port_t port ,Pin_t pin ,PinValue_t* pin_value);
/**
 * @brief  : Toggle the GPIO Pin value
 * @param  : port      : the pin in which port       					@ref Port_t
 * 		   : pin  	   : pin number			         					@ref Pin_t
 * @return :
 * 			(RET_OK) : The function done successfully
 * 			(RET_ERROR) : The function has a problem to perform this action
 */
Std_RetType_t gpio_toggle_pin_value(Port_t port ,Pin_t pin);
/**
 * @brief  : Set the GPIO Port value
 * @param  : port      : the pin in which port   		@ref Port_t
 * 		   : pin_value : value to be written on port    @ref PinValue_t
 * @return :
 * 			(RET_OK) : The function done successfully
 * 			(RET_ERROR) : The function has a problem to perform this action
 */
Std_RetType_t gpio_set_port_value(Port_t port ,const uint32_t port_value);
/**
 * @brief  : Get the GPIO Port value
 * @param  : port      : the pin in which port   		@ref Port_t
 * 		   : pin_value : pointer to variable for store the port value
 * @return :
 * 			(RET_OK) : The function done successfully
 * 			(RET_ERROR) : The function has a problem to perform this action
 */
Std_RetType_t gpio_get_port_value(Port_t port ,uint32_t* port_value);


#endif /* MCAL_GPIO_GPIO_INTERFACE_H_ */
