#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

// constructors

sNumeroNatural* newStruct()
{
    sNumeroNatural* aux;
    aux = (sNumeroNatural*) malloc(sizeof(sNumeroNatural));
}

/*sNumeroNatural* newStructWithParam(parametros)
{
    sNumeroNatural* aux = newStruct();
    set_int_entero1(aux, parametro);
    set_string_titulo(aux, "cadena");
}*/

// Seters & Geters

int set_int_numero(sNumeroNatural* this, int numero)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->numero = numero;
        retorno = 0;
    }
    return retorno;
}

int get_int_numero(sNumeroNatural* this)
{
    int numero = -1;
    if(this != NULL)
    {
        numero = this->numero;
    }
    return numero;
}

int set_int_par(sNumeroNatural* this, int par)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->par = par;
        retorno = 0;
    }
    return retorno;
}

int get_int_par(sNumeroNatural* this)
{
    int par = -1;
    if(this != NULL)
    {
        par = this->par;
    }
    return par;
}

int set_int_impar(sNumeroNatural* this, int impar)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->impar = impar;
        retorno = 0;
    }
    return retorno;
}

int get_int_impar(sNumeroNatural* this)
{
    int impar = -1;
    if(this != NULL)
    {
        impar = this->impar;
    }
    return impar;
}

int set_int_primo(sNumeroNatural* this, int primo)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->primo = primo;
        retorno = 0;
    }
    return retorno;
}

int get_int_primo(sNumeroNatural* this)
{
    int primo = -1;
    if(this != NULL)
    {
        primo = this->primo;
    }
    return primo;
}

int set_string_nombre(sNumeroNatural* this, char* nombre)
{
    int retorno=-1;
    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        retorno = 0;
    }
    return retorno;
}

char* get_string_nombre(sNumeroNatural* this)
{
    char* nombre = NULL;
    if(this != NULL)
    {
        nombre = this->nombre;
    }
    return nombre;
}

// ABM
/*
int altaStruct(ArrayList* this)
{
    int retorno=-1;
    sNumeroNatural* aux = newStruct();
    char auxString[1][50];
    if(this != NULL && aux!=NULL)
    {
        retorno = 0;
        set_int_id(aux, maxID(this)+1);
        set_string_nombre(aux, ingresarStringValida("Ingrese el nombre: \n", "Error\n", "Nombre demasiado largo\n", auxString, 20));
        set_string_apellido(aux, ingresarStringValida("Ingrese el apellido: \n", "Error\n", "apellido demasiado largo\n", auxString, 20));
        this->add(this, aux);
    }
    return retorno;
}

int maxID(ArrayList* this)
{
    int maxID=-1;
    int i;
    sNumeroNatural* aux;
    if(this != NULL)
    {
        maxID = 0;
        for(i=0; i<this->len(this); i++)
        {
            aux = this->get(this, i);
            if(get_int_id(aux) > maxID)
            {
                maxID = get_int_id(aux);
            }
        }
    }
    return maxID;
}

int modificacionStruct(ArrayList* this)
{
    int retorno=-1;
    int opcion;
    int index;
    sNumeroNatural* aux;
    char auxString[1][50];
    if(this != NULL)
    {
        retorno = 0;
        mostrarLista(this, "");
        opcion = ingresarIntValido("Seleccione ID a modificar:\n", "Numero ingresado incorrecto.\n", 1, maxID(this));
        index = indexByID(this, opcion);
        aux = this->get(this, index);
        do
        {
            opcion = menuSwitch("1-Nombre\n2-Apellido\n3-Salir\n", 1, 3);
            switch(opcion)
            {
            case 1:
                retorno = 1;
                printf("Cambiar nombre (Actual: %s)\n", get_string_nombre(aux));
                ingresarStringValida("Ingrese el nuevo nombre:\n", "Utilice solamente letras.\n", "Nombre demasiado largo.\n", auxString, 20);
                set_string_nombre(aux, auxString);
                break;
            case 2:
                retorno = 1;
                printf("Cambiar apellido (Actual: %s)\n", get_string_apellido(aux));
                ingresarStringValida("Ingrese el nuevo apellido:\n", "Utilice solamente letras.\n", "apellido demasiado largo.\n", auxString, 20);
                set_string_nombre(aux, auxString);
                break;
            case 3:
                break;
            }
        }
        while(opcion != 3);
    }
    return retorno;
}

int indexByID(ArrayList* this, int idToSearch)
{
    int retorno = -1;
    int i;
    sNumeroNatural* aux;
    if(this != NULL && idToSearch > 0)
    {
        for(i=0; i<this->len(this); i++)
        {
            aux = this->get(this, i);
            if(get_int_id(aux) == idToSearch)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int bajaStruct(ArrayList* this)
{
    int retorno=-1;
    int opcion;
    int index;
    if(this != NULL)
    {
        retorno = 0;
        mostrarLista(this, "");
        opcion = ingresarIntValido("Seleccione ID a dar de baja:\n", "Numero ingresado incorrecto.\n", 1, maxID(this));
        index = indexByID(this, opcion);
        printf("Se dara de baja a %s\n...", get_string_nombre(this->get(this, index)));
        opcion = ingresarIntValido("ESTA SEGURO? 1-SI 2-NO\n", "Numero incorrecto.\n", 1, 2);
        if(opcion == 1)
        {
            retorno = 1;
            this->remove(this, index);
        }
    }
    return retorno;
}
*/
// Funciones

int menuSwitch(char* menu, int min, int max)
{
    int retorno;
    printf("%s", menu);
    retorno = ingresarIntValido("Ingrese una opcion: ", "ERROR! La opcion ingresada no es valida.\n", min, max);
    return retorno;
}

int criterioRepetidos(ArrayList* repetidos, ArrayList* noRepetidos)
{
    int retorno=0;
    int i;
    int j;
    int noRepe;
    sNumeroNatural* aux = NULL;
    sNumeroNatural* auxj = NULL;
    if(repetidos != NULL && noRepetidos != NULL)
    {
        retorno = 1;
        for(i=0; i<repetidos->len(repetidos); i++)
        {
            aux = al_get(repetidos, i);
            noRepe = estaRepetido(repetidos, aux->numero);
            if(noRepe == 0)
            {
                noRepetidos->add(noRepetidos, repetidos->pop(repetidos, i));
            }
        }
    }
    return retorno;
}

int estaRepetido(ArrayList* this, int elemento)
{
    int retorno = 1;
    int i;
    int cont=0;
    sNumeroNatural* aux = NULL;
    if(this != NULL)
    {
        for(i=0; i<this->len(this); i++)
        {
            aux = al_get(this, i);
            if(get_int_numero(aux) == elemento)
            {
                cont++;
            }
        }
        if(cont < 2)
        {
            retorno = 0;
        }
    }
    return retorno;
}

int mostrarLista(ArrayList* this, char* columnas)
{
    int i;
    int len = this->len(this);
    int contador=1;
    int listo = -1;
    sNumeroNatural* actual;
    if(this != NULL)
    {
        if(columnas != NULL && strlen(columnas) < 0)
        {
            printf("%s\n", columnas);
        }
        for(i=0; i<len; i++)
        {
            printf("%2d ", i+1);
            actual = (sNumeroNatural*) this->get(this, i);
            mostrarUno(actual);
            if(i == 10)
            {
                //pause();
            }
        }
        listo = 0;
    }
    return listo;
}

int mostrarUno(sNumeroNatural* this)
{
    int retorno=-1;
    if(this != NULL)
    {
        printf("%2d %-20.40s   %d  %d  %d\n", get_int_numero(this), get_string_nombre(this), get_int_par(this), get_int_impar(this), get_int_primo(this));
        retorno = 0;
    }
    return retorno;
}

/*int funcionQueFiltra(void* item)
{
    int retorno = 0;
    sNumeroNatural* elemento = (sNumeroNatural*) item;
    if(getEdad(elemento) > 30 && strcmp(get (elemento), "asdf") == 0)
    {
        retorno = 1;
    }
    return retorno;
}
*/
// Archivos

int lecturaDeDatos(ArrayList* this)
{
    int retorno=-1;
    int flag=0;
    FILE* data = fopen("datos.csv","r");
    if(data!=NULL)
    {
        retorno = 1;
        sNumeroNatural* structAux;
        // campos
        int numero;
        char nombre[100];
        int par=0;
        int impar=0;
        int primo=0;
        //
        do
        {
            structAux = newStruct();
            if(flag==0)
            {
                fscanf(data, "%*[^\n]\n", NULL);
                flag = 1;
            }
            fscanf(data, "%d,%[^,],%d,%d,%d\n", &numero, nombre, &par, &impar, &primo);
            if(numero > 0 && strlen(nombre) < 50)
            {
                if(numero %2 == 0)
                {
                    par = 1;
                }
                if(numero %2 != 0)
                {
                    impar = 1;
                }
                primo = esPrimo(numero);
                set_int_numero(structAux, numero);
                set_string_nombre(structAux, nombre);
                set_int_par(structAux, par);
                set_int_impar(structAux, impar);
                set_int_primo(structAux, primo);
                this->add(this, structAux);
            }
        }
        while(!feof(data));
    }
    return retorno;
}

int esPrimo(int num)
{
    int i;
    int primo=0;
    int cont=0;
    for(i=1; i<=num; i++)
    {
        if(num %i ==0)
        {
            cont++;
        }
    }
    if(cont == 2)
    {
        primo = 1;
    }
    return primo;
}

int lecturaDeDatosBIN(ArrayList* this)
{
    int retorno=-1;
    int aux;
    int temp=0;
    sNumeroNatural* structAux;
    FILE* binario = fopen("binario.dat", "rb");
    if(binario != NULL)
    {
        retorno = 1;
        while(!feof(binario))
        {
            structAux = newStruct();
            if(fread(structAux, sizeof(sNumeroNatural), 1, binario) != 0)
            {
                this->add(this, structAux);
            }
        }
        fclose(binario);
    }
    return retorno;
}

void actualizarArchivo(ArrayList* this, char* nombre)
{
    int i;
    sNumeroNatural* auxStruc;
    FILE* data = fopen(nombre,"w");
    if(data != NULL)
    {
        for(i=0; i<this->len(this); i++)
        {
            auxStruc = this->get(this, i);
            fprintf(data, "%d,%s,%d,%d,%d\n", get_int_numero(auxStruc), get_string_nombre(auxStruc), get_int_par(auxStruc), get_int_impar(auxStruc), get_int_primo(auxStruc));
        }
        fclose(data);
    }
    else
    {
        printf("\nERROR. No se puede abrir.\n");
    }
}

void actualizarArchivoBIN(ArrayList* this)
{
    int i;
    sNumeroNatural* auxStruc;
    FILE* binario = fopen("binario.dat", "wb");
    if(binario != NULL)
    {
        for(i=0; i<this->len(this); i++)
        {
            auxStruc = al_get(this, i);
            fwrite(auxStruc, sizeof(sNumeroNatural),1, binario);
        }
        fclose(binario);
    }
    else
    {
        printf("\nERROR. No se puede abrir.\n");
    }
}

// Comparadores

int compararEntero(void* E1, void* E2)
{
    int retorno = 1;
    sNumeroNatural* COMP1 = (sNumeroNatural*) E1;
    sNumeroNatural* COMP2 = (sNumeroNatural*) E2;
    if(COMP1->numero < COMP2->numero)
    {
        retorno = -1;
    }
    else if(COMP1->numero == COMP2->numero)
    {
        retorno = 0;
    }
    return retorno;
}
/*
int compararCadena(void* E1, void* E2)
{
    sNumeroNatural* COMP1 = (sNumeroNatural*) E1;
    sNumeroNatural* COMP2 = (sNumeroNatural*) E2;
    return strcmp(COMP1->nombre, COMP2->nombre);
}
*/
