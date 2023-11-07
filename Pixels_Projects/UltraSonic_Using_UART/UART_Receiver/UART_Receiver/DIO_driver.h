/*
 * DIO_driver.h
 *
 * Created: 9/27/2022 9:50:33 AM
 *  Author: abdel
 */ 


#ifndef DIO_DRIVER_H_
#define DIO_DRIVER_H_
void DIO_vset_pindir(unsigned char port,unsigned char pin,unsigned char dir);
void DIO_vwrite_pin(unsigned char port,unsigned char pin,unsigned char val);
unsigned char DIO_U8read_pin(unsigned char port,unsigned char pin);
void DIO_vtoggle(unsigned char port,unsigned char pin);
void DIO_vset_portdir(unsigned char port,unsigned char dir);
void DIO_vwrite_port(unsigned char port,unsigned char val);
unsigned char DIO_U8read_port(unsigned char port);
void DIO_vtog_port(unsigned char port);
void DIO_vcontrolpullup(unsigned char port,unsigned char pin,unsigned char enable);
#endif /* DIO_DRIVER_H_ */