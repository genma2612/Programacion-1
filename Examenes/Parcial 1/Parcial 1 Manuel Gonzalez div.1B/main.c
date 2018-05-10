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

    eIngreso ingresos[CANT_PROPIETARIOS];
    auxiliar = eIngreso_init(ingresos);
    auxiliar = eIngreso_HC(ingresos);

    char menuPrincipalMensaje[] =
        "1-Alta de propietario.\
                 \n2-Modificar.\
                 \n3-Baja.\
                 \n4-Ingreso de automovil.\
                 \n5-.\
                 \n6-Mostrar.\
                 \n7-Mostrar Autos.\
                 \n8-Salir.\
                 \n9-Salir.\
                 \n";

    do
    {
        printf("%s", menuPrincipalMensaje);
        opcion = ingresarIntValido("Ingrese una opcion: ", "ERROR! La opcion ingresada no es valida.\n", 1, 9);
        switch(opcion)
        {
        case 1:
            clearScreen();
            auxiliar = ePro_alta(propietarios);
            mensajeRetorno(auxiliar, "No quedan espacios disponibles\n", "Usuario dado de alta correctamente\n", "");
            break;
        case 2:
            clearScreen();
            auxiliar = ePro_modif("Ingrese el ID del usuario a modificar ", propietarios);
            mensajeRetorno(auxiliar, "Error, la ID no se encuentra.\n", "Modificacion cancelada.\n", "Usuario modificado correctamente\n");
            break;
        case 3:
            clearScreen();
            auxiliar = ePro_baja("Ingrese el ID del usuario a dar de baja", propietarios);
            mensajeRetorno(auxiliar, "La ID ingresada no se encuentra.\n","Baja cancelada\n", "Baja realizada correctamente.\n");
            break;
        case 4:
            clearScreen();
            auxiliar = eAuto_Ingreso(ingresos, propietarios);
            mensajeRetorno(auxiliar, "No hay lugar\n","La ID ingresada no se encuentra.\n", "Ingreso realizado correctamente.\n");
            break;
        case 5:

            break;
        case 6:
            clearScreen();
            ePro_mostrarListado(propietarios);
            printf("Presione enter para continuar...\n");
            pause();
            clearScreen();
            break;
        case 7:
            clearScreen();
            ePro_mostrarListadoAutos(ingresos);
            printf("Presione enter para continuar...\n");
            pause();
            clearScreen();
            break;
        default:
            system("pause");
            opcion = 0;
            break;
        }

    }
    while(opcion != 9);














    return 0;
}
