#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (int argc, char* argv[]){
    if (argc<4){
        printf("faltan argumentos \n");
        return -1;
    }

    FILE* pReadFile;
    FILE* pWriteFile;
    char* caracterDeReemplazo = argv[2];
    char* caracterAReemplazar = argv[1];
    const char* archivo = argv[3];

    pReadFile = fopen(archivo,"r");
    pWriteFile = fopen("out.txt","w");

    if(pReadFile==NULL || pWriteFile==NULL){
        printf("error al abrir archivo\n");
        return -1;
    }

    char caracterLeido = getc(pReadFile);
    while(EOF != caracterLeido){
        if(caracterLeido == *caracterAReemplazar){
            caracterLeido = *caracterDeReemplazo;
        }
        putc(caracterLeido,pWriteFile);
        caracterLeido = getc(pReadFile);
    }
    
    fclose(pReadFile);
    fclose(pWriteFile);
    return 0;
}