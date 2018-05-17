#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "egresos.h"
#define LIBRE 0
#define OCUPADO 1

int eEgreso_init(eEgreso egresos[])
{
    int retorno = -1;
    int i;
    if(100 > 0 && egresos != NULL)
    {
        retorno = 0;
        for(i=0; i<100; i++)
        {
            egresos[i].estado = LIBRE;
            egresos[i].marca = -1;
            egresos[i].importe = 0;
            egresos[i].idPropietario = -1;
        }
    }
    return retorno;
}

int eEgreso_HC(eEgreso egresos[])
{
    int marca[]= {1,1,2,3,2,2,3,4,1,1};
    float importe[] = {100,200,100,300,100,100,200,200,100,100};
    int propietario[] = {2,1,3,1,4,2,1,1,3,4};
    int retorno = -1;
    int i;
    if(100 > 0 && egresos != NULL)
    {
        retorno = 0;
        for(i=0; i<10; i++)
        {
            egresos[i].marca = marca[i];
            egresos[i].importe = importe[i];
            egresos[i].idPropietario = propietario[i];
            egresos[i].estado = OCUPADO;
        }
    }
    return retorno;
}
