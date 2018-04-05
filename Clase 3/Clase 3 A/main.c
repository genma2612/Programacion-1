#include <stdio.h>
#include <stdlib.h>

/*Primero se hace la -declaracion, prototipo o firma- de la funcion
Estructura de funciòn:

tipo_de_dato_devuelto identificador (parametros de entrada)

tipo_de_dato_devuelto: void, float, int, char, etc.

identificador: nombre representativo: verbo + objeto.

parametros de entrada: Son opcionales. Se declara una variable por
cada dato. Cumplen las mismas reglas que la declaraciòn de variables.

*/

int mostrarEIncrementar(int);
// cuando la funcion no recibe un valor se completan los () con el tipo generico "void". Vacio recibe un entero.
// Puede declararse una variable o solo el tipo de dato que recibirà.

int main()
{
    int numero;
    int incremento;
    printf("Ingrese un numero\n");
    scanf("%d", &numero);
    // mostrarEIncrementar(numero); //parametro actual
    incremento = mostrarEIncrementar(numero);
    printf("El numero incrementado es: %d\n",incremento);
    return 0;
}

// 2do implementaciòn o desarrollo de la funciòn.
// Los parametros entre () se denominan parametros formales
// Las variables pueden tener el mismo nombre que otras siempre que existan en distintos
// contextos (Cada variable asigna un valor segùn la funcion.) Pertenecen a direcciones de memoria distintas
int mostrarEIncrementar(int numero) //parametro formal (Recibe el valor del "parametro actual", el nombre no influye.)
{
    int retorno;
    printf("El numero ingresado es: %d\n",numero);
    retorno = numero + 10;
    return retorno;
}
