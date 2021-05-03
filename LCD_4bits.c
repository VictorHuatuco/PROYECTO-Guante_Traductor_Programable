#include <xc.h>
#include "LCD_4bits.h"
#include "Configuracion.h"

void LCD_Init(void){
    TRISD = 0x00; //PUERTO D SALIDA
    //__delay_ms(100);
    LCD_Comando(0x30);
    //__delay_ms(5);
    LCD_Comando(0x30);
    //__delay_us(100);
    LCD_Comando(0x32);// 4 bits
    LCD_Comando(0x28);
    LCD_Comando(0x0C);
    LCD_Comando(LCD_Borrar);
    LCD_Comando(0x06);
}

void LCD_Comando(char cmd){
    //cmd = 0X30
    LCD_PORT = LCD_PORT & 0x0F;
    /*
     * PORTD = 0XF3 AND    1111 0011
     *         0X0F        0000 1111
     *         0X03        0000 0011
     */
    LCD_PORT = LCD_PORT | (cmd & 0xF0);
    /*
     * cmd = 0011 0000 AND
     *     = 1111 0000
     *     = 0011 0000
     * 
     * LCD_PORT | cmd
     *  0x03    |   0x30 = 0x33
     */
    RS = 0; // MODO COMANDO
    __delay_ms(1);
    E = 1;
    __delay_ms(1);
    E = 0;
    
    LCD_PORT &= 0x0F;
    /*
     * PORTD = 0XF3 AND    1111 0011
     *         0X0F        0000 1111
     *         0X03        0000 0011
     */
    LCD_PORT |= ((cmd<<4) & 0xF0);
    /*
     * cmd = 0010 0000<<4
     *     = 1111 0000 and
     *     = 0010 0000
     * 
     * LCD_PORT | cmd
     *  0x03    |   0x20 = 0x23
     */
    RS = 0; // MODO COMANDO
    __delay_ms(1);
    E = 1;
    __delay_ms(1);
    E = 0;
    
    LCD_PORT &= 0x0F;
}

void LCD_Caracter(char data){
    //cmd = 0X30
    LCD_PORT &= 0x0F;

    LCD_PORT |= (data & 0xF0);
  
    RS = 1; // MODO CARACTER
    __delay_ms(1);
    E = 1;
    __delay_ms(1);
    E = 0;
    
    LCD_PORT &= 0x0F;

    LCD_PORT |= ((data<<4) & 0xF0);

    RS = 1; // MODO CARACTER
    __delay_ms(1);
    E = 1;
    __delay_ms(1);
    E = 0;
    
    LCD_PORT &= 0x0F;
}

void LCD_XY(int x, int y){
    if(x>0){
        LCD_Comando(0xC0+y);
    }
    else{
        LCD_Comando(0x80+y);
    }
}

void LCD_Cadena(char *dat){
    while(*dat != '\0'){
        LCD_Caracter(*dat);
        dat++;
    }

}