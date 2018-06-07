#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"


int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    int retorno;
    return retorno;
}

int employee_compareName(void* pEmployeeA,void* pEmployeeB) //En este caso, por nombre.
{
    int retorno;
    Employee* emp1 = (Employee*) pEmployeeA;
    Employee* emp2 = (Employee*) pEmployeeB;
    retorno = strcmp(emp1->name, emp2->name);
    return retorno;
}

int employee_compareLastName(void* pEmployeeA,void* pEmployeeB) //En este caso, por nombre.
{
    int retorno;
    Employee* emp1 = (Employee*) pEmployeeA;
    Employee* emp2 = (Employee*) pEmployeeB;
    retorno = strcmp(emp1->lastName, emp2->lastName);
    return retorno;
}

void employee_print(Employee* this)
{
    printf("Nombre y apellido: %s %s. ID: %d.\n", this->name, this->lastName, this->id);
}


Employee* employee_new(void)
{

    Employee* returnAux = NULL;



    return returnAux;

}

void employee_delete(Employee* this)
{


}

int employee_setId(Employee* this, int id)
{

    return 0;

}

int employee_getId(Employee* this)
{

    return 0;

}


