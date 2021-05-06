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


#define BOTON1 PORTBbits.RB0
#define BOTON2 PORTBbits.RB1
#define BOTON3 PORTBbits.RB2

//Variables
int p1[4];//Variables temporales de lo leido por el ADC
int p2[4];//Lectura del ADC para la traduccion
int dedos[4];//Selector que se mueve entre opciones

unsigned int selector = 1;//Selector que se mueve entre opciones
int i = 0,z = 0, n = 0, q = 0,w=0,j=0,k=0,c=0,h=0;//Variables de bucles for
int letras[26][5]; //Jala los valores guardados en la memoria EEPROM
char letra_sola[27];//Guarda las letras del abecedario
int texto[16];//16 es por que el LCD es 16x2


void main(void) {
   TRISBbits.RB0 = 1;//Defino como entrada el boton 1
   TRISBbits.RB1 = 1;//Defino como entrada el boton 2
   TRISBbits.RB2 = 1;//Defino como entrada el boton 3
   TRISAbits.RA0 = 1;//Defino como entrada el pulgar
   TRISAbits.RA1 = 1;//Defino como entrada el indice
   TRISAbits.RA2 = 1;//Defino como entrada el medio
   TRISAbits.RA3 = 1;//Defino como entrada el anular
   TRISAbits.RA5 = 1;//Defino como entrada el menique
   ADC_init();//Inicializar ADC
   LCD_Init();//Inicializar LCD
   //Asignación de letras
   letra_sola[0]='A';letra_sola[1]='B';letra_sola[2]='C';letra_sola[3]='D';letra_sola[4]='E';
   letra_sola[5]='F';letra_sola[6]='G';letra_sola[7]='H';letra_sola[8]='I';letra_sola[9]='J';
   letra_sola[10]='K';letra_sola[11]='L';letra_sola[12]='M';letra_sola[13]='N';letra_sola[14]='O';
   letra_sola[15]='P';letra_sola[16]='Q';letra_sola[17]='R';letra_sola[18]='S';letra_sola[19]='T';
   letra_sola[20]='U';letra_sola[21]='V';letra_sola[22]='W';letra_sola[23]='X';letra_sola[24]='Y';letra_sola[25]='Z';
    //Inicar menu
   LCD_XY(0,0);
   LCD_Cadena("Traducir <="); 
   LCD_XY(1,0);
   LCD_Cadena("Programar"); 
   __delay_ms(50);
    while(1){
  
    

        if((BOTON1 == 1) && (BOTON2 == 0)){ //Mover a opción Traducir
            selector = selector - 1;
            
            LCD_Comando(0x01);
            LCD_XY(0,0);
            LCD_Cadena("Traducir <="); 
            LCD_XY(1,0);
            LCD_Cadena("Programar");
            if(selector <= 1){
                selector = 1;
            } else {}

        } else {
            if((BOTON1 == 0) && (BOTON2 == 1)){//Mover a opción Programar
                selector = selector + 1;
                LCD_Comando(0x01);
                LCD_XY(0,0);
                LCD_Cadena("Traducir"); 
                LCD_XY(1,0);
                LCD_Cadena("Programar <=");
                if (selector >= 2){
                    selector = 2;
                } else {}
              
            }
        }
 //----------------------------------------------------------
    if (BOTON3 == 1){
        __delay_ms(500);
         //----------------------------------------------------------
        if ( selector == 1){//Selección de opción Traducción
            LCD_XY(1,0);
            LCD_Cadena("Traduciendo");
            __delay_ms(100);
            LCD_Comando(0x01);
            LCD_XY(0,0);
            LCD_Cadena("----------------");
            LCD_XY(1,0);
            LCD_Cadena("Sig.Le.<=");
            LCD_XY(1,9);
            LCD_Cadena("SALIR");
            for(q=0;q<=10;q++){// Lee lo almacenado en la EEPROM y lo garda en paquete de 16 bits
                for(w=0;w<=8;w+=2){
                letras[q][w/2] = EEPROM_Lectura_int16(10*q+w);
                }
            }
            h=0;//Varibale que moverá la posición en el LCD
            
            for (z = 0; z <= 1;){//Bucle de opción Traducir 
                for (j = 0; j <=4; j++){
                  dedos[j] = ADC_read(j);
                }
                for (k = 0;k<= 26; k++){//Traducción de letras mediante verificación del rangos
                    
                    if (letras[k][0]-20<=dedos[0] && dedos[0]<=letras[k][0]+20 &&
                        letras[k][1]-20<=dedos[1] && dedos[1]<=letras[k][1]+20 &&
                        letras[k][2]-20<=dedos[2] && dedos[2]<=letras[k][2]+20 &&
                        letras[k][3]-20<=dedos[3] && dedos[3]<=letras[k][3]+20 &&
                        letras[k][4]-20<=dedos[4] && dedos[4]<=letras[k][4]+20){
                    LCD_XY(0,h);
                    LCD_Data(letra_sola[k]);    //Muestra en el LCD la letra traducida   
                    }
                }
                 if((BOTON1 == 1) && (BOTON2 == 0)){//Mover a opción Programar Sig.Le.
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
                    if((BOTON1 == 0) && (BOTON2 == 1)){//Mover a opción SALIR
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
               if ( BOTON3 == 1 && selector == 1){//Mueve la posición del LCD para formar traducir la siguiente letra
                     h = h + 1 ;
                    __delay_ms(300);
                    }
               if ( BOTON3 == 1 && selector == 2){//Sale de la opción Traducir y vuelve al menu principal
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
        __delay_ms(200);
         //----------------------------------------------------------
        if ( selector == 2){//Selección de opción Programar
            n=0;
            LCD_Comando(0x01);
            LCD_XY(0,0);
            LCD_Data(letra_sola[n]);
            LCD_XY(0,4);
            LCD_Cadena("OK<=");
            LCD_XY(0,9);
            LCD_Cadena("SALIR");
            selector = 1;
            for (z = 0; z <= 1;){//Bucle de opción Programar
                
                 if((BOTON1 == 1) && (BOTON2 == 0)){//Mover a opción OK
                    selector = selector - 1;
                    if(selector <= 1){
                        selector = 1;
                    } }
                if((BOTON1 == 0) && (BOTON2 == 1)){//Mover a opción SALIR
                        selector = selector + 1;
                        if (selector >= 3){
                            selector = 3;
                        }}
                switch (selector){
                    case 1: 
                        LCD_XY(0,8);
                        LCD_Cadena("  ");
                        LCD_XY(0,2);
                        LCD_Cadena("OK<");
                        LCD_XY(0,5);
                        LCD_Cadena("SIG");
                        LCD_XY(0,9);
                        LCD_Cadena("SALIR");
                        __delay_ms(100);
                        break;
                    case 2: 
                        LCD_XY(0,4);
                        LCD_Cadena("  ");
                        LCD_XY(0,14);
                        LCD_Cadena("  ");
                        LCD_XY(0,2);
                        LCD_Cadena("OK");
                        LCD_XY(0,5);
                        LCD_Cadena("SIG<");
                        LCD_XY(0,9);
                        LCD_Cadena("SALIR");
                        __delay_ms(100);
                        break;
                    case 3:
                        LCD_XY(0,8);
                        LCD_Cadena("  ");
                        LCD_XY(0,2);
                        LCD_Cadena("OK");
                        LCD_XY(0,5);
                        LCD_Cadena("SIG");
                        LCD_XY(0,9);
                        LCD_Cadena("SALIR<");
                        __delay_ms(100);
                        break;
                }
                
//                
                
                for (j = 0; j <=4; j++){//Lectura de los ADC's
                  dedos[j] = ADC_read(j);
                  p1[j] = dedos[j]/10;
                }
                LCD_XY(0,0);
                
                LCD_Data(letra_sola[n]);//Imprime la letra a programar
                
                    LCD_XY(0,0);
                    LCD_Data(letra_sola[n]);
                    sprintf(texto,"%u-%u-%u-%u-%u",p1[0],p1[1],p1[2],p1[3],p1[4]);//Convierte a string los valores del ADC
                    LCD_XY(1,0);
                    LCD_Cadena(texto);//Imprime los valores del ADC entre 10
                
                __delay_ms(80);
            if (selector == 3 & BOTON3 == 1){//Selecciona la opción Salir y vuelve al menu principal
                    LCD_Comando(0x01);
                    LCD_XY(0,0);
                    LCD_Cadena("Traducir <="); 
                    LCD_XY(1,0);
                    LCD_Cadena("Programar"); 
                    __delay_ms(100);
                    z=2;
                    selector = 1;
                                   }
            if (selector == 1 & BOTON3 == 1){//Selecciona la opción OK y almacena los valores de los sensores en la memoria EEPROM
                
                    for (j = 0; j <=8; j+=2){EEPROM_Guardar_int16(10*n+j,dedos[j/2]);}
//                       
                    n=n+1;
                    selector = 1;
                    __delay_ms(500);}
            if (selector == 2 & BOTON3 == 1){//Selecciona la opción OK y almacena los valores de los sensores en la memoria EEPROM
                    selector = 2;    
                    n = n + 1;
                    __delay_ms(200);}    
                
                
            }

            }
        }
   
    } 

    
    return;
}
