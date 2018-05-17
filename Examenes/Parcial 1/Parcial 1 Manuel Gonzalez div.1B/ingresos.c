#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ingresos.h"
#define CANT_PROPIETARIOS 20
#define LIBRE 0
#define OCUPADO 1

int eIngreso_init(eIngreso ingresos[])
{
    int retorno = -1;
    int i;
    if(100 > 0 && ingresos != NULL)
    {
        retorno = 0;
        for(i=0; i<100; i++)
        {
            ingresos[i].estado = LIBRE;
            ingresos[i].marca = -1;
            ingresos[i].idIngreso = -1;
            ingresos[i].idPropietario = -1;
        }
    }
    return retorno;
}

int eIngreso_HC(eIngreso ingresos[])
{
    char patente[][20]= {"AAA","CCC","DDD","BBB","ZZZ","III","HHH","EEE","FFF","GGG"};
    int id[]= {1,2,3,4,5,6,7,8,9,10};
    int marca[]= {1,3,3,2,2,3,3,4,3,1};
    int propietario[]= {2,1,2,1,3,3,4,1,4,3};
    int retorno = -1;
    int i;
    if(100 > 0 && ingresos != NULL)
    {
        retorno = 0;
        for(i=0; i<10; i++)
        {
            strcpy(ingresos[i].patente, patente[i]);
            ingresos[i].idIngreso = id[i];
            ingresos[i].marca = marca[i];
            ingresos[i].idPropietario = propietario[i];
            ingresos[i].estado = OCUPADO;
        }
    }
    return retorno;
}
