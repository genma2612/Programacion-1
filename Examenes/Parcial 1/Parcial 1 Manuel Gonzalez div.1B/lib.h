#include "propietarios.h"
#include "ingresos.h"
#include "egresos.h"


/** \brief Registra un nuevo propietario miembro del estacionamiento.
 *
 * \param ePropietarios[] array de propietarios.
 * \return int Cod. de mensaje.
 *
 */
int ePro_alta(ePropietarios[]);

/** \brief Genera una ID para un nuevo miembro.
 *
 * \param ePropietarios[] Array de propietarios.
 * \return int ID generada.
 *
 */
int ePro_siguienteId(ePropietarios[]);

/** \brief Busca si hay lugar disponible para un nuevo miembro.
 *
 * \param ePropietarios[] array de propietarios.
 * \return int Retorna el indice disponible, -1 si no lo hay.
 *
 */
int ePro_buscarLugarLibre(ePropietarios[]);

/** \brief Modificacion de la tarjeta de un miembro.
 *
 * \param mensaje[] char Mensaje a mostrar.
 * \param listado[] ePropietarios array de propietarios.
 * \param ingresos[] eIngreso array de vehiculos estacionados.
 * \return int Cod. de mensaje.
 *
 */
int ePro_modif(char mensaje[], ePropietarios listado[], eIngreso ingresos[]);

/** \brief Busca por ID a los propietarios.
 *
 * \param ePropietarios[] array de propietarios.
 * \param int ID a buscar.
 * \return int Retorna el indice de la ID, -1 si no se encuentra.
 *
 */
int buscarPorId(ePropietarios[], int);

/** \brief Realiza la baja de un miembro y, en caso de contar con vehiculos estacionados, genera el total adeudado.
 *
 * \param mensaje[] char Mensaje a mostrar.
 * \param listado[] ePropietarios array de propietarios.
 * \param ingresos[] eIngreso Array de vehiculos estacionados.
 * \param egresos[] eEgreso Array de egresos.
 * \return int Cod. mensaje.
 *
 */
int ePro_baja(char mensaje[], ePropietarios listado[], eIngreso ingresos[], eEgreso egresos[]);

/** \brief Muestra listado de los miembros actuales del estacionamiento.
 *
 * \param listado[] ePropietarios array de propietarios.
 * \return void
 *
 */
void ePro_mostrarListado(ePropietarios listado[]);

/** \brief Genera un numero del 1 al 24 al azar.
 *
 * \return int Numero generado.
 *
 */
int devolverHorasEstadia();

/** \brief Registra el ingreso de un vehiculo al estacionamiento.
 *
 * \param listado[] eIngreso array de vehiculos estacionados.
 * \param propietarios[] ePropietarios array de propietarios.
 * \return int cod. de mensaje.
 *
 */
int eAuto_Ingreso(eIngreso listado[], ePropietarios propietarios[]);

/** \brief Busca si hay lugar disponible para el ingreso de un vehiculo.
 *
 * \param listado[] eIngreso array de vehiculos estacionados.
 * \return int retorna el indice de un lugar disponible, -1 si no hay.
 *
 */
int eIngreso_buscarLugarLibre(eIngreso listado[]);

/** \brief Retorna el siguiente ID al ultimo registrado (ID auto-incrementable).
 *
 * \param listado[] eIngreso array de vehiculos estacionados.
 * \return int Retorna ID generada.
 *
 */
int eIngreso_siguienteId(eIngreso listado[]);

/** \brief Muestra el listado de autos estacionados.
 *
 * \param ingresos[] eIngreso array de vehiculos estacionados.
 * \param propietarios[] ePropietarios array de propietarios.
 * \return void
 *
 */
void ePro_mostrarListadoAutos(eIngreso ingresos[], ePropietarios propietarios[]);

/** \brief Registra el egreso de un automovil.
 *
 * \param eIngreso[] array de vehiculos estacionados.
 * \param eEgreso[] array de egresos.
 * \param ePropietarios[] array de propietarios.
 * \return int Cod. de mensaje.
 *
 */
int egresoAutomovil(eIngreso[], eEgreso[], ePropietarios[]);

/** \brief Genera un importe en el egreso de un vehiculo segun marca y estadia.
 *
 * \param egresos[] eEgreso array de egresos.
 * \param marca int Marca del vehiculo.
 * \return float Importe generado.
 *
 */
float calcularImporte(eEgreso egresos[], int marca);

/** \brief Busca el indice del ID de ingreso seleccionado.
 *
 * \param ingresos[] eIngreso Array de autos estacionados.
 * \param id int ID a buscar.
 * \return int Indice de la ID, si la encuentra. -1 si no.
 *
 */
int buscarIdIngreso(eIngreso ingresos[], int id);

/** \brief Muestra recaudacion total.
 *
 * \param listado[] eEgreso array de egresos.
 * \return void
 *
 */
void mostrarRecaudacion(eEgreso listado[]);

/** \brief Muestra la recaudacion separada por marca.
 *
 * \param listado[] eEgreso array de egresos.
 * \return void
 *
 */
void mostrarRecaudacionPorMarca(eEgreso listado[]);

/** \brief Calcula, si es que tiene autos, el total adeudado luego de una baja de usuario.
 *
 * \param listado[] ePropietarios array de propietarios.
 * \param ingresos[] eIngreso array de autos estacionados.
 * \param egresos[] eEgreso array de egresos.
 * \param idPropietario int id del propietario a dar de baja.
 * \return float Total adeudado.
 *
 */
float liquidacion(ePropietarios listado[],eIngreso ingresos[],eEgreso egresos[], int idPropietario);

/** \brief Muestra a los miembros propietarios de vehiculos del estacionamiento.
 *
 * \param listado[] ePropietarios array de propietarios.
 * \param ingresos[] eIngreso array de autos estacionados.
 * \return int Cod. de mensaje.
 *
 */
int mostrarPropietario(ePropietarios listado[], eIngreso ingresos[]);

/** \brief Muestra en pantalla a los propietarios de algun vehiculo AUDI.
 *
 * \param listado[] ePropietarios array de propietarios.
 * \param ingresos[] eIngreso array de autos estacionados.
 * \return void
 *
 */
void propietariosDeAudi(ePropietarios listado[], eIngreso ingresos[]);

/** \brief Muestra el historial de facturacion.
 *
 * \param egresos[] eEgreso La array de egresos.
 * \return void
 *
 */
void mostrarEgresos(eEgreso egresos[]);

