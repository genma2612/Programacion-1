#ifndef __included_productos_h
#define __included_productos_h
#include <stdio.h>
#include <stdlib.h>
#include "usuarios.h"

#define CANT_USUARIOS 100
#define CANT_PRODUCTOS 1000

typedef struct
{
    char nombre[20];
    float precio;
    int stock;
    int cantVendida;
    int idProducto;
    int idVendedor;
    int estado;
}eProducto;

int eProd_init(eProducto[],int);

int eProd_HC(eProducto[],int);

int eProd_alta(eProducto[], int, eUsuarios[], int);

int eProd_siguienteId(eProducto[] ,int);

int eProd_buscarLugarLibre(eProducto[],int);

int eProd_modif(char mensaje[], char menu[], eProducto[], int);

int buscarPorIdProducto(eProducto[],int, int);

int eProd_baja(char mensaje[], eProducto[],int);

int mostrarListado(eProducto[], int);

#endif;
