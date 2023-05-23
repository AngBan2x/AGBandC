#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdio_ext.h>
#define tam 1000

//Estructuras
struct fecha {
    int dia,mes,anio;

};

struct CLIENTE {
    char nombre[30];
    char apellido[30];
    char departamento[30];
    char cargo[30];
    unsigned int cedula;
    struct fecha f;
    unsigned int sueldo;
};

//globales
struct CLIENTE vector_archivo[tam];
char vector_departamento[6][30]={"rrhh","consultor","diseno","produccion","calidad","distribucion"};
char vector_cargo[6][30]={"gerente","supervisor","analista","disenador","desarrollador","auditor"};
char vector_motivo[4][30]={"Traslado","Renuncia","Despido","Otro"};
int dim;

//Prototipos de funciones
void leer_datos_archivo(FILE *pf,int *dim);                                       // CON ESTA FUNCION, LEEMOS EL ARCHIVO PRINCIPAL, Y NOS RETORNA CUANTAS LINEAS HAY, ESO SERIA LA DIMENSION. ESTA FUNCION TAMBIEN PASA TODOS LOS DATOS DEL ARCHIVO A UN VECTOR
void mostrar_menu();                                                              // ESTE ES EL TIPICO MENU CON SWITCH
void crear_trabajador(struct CLIENTE vector_archivo[],int* dim);                  // ESTA FUNCION RECIBE COMO PARAMETROS EL VECTOR QUE SE LEYO CON LA FUNCION (LEER LINEAS), Y LA DIMENSION QUE RETORNO DICHA FUNCION TAMBIEN. A PARTIR DE ALLI SE PIDEN DATOS PARA IR AGREANDO AL VECTOR
void filtrar_cedula(struct CLIENTE vector_archivo[],int dim);                     // ESTO ES PARA FILTRAR POR NUMERO DE CEDULA Y ENSE;AR LA INFORMACION
int mostrar_posicion_cedula(struct CLIENTE vector_archivo[],int* dim, int c_i);   // ESTA FUNCION SE USA EN VARIAS FUNCIONES, NOS RETORNA LA POSICION DE UNA CEDULA BUSCADA, YA SEA PARA MODIFICAR, ELIMINAR O MOSTRAR.
void departamento(struct CLIENTE vector_archivo[],int dim);                       // ESTA RECORRE EL VECTOR Y FILTRA POR DEPARTAMENTO
void cargo(struct CLIENTE vector_archivo[],int dim);                              // IGUAL QUE EN DEPARTAMENTO(), PERO FILTRA POR CARGO
void mayor_sueldo(struct CLIENTE vector_archivo[],int dim);                       // MUESTRA EL EMPLEADO CON EL MAYOR SUELDO
void menor_sueldo(struct CLIENTE vector_archivo[],int dim);                       // MUESTRA EL EMPLEADO CON EL MENOR SUELDO
void modificar_trabajador(struct CLIENTE vector_archivo[],int dim);               // BUSCAMOS POR CEDULA POSICION QUE QUEREMNOS MODIFICAR Y SUSTITUIMOS EN ESA POSICION
void eliminar_trabajador(struct CLIENTE vector_archivo[],int* dim);               // IGUAL QUE MODIFICAR, LO QUE VARIA ES QUE, LO QUE SE ELIMINE VA A GUARDARSE EN OTRO ARCHIVO, Y LO TIPO CUANDO ELIMINAMOS, CORREMOS UNA POSICION LOS VALORES Y RESTAMOS UN VALOR A LA DIMENSION
void cargar_datos_archivo(struct CLIENTE vector_archivo[],int dim);               // ESTA ES LA MAS IMPORTANTE, TODO SE HARA EN VECTORES, Y AL FINAL CUANDO TERMINE DE EJECUTARSE EL PROGRAMA, SE DEBE EJECTURAR ESTA YA QUE ES LA QUE MONTA LA DATA AL ARCHIVO, YA CON VALORES ELIMINADO MODIFICADOS AGREGADOS
char siono(char var,char si,char no);						                      // FUNCION SENCILLA QUE SE ENCARGA DE VALIDAR LAS RESPUESTAS A LAS PREGUNTAS DE SI O NO DURANTE EL PROGRAMA
int validar_opcion(int n);                                                        // VALIDA LAS OPCIONES (NUMERICAS) DADAS


//funcion main
int main () {
    FILE *pf;
    leer_datos_archivo((FILE*)"clientes.dat",&dim);
    mostrar_menu();
}

void mostrar_menu() {
    int n,i;
    bool salir;
    salir = true;
    printf("\nBienvenido al sistema de gestion de la empresa FUTURE, C.A.\n");
    do {
        printf("\nMENU PRINCIPAL\nOPCIONES DISPONIBLES:\n\n");
        printf("1 - SECCION INGRESAR NUEVO TRABAJADOR\n");
        printf("2 - SECCION CONSULTAR\n");
        printf("3 - SECCION MODIFICAR UN TRABAJADOR\n");
        printf("4 - SECCION ELIMINAR UN TRABAJADOR\n");
        printf("5 - SALIR\n\n");
        printf("Por favor seleccione una opcion: ");
        scanf("%d", &n);
        switch (n) {
            case 1:
                printf("\nSe le pedira a continuacion los datos necesarios para poder agregar con exito un nuevo trabajador.\n");
                crear_trabajador(vector_archivo,&dim);
                break;

            case 2:
                do{
                    printf("\nOpciones de consulta disponibles:\n\n");
                    printf("1 - CEDULA\n");
                    printf("2 - DEPARTAMENTO\n");
                    printf("3 - CARGO\n");
                    printf("4 - EMPLEADO CON MAYOR SUELDO\n");
                    printf("5 - EMPLEADO CON MENOR SUELDO\n");
                    printf("6 - VOLVER AL MENU ANTERIOR\n");
                    printf("\nINDIQUE EL TIPO DE CONSULTA QUE VA A REALIZAR: ");
                    scanf("%d", &i);
                    __fpurge(stdin);
                    switch (i) {
                        case 1:
                            filtrar_cedula(vector_archivo, dim);
                            break;
                        case 2:
                            departamento(vector_archivo, dim);
                            break;
                        case 3:
                            cargo(vector_archivo, dim);
                            break;
                        case 4:
                            mayor_sueldo(vector_archivo,dim);
                            break;
                        case 5:
                             menor_sueldo(vector_archivo,dim);
                            break;
                        case 6:
                            break;
                        default:
                            printf("\nOPCION INVALIDA.\n");
                            break;

                    }
                }while(i<1 || i>6);
                break;

            case 3:
                modificar_trabajador(vector_archivo,dim);
                break;

            case 4:
                eliminar_trabajador(vector_archivo,&dim);
                break;

            case 5:
                cargar_datos_archivo(vector_archivo,dim);
                break;

            default:
                printf("OPCION INVALIDA.\n");
                break;
        }
    } while (n!=5);
}

void leer_datos_archivo(FILE *pf,int *dim) {
    int i=0;
    pf = fopen("clientes.dat", "r");
    if (pf != NULL) {
        printf("Fichero abierto correctamente.\n");
        if (!feof(pf)) {

            while (fscanf(pf,"%d\t\t%s %s\t\t%s\t\t%s\t\t%d\t\t%d-%d-%d\n",&vector_archivo[i].cedula,vector_archivo[i].nombre, vector_archivo[i].apellido,
                          vector_archivo[i].departamento,vector_archivo[i].cargo,&vector_archivo[i].sueldo,&vector_archivo[i].f.anio,
                          &vector_archivo[i].f.mes,&vector_archivo[i].f.dia) != EOF ) {
                i=i+1;}
        }
        *dim=i;
        fclose(pf);
    }
}

void cargar_datos_archivo(struct CLIENTE vector_archivo[],int dim){
    int i;
    FILE *pf = fopen("clientes.dat", "w");

    if (pf != NULL) {
        for (i=0;i<dim;i++){
            fprintf(pf,"%-10d\t\t%s %s\t\t%-10s\t\t%-10s\t\t%-10d\t\t%d-%d-%d\n",vector_archivo[i].cedula, vector_archivo[i].nombre,
                    vector_archivo[i].apellido, vector_archivo[i].departamento, vector_archivo[i].cargo, vector_archivo[i].sueldo,
                    vector_archivo[i].f.anio, vector_archivo[i].f.mes, vector_archivo[i].f.dia);
        }
        printf("DATOS GUARDADOS CORRECTAMENTE EN EL ARCHIVO.\n");
    }
}

void crear_trabajador(struct CLIENTE vector_archivo[],int* dim){
    int n,f,i;
    char letra;
    printf("\nINDIQUE LA CANTIDAD DE USUARIOS QUE DESEA REGISTRAR: ");
    scanf("%d",&n);
    __fpurge(stdin);

    i=*dim;
    f=((*dim)+n);

    for (i;i<f;i++) {
        if(n>1) printf("\nEMPLEADO #%d \n\n", i+1);

        printf("Ingrese el numero de cedula: ");
        scanf("%d", &vector_archivo[i].cedula);
        __fpurge(stdin);

        printf("Ingrese el nombre del cliente: ");
        scanf("%s",vector_archivo[i].nombre);
        __fpurge(stdin);

        printf("Ingrese el apellido del cliente: ");
        scanf("%s", vector_archivo[i].apellido);
        __fpurge(stdin);

        printf("\nDepartamentos disponibles:\n\n- rrhh\n- consultor\n- diseno\n- produccion\n- calidad\n- distribucion\n\nSeleccione un departamento: ");
        scanf("%s", vector_archivo[i].departamento);
        __fpurge(stdin);

        printf("\nCargos disponibles:\n\n- gerente\n- supervisor\n- analista\n- disenador\n- desarrollador\n- auditor\n\nSeleccione un cargo: ");
        scanf("%s", vector_archivo[i].cargo);
        __fpurge(stdin);

        printf("Inserte el sueldo del trabajador: ");
        scanf("%i", &vector_archivo[i].sueldo);
        __fpurge(stdin);

        printf("Inserte el agno en el que ingreso: ");
        scanf("%d", &vector_archivo[i].f.anio);
        __fpurge(stdin);

        printf("Inserte el mes en el que ingreso: ");
        scanf("%d", &vector_archivo[i].f.mes);
        __fpurge(stdin);

        printf("Inserte el dia en el que ingreso: ");
        scanf("%d", &vector_archivo[i].f.dia);
        __fpurge(stdin);
    }
    (*dim)=(*dim)+n;
    printf("DATOS RECIBIDOS.\n");

}
int mostrar_posicion_cedula(struct CLIENTE vector_archivo[],int* dim, int c_i){
    int j=0;
    bool band=false;

    while (j != *dim) {
        if ((vector_archivo[j].cedula) == c_i) {
            band=true;
            break;
        } else {
            j = j + 1;
        }
    }
    if (band) {
        return j;
    } else {
        return -1;
    }
}

void filtrar_cedula(struct CLIENTE vector_archivo[],int dim) {
    int consulta_ci,pos,n;

    printf("\nINGRESE EL NUMERO DE CEDULA QUE VA A CONSULTAR: ");
    scanf("%d",&consulta_ci);
    __fpurge(stdin);

    pos = mostrar_posicion_cedula(vector_archivo,&dim, consulta_ci);

    if (pos >= 0) {
        printf("\nESTOS SON LOS DATOS DEL CEDULA SOLICITADA:\n%d %s %s %s %s %d %d-%d-%d\n", vector_archivo[pos].cedula, vector_archivo[pos].nombre,
               vector_archivo[pos].apellido, vector_archivo[pos].departamento, vector_archivo[pos].cargo,
               vector_archivo[pos].sueldo, vector_archivo[pos].f.anio, vector_archivo[pos].f.mes, vector_archivo[pos].f.dia);
    }
    else {
        printf("CEDULA NO ENCONTRADA\n");
    }
}

void departamento(struct CLIENTE vector_archivo[],int dim) {
    int n, i, n_trab=0, acum_sueldo=0,aux;
    char j, seguir;
    FILE *ps;

    printf("\nDEPARTAMENTOS A CONSULTAR DISPONIBLES: \n\n1: RRHH\n2: CONSULTOR\n3: DISENO\n4: PRODUCCION\n5: CALIDAD\n6: DISTRIBUCION:\n7: VOLVER \n\nINGRESE EL NUMERO DEL DEPARTAMENTO A CONSULTAR: " );
    scanf("%d", &n);
    __fpurge(stdin);
    if (n==7){
        return;
    }
    else if (n>7){
        aux=validar_opcion(n);
        if (aux==7){
            return;
        }else {
            n = aux;
        }
    }
    printf("\nDeseas generar un archivo de esta consulta? (s/n): ");
    scanf("%c", &j);
    __fpurge(stdin);


    if (siono(j, 's', 'n') == 's') {
        ps = fopen("departamento.dat", "w");
        if (ps != NULL) {
            for (i = 0; i < dim; i++) {
                if (j == 's') {
                    if (strcmp(vector_archivo[i].departamento, vector_departamento[n - 1]) == 0) {
                        printf("\n%d %s %s %s\n", vector_archivo[i].cedula,vector_archivo[i].nombre,vector_archivo[i].apellido, vector_archivo[i].departamento);
                        n_trab++;
                        acum_sueldo += vector_archivo[i].sueldo;

                        fprintf(ps,"%-10d\t\t%s %s\t\t%-10s\t\t%-10s\t\t%-10d\t\t%d-%d-%d\n",vector_archivo[i].cedula, vector_archivo[i].nombre,
                                vector_archivo[i].apellido, vector_archivo[i].departamento, vector_archivo[i].cargo, vector_archivo[i].sueldo,
                                vector_archivo[i].f.anio, vector_archivo[i].f.mes, vector_archivo[i].f.dia);
                    }
                }

            }
        }
        fclose(ps);

    } else {
        for (i = 0; i < dim; i++) {
            if (strcmp(vector_archivo[i].departamento, vector_departamento[n - 1]) == 0) {
                printf("\n%d %s %s %s\n", vector_archivo[i].cedula,vector_archivo[i].nombre,vector_archivo[i].apellido, vector_archivo[i].departamento);
                n_trab++;
                acum_sueldo += vector_archivo[i].sueldo;
            }
        }
    }
    printf("\nNumero de trabajadores pertenecientes al departamento: %d\n", n_trab);
    printf("Sueldo total del departamento: %i\n", acum_sueldo);
}

void cargo(struct CLIENTE vector_archivo[],int dim) {
    int n, i, n_trab=0, acum_sueldo=0,aux;
    char j, seguir;
    FILE *ps;

    printf("\nCARGOS A CONSULTAR DISPONIBLES: \n\n1: GERENTE\n2: SUPERVISOR\n3: ANALISTA\n4: DISENADOR\n5: DESARROLADOR\n6: AUDITOR\n7: VOLVER \n\nINGRESE EL CARGO A CONSULTAR: " );
    scanf("%d", &n);
    __fpurge(stdin);
    if (n==7){
        return;
    }
    else if (n>7){
        aux=validar_opcion(n);
        if (aux==7){
                return;
        }else {
            n = aux;
        }
    }

    printf("\nDeseas generar un archivo de esta consulta? (s/n): ");
    scanf("%c", &j);
    __fpurge(stdin);

    if (siono(j, 's', 'n') == 's') {
        ps = fopen("cargo.dat", "w");
        if (ps != NULL) {

            for (i = 0; i < dim; i++) {
                if (j == 's') {
                    if (strcmp(vector_archivo[i].cargo, vector_cargo[n - 1]) == 0) {
                        printf("\n%d %s %s %s \n", vector_archivo[i].cedula,vector_archivo[i].nombre,vector_archivo[i].apellido, vector_archivo[i].cargo);
                        n_trab++;
                        acum_sueldo += vector_archivo[i].sueldo;

                        fprintf(ps,"%-10d\t\t%s %s\t\t%-10s\t\t%-10s\t\t%-10d\t\t%d-%d-%d\n",vector_archivo[i].cedula, vector_archivo[i].nombre,
                                vector_archivo[i].apellido, vector_archivo[i].departamento, vector_archivo[i].cargo, vector_archivo[i].sueldo,
                                vector_archivo[i].f.anio, vector_archivo[i].f.mes, vector_archivo[i].f.dia);
                    }
                }
            }
        }
        fclose(ps);

    } else {
        for (i = 0; i < dim; i++) {
            if (strcmp(vector_archivo[i].cargo, vector_cargo[n - 1]) == 0) {
                n_trab++;
                acum_sueldo += vector_archivo[i].sueldo;

                printf("\n%d %s %s %s\n", vector_archivo[i].cedula,vector_archivo[i].nombre,vector_archivo[i].apellido, vector_archivo[i].cargo);
            }
        }
    }
    printf("\nNumero de trabajadores pertenecientes al cargo: %d\n", n_trab);
    printf("Sueldo total del cargo: %i\n", acum_sueldo);

}


void mayor_sueldo(struct CLIENTE vector_archivo[],int dim){
    int aux,i,p=0;
    aux = vector_archivo[0].sueldo;
    for(i=1; i<dim; i++){
        if(aux < vector_archivo[i].sueldo){
            aux = vector_archivo[i].sueldo;
            p = i;
        }
    }

    printf("%s %s, C.I. %d, es el sueldo mayor con: %d\n",vector_archivo[p].nombre,vector_archivo[p].apellido,vector_archivo[p].cedula,vector_archivo[p].sueldo);
}

void menor_sueldo(struct CLIENTE vector_archivo[],int dim){
    int aux,p=0,i;
    aux = vector_archivo[0].sueldo;
    for(i=1; i<dim; i++){
        if(aux > vector_archivo[i].sueldo) {
            aux = vector_archivo[i].sueldo;
            p = i;
        }
    }

    printf("%s %s, C.I. %d, es el sueldo menor con : %d\n",vector_archivo[p].nombre, vector_archivo[p].apellido, vector_archivo[p].cedula ,vector_archivo[p].sueldo);
}

void modificar_trabajador(struct CLIENTE vector_archivo[],int dim) {
    int n,pos,i;
    char letra,band=true;

    printf("\nIngrese el numero de cedula a modificar: ");
    scanf("%d", &n);
    __fpurge(stdin);
    pos=mostrar_posicion_cedula(vector_archivo,&dim,n);

    if (pos>=0) {
        printf("\nCEDULA ENCONTRADA ESTOS SON SUS DATOS:\n\n%d %s %s %s %s %d %d-%d-%d\n", vector_archivo[pos].cedula, vector_archivo[pos].nombre,vector_archivo[pos].apellido,
               vector_archivo[pos].departamento, vector_archivo[pos].cargo,vector_archivo[pos].sueldo, vector_archivo[pos].f.anio, vector_archivo[pos].f.mes, vector_archivo[pos].f.dia);
        do {
            printf("\nDATOS MODIFICABLES:\n\n1: NOMBRE\n2: APELLIDO\n3: DEPARTAMENTO\n4: CARGO\n5: SUELDO\n6: FECHA-INGRESO\n7: TODOS-LOS-CAMPOS\n8: SALIR\n\nINDIQUE QUE DESEA MODIFICAR: ");
            scanf("%d", &n);
            switch (n) {
                case 1:
                    printf("Ingrese el nombre del cliente: ");
                    scanf("%s", vector_archivo[pos].nombre);
                    __fpurge(stdin);
                    break;

                case 2:
                    printf("Ingrese el apellido del cliente: ");
                    scanf("%s", vector_archivo[pos].apellido);
                    __fpurge(stdin);
                    break;

                case 3:
                    printf("\nDepartamentos disponibles:\n\n- rrhh\n- consultor\n- diseno\n- produccion\n- calidad\n- distribucion\n\nSeleccione un departamento: ");
                    scanf("%s", vector_archivo[pos].departamento);
                    __fpurge(stdin);

                    break;

                case 4:
                    printf("\nCargos disponibles:\n\n- gerente\n- supervisor\n- analista\n- disenador\n- desarrollador\n- auditor\n\nSeleccione un cargo: ");
                    scanf("%s", vector_archivo[pos].cargo);
                    __fpurge(stdin);

                    break;

                case 5:
                    printf("Inserte el sueldo del trabajador: ");
                    scanf("%i", &vector_archivo[pos].sueldo);
                    __fpurge(stdin);

                    break;

                case 6:
                    printf("Inserte el agno en el que ingreso: ");
                    scanf("%d", &vector_archivo[pos].f.anio);
                    __fpurge(stdin);

                    printf("Inserte el mes en el que ingreso: ");
                    scanf("%d", &vector_archivo[pos].f.mes);
                    __fpurge(stdin);

                    printf("Inserte el dia en el que ingreso ");
                    scanf("%d", &vector_archivo[pos].f.dia);
                    __fpurge(stdin);

                    break;

                case 7:
                    printf("Ingrese el nombre del cliente: ");
                    scanf("%s", vector_archivo[i].nombre);
                    __fpurge(stdin);

                    printf("Ingrese el apellido del cliente: ");
                    scanf("%s", vector_archivo[i].apellido);
                    __fpurge(stdin);

                    printf("\nDepartamentos disponibles:\n\n- rrhh\n- consultor\n- diseno\n- produccion\n- calidad\n- distribucion\n\nSeleccione un departamento: ");
                    scanf("%s", vector_archivo[i].departamento);
                    __fpurge(stdin);

                    printf("\nCargos disponibles:\n\n- gerente\n- supervisor\n- analista\n- disenador\n- desarrollador\n- auditor\n\nSeleccione un cargo: ");
                    scanf("%s", vector_archivo[i].cargo);
                    __fpurge(stdin);

                    printf("Inserte el sueldo del trabajador: ");
                    scanf("%i", &vector_archivo[i].sueldo);
                    __fpurge(stdin);

                    printf("Inserte el agno en el que ingreso: ");
                    scanf("%d", &vector_archivo[i].f.anio);
                    __fpurge(stdin);

                    printf("Inserte el mes en el que ingreso: ");
                    scanf("%d", &vector_archivo[i].f.mes);
                    __fpurge(stdin);

                    printf("Inserte el dia en el que ingreso ");
                    scanf("%d", &vector_archivo[i].f.dia);
                    __fpurge(stdin);
                    break;

                case 8:
                    band=false;
                    break;

                default:
                    printf("Opcion invalida.\n");
                    break;
            }
        } while ((i > 0 && i <=8)&& band);
        printf("\nDATOS MODIFICADOS EXITOSAMENTE\n");

    } else {
        printf("ESTA CEDULA NO SE ENCUENTRA EN LA EMPRESA\n");
    }
}

void eliminar_trabajador(struct CLIENTE vector_archivo[],int* dim) {
    struct CLIENTE a;
    int n, pos,i;
    char seguir;

    printf("\nIngrese el numero de cedula del trabajador que va a despedir: ");
    scanf("%d", &n);
    __fpurge(stdin);
    pos = mostrar_posicion_cedula(vector_archivo, dim, n);

    if (pos >= 0) {
        printf("\nEstas seguro de querer eliminar la informacion de esta persona?\n\n%d %s %s %s %s\n\n(s/n): ",
               vector_archivo[pos].cedula, vector_archivo[pos].nombre,
               vector_archivo[pos].apellido, vector_archivo[pos].departamento, vector_archivo[pos].cargo);

        scanf("%c", &seguir);
        __fpurge(stdin);

        if (siono(seguir,'s','n') == 's') {
            printf("MOTIVOS:\n\n1: TRASLADO\n2: RENUNCIA\n3: DESPIDO\n4: OTRO\n\nIndique un motivo de retiro: ");
            scanf("%d",&i);
            __fpurge(stdin);
            printf("INDIQUE EL AGNO DEL RETIRO: ");
            scanf("%d",&a.f.anio);
            __fpurge(stdin);
            printf("INDIQUE EL MES DEL RETIRO: ");
            scanf("%d",&a.f.mes);
            __fpurge(stdin);
            printf("INDIQUE EL DIA DEL RETIRO: ");
            scanf("%d",&a.f.dia);
            __fpurge(stdin);

            FILE *ps = fopen("extrabajadores.dat", "a");
            if (ps != NULL) {

                fprintf(ps,"%-10d\t\t%s %s\t\t%-10s\t\t%-10s\t\t%-10d\t\t%d-%d-%d\t\t%-10s\t\t%d-%d-%d\n", vector_archivo[pos].cedula,
                        vector_archivo[pos].nombre,
                        vector_archivo[pos].apellido, vector_archivo[pos].departamento, vector_archivo[pos].cargo,
                        vector_archivo[pos].sueldo, vector_archivo[pos].f.anio, vector_archivo[pos].f.mes,
                        vector_archivo[pos].f.dia,vector_motivo[i-1],a.f.anio,a.f.mes,a.f.dia);
            }
            for (pos; pos <= *dim - 1; pos++) {
                vector_archivo[pos] = vector_archivo[pos + 1];
            }
            (*dim)--;
            printf("\nCLIENTE BORRADO SATISFACTORIAMENTE, PARA CONSULTAR MAS DETALLES REVISE EL DOCUMENTO EXTRABAJADORES DE LA EMPRESA\n");
        }
    }else {
        printf("\nCEDULA NO ENCONTRADA EN LA EMPRESA\n");
    }
}

char siono(char var,char si,char no){
    do {
        if(var != si && var != no) {
            printf("No es una respuesta valida! Tiene que ser 's' o 'n' (sin comillas): ");
            scanf("%s",&var);
            __fpurge(stdin);

        }
    } while(var != si && var != no);
    return var;
}

int validar_opcion(int n){
    do {
        printf("\nINGRESE UNA OPCION VALIDA DEL 1 AL 7: \n" );
        scanf("%d",&n);
        __fpurge(stdin);
    } while (n!=7 && n!=6 && n!=5 && n!=4 && n!=3 && n!=2 && n!=1);
    return n;
}
