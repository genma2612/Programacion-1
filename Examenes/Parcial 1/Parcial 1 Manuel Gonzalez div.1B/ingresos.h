#define LIBRE 0
#define OCUPADO 1
#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTRO 4

typedef struct
{
    char patente[20];
    int marca;
    int idIngreso;
    int idPropietario;
    int estado;
}eIngreso;

int eIngreso_init(eIngreso[]);

int eIngreso_HC(eIngreso[]);


