#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuarios.h"

#define LIBRE 0
#define OCUPADO 1

int eUsu_init(eUsuarios listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado = LIBRE;
            listado[i].id = 0;
        }
    }
    return retorno;
}

int eUsu_HC(eUsuarios listado[], int limite)
{
    char nombre[][20]= {"Pedro","Juan","Luis","Maria","Andrea"};
    char apellido[][20]= {"perez","dasse","gomez","garcia","fernandez"};
    char usuarios[][20]= {"Pedro92","Juancho19","LuisPerez2","Mary2017","andre15"};
    char password[][20]= {"123456", "contraseña22", "passsecreta", "secretpassword", "1111"};
    char telefono[][10]= {"1111-1111","2222-2222","3333-3333","4444-4444","5555-5555"};
    int ids[5]= {0,1,2,3,4};
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<5; i++)
        {
            strcpy(listado[i].nombre, nombre[i]);
            strcpy(listado[i].apellido, apellido[i]);
            strcpy(listado[i].usuario, usuarios[i]);
            strcpy(listado[i].password, password[i]);
            strcpy(listado[i].telefono, telefono[i]);
            listado[i].id = ids[i];
            listado[i].estado = OCUPADO;
        }
    }
    return retorno;
}
