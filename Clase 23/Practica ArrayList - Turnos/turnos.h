#include <stdio.h>
#include <stdlib.h>

#include "ArrayList.h"

typedef struct
{
    char nombre[20];
    int dni;
}eTurno;

eTurno* nuevoTurno();

void turnosHC(ArrayList* regular, ArrayList* urgente, eTurno* this);

void turnoPrint(eTurno* this);

void listar(ArrayList*, ArrayList*);
