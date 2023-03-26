/*Escribir en lenguaje C un programa que:
1) Pida por teclado tres numeros enteros
2) Muestre el mayor de los tres numeros introducidos*/

#include <stdio.h>
void main(){
    int num1, num2, num3;
    
    printf("CUAL NUMERO ES EL MAYOR DE TRES? \n \nInserta el primer numero: ");
    scanf("%d", &num1);
    
    printf("Inserta el segundo numero: ");
    scanf("%d", &num2);
    
    printf("Inserta el tercer numero: ");
    scanf("%d", &num3);
    
    if ((num1>num2 && num1>num3)||(num1==num2 && num2>num3))
    {
        printf("%d es el numero mayor", num1);
    }
    else if (num2>num1 && num2>num3)
    {
        printf("%d es el numero mayor", num2);
    }
    else if ((num3>num1 && num3>num2)||(num3==num1 && num1>num2))
    {
        printf("%d es el numero mayor", num3);
    }
    else
    {
        printf("Son numeros iguales!");
    }
    
}