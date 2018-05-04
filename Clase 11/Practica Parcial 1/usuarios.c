#include <string.h>
#include "usuarios.h"

#define LIBRE 0
#define OCUPADO 1

int eUsu_init(eUsuarios listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado = LIBRE;
            listado[i].id = 0;
        }
    }
    return retorno;
}

int eUsu_HC(eUsuarios listado[], int limite)
{
    char nombre[][20]= {"Pedro","Juan","Luis","Maria","Andrea"};
    char apellido[][20]= {"perez","dasse","gomez","garcia","fernandez"};
    char usuarios[][20]= {"Pedro92","Juancho19","LuisPerez2","Mary2017","andre15"};
    char password[][20]= {"123456", "contraseña22", "passsecreta", "secretpassword", "1111"};
    char telefono[][10]= {"1111-1111","2222-2222","3333-3333","4444-4444","5555-5555"};
    int ids[5]= {0,1,2,3,4};
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<5; i++)
        {
            strcpy(listado[i].nombre, nombre[i]);
            strcpy(listado[i].apellido, apellido[i]);
            strcpy(listado[i].usuario, usuarios[i]);
            strcpy(listado[i].password, password[i]);
            strcpy(listado[i].telefono, telefono[i]);
            listado[i].id = ids[i];
            listado[i].estado = OCUPADO;
        }
    }
    return retorno;
}

int eUsu_alta(eUsuarios listado[],int limite)
{
    int retorno = 0;
    int id;
    int indice;
    if(limite > 0 && listado != NULL)
    {
        indice = eUsu_buscarLugarLibre(listado,limite);
        if(indice >= 0)
        {
            id = eUsu_siguienteId(listado,limite);
            printf("Ingrese nombre: \n");
            fflush(stdin);
            gets(listado[indice].nombre);
            printf("Ingrese apellido: \n");
            fflush(stdin);
            gets(listado[indice].apellido);
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

int eUsu_baja(char mensaje[], eUsuarios listado[],int limite)
{
    int retorno = 0;
    int indice;
    int idaux;
    printf("%s", mensaje);
    scanf("%d", &idaux);
    indice = buscarPorId(listado, CANT_USUARIOS, idaux);
    while(indice < 0)
    {
        printf("Error, la ID no se encuentra\n");
        system("pause");
        printf("%s", mensaje);
        scanf("%d", &idaux);
        indice = buscarPorId(listado, CANT_USUARIOS, idaux);
    }
    retorno = 1;
    listado[indice].estado = LIBRE;
    return retorno;
}

int mostrarListado(eUsuarios listado[], int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 1;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado==OCUPADO)
            {
                printf("%s - %s - %s - %s - %s - %d - %d\n", listado[i].nombre, listado[i].apellido, listado[i].usuario, listado[i].password, listado[i].telefono, listado[i].id, listado[i].estado);
            }
        }
        printf("\n");
    }
    return retorno;
}
