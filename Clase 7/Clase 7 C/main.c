#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float calculoPromedio(int, int);
void mostrarDatos(int[], char[][30], int[], int[], float[]);
int buscarLegajo(int[], int, int);

int main()
{
    int legajo[3];
    char nombre[3][30];
    int nota1[3];
    int nota2[3];
    float promedio[3];
    int aBuscar;
    int i;
    for(i=0; i < 3;i++)
    {
        printf("Ingrese legajo\n");
        scanf("%d", &legajo[i]);
        printf("Ingrese nombre\n");
        fflush(stdin);
        gets(nombre[i]);
        printf("Ingrese nota 1\n");
        scanf("%d", &nota1[i]);
        printf("Ingrese nota 2\n");
        scanf("%d", &nota2[i]);
        promedio[i] = calculoPromedio(nota1[i], nota2[i]);
    }
    printf("\nDatos ingresados\n");
    mostrarDatos(legajo, nombre, nota1, nota2, promedio);
    aBuscar = buscarLegajo(legajo, 3, 22);
    if(aBuscar > -1)
    {
        printf("\nSe encontro el legajo en el subindice %d\n", aBuscar);
    }
    else
    {
        printf("\nEl numero de legajo no se encuentra en el sistema\n");
    }
    return 0;
}

float calculoPromedio(int n1, int n2)
{
    float promedio;
    promedio = (float)(n1 + n2) / 2;
    return promedio;
}

void mostrarDatos(int legajo[], char nombre[][30], int n1[], int n2[], float promedio[])
{
    int i;
    for(i=0; i < 3;i++)
    {
        printf("\nLegajo: %d\n", legajo[i]);
        printf("Nombre: %s\n", nombre[i]);
        printf("Nota 1: %d\n", n1[i]);
        printf("Nota 2: %d\n", n2[i]);
        printf("Promedio: %.1f\n", promedio[i]);
    }
}

int buscarLegajo(int legajo[], int size, int aBuscar)
{
    int index = -1;
    int i;
    for(i=0; i < size;i++)
    {
        if(legajo[i] == aBuscar)
        {
            index = i;
            break;
        }
    }
    return index;
}

