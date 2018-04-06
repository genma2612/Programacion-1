#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

// Factorial recursivo.

/** \brief Calcula el factorial (!) de un numero.
 *
 * \param int Recibe un numero.
 * \return int El factorial de un numero recibido.
 *
 */
int factorial(int);

int main()
{
    int numero;
    int factor;
    numero = pedirEntero("Ingrese un numero ",0,1000);
    factor = factorial(numero);
    printf("El factorial es: %d", factor);

    return 0;
}


int factorial(int numero)
{
    int respuesta;
    if(numero == 0)
    {
        respuesta = 1;
    }
    else
    {
        respuesta = numero * factorial(numero-1); //factorial llama a factorial
    }
    return respuesta;
}


