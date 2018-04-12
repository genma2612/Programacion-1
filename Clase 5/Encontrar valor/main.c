#include <stdio.h>
#include <stdlib.h>
#include "vectores.h"
#define TAM 5

int main()
{
    int vector[TAM] = {};
    int indice;
    cargarVector(vector, TAM);
    mostrarVector(vector, TAM);
    indice = buscarValor(vector, TAM, 14);
    if(indice == -1)
    {
        printf("No lo encontro\n");
    }
    else
    {
        printf("Encontro el valor.\n");
    }
    printf("El indice esta en la posicion: %d.\n", indice);
    return 0;
}
