/*
 * Uart_Transmitter.c
 *
 * Created: 11/7/2023 4:12:53 PM
 *  Author: Abdelrahman Matarawy
 */ 


#include <avr/io.h>
#include "ultra_sonic.h"
#include "USART.h"
#define F_CPU 1000000UL
#include <util/delay.h>
int main(void)
{
	UART_vinit(9600);
	_delay_ms(300);
	int distance=0;
    while(1)
    {
        distance = ultra_sonic();
		UART_vsendData(distance);
		_delay_ms(1000); 
    }
}