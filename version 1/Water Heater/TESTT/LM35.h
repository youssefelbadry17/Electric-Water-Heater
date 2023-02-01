/*
 * Header.h
 *
 * Created: 17/09/2022 9:01:18 AM
 *  Author: Lenovo
 */ 


#ifndef LM35_H_
#define LM35_H_


#define sensor_pin PA1
#define Heating_element_sensor_Port PORTA


/**************************************************************************************/

void ADC_initi ();

unsigned int ADC_read();

int avg_tempreture (void);


#endif /* HEADER_H_ */