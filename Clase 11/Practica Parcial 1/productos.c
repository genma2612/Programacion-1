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
            productos[i].stock = 0;
            productos[i].idProducto = 0;
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

int eProd_alta(eProducto productos[],int limite, eUsuarios listado[], int CANT_USUARIOS)
{
    int retorno = 0;
    int auxiliar;
    int idVendedor;
    int indice;
    int id;
    printf("Ingrese el ID del vendedor del producto: \n");
    scanf("%d",idVendedor);
    auxiliar = buscarPorId(listado, CANT_USUARIOS, idVendedor);
    if(auxiliar >= 0 && limite > 0 && productos != NULL)
    {
        indice = eProd_buscarLugarLibre(productos,limite);
        retorno = 1;
        if(indice >= 0)
        {
            productos[indice].idVendedor = listado[auxiliar].id;
            printf("Ingrese nombre del producto: \n");
            fflush(stdin);
            gets(productos[indice].nombre);
            printf("Ingrese precio: \n");
            scanf("%f", productos[indice].precio);
            printf("Ingrese stock: \n");
            scanf("%f", productos[indice].stock);
            id = eProd_siguienteId(productos, CANT_PRODUCTOS);
            productos[indice].idProducto = id;
            productos[indice].estado = OCUPADO;
            retorno = 2;
        }
    }
    else if (auxiliar < 0)
    {
        printf("No se encuentra el ID.\n");
    }
    return retorno;
}

int eProd_buscarLugarLibre(eProducto productos[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && productos != NULL)
    {
        retorno = -2;
        for(i=0; i<limite; i++)
        {
            if(productos[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eProd_siguienteId(eProducto productos[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && productos != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(productos[i].estado == OCUPADO)
            {
                if(productos[i].idProducto > retorno)
                {
                    retorno = productos[i].idProducto;
                }
            }
        }
    }
    return retorno+1;
}

int eProd_modif(char mensaje[], char menu[], eProducto usuarios[], int limite)
{
    int retorno = 0;
    int opcion;
    int idaux;
    int indice;
    printf("%s", mensaje);
    scanf("%d", &idaux);
    indice = buscarPorId(usuarios, CANT_USUARIOS, idaux);
    while(indice < 0)
    {
        printf("Error, la ID no se encuentra\n");
        system("pause");
        printf("%s", mensaje);
        scanf("%d", &idaux);
        indice = buscarPorId(usuarios, CANT_USUARIOS, idaux);
    }
    retorno = 1;
    do
    {
        printf("%s", menu);
        scanf("%d", &opcion);
    switch(opcion)
    {
    case 1:
        printf("Ingrese el nuevo nombre: \n");
        fflush(stdin);
        gets(usuarios[indice].nombre);

        break;
    case 2:
        printf("Ingrese el nuevo apellido: \n");
        fflush(stdin);
        gets(usuarios[indice].apellido);

        break;
    case 3:
        printf("Ingrese el nuevo usuario: \n");
        fflush(stdin);
        gets(usuarios[indice].usuario);

        break;
    case 4:
        printf("Ingrese el nuevo password: \n");
        fflush(stdin);
        gets(usuarios[indice].password);

        break;
    case 5:
        printf("Ingrese el nuevo telefono: \n");
        fflush(stdin);
        gets(usuarios[indice].telefono);

        break;
    case 6:

        break;
    }
    }while(opcion != 6);
    return retorno;
}

int buscarPorIdProducto(eProducto productos[],int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && productos != NULL)
    {
        retorno = -2;
        for(i=0; i<limite; i++)
        {
            if(productos[i].estado == OCUPADO && productos[i].idProducto == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eProd_baja(char mensaje[], eProducto productos[],int limite)
{
    int retorno = 0;
    int indice;
    int idaux;
    printf("%s", mensaje);
    scanf("%d", &idaux);
    indice = buscarPorId(productos, CANT_PRODUCTOS, idaux);
    while(indice < 0)
    {
        printf("Error, la ID no se encuentra\n");
        system("pause");
        printf("%s", mensaje);
        scanf("%d", &idaux);
        indice = buscarPorId(productos, CANT_PRODUCTOS, idaux);
    }
    retorno = 1;
    productos[indice].estado = LIBRE;
    return retorno;
}

int mostrarproductos(eProducto productos[], int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && productos != NULL)
    {
        retorno = 1;
        for(i=0; i<limite; i++)
        {
            if(productos[i].estado==OCUPADO)
            {
                printf("%s - %s - %s - %s - %s - %d - %d\n", productos[i].nombre, productos[i].apellido, productos[i].usuario, productos[i].password, productos[i].telefono, productos[i].id, productos[i].estado);
            }
        }
        printf("\n");
    }
    return retorno;
}

