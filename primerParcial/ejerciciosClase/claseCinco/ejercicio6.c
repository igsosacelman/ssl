#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void max(int*,int, int*, int*);

int main (char argc, char* argv[]){
    //printf("%d   %s", argc,argv[1]);
    int vector[] = {1,2,3,4,9,5,6,7,8,9};
    int indice = 0;
    int maximo;
    max(vector,10,&indice, &maximo);
    printf("Maximo: %d \t posicion: %d \n", maximo,indice);
}

void max(int* vector,int len, int* indice, int* max){
    if (len == 0){
        *max = -1;
        *indice = -1;
    }
    else{
        int i;
        for (i = 0; i < len; i++){
            if(*max < *(vector+i) || i == 0){
                *max = *(vector+i);
                *indice = i;
            }
        }
    } 
}
