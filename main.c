	/*
 * traffic1.c
 *
 * Created: 30-03-2024 21:39:47
 * Author : Dev Arora
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>
#define Bud 9600UL
#define RS PG2
#define RW PG1
#define EN PG0
#define LCD_Data_Dir DDRC		
#define LCD_Command_Dir DDRG		
#define LCD_Data_Port PORTC		
#define LCD_Command_Port PORTG

void LCD_Command(unsigned char c)
{
	PORTC= c;
	PORTG &= ~(1<<RS);	/* RS=0 command reg. */
	PORTG &= ~(1<<RW);	/* RW=0 Write operation */
	PORTG |= (1<<EN);	/* Enable pulse */
	_delay_us(10);
	PORTG &= ~(1<<EN);
	_delay_ms(3);
}
void LCD_Init (void){
	DDRC=0xff;
	DDRG=0xff;
	_delay_ms(30);
	LCD_Command (0x38);
	_delay_ms(2);/* Initialization of 16X2 LCD in 8bit */
	LCD_Command (0x0C);
	_delay_ms(2);	/* Display ON Cursor OFF */
	LCD_Command (0x06);
	_delay_ms(2);	/* Auto Increment cursor */
	LCD_Command (0x01);
	_delay_ms(2);	/* clear display */
	LCD_Command (0x80);
	_delay_ms(2);
}

void LCD_Char (unsigned char char_data)	/* LCD data write function */
{
	LCD_Data_Port= char_data;
	LCD_Command_Port |= (1<<RS);	/* RS=1 Data reg. */
	LCD_Command_Port &= ~(1<<RW);	/* RW=0 write operation */
	LCD_Command_Port |= (1<<EN);	/* Enable Pulse */
     _delay_us(1);
	LCD_Command_Port &= ~(1<<EN);
	_delay_ms(1);
}
void LCD_String (char *str)		/* Send string to LCD function */
{
	int i;
	for(i=0;str[i]!=0;i++)		/* Send each char of string till the NULL */
	{
		LCD_Char (str[i]);
	}
}
void LCD_Clear()
{
	LCD_Command (0x01);		/* clear display */
	LCD_Command (0x80);		/* cursor at home position */
}


int main(void){
DDRA=0xff;
PORTA=0xff;
_delay_ms(1000);
DDRB=DDRB | (1<<2) |(1<<0);
PORTB=PORTB & 0b11111110;
DDRB=DDRB | (1<<1);
SPCR= SPCR | (1<<SPE) | (1<<MSTR) | (1<<SPR0);
LCD_Init();
LCD_Clear();	
char Queue[5];
for(int i=0; i<5; i++){
	Queue[i]='0';
}
DDRF=0X00;
for(int i=0; i<5; i++){
	PORTA=0xff;
	_delay_ms(5000);
	PORTA=0x00;
	if(PINF==0b00000000){
		Queue[i]='1';
		LCD_String("1");
		_delay_ms(10);
		
	}
    else if(PINF==0B10000000){
		Queue[i]='2';
		LCD_String("2");
		_delay_ms(10);
}
    else if(PINF==0b11000000){
	    Queue[i]='3';
		LCD_String("3");
	}
     else {
 		Queue[i]='4';
 		LCD_String("4");
		_delay_ms(10);
 	}
}
while(1){
	for(int i=0; i<5; i++){
		SPDR=Queue[i];
		while (!(SPSR & (1<<SPIF)));
		_delay_ms(100);
	}
	SPDR=' ';
	while (!(SPSR & (1<<SPIF)));
	_delay_ms(100);
}

return 0;
}
		

