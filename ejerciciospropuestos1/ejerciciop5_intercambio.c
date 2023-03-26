/*Escribir en lenguaje C un programa que:
1) Pida por teclado dos números (datos enteros) y sean
almacenados en dos variables, llamadas v1 y v2
2) Intercambie los valores de las variables
3) Muestre por pantalla los valores contenidos en las
variables*/

#include <stdio.h>
void main (){
    int v1, v2;
    printf("INTERCAMBIO DE DOS VARIABLES \n \n");
    printf("Inserte un numero para la primera variable> \n");
    scanf("%i", &v1);
    printf("Inserte un numero para la segunda variable: \n");
    scanf("%i", &v2);
    v1 = v1 + v2;
    v2 = v1 - v2;
    v1 = v1 - v2;
    printf("Ahora la variable 1 vale %i y la variable 2 vale %i", v1, v2);

}