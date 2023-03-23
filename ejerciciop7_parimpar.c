/*Escribir en lenguaje C un programa que:
1)Pida por teclado un numero (dato entero)
2)Muestre por pantalla:
    * "ES PAR", en el caso de que el numero sea divisible entre 2
    * "ES IMPAR", en caso de que no lo sea*/
#include <stdio.h>
void main(){
    int numero;
    
    printf("ES PAR O IMPAR? \n \nInserte un numero entero cualquiera: ");
    scanf("%d", &numero);
    
    if ((numero % 2) == 0)
    {
        printf("%d es un numero par", numero);
    }
    else
    {
        printf("%d es un numero impar", numero);
    }
    
}