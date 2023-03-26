/*Desarrolle un programa en C que permita registrar las citas medicas de la clinica
ABC de n cantidad de pacientes, permitiendo mostrar por pantalla:
1) Cantidad de pacientes femeninos
2) Cantidad de pacientes masculinos
3) Cantidad de pacientes mayores de edad
4) Cantidad de pacientes menores de edad
5) Validar las fechas de nacimiento de cada paciente
6) Los pacientes cuya cedula de identidad termine en un numero par y sean del sexo
femenino, tendran un descuento del 35% sobre el costo de la consulta
7) Los pacientes del sexo masculino que tengan una edad mayor a 60 años, tendran un
descuento del 30%*/ 

#include <stdio.h>

int valminmax(int *num, int *nummax, int *nummin){ //validar con limite superior e inferior
    do
    {
        scanf("%d", num);
        if ((*num>*nummax)||(*num<*nummin))
        {
            printf("Numero no valido! Inserta un numero valido: ");
        }
    } while ((*num>*nummax)||(*num<*nummin));
    return *num;
}

int valmin(int *num, int *nummin){ //validar con solo un limite inferior
    do
    {
        scanf("%d", num);
        if (*num<*nummin)
        {
            printf("Numero no valido! Inserta un numero valido: ");
        }
    } while (*num<*nummin);
    return *num;
}

int valmax(int *num, int *nummax){ //validar con solo un limite superior
    do
    {
        scanf("%d", num);
        if (*num>*nummax)
        {
            printf("Numero no valido! Inserta un numero valido: ");
        }
    } while (*num>*nummax);
    return *num;
}

int main(){
    
    printf("CLINICA ABC\n \nInserta cuantos pacientes quiere registrar: ");
    int npac, npac_min=0;
    valmin(&npac, &npac_min);

    int dda, mma, aa; //variables para crear una "fecha actual" y asi validar las fechas de nacimiento en base a la "actual"

    printf("FECHA ACTUAL\n\nInserta el a%co actual: ", 164);
    scanf("%d", &aa);
    
    printf("Inserta el mes actual: ");
    int mma_min=1, mma_max=12;
    valminmax(&mma, &mma_max, &mma_min);

    printf("Inserta el dia actual: ");
    int dda_min=1, dda_max=31;
    if ((mma==1)||(mma==3)||(mma==5)||(mma==7)||(mma==8)||(mma==10)||(mma==12))
    {
        valminmax(&dda, &dda_max, &dda_min);
    }
    else if ((mma==4)||(mma==6)||(mma==9)||(mma==11))
    {
        dda_max=30;
        valminmax(&dda, &dda_max, &dda_min);
    }
    else if ((mma==2)&&((aa%4==0)&&((aa%100!=0)||(aa%400==0)))) //validar si el año actual es bisiesto
    {
        dda_max=29;
        valminmax(&dda, &dda_max, &dda_min);
    }
    else if (mma==2)
    {
        dda_max=28;
        valminmax(&dda, &dda_max, &dda_min);
    }
    printf("\nLa fecha de hoy es %d-%d-%d \n \n", dda, mma, aa);

    int consulta, consulta_min=1;
    printf("Inserte el costo de la consulta: ");
    valmin(&consulta, &consulta_min);

    int sexo, pacf=0, pacm=0, ci, pacmae=0, pacmee=0, cdescmasc=0, cdescfem=0;
    /*pacmae = pacientes mayores de edad
    pacmee = pacientes menores de edad
    cdescmasc = consulta descontada por pacientes masculinos
    cdescfem = consulta descontada por pacientes femeninos*/
    
    int dd, mm, ac; //fecha de nacimiento del cliente
    
    for (int i = 0; i < npac; i++)
    {
        printf("Ingrese de que sexo es el/la paciente nro %d. \n(1: Masculino / 0 Femenino): ", i+1);
        do
        {
            fflush(stdin);
            scanf("%d", &sexo);
            if ((sexo>1)||(sexo<0))
            {
                printf("No es un numero valido!\nInserte un numero valido.\n(1: Masculino / 0: Femenino): ");
            }
        } while ((sexo>1)||(sexo<0));
        
        if (sexo==1)
        {
            pacm = pacm+1;
        }
        else
        {
            pacf = pacf+1;
        }
        
        int ci_min=1;
        printf("Inserte el numero de cedula del paciente: ");
        valmin(&ci, &ci_min);
        
        int amin=aa-122, mm_min=1, mm_max=12, dd_max=31, dd_min=1;
        printf("\nFECHA DE NACIMIENTO\n\nInserte el a%co en que nacio: ", 164);
        valminmax(&ac, &aa, &amin);
        if (ac==aa)
        {
            printf("Inserte el mes en que nacio: ");
            valminmax(&mm, &mma, &mm_min);
            printf("Inserta el numero el dia en que nacio: ");
            valminmax(&dd, &dda, &dd_min);
        }    
        else
        {
            printf("Inserte el mes en que nacio: ");
            valminmax(&mm, &mm_max, &mm_min);
            printf("Inserta el numero del dia en que nacio: ");
            if ((mm==1)||(mm==3)||(mm==5)||(mm==7)||(mm==8)||(mm==10)||(mm==12))
            {
                valminmax(&dd, &dd_max, &dd_min);
            }
            else if ((mm==4)||(mm==6)||(mm==9)||(mm==11))
            {
                dd_max=30;
                valminmax(&dd, &dd_max, &dd_min);
            }
            else if ((mm==2)&&((ac%4==0)&&((ac%100!=0)||(ac%400==0)))) //valida si el año en que nacio el/la cliente/a es bisiesto
            {
                dd_max=29;
                valminmax(&dd, &dd_max, &dd_min);
            }
            else if (mm==2)
            {
                dd_max=28;
                valminmax(&dd, &dd_max, &dd_min);
            }
        }
        int edad; //edad del paciente
        if ((mm==mma)&&(dd==dda))
        {
            edad = aa-ac;
        }
        else
        {
            edad = (aa-ac) - 1;
        }
        
        if (edad>=18)
        {
            pacmae++;
        }
        else
        {
            pacmee++;
        }
        
        if ((edad>=60)&&(sexo==1))
        {
            cdescmasc++;
        }
        else if (((ci%2)==0)&&(sexo==0))
        {
            cdescfem++;
        }
    }
    printf("\nPacientes del sexo masculino: %d\n", pacm);
    printf("Pacientes del sexo femenino: %d\n", pacf);
    printf("Pacientes mayores de edad: %d\n", pacmae);
    printf("Pacientes menores de edad: %d\n", pacmee);
    printf("Pacientes con el 35%% de descuento: %d\n", cdescfem);
    printf("Pacientes con el 30%% de descuento: %d", cdescmasc);
}