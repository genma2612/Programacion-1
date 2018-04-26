#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int legajo;
    char nombre[50];
    float promedio;
}eAlumno;  //estructura define un tipo de dato (Como int, float, etc). eAlumno alumno1;

// void mostrar(int legajo[], char nombre[], float promedio[]); en Vectores paralelos
void mostrar(eAlumno unAlumno); //En estructuras

int main()
{
    eAlumno miAlumno = {1, "Juan", 7.5}; //tipo_de_dato variable_compuesta
    eAlumno otroAlumno;
    otroAlumno.legajo=2;
    strcpy(otroAlumno.nombre, "Maria");
    mostrar(miAlumno);
    mostrar(otroAlumno);
    //printf("%d | %s | %.1f\n",miAlumno.legajo, miAlumno.nombre, miAlumno.promedio);
    //printf("%d | %s | %.1f\n",otroAlumno.legajo, otroAlumno.nombre, otroAlumno.promedio);

    return 0;
}

void mostrar(eAlumno unAlumno)
{
    printf("%d | %s | %.1f\n",unAlumno.legajo, unAlumno.nombre, unAlumno.promedio);
}

