#include <stdio.h>
#include <stdlib.h>

int pedirNumero();

int main()
{
    int numero;
    int numero2;
    edad = pedirNumero();
    legajo = pedirNumero();
    printf("La edad es: %d\n", edad);
    printf("El legajo es: %d\n", legajo);
    return 0;
}

int pedirNumero()
{
    int numero;
    printf("Ingrese un numero\n");
    scanf("%d", &numero);
    return numero;
}
