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
    al_sort(listadoCompleto, compararEntero, 1);
    al_sort(listadoSinRepetidos, compararEntero, 1);
    al_sort(listadoRepetidos, compararEntero, 0);
    int opcion;
    int auxiliar;
    char columnas[][50]={" IN NUM NOMBRE                 PAR IMPAR PRIMO"};
    printf("Hacer un parse del archivo \"datos.csv\".\
           \nCampos: Numero, Nombre de numero, Par, Impar y Primo (1 si lo es, 0 si no).\
           \nUtilizar la biblioteca Arraylist.\
           \nVALIDACIONES:\
           \nA: Numero > 0.\
           \nB: Nombre de numero < 50 char.\
           \nC: Agregar si es par,impar y/o primo utilizando las funciones correspondientes.");
    pause();
    clearScreen();
    do
    {
        opcion = menuSwitch("1-Listado Completo\
                            \n2-Listar repetidos con todas sus ocurrencias (descendente).\
                            \n3-Listar no repetidos (ascendente).\
                            \n4-Generar Archivos de salida (repetidos.csv y depurado.csv).\
                            \n5-Salir.\n", 1, 5);
        switch(opcion)
        {
        case 1:
            mostrarLista(listadoCompleto, columnas);
            pause();
            break;
        case 2:
            mostrarLista(listadoRepetidos, columnas);
            pause();
            break;
        case 3:
            mostrarLista(listadoSinRepetidos, columnas);
            pause();
            break;
        case 4:
            actualizarArchivo(listadoCompleto, "datos completo.csv");
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
