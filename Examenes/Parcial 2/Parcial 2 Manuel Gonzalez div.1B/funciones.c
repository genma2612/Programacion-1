#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

sEmpleados* newEmpleado()
{
    sEmpleados* aux;
    aux = (sEmpleados*) malloc(sizeof(sEmpleados));
}

int setID(sEmpleados* this, int id)
{
    int retorno=-1;
    if(this != NULL && id > 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

int setNombre(sEmpleados* this, char* nombre)
{
    int retorno=-1;
    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        retorno = 0;
    }
    return retorno;
}

int setSueldo(sEmpleados* this, int sueldo)
{
    int retorno=-1;
    if(this != NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
        retorno = 0;
    }
    return retorno;
}

int setEdad(sEmpleados* this, int edad)
{
    int retorno=-1;
    if(this != NULL && edad > 0)
    {
        this->edad = edad;
        retorno = 0;
    }
    return retorno;
}

int getId(sEmpleados* this)
{
    int id=-1;
    if(this != NULL)
    {
        id = this->id;
    }
    return id;
}

char* getNombre(sEmpleados* this)
{
    char* nombre=NULL;
    if(this != NULL)
    {
        nombre = this->nombre;
    }
    return nombre;
}

int getSueldo(sEmpleados* this)
{
    int sueldo=-1;
    if(this != NULL)
    {
        sueldo = this->sueldo;
    }
    return sueldo;
}

int getEdad(sEmpleados* this)
{
    int edad=-1;
    if(this != NULL)
    {
        edad = this->edad;
    }
    return edad;
}

char* getProfesion(sEmpleados* this)
{
    char* profesion=NULL;
    if(this != NULL)
    {
        profesion = this->profesion;
    }
    return profesion;
}

int setProfesion(sEmpleados* this, char* profesion)
{
    int retorno=-1;
    if(this != NULL && profesion != NULL)
    {
        strcpy(this->profesion, profesion);
        retorno = 0;
    }
    return retorno;
}




void comprobacionEinicializacion()
{
    int i;
    int id[5]={1,2,3,4,5};
    char nombre[5][30]={"Juan","Pedro","Maria","Luis","Gabriela"};
    int sueldo[5]={1000,2000,1000,800,2500};
    int edad[5]={25,30,22,26,21};
    char profesion[5][20]={"analista","analista","programador","tester","programador"};
    FILE* data;
    if((data = fopen("data.csv","r"))==NULL)
    {
        if((data=fopen("data.csv","w"))!=NULL)
        {
            for(i=0; i<5; i++)
            {
                fprintf(data, "%d,%s,%d,%d,%s\n", id[i],nombre[i],sueldo[i],edad[i],profesion[i]);
            }
            fclose(data);
        }
    }
}

int ingresoDeDatos(ArrayList* this)
{
    FILE* data = fopen("data.csv","r");
    sEmpleados* empleadoAux;
    int retorno=-1;
    int id;
    char nombre[30];
    int sueldo;
    int edad;
    char profesion[20];
    do{
        empleadoAux = newEmpleado();
        fscanf(data, "%d,%[^,],%d,%d,%[^\n]\n", &id,nombre,&sueldo,&edad,profesion);
        setID(empleadoAux, id);
        setNombre(empleadoAux, nombre);
        setSueldo(empleadoAux, sueldo);
        setEdad(empleadoAux, edad);
        setProfesion(empleadoAux, profesion);
        this->add(this, empleadoAux);
    }while(!feof(data));
}

int mostrarLista(ArrayList* this)
{
    int i;
    int len = this->len(this);
    int listo = -1;
    sEmpleados* empleadoActual;
    if(this != NULL)
    {
        for(i=0; i<len; i++)
        {
            empleadoActual = (sEmpleados*) this->get(this, i);
            mostrarEmpleado(empleadoActual);
        }
        listo = 0;
    }
    return listo;
}

int mostrarEmpleado(sEmpleados* this)
{
    int retorno=-1;
    if(this != NULL)
    {
        printf("%d %s %d %d %s\n", getId(this), getNombre(this), getSueldo(this), getEdad(this), getProfesion(this));
        retorno = 0;
    }
    return retorno;
}

int funcionQueFiltra(void* item)
{
    int retorno = 0;
    sEmpleados* elemento = (sEmpleados*) item;
    if(getEdad(elemento) > 30 && strcmp(getProfesion(elemento), "programador") == 0)
    {
        retorno = 1;
    }
    return retorno;
}
