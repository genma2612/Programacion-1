#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define TAM 6

int main()
{
    int legajo[TAM]= {1,2,3,4,5};
    char nombre[TAM][20]= {"Luis","Jose","Ana","Maria","Pedro"};
    int nota1[TAM]= {10,5,3,5,5};
    int nota2[TAM]= {10,2,8,4,2};
    float promedio[TAM];
    int opcion;
    int index;
    int retornoBuscador;
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

        case 3:
            printf("Ingrese el numero de legajo a modificar\n");
            scanf("%d", &index);
            retornoBuscador = buscarLegajo(legajo, index);
            if(retornoBuscador > -1)
            {
                modificarAlumno(nombre, nota1, nota2, promedio, retornoBuscador);
                printf("Los datos del legajo %d fueron modificados correctamente\n", index);
            }
            else
            {
                printf("No se encontro el legajo ingresado\n");
            }
        break;
        case 4:
            printf("Ingrese el numero de legajo a dar de baja\n");
            scanf("%d", &index);
            retornoBuscador = buscarLegajo(legajo, index);
            if(retornoBuscador > -1)
            {
                bajaAlumno(legajo, nombre, nota1, nota2, promedio, retornoBuscador);
                printf("El legajo %d fue dado de baja correctamente\n", index);
            }
            else
            {
                printf("No se encontro el legajo ingresado\n");
            }
        break;
        case 5:
            ordenarPorNombre(legajo, nombre, nota1, nota2, promedio);
            printf("Alumnos ordenados por nombre\n");
        break;
        }
    }
    while(opcion!=9);
    return 0;
}
