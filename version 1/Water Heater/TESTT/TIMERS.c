/*
 * TIMERS.c
 *
 * Created: 31/01/2023 6:03:55 PM
 *  Author: Lenovo
 */ 

#include <avr/io.h>
#define F_CPU 1000000ul
#include <util/delay.h>
#include "TIMERS.h"
#include "BitWiseOperation.h"


void timer_Init(void)
{
	set(TCCR0,WGM01);        //CTC Mode

	clear(TCCR0,COM00);        //Normal OC0 port operation
	clear(TCCR0,COM01);

	clear(TCCR0,CS00);        //prescalar 8
	set(TCCR0,CS01);
	clear(TCCR0,CS02);

	set(TIMSK,OCIE0);        //Compare match interrupt enable

	OCR0 = 200;

	TCNT0 = 0;
}

void timer_OFF(void)
{
	clear(TCCR0,CS00);        //Disable clock
	clear(TCCR0,CS01);
	clear(TCCR0,CS02);
}