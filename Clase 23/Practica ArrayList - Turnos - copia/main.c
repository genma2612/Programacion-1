#include <stdio.h>
#include <stdlib.h>

#include "ArrayList.h"
#include "turnos.h"
#include "tools.h"

int main()
{
    /*eTramite* t;
    t= new_Tramite();
    setId(t, 5);
    setDNI(t, "333333");

    mostrarTramite(t);*/

    char menu[] =
        "1-Tramite urgente.\
        \n2-Tramite regular.\
        \n3-Proximo cliente.\
        \n4-Listar pendientes.\
        \n5-Informar atendidos.\
        \n6-Salir.\
        \n";
    int auxiliar;
    int i;
    int len;
    int opcion;
    char dni[10];
    int ultimoIdTramiteUrgente=0;
    int ultimoIdTramiteRegular=0;
    eTramite* tramiteActual;

    //Creacion de arrayLists
    ArrayList* listaUrgente = al_newArrayList();
    ArrayList* atendidosUrgente = al_newArrayList();
    ArrayList* listaRegular = al_newArrayList();
    ArrayList* atendidosRegular = al_newArrayList();


    do
    {
        printf("%s", menu);
        opcion = ingresarIntValido("Ingrese una opcion: ", "ERROR! La opcion ingresada no es valida.\n", 1, 6);
        switch(opcion)
        {
        case 1:
            clearScreen();
            ultimoIdTramiteUrgente++;
            //tramiteActual = new_Tramite(); //no debe ir fuera de aca, ya que sino siempre apuntarà al mismo lugar (el ultimo cliente agregado)
            printf("Ingrese su DNI: ");
            fflush(stdin);
            gets(dni);
            cargarTramite(listaUrgente, ultimoIdTramiteUrgente, dni);
            //mensajeRetorno(auxiliar, "No quedan espacios disponibles\n", "Usuario dado de alta correctamente\n", "");
            break;
        case 2:
            clearScreen();
            ultimoIdTramiteRegular++;
            printf("Ingrese su DNI: ");
            fflush(stdin);
            gets(dni);
            cargarTramite(listaRegular, ultimoIdTramiteRegular, dni);
            //mensajeRetorno(auxiliar, "Error, la ID no se encuentra.\n", "Modificacion cancelada.\n", "Usuario modificado correctamente\n");
            break;
        case 3:
            if(!listaUrgente->isEmpty(listaUrgente))
            {
                printf("Cliente a ser atendido (urgente): ");
                atenderTramite(listaUrgente, atendidosUrgente);
            }
            else
            {
                if(!listaRegular->isEmpty(listaRegular))
                {
                    printf("Cliente a ser atendido (regular): ");
                    atenderTramite(listaRegular, atendidosRegular);
                }
                else
                {
                    printf("No hay cliente por atender.\n");
                }
            }
            break;
        case 4:
            clearScreen();
            if(!listaUrgente->isEmpty(listaUrgente))
            {
                printf("Urgentes:\n");
                mostrarListaTramites(listaUrgente);
            }
            if(!listaRegular->isEmpty(listaRegular))
            {
                printf("Regulares:\n");
                mostrarListaTramites(listaRegular);
            }
            pause();
            clearScreen();
            break;
        case 5:
            clearScreen();
            if(!atendidosUrgente->isEmpty(atendidosUrgente))
            {
                atendidosUrgente->sort(atendidosUrgente, compararPorDni, 0);
                printf("Urgentes:\n");
                mostrarListaTramites(atendidosUrgente);
            }
            if(!atendidosRegular->isEmpty(atendidosRegular))
            {
                atendidosRegular->sort(atendidosRegular, compararPorDni, 0);
                printf("Regulares:\n");
                mostrarListaTramites(atendidosRegular);
            }
            pause();
            clearScreen();
            //mensajeRetorno(auxiliar, "Egreso Cancelado\n","", "");
            break;
        case 6:
            break;
        }
    }
    while(opcion != 6);
    return 0;
}
