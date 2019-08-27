#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char* argv[]){
    if (argc<3){
        printf("faltan argumentos \n");
        return -1;
    }

    if(strlen(argv[1]) != strlen(argv[2])){
        printf("Las cadenas deben tener la misma longitud\n");
        return -1;
    }

    char s1[50];

    int i=0;
    while (argv[1][i]!='\0')
    {
        s1[i] = argv[1][i] + argv[2][i];
        i++;
    }
    s1[i]= '\0';
     
    printf("Cadena encriptada: %s\n", s1);
    i=0;
    while (argv[1][i]!='\0')
    {
        s1[i] = s1[i] - argv[2][i];
        i++;
    }
    s1[i]= '\0';
     
    printf("Cadena desencriptada: %s\n", s1);
    return 0;
}