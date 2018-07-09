#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "tools.h"
#include "ArrayList.h"


int main()
{
    ArrayList* listado = al_newArrayList();
    ArrayList* listaFiltrada = al_newArrayList();
    if(listado != NULL && listaFiltrada != NULL)
    {
        comprobacionEinicializacion();
        ingresoDeDatos(listado);
    }

    int opcion;
    char menu[] =
        "1-Mostrar Lista.\
        \n2-Generar y mostrar lista filtrada.\
        \n6-Salir.\
        \n";

     do
    {
        printf("%s", menu);
        opcion = ingresarIntValido("Ingrese una opcion: ", "ERROR! La opcion ingresada no es valida.\n", 1, 6);
        switch(opcion)
        {
        case 1:
            clearScreen();
            mostrarLista(listado);
            //mensajeRetorno(auxiliar, "No quedan espacios disponibles\n", "Usuario dado de alta correctamente\n", "");
            break;
        case 2:
            clearScreen();
            listaFiltrada = al_filter(listado, funcionQueFiltra);
            mostrarLista(listaFiltrada);
            break;
        case 6:
            break;
        }
    }
    while(opcion != 6);
    return 0;
}
