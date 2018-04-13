#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "vectores.h"

int main()
{
    char palabra1[15];
    char palabra2[15];
    char buffer[1024];
    int cant;
    int comp;
    printf("Ingrese una palabra\n");
    fflush(stdin);
    gets(buffer);
    while(strlen(buffer) > 14)              // Se crea un buffer con alto valor para validar luego la cantidad maxima de caracteres permitidos
    {
        printf("reingrese una palabra\n");
        fflush(stdin);
        gets(buffer);
    }
    cant = strlen(buffer); //Cuenta la cantidad de caracteres
    strcpy(palabra1, buffer);    //Una vez validado, se descarga el buffer a la palabra1.
    strcpy(palabra2, "GATO");
    //comp = strcmp(palabra1, palabra2); // (Gato != gato)
    comp = stricmp(palabra1, palabra2); //stricmp funciona entre minusculas y mayusculas (Gato = gato)
    strupr(palabra1); //convierte cadena a mayuscula.
    strlwr(palabra2); //convierte cadena a minuscula.

    strcat(buffer, palabra2);
    strcat(buffer, palabra1);

    printf("El resultado de la comparacion: %d\n", comp);
    printf("Cantidad de chars palabra1: %d\n", cant);
    printf("Palabra1: %s palabra2: %s\n", palabra1, palabra2);

    return 0;
}
