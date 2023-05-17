//este programa suma dos matrices cuadradas de cualquier dimension

#include <stdio.h>

int dim; //dimensiones de las matrices
void llenarmatriz(float matriz[][dim]);
void impmat(float mat[][dim]);
void summat(float m1[][dim], float m2[][dim],float res[][dim]);

void main(){
    printf("Inserte la dimension para las dos matrices:");
    scanf("%d", &dim);

    float mat1[dim][dim];
    float mat2[dim][dim];
    float matr[dim][dim]; //matriz auxiliar que sera la resultante de la suma

    //llenado de las matrices
    llenarmatriz(mat1);
    printf("La primera matriz es: \n\n");
    impmat(mat1);
    printf("\n");

    llenarmatriz(mat2);
    printf("\nLa segunda matriz es: \n\n");
    impmat(mat2);

    //ahora, la suma de las dos matrices

    summat(mat1, mat2, matr);
    printf("\nLa matriz resultante es: \n\n");
    impmat(matr);
}

void summat(float m1[][dim],float m2[][dim], float res[][dim]){
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            res[i][j] = (m1[i][j]) + (m2[i][j]);
        }
    }
}

void impmat(float mat[][dim]){
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            printf("%g\t", mat[i][j]);
        }
        printf("\n");
    }
}

void llenarmatriz(float matriz[][dim]){
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            printf("Inserte el numero para la fila %d, columna %d: ", i+1, j+1);
            scanf("%f", &(matriz[i][j]));
        }
    }
}
