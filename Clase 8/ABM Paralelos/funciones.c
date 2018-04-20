#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define TAM 6

int buscarLibre(int legajo[], int tam)
{
    int index=-1;
    int i;
    for(i=0; i < tam;i++)
    {
        if(legajo[i] == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

int buscarLegajo(int legajo[], int aBuscar)
{
    int index=-1;
    int i;
    for(i=0; i < TAM;i++)
    {
        if(legajo[i] == aBuscar)
        {
            index = i;
            break;
        }
    }
    return index;
}

int cargarAlumno(int legajo[], char nombre[][20], int nota1[], int nota2[], float promedio[], int tam)
{
    int index ;
    index = buscarLibre(legajo, tam);
            if(index!=-1)
            {
                printf("Ingrese legajo\n");
                scanf("%d", &legajo[index]);
                printf("Ingrese nombre\n");
                fflush(stdin);
                gets(nombre[index]);
                printf("Ingrese nota 1\n");
                scanf("%d", &nota1[index]);
                printf("Ingrese nota 2\n");
                scanf("%d", &nota2[index]);
                promedio[index] = calcularPromedio(nota1[index], nota2[index]);
            }
    return index;
}

void bajaAlumno(int legajo[], char nombre[][20], int nota1[], int nota2[], float promedio[], int indice)
{
    legajo[indice] = 0;
    strcpy(nombre[indice], " ");
    nota1[indice] = 0;
    nota2[indice] = 0;
    promedio[indice] = 0;
}

void modificarAlumno(char nuevoNombre[][20], int nuevaN1[], int nuevaN2[], float nuevoPromedio[], int indice)
{
    printf("Ingrese nuevo nombre\n");
    fflush(stdin);
    gets(nuevoNombre[indice]);
    printf("Ingrese nueva nota 1\n");
    scanf("%d", &nuevaN1[indice]);
    printf("Ingrese nueva nota 2\n");
    scanf("%d", &nuevaN2[indice]);
    nuevoPromedio[indice] = calcularPromedio(nuevaN1[indice], nuevaN2[indice]);
}


float calcularPromedio(int nota1, int nota2)
{
    float promedio;
    promedio = (float)(nota1+nota2)/2;
    return promedio;
}

void mostrarAlumnos(int legajos[], char nombres[][20], int nota1[], int nota2[], float promedio[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(legajos[i]!=0)
        {
            printf("Legajo: %d \nNombre: %s Nota 1: %d Nota 2: %d  Promedio: %.1f\n", legajos[i], nombres[i], nota1[i], nota2[i], promedio[i] );
        }

    }
}

void ordenarPorNombre(int legajo[], char nombre[][20], int nota1[], int nota2[], float promedio[])
{
    int i;
    int j;
    char auxNombre[20];
    int auxInt;
    float auxProm;
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





}
