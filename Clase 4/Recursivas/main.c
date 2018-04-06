#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

// Factorial no recursivo.

int main()
{
    int numero;
    int i;
    int factor = 1;
    numero = pedirEntero("Ingrese un numero ", 1, 1000);
    for(i = numero; i > 0; i--)
    {
        factor = factor * i;
    }
    printf("El factorial es: %d", factor);
    return 0;
}
