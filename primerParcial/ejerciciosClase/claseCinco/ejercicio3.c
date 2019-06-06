#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint64_t factorial (int);
/*
void main (void){
    int numero = 0;
    uint64_t fact = 0;
    printf("\nIngrese numero a calcular factorial: ");
    scanf("%d",&numero);
    fact = factorial(numero);
    printf("start: %x - end: %x", (uint64_t *)&fact, ((uint64_t *)&fact)+1);
    printf("\nEl factorial de %d es %lld \n", numero,fact);
    return;
}
*/
uint64_t factorial (int numero){
    if( numero < 0 ) return -1;
    if (numero == 1 || numero == 0){
        return 1;
    }
    return numero * factorial( numero - 1 );

}