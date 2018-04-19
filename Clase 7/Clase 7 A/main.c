#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float calculoPromedio(int, int);

int main()
{
    int legajo[3];
    char nombre[3][30];
    int nota1[3];
    int nota2[3];
    float promedio[3];
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
    for(i=0; i < 3;i++)
    {
        printf("\nLegajo: %d\n", legajo[i]);
        printf("Nombre: %s\n", nombre[i]);
        printf("Nota 1: %d\n", nota1[i]);
        printf("Nota 2: %d\n", nota2[i]);
        printf("Promedio: %.1f\n", promedio[i]);
    }
    return 0;
}

float calculoPromedio(int n1, int n2)
{
    float promedio;
    promedio = (float)(n1 + n2) / 2;
    return promedio;
}
