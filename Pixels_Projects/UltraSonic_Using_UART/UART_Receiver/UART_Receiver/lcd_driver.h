/*
 * lcd.h
 *
 * Created: 11/29/2022 4:30:47 PM
 *  Author: abdel
 */
#ifndef LCD_H_
#define LCD_H_
#include "DIO_driver.h"
#include "LCD_config.h"
#define CLR_SCREEN 0x01
#define CURSOR_ON_DISPLAN_ON 0x0E
#define CURSOR_OFF_DISPLAN_OFF 0x08
#define CURSOR_OFF_DISPLAN_ON 0x0c
#define CURSOR_BLINK_DISPLAN_ON 0x0f
#define RETURN_HOME 0x02
#define ENTRY_MODE 0x06 
#if defined four_bits_mode
#define EN 0
#define RW 1
#define RS 2
#define FOUR_BITS 0x28
#elif defined eight_bits_mode
#define EN 0
#define RS 1
#define RW 2
#define EIGHT_BITS 0x38
#endif
void LCD_vinit();
static void send_falling_edge(void);
void LCD_vsend_char(char data);
void LCD_vsend_cmd(char cmd);
void LCD_vclearscreen();
void LCD_vmove_cursor(unsigned char row , unsigned char column);
void LCD_vSend_string(char *data);
void vwrite_lownibble(unsigned char port,unsigned char number);
void vwrite_highnibble(unsigned char port,unsigned char number);
#endif /* LCD_H_ */