#include <stdio.h>
#include <stdlib.h>
#include "vectores.h"
#define TAM 5

int main()
{
    int vector[TAM] = {-2,-4,3,6,-1};
    int contPar;
    int contPosi;
    //cargarVector(vector, TAM);
    mostrarVector(vector, TAM);
    contPar = contarPares(vector, TAM);
    printf("La cantidad de numeros pares en el vector es: %d\n", contPar);
    contPosi = contarPositivos(vector, TAM);
    printf("La cantidad de numeros positivos en el vector es: %d\n", contPosi);
    return 0;
}
