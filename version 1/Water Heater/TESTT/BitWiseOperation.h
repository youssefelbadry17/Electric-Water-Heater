/*
 * BitWiseOperation.h
 *
 * Created: 29/01/2023 11:09:14 PM
 *  Author: Lenovo
 */ 


#ifndef BITWISEOPERATION_H_
#define BITWISEOPERATION_H_

#define set(reg,bit)	reg|=(1<<bit)
#define clear(reg,bit)	reg&=(~(1<<bit))
#define toggle(reg,bit) reg^=(1<<bit)
#define read(reg,bit)	(reg&(1<<bit))>>bit


#endif /* BITWISEOPERATION_H_ */