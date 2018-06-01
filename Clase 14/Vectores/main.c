#include <stdio.h>
#include <stdlib.h>
void mostrar(int *puntero, int cantidad);

int main()
{
    int numeros[3];
    int *puntero;
    int auxiliar=333;
    puntero = numeros;


    numeros[0]=9;
    numeros[1]=99;
    numeros[2]=999;
    printf("Puntero: %d\n", *(puntero-2));
    printf("Puntero: %d\n", *(puntero+1));
    printf("Puntero: %d\n", *(puntero+2));
    printf("Puntero: %d\n", *(puntero+3));
    printf("Puntero: %d\n", *(puntero+4));

    printf("Puntero: %d\n", numeros);


    mostrar(numeros, 3);


    return 0;
}


void mostrar(int *puntero, int cantidad)
{
    int i;
    for(i=0;i<cantidad;i++)
    {
       printf("El numero es: %d\n",*(puntero + i)); //Algebra de punteros
    }

}
