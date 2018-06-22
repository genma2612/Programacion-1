#include <stdio.h>
#include <stdlib.h>
#include "tools.h"
#include "ArrayList.h"

typedef struct
{
    char dni[10];
    int idTramite;
}eTramite;

eTramite* new_Tramite();

int setId(eTramite* this, int);

int getId(eTramite*);

int setDNI(eTramite* this, char* dni);

char* getDni(eTramite* this);

int mostrarTramite(eTramite* this);

int compararPorDni(void* tramiteA, void* tramiteB);

int mostrarListaTramites(ArrayList* this);

int cargarTramite(ArrayList* this, int id, char*);

int atenderTramite(ArrayList*, ArrayList*);
