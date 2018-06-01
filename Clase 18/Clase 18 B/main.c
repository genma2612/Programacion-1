#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int main()
{
    // int vector[5]; esto inicializa en stack.

    int* pVector;
    int* aux;
    int i;
    pVector = (int*) malloc(sizeof(int)*TAM); //Reserva memoria en heap.

    if(pVector!=NULL)
    {
        for(i=0; i<TAM; i++)
        {
            *(pVector+i) = i+1;
        }
        for(i=0; i<TAM; i++)
        {
            printf("%d ", *(pVector+i));
        }
        // pVector = (int*) realloc(pVector, sizeof(int) * (TAM*2); // Si da null, puedo perder la informacion original de pVector.
        aux = (int*) realloc(pVector, sizeof(int) * (TAM*2)); // Verifico con un puntero auxiliar, si no es nulo, asigno a pVector.
        printf("\nDespues del realloc 1\n");
        if(aux!=NULL)
        {
            pVector = aux;
            for(i=TAM; i<TAM*2; i++)
            {
                *(pVector+i) = i+1;
            }
            for(i=0; i<TAM*2; i++)
            {
                printf("%d ", *(pVector+i));
            }

            aux = (int*) realloc(pVector, sizeof(int) * 4); // Verifico con un puntero auxiliar, si no es nulo, asigno a pVector.
            printf("\nDespues del realloc 2 (Por menos)\n");
            if(aux!=NULL)
            {
                pVector = aux;
                for(i=0; i<4; i++)
                {
                    printf("%d ", *(pVector+i));
                }
            }
            free(aux); //Abajo de todo, cuando se que no necesito mas la informacion en memoria. == free(pVector)
        }
    }
    // pVector = vector; reserva memoria en stack, no sirve.
    return 0;
}
