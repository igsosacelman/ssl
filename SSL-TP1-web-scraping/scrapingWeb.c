#include <stdio.h>

FILE *popen(const char * command, const char *mode);
int pclose(FILE *stream);

int main(void){

    /* wget -q = silent mode */
    FILE *cmd = popen("wget -q -O - http://52.67.191.9/SSL/lideres-bcba.html --no-check-certificate","r");
    FILE* pFileScrappedWeb;
    char result[1048576]; // 1 MB de buffer, ajustar segun implementacion
    /*
    while (fgets(result,sizeof(result),cmd) != NULL)
        printf("%s", result);
    */
    pFileScrappedWeb = fopen("scrappedWeb.txt","w");
    
    if(pFileScrappedWeb == NULL) {
        printf("Error al intentar abrir el archivo.\n");
        return -1;
    }

    while (fgets(result,sizeof(result),cmd) != NULL) {
        fprintf(pFileScrappedWeb,"%s",result);
    }

    fclose(pFileScrappedWeb);
    pclose(cmd);
    
    return 0;
}