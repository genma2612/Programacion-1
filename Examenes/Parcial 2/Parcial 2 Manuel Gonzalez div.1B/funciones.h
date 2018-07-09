#include "ArrayList.h"

typedef struct
{
    int id;
    char nombre[30];
    int sueldo;
    int edad;
    char profesion[20];
} sEmpleados;

void comprobacionEinicializacion();

sEmpleados* newEmpleado();

int ingresoDeDatos(ArrayList* this);

int getId(sEmpleados* this);

char* getNombre(sEmpleados* this);

int getSueldo(sEmpleados* this);

int getEdad(sEmpleados* this);

char* getProfesion(sEmpleados* this);

int setID(sEmpleados* this, int id);

int setNombre(sEmpleados* this, char* nombre);

int setSueldo(sEmpleados* this, int sueldo);

int setEdad(sEmpleados* this, int edad);

int setProfesion(sEmpleados* this, char* profesion);

int mostrarLista(ArrayList* this);

int mostrarEmpleado(sEmpleados* this);

int funcionQueFiltra(void* item);

int filtrarEdad(sEmpleados* elemento);

int filtrarProfesion(void* elemento);
