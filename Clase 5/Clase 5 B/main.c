#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vector[5] = {}; //llaves vacias inicializa el vector con todos los elementos en 0.
    //int vector[5] = {}; //llaves vacias inicializa el vector con todos los elementos en 0.
    int i;

    for(i=0;i<5;i++)
    {
        vector[i] = 7; // barrido secuencial que asigna "7" a cada uno de los elementos del vector.
    }

    for(i=0;i<5;i++) // Desbordamiento: seguirìa escribiendo datos de la memoria bajo los reservados para el vector, pudiendo cambiar datos valiosos a otras espacios de memoria.
    {
        printf("Ingrese un numero: \n");
        scanf("%d", &vector[i]); // Entrada secuencial que asigna numeros ingresados a cada uno de los elementos del vector.
    }                            // El & asigna el sector de la memoria al vector.

    for(i=0;i<5;i++) // for(i=0;i<10;i++) Desbordamiento: seguirìa leyendo datos de la memoria bajo los reservados para el vector.
    {
        printf("%d\n", vector[i]);
    }


    return 0;
}
