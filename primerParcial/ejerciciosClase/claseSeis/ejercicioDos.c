#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    
    FILE* pFileToRead;
    FILE* pFileToWrite;

    const char* caracterAReemplazar = argv[1];
    const char* caracterDeReemplazo = argv[2];
    const char* fileName = argv[3];

    pFileToRead = fopen(fileName,"r");
    pFileToWrite = fopen("out.txt","w");

    if(argc < 4) {
        printf("Faltan parametros.\n");
        return -1;
    }

    if(pFileToRead == NULL) {
        printf("Error al intentar abrir el archivo.\n");
        return -1;
    }

    if(pFileToWrite == NULL) {
        printf("Error al intentar abrir el archivo.\n");
        return -1;
    }

    char currentChar;

    while(EOF != fscanf(pFileToRead,"%c",&currentChar)) {
        if( currentChar == *caracterAReemplazar) {
            currentChar = *caracterDeReemplazo;
        }
        fprintf(pFileToWrite,"%c",currentChar);
    }

    fclose(pFileToRead);
    fclose(pFileToWrite);

    return 0;
}