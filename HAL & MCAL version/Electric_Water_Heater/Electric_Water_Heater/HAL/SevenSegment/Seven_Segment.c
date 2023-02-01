/*
 * Seven_Segment.c
 *
 * Created: 29/01/2023 9:42:59 PM
 *  Author: Lenovo
 */ 

#include <avr/io.h>
#define F_CPU 1000000ul
#include "Seven_Segment.h"
#include "../BItWise/BitWiseOperation.h"
#include <util/delay.h>

void sev_seg_init()
{
	set(Sev_Seg_2_state,Sev_Seg_en);
	/*switch(N)
	{
		case 0 : set(Sev_Seg_Port_State,Sev_Seg_1); break;
		case 1 : set(Sev_Seg_Port_State,Sev_Seg_2); break;
		default: ;
	}*/
}

void sev_seg_enable()
{	set(Sev_Seg_2_Port,Sev_Seg_en);
	/*switch(N)
	{
		case 0 : set(Sev_Seg_Port,Sev_Seg_1); break;
		case 1 : set(Sev_Seg_Port,Sev_Seg_2); break;
		default: ;
	}*/
}

void sev_seg_disable()
{
	clear(Sev_Seg_2_Port,Sev_Seg_en);
	/*
	switch(N)
	{
		case 0 : clear(Sev_Seg_Port,Sev_Seg_1); break;
		case 1 : clear(Sev_Seg_Port,Sev_Seg_2); break;
		default: ;
	}*/
}

void sev_seg_1_displaynumper(int N)
{	int bite;
	set(Sev_Seg_1_Port,Sev_Seg_1_Pin1);
	set(Sev_Seg_1_Port,Sev_Seg_1_Pin2);
	set(Sev_Seg_1_Port,Sev_Seg_1_Pin3);
	set(Sev_Seg_1_Port,Sev_Seg_1_Pin4);
		
	if (N <=9)
	{
		for (int i=4;i<8;i++)
		{
			bite=(N&(1<<(i-4)))>>(i-4);
			if (bite!=0)
			{
				set(Sev_Seg_1_Port,i);
			}
			else
			{
				clear(Sev_Seg_1_Port,i);
			}
		}
	}
	else
	{
		//do nothing
	}
}
void sev_seg_2_displaynumper(int N)
{	int bite;
	set(Sev_Seg_2_Port,Sev_Seg_2_Pin1);
	set(Sev_Seg_2_Port,Sev_Seg_2_Pin2);
	set(Sev_Seg_2_Port,Sev_Seg_2_Pin3);
	set(Sev_Seg_2_Port,Sev_Seg_2_Pin4);
	
	if (N <=9)
	{
		for (int i=4;i<8;i++)
		{
			bite=(N&(1<<(i-4)))>>(i-4);
			if (bite!=0)
			{
				set(Sev_Seg_2_Port,i);
			}
			else
			{
				clear(Sev_Seg_2_Port,i);
			}
		}
	}
	else
	{
		//do nothing
	}
}
