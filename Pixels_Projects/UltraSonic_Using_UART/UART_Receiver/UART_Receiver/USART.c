#define F_CPU 1000000UL
#include <util/delay.h>
#include "std_macros.h"
#include <avr/io.h>

void UART_vinit(unsigned long baud)
{
	unsigned short UBRR;
	UBRR=(F_CPU/(16*baud))-1;
	UBRRH=(unsigned char)(UBRR>>8);
	UBRRL=(unsigned char)UBRR;
	SET_BIT(UCSRB,RXEN);
	SET_BIT(UCSRB,TXEN);
	UCSRC=(1<<URSEL) | (1<<UCSZ0) | (1<<UCSZ1);
}

void UART_vsendData(char data)
{
	while(READ_BIT(UCSRA,UDRE)==0);
	UDR=data;
}

int UART_u8ReceiveData(void)
{
	while(READ_BIT(UCSRA,RXC)==0);
	return UDR;
}

void UART_vsendString(char*ptr)
{
	while(*ptr !=0)
	{
		UART_vsendData(*ptr);
		ptr++;
		_delay_ms(100);
	}
}