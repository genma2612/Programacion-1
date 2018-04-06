#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

//Prototipo 1
void sumar1(void);
//Prototipo 2
void sumar2(int, int);
//Prototipo 3
int sumar3();
//Prototipo 4
int sumar4(int, int);


int main()
{
    //sumar1();
    //sumar2(9, 1);
    //int suma
    //suma = sumar3();
    int resultado;
    int numero1;
    int numero2;
    numero1 = pedirEntero("Ingrese un numero ", 1, 1000);
    numero2 = pedirEntero("Ingrese un numero ", 1, 1000);
    resultado = sumar4(numero1, numero2);
    printf("La suma es: %d", resultado);
    return 0;
}
//Prototipo 1
void sumar1(void)
{
    int numero1;
    int numero2;
    int suma;
    numero1 = pedirEntero("Ingrese un numero\n", 1, 1000);
    numero2 = pedirEntero("Ingrese un numero\n", 1, 1000);
    suma = numero1 + numero2;
    printf("La suma es: %d", suma);
}

//Prototipo 2
void sumar2(int numero1, int numero2)
{
    int suma;
    suma = numero1 + numero2;
    printf("La suma es: %d", suma);
}

//Prototipo 3
int sumar3()
{
    int numero1;
    int numero2;
    int suma;
    numero1 = pedirEntero("Ingrese un numero ", 1, 1000);
    numero2 = pedirEntero("Ingrese un numero ", 1, 1000);
    suma = numero1 + numero2;
    return suma;
}

//Prototipo 4
int sumar4(int n1, int n2)
{
    int suma;
    suma = n1 + n2;
    return suma;
}
