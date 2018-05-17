#include <stdio.h>
#include <stdlib.h>
#include "tools.h"
#include "lib.h"
#define CANT_PROPIETARIOS 20

int main()
{
    int auxiliar;
    int opcion;

    //Creacion y hardcodeo de "propietarios"
    ePropietarios propietarios[CANT_PROPIETARIOS];
    auxiliar = ePro_init(propietarios);
    auxiliar = ePro_HC(propietarios);

    eIngreso ingresos[100];
    auxiliar = eIngreso_init(ingresos);
    auxiliar = eIngreso_HC(ingresos);

    eEgreso egresos[100];
    auxiliar = eEgreso_init(egresos);
    auxiliar = eEgreso_HC(egresos);



    char menuPrincipalMensaje[] =
        "1-Alta de propietario.\
                \n2-Modificar propietario.\
                 \n3-Baja de propietario.\
                 \n4-Ingreso de automovil.\
                 \n5-Egreso de automovil.\
                 \n6-Recaudacion total del estacionamiento.\
                 \n7-Recaudacion total por marca.\
                 \n8-Info. propietario segun ID.\
                 \n9-Propietarios de AUDI.\
                 \n10-Listado de estacionados con propietarios ordenados por patente.\
                 \n11-Listado de propietarios.\
                 \n12-Historial de egresos.\
                 \n13-Salir.\
                 \n";

    do
    {
        printf("%s", menuPrincipalMensaje);
        opcion = ingresarIntValido("Ingrese una opcion: ", "ERROR! La opcion ingresada no es valida.\n", 1, 13);
        switch(opcion)
        {
        case 1:
            clearScreen();
            auxiliar = ePro_alta(propietarios);
            mensajeRetorno(auxiliar, "No quedan espacios disponibles\n", "Usuario dado de alta correctamente\n", "");
            break;
        case 2:
            clearScreen();
            auxiliar = ePro_modif("Ingrese el ID del usuario a modificar ", propietarios, ingresos);
            mensajeRetorno(auxiliar, "Error, la ID no se encuentra.\n", "Modificacion cancelada.\n", "Usuario modificado correctamente\n");
            break;
        case 3:
            clearScreen();
            auxiliar = ePro_baja("Ingrese el ID del usuario a dar de baja", propietarios, ingresos, egresos);
            mensajeRetorno(auxiliar, "La ID ingresada no se encuentra.\n","No se registra deuda\n", "");
            printf("Presione enter para continuar...\n");
            pause();
            clearScreen();
            break;
        case 4:
            clearScreen();
            auxiliar = eAuto_Ingreso(ingresos, propietarios);
            mensajeRetorno(auxiliar, "No hay lugar\n","La ID ingresada no se encuentra.\n", "Ingreso realizado correctamente.\n");
            break;
        case 5:
            clearScreen();
            auxiliar = egresoAutomovil(ingresos, egresos, propietarios);
            mensajeRetorno(auxiliar, "Egreso Cancelado\n","", "");
            break;
        case 6:
            clearScreen();
            mostrarRecaudacion(egresos);
            printf("Presione enter para continuar...\n");
            pause();
            clearScreen();
            break;
        case 7:
            clearScreen();
            mostrarRecaudacionPorMarca(egresos);
            printf("Presione enter para continuar...\n");
            pause();
            clearScreen();
            break;
        case 8:
            clearScreen();
            auxiliar = mostrarPropietario(propietarios, ingresos);
            mensajeRetorno(auxiliar, "ID no encontrada\n","Presione enter para continuar...\n", "");
            pause();
            clearScreen();
            break;
        case 9:
            clearScreen();
            propietariosDeAudi(propietarios, ingresos);
            printf("Presione enter para continuar...\n");
            pause();
            clearScreen();
            break;
        case 10:
            clearScreen();
            ePro_mostrarListadoAutos(ingresos, propietarios);
            printf("Presione enter para continuar...\n");
            pause();
            clearScreen();
            break;
        case 11:
            clearScreen();
            ePro_mostrarListado(propietarios);
            printf("Presione enter para continuar...\n");
            pause();
            clearScreen();
            break;
        case 12:
            clearScreen();
            mostrarEgresos(egresos);
            printf("Presione enter para continuar...\n");
            pause();
            clearScreen();
            break;
        case 13:
            break;
        }
    }while(opcion != 13);
    return 0;
}
