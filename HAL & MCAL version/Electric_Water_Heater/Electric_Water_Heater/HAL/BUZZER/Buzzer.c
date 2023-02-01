#include <avr/io.h>
#define F_CPU 1000000ul
#include <util/delay.h>
#include "../HAL/LCD/LCD.h"
#include "Buzzer.h"
#include "../BItWise/BitWiseOperation.h"

void Buzzer_init()
{
	set(buzzer_state,buzzer_pin);
}

void Buzzer_on ()
{
	set(buzzer_port,buzzer_pin);	
}

void Buzzer_stop()
{
	clear(buzzer_port,buzzer_pin);
}