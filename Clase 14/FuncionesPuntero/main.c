#include <stdio.h>
#include <stdlib.h>

void intercambiar(int num1, int num2);
void intercambiarConPuntero(int *num1, int *num2);
void ponerEnCero(int *num1);

int main()
{
    int edadUno;
    int edadDos;
    edadUno=22;
    edadDos=99;
    ponerEnCero(&edadUno);
    //intercambiar(edadUno, edadDos); Pasajes por valor. La funcion no modifica el resultado
    intercambiarConPuntero(&edadUno, &edadDos);
    printf("\nedad 1: %d",edadUno);
    printf("\nedad 2: %d",edadDos);
    return 0;
}

void ponerEnCero(int *num1)
{
    *num1 = 0;
}

void intercambiar(int num1, int num2)
{
    int aux;
    aux = num1;
    num1 = num2;
    num2 = aux;
}

void intercambiarConPuntero(int *num1, int *num2)
{
    int aux;
    aux = *num1;
    *num1 = *num2;
    *num2 = aux;
}
