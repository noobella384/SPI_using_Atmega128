/*
 * SPI2.c
 *
 * Created: 25-03-2024 22:48:36
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

char SPI_SlaveReceive(void)
{
	while(!(SPSR & (1<<SPIF)));
	PORTA^=0xff;
	return SPDR;
}

int main(void)
{
	
	DDRB =DDRB | (1<<3);
	SPCR=SPCR | (1 <<SPE);
	UART_init(9600);
	PORTA=0xff;
	_delay_ms(1000);
	while(1){
	char c=SPI_SlaveReceive();
	_delay_ms(50);
	UART_TxChar(c);
	_delay_ms(50);
}
return 0;
}
 

