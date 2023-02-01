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


#include "EEPROM.h"
#include "Seven_Segment.h"
#include "LCD.h"
#include "buzzer.h"
#include "LM35.h"
#include "LED.h"
#include "fan_motors.h"
#include "Interupt.h"
#include "TIMERS.h"
#include "BitWiseOperation.h"




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