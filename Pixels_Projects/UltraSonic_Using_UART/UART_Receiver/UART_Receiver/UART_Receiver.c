/*
 * UART_Receiver.c
 *
 * Created: 11/7/2023 4:13:47 PM
 *  Author: abdel
 */ 




#include <avr/io.h>
#define F_CPU 1000000UL
#include "USART.h"
#include "lcd_driver.h"
#include <util/delay.h>
int main(void)
{
	int Received_Data;
	LCD_vinit();
	UART_vinit(9600);
    while(1)
    {
        Received_Data =UART_u8ReceiveData();
		if(Received_Data == 0)
		{
			LCD_vclearscreen();
			LCD_vSend_string("No Object");
			_delay_ms(500);
		}
		else
		{
			LCD_vclearscreen();
			LCD_vSend_string("Distance = ");
			LCD_vsend_char((Received_Data/10)+48);
			LCD_vsend_char((Received_Data%10)+48);
			LCD_vSend_string("Cm");
			_delay_ms(500);
		}								
    }
}