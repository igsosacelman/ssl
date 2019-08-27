/*
    Realice un programa que, dado el ingreso de un carácter, mencione si es una vocal o no.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char* argv[]){
    if (argc < 2){
        printf("Tenes que poner una letra al lado del nombre de la funcion\n");
        return 0;
    }
    char letra = *argv[1]; 
    int result;
    switch(letra){
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            result = 1;
            break;
        default: 
            result = 0;
            break;
    }
    char *respuesta;
    if (result) respuesta = "Es una vocal\n";
    else respuesta = "No es una vocal\n";
    printf("%s",respuesta);
    return 0;
}