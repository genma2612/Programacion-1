#include <stdio.h>
#include <stdlib.h>
#include "vectores.h"
#define TAM 5

int main()
{
    int vector[TAM] = {-2,-4,3,6,-1};
    int cantPar;
    int cantPosi;
    //cargarVector(vector, TAM);
    mostrarVector(vector, TAM);
    cantPar = contarPares(vector, TAM);
    printf("La cantidad de numeros pares en el vector es: %d\n", cantPar);
    cantPosi = contarPositivos(vector, TAM);
    printf("La cantidad de numeros positivos en el vector es: %d\n", cantPosi);
    return 0;
}
