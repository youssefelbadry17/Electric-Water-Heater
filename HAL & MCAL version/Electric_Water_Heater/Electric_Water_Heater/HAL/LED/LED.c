/*
 * LED.c
 *
 * Created: 30/01/2023 2:12:25 PM
 *  Author: Lenovo
 */ 
#include <avr/io.h>
#define F_CPU 1000000ul
#include <util/delay.h>
#include "LED.h"
#include "../BItWise/BitWiseOperation.h"

void LED_init()
{
	set(Heating_element_Led_state,Heating_element_Led_Pin);
}
void LED_COOLING()
{
	set(Heating_element_Led_Port,Heating_element_Led_Pin);
}
void LED_HEATING()
{
	toggle(Heating_element_Led_Port,Heating_element_Led_Pin);
}
void LED_off()
{
	clear(Heating_element_Led_Port,Heating_element_Led_Pin);
}
