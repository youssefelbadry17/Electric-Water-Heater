/*
 * APP_.h
 *
 * Created: 30/01/2023 11:26:30 AM
 *  Author: Lenovo
 */ 


#ifndef APP_H_
#define APP_H_


#define F_CPU 1000000ul
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


#include "../HAL/EEPROM/EEPROM.h"
#include "../HAL/SevenSegment/Seven_Segment.h"
#include "../HAL/LCD/LCD.h"
#include "../HAL/BUZZER/buzzer.h"
#include "../HAL/Temp sensor/LM35.h"
#include "../HAL/LED/LED.h"
#include "../HAL/FAN/fan_motors.h"
#include "../MCAL/INTERUPTS/Interupt.h"
#include "../MCAL/Timers/TIMERS.h"
#include "../BItWise/BitWiseOperation.h"




#define OFF 0
#define ON 1
#define set_tempe 2
#define addresse 0 
#define initial_Temperture 60
#define ADC_Number 1
#define accuracy 5

void APP_init();
void APP_start();
void Mode_ON();
void Mode_OFF();
void Mode_set_tepmerture();
void Sev_seg_blink(unsigned char TEMP);

#endif /* APP'_H_ */