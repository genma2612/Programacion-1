#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    char calle[50];
    int numero;
    char localidad;
    int piso;
    char dpo;
    int cp;
} eDomicilio;

typedef struct //typed para no tener que escribir struct cada vez que llamemos a "elAlumno"
{
    int legajo;
    char nombre[50];

    /* */
    eDomicilio domicilio;

} eAlumno;

typedef struct
{
    int legajo;
    char nombre[50];
    eDomicilio domicilio;
} profesor;



int main()
{
    eAlumno miAlumno;
    miAlumno.legajo=400;
    miAlumno.domicilio.cp=1870;
    printf("legajo: %d -- CP: %d\n", miAlumno.legajo, miAlumno.domicilio.cp);
    return 0;
}
