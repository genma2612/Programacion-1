#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int a;
    char b;
}dato;


int main()
{
    dato d;
    d.a=5;
    d.b='A';


    dato* pDato;

    pDato = &d;


    //printf("%d - %c", (*pDato).a, (*pDato).b); //Sin operador flecha.
    printf("%d - %c", pDato->a, pDato->b); //Operador flecha


    /*int i;
    dato l[2]

    pLista = l;


    (pLista+1)->a
    (*(pLista+i)).a



*/
    // sizeof
    //printf("%d -- %c\n", d.a, d.b);
    return 0;
}
