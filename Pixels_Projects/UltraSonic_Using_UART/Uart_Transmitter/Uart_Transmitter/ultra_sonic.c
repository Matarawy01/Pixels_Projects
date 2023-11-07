#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
int ultra_sonic()
{
	unsigned short a,b,high,distance;
	DIO_vset_pindir('d',7,1);

    TCCR1A=0;  //To work in Normal Mode 
	TIFR=(1<<ICF1); //Clearing the flag bit by writing logic one on it
	DIO_vwrite_pin('d',7,1);
	_delay_us(50);
	DIO_vwrite_pin('d',7,0);
		
	TCCR1B=0xc1; // c-> we activate noise cancellation and detection of raising edge ... 1-> for prescaler 1 
	while((TIFR&(1<<ICF1))==0); //polling until reach raising edge
	a=ICR1; //For first raising edge
		
	TIFR=(1<<ICF1); //Clearing the flag bit by writing logic one on it
	TCCR1B=0x81; // 8-> we activate noise cancellation and detection of falling edge ... 1-> for prescaler 1 
	while((TIFR&(1<<ICF1))==0);
	b=ICR1; // for first falling edge
		
	TIFR=(1<<ICF1);
	TCNT1=0;
	TCCR1B=0;
	high=b-a; //We now having ON time
	distance=((high*34600)/(2*F_CPU));
	if(distance>=80)
	{
		return 0;
	}
	else
	{
		return distance;
	}
								
}