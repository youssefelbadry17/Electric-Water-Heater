/*
 * Seven_Segment.h
 *
 * Created: 29/01/2023 7:20:50 PM
 *  Author: Lenovo
 */ 


#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_


//Macros
#define Sev_Seg_1_state DDRA //Sev_Seg_1_Port_State and Sev_Seg_2_Port_State in port A
#define Sev_Seg_2_state DDRB
#define Sev_Seg_1_Port PORTA		//Sev_Seg_1_Port_State and Sev_Seg_2_Port_State in port A
#define Sev_Seg_2_Port PORTB
#define Sev_Seg_en PB3
#define Sev_Seg_1_Pin1 PA4
#define Sev_Seg_1_Pin2 PA5
#define Sev_Seg_1_Pin3 PA6
#define Sev_Seg_1_Pin4 PA7
#define Sev_Seg_2_Pin1 PB4
#define Sev_Seg_2_Pin2 PB5
#define Sev_Seg_2_Pin3 PB6
#define Sev_Seg_2_Pin4 PB7

//Functions
void sev_seg_init();
void sev_seg_enable();
void sev_seg_disable();
void sev_seg_1_displaynumper(int N);
void sev_seg_2_displaynumper(int N);



#endif /* SEVEN_SEGMENT_H_ */