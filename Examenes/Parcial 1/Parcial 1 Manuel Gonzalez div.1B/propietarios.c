#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "propietarios.h"

#define LIBRE 0
#define OCUPADO 1
#define CANT_PROPIETARIOS 20

int ePro_init(ePropietarios listado[])
{
    int retorno = -1;
    int i;
    if(CANT_PROPIETARIOS > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<CANT_PROPIETARIOS; i++)
        {
            listado[i].estado = LIBRE;
            listado[i].idPropietario = 0;
        }
    }
    return retorno;
}

int ePro_HC(ePropietarios listado[])
{
    char nombre[][20]= {"Juan","Luis","Maria","Jose"};
    char apellido[][20]= {"perez","dasse","gomez","garcia"};
    char direccion[][20]= {"mitre","urquiza","belgrano","alsina"};
    char tarjeta[][20]= {"111-111","222-222","333-333","444-444"};
    int id[]= {1,2,3,4};
    int retorno = -1;
    int i;
    if(CANT_PROPIETARIOS > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<4; i++)
        {
            strcpy(listado[i].nombre, nombre[i]);
            strcpy(listado[i].apellido, apellido[i]);
            strcpy(listado[i].direccion, direccion[i]);
            strcpy(listado[i].tarjeta, tarjeta[i]);
            listado[i].idPropietario = id[i];
            listado[i].estado = OCUPADO;
        }
    }
    return retorno;
}
