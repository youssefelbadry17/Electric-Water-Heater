/*
 * EEPROM.h
 *
 * Created: 29/01/2023 6:58:24 PM
 *  Author: Lenovo
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#define EEPROM_SlAVE_ADDRESS_BASE 0x50

#define EEPROM_BLOCK_0 0
#define EEPROM_BLOCK_1 1
#define EEPROM_BLOCK_2 2
#define EEPROM_BLOCK_3 3
#define EEPROM_BLOCK_4 4
#define EEPROM_BLOCK_5 5
#define EEPROM_BLOCK_6 6
#define EEPROM_BLOCK_7 7

#define BLOCK_0 (EEPROM_SlAVE_ADDRESS_BASE|EEPROM_BLOCK_0)<<1
#define BLOCK_1 (EEPROM_SlAVE_ADDRESS_BASE|EEPROM_BLOCK_1)<<1
#define BLOCK_2 (EEPROM_SlAVE_ADDRESS_BASE|EEPROM_BLOCK_2)<<1
#define BLOCK_3 (EEPROM_SlAVE_ADDRESS_BASE|EEPROM_BLOCK_3)<<1
#define BLOCK_4 (EEPROM_SlAVE_ADDRESS_BASE|EEPROM_BLOCK_4)<<1
#define BLOCK_5 (EEPROM_SlAVE_ADDRESS_BASE|EEPROM_BLOCK_5)<<1
#define BLOCK_6 (EEPROM_SlAVE_ADDRESS_BASE|EEPROM_BLOCK_6)<<1
#define BLOCK_7 (EEPROM_SlAVE_ADDRESS_BASE|EEPROM_BLOCK_7)<<1

#define EEPRO_PAGE_SIZE 16

//functions
void EEPROM_init(void); //Initializing I2C communication with 100KHz
void EEPROM_writeByte(char eepromblock,char eepromaddress,char Data); //writing a data byte in a specific eeprom block
void EEPROM_writeDataStream(char eepromblock,char eepromaddress,char *Data,char DataSize);//writing a stream of data bytes in a specific eeprom block (max 16 bytes)
void EEPROM_readByte(char eepromblock,char eepromaddress,char *Data); // reading a data byte from a specific eeprom block
void EEPROM_readDatastream(char eepromblock,char eepromaddress,char *Data,char DataSize); // reading a stream of data bytes from a specific eeprom block

#endif /* EEPROM_H_ */