#include <stdio.h>
#include <stdlib.h>
#include "vectores.h"
#define TAM 5

int main()
{
    char vector[TAM] = {'a','b','c','d','e'};
    char aBuscar = 'd';
    int indexLetra;
    //cargarVector(vector, TAM);
    mostrarVectorChar(vector, TAM);
    indexLetra = buscarChar(vector, TAM, aBuscar);
    if(indexLetra == -1)
    {
        printf("\nNo se encuentra el char \"%c\" en el vector", aBuscar);
    }
    else
    {
        printf("\nSe encontro el char \"%c\" en el subindice %d.", aBuscar, indexLetra);
    }
    return 0;
}
