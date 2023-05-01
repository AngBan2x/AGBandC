//ejercicio c de los ejercicios de funciones y vectores
//uso de vectores dinamicos

#include <stdio.h>
#include <stdlib.h>

int main(){
    int *vector;
    int tam;

    printf("Introduce el tama%co del vector: ", 164);
    scanf("%d", &tam);

    vector = (int *) malloc(tam * sizeof(int));
    /*  1) (int *) convierte el valor del dato a "int *"
        2) malloc le asigna dinamicamente al vector el valor de tam * sizeof(int), en bytes
        3) se multiplica tam * sizeof(int) para darle el espacio de memoria de int a cada elemento del vector
        4) el valor de sizeof se evalua como constante en tiempo de ejecucion. Su valor no puede ser cambiado*/

    //validar si se le ha podido asignar a la memoria al vector correctamente
    if(vector == NULL){
        printf("Error: no se ha podido asignar a la memoria.\n");
        return 1;
    }

    printf("Introduce los elementos del vector: \n");
    for(int i=0; i<tam; i++){
        printf("Inserte el elemento %d: ", i+1);
        scanf("%d", &vector[i]);
    }

    printf("El vector es:\n");
    for(int i = 0; i < tam; i++){
        if(i == (tam-1)) printf("%d\n", vector[i]);
        else printf("%d, ", vector[i]);
    }

    free(vector); //libera la memoria asignada al vector

    return 0;
}