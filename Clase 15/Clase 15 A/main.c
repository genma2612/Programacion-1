#include <stdio.h>
#include <stdlib.h>

int cargarArray(int*, int);
void mostrarArray(int*, int);

int main()
{
    int vector[3];

    int* p;
    //puntero = vector;

    if(cargarArray(vector, 3))
       {
           printf("Carga exitosa\n");
       }
    else
        {
            printf("Error al cargar los datos.\n");
        }
    mostrarArray(vector, 3);


    //printf("%d\n", vector);
    //printf("%d\n", &vector[0]); //Redundante
    //printf("%d\n", &vector);    //Redundante



    return 0;
}


int cargarArray(int* array, int tam)
{
    int i;
    int retorno=0;
    if(array!=NULL)
    {
        retorno = 1;
        for(i=0; i<tam; i++)
        {
            printf("Ingrese un numero:\n");
            scanf("%d", array+i);
        }
    }
    return retorno;
}

void mostrarArray(int* array, int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        printf("%d\n", *(array+i));
    }
}
