// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef LCD_4BITS_H
#define	LCD_4BITS_H

#include <xc.h> // include processor files - each processor file is guarded.  

void LCD_Init(void);
void LCD_Comando(char cmd);
void LCD_Caracter(char data);
void LCD_XY(int x, int y);
void LCD_Cadena(char *dat);

#define LCD_PORT LATD
#define RS       LATDbits.LATD2
#define E        LATDbits.LATD3

#define LCD_Borrar 0x01

#endif	/* XC_HEADER_TEMPLATE_H */