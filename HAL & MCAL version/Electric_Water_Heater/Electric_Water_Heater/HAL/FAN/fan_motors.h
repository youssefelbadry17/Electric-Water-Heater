#ifndef FAN_MOTORS_H_
#define FAN_MOTORS_H_

#define HEATING_FAN_PIN				PB0
#define COOLING_FAN_PIN				PB1

#define FANS_PORT					PORTB
#define FANS_STATE					DDRB

void FAN_init(void);
void Heater_ON(void);
void Cooler_ON(void);
void Fans_OFF(void);

#endif /* FAN_MOTORS_H_ */