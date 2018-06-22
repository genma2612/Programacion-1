#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "turnos.h"
#include "tools.h"

eTramite* new_Tramite()
{
    eTramite* aux;
    aux = (eTramite*) malloc(sizeof(eTramite));
}

int setId(eTramite* this, int id)
{
    int retorno=-1;
    if(this != NULL)
    {
        this->idTramite = id;
        retorno = 0;
    }
    return retorno;
}

int getId(eTramite* this)
{
    int id=-1;
    if(this != NULL)
    {
        id = this->idTramite;
    }
    return id;
}

int setDNI(eTramite* this, char* dni)
{
    int retorno=-1;
    if(this != NULL && dni != NULL)
    {
        strcpy(this->dni, dni);
        retorno = 0;
    }
    return retorno;
}

char* getDni(eTramite* this)
{
    char* dni=NULL;
    if(this != NULL)
    {
        dni = this->dni;
    }
    return dni;
}

int mostrarTramite(eTramite* this)
{
    int retorno=-1;
    if(this != NULL)
    {
        printf("%d--%s\n", getId(this), getDni(this));
        retorno = 0;
    }
    return retorno;
}

int compararPorDni(void* tramiteA, void* tramiteB)
{
    eTramite* tramite1;
    eTramite* tramite2;
    tramite1 = (eTramite*) tramiteA;
    tramite2 = (eTramite*) tramiteB;
    return strcasecmp(tramite1->dni, tramite2->dni);
}

int mostrarListaTramites(ArrayList* this)
{
    int i;
    int len = this->len(this);
    int listo = -1;
    eTramite* tramiteActual;
    if(this != NULL)
    {
        for(i=0; i<len; i++)
        {
            tramiteActual = (eTramite*) this->get(this, i);
            mostrarTramite(tramiteActual);
        }
        listo = 0;
    }
    return listo;
}

int cargarTramite(ArrayList* this, int id, char* dni)
{
    int cargo=-1;
    eTramite* tramiteActual;
    if(this != NULL && dni != NULL && id > 0)
    {
        tramiteActual = new_Tramite();
        setId(tramiteActual, id);
        setDNI(tramiteActual, dni);
        this->add(this, tramiteActual);
        cargo = 0;
    }
    return cargo;
}

int atenderTramite(ArrayList* listaPendientes, ArrayList* listaAtendidos)
{
    int retorno=-1;
    eTramite* tramiteActual;
    if(listaPendientes != NULL && listaAtendidos != NULL)
    {
        tramiteActual = (eTramite*) listaPendientes->pop(listaPendientes, 0);
        listaAtendidos->add(listaAtendidos, tramiteActual);
        mostrarTramite(tramiteActual);
        retorno = 0;
    }
    return retorno;
}
