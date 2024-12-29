/*
 * SPI1.c
 *
 * Created: 25-03-2024 18:14:01
 * Author : Dev Arora
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>
#define Bud 9600UL

int main(void){
	DDRA=0xff;
	PORTA=0xff;
	_delay_ms(1000);
	DDRB=DDRB | (1<<2) |(1<<0);
	PORTB=PORTB & 0b11111110;
	DDRB=DDRB | (1<<1);
	SPCR= SPCR | (1<<SPE) | (1<<MSTR) | (1<<SPR0);
	
	while(1){
	SPDR='d';
    while (!(SPSR & (1<<SPIF)));
	_delay_ms(100);
	SPDR='e';
	while (!(SPSR & (1<<SPIF)));
	_delay_ms(100);
	SPDR='v';
	while (!(SPSR & (1<<SPIF)));
	_delay_ms(100);
	SPDR=' ';
	while (!(SPSR & (1<<SPIF)));
	_delay_ms(100);
	}
	return 0;
}

