#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "turnos.h"
#include "tools.h"

void nuevoTurno(ArrayList* tramite, eTurno* this)
{
    int indice = buscarIndiceLibre(this);
    setNombre((this+indice));
    setDNI((this+indice));
    (this+indice)->estado = 1;
    al_add(tramite, (this+indice));
}

int buscarIndiceLibre(eTurno* this)
{
    int i;
    int retorno=-1;
    if(this!=NULL)
    {
        for(i=0;i<20;i++)
        {
            if((this+i)->estado == 0)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

void setNombre(eTurno* this)
{
    if(this!=NULL)
    {
        ingresarStringValida("Ingrese el nombre:\n", "Error\n", "Muy largo\n", this->nombre, 30);
    }
}

void setDNI(eTurno* this)
{
    if(this!=NULL)
    {
        this->dni = ingresarIntValido("Ingrese el DNI\n", "Error\n", 1111, 999999999);
    }
}

void turnosHC(ArrayList* urgente, ArrayList* regular, eTurno* this)
{
    int i;
    int dni[6]= {4444,1111,6666,3333,5555,2222};
    char nombre[][30]= {"pepe","luis","mario","laura","pedro","micaela"};
    for(i=0; i<20; i++)
    {
        (this+i)->estado = 0;
        if(i<6)
        {
            (this+i)->dni = dni[i];
            strcpy((this+i)->nombre, nombre[i]);
            (this+i)->estado = 1;
            if(i<3)
            {
                al_add(urgente, (this+i));
            }
            else
            {
                al_add(regular, (this+i));
            }
        }
    }
}

void turnoPrint(eTurno* this)
{
    printf("%-15s %d\n", this->nombre, this->dni);
}

void listar(ArrayList* listaUrgente, ArrayList* listaRegular)
{
    eTurno* aux;
    int i;
    int size = al_len(listaUrgente);
    printf("Urgentes: %d\n", al_len(listaUrgente));
    printf("NOMBRE           DNI\n");
    for(i=0; i<size; i++)
    {
        aux = (eTurno*) al_get(listaUrgente, i);
        turnoPrint(aux);
    }
    size = al_len(listaRegular);
    printf("\nRegulares: %d\n", al_len(listaRegular));
    printf("NOMBRE           DNI\n");
    for(i=0; i<size; i++)
    {
        aux = (eTurno*) al_get(listaRegular, i);
        turnoPrint(aux);
    }
    pause();
    clearScreen();
}
