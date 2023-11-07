/*
 * lcd.c
 *
 * Created: 11/29/2022 4:30:35 PM
 *  Author: abdel
 */ 
#include "lcd_driver.h"
#include "DIO_driver.h"
#define F_CPU 1000000UL
#include <util/delay.h>
#include "std_macros.h"
void LCD_vinit()
{
	#if defined eight_bits_mode
	_delay_ms(200);
	DIO_vset_pindir('A',0,1);
	DIO_vset_pindir('A',1,1);
	DIO_vset_pindir('A',2,1);
	DIO_vset_pindir('A',3,1);
	DIO_vset_pindir('A',4,1);
	DIO_vset_pindir('A',5,1);
	DIO_vset_pindir('A',6,1);
	DIO_vset_pindir('A',7,1);
	DIO_vset_pindir('B',EN,1);
	DIO_vset_pindir('B',RW,1);
	DIO_vset_pindir('B',RS,1);
	DIO_vwrite_pin('B',RW,0);
	LCD_vsend_cmd(EIGHT_BITS); //8 bit mode
	_delay_ms(1);
	LCD_vsend_cmd(CURSOR_ON_DISPLAN_ON);//display on cursor on
	_delay_ms(1);
	LCD_vsend_cmd(CLR_SCREEN);//clear the screen
	_delay_ms(10);
	LCD_vsend_cmd(ENTRY_MODE); //entry mode
	_delay_ms(1);
	
	#elif defined four_bits_mode
	_delay_ms(200);
	DIO_vset_pindir('A',4,1);
	DIO_vset_pindir('A',5,1);
	DIO_vset_pindir('A',6,1);
	DIO_vset_pindir('A',7,1);
	DIO_vset_pindir('A',EN,1);
	DIO_vset_pindir('A',RW,1);
	DIO_vset_pindir('A',RS,1);
	DIO_vwrite_pin('A',RW,0);
	LCD_vsend_cmd(RETURN_HOME); //return home
	_delay_ms(10);
	LCD_vsend_cmd(FOUR_BITS); //4 bit mode
	_delay_ms(1);
	LCD_vsend_cmd(CURSOR_ON_DISPLAN_ON);//display on cursor on
	_delay_ms(1);
	LCD_vsend_cmd(CLR_SCREEN);//clear the screen
	_delay_ms(10);
	LCD_vsend_cmd(ENTRY_MODE); //entry mode
	_delay_ms(1);
	#endif
}
static void send_falling_edge(void)
{
	DIO_vwrite_pin('A',EN,1);
	_delay_ms(2);
	DIO_vwrite_pin('A',EN,0);
	_delay_ms(2);
}
void LCD_vsend_char(char data)
{
	#if defined eight_bits_mode
	DIO_vwrite_port('A',data);
	DIO_vwrite_pin('B',RS,1);
	send_falling_edge();
	
	#elif defined four_bits_mode
	vwrite_highnibble('A',data>>4);
	DIO_vwrite_pin('A',RS,1);
	send_falling_edge();
	vwrite_highnibble('A',data);
	DIO_vwrite_pin('A',RS,1);
	send_falling_edge();
	_delay_ms(1);
	#endif
}
void LCD_vsend_cmd(char cmd)
{
	#if defined eight_bits_mode
	DIO_vwrite_port('A',cmd);
	DIO_vwrite_pin('B',RS,0);
	send_falling_edge();
	
	#elif defined four_bits_mode
	vwrite_highnibble('A',cmd>>4);
	DIO_vwrite_pin('A',RS,0);
	send_falling_edge();
	vwrite_highnibble('A',cmd);
	DIO_vwrite_pin('A',RS,0);
	send_falling_edge();
	_delay_ms(1);
	#endif
}
void LCD_vclearscreen()
{
	LCD_vsend_cmd(CLR_SCREEN);
	_delay_ms(10);
}

void LCD_vmove_cursor(unsigned char row , unsigned char coloumn)
{
	char data ;
	if(row>2||row<1||coloumn>16||coloumn<1)
	{
		data=0x80;
	}
	else if(row==1)
	{
		data=0x80+coloumn-1 ;
	}
	else if (row==2)
	{
		data=0xc0+coloumn-1;
	}	LCD_vsend_cmd(data);
	_delay_ms(1);	
}
void LCD_vSend_string(char *data)
{
	while((*data)!='\0')
	{
		LCD_vsend_char(*data);
		data++;
	}
}
void vwrite_lownibble(unsigned char port,unsigned char number)
{
	DIO_vwrite_pin(port,0,READ_BIT(number,0));
	DIO_vwrite_pin(port,1,READ_BIT(number,1));
	DIO_vwrite_pin(port,2,READ_BIT(number,2));
	DIO_vwrite_pin(port,3,READ_BIT(number,3));
}
void vwrite_highnibble(unsigned char port,unsigned char number)
{
	DIO_vwrite_pin(port,4,READ_BIT(number,0));
	DIO_vwrite_pin(port,5,READ_BIT(number,1));
	DIO_vwrite_pin(port,6,READ_BIT(number,2));
	DIO_vwrite_pin(port,7,READ_BIT(number,3));
}