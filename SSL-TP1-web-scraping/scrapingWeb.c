#include <stdio.h>

FILE *popen(const char * command, const char *mode);
int pclose(FILE *stream);

int main(void){

    /* wget -q = silent mode */
    FILE *cmd = popen("wget -q -O - http://52.67.191.9/SSL/lideres-bcba.html --no-check-certificate","r");
    char result[1048576]; // 1 MB de buffer, ajustar segun implementacion

    while (fgets(result,sizeof(result),cmd) != NULL)
        printf("%s", result);
    pclose(cmd);
    return 0;
}