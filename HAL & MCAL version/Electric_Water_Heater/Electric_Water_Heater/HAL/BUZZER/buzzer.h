#ifndef Buzzer_h_
#define Buzzer_h_

//BUZZER
#define buzzer_port						PORTD
#define buzzer_state					DDRD
#define buzzer_pin						PD0


//BUZZER FUCTIONS
void Buzzer_init();
void Buzzer_on ();
void Buzzer_stop();

#endif