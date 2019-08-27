/*
    Confeccione un programa en C que lea los coeficientes reales a,b y c de un polinomio de
    grado 2 y calcule la/las raíz/raíces en caso de ser posible.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main (int argc, char* argv[]){
    int a,b,c;

    printf("Ingrese los coeficientes del polinomio: \n");
    printf("Coeficiente a: ");
    scanf("%d",&a);
    printf("Coeficiente b: ");
    scanf("%d",&b);
    printf("Coeficiente c: ");
    scanf("%d",&c);

    printf("\nForma polinomica: (%d) . X^2 + (%d) . X + (%d) \n", a,b,c);

    int contenidoDeLaRaiz = b * b - 4 * a * c;

    if(contenidoDeLaRaiz < 0){
        printf("El resultado no pertenece al campo de los numeros reales");
        return 0;
    }

    float x1 = (float)((-1) * b + sqrt(contenidoDeLaRaiz))/(2 * a);
    float x2 = (float)((-1) * b - sqrt(contenidoDeLaRaiz))/(2 * a);

    printf("Raices del polinomio: \nX1 = %.1f\tX2 = %.1f\n",x1,x2);
    printf("\nForma factorizada: (%d) . ( X - (%.1f) ) . ( X - (%.1f) )\n", a,x1,x2);

    return 0;
}
