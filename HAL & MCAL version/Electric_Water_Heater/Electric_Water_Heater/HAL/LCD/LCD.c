#include <avr/io.h>
#define F_CPU 1000000ul
#include <util/delay.h>
#include "LCD.h"
#include "../BItWise/BitWiseOperation.h"

void LCD_COMMAND(char x)
{
	LCD_DATA_PORT=(LCD_DATA_PORT&0x0F)|(0xF0&x);
	
	clear(LCD_CONTROL_PORT,LCD_RS_PIN);
	clear(LCD_CONTROL_PORT,LCD_RW_PIN);
	set(LCD_CONTROL_PORT,LCD_EN_PIN);
	_delay_ms(LCD_instruction_Delay/*=2*/);  //_delay_us(20);
	clear(LCD_CONTROL_PORT,LCD_EN_PIN);
	_delay_ms(LCD_instruction_Delay);
	
	LCD_DATA_PORT=(LCD_DATA_PORT&0x0F)|(0xF0&(x<<4));
	clear(LCD_CONTROL_PORT,LCD_RS_PIN);
	clear(LCD_CONTROL_PORT,LCD_RW_PIN);
	set(LCD_CONTROL_PORT,LCD_EN_PIN);
	_delay_ms(LCD_instruction_Delay/*=2*/);  //_delay_us(20);
	clear(LCD_CONTROL_PORT,LCD_EN_PIN);
	_delay_ms(LCD_instruction_Delay);
}

void LCD_int()
{
	//SETTING LCD PINS AS OUTPUT
	set(LCD_CONTROL_PORT_STATE,LCD_RS_PIN);
	set(LCD_CONTROL_PORT_STATE,LCD_RW_PIN);
	set(LCD_CONTROL_PORT_STATE,LCD_EN_PIN);
	set(LCD_DATA_PORT_STATE,LCD_D4_PIN);
	set(LCD_DATA_PORT_STATE,LCD_D5_PIN);
	set(LCD_DATA_PORT_STATE,LCD_D6_PIN);
	set(LCD_DATA_PORT_STATE,LCD_D7_PIN);

	_delay_ms(LCD_PowerOn_Delay);
	LCD_COMMAND(send_4bit_intitializsion);		//4-bit bus mode
	_delay_ms(LCD_instruction_Delay);
	LCD_COMMAND(internal_2lines_4bit);			//function set
	_delay_ms(LCD_instruction_Delay);
	LCD_COMMAND(home_position);					//return home
	_delay_ms(LCD_instruction_Delay);
	LCD_COMMAND(disply_on_corsor_off);			//display on/off control
	_delay_ms(LCD_instruction_Delay);
	LCD_COMMAND(clear_disply);					//clear display
	_delay_ms(LCD_instruction_Delay);
	LCD_COMMAND(auto_increment);				//entry mode
	_delay_ms(LCD_instruction_Delay);
}

void LCD_char(char x)
{
	LCD_DATA_PORT=(LCD_DATA_PORT&0x0F)|(0xF0&x);
	set(LCD_CONTROL_PORT,LCD_RS_PIN);
	clear(LCD_CONTROL_PORT,LCD_RW_PIN);
	set(LCD_CONTROL_PORT,LCD_EN_PIN);
	_delay_ms(LCD_instruction_Delay/*=2*/);  //_delay_us(200);
	clear(LCD_CONTROL_PORT,LCD_EN_PIN);
	_delay_ms(LCD_instruction_Delay);
	
	LCD_DATA_PORT=(LCD_DATA_PORT&0x0F)|(0xF0&(x<<4));
	set(LCD_CONTROL_PORT,LCD_RS_PIN);
	clear(LCD_CONTROL_PORT,LCD_RW_PIN);
	set(LCD_CONTROL_PORT,LCD_EN_PIN);
	_delay_ms(LCD_instruction_Delay/*=2*/);  //_delay_us(200);
	clear(LCD_CONTROL_PORT,LCD_EN_PIN);
	_delay_ms(LCD_instruction_Delay);
}

void LCD_String (char *str)		/* Send string to LCD function  */
{
	int i;
	for(i=0;str[i]!=0;i++)		/* Send each char of string till the NULL */
	{
		LCD_char (str[i]);
	}
}

void LCD_Clear()
{
	LCD_COMMAND (clear_disply);
	_delay_ms(LCD_instruction_Delay);
	LCD_COMMAND (home_position);
}

void LCD_Show_temp(int x)
{
	LCD_Clear();
	LCD_String("Current Temp");
	LCD_COMMAND(NextLine);
	unsigned char ch[3]={' '};
	for(int i=0;i<3;i++)
	{
		ch[i]=' ';
	}
	itoa(x,ch,10);
	for (int j=0;j<3;j++)
	{
		if (ch[j]<'0'||ch[j]>'9')
		LCD_char(' ');
		else
		LCD_char(ch[j]);
	}
	LCD_String("'C");
}

void LCD_off()
{
	LCD_Clear();
	LCD_String("turning off");	
	LCD_COMMAND(NextLine);
	LCD_String("    :(");
	_delay_ms(100);
	LCD_Clear();
	LCD_COMMAND(disply_on_corsor_off);
	LCD_CONTROL_PORT=0x00;
}

void LCD_Show_set_temp(int x)
{
	LCD_Clear();
	LCD_String("Set Temp");
	LCD_COMMAND(NextLine);
	unsigned char ch[3]={' '};
	for(int i=0;i<3;i++)
	{
		ch[i]=' ';
	}
	itoa(x,ch,10);
	for (int j=0;j<3;j++)
	{
		if (ch[j]<'0'||ch[j]>'9')
		LCD_char(' ');
		else
		LCD_char(ch[j]);
	}
	LCD_String("'C");
}