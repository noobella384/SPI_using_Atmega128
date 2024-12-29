/*
 * UART.c
 *
 * Created: 21-03-2024 22:27:52
 * Author : Dev Arora
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>
#define Bud 9600UL
#define ubrr ((F_CPU / (Bud*16)) - 1)

void UART_init(unsigned long BUD)
{
	UCSR0B = UCSR0B | (1<< TXEN0);
	UCSR0C =  (1<< UCSZ00) | (1<<UCSZ01);
	UBRR0L= ubrr;
	UBRR0H= ubrr >> 8;
	
}
void UART_TxChar(char ch){
	while (! (UCSR0A & (1<<UDRE0)));
	UDR0=ch;
}
void UART_SendString(char *str)
{
	unsigned char j=0;
	
	while (str[j]!=0)		/* Send string till null */
	{
		UART_TxChar(str[j]);
		j++;
	}
}

int main(void)
{
    char ch=9;
	UART_init(9600);
	
    while (1) 
    {
		UART_TxChar(ch);
		UART_SendString("dev");
		PORTA ^=0xff;
		_delay_ms(1000);
    }
}

