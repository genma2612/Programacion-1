#include <stdio.h>
#include <stdlib.h>
#include "usuarios.h"

#define CANT_USUARIOS 100
#define CANT_PRODUCTOS 1000
#define LIBRE 0
#define OCUPADO 1

int main()
{
    int auxiliar;
    eUsuarios usuarios[CANT_USUARIOS];
    auxiliar = eUsu_init(usuarios,CANT_USUARIOS);
    auxiliar = eUsu_HC(usuarios, CANT_USUARIOS);

    int opcion=0;
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
        //clearScreen();
        //int opcion=0;

        switch(opcion)
        {
        case 1: // ALTA ABONADO
            auxiliar = eUsu_alta(usuarios, CANT_USUARIOS);
            break;
        case 2: // MODIFICAR ABONADO

            break;
        case 3: // BAJA ABONADO

            break;
        case 4: // NUEVA LLAMADA

            break;
        case 5: // FINALIZAR LLAMADA

            break;
        case 6: // INFORMES

            break;
        case 7: // LISTAR LLAMADAS

            //pause();
            break;
        case 8: // LISTAR ABONADOS

            //pause();
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

    }while(opcion != 11);

    return 0;
}
