#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "productos.h"

#define LIBRE 0
#define OCUPADO 1

int eProd_init(eProducto productos[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && productos != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            productos[i].estado = LIBRE;
            productos[i].cantVendida = 0;
            productos[i].stock = -1;
            productos[i].idProducto = -1;
            productos[i].idVendedor = -1;
        }
    }
    return retorno;
}

int eProd_HC(eProducto productos[], int limite)
{
    char nombre[][20]= {"Peine","Bateria","Plato","Tenedor","Pelota","Remera","Pantalon","Zapatillas","Monitor","Teclado"};
    float precios[]= {3.5,10,7.5,3,15.6,12.5,20.5,33.99,1999.99,250};
    int stock[]= {26,20,12,10,6,35,29,10,6,17};
    int cantVendida[]= {3,5,9,1,7,5,11,22,31,8};
    int idProducto[]= {0,1,2,3,4,5,6,7,8,9};
    int idVendedor[]= {0,0,1,1,2,2,3,3,4,4};
    int retorno = -1;
    int i;
    if(limite > 0 && productos != NULL)
    {
        retorno = 0;
        for(i=0; i<10; i++)
        {
            strcpy(productos[i].nombre, nombre[i]);
            productos[i].precio = precios[i];
            productos[i].stock = stock[i];
            productos[i].cantVendida = cantVendida[i];
            productos[i].idProducto = idProducto[i];
            productos[i].idVendedor = idVendedor[i];
            productos[i].estado = OCUPADO;
        }
    }
    return retorno;
}
