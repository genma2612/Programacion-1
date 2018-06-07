#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/


int main()
{
    int size;
    int i;
    int aux;
    ArrayList* lista;
    lista = al_newArrayList();
    Employee* auxEmployee;

    // Empleado 1
    Employee* empleado1;
    empleado1 = (Employee*) malloc(sizeof(Employee));
    empleado1->id = 1111;
    strcpy(empleado1->name, "Pedro");
    strcpy(empleado1->lastName, "Perez");
    empleado1->isEmpty = 1;

    // Empleado 2
    Employee* empleado2;
    empleado2 = (Employee*) malloc(sizeof(Employee));
    empleado2->id = 2222;
    strcpy(empleado2->name, "Juan");
    strcpy(empleado2->lastName, "Gomez");
    empleado2->isEmpty = 1;
    ////
    al_add(lista, empleado1); // Agrega una estructura al "array de punteros". Lista y empleado
    al_add(lista, empleado2); // Agrega una estructura al "array de punteros". Lista y empleado

    size = al_len(lista); //Leo el size del arrayList
    printf("Cant. de elementos: %d.\n", size);
    ////
    // Funcion al_Sort
    //printf("Resultado del compare: %d\n", employee_compare(empleado1, empleado2));
    al_sort(lista, employee_compareName, 1); // lista de Arrays, DIRECCION DE LA FUNCION QUE UTILIZARA al_sort, criterio A/Z - Z/A
    for(i=0;i<size;i++)
    {
        auxEmployee = (Employee*) al_get(lista, i); // Lista, posiciòn
        employee_print(auxEmployee); //Muestro el empleado.
    }
    ////
    return 0;
}
