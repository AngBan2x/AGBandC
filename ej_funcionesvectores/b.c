//ejercicio b de los ejercicios de funciones y vectores
//paso de funciones como parametros

#include <stdio.h>

void aplicarFuncion(int(*funcion)(int), int num);

int cuadrado(int x);
int cubo(int x);

void main(){
    int num = 5;

    printf("Aplicando la funci%cn cuadrado a %d: ", 162, num);
    aplicarFuncion(cuadrado, num);

    printf("Aplicando la funci%cn cubo a %d: ", 162, num);
    aplicarFuncion(cubo, num);
}

void aplicarFuncion(int (*funcion)(int), int num){
    int resultado = funcion(num);
    printf("%d\n", resultado);
}

int cuadrado(int x){
    return x*x;
}

int cubo(int x){
    return x*x*x;
}