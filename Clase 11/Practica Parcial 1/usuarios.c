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
    char nombres[10][50]={"Pedro","Juan","Luis","Maria","Andrea","Manuel","Pablo","Laura","German","Jesica"};
    char usuarios[10][20]={"Pedro92","Juancho19","LuisPerez2","Mary2017","andre15","manu_rojo04","nbgyjn","lg_f92","germ17","jessycat"};
    int ids[10]={0,1,2,3,4,5,6,7,8,9};
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<10; i++)
        {
            strcpy(listado[i].nombre, nombres[i]);
            strcpy(listado[i].usuario, usuarios[i]);
            listado[i].id = ids[i];
            listado[i].estado = OCUPADO;
        }
    }
    return retorno;
}

int eUsu_alta(eUsuarios listado[],int limite)
{
    int retorno = -1;
    char nombre[50];
    int id;
    int indice;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        indice = eUsu_buscarLugarLibre(listado,limite);
        if(indice >= 0)
        {
            retorno = -3;
            id = eUsu_siguienteId(listado,limite);
            //En parcial, utilizar funciones para el ingreso de datos
            retorno = 0;
            printf("Ingrese nombre:\n");
            fflush(stdin);
            gets(listado[indice].nombre);
            printf("Ingrese usuario:\n");
            fflush(stdin);
            gets(listado[indice].usuario);
            listado[indice].id = id;
            listado[indice].estado = OCUPADO;
        }
    }
    return retorno;
}

int eUsu_buscarLugarLibre(eUsuarios listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eUsu_siguienteId(eUsuarios listado[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO)
            {
                    if(listado[i].id>retorno)
                    {
                         retorno=listado[i].id;
                    }

            }
        }
    }

    return retorno+1;
}
