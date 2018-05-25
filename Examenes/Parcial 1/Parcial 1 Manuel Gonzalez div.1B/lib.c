#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
            ingresarStringValidaTelefono("Ingrese la tarjeta (XXX-XXX): ", "Solo puede contener numeros separados por un guiin.\n", "Cant maxima superada\n", listado[indice].tarjeta, 8);
            listado[indice].idPropietario = id;
            listado[indice].estado = OCUPADO;
            retorno = 0;
        }
    }
    clearScreen();
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

int ePro_modif(char mensaje[], ePropietarios listado[], eIngreso ingresos[])
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
        ingresarStringValidaTelefono("Ingrese la nueva tarjeta: (XXX-XXX)", "Solo puede contener numeros separados por un guiin.\n", "Cant maxima superada\n", listado[indice].tarjeta, 8);
    }
    clearScreen();
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

int ePro_baja(char mensaje[], ePropietarios listado[], eIngreso ingresos[], eEgreso egresos[])
{
    int retorno = -1;
    int indice;
    int idaux;
    float deuda=0;
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
    idaux = ingresarIntValido("Confirmar la baja 1-Si 2-No \n", "Opcion ingresada incorrecta. Confirmar la baja? 1-Si 2-No \n", 1, 2);
    if(idaux == 2)
    {
        return retorno;
    }
    listado[indice].estado = LIBRE;
    deuda = liquidacion(listado, ingresos, egresos, listado[indice].idPropietario);
    if(!deuda)
    {
        retorno = 0;
        return retorno;
    }
    retorno = 1;
    clearScreen();
    printf("%s %s fue dado de baja. El importe a abonar es: %.2f\n", listado[indice].nombre, listado[indice].apellido, deuda);
    return retorno;
}

float liquidacion(ePropietarios listado[],eIngreso ingresos[],eEgreso egresos[], int idPropietario)
{
    int i;
    int j;
    float importe=0;
    float total=0;
    for(i=0; i<100; i++)
    {
        if(ingresos[i].estado == OCUPADO && ingresos[i].idPropietario == idPropietario)
        {
            for(j=0; j<100; j++)
            {
                if(egresos[j].estado == LIBRE)
                {
                    ingresos[i].estado = LIBRE;
                    egresos[j].estado = OCUPADO;
                    egresos[j].idPropietario = ingresos[i].idPropietario;
                    egresos[j].marca = ingresos[i].marca;
                    importe = calcularImporte(egresos, ingresos[i].marca);
                    egresos[j].importe = importe;
                    total = total + importe;
                    break;
                }
            }
        }
    }
    return total;
}

void ePro_mostrarListado(ePropietarios listado[])
{
    int i;
    if(CANT_PROPIETARIOS > 0 && listado != NULL)
    {
        printf("ID  NOMBRE   APELLIDO  DIRECCION   TARJETA\n");
        for(i=0; i<CANT_PROPIETARIOS; i++)
        {
            if(listado[i].estado==OCUPADO)
            {
                printf("%d   %s   %s   %s   %s\n", listado[i].idPropietario, listado[i].nombre, listado[i].apellido, listado[i].direccion, listado[i].tarjeta);
            }
        }
    }
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
                if(listado[i].idIngreso > retorno)
                {
                    retorno = listado[i].idIngreso;
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

void ePro_mostrarListadoAutos(eIngreso ingresos[], ePropietarios propietarios[])
{
    int i;
    int j;
    int auxInt;
    char auxiliar[20];
    char marcas[5][15]= {" ","Alpha Romeo","Ferrari","Audi","otro"};
    for(i=0; i<19; i++)
    {
        for(j=i+1; j<CANT_PROPIETARIOS; j++)
        {
            if(ingresos[i].estado == OCUPADO && ingresos[j].estado == OCUPADO)
            {
                if(strcmp(ingresos[i].patente, ingresos[j].patente) > 0)
                {
                    strcpy(auxiliar, ingresos[i].patente);
                    strcpy(ingresos[i].patente, ingresos[j].patente);
                    strcpy(ingresos[j].patente, auxiliar);

                    auxInt = ingresos[i].idIngreso;
                    ingresos[i].idIngreso = ingresos[j].idIngreso;
                    ingresos[j].idIngreso = auxInt;

                    auxInt = ingresos[i].idPropietario;
                    ingresos[i].idPropietario = ingresos[j].idPropietario;
                    ingresos[j].idPropietario = auxInt;

                    auxInt = ingresos[i].marca;
                    ingresos[i].marca = ingresos[j].marca;
                    ingresos[j].marca = auxInt;
                }
            }
        }
    }
    printf("PATENTE ID.PROP. ID.INGRESO MARCA DE AUTOMOVIL    NOMBRE    APELLIDO\n");
    for(i=0; i<100; i++)
    {
        if(ingresos[i].estado == OCUPADO)
        {
            printf("%-6.5s %5d %10d %20s ", ingresos[i].patente, ingresos[i].idPropietario,ingresos[i].idIngreso, marcas[ingresos[i].marca]);
            for(j=0; j<CANT_PROPIETARIOS; j++)
            {
                if(ingresos[i].idPropietario == propietarios[j].idPropietario)
                {
                    printf("%10s %10s\n", propietarios[j].nombre, propietarios[j].apellido);
                }
            }
        }
    }
    printf("\n");
}

// egresos

int egresoAutomovil(eIngreso ingresos[], eEgreso egresos[], ePropietarios propietarios[])
{
    int retorno=-1;
    int i;
    int aux;
    int indice;
    int flag=0;
    char marcas[5][15]= {" ","Alpha Romeo","Ferrari","Audi","otro"};
    float importe;
    ePro_mostrarListadoAutos(ingresos, propietarios);
    do
    {
        if(flag)
        {
            printf("Error, la ID de ingreso no se encuentra\n");
        }
        aux = ingresarIntValido("Ingrese el ID del auto que saldra o 0 para cancelar: \n", "Error, ingrese un numero, debe ser la ID del auto que saldra, o 0 para cancelar: \n", 0, 100);
        if(!aux)
        {
            return retorno;
        }
        indice = buscarIdIngreso(ingresos, aux);
        flag=1;
    }
    while (indice < 0);
    aux = ingresarIntValido("Confirmar salida 1-Si 2-Cancelar: \n", "Opcion incorrecta 1-Confirmar salida 2-Cancelar: ", 1, 2);
    if(aux == 2)
    {
        return retorno;
    }
    for(i=0; i<100; i++)
    {
        if(egresos[i].estado == LIBRE)
        {
            egresos[i].marca = ingresos[indice].marca;
            egresos[i].idPropietario = ingresos[indice].idPropietario;
            egresos[i].estado = OCUPADO;
            importe = calcularImporte(egresos, ingresos[indice].marca);
            egresos[i].importe = importe;
            ingresos[indice].estado = LIBRE;
            break;
        }
    }
    aux = buscarPorId(propietarios, ingresos[indice].idPropietario);
    clearScreen();
    printf("TICKET:\nNOMBRE: %s %s PATENTE: %s MARCA: %s", propietarios[aux].nombre,propietarios[aux].apellido, ingresos[indice].patente, marcas[egresos[i].marca]);
    printf(" VALOR DE ESTADIA: %.2f\nPresione enter para continuar...\n", egresos[i].importe);
    pause();
    clearScreen();
    retorno = 0;
    return retorno;
}

int buscarIdIngreso(eIngreso ingresos[], int id)
{
    int retorno = -1;
    int i;
    if(100 > 0 && ingresos != NULL)
    {
        for(i=0; i<100; i++)
        {
            if(ingresos[i].idIngreso == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

float calcularImporte(eEgreso egresos[], int marca)
{
    int horas;
    float importe;
    horas = devolverHorasEstadia();
    switch(marca)
    {
    case 1:
        importe = horas * 150;
        break;
    case 2:
        importe = horas * 175;
        break;
    case 3:
        importe = horas * 200;
        break;
    case 4:
        importe = horas * 250;
        break;
    }
    return importe;

}

void mostrarRecaudacion(eEgreso listado[])
{
    int i;
    float recaudacion=0;
    for(i=0; i<100; i++)
    {
        if(listado[i].estado)
        {
            recaudacion = recaudacion + listado[i].importe;
        }
    }
    printf("La recaudacion total de los autos egresados es de: $%.2f\n", recaudacion);
}

void mostrarRecaudacionPorMarca(eEgreso listado[])
{
    int i;
    float recaudacion[4]= {0};
    for(i=0; i<100; i++)
    {
        if(listado[i].estado == OCUPADO)
        {
            switch(listado[i].marca)
            {
            case 1:
                recaudacion[0] = recaudacion[0] + listado[i].importe;
                break;
            case 2:
                recaudacion[1] = recaudacion[1] + listado[i].importe;
                break;
            case 3:
                recaudacion[2] = recaudacion[2] + listado[i].importe;
                break;
            case 4:
                recaudacion[3] = recaudacion[3] + listado[i].importe;
                break;
            }
        }

    }
    clearScreen();
    printf("Recaudacion por marcas:\nAlpha Romeo: $%.2f Ferrari: $%.2f Audi: $%.2f Otros: $%.2f\n", recaudacion[0], recaudacion[1], recaudacion[2], recaudacion[3]);
}

int mostrarPropietario(ePropietarios listado[], eIngreso ingresos[])
{
    int indice;
    int i;
    int aux;
    int retorno=-1;
    int contador=0;
    char marcas[5][15]= {" ","Alpha Romeo","Ferrari","Audi","otro"};
    aux = ingresarIntValido("ingrese ID a buscar:\n", "Error, ingrese el ID a buscar:\n", 0, 1000);
    indice = buscarPorId(listado, aux);
    if(indice < 0)
    {
        return retorno;
    }
    printf("%s %s \nMARCA               PATENTE\n", listado[indice].nombre, listado[indice].apellido);
    for(i=0; i<100; i++)
    {
        if(listado[indice].idPropietario == ingresos[i].idPropietario)
        {
            contador++;
            printf("%-10.15s %15.15s\n", marcas[ingresos[i].marca], ingresos[i].patente);
        }
    }
    if(!contador)
    {
        printf("No posee autos estacionados actualmente.\n");
    }
    retorno = 0;
    return retorno;
}

void propietariosDeAudi(ePropietarios listado[], eIngreso ingresos[])
{
    int i;
    int j;
    printf("Propietarios de AUDI\n");
    printf("NOMBRE  APELLIDO    DIRECCION   TARJETA\n");
    for(i=0; i<CANT_PROPIETARIOS; i++)
    {
        if(listado[i].estado == OCUPADO)
        {
            for(j=0; j<100; j++)
            {
                if(ingresos[j].estado == OCUPADO && listado[i].idPropietario == ingresos[j].idPropietario && ingresos[j].marca == 3)
                {
                    printf("%-8.15s %s %12.20s %12s\n", listado[i].nombre, listado[i].apellido, listado[i].direccion, listado[i].tarjeta);
                    break;
                }
            }
        }
    }
    printf("\n");
}

void mostrarEgresos(eEgreso egresos[])
{
    int i;
    char marcas[5][15]= {" ","Alpha Romeo","Ferrari","Audi","otro"};
    printf("MARCA                   IMPORTE           ID PROPIETARIO\n");
    for(i=0;i<100;i++)
    {
        if(egresos[i].estado == OCUPADO)
        {
            printf("%-20.15s %10.2f %15d\n", marcas[egresos[i].marca], egresos[i].importe, egresos[i].idPropietario);
        }
    }
}
