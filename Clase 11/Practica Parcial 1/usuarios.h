#include <stdio.h>
#include <stdlib.h>

#define CANT_USUARIOS 100
#define CANT_PRODUCTOS 1000

typedef struct
{
    char usuario[20];
    char nombre[50];
    int id;
    int estado;
}eUsuarios;

int eUsu_init(eUsuarios[],int);

int eUsu_HC(eUsuarios[],int);

int eUsu_alta(eUsuarios[],int);

int eUsu_siguienteId(eUsuarios[] ,int);

int eUsu_buscarLugarLibre(eUsuarios[],int);
