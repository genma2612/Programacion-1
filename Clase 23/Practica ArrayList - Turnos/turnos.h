#include <stdio.h>
#include <stdlib.h>
#include "tools.h"
#include "ArrayList.h"

typedef struct
{
    char nombre[20];
    int dni;
    int estado;
}eTurno;

void nuevoTurno(ArrayList* tramite, eTurno* this);

void turnosHC(ArrayList* regular, ArrayList* urgente, eTurno* this);

void turnoPrint(eTurno* this);

void listar(ArrayList*, ArrayList*);

void setNombre(eTurno* this);

void setDNI(eTurno* this);
