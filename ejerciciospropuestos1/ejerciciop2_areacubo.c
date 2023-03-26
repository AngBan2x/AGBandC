/*Escribir en lenguaje C un programa que:
1) Pida por teclado la arista (dato real) de un cubo
2) Calcule el volumen del cubo
3) Muestre por pantalla el resultado (dato real)*/

#include <stdio.h>
#include <math.h>

void main() {
    float arista, area;
    printf("CALCULADORA DEL AREA DE UN CUBO \n");
    
    printf("Inserte la longitud de la arista: \n");
    scanf("%f", &arista);

    area = arista * arista * arista; //calcular el area del cubo

    printf("El area del cubo es %f", area);
}