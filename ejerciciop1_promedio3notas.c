/*Escribir en Lenguaje C un programa que:
1) Pida por teclado la nota de tres exámenes (datos reales)
2) Calcule la nota media de los tres exámenes
3) Muestre por pantalla el resultado (dato real)*/

#include <stdio.h>
void main()
{
    float nota1, nota2, nota3, prom;
    printf("PROMEDIO DE NOTAS DE TRES EXAMENES \n");
    
    do
    {
        printf("Inserte la primera nota (Hasta 20):");
        scanf("%f", &nota1);
    } while ((nota1<0) || (nota1>20));
    
    do
    {
        printf("Inserte la segunda nota (Hasta 20):");
        scanf("%f", &nota2);
    } while ((nota2<0)||(nota2>20));
    
    do
    {
        printf("Inserte la tercera nota (Hasta 20):");
        scanf("%f", &nota3);
    } while ((nota3<0)||(nota3>20));
    
    prom = (nota1 + nota2 + nota3)/3; //calcula el promedio entre las tres notas

    printf("El promedio entre las tres notas es %f", prom);
}