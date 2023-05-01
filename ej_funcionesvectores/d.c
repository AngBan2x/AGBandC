//ejercicio d de los ejercicios de funciones y vectores
//matrices

#include <stdio.h>

int main(){
    //Definir las matrices a sumar y la matriz resultante
    int matriz1[2][2] = {{1,2},{3,4}};
    int matriz2[2][2] = {{5,6},{7,8}};
    int matrizResultado[2][2];

    //Verificar que las dimensiones de las matrices sean iguales
    if(sizeof(matriz1)!=sizeof(matriz2)){
        printf("Error: Las matrices deben tener la misma dimensi%cn.\n", 162);
        return 1;
    }

    //Recorrer ambas matrices y sumar los elementos correspondientes
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            matrizResultado[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }

    //Imprimir la matriz resultante
    printf("La matriz resultante es: \n");
    for(int i=0; i<2; i++){
        for(int j=  0; j<2; j++){
            printf("%d\t", matrizResultado[i][j]);
        }
        printf("\n");
    }
    return 0;
}