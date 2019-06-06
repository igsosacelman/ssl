#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int fibonacci(int);
int fibonacciFalopa(int*,int);

int main (char argc, char* argv[]){
    int numero = 0;
    printf("Ingrese numero: ");
    scanf("%d",&numero);
    /*
    int fibo = fibonacci(numero);
    printf("%d\n",fibo);
    */
    int* lista = (int*) malloc (numero*(sizeof(int)));
    int falopa = fibonacciFalopa(lista, numero);
    int indice;
    for(indice = 0; indice<numero; indice++){
        printf("\nlista[%d]: %d", indice, lista[indice]);
    }
}

int fibonacci(int numero){
    if (numero == 0) return 0;
    if (numero == 1) return 1;
    return fibonacci(numero-1)+fibonacci(numero-2);
}

int fibonacciFalopa(int* lista, int numero){
    if (numero == 0) return lista[0]=0;
    if (numero == 1) return lista[1]=1;
    lista[numero-1] = fibonacciFalopa(lista, numero-1);
    lista[numero-2] = fibonacciFalopa(lista, numero-2);
    return lista[numero-1]+lista[numero-2];
}

