#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char nombre[50];
} ePersona;

int ePersona_setId(ePersona*, int);
int ePersona_setNombre(ePersona*, char*);
int ePersona_getId(ePersona*);
char* ePersona_getNombre(ePersona*);

// Funcion constructor


ePersona* newPersona();


int main()
{

    ePersona* pPersona; //Al inicializarlo con Malloc, no hace falta inicializar el puntero en NULL.

    /// ePersona* newPersona(); ///

    pPersona = (ePersona*) malloc(sizeof(ePersona)); //Pido memoria en Heap, en este caso, el peso de la estructura ePersona. Casteo al tipo de puntero necesario.
    if(pPersona!=NULL)
    {
        if(ePersona_setId(pPersona, 45)==-1)
        {
            printf("ERROR, ID NEGATIVO!!\n");
        }
        else
        {
            if(ePersona_setNombre(pPersona, "Jose")==-1)
            {
                printf("NOMBRE INCORRECTO!!\n");
            }
            else
            {
                printf("%d -- %s", ePersona_getId(pPersona), ePersona_getNombre(pPersona));
            }
        }
    }
    return 0;
}

int ePersona_setId(ePersona* this, int idAAsignar)
{
    int retorno=-1;
    if(this!=NULL && idAAsignar>0)
    {
        retorno=1;
        this->id = idAAsignar;
    }
    return retorno;
}

int ePersona_setNombre(ePersona* this, char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL && (strlen(nombre)>3))
    {
        retorno=1;
        strcpy(this->nombre, nombre);
    }
    return retorno;
}

int ePersona_getId(ePersona* this)
{
    int retorno=-1;
    if(this!=NULL)
    {
        return this->id;
    }
    return retorno;
}

char* ePersona_getNombre(ePersona* this)
{
    char* retorno= NULL;
    if(this!=NULL)
    {
        retorno = this->nombre;
    }
    return retorno;
}

ePersona* newPersona()
{
    ePersona* persona;
    persona = (ePersona*) malloc(sizeof(ePersona));
    return persona;
}