#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "turnos.h"


eTurno* nuevoTurno()
{
    eTurno* turno;
    turno = (eTurno*) malloc(sizeof(eTurno));
    return turno;
}

void turnosHC(ArrayList* regular, ArrayList* urgente, eTurno* this)
{
    int i;
    int dni[6]= {1111,2222,3333,4444,5555,6666};
    char nombre[][30]= {"pepe","luis","mario","laura","pedro","micaela"};
    for(i=0; i<6; i++)
    {
        (this+i)->dni = dni[i];
        strcpy((this+i)->nombre, nombre[i]);
        if(i<3)
        {
            al_add(regular, (this+i));
        }
        else
        {
            al_add(urgente, (this+i));
        }
    }
}

void turnoPrint(eTurno* this)
{
    printf("%s.   %d.\n", this->nombre, this->dni);
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
    printf("Regulares: %d\n", al_len(listaRegular));
    printf("NOMBRE           DNI\n");
    for(i=0; i<size; i++)
    {
        aux = (eTurno*) al_get(listaRegular, i);
        turnoPrint(aux);
    }
}
