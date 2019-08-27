/*
    Modifique el programa anterior para que el programa indique si el caractér es dígito o no.
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
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            result = 2;
            break;
        default: 
            result = 0;
            break;
    }
    char *respuesta;
    if (result == 1) respuesta = "Es una vocal\n";
    else if (result == 2) respuesta = "Es un digito\n";
    else respuesta = "No es una vocal\n";
    printf("%s",respuesta);
    return 0;

}