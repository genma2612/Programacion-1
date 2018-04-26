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

int main()
{
    eAlumno miAlumno = {1, "Juan", 7.5};
    eAlumno otroAlumno;

    printf("Ingrese legajo\n");
    scanf("%d", &otroAlumno.legajo);
    printf("Ingrese nombre\n");
    fflush(stdin);
    gets(otroAlumno.nombre);
    printf("Ingrese promedio\n");
    scanf("%f", &otroAlumno.promedio);

    //otroAlumno = miAlumno; // Las estructuras se pueden asignar entre si.
    mostrar(miAlumno);
    mostrar(otroAlumno);

    return 0;
}

void mostrar(eAlumno unAlumno)
{
    printf("%d | %s | %.1f\n",unAlumno.legajo, unAlumno.nombre, unAlumno.promedio);
}

