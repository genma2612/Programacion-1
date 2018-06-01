#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char nombre[50];
} ePersona;

//getters/setter

int ePersona_setId(ePersona*, int);
int ePersona_setNombre(ePersona*, char*);

int ePersona_getId(ePersona*);
char* ePersona_getNombre(ePersona*);

int main()
{
    //1 ePersona miPersona; //Borrar variables en "stack" para guardarlas en Heap
    ePersona* pPersona; //Al inicializarlo con Malloc, no hace falta inicializar el puntero en NULL.
    //2 printf("%p\n", pPersona); //puntero pPersona en stack.
    pPersona = (ePersona*) malloc(sizeof(ePersona)); //Pido memoria en Heap, en este caso, el peso de la estructura ePersona. Casteo al tipo de puntero necesario.
    if(pPersona!=NULL)
    {
        //3 pPersona->id=45;
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
        //3 strcpy(pPersona->nombre, "Juan");
        //printf("%d -- %s", pPersona->id, pPersona->nombre);
        }
    }
    //2 printf("%p\n", pPersona); //puntero pPersona en heap.
    //1 pPersona = &miPersona; //Borrar variables en "stack" para guardarlas en Heap
    return 0;
}

int ePersona_setId(ePersona* this, int idAAsignar) //this palabra reservada
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
