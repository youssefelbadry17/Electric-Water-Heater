/*
 * LED.h
 *
 * Created: 30/01/2023 2:13:20 PM
 *  Author: Lenovo
 */ 


#ifndef LED_H_
#define LED_H_

#define Heating_element_Led_state DDRA
#define Heating_element_Led_Port PORTA
#define Heating_element_Led_Pin PA0

void LED_init();
void LED_COOLING();
void LED_HEATING();
void LED_off();



#endif /* LED_H_ */