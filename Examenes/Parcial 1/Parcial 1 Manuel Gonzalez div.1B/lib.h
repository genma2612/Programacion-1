#include "propietarios.h"
#include "ingresos.h"
#include "egresos.h"


int ePro_alta(ePropietarios[]);

int ePro_siguienteId(ePropietarios[]);

int ePro_buscarLugarLibre(ePropietarios[]);

int ePro_modif(char mensaje[], ePropietarios listado[], eIngreso ingresos[]);

int buscarPorId(ePropietarios[], int);

int ePro_baja(char mensaje[], ePropietarios listado[], eIngreso ingresos[], eEgreso egresos[]);

int ePro_mostrarListado(ePropietarios listado[]);

int devolverHorasEstadia();

int eAuto_Ingreso(eIngreso listado[], ePropietarios propietarios[]);

int eIngreso_buscarLugarLibre(eIngreso listado[]);

int eIngreso_siguienteId(eIngreso listado[]);

int ePro_mostrarListadoAutos(eIngreso ingresos[], ePropietarios propietarios[]);

int egresoAutomovil(eIngreso[], eEgreso[], ePropietarios[]);

float calcularImporte(eEgreso egresos[], int marca);

int buscarIdIngreso(eIngreso ingresos[], int id);

void mostrarRecaudacion(eEgreso listado[]);

void mostrarRecaudacionPorMarca(eEgreso listado[]);

float liquidacion(ePropietarios listado[],eIngreso ingresos[],eEgreso egresos[], int idPropietario);

int mostrarPropietario(ePropietarios listado[], eIngreso ingresos[]);

void propietariosDeAudi(ePropietarios listado[], eIngreso ingresos[]);

void mostrarEgresos(eEgreso egresos[]);

