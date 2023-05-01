//ejercicio de archivos.pdf

#include <stdio.h>

struct CLIENTE{
    char nombre[30];
    char apellido[30];
    unsigned int cedula;
    char direccion[100];
}cli;

int registro_clientes(FILE *pf);

int main(){
    FILE *pf;
    int c;
    pf = fopen("clientes.txt", "a");
    //archivo abierto en modo "a" para poder añadir más de un cliente
    
    if(pf==NULL){
        printf("Error al abrir el fichero.\n");
        return -1;
    }
    else{
        printf("Fichero abierto correctamente.\n");
        c = registro_clientes(pf);
        if (c>0) printf("Registro guardado con exito!\n");
        fclose(pf);
        return 0;
    }
}

int registro_clientes(FILE *pf){
    printf("Ingrese el nombre del cliente: \n");
    scanf("%s", cli.nombre);

    printf("Ingrese el apellido del cliente: \n");
    scanf("%s", cli.apellido);

    fprintf(pf, "%s\t\t%s\n", cli.nombre, cli.apellido);
    return 1;
}