//ejercicio del apartado de cadenas, de los ejercicios de funciones y vectores
//este programa lee una linea de texto desde la entrada estandar y la imprime en la salida estandar

#include <stdio.h>

int main(){
    char cadena[100];

    printf("Ingresa una cadena: ");
    fgets(cadena, 100, stdin);

    printf("La cadena ingresada es: %s\n", cadena);

    return 0;
}