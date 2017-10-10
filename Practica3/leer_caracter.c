#include <stdio.h>

main()
{
    char nombre[20];
    printf("Introduzca una cadena\n");
    scanf("%s", nombre);

    printf("La cadena introducida es: %s\n", nombre);

    if (strcmp(nombre, "hola")==0) {
        printf("Has introducido hola");
    } else {
        printf ("NO has introducido hola");
    }

}