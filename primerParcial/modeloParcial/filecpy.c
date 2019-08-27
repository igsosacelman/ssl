#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (int argc, char* argv[]){
    if (argc<3){
        printf("faltan argumentos \n");
        return -1;
    }

    FILE* pFile;
    FILE* pFileToCopy;
    const char* archivoUno = argv[1];
    char* archivoDos = argv[2];

    pFile = fopen(archivoUno,"r");
    pFileToCopy = fopen(archivoDos,"w");

    if(pFile==NULL || pFileToCopy==NULL){
        printf("error al abrir archivo\n");
        return -1;
    }
    char caracter = getc(pFile);
    while(EOF != caracter){
        if(caracter == 'a'){
            caracter = 'e';
        }
        putc(caracter,pFileToCopy);
        caracter = getc(pFile);
    }

    fclose(pFile);
    fclose(pFileToCopy);
    return 0;
}