#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nombre[20]={"Mi nombre"};
    char *apellido={"Mi apellido"};
    char *punteros;
    punteros = nombre;

    printf("%s\n",nombre);
    printf("%s\n",apellido);

    printf("%s\n\n", punteros);

    int i;

    for(i=0;*(apellido+i) != '\0';i++)
    {
        printf("%c\n",*(apellido+i));
    }
    return 0;
}
