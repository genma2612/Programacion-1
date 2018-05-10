#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "tools.h"

#define CANT_USUARIOS 100
#define CANT_PRODUCTOS 1000
#define LIBRE 0
#define OCUPADO 1

int main()
{
    int auxiliar;

    // Creación, inicialización y hardcodeo del vector usuarios.
    eUsuarios usuarios[CANT_USUARIOS];
    auxiliar = eUsu_init(usuarios,CANT_USUARIOS);
    auxiliar = eUsu_HC(usuarios, CANT_USUARIOS);

    eProducto productos[CANT_PRODUCTOS];
    auxiliar = eProd_init(productos, CANT_PRODUCTOS);
    auxiliar = eProd_HC(productos, CANT_PRODUCTOS);

    int opcion=0;
    char menuModificacionUsuario[] =
        "Que campo desea modificar?\
        \n1-Nombre\
        \n2-Apellido\
        \n3-Usuario\
        \n4-Password\
        \n5-Telefono\
        \n6-Finalizar\n";
    char menuPrincipalMensaje[] =
        "1-Alta de usuario.\
                 \n2-Modificar datos del usuario.\
                 \n3-Baja del usuario.\
                 \n4-Publicar producto.\
                 \n5-Modificar publicacion.\
                 \n6-Cancelar publicacion.\
                 \n7-Comprar producto.\
                 \n8-Listar publicaciones de usuario.\
                 \n9-Listar publicaciones.\
                 \n10-Listar usuarios.\
                 \n11-Salir\n";
    do
    {
        printf("%s", menuPrincipalMensaje);
        opcion = ingresarIntValido("Ingrese una opcion: ", "ERROR! La opcion ingresada no es valida.\n", 1, 11);
        switch(opcion)
        {
        case 1:
            clearScreen();
            auxiliar = eUsu_alta(usuarios, CANT_USUARIOS);
            mensajeRetorno(auxiliar, "\nNo quedan espacios disponibles\n", "\nUsuario dado de alta correctamente\n\n", "");
            break;
        case 2:
            clearScreen();
            auxiliar = eUsu_modif("Ingrese el ID del usuario a modificar ", menuModificacionUsuario, usuarios, CANT_USUARIOS);
            mensajeRetorno(auxiliar, "\nError, la ID no se encuentra.\n", "\nUsuario modificado correctamente\n\n", "");
            break;
        case 3:
            clearScreen();
            auxiliar = eUsu_baja("Ingrese el ID del usuario a dar de baja", usuarios, productos);
            mensajeRetorno(auxiliar, "La ID ingresada no se encuentra.\n","Usuario dado de baja correctamente\n", "");
            break;
        case 4:
            auxiliar = eProd_alta(productos, CANT_PRODUCTOS, usuarios, CANT_USUARIOS);
            mensajeRetorno(auxiliar, "La ID ingresada no se encuentra.\n", "No queda espacio.\n", "Producto agregado correctamente\n");
            break;
        case 5:
            auxiliar = eProd_modif("Ingrese el ID: ", productos, usuarios);
            mensajeRetorno(auxiliar, "La ID ingresada no se encuentra.\n", "ID del producto incorrecto\n", "Producto modificado correctamente\n");

            break;
        case 6:
            auxiliar = eProd_baja("Ingrese el ID: ", productos, usuarios);
            mensajeRetorno(auxiliar, "La ID ingresada no se encuentra.\n", "ID del producto incorrecto\n", "Publicacion cancelada correctamente.\n");
            break;
        case 7:

            break;
        case 8:
            auxiliar = listarPublicacionesDeUsuario("Ingrese el ID: ", productos, usuarios);
            mensajeRetorno(auxiliar, "La ID ingresada no se encuentra.\n", "", "");
            break;
        case 9:
            auxiliar = listarPublicaciones(productos, usuarios);
            break;
        case 10:
            auxiliar = mostrarListado(usuarios, productos);
            break;
        case 11:
            //SALIR
            break;
        default:
            system("pause");
            opcion = 0;
            break;
        }

    }
    while(opcion != 11);
    return 0;
}
