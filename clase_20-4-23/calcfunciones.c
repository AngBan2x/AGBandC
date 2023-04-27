//usando acciones nominadas, realizar una calculadora que realice las cuatro operaciones básicas, entre dos números; y un menú

#include <stdio.h>

//declaracion de las acciones nominadas de las operaciones
float suma(float a, float b);
float resta(float a, float b);
float prod(float a, float b);
float division(float a, float b);
float valexc(float num, float exc);                        //validar un numero en base a la exclusion a otro numero
int valmin(int *num, int *liminf);                         //validar un numero en base a un limite inferior
int valminmax(int *num, int *liminf, int *limsup);         //validar un numero en base a un limite superior e inferior
void menu();

char valrepetir(char si, char no);

void main(){
    int opcion;
    int opcionmax=4;
    int cero=0;
    char repetir;

    printf("Esta es una calculadora que calcula dos operaciones basicas entre SOLO dos numeros\n");
    
    do{
        menu();
        valminmax(&opcion, &cero, &opcionmax);

        switch (opcion)
        {
        case 0:
            printf("Adios!\n");
            break;
        case 1:
            printf("~~~~~SUMA~~~~~\n");
            float sum1, sum2;

            printf("Inserte un sumando: ");
            scanf("%f", &sum1);

            printf("Inserte el otro sumando: ");
            scanf("%f", &sum2);

            printf("El total: %f + %f = %f\n", sum1, sum2, suma(sum1, sum2));
            break;
        case 2:
            printf("~~~~~RESTA~~~~~\n");
            float min, sus;

            printf("Inserte el minuendo: ");
            scanf("%f", &min);

            printf("Inserte el sustraendo: ");
            scanf("%f", &sus);

            printf("La diferencia: %f - %f = %f\n", min, sus, resta(min, sus));
            break;
        case 3:
            printf("~~~~~MULTIPLICACION~~~~~\n");

            float f1, f2;

            printf("Inserte el multiplicando: ");
            scanf("%f", &f1);

            printf("Inserte el multiplicador: ");
            scanf("%f", &f2);

            printf("El producto: %f x %f = %f\n", f1, f2, prod(f1, f2));
            break;
        case 4:
            printf("~~~~~DIVISION~~~~~\n");

            float d1, d2;

            printf("Inserte el dividendo: ");
            scanf("%f", &d1);

            printf("Inserte el divisor: ");
            d2 = valexc(d2, cero);
            float coc = division(d1, d2);

            printf("El cociente: %f / %f = %f\n", d1, d2, coc);
            break;
        }
        if (opcion!=0){
            printf("Quieres realizar mas calculos? (s/n): ");
            repetir = valrepetir('s', 'n');
            fflush(stdin);
            if ((repetir == 'n')){
                fflush(stdin);
                printf("\nAdios!\n");
                break;}
        }
    }while((repetir == 's')&&(opcion!=0));
}

//definicion de las funciones
float suma(float a, float b){
    float res = a+b;
    return res;
}

float resta(float a, float b){
    float res = a-b;
    return res;
}

float prod(float a, float b){
    float res = a*b;
    return res;
}

float division(float a, float b){
    float res = a/b;
    return res;
}

float valexc(float num, float exc){
    do
    {
        scanf("%f", &num);
        if(num == exc) printf ("No es un numero valido, inserte un numero valido");
    } while (num == exc);
    
    return num;
}

int valmin(int *num, int *liminf){
    do{
        scanf("%d", num);
        if(*num < *liminf) printf("No es un numero valido!\nInserta un numero valido: ");
    }while(*num < *liminf);
    return *num;
}

int valminmax(int *num, int *liminf, int *limsup){
    do{
        scanf("%d", num);
        if((*num < *liminf)||(*num > *limsup))
            printf("No es un numero valido!\nInserta un numero valido: ");
    }while((*num < *liminf)||(*num > *limsup));
    return *num;
}

char valrepetir(char si, char no){
    char repetir;
    do
    {
        fflush(stdin);
        scanf("%c", &repetir); 
        fflush(stdin);
        if(repetir != si && repetir != no)
        {printf("Solo puede ser %c o %c: ", si, no); fflush(stdin);}
    } while (repetir != si && repetir != no);
    fflush(stdin);
    return repetir;
}

void menu(){
    printf("\n=====MENU PRINCIPAL=====\n");
    printf("\n1: Suma\n");
    printf("2: Resta\n");
    printf("3: Multiplicacion\n");
    printf("4: Division\n");
    printf("0: Salir\n");
    printf("\nElige una opcion: \n");
}