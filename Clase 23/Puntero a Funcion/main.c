#include <stdio.h>
#include <stdlib.h>

void funcionBienvenida(char* nombre);
void funcionDespedida(char* nombre);

void funcionDelegaLaFuncionalidad(void(*punteroFuncion)(char* elDato), char* nombre);
//void funcionalidadDelegada(void(*)(char*), char*);

int main()
{
    funcionDelegaLaFuncionalidad(funcionBienvenida, "natalia natalia");
    getche();
    funcionDelegaLaFuncionalidad(funcionDespedida, "natalia natalia");
    getche();


    //// Agregar ejemplos con màs parametros o sin parametros.




    return 0;
}

void funcionBienvenida(char* nombre)
{
    printf("Bienvenida %s a la empresa.\n",nombre);
}

void funcionDespedida(char* nombre)
{
    printf("Vos %s estas despedida -------->.",nombre);
}

void funcionDelegaLaFuncionalidad(void(*punteroFuncion)(char* elDato), char* nombre)
{
    punteroFuncion(nombre);
}
