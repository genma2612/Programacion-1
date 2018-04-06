#include <stdio.h>
#include "Funciones.h"

int pedirEntero(char mensaje[], int min, int max)
{
    int numero;
    printf("%s", mensaje); //%s es para cadena (Vector de characters).
    scanf("%d", &numero);
    numero = validarEntero(numero, min, max, mensaje);
    return numero;
}

int validarEntero(int dato, int min, int max, char mensaje[])
{
        while(dato < min || dato > max)
    {
        printf("Error! %s", mensaje);
        scanf("%d", &dato);
        return dato;
    }
}
