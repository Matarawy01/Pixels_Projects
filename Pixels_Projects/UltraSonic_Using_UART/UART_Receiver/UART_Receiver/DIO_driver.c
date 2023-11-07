#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
#include "std_macros.h"
void DIO_vset_pindir(unsigned char port,unsigned char pin,unsigned char dir)
{
switch(port)
{
	case 'A':
	case 'a':
	if(dir==1)
	{
		SET_BIT(DDRA,pin);
	} 
	else
	{
		CLR_BIT(DDRA,pin);
	}
	break;
	case 'B':
	case 'b':
	if(dir==1)
	{
		SET_BIT(DDRB,pin);
	}
	else
	{
		CLR_BIT(DDRB,pin);
	}
	break;
	case 'C':
	case 'c':
	if(dir==1)
	{
		SET_BIT(DDRC,pin);
	}
	else
	{
		CLR_BIT(DDRC,pin);
	}
	break;
	case 'D':
	case 'd':
	if(dir==1)
	{
		SET_BIT(DDRD,pin);
	}
	else
	{
		CLR_BIT(DDRD,pin);
	}
	break;
}}
void DIO_vwrite_pin(unsigned char port,unsigned char pin,unsigned char val)
{
	switch(port)
	{
		case 'A':
		case 'a':
		if(val==1)
		{
			SET_BIT(PORTA,pin);
		}
		else
		{
			CLR_BIT(PORTA,pin);
		}
		break;
		case 'B':
		case 'b':
		if(val==1)
		{
			SET_BIT(PORTB,pin);
		}
		else
		{
			CLR_BIT(PORTB,pin);
		}
		break;
		case 'C':
		case 'c':
		if(val==1)
		{
			SET_BIT(PORTC,pin);
		}
		else
		{
			CLR_BIT(PORTC,pin);
		}
		break;
		case 'D':
		case 'd':
		if(val==1)
		{
			SET_BIT(PORTD,pin);
		}
		else
		{
			CLR_BIT(PORTD,pin);
		}
		break;
	}}
unsigned char DIO_U8read_pin(unsigned char port,unsigned char pin)
{
	unsigned char value;
	switch(port)
	{
		case 'A':
		case 'a':
			value=READ_BIT(PINA,pin);
			break;
		case 'B':
		case 'b':
			value=READ_BIT(PINB,pin);
			break;
		case 'C':
		case 'c':
			value=READ_BIT(PINC,pin);
			break;
		case 'D':
		case 'd':
			value=READ_BIT(PIND,pin);
			break;
	}
	return value;
} 
void DIO_vtoggle(unsigned char port,unsigned char pin)
{
switch(port)
{
	case 'A':
	case 'a':
		TOG_BIT(PORTA,pin);
		break;
	case 'B':
	case 'b':
		TOG_BIT(PORTB,pin);
		break;
	case 'C':
	case 'c':
		TOG_BIT(PORTC,pin);
		break;
	case 'D':
	case 'd':
		TOG_BIT(PORTD,pin);
		break;
	}
}
void DIO_vset_portdir(unsigned char port,unsigned char dir)
{
	switch(port)
	{
		case 'A':
		case 'a':
		DDRA=dir;
		break;
		case 'B':
		case 'b':
		DDRB=dir;
		break;
		case 'C':
		case 'c':
		DDRC=dir;
		break;
		case 'D':
		case 'd':
		DDRD=dir;
		break;
	}
}
void DIO_vwrite_port(unsigned char port,unsigned char val)
{
	switch(port)
	{
		case 'A':
		case 'a':
		PORTA=val;
		break;
		case 'B':
		case 'b':
		PORTB=val;
		break;
		case 'C':
		case 'c':
		PORTC=val;
		break;
		case 'D':
		case 'd':
		PORTD=val;
		break;
	}
}
unsigned char DIO_U8read_port(unsigned char port)
{
	int val;
	switch(port)
	{
		case 'A':
		case 'a':
		PINA=val;
		break;
		case 'B':
		case 'b':
		val=PINB;
		break;
		case 'C':
		case 'c':
		val=PINC;
		break;
		case 'D':
		case 'd':
		val=PIND;
		break;
	}
	return val;
}
void DIO_vtog_port(unsigned char port)
{
	switch(port)
	{
		case 'A':
		case 'a':
		PORTA=~PORTA;
		break;
		case 'B':
		case 'b':
		PORTB=~PORTB;
		break;
		case 'C':
		case 'c':
		PORTC=~PORTC;
		break;
		case 'D':
		case 'd':
		PORTD=~PORTD;
		break;
	}
}
void DIO_vcontrolpullup(unsigned char port,unsigned char pin,unsigned char enable)
{
	switch(port)
	{
		case 'a':
		case 'A':
		if(enable==1)
		{
			SET_BIT(PORTA,pin);
		}
		else
		{
			CLR_BIT(PORTA,pin);
		}
		break;
		case 'b':
		case 'B':
		if(enable==1)
		{
			SET_BIT(PORTB,pin);
		}
		else
		{
			CLR_BIT(PORTB,pin);
		}
		break;
		case 'c':
		case 'C':
		if(enable==1)
		{
			SET_BIT(PORTC,pin);
		}
		else
		{
			CLR_BIT(PORTC,pin);
		}
		break;
		case 'd':
		case 'D':
		if(enable==1)
		{
			SET_BIT(PORTD,pin);
		}
		else
		{
			CLR_BIT(PORTD,pin);
		}
		break;
		
	}
	
}