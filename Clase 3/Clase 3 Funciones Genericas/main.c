#include <stdio.h>
#include <stdlib.h>

int pedirEntero(char[], int, int);
int validarEntero(int, int, int, char[]);
int pedirFlotante(char[], float, float);
char pedirChar(char[], char, char);

int main()
{
    int edad;       // Entre 18 y 60 años
    int legajo;     // Entre 1 y 1000
    int nota;       // Entre 1 y 10
    edad = pedirEntero("Ingrese edad: \n", 18, 60);
    legajo = pedirEntero("Ingrese legajo: \n", 1, 1000);
    nota = pedirEntero("Ingrese nota: \n", 1, 10);
    printf("La edad es: %d \nEl legajo es: %d \nLa nota es: %d", edad,legajo,nota);
    return 0;
}

int pedirEntero(char mensaje[], int min, int max)
{
    int numero;
    printf("%s", mensaje); //%s es para cadena (Vector de characters).
    scanf("%d", &numero);
    numero = validarEntero(numero, min, max, mensaje);
    return numero;
}

int validarEntero(int dato, int min, int max, char mensaje[])
{
        while(dato < min || dato > max)
    {
        printf("Error! %s", mensaje);
        scanf("%d", &dato);
    }
    // return dato // Al ser el mismo dato que entra y sale, no es necesario declarar return
}

int pedirFlotante(char[], float, float)
{
    int numero;
    printf("%s", mensaje);
    scanf("%f", &numero);
}


char pedirChar(char[], char, char)
{
    char caracter;
    printf("%s", mensaje);
    scanf("%c", &caracter);
}

