#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 3

void mostrarDatos(int[], char[][30], int[], int[], float[]);
float calcularPromedio(int, int);

int main()
{
    int legajo[TAM]={11,33,22};
    char nombre[TAM][30]={"Ximena","Alan","Pepe"};
    int nota1[TAM]={6, 8, 10};
    int nota2[TAM]={2, 8, 8};
    float promedio[TAM];
    float auxProm;
    int auxInt;
    char auxNombre[30];
    int i;
    int j;
    for(i=0; i < 3;i++)
    {
        promedio[i] = calcularPromedio(nota1[i], nota2[i]);
    }
    for(i=0;i<TAM-1; i++)
    {
        for(j=i+1; j<TAM; j++)
        {
            if(stricmp(nombre[i], nombre[j]) > 0)
            {
                strcpy(auxNombre, nombre[i]);
                strcpy(nombre[i], nombre[j]);
                strcpy(nombre[j], auxNombre);

                auxInt = legajo[i];
                legajo[i] = legajo[j];
                legajo[j] = auxInt;

                auxInt = nota1[i];
                nota1[i] = nota1[j];
                nota1[j] = auxInt;

                auxInt = nota2[i];
                nota2[i] = nota2[j];
                nota2[j] = auxInt;

                auxProm = promedio[i];
                promedio[i] = promedio[j];
                promedio[j] = auxProm;
            }
        }
    }
    printf("Datos ingresados\n");
    mostrarDatos(legajo, nombre, nota1, nota2, promedio);
    return 0;
}

float calcularPromedio(int n1, int n2)
{
    float prom;
    prom = (float)(n1+n2)/2;
    return prom;
}

void mostrarDatos(int legajo[], char nombre[][30], int n1[], int n2[], float promedio[])
{
    int i;
    for(i=0; i < TAM;i++)
    {
        printf("\nLegajo: %d\n", legajo[i]);
        printf("Nombre: %s\n", nombre[i]);
        printf("Nota 1: %d\n", n1[i]);
        printf("Nota 2: %d\n", n2[i]);
        printf("Promedio: %.1f\n", promedio[i]);
    }
}


