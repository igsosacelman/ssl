#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    
    FILE* pFile;
    const char* fileName = argv[1];
    char* wordToFind = argv[2];

    pFile = fopen(fileName,"r");

    if(argc < 3) {
        printf("Faltan parametros.\n");
        return -1;
    }


    if(pFile == NULL) {
        printf("Error al intentar abrir el archivo.\n");
        return -1;
    }

    int wordCount = 0;
    char currentWord[100];

    printf("eof %d\n",EOF );
    
    while(EOF != fscanf(pFile,"%s",currentWord)) {
        if( strcmp(currentWord,wordToFind) == 0) {
            wordCount++;
        }       
    }

    fclose(pFile);

    printf("\nLa cantidad de veces que aparece la palabra %s es %d.\n",wordToFind, wordCount);
    return 0;
}