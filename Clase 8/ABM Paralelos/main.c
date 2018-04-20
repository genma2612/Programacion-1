#include <stdio.h>
#include <stdlib.h>
#define TAM 6

int buscarLibre(int[], int);
void mostrarAlumnos(int[], char[][20], int[], int[], float[], int);
float calcularPromedio(int, int);
int cargarAlumno(int[], char[][20], int[], int[], float[], int);

int main()
{
    int legajo[TAM]= {1,2,3,4,5};
    char nombre[TAM][20]= {"a","b","c","d","e"};
    int nota1[TAM]= {10,5,3,5,5};
    int nota2[TAM]= {10,2,8,4,2};
    float promedio[TAM];
    int opcion;
    int index;
    int i;
    for(i=0; i < TAM;i++)
    {
        promedio[i] = calcularPromedio(nota1[i], nota2[i]);
    }
    do
    {
        printf("1. ALTAS\n2. MOSTRAR\n3. MODIFICAR\n4. BAJA\n5. ORDENAR (por nombre)\n9. SALIR\nElija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:

            index=cargarAlumno(legajo, nombre, nota1, nota2, promedio, TAM);
            if(index == -1)
            {
                printf("No hay lugar\n");
            }
            else
            {
                printf("Alumno ingresado\n");
            }
            break;
        case 2:

        mostrarAlumnos(legajo, nombre, nota1, nota2, promedio, TAM);




        break;
        }

    }
    while(opcion!=9);




    return 0;
}

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

int cargarAlumno(int legajo[], char nombre[][20], int nota1[], int nota2[], float promedio[], int tam)
{
    int index ;
    index = buscarLibre(legajo, tam);
            if(index!=-1)
            {
                //Pedir datos
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
                    printf("Legajo: %d Nombre: %s Nota 1: %d  Nota 2: %d  Promedio: %.1f\n", legajos[i], nombres[i], nota1[i], nota2[i], promedio[i] );
                }

            }

}
