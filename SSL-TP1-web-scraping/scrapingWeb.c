#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *popen(const char *, const char *);
int pclose(FILE *);
void saveScrappedWebInFile(FILE*,FILE*,char*);
typedef enum { false, true } bool;
typedef enum { initTag, lookingForTag, lookingForProperty, saveInformation, finish } tagCase;

void filterFileByTagWithProperty(char* fileNameToRead,char* fileNameToWrite,char* tag, char* property, char* propertyName);
void filterFileByTag(char* fileNameToRead,char* fileNameToWrite,char* tag);

void formatScrappedWebFile(char*,char*);
void formatFilterFile(char*,char*);

void runMenu(void);
void imprimirEspecies(void);
void generarCSV(void);
void generarHTML(void);
void beforeLeaving(void);
void error(void);
void finishMessage(void);

int main(void){

    char *scrappedFileName = "scrappedWeb.txt";
    char *filteredFileName = "filterByTag.txt";
    char *auxFileName = "scrappedWebAuxiliar.txt";

    FILE *cmd = popen("wget -q -O - http://52.67.191.9/SSL/lideres-bcba.html --no-check-certificate","r");
    FILE *pFileScrappedWebWrite = fopen(scrappedFileName,"w");
    
    char result[1048576]; // 1 MB de buffer, ajustar segun implementacion
    
    if(cmd == NULL || pFileScrappedWebWrite == NULL ) {
        printf("Error al intentar abrir el archivo.\n");
        return 1;
    }
    saveScrappedWebInFile(cmd,pFileScrappedWebWrite,result);
    fclose(pFileScrappedWebWrite);
    pclose(cmd);

    formatScrappedWebFile(scrappedFileName,auxFileName);

    filterFileByTagWithProperty(auxFileName,filteredFileName,"table","id","tbAcciones");
    filterFileByTag(filteredFileName,auxFileName,"tbody");
    formatFilterFile(auxFileName,filteredFileName);

    //runMenu();

    return 0;
}

void saveScrappedWebInFile(FILE* read,FILE* write,char* buffer){
    while (fgets(buffer,sizeof(buffer),read) != NULL) {
        fprintf(write,"%s",buffer);
    }
}

void formatScrappedWebFile(char* fileNameToRead,char* fileNameToWrite){
    char currentWord[10];
    FILE* pFileToRead = fopen(fileNameToRead,"r");
    FILE* pFileToWrite = fopen(fileNameToWrite,"w");
    if(pFileToRead == NULL || pFileToWrite == NULL){
        printf("Error al intentar abrir el archivo.\n");
        return;
    }
    while(EOF != fscanf(pFileToRead,"%c",currentWord)){
        fputs(currentWord,pFileToWrite);
        if(strcmp(currentWord,">") == 0){
            fputs("\n",pFileToWrite);
        }
    }
    fclose(pFileToWrite);
    fclose(pFileToRead);
}

void formatFilterFile(char* fileNameToRead,char* fileNameToWrite){
    char currentWord[10];
    FILE* pFileToRead = fopen(fileNameToRead,"r");
    FILE* pFileToWrite = fopen(fileNameToWrite,"w");
    if(pFileToRead == NULL || pFileToWrite == NULL){
        printf("Error al intentar abrir el archivo.\n");
        return;
    }
    while(EOF != fscanf(pFileToRead,"%c",currentWord)){
        fputs(currentWord,pFileToWrite);
        if(strcmp(currentWord,"<") == 0){
            fputs(" ",pFileToWrite);
        }
    }
    fclose(pFileToWrite);
    fclose(pFileToRead);
}


void filterFileByTagWithProperty(char* fileNameToRead,char* fileNameToWrite,char* tag, char* property, char* propertyName){

    FILE* fileToRead = fopen(fileNameToRead,"r");
    FILE* fileToWrite = fopen(fileNameToWrite,"w");

    if(fileToRead == NULL || fileToWrite == NULL ) {
        printf("Error al intentar abrir el archivo.\n");
        return;
    }

    bool runEnable = true; tagCase state = lookingForTag;
    char currentWord[1048576] = {'\0'};
    char comparadorDeInicio[100] = {'\0'};
    char comparadorDeFin[100] = {'\0'};
    char comparadorDePropiedad[100] = {'\0'};
    char* tagInit = "<"; 
    char* tagFinOpen = "</"; char* tagFinClose = ">";
    char* propertyInit = "=\""; char* propertyClose = "\"";
    char* format = "%s";
    strcat(strcat(comparadorDeInicio,tagInit),tag);
    strcat(strcat(strcat(comparadorDeFin,tagFinOpen),tag),tagFinClose);
    strcat(strcat(strcat(strcat(comparadorDePropiedad,property),propertyInit),propertyName),propertyClose);

    while(EOF != fscanf(fileToRead,format, currentWord) && runEnable){
        switch(state){
            case lookingForTag: 
                if(strcmp(currentWord,comparadorDeInicio) == 0){
                state = lookingForProperty;
                }else{
                    state = lookingForTag;
                }
                break;
            case lookingForProperty: 
                if(strcmp(currentWord,comparadorDePropiedad) == 0){
                state = saveInformation;
                }else{
                    state = lookingForTag;
                }
                break;
            case saveInformation: 
                if(strcmp(currentWord,comparadorDeFin)!=0){
                    fputs(currentWord,fileToWrite);
                    fputs("\n",fileToWrite);
                }
                else{// Caso positivo: encontro el tag de cierre
                    state = finish;
                }
                break;
            case finish: 
                state = lookingForTag;
                runEnable = false;
                break;
            default: 
                printf("Algo salio mal");
                state = lookingForTag;
                runEnable = false;
                break;
        }
    }
    fclose(fileToRead);
    fclose(fileToWrite);
}

void filterFileByTag(char* fileNameToRead,char* fileNameToWrite,char* tag){

    FILE* fileToRead = fopen(fileNameToRead,"r");
    FILE* fileToWrite = fopen(fileNameToWrite,"w");

    if(fileToRead == NULL || fileToWrite == NULL ) {
        printf("Error al intentar abrir el archivo.\n");
        return;
    }

    bool runEnable = true; tagCase state = lookingForTag;
    char currentWord[1048576] = {'\0'};
    char comparadorDeInicio[100] = {'\0'}; 
    char comparadorDeFin[100] = {'\0'};
    char* tagInit = "<"; 
    char* tagFinOpen = "</"; char* tagFinClose = ">";
    char* format = "%s";
    strcat(strcat(strcat(comparadorDeInicio,tagInit),tag),tagFinClose);
    strcat(strcat(strcat(comparadorDeFin,tagFinOpen),tag),tagFinClose);
    while(EOF != fscanf(fileToRead,format, currentWord) && runEnable){
        switch(state){
            case lookingForTag: 
                if(strcmp(currentWord,comparadorDeInicio) == 0){
                state = saveInformation;
                }else{
                    state = lookingForTag;
                }
                break;
            case saveInformation: 
                if(strcmp(currentWord,comparadorDeFin)!=0){
                    fputs(currentWord,fileToWrite);
                    //fputs("\n",fileToWrite);
                }
                else{// Caso positivo: encontro el tag de cierre
                    state = finish;
                }
                break;
            case finish: 
                state = lookingForTag;
                runEnable = false;
                break;
            default: 
                printf("Algo salio mal");
                state = lookingForTag;
                runEnable = false;
                break;
        }
    }
    fclose(fileToRead);
    fclose(fileToWrite);

}

void runMenu(void){
    system("clear");
    bool run = true;
    int opcion;
    char ch;
    while(run){
        printf("1. Imprimir en pantalla\n");
        printf("2. Generar scv\n");
        printf("3. Generar html\n");
        printf("0. Salir\n");
        printf("Ingrese la opción que desea: ");
        ch = getchar();
        printf("esto es ch: %c",ch);
        switch(ch){
            case '0': 
                run = false;
                finishMessage();
                break;
            case '1': 
                imprimirEspecies();
                break;
            case '2': 
                generarCSV();
                break;
            case '3': 
                generarHTML();
                break;
            default: 
                error();
                break;
        }
        beforeLeaving();
    }
}

void imprimirEspecies(void){
    system("clear");
    printf("\nEsto es imprimir Especies\n");
    
}

void generarCSV(void){
    system("clear");
    printf("\nEsto es generar CSV\n");
}

void generarHTML(void){
    system("clear");
    printf("\nEsto es generar HTML\n");
}

void error(void){
    system("clear");
    printf("\nLa opción ingresada no es válida. Por favor, vuelva a intentarlo\n");
}

void finishMessage(void){
    system("clear");
    printf("\nMuchas gracias\n");
}

void beforeLeaving(void){
    printf("Press enter to continue\n");
    getchar();
    getchar();
    system("clear");
}