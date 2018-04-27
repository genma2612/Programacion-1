#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define cant 5


typedef struct
{
    int legajo;
    char nombre[50];
    float promedio;
}eAlumno;

//void mostrar(eAlumno unAlumno); For para imprimir el array de estructura.
void mostrarListaAlumnos(eAlumno[], int); //Funcion para imprimir array de estructura.

int main()
{
    int i;
    eAlumno clase[cant];

    for(i=0; i<cant; i++)
    {
        printf("Ingrese legajo\n");
        scanf("%d", &clase[i].legajo);
        printf("Ingrese nombre\n");
        fflush(stdin);
        gets(clase[i].nombre);
        printf("Ingrese promedio\n");
        scanf("%f", &clase[i].promedio);
    }
    mostrarListaAlumnos(clase, cant);
    /*for(i=0; i<5; i++) For para imprimir el array de estructura.
    {
        mostrar(clase[i]);
    }*/

    return 0;
}

/*void mostrar(eAlumno unAlumno) For para imprimir el array de estructura.
{
    printf("%d | %s | %.1f\n",unAlumno.legajo, unAlumno.nombre, unAlumno.promedio);
}*/

void mostrarListaAlumnos(eAlumno clase[], int T)
{
    int i;
    for(i=0; i<T; i++)
    {
        if(clase[i].legajo != 0)
        {
            printf("Legajo: %d | %s | Promedio: %0.1f\n", clase[i].legajo, clase[i].nombre, clase[i].promedio);
        }
    }
    printf("\n");
}
