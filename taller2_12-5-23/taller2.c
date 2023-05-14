#include <stdio.h>
#include <stdlib.h>
#define max 1000

typedef int vec_n[3];

struct estudiante {
    char nombre[100];
    vec_n notas;
}est;

struct estudiante v_est[max];
float v_prom[5];

void llenar_a_mat(int matriz[][3]);
void promedio(int matriz[][3]);
void guardar_resultados(int matriz[][3]);
int matriz[3][3];

int main(){

    llenar_a_mat(matriz);
    promedio(matriz);
    guardar_resultados(matriz);

    return 0;
}

void llenar_a_mat(int mat[][3]){
    FILE *pf; //puntero pal archivo
    pf = fopen("notas_alumnos.txt", "r");
    int i=0;
    
    while(!feof(pf)) { //llenar a la matriz
        fscanf(pf, "%s" "%d" "%d" "%d", v_est[i].nombre, &v_est[i].notas[0], &v_est[i].notas[1], &v_est[i].notas[2]);
        i++;
    }

    for(int i=0; i<5; i++){
        for(int j=0; j<3;j++){
            mat[i][j] = v_est[i].notas[j];
        } 
    }
    for(int i=0; i<5; i++){ //imprimir la matriz
        printf("%s: ", v_est[i].nombre);
        for(int j=0; j<3; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    fclose(pf);
}

void promedio(int matriz[][3]){
    for(int i=0; i<5; i++){
        int acum=0;
        float prom=0;
        
        for (int j = 0; j < 3; j++){
            acum += matriz[i][j];
        }
        prom = acum / 3;
        v_prom[i] = prom;
        printf("El promedio de %s es: %g\n", v_est[i].nombre, prom);
    }
}

void guardar_resultados(int matriz[][3]){
    FILE *pf;
    pf = fopen("resultados.txt", "w");

    for(int i =0 ; i<5; i++){
        if(!feof(pf)){
            fprintf(pf, "%s: %g\n", v_est[i].nombre, v_prom[i]);
        }
    }
    fclose(pf);
}