#include "usuarios.h"
#include "productos.h"


// USUARIOS

int eUsu_alta(eUsuarios[],int);

int eUsu_siguienteId(eUsuarios[] ,int);

int eUsu_buscarLugarLibre(eUsuarios[],int);

int eUsu_modif(char mensaje[], char menu[], eUsuarios[], int);

int buscarPorId(eUsuarios[],int, int);

int eUsu_baja(char mensaje[], eUsuarios[], eProducto[]);

int mostrarListado(eUsuarios[], eProducto[]);


// PRODUCTOS

int eProd_alta(eProducto[], int, eUsuarios[], int);

int eProd_siguienteId(eProducto[] ,int);

int eProd_buscarLugarLibre(eProducto[],int);

int eProd_modif(char mensaje[], eProducto[], eUsuarios[]);

int buscarPorIdProducto(eProducto[],int, int);

int eProd_baja(char mensaje[], eProducto[], eUsuarios[]);



int listarPublicacionesDeUsuario(char mensaje[], eProducto producto[], eUsuarios usuarios[]);

int listarPublicaciones(eProducto productos[], eUsuarios listado[]);
