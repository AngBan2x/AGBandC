/*Escribir en lenguaje C un programa que:
1) Pida por teclado una hora en horas, minutos y segundos
(datos enteros)
2) Calcule cuantos segundos han pasado desde las 0:0:0 horas
3) Muestre por pantalla los resultados (datos reales)*/

#include <stdio.h>
#include <stdlib.h>

void main() {
    int hour, min, sec;
    printf("CUANTAS HORAS MINUTOS Y SEGUNDOS HAN PASADO \n \n");
    printf("Inserte una cantidad en horas: \n");
    scanf("%i", &hour);
    printf("Inserte una cantidad en minutos: \n");
    scanf("%i", &min);
    printf("Inserte una cantidad en segundos \n");
    scanf("%i", &sec);

    sec = sec + min * 60 + hour * 3600;
    printf("Han pasado %i segundos desde las 0:0:0 horas", sec);
}