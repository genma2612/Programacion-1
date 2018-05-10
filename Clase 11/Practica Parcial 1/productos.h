#define CANT_USUARIOS 100
#define CANT_PRODUCTOS 1000
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    char nombre[20];
    float precio;
    int stock;
    int cantVendida;
    int idProducto;
    int idVendedor;
    int estado;
}eProducto;

int eProd_init(eProducto[],int);

int eProd_HC(eProducto[],int);


