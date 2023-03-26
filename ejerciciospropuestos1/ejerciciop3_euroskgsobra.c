/*Suponiendo que el kilo de azucar y de cafe estan a 3$ y 0.72$ respectivamente, escribir en lenguaje C un programa que:
1) Pida por teclado una cantidad (dato real) en euros
2) Si la mitad de la cantidad introducida se destina a comprar azucar, una tercera parte a comprar cafe y el resto no se gasta, calcule cuantos kilos de azucar y cafe (datos reales) se pueden comprar
con dicha cantidad de dinero, asi como la cantidad (dato real) de dinero sobrante.
3) Muestre por pantalla los resultados (datos reales)*/

#include <stdio.h>
int main (){
    float euros, azucarkg, cafekg, sobra;
    printf("CUANTO CAFE Y AZUCAR PUEDES COMPRAR CON TU DINERO \n");
    printf("Inserte cuanto dinero en euros tienes: \n");
    scanf("%f", &euros);

    azucarkg = euros / 2;
    cafekg = euros / 3;
    sobra = euros - (azucarkg + cafekg);

    printf("Teniendo %.2f euros, se pueden comprar %f kilos de azucar, %f kilos de cafe, y sobrarian %.2f euros", euros, azucarkg, cafekg, sobra);
}