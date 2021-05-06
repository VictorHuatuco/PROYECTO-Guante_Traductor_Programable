# GUANTE TRADUCTOR DE LENGUAJE DE SEÑAS PROGRAMABLE 

La idea de este proyecto nació a partir de proyectos parecidos en internet y por mi iniciativa de quere hacer uno a mi estilo y mejorarlo para que tenga la capacidad de que ser programable para que cualquier usuario pueda personalizar la traducción de cada letra como deseé. 

### Materiales:
#### ►PIC18F4550
#### ►LCD 16x2
#### ►5 sensores flex
#### ►3 Botones
#### ►Opamp's
#### ►Resistencias y condensadores.

## Simulación de uso:

Circuito esquemático en Proteus 8.9:
![img](https://github.com/VictorHuatuco/images/blob/master/Esquem%C3%A1tico.png)
Nota: Los potenciometros simulan sensor flex que se acomodan a cada dedo.

### Menú de inicio:
![img](https://github.com/VictorHuatuco/images/blob/master/Menu1.png)

Nota:Con los botones 1 y 2 se mueve el selector y con el botón 3 seleccionas la opción.

### Opción "Traducir":
Al ingresar a la opción traducir empezará a traducir letra por letra según el cumplimiento de la condición de la posición de los sensores para que se forme una letra al hacer una seña.
![img](https://github.com/VictorHuatuco/images/blob/master/Traducir1.png)


Al seleccionar "Sig.Le." se mueve a la posición de la segunda columna del LCD
![img](https://github.com/VictorHuatuco/images/blob/master/Traducir2.png)


Así entonces puede formar una palabra:
![img](https://github.com/VictorHuatuco/images/blob/master/Traducir3.png)


### Opción "Programar":

Al ingresar en está opción se verá como primer letra la "A". Abajo de esta se ve los valores de los sensores.
Con la opción "SIG" puede navegar entre las letras sin guardar los valores del sensor..

![img](https://github.com/VictorHuatuco/images/blob/master/Programar2.png)

Si desea guardar los valores en la memoria del microcontrolador, haga la posición se seña de la letra deseada y seleccione la opción "OK".

![img](https://github.com/VictorHuatuco/images/blob/master/Programar1.png)






