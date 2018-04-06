#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

int main()
{
    int edad;       // Entre 18 y 60 años
    int legajo;     // Entre 1 y 1000
    int nota;       // Entre 1 y 10
    edad = pedirEntero("Ingrese edad: \n", 18, 60);
    legajo = pedirEntero("Ingrese legajo: \n", 1, 1000);
    nota = pedirEntero("Ingrese nota: \n", 1, 10);
    printf("La edad es: %d \nEl legajo es: %d \nLa nota es: %d", edad,legajo,nota);
    return 0;
}
