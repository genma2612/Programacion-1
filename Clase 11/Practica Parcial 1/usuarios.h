#define CANT_USUARIOS 100
#define CANT_PRODUCTOS 1000
#define LIBRE 0
#define OCUPADO 1

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



