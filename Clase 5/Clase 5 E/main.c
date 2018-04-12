#include <stdio.h>
#include <stdlib.h>
#include "vectores.h"
#define TAM 5

int main()
{
    int vector[TAM] = {};
    int valorMax;
    cargarVector(vector, TAM);
    modificarValor(vector);
    mostrarVector(vector, TAM);
    valorMax = buscarMaximo(vector, TAM);
    printf("El valor maximo guardado en el vector es: %d\n", valorMax);
    return 0;
}
