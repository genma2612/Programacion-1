#include <stdio.h>
#include <stdlib.h>

/*
* Se ingresan numeros (Tienen que ser distintos que 0), no se sabe cuantos.
* Se pide mostrar:
* Cantidad de pares e impares.
* Porcentaje de numeros positivos y negativos.
* Maximo y minimo.
* Maximo numero par.
* Cantidad de numeros comprendidos entre 125 y 236.
*/

int main()
{
    int numero,maximo=0,maximoPar=0,minimo=0,contador,contPar=0,contImpar=0,ContEntre=0,flag=1,contPosi=0,contNega=0;
    float porNeg,porPos;
    char seguir;

    do
    {
        printf("Ingrese un numero ");
        scanf("%d", &numero);
        while(numero == 0)
        {
            printf("Reingrese un numero distinto a 0 ");
            scanf("d", &numero);
        }

        printf("Continuar? (s/n) \n");
        seguir = getch();

        if (numero > maximo || flag == 1)
        {
            maximo = numero;
            if (maximo % 2 == 0)
            {
                maximoPar = maximo;
            }
        }
        if (numero < minimo || flag == 1)
        {
            minimo = numero;
            flag = 0;
        }
        if (numero % 2 == 0)
        {
            contPar++;
        }
        if (numero % 2 != 0)
        {
            contImpar++;
        }
        if (numero < 0)
        {
            contNega++;
        }
        if (numero > 0)
        {
            contPosi++;
        }
        if (numero >= 124 && numero <= 236)
        {
            ContEntre++;
        }

    } while (seguir == 's');

    contador = contPar + contImpar;
    porPos = (float) (contPosi * 100) / contador;
    porNeg = 100 - porPos;

    printf("\nCant. pares: %d , cant. de impares: %d.\n",contPar,contImpar);
    printf("El numero maximo es: %d y el minimo: %d.\n",maximo,minimo);
    printf("Numeros entre 125 y 236 : %d.\n",ContEntre);
    printf("Porcentaje de numeros positivos: %.2f.\n",porPos);
    printf("porcentaje de numeros negativos: %.2f.\n",porNeg);
    printf("El numero par mas grande es: %d.\n",maximoPar);

    return 0;
}
