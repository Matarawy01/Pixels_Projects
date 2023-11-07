/*
 * USART.h
 *
 * Created: 3/12/2023 6:02:39 AM
 *  Author: abdel
 */ 


#ifndef USART_H_
#define USART_H_
UART_vinit(unsigned long baud);
void UART_vsendData(char data);
int UART_u8ReceiveData(void);
void UART_vsendString(char*ptr);

#endif /* USART_H_ */