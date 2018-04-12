#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vector[5] = {9,-3,5,14,-4};
    int i;
    for(i=0;i<5;i++) //variable de control i comienza en 0, los vectores estan indexados a partir de 0.
    {
        printf("%d\n", vector[i]); //%vector[i] muestra direccion en la memoria.
        //printf("%d --- Vector %d\n", i, &vector);
    }


    return 0;
}
