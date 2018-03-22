#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero1;
    float numero2;
    char letra;
    float suma;
    printf("Ingrese un numero entero: ");
    scanf("%d", &numero1);
    printf("Ingrese un numero con coma: ");
    scanf("%f", &numero2);
    printf("Ingrese una letra: \n");
    letra = getch();
    //fflush(stdin); // fflush: vacia buffer, stdin es buffer de entrada
    //scanf("%c", &letra); //espacio entre comilla y %, buffer vacio
    suma = numero1 + numero2;
    printf("El 1er numero es: %d y el 2do es: %.1f\n",numero1,numero2);
    printf("La suma es: %.1f\n",suma);
    printf("La letra es %c\n",letra);
    return 0;
}
