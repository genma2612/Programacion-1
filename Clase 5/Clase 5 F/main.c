#include <stdio.h>
#include <stdlib.h>
#include "vectores.h"
#define TAM 5

int main()
{
    int vector[TAM] = {};
    int valorMax;
    int indice;
    cargarVector(vector, TAM);
    modificarValor(vector);
    mostrarVector(vector, TAM);
    valorMax = buscarMaximo(vector, TAM);
    printf("El valor maximo guardado en el vector es: %d\n", valorMax);
    indice = buscarValor(vector, TAM, 14);
    if(indice == -1)
    {
        printf("No lo encontro\n");
    }
    else
    {
        printf("Encontro el valor\n");
    }
    printf("El indice esta en la posicion: %d\n", indice);
    return 0;
}
