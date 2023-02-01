#define F_CPU 1000000ul
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "LM35.h"
#include "../BItWise/BitWiseOperation.h"


void ADC_initi(int adc_number) //ADC initialize
{
	//ADMUX |= 0000 0010 ADC2 for example
	//start conversion in read or auto trigger
	clear(DDRA,1);
	ADMUX |= adc_number; //choose which ADC will work
	set (ADMUX,REFS0); //AVCC with external capacitor at AREF
	set (ADCSRA,ADEN); //ADC enable
	set (ADCSRA,ADPS0); //prescaler 16 //ADC speed must be in range of 50k and 200k
	set (ADCSRA,ADPS1); //prescaler for kit cpu is 16000000 so we divide it over 128 (1 1 1)
	set (ADCSRA,ADPS2);
}

/********************************************************************************************************/

unsigned int ADC_read() //ADC read
{
	unsigned int ADC_read=0;
	set (ADCSRA,ADSC); //ADC start conversion
	while(!(ADCSRA&(1<<ADIF))); //wait until conversion complete
	{
		
		
	}
	_delay_us(10); //wait until the value stored in ADC register
	ADC_read = (int)ADCL + (int) ADCH*256; // calculate ADC value
	return ADC_read;
}

/*******************************************************************************************/

int avg_tempreture (void) //Average Temperture
{
	unsigned int tempreture=0;
	int temp=0;
	unsigned char i=0;
	int Average=0;
	
	ADC_initi(1);
	
	while (1)
	{
		tempreture = ADC_read(1);
		tempreture = (tempreture*5.0/1024.0)*100.0;
		
		if (i<10)
		{
			temp=temp+tempreture;
			i++;
		}
		else
		{
			Average=temp/10;
			break;
		}
		_delay_ms(100);	
	}
	return Average;
}

/*******************************************************************************************/

