#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Punteros
    int *punteroNumero;
    int numero;
    int numeroDos;
    numero=66;
    numeroDos=&numero; //asignacion memoria
    punteroNumero=&numero; //asigna la memoria de una variable
    printf("a- %d\n", numeroDos);
    numeroDos=*punteroNumero; //asignacion valor
    printf("b- %d\n",numeroDos);
    //*punteroNumero=&numero; //No funciona con * al principio
    //*punteroNumero=55; //No es un entero. Es un puntero a entero.
    printf("%d\n", numero);
    printf("%d\n", numeroDos);
    printf("%p\n", &numero);
    printf("%p\n", punteroNumero);
    printf("%p\n", &punteroNumero);
    printf("%d\n", *punteroNumero);
    //printf("%d", *punteroNumero);
    return 0;
}
