#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "tools.h"
#include "ArrayList.h"


int main()
{
    ArrayList* listadoCompleto = al_newArrayList();
    ArrayList* listadoRepetidos = al_newArrayList();
    ArrayList* listadoSinRepetidos = al_newArrayList();
    if(listadoCompleto != NULL)
    {
        lecturaDeDatos(listadoCompleto);
        listadoRepetidos = al_clone(listadoCompleto);
    }
    criterioRepetidos(listadoRepetidos, listadoSinRepetidos);
    al_sort(listadoSinRepetidos, compararEntero, 1);
    al_sort(listadoRepetidos, compararEntero, 0);
    int opcion;
    int auxiliar;
    do
    {
        opcion = menuSwitch("1-Listado Completo\n2-Listar repetidos con todas sus ocurrencias (descendente) .\n3-Listar no repetidos (ascendente).\n4-Generar Archivos de salida\n5-Salir.\n\n", 1, 5);
        switch(opcion)
        {
        case 1:
            printf("IN NUM NOMBRE                P IM PR\n");
            mostrarLista(listadoCompleto, "");
            pause();
            break;
        case 2:
            printf("IN NUM NOMBRE                P IM PR\n");
            mostrarLista(listadoRepetidos, "");
            pause();
            break;
        case 3:
            printf("IN NUM NOMBRE                P IM PR\n");
            mostrarLista(listadoSinRepetidos, "");
            pause();
            break;
        case 4:
            actualizarArchivo(listadoRepetidos, "repetidos.csv");
            actualizarArchivo(listadoSinRepetidos, "depurado.csv");
            clearScreen();
            printf("Archivos generados correctamente.\n");
            pause();
            break;
        case 5:
            break;
        }
        clearScreen();
    }
    while(opcion != 5);
    return 0;
}
