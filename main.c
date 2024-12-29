/*
 * LEDBlinkToggle.c
 *
 * Created: 14-03-2024 23:41:39
 * Author : Dev Arora
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRA=0x01;
    /* Replace with your application code */
    while (1) 
    {
		PORTA ^=(1<<0);
		_delay_ms(100);
		
    }
	return 0;
}

