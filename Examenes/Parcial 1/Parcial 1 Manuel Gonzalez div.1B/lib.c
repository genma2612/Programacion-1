#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "tools.h"
#include "time.h"
#define CANT_PROPIETARIOS 20



// propietarios

int ePro_alta(ePropietarios listado[])
{
    int retorno = -1;
    int id;
    int indice;
    if(CANT_PROPIETARIOS > 0 && listado != NULL)
    {
        indice = ePro_buscarLugarLibre(listado);
        if(indice >= 0)
        {
            id = ePro_siguienteId(listado);
            ingresarStringValida("Ingrese el nombre: ", "El nombre debe contener solo letras.\n", "La cantidad max. es de 20 caracteres.\n", listado[indice].nombre, 21);
            ingresarStringValida("Ingrese el apellido: ", "El apellido debe contener solo letras.\n", "La cantidad max. es de 20 caracteres.\n", listado[indice].apellido, 21);
            ingresarStringValidaAlfa("Ingrese la direccion: ", "Solo puede contener numeros y letras\n", "La cantidad max. es de 20 caracteres\n", listado[indice].direccion, 21);
            ingresarStringValidaAlfa("Ingrese la tarjeta: ", "Solo puede contener numeros.\n", "La cantidad max. es de 20 caracteres\n", listado[indice].tarjeta, 21);
            listado[indice].idPropietario = id;
            listado[indice].estado = OCUPADO;
            retorno = 0;
        }
    }
    return retorno;
}

int ePro_buscarLugarLibre(ePropietarios listado[])
{
    int retorno = -1;
    int i;
    if(CANT_PROPIETARIOS > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0; i<CANT_PROPIETARIOS; i++)
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

int ePro_siguienteId(ePropietarios listado[])
{
    int retorno = 0;
    int i;
    if(CANT_PROPIETARIOS > 0 && listado != NULL)
    {
        for(i=0; i<CANT_PROPIETARIOS; i++)
        {
            if(listado[i].estado == OCUPADO)
            {
                if(listado[i].idPropietario > retorno)
                {
                    retorno = listado[i].idPropietario;
                }
            }
        }
    }
    return retorno+1;
}

int ePro_modif(char mensaje[], ePropietarios listado[])
{
    int retorno = -1;
    int idaux;
    int indice;
    idaux = ingresarIntValido("Mostrar listado de ID's? 1-Si 2-No \n", "Opcion ingresada incorrecta. Mostrar listado de ID's? 1-Si 2-No \n", 1, 2);
    if(idaux == 1)
    {
        ePro_mostrarListado(listado);
    }
    idaux = ingresarIntValido(mensaje, "El dato ingresado no es valido", 0, 1000);
    indice = buscarPorId(listado, idaux);
    if(indice < 0)
    {
        return retorno;
    }
    retorno = 0;
    idaux = ingresarIntValido("Confirmar la modificacion? 1-Si 2-No \n", "Opcion ingresada incorrecta. Confirmar la modificacion? 1-Si 2-No \n", 1, 2);
    if(idaux == 1)
    {
        retorno = 1;
        ingresarStringValidaAlfa("Ingrese la nueva tarjeta: ", "Solo puede contener numeros.\n", "La cantidad max. es de 20 caracteres\n", listado[indice].tarjeta, 21);
    }
    return retorno;
}

int buscarPorId(ePropietarios listado[], int id)
{
    int retorno = -1;
    int i;
    if(CANT_PROPIETARIOS > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0; i<CANT_PROPIETARIOS; i++)
        {
            if(listado[i].estado == OCUPADO && listado[i].idPropietario == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int ePro_baja(char mensaje[], ePropietarios listado[])
{
    int retorno = -1;
    int indice;
    int idaux;
    idaux = ingresarIntValido("Mostrar listado de ID's? 1-Si 2-No \n", "Opcion ingresada incorrecta. Mostrar listado de ID's? 1-Si 2-No \n", 1, 2);
    if(idaux == 1)
    {
        ePro_mostrarListado(listado);
    }
    idaux = ingresarIntValido("Ingrese la ID del propietario: ", "Error, la ID contiene solo numeros", 0, CANT_PROPIETARIOS);
    indice = buscarPorId(listado, idaux);
    if(indice < 0)
    {
        return retorno;
    }
    retorno = 0;
    idaux = ingresarIntValido("Confirmar la baja 1-Si 2-No \n", "Opcion ingresada incorrecta. Confirmar la baja? 1-Si 2-No \n", 1, 2);
    if(idaux == 1)
    {
        retorno = 1;
        listado[indice].estado = LIBRE;
    }
    return retorno;
}

int ePro_mostrarListado(ePropietarios listado[])
{
    int retorno = 0;
    int i;
    if(CANT_PROPIETARIOS > 0 && listado != NULL)
    {
        retorno = 1;
        printf("ID  NOMBRE   APELLIDO  DIRECCION   TARJETA\n");
        for(i=0; i<CANT_PROPIETARIOS; i++)
        {
            if(listado[i].estado==OCUPADO)
            {
                printf("%d   %s   %s   %s   %s\n", listado[i].idPropietario, listado[i].nombre, listado[i].apellido, listado[i].direccion, listado[i].tarjeta);
            }
        }
    }
    return retorno;
}

// ingresos

int eAuto_Ingreso(eIngreso listado[], ePropietarios propietarios[])
{
    int retorno = -1;
    int aux;
    int id;
    int indice;
    int indicePropietario;
    if(CANT_PROPIETARIOS > 0 && listado != NULL)
    {
        indice = eIngreso_buscarLugarLibre(listado);
        if(indice < 0)
        {
            return retorno;
        }
        aux = ingresarIntValido("Mostrar listado de ID's? 1-Si 2-No \n", "Opcion ingresada incorrecta. Mostrar listado de ID's? 1-Si 2-No \n", 1, 2);
        if(aux == 1)
        {
            ePro_mostrarListado(propietarios);
        }
        aux = ingresarIntValido("Ingrese el ID del propietario: ", "Opcion incorrecta. Ingrese el ID del propietario: ", 0, 1000);
        indicePropietario = buscarPorId(propietarios, aux);
        if(indicePropietario < 0)
        {
            retorno = 0;
            return retorno;
        }
        listado[indice].idPropietario = propietarios[indicePropietario].idPropietario;
        id = eIngreso_siguienteId(listado);
        ingresarStringValidaAlfa("Ingrese la patente: ", "La patente debe contener solo letras y numeros.\n", "La cantidad max. es de 9 caracteres.\n", listado[indice].patente, 10);
        listado[indice].marca = ingresarIntValido("Ingrese la marca 1-Alpha romeo 2-Ferrari 3-Audi 4-Otro ", "Opcion incorrecta \n", 1, 4);
        listado[indice].idIngreso = id;
        listado[indice].estado = OCUPADO;
        retorno = 1;
    }
    return retorno;
}

int eIngreso_buscarLugarLibre(eIngreso listado[])
{
    int retorno = -1;
    int i;
    if(CANT_PROPIETARIOS > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0; i<CANT_PROPIETARIOS; i++)
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

int eIngreso_siguienteId(eIngreso listado[])
{
    int retorno = 0;
    int i;
    if(CANT_PROPIETARIOS > 0 && listado != NULL)
    {
        for(i=0; i<CANT_PROPIETARIOS; i++)
        {
            if(listado[i].estado == OCUPADO)
            {
                if(listado[i].idPropietario > retorno)
                {
                    retorno = listado[i].idPropietario;
                }
            }
        }
    }
    return retorno+1;
}



int devolverHorasEstadia()
{
    int horas;

    srand(time(NULL));

    horas = (rand()%24)+1;

    return horas ;

}

int ePro_mostrarListadoAutos(eIngreso listado[])
{
    int retorno = 0;
    int i;
    if(CANT_PROPIETARIOS > 0 && listado != NULL)
    {
        retorno = 1;
        printf("PAT. ID.PRO. MARCA ID.ING\n");
        for(i=0; i<CANT_PROPIETARIOS; i++)
        {
            if(listado[i].estado==OCUPADO)
            {
                printf("%s   %d   %d  ", listado[i].patente, listado[i].idPropietario,listado[i].idIngreso, listado[i].marca);
                if(listado[i].marca == 1)
                {
                printf("Alpha Romeo\n");
                }
                else if(listado[i].marca == 2)
                {


                printf("Ferrari\n");
                }
                else if(listado[i].marca == 3)
                {


                printf("AUDI\n");
                }
                else
                printf("Otro\n");
            }
        }
    }
    return retorno;
}
