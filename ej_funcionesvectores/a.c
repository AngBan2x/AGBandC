//ejercicio a de los ejercicios de funciones y vectores

#include <stdio.h>

void sumar(int *vector, int tam); //funcion que le suma 10, tam veces a los elementos de un vector

void main(){
    int numeros[]={1,2,3,4,5};
    int tam = sizeof(numeros)/sizeof(int); 
    /*sizeof(numeros) = 5, sizeof(int) = 4
    5/4 =  1,25 (como la operacion es entre enteros, el resultado que da es 1)*/

    printf("Antes de la suma: ");
    for (int i = 0; i < tam; i++){
        if(i == (tam-1)) printf("%d", numeros[i]);
        else printf("%d, ", numeros[i]);
    }

    sumar(numeros, tam); //esto le suma 10 a cada elemento del vector. Ya que tam = 1, el bucle itera una sola vez

    printf("\nDespu%cs de la suma: ", 130);
    for(int i=0; i<tam; i++){
        if(i == (tam-1)) printf("%d", numeros[i]);
        else printf("%d, ", numeros[i]);
    } 
}

void sumar(int *vector, int tam){
    for(int i=0; i<tam; i++){
        *(vector+i)+=10;
    }
}