#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* f;



    f = fopen("MiHTML.html", "w");

    if(f!=NULL)
    {
        fprintf(f, "<html> <head> HOLA! </head> </html>");

        fclose(f);
    }

    return 0;
}
