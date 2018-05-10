#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    char nombre[20];
    char apellido[20];
    char direccion[20];
    char tarjeta[20];
    int idPropietario;
    int estado;
}ePropietarios;

int ePro_init(ePropietarios[]);

int ePro_HC(ePropietarios[]);



