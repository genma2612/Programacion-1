#include <stdio.h>
#include <stdlib.h>
#define TAM 10 //asigna 5 a la palabra TAM en el c�digo.


int main()
{
    int vector[TAM] = {};
    int const T = 10; //constante guardada en memoria. Cada aparici�n de T ser� reemplazada por 5.
    int i;

    for(i=0;i<TAM;i++)
    {
        printf("Ingrese un numero: \n");
        scanf("%d", &vector[i]);
    }

    for(i=0;i<T;i++)
    {
        printf("%d\n", vector[i]);
    }


    return 0;
}
