#include <stdio.h>
#include <stdlib.h>

#include "ArrayList.h"
#include "turnos.h"
#include "tools.h"

int main()
{
    char menu[] =
        "1-Tramite urgente.\
        \n2-Tramite regular.\
        \n3-Proximo cliente.\
        \n4-Listar.\
        \n5-Informar.\
        \n6-Salir.\
        \n";
    int auxiliar;
    int opcion;

    //Creacion de arrayLists
    ArrayList* listaUrgente = al_newArrayList();
    ArrayList* listaRegular = al_newArrayList();
    //turnos
    eTurno* turnos;
    turnos = (eTurno*) malloc(sizeof(eTurno)*20);
    turnosHC(listaRegular, listaUrgente, turnos);

    do
    {
        printf("%s", menu);
        opcion = ingresarIntValido("Ingrese una opcion: ", "ERROR! La opcion ingresada no es valida.\n", 1, 6);
        switch(opcion)
        {
        case 1:
            clearScreen();
            nuevoTurno(listaUrgente, turnos);
            //mensajeRetorno(auxiliar, "No quedan espacios disponibles\n", "Usuario dado de alta correctamente\n", "");
            break;
        case 2:
            clearScreen();
            nuevoTurno(listaRegular, turnos);
            //mensajeRetorno(auxiliar, "Error, la ID no se encuentra.\n", "Modificacion cancelada.\n", "Usuario modificado correctamente\n");
            break;
        case 3:

            break;
        case 4:
            clearScreen();
            listar(listaUrgente, listaRegular);
            break;
        case 5:
            clearScreen();

            mensajeRetorno(auxiliar, "Egreso Cancelado\n","", "");
            break;
        case 6:
            break;
        }
    }
    while(opcion != 6);
    return 0;
}
