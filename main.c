/*
 * LCD.c
 *
 * Created: 29-03-2024 22:02:27
 * Author : Dev Arora
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>	
#define RS PG2
#define RW PG1
#define EN PG0
#define LCD_Data_Dir DDRC		/* Define LCD data port direction */
#define LCD_Command_Dir DDRG		/* Define LCD command port direction register */
#define LCD_Data_Port PORTC		/* Define LCD data port */
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
	DDRA=0xff;
	_delay_ms(30);
	LCD_Command (0x38);	
	_delay_ms(2);/* Initialization of 16X2 LCD in 8bit mode */
	LCD_Command (0x0C);
	_delay_ms(2);	/* Display ON Cursor OFF */
	LCD_Command (0x06);
	_delay_ms(2);	/* Auto Increment cursor */
	LCD_Command (0x01);
	_delay_ms(2);	/* clear display */
	LCD_Command (0x80);
	_delay_ms(2);
	PORTA=0xff;
	_delay_ms(1000);
	PORTA=0x00;
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
	LCD_Init();
	LCD_Clear();
	LCD_String("GOODNIGHT");
	LCD_Command(0xC0);
	LCD_String("");
	
	return 0;
	
}

