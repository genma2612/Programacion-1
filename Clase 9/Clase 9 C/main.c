#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int legajo;
    char nombre[50];
    float promedio;
}eAlumno;

void mostrar(eAlumno unAlumno);
void mostrarListaAlumnos(eAlumno[], int);

int main()
{
    int i;
    eAlumno clase[5];

    for(i=0; i<5; i++)
    {
        printf("Ingrese legajo\n");
        scanf("%d", &clase[i].legajo);
        printf("Ingrese nombre\n");
        fflush(stdin);
        gets(clase[i].nombre);
        printf("Ingrese promedio\n");
        scanf("%f", &clase[i].promedio);
    }
    mostrarListaAlumnos(clase, 5);
    /*for(i=0; i<5; i++)
    {
        mostrar(clase[i]);
    }*/

    return 0;
}

void mostrar(eAlumno unAlumno)
{
    printf("%d | %s | %.1f\n",unAlumno.legajo, unAlumno.nombre, unAlumno.promedio);
}

void mostrarListaAlumnos(eAlumno clase[], int 5)
{
    int i;
    for(i=0; i<5; i++)
    {
        if(clase[i].estado != 0)
        {
            printf("Legajo: %d | %s | Promedio: \n", clase[i].legajo, clase[i].nombre, clase[i].promedio);
        }
    }
    printf("\n");
}

