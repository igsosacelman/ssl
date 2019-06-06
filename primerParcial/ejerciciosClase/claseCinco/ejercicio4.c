#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int max(int*,int, int*);

int main (char argc, char* argv[]){
    //printf("%d   %s", argc,argv[1]);
    int vector[] = {1,2,3,4,-9,5,6,7,8,9};
    int indice = 0;
    int maximo = 0;
    maximo = max(vector,10,&indice);
    printf("Maximo: %d \t posicion: %d \n", maximo,indice);
}

int max(int* vector,int len, int* indice){
    if (len == 0){
        *indice = -1;
        return -1;
    } 
    int i, max;
    for (i = 0; i < len; i++){
        if(max < vector[i] || i == 0){
            max = vector[i];
            *indice = i;
        }
    }
    return max;
}
