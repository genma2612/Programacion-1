#include <stdio.h>
#include <stdlib.h>
#define TAM 5

void mostrarVector(int[], int); //int con corchetes representa la cadena de valores o vector. O cadena.
                                //El segundo int es el tamaño del vector.

int main()
{
    int vector[TAM] = {};
    int i;
    for(i=0;i<TAM;i++)
    {
        printf("Ingrese un numero: \n");
        scanf("%d", &vector[i]);
    }
    mostrarVector(vector, TAM); //se le pasa la direccion de memoria del vector (variable por referencia, o sea, su lugar en la memoria)
    return 0;
}

void mostrarVector(int vec[], int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("%d\n", vec[i]); // Pasaje por referencia, al estar asignado al mismo espacio de memoria, modificar el vector
    }                           // en la funcion tambièn lo harà en el main.
                                // valores entre variables se pasan por valor. Valores entre arrays se pasan por referencia.
}


