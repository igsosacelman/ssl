#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void sumaVectores(int*,int*,int*,int);

int main (char argc, char* argv[]){
    const int len = 10;
    int vectorUno[] = {1,2,3,4,5,5,6,7,8,9};
    int vectorDos[] = {1,1,1,2,2,1,1,1,2,1};
    int vectorTres[10];   
    sumaVectores(vectorUno, vectorDos, vectorTres, len);
    int indice;
    for(indice = 0; indice<len; indice++){
        printf("%d ",vectorTres[indice]);
    }
}

void sumaVectores(int* vectorUno ,int* vectorDos,int* vectorTres,int len){
    int indice;
    for(indice = 0; indice<len; indice++){
        vectorTres[indice] = vectorUno[indice] + vectorDos[indice];
    }
}