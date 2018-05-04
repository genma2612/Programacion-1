#include <stdio.h>
#include <stdlib.h>

#define CANT_USUARIOS 100
#define CANT_PRODUCTOS 1000

typedef struct
{
    char nombre[20];
    char apellido[20];
    char usuario[20];
    char password[20];
    char telefono[10];
    int id;
    int estado;
}eUsuarios;

int eUsu_init(eUsuarios[],int);

int eUsu_HC(eUsuarios[],int);

int eUsu_alta(eUsuarios[],int);

int eUsu_siguienteId(eUsuarios[] ,int);

int eUsu_buscarLugarLibre(eUsuarios[],int);

int eUsu_modif(char mensaje[], char menu[], eUsuarios[], int);

int buscarPorId(eUsuarios[],int, int);

int eUsu_baja(char mensaje[], eUsuarios[],int);

int mostrarListado(eUsuarios[], int);
