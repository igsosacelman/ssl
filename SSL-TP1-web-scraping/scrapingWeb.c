#include <stdio.h>

FILE *popen(const char * command, const char *mode);
int pclose(FILE *stream);
void saveScrappedWebInFile(FILE* read,FILE* write,char* buffer);
void closeFilePointer(FILE* read,FILE* write);

int main(void){

    FILE *cmd = popen("wget -q -O - http://52.67.191.9/SSL/lideres-bcba.html --no-check-certificate","r");
    FILE *pFileScrappedWeb = fopen("scrappedWeb.txt","w");
    char result[1048576]; // 1 MB de buffer, ajustar segun implementacion
    
    if(cmd == NULL || pFileScrappedWeb == NULL) {
        printf("Error al intentar abrir el archivo.\n");
        return 1;
    }

    saveScrappedWebInFile(cmd,pFileScrappedWeb,result);
    closeFilePointer(cmd,pFileScrappedWeb);

    return 0;
}

void saveScrappedWebInFile(FILE* read,FILE* write,char* buffer){
    while (fgets(buffer,sizeof(buffer),read) != NULL) {
        fprintf(write,"%s",buffer);
    }
}

void closeFilePointer(FILE* read,FILE* write){
    fclose(read);
    pclose(write);
}