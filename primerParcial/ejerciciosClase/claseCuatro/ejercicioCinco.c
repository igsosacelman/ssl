/*
    Programe “la potencia de un número”, siendo un programa que pida la base y el exponente
    de un número y calcule la potencia. El exponente siempre será entero, pudiendo ser
    negativo o positivo. No se debe utilizar la función pow para resolver este ejercicio, ya que
    el objetivo es practicar estructuras de repetición.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float potenciaPorRecursividad(float,int);

int main (int argc, char* argv[]){
    int base,exponente;

    printf("Ingrese valores para calcular potencia: \n");
    printf("Base: ");
    scanf("%d",&base);
    printf("Exponente: ");
    scanf("%d",&exponente);
    float potencia = potenciaPorRecursividad((float)base,exponente);
    printf("\n%d elevado a %d = %f\n", base,exponente,potencia);
    return 0;       
}

float potenciaPorRecursividad(float b, int e){
    if (e == 0) return 1;
    else if(e > 0) return (b * potenciaPorRecursividad(b, e-1));
    else return ((1/b) * potenciaPorRecursividad(b, e+1));
}