#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;

    char buffer[100] = {"Esto es un texto dentro del fichero"};
    char bufferIn[100];

    fp = fopen("fichero.txt", "w");

    fprintf(fp, buffer);

    fclose(fp);
    system("pause");
    system("cls");

    fp=fopen("fichero.txt", "r");
    if(fp == NULL)
    {
        printf("Archivo no encontrado\n");
    }
    else
    {
        fgets(bufferIn, 100, fp);
        puts(bufferIn);
    }

    return 0;
}
