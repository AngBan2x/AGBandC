/*Escribir un programa en C que pida por teclado n numeros enteros. Cada uno de ellos
debera de ser introducido. Calcular:

1) Cuantos son pares e impares
2) Cuantos ceros se han introducidos por teclado
3) Cuantos son primos*/

#include <stdio.h>
#include <stdbool.h>
int main(){
    printf("VERIFICADOR DE NUMEROS Y DIGITOS \n \n");
    
    int n; //n cantidad de numeros
    do
    {
        printf("Cuantos numeros quiere insertar: ");
        scanf("%d", &n);
    } while (n<1);
    
    int num, par=0, imp=0, pri=0, zer=0;
    bool band;

    for (int i = 0; i < n; i++)
    {
        printf("Inserta el numero: ");
        scanf("%d", &num);

        if (num%2==0)
        {
            par = par+1; //contar pares
        }
        else
        {
            imp = imp+1;
        }

        if (num > 2) //verificar si es primo o no
        {
            int c=2;
            
            band=false;
            while ((c<(num/2))&&(band==false))
            {
                band = (num)%c == 0;
                c=c+1;
            }
            if (band==false)
            {
                pri=pri+1;
            }
        }
        if (num==2)
        {
            pri=pri+1;
        }

        int aux=num;
        while (aux>=10) //ciclo para contar cuantos ceros en total estan en los digitos de todos los numeros
        {
            if (aux%10==0)
            {
                zer=zer+1;
            }
            aux=aux/10;
        }
        
    }
    
    printf("\nNumeros pares: %d\n", par);
    printf("Numeros impares: %d\n", imp);
    printf("Numeros primos: %d\n", pri);
    printf("Cantidad de ceros: %d\n \n", zer);
    return 0;
}