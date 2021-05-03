/*
 * File:   Programa_Principal.c
 * Author: Victor Huatuco
 *
 * Created on 16 de febrero de 2021, 03:34 PM
 */


#include <xc.h>
#include <stdio.h>
#include <stdint.h>
#include "Configuracion.h"
#include "ADC_Libreria.h"
#include "LCD_Libreria.h"
#include "EEPROM_Libreria.h"
#include "menu_seleccion.h"


#define BOTON1 PORTBbits.RB0
#define BOTON2 PORTBbits.RB1
#define BOTON3 PORTBbits.RB2
int p1[4];
int p2[4];
int dedos[4];
int let[3];
unsigned int selector = 1;
int i = 0,z = 0, n = 0, q = 0,w=0,j=0,k=0,c=0,h=0;
int letras[26][5];
char letra_sola[27];
int texto[16];
int ab[3];

void main(void) {
   TRISBbits.RB0 = 1;
   TRISBbits.RB1 = 1;
   TRISBbits.RB2 = 1;
   TRISAbits.RA0 = 1;
   TRISAbits.RA1 = 1;
   TRISAbits.RA2 = 1;
   TRISAbits.RA3 = 1;
   TRISAbits.RA5 = 1;
   ADC_init();
   LCD_Init();
   letra_sola[0]='A';letra_sola[1]='B';letra_sola[2]='C';letra_sola[3]='D';letra_sola[4]='E';
   letra_sola[5]='A';letra_sola[6]='B';letra_sola[7]='C';letra_sola[8]='D';letra_sola[9]='E';
   letra_sola[10]='A';letra_sola[11]='B';letra_sola[12]='C';letra_sola[13]='D';letra_sola[14]='E';
   LCD_XY(0,0);
   LCD_Cadena("Traducir <="); 
   LCD_XY(1,0);
   LCD_Cadena("Programar"); 
   __delay_ms(50);
    while(1){
  
    //LCD_Comando(0x01); //Clear LCD

        if((BOTON1 == 1) && (BOTON2 == 0)){
            selector = selector - 1;
            
            LCD_Comando(0x01);
            LCD_XY(0,0);
            LCD_Cadena("Traducir <="); 
            LCD_XY(1,0);
            LCD_Cadena("Programar");
            if(selector <= 1){
                selector = 1;
            } else {}
//            seleccion(selector,"Traducir",0,0,"Programar",1,0);
        } else {
            if((BOTON1 == 0) && (BOTON2 == 1)){
                selector = selector + 1;
                LCD_Comando(0x01);
                LCD_XY(0,0);
                LCD_Cadena("Traducir"); 
                LCD_XY(1,0);
                LCD_Cadena("Programar <=");
                if (selector >= 2){
                    selector = 2;
                } else {}
                //seleccion(selector,"Traducir",0,0,"Programar",1,0);
            }
        }
 //----------------------------------------------------------
    if (BOTON3 == 1){
        __delay_ms(500);
         //----------------------------------------------------------
        if ( selector == 1){
            LCD_XY(1,0);
            LCD_Cadena("Traduciendo");
            __delay_ms(1000);
            LCD_Comando(0x01);
            LCD_XY(0,0);
            LCD_Cadena("----------------");
            LCD_XY(1,0);
            LCD_Cadena("Sig.Le.<=");
            LCD_XY(1,9);
            LCD_Cadena("SALIR");
            for(q=0;q<=10;q++){
                for(w=0;w<=8;w+=2){
                letras[q][w/2] = EEPROM_Lectura_int16(10*q+w);
                }
            }
            h=0;
            
            for (z = 0; z <= 1;){
                for (j = 0; j <=4; j++){
                  dedos[j] = ADC_read(j);
                }
                for (k = 0;k<= 26; k++){
                    
                    if (letras[k][0]-20<=dedos[0] && dedos[0]<=letras[k][0]+20 &&
                        letras[k][1]-20<=dedos[1] && dedos[1]<=letras[k][1]+20 &&
                        letras[k][2]-20<=dedos[2] && dedos[2]<=letras[k][2]+20 &&
                        letras[k][3]-20<=dedos[3] && dedos[3]<=letras[k][3]+20 &&
                        letras[k][4]-20<=dedos[4] && dedos[4]<=letras[k][4]+20){
                    LCD_XY(0,h);
                    LCD_Data(letra_sola[k]);    
                    }
                }
                 if((BOTON1 == 1) && (BOTON2 == 0)){
                    selector = selector - 1;
                    LCD_XY(1,14);
                    LCD_Cadena("  ");
                    LCD_XY(1,0);
                    LCD_Cadena("Sig.Le.<=");
                    LCD_XY(1,9);
                    LCD_Cadena("SALIR");
                    if(selector <= 1){
                        selector = 1;
                    } else {}
                } else {}
                    if((BOTON1 == 0) && (BOTON2 == 1)){
                        selector = selector + 1;
                        LCD_XY(1,7);
                        LCD_Cadena("  ");
                        LCD_XY(1,0);
                        LCD_Cadena("Sig.Le.");
                        LCD_XY(1,9);
                        LCD_Cadena("SALIR<=");
                        if (selector >= 2){
                            selector = 2;
                        } else {}
                    }
               if ( BOTON3 == 1 && selector == 1){
                     h = h + 1 ;
                    __delay_ms(300);
                    }
               if ( BOTON3 == 1 && selector == 2){
                     LCD_Comando(0x01);
                    LCD_XY(0,0);
                    LCD_Cadena("Traducir <="); 
                    LCD_XY(1,0);
                    LCD_Cadena("Programar"); 
                    __delay_ms(100);
                    z=2;
                    selector = 1;}
            }
        }
        __delay_ms(500);
         //----------------------------------------------------------
        if ( selector == 2){
            n=0;
            LCD_Comando(0x01);
            LCD_XY(0,0);
            LCD_Data(letra_sola[n]);
            LCD_XY(0,4);
            LCD_Cadena("OK<=");
            LCD_XY(0,9);
            LCD_Cadena("SALIR");
            selector = 1;
            for (z = 0; z <= 1;){
                
                if((BOTON1 == 1) && (BOTON2 == 0)){
                    selector = selector - 1;
                    LCD_XY(0,14);
                    LCD_Cadena("  ");
                    LCD_XY(0,4);
                    LCD_Cadena("OK<=");
                    LCD_XY(0,9);
                    LCD_Cadena("SALIR");
                    if(selector <= 1){
                        selector = 1;
                    } else {}
                } else {}
                    if((BOTON1 == 0) && (BOTON2 == 1)){
                        selector = selector + 1;
                        LCD_XY(0,6);
                        LCD_Cadena("  ");
                        LCD_XY(0,4);
                        LCD_Cadena("OK");
                        LCD_XY(0,9);
                        LCD_Cadena("SALIR<=");
                        if (selector >= 2){
                            selector = 2;
                        } else {}
                    }
                
//                if (selector == 2){z=1;}
                
//                sprintf(ab,"%u",selector);
//                LCD_XY(1,10);
//                LCD_Cadena(ab);
                
                for (j = 0; j <=4; j++){
                  dedos[j] = ADC_read(j);
                  p1[j] = dedos[j]/10;
                }
                LCD_XY(0,0);
                //sprintf(let,"--%s-",letra_sola[0]);
                LCD_Data(letra_sola[n]);
                //if (*p2 != *p1){
                    //LCD_Comando(0x01);
                    LCD_XY(0,0);
                    LCD_Data(letra_sola[n]);
                    sprintf(texto,"%u-%u-%u-%u-%u",p1[0],p1[1],p1[2],p1[3],p1[4]);
                    LCD_XY(1,0);
                    LCD_Cadena(texto);
                //}
                //*p2 = *p1;
                __delay_ms(80);
            if (selector == 2 & BOTON3 == 1){
                    LCD_Comando(0x01);
                    LCD_XY(0,0);
                    LCD_Cadena("Traducir <="); 
                    LCD_XY(1,0);
                    LCD_Cadena("Programar"); 
                    __delay_ms(100);
                    z=2;
                    selector = 1;
                    __delay_ms(150);                }
            if (selector == 1 & BOTON3 == 1){
                
                    for (j = 0; j <=8; j+=2){EEPROM_Guardar_int16(10*n+j,dedos[j/2]);}
//                        letras[0][1] = EEPROM_Lectura_int16(2);
//                    for(w=0;w<=8;w+=2){
//                    letras[q][w/2] = EEPROM_Lectura_int16(10*q+w);
//                    }
////                      sprintf(texto,"---%u---",letras[0][1])  ;
//                    sprintf(texto,"%u-%u-%u-%u",letras[0][0],letras[0][1],letras[0][2],letras[0][3]);
//                    LCD_XY(1,0);
//                    LCD_Cadena(texto);
//                    __delay_ms(3000);
//                    
                    n=n+1;
                    selector = 1;
                    __delay_ms(150);}
            }

            }
        }
   
    } 

    
    return;
}
