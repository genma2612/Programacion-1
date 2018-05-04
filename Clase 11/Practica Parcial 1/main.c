#include <stdio.h>
#include <stdlib.h>
#include "usuarios.h"

#define CANT_USUARIOS 100
#define CANT_PRODUCTOS 1000
#define LIBRE 0
#define OCUPADO 1

void imprimirResultado(int valor, char error[], char sucess[]);

int main()
{
    int auxiliar;

    // Creación, inicialización y hardcodeo del vector usuarios.
    eUsuarios usuarios[CANT_USUARIOS];
    auxiliar = eUsu_init(usuarios,CANT_USUARIOS);
    auxiliar = eUsu_HC(usuarios, CANT_USUARIOS);

    int opcion=0;
    char menuModificacionUsuario[] =
        "Que campo desea modificar?\
        \n1-Nombre\
        \n2-Apellido\
        \n3-Usuario\
        \n4-Password\
        \n5-Telefono\
        \n6-Finalizar\
        \nIngrese una opcion: ";
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
                 \n11-Salir\
                 \nIngrese una opcion: ";
    do
    {
        printf("%s", menuPrincipalMensaje);
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            auxiliar = eUsu_alta(usuarios, CANT_USUARIOS);
            imprimirResultado(auxiliar, "\nNo quedan espacios disponibles\n", "\nUsuario dado de alta correctamente\n\n");
            break;
        case 2:
            auxiliar = eUsu_modif("Ingrese el ID del usuario a modificar ", menuModificacionUsuario, usuarios, CANT_USUARIOS);
            imprimirResultado(auxiliar, "\nNo se pudo modificar\n", "\nUsuario modificado correctamente\n\n");


            break;
        case 3:
            auxiliar = eUsu_baja("Ingrese el ID del usuario a dar de baja", usuarios, CANT_USUARIOS);
            imprimirResultado(auxiliar, "\nNo se pudo dar de baja.\n", "\nUsuario dado de baja correctamente\n\n");

            break;
        case 4:

            break;
        case 5:
            auxiliar = mostrarListado(usuarios, CANT_USUARIOS);

            break;
        case 6:

            break;
        case 7:

            break;
        case 8:

            break;
        case 9:

            break;
        case 10:

            break;
        case 11:
            //SALIR
            break;
        default:
            printf("\nNO ES UNA OPCION VALIDA!!!\n\n");
            system("pause");
            opcion = 0;
            break;
        }

    }
    while(opcion != 11);
    return 0;
}

void imprimirResultado(int valor, char error[], char sucess[])
{
    if(valor == 0)
    {
        printf("%s",error);
    }
    else
    {
        printf("%s",sucess);
    }
}
