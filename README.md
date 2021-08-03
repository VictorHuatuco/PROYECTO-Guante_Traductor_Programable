# GUANTE TRADUCTOR DE LENGUAJE DE SEÑAS PROGRAMABLE 

Este proyecto consiste en un guante acondicionado con sensores que son capaces de leer la posición de los dedos. El objetivo es que al hacer una seña del lenguaje de señas con la mano, estqa se pueda traducir a su letra correspondiente que se mostrará en un LCD. La particularidad de este proyecto frente a parecidos es que tiene la capacidad de ser programable para que cualquier usuario pueda personalizar cada posición de las señas como guste. 

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

Al ingresar en está opción se verá como primera letra la "A". Abajo de esta se ve los valores de los sensores.
Con la opción "SIG" puede navegar entre las letras sin guardar los valores del sensor..

![img](https://github.com/VictorHuatuco/images/blob/master/Programar2.png)

Si desea guardar los valores en la memoria del microcontrolador, haga la posición se seña de la letra deseada y seleccione la opción "OK".

![img](https://github.com/VictorHuatuco/images/blob/master/Programar1.png)

Por último seleccione la opción salir y entre a la opción traducir para seguir traduciendo letras. Además, si desea puede apagarlo y al volver a prenderlo todas las configuraciones programada quedarán guardadas.

Posibles mejoras: La letra "J" y "Z" necesitan un sensor acelerómetro para poder se traducida.

Anexo:

Lenguaje de señas:

![img](https://github.com/VictorHuatuco/images/blob/master/sign-language-hands.jpg)




