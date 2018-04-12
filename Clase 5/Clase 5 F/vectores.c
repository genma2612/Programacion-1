#include <stdio.h>
#include "vectores.h"

void mostrarVector(int vec[], int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("%d\n", vec[i]);
    }
}

void modificarValor(int vec[]) // Muestra de como el valor del vector es el mismo en la funcion y en el main.
{
    vec[3] = 799;
}

int buscarMaximo(int vec[], int tamano)
{
    int i;
    int max;
    int flag=1;
    for(i=0;i<tamano;i++)
    {
        if(vec[i] > max || flag == 1)
        {
            max = vec[i];
            flag = 0;
        }
    }
    return max;
}

void cargarVector(int vec[], int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("Ingrese un numero: \n");
        scanf("%d", &vec[i]);
    }
}

int buscarValor(int vec[], int tamano, int valor)
{
    int index = -1;
    int i;
    for(i=0;i<tamano;i++)
    {
        if(valor == vec[i]) //Else dentro de for no es una buena practica.
            index = i;
            break;
    }
    return index;
}
