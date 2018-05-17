#define LIBRE 0
#define OCUPADO 1
#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTRO 4

typedef struct
{
    int marca;
    float importe;
    int idPropietario;
    int estado;
}eEgreso;

int eEgreso_init(eEgreso[]);

int eEgreso_HC(eEgreso[]);



