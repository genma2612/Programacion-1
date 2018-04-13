#include <stdio.h>
#include <stdlib.h>
#include "vectores.h"
#define TAM 5

int main()
{
    char vector[TAM] = {'a','b','c','d','e'};
    char aBuscar = 'd';
    int retorno;
    //cargarVector(vector, TAM);
    mostrarVectorChar(vector, TAM);
    retorno = buscarChar(vector, TAM, aBuscar);
    if(retorno == -1)
    {
        printf("\nNo se encuentra el char \"%c\" en el vector", aBuscar);
    }
    else
    {
        printf("\nSe encontro el char \"%c\" en el subindice %d.", aBuscar, retorno);
    }
    return 0;
}
