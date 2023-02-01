/*
 * Interupt.c
 *
 * Created: 31/01/2023 11:50:12 AM
 *  Author: Lenovo
 */ 
#include <avr/io.h>
#define F_CPU 1000000ul
#include "Interupt.h"
#include "BitWiseOperation.h"
#include <avr/interrupt.h>

void interupts_init(void)
{
	set(MCUCR,ISC11);
	set(MCUCR,ISC01);
	set(MCUCR,ISC00);
	set(GICR,INT2);
	sei();
}

void interupts_ON(void)
{
	set(GICR,INT0);
	set(GICR,INT1);
}

void interupts_OFF(void)
{
	clear(GICR,INT0);
	clear(GICR,INT1);
}

