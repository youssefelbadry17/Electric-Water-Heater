#include <avr/io.h>
#include "fan_motors.h"
#include "BitWiseOperation.h"


void FAN_init()
{
	set(FANS_STATE,HEATING_FAN_PIN);
	set(FANS_STATE,COOLING_FAN_PIN);
}

void Heater_ON(void)
{
	set(FANS_PORT,HEATING_FAN_PIN);
	clear(FANS_PORT,COOLING_FAN_PIN);
}

void Cooler_ON(void)
{
		clear(FANS_PORT,HEATING_FAN_PIN);
		set(FANS_PORT,COOLING_FAN_PIN);
}

void Fans_OFF(void)
{
	clear(FANS_PORT,HEATING_FAN_PIN);
	clear(FANS_PORT,COOLING_FAN_PIN);
}