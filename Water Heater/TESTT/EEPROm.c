/*
 * EEPROm.c
 *
 * Created: 29/01/2023 6:54:36 PM
 *  Author: Lenovo
 */ 
#include <avr/io.h>
#define F_CPU 1000000ul
#include "EEPROM.h"
#include "I2C.h"
#include "BitWiseOperation.h"
#include <util/delay.h>

void EEPROM_init(void)
{
	I2C_Init();
}

void EEPROM_writeByte(char eepromblock,char eepromaddress,char Data)
{
	I2C_Start(eepromblock);
	I2C_Write(eepromaddress);
	_delay_ms(10);
	I2C_Write(Data);
	_delay_ms(10);
	I2C_Stop();
}

void EEPROM_writeDataStream(char eepromblock,char eepromaddress,char *Data,char DataSize)
{
	char loopingVar;
	//Checking if the write  size is more than page size or not
	if (DataSize > EEPRO_PAGE_SIZE)
	{
		loopingVar = EEPRO_PAGE_SIZE ;//setting the page size as default
	}
	else
	{
		loopingVar = DataSize;
	}
	
	I2C_Start(eepromblock);
	I2C_Write(eepromaddress);
	_delay_ms(10);
	
	while(loopingVar)
	{
		I2C_Write(*Data);
		Data++;
		loopingVar--;
	}
	_delay_ms(10);
	I2C_Stop();
}

void EEPROM_readByte(char eepromblock,char eepromaddress,char *Data)
{
	I2C_Start(eepromblock);
	I2C_Write(eepromaddress);
	I2C_Repeated_Start(eepromblock+1);
	*Data = I2C_Read_Ack();
	_delay_ms(10);
	I2C_Stop();
}

void EEPROM_readDatastream(char eepromblock,char eepromaddress,char *Data,char DataSize)
{
	I2C_Start(eepromblock);
	I2C_Write(eepromaddress);
	I2C_Repeated_Start(eepromblock+1);
	
	while(DataSize)
	{
		*Data = I2C_Read_Ack();
		_delay_ms(10);
		Data++;
		DataSize--;
	}
	_delay_ms(10);
	I2C_Stop();
}


