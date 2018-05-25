#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* pArchivo;
    char cadena[50]="Hola ";
/*
    pArchivo = fopen("archivo.txt", "w");

    if(pArchivo!=NULL)
    {
        fprintf(pArchivo, "%s %d", cadena, 1993); // Solo se puede imprimir strings.
        fclose(pArchivo);
        printf("Guardado!\n");
    }
    else
    {
        printf("Imposible guardar \n");
    }*/

    pArchivo = fopen("archivo.txt", "r");
    if(pArchivo!=NULL);
    {
        while(!feof(pArchivo)) //Lee linea por linea. fgets sòlo lee una linea.
        {
            fgets(cadena, 50, pArchivo);
            puts(cadena);
        }
        fclose(pArchivo);
    }
    return 0;







}
