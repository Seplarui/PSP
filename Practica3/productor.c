#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int fp;
    char cadena[50];
    fp = open("FIFO1", 1);

    if (fp == -1)
    {
        printf("Error al abrir el archivo\n");
        exit(1);
    }
    else
    {

       

        while (strcmp(cadena, ".") != 0)
        {
            printf("Introduzca una cadena\n");
            scanf("%s", cadena);
            write(fp, cadena, strlen(cadena));
        }
    }
    close(fp);

    return 0;
}
