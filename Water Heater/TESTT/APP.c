/*
 * APP.c
 *
 * Created: 30/01/2023 11:26:50 AM
 *  Author: Lenovo
 */ 

#include "APP.h"

//Global variable
unsigned char state = OFF;
unsigned char set_Temperture = initial_Temperture;
unsigned int temp = 0;
//volatile int tick_counter = 0;        //counter for timer ticks
//int delay = 5;
//int seconds_counter = 5;
unsigned char prev_state = OFF; 




/* /////////////////////////////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////Functions///////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////////////////////////////////////    */

void APP_init()
{
	//EEPROM initialization
	EEPROM_init();
	EEPROM_writeByte(BLOCK_0,addresse,set_Temperture);
	_delay_ms(10);
	//7segment initialization
	sev_seg_init();
	//LCD initialization
	LCD_int();
	//TEMP SENSOR
	ADC_initi(ADC_Number);
	//LED init
	LED_init();
	//interuptte init
	interupts_init();
	//DAN Init
	FAN_init();
	//buzzer init
	Buzzer_init();

}

void APP_start()
{	
	while(1)
	{
		if(state == OFF)
		{
			Mode_OFF();
		}
		else if (state == ON)
		{
			Mode_ON();
		}
		else if (state == set_tempe)
		{
			Mode_set_tepmerture();
		}
		else
		{
			state = OFF;
		}
	}
}

void Mode_OFF()
{
	Fans_OFF();
	LED_off();
	LCD_Clear();
	LCD_COMMAND(disply_on_corsor_off);
	Buzzer_stop();
	interupts_OFF();
	sev_seg_disable();
}

void Mode_ON()
{	
	char saved_Tempreture = 0;
	int Temperture = 0 ;
	interupts_ON();
	if (prev_state ==OFF)
	{
		EEPROM_readByte(BLOCK_0,addresse,&saved_Tempreture);
	}
	else
	{
		saved_Tempreture = set_Temperture;
	}

	Temperture = avg_tempreture();
	sev_seg_enable();
	if (temp != Temperture || prev_state == set_tempe)
	{	
		sev_seg_1_displaynumper(Temperture/10);
		sev_seg_2_displaynumper(Temperture%10);
		LCD_COMMAND(disply_on_corsor_off);
		LCD_Clear();
		LCD_String("MODE ON ");
		_delay_ms(10);
		LCD_Show_temp(Temperture);
		temp = Temperture;
	}
	else
	{
		//do nothing
	}


	if (Temperture>80 || Temperture<30)
		{
			Buzzer_on();
			_delay_ms(50);
			LCD_Show_temp(Temperture);
			_delay_ms(100);
			
		}
	else
		{
			Buzzer_stop();
		}

	
	if ((Temperture-saved_Tempreture) > accuracy)
	{
		Cooler_ON();
		LED_COOLING();
		if (temp != Temperture)
		{
			temp = Temperture;
			LCD_String(" COOLER ON ");
		}
		else
		{
			//do nothing
		}
		
	}
	else if ((saved_Tempreture-Temperture) > accuracy)
	{
		Heater_ON();
		LED_HEATING();
			if (temp != Temperture)
			{
				temp = Temperture;
				LCD_String(" HEATER ON ");
			}
			else
			{
				//do nothing
			}
	}
	else
	{
		Fans_OFF();
		LED_off();
	}
	prev_state = ON; 
}

void Mode_set_tepmerture()
{	//unsigned char Temperture = 0 ;
	//EEPROM_readByte(BLOCK_0,addresse,&Temperture);
	LCD_Clear();
	_delay_ms(10);
	LCD_String("SET TEMP MODE");
	_delay_ms(100);
	LCD_Show_set_temp(set_Temperture);
	Sev_seg_blink(set_Temperture);
	LED_off();
	Fans_OFF();
	/*if (tick_counter >= 625)
	{
		seconds_counter++;
		tick_counter = 0;
		if (seconds_counter < delay)
		{
			interupts_OFF();
		}
		else
		{
			interupts_ON();
			timer_OFF();
		}
	}*/
	EEPROM_writeByte(BLOCK_0,addresse,set_Temperture);
	 
	state = ON;
	prev_state = set_tempe;
}
	

//ON & OFF BUTTON
ISR(INT2_vect)
{
	if (state == OFF)       
	{
		//interupts_ON(); 
		state = ON ;    
	}
	else
	{
		//interupts_OFF();
		state = OFF;
		LCD_off();      
	}
}

// UP BUTTON
ISR(INT0_vect)
{
	if (state != set_tempe)
	{
		state = set_tempe;
		LCD_Show_set_temp(set_Temperture);
		
	}
	else
	{
		if (set_Temperture >= 75)
		{
			set_Temperture = 75;
		}
		else
		{
			set_Temperture = set_Temperture + 5;
		}
	}
	state = set_tempe;

}

// DOWN BUTTON
ISR(INT1_vect)
{
	if (state != set_tempe)
	{
		state = set_tempe;
		LCD_Show_set_temp(set_Temperture);
	}
	else
	{
		if (set_Temperture <= 35)
		{
			set_Temperture = 35;
		}
		else
		{
			set_Temperture = set_Temperture - 5;
		}
	}
	state = set_tempe;

}

void Sev_seg_blink(unsigned char TEMP)
{		for (int timer = 0;timer<25;timer++)
	   {
		 sev_seg_enable();
		 sev_seg_1_displaynumper(TEMP/10);
		 sev_seg_2_displaynumper(TEMP%10);
		 _delay_ms(100);
		 sev_seg_disable();
		 _delay_ms(100);
	   }
}

/*ISR(TIMER0_COMP_vect)
{
	tick_counter++;
}*/

