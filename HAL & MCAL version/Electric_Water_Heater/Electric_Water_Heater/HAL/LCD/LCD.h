#ifndef LCD_h_
#define LCD_h_


////LCD CONTROL LINE CONFIGURATIONS
#define LCD_CONTROL_PORT				PORTC
#define LCD_CONTROL_PORT_STATE			DDRC
#define LCD_RS_PIN						PC5				
#define LCD_RW_PIN						PC6				
#define LCD_EN_PIN						PC7				


//LCD DATA LINE CONFIGURATIONS
#define LCD_DATA_PORT					PORTD
#define LCD_DATA_PORT_STATE				DDRD
#define LCD_D4_PIN						PD4				//"PIN4"
#define LCD_D5_PIN						PD5				//"PIN5"
#define LCD_D6_PIN						PD6				//"PIN6"
#define LCD_D7_PIN						PD7				//"PIN7"



//LCD Instructions
#define internal_8bit					0x38
#define internal_2lines_4bit			0x28
#define send_4bit_intitializsion		0x02
#define disply_on_corsor_off			0x0c
#define disply_on_corsor_on				0x0F
#define auto_increment					0x06
#define clear_disply					0x01
#define home_position					0x80
#define right_shift						0b00010100 //0x0E
#define NextLine						0xc0

//LCD delays
#define LCD_PowerOn_Delay				100
#define LCD_instruction_Delay			40

//LCD FUNCTIONS
void LCD_COMMAND(char x);
void LCD_int();
void LCD_char(char x);
void LCD_String (char *str);
void LCD_Write_Integer(int data);
void LCD_Clear();
void LCD_Show_temp(int x);
void LCD_off();
void LCD_Show_set_temp(int x);

#endif