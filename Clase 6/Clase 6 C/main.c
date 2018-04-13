#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vectores.h"

int main()
{
    //char palabra[15]="hola"; //puede guardar 14 + \0. Se puede asignar "hola" sòlo al momento de declarar la variable.
    // palabra = "hola" Esto no asigna nada.
    char palabra1[15];
    char palabra2[15];
    int i;
    printf("Ingrese una palabra\n");
    //scanf("%s", palabra); //Es lo mismo que &palabra. interpreta el "espacio" como un \0
    fflush(stdin); // limpia el buffer antes de una cadena de caracteres. Es necesaria siempre de manera preventiva.
    gets(palabra1); //Permite ingresar espacios entre palabras.
    //strcpy("destino", "origen"); //
    strcpy(palabra2, palabra1);
    printf("Palabra1: %s palabra2: %s\n", palabra1, palabra2);



    return 0;
}
