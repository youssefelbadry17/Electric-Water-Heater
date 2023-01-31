/*
 * I2C.h
 *
 * Created: 29/01/2023 7:07:30 PM
 *  Author: Lenovo
 */ 


#ifndef I2C_H_
#define I2C_H_

//Macros
#define SCL_CLK 10000
#define BITRATE(TWSR)	((F_CPU/SCL_CLK)-16)/(2*pow(4,(TWSR&((1<<TWPS0)|(1<<TWPS1)))))

//Functions
void I2C_Init();
char I2C_Start(char address);
char I2C_Repeated_Start(char read_address);
char I2C_Read_Ack();
void I2C_Stop()	;



#endif /* I2C_H_ */