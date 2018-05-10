#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "tools.h"
#define CANT_USUARIOS 100
#define CANT_PRODUCTOS 1000
#define LIBRE 0
#define OCUPADO 1

// usuarios

int eUsu_alta(eUsuarios listado[],int limite)
{
    int retorno = -1;
    int id;
    int indice;
    if(limite > 0 && listado != NULL)
    {
        indice = eUsu_buscarLugarLibre(listado,limite);
        if(indice >= 0)
        {
            id = eUsu_siguienteId(listado,limite);
            ingresarStringValida("Ingrese el nombre: ", "El nombre debe contener solo letras.\n", "La cantidad max. es de 20 caracteres.\n", listado[indice].nombre, 21);
            ingresarStringValida("Ingrese el apellido: ", "El apellido debe contener solo letras.\n", "La cantidad max. es de 20 caracteres.\n", listado[indice].apellido, 21);
            printf("Ingrese usuario: \n");
            fflush(stdin);
            gets(listado[indice].usuario);
            printf("Ingrese password: \n");
            fflush(stdin);
            gets(listado[indice].password);
            printf("Ingrese telefono: \n");
            fflush(stdin);
            gets(listado[indice].telefono);
            listado[indice].id = id;
            listado[indice].estado = OCUPADO;
            retorno = 1;
        }
    }
    return retorno;
}

int eUsu_buscarLugarLibre(eUsuarios listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eUsu_siguienteId(eUsuarios listado[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO)
            {
                if(listado[i].id > retorno)
                {
                    retorno = listado[i].id;
                }
            }
        }
    }
    return retorno+1;
}

int eUsu_modif(char mensaje[], char menu[], eUsuarios usuarios[], int limite)
{
    int retorno = -1;
    int opcion;
    int idaux;
    int indice;
    printf("%s", mensaje);
    scanf("%d", &idaux);
    indice = buscarPorId(usuarios, CANT_USUARIOS, idaux);
    if(indice < 0)
    {
        return retorno;
    }
    retorno = 1;
    do
    {
        printf("%s", menu);
        opcion = ingresarIntValido("ingrese una opcion: ", "Opcion incorrecta, ingrese una opcion: ", 1, 6);
    switch(opcion)
    {
    case 1:
        printf("Ingrese el nuevo nombre: \n");
        fflush(stdin);
        gets(usuarios[indice].nombre);
        clearScreen();
        break;
    case 2:
        printf("Ingrese el nuevo apellido: \n");
        fflush(stdin);
        gets(usuarios[indice].apellido);
        clearScreen();
        break;
    case 3:
        printf("Ingrese el nuevo usuario: \n");
        fflush(stdin);
        gets(usuarios[indice].usuario);
        clearScreen();
        break;
    case 4:
        printf("Ingrese el nuevo password: \n");
        fflush(stdin);
        gets(usuarios[indice].password);
        clearScreen();
        break;
    case 5:
        printf("Ingrese el nuevo telefono: \n");
        fflush(stdin);
        gets(usuarios[indice].telefono);
        clearScreen();
        break;
    case 6:
        break;
    }
    }while(opcion != 6);
    return retorno;
}

int buscarPorId(eUsuarios listado[],int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO && listado[i].id == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eUsu_baja(char mensaje[], eUsuarios listado[], eProducto productos[])
{
    int retorno = -1;
    int i;
    int indice;
    int idaux;
    idaux = ingresarIntValido("Ingrese la ID del usuario: ", "Error, la ID contiene solo numeros", 0, CANT_USUARIOS);
    indice = buscarPorId(listado, CANT_USUARIOS, idaux);
    if(indice < 0)
    {
        return retorno;
    }
    retorno = 0;
    listado[indice].estado = LIBRE;
    for(i=0;i<CANT_PRODUCTOS;i++)
    {
        if(listado[indice].id == productos[i].idVendedor)
        {
            productos[i].estado = LIBRE;
        }
    }
    return retorno;
}

int mostrarListado(eUsuarios listado[], eProducto productos[])
{
    int retorno = 0;
    int i;
    if(CANT_USUARIOS > 0 && listado != NULL)
    {
        retorno = 1;
        for(i=0; i<CANT_USUARIOS; i++)
        {
            if(listado[i].estado==OCUPADO)
            {
                printf("ID: %d. Nombre: %s  %s - %s - %s - %s - %d\n", listado[i].id, listado[i].nombre, listado[i].apellido, listado[i].usuario, listado[i].password, listado[i].telefono, listado[i].estado);
            }
        }
    }
    pause();
    clearScreen();
    return retorno;
}

// productos

int eProd_alta(eProducto productos[],int limite, eUsuarios listado[], int size)
{
    int retorno = -1;
    int auxiliar;
    int idVendedor;
    int indice;
    int id;
    idVendedor = ingresarIntValido("Ingrese el ID del vendedor: ", "La ID ingresada no es valida. 0-100\n", 0, CANT_USUARIOS);
    auxiliar = buscarPorId(listado, size, idVendedor);
    if(auxiliar >= 0 && limite > 0 && productos != NULL)
    {
        retorno = 1;
        indice = eProd_buscarLugarLibre(productos,limite);
        if(indice >= 0)
        {
            retorno = 2;
            productos[indice].idVendedor = listado[auxiliar].id;
            printf("Ingrese nombre del producto: \n");
            fflush(stdin);
            gets(productos[indice].nombre);
            printf("Ingrese precio: \n");
            scanf("%f", &productos[indice].precio);
            printf("Ingrese stock: \n");
            scanf("%d", &productos[indice].stock);
            id = eProd_siguienteId(productos, CANT_PRODUCTOS);
            productos[indice].idProducto = id;
            productos[indice].estado = OCUPADO;
        }
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

int eProd_modif(char mensaje[], eProducto producto[], eUsuarios usuarios[])
{
    int retorno = -1;
    int i;
    int idaux;
    int indice;
    printf("%s", mensaje);
    scanf("%d", &idaux);
    indice = buscarPorId(usuarios, CANT_USUARIOS, idaux);
    if(indice < 0)
    {
        return retorno;
    }
    retorno = 0;
    clearScreen();
    for(i=0;i<CANT_PRODUCTOS;i++)
    {
        if(producto[i].idVendedor == idaux)
        {
            printf("ID del producto: %d. Nombre: %s. Precio: %.2f. Cant. Vendida: %d. Stock disponible: %d.\n", producto[i].idProducto, producto[i].nombre, producto[i].precio, producto[i].cantVendida, producto[i].stock);
        }
    }
    idaux = ingresarIntValido("Ingrese el ID del producto a modificar: ", "Error", 0, CANT_PRODUCTOS);
    indice = buscarPorIdProducto(producto, CANT_PRODUCTOS, idaux);
    if(indice == -1)
    {
        return retorno;
    }
    else
    {
        retorno = 1;
        producto[indice].precio = ingresarFloatValido("Ingrese el nuevo precio: ", "Precio ingresado erroneo.\n", 0.1, 1000);
        producto[indice].stock = ingresarIntValido("Ingrese el nuevo stock: ", "stock ingresado erroneo.\n", 1, 1000);
    }
    return retorno;
}

int buscarPorIdProducto(eProducto productos[],int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && productos != NULL)
    {
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

int eProd_baja(char mensaje[], eProducto producto[], eUsuarios usuarios[])
{
    int retorno = -1;
    int i;
    int idaux;
    int indice;
    printf("%s", mensaje);
    scanf("%d", &idaux);
    indice = buscarPorId(usuarios, CANT_USUARIOS, idaux);
    if(indice < 0)
    {
        return retorno;
    }
    retorno = 0;
    clearScreen();
    for(i=0;i<CANT_PRODUCTOS;i++)
    {
        if(producto[i].idVendedor == idaux)
        {
            printf("ID del producto: %d. Nombre: %s. Precio: %.2f. Cant. Vendida: %d. Stock disponible: %d.\n", producto[i].idProducto, producto[i].nombre, producto[i].precio, producto[i].cantVendida, producto[i].stock);
        }
    }
    idaux = ingresarIntValido("Ingrese el ID de la publicacion a dar de baja: ", "Error", 0, CANT_PRODUCTOS);
    indice = buscarPorIdProducto(producto, CANT_PRODUCTOS, idaux);
    if(indice == -1)
    {
        return retorno;
    }
    else
    {
        retorno = 1;
        producto[indice].estado = LIBRE;
    }
    return retorno;
}

int listarPublicaciones(eProducto productos[], eUsuarios listado[])
{
    int retorno = 0;
    int i, j;
    for(i=0; i<CANT_PRODUCTOS; i++)
    {
        if(productos[i].estado == OCUPADO)
        {
            printf("%d - %s - %.2f - %d - %d ",productos[i].idProducto, productos[i].nombre,  productos[i].precio, productos[i].cantVendida, productos[i].stock);
            for(j=0; j<CANT_USUARIOS; j++)
            {
                if(listado[j].id == productos[i].idVendedor && listado[j].estado == OCUPADO)
                {
                    printf("%s\n", listado[j].nombre);
                }
            }
        }
    }
    pause();
    clearScreen();
    return retorno;
}

int listarPublicacionesDeUsuario(char mensaje[], eProducto producto[], eUsuarios usuarios[])
{
    int retorno = -1;
    int i;
    int idaux;
    int indice;
    printf("%s", mensaje);
    scanf("%d", &idaux);
    indice = buscarPorId(usuarios, CANT_USUARIOS, idaux);
    if(indice < 0)
    {
        return retorno;
    }
    retorno = 0;
    for(i=0;i<CANT_PRODUCTOS;i++)
    {
        if(producto[i].idVendedor == idaux)
        {
            printf("ID del producto: %d. Nombre: %s. Precio: %.2f. Cant. Vendida: %d. Stock disponible: %d.\n", producto[i].idProducto, producto[i].nombre, producto[i].precio, producto[i].cantVendida, producto[i].stock);
        }
    }
    pause();
    clearScreen();
    return retorno;
}
