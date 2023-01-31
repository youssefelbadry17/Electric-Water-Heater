#include <avr/io.h>
#define F_CPU 1000000ul
#include <util/delay.h>
#include "LCD.h"
#include "Buzzer.h"
#include "BitWiseOperation.h"

void Buzzer_init()
{
	set(buzzer_state,buzzer_pin);
}

void Buzzer_on ()
{
	set(buzzer_port,buzzer_pin);
	LCD_Clear();
	LCD_String("!!!warning!!!");
}

void Buzzer_stop()
{
	clear(buzzer_port,buzzer_pin);
}