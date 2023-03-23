/*Escribir en leguaje C un programa que:
1) Pida por teclado una cantidad (dato entero) en dolares
2) Calcule su equivalente en euros
3) Muestre por pantalla el resultado (dato real)*/

#include<stdio.h>
void main(){
    int dolares;
    float euros;
    printf("CONVERSOR DE DOLARES A EUROS \n \nInserte una cantidad en dolares: ");
    scanf("%i", &dolares);
    euros = dolares / 166.386;
    printf("\n%i dolares son equivalentes a %.2f euros \n", dolares, euros);
}