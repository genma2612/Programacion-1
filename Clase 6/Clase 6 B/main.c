#include <stdio.h>
#include <stdlib.h>
#include "vectores.h"

int main()
{
    //For's anidados.
    int vector[5]={10,1,33,-5,2};
    int auxiliar;
    int i;
    int j;
    //Ordenar de menor a mayor i > j
    for(i=0; i<4; i++) // "mano amarilla" llega hasta la anteultima posicion. i<4
    {
        for(j = i+1; j<5; j++) //"mano celeste" llega hasta la ultima posicion. j<5
        {
            if(vector[i] > vector[j]) // > ordena de menor a mayor. < de mayor a menor.
            {
                auxiliar = vector[i];
                vector[i] = vector[j];
                vector[j] = auxiliar;
            }
        }
    }
    mostrarVector(vector, 5);
    return 0;
}
