#include "ArrayList.h"

typedef struct
{
    int numero;
    char nombre[50];
    int par;
    int impar;
    int primo;
}sNumeroNatural;

// constructors

/** \brief Funcion constructor que asigna espacio en memoria a un dato.
 *
 * \return sNumeroNatural* Direccion de memoria asignada.
 *
 */
sNumeroNatural* newStruct();

/** \brief Funcion constructor que asigna espacio en memoria a un dato con posibilidad de asignar valores.
 *
 * \return sNumeroNatural* Direccion de memoria asignada.
 *
 */
sNumeroNatural* newStructWithParam(parametros);

// Seters & Geters

/** \brief Setea el parametro numero.
 *
 * \param this sNumeroNatural* elemento en el cual será seteado numero.
 * \param intparam1 int campo a numero.
 * \return int retorna -1 si el elemento es null o si el entero no es valido.
 *
 */
int set_int_numero(sNumeroNatural* this, int numero);

/** \brief Consigue el parametro numero.
 *
 * \param this sEmpleados* elemento del cual se obtendra numero.
 * \return int numero
 *
 */
int get_int_numero(sNumeroNatural* this);

/** \brief Setea el parametro par.
 *
 * \param this sNumeroNatural* elemento en el cual será seteado par.
 * \param intparam1 int campo a par.
 * \return int retorna -1 si el elemento es null o si el entero no es valido.
 *
 */
int set_int_par(sNumeroNatural* this, int par);

/** \brief Consigue el parametro par.
 *
 * \param this sEmpleados* elemento del cual se obtendra par.
 * \return int par
 *
 */
int get_int_par(sNumeroNatural* this);

/** \brief Setea el parametro impar.
 *
 * \param this sNumeroNatural* elemento en el cual será seteado entero1.
 * \param intparam1 int campo a setear.
 * \return int retorna -1 si el elemento es null o si el entero no es valido.
 *
 */
int set_int_impar(sNumeroNatural* this, int impar);

/** \brief Consigue el parametro impar.
 *
 * \param this sEmpleados* elemento del cual se obtendra impar.
 * \return int impar
 *
 */
int get_int_impar(sNumeroNatural* this);

/** \brief Setea el parametro primo.
 *
 * \param this sNumeroNatural* elemento en el cual será seteado entero1.
 * \param intparam1 int campo a setear.
 * \return int retorna -1 si el elemento es null o si el entero no es valido.
 *
 */
int set_int_primo(sNumeroNatural* this, int primo);

/** \brief Consigue el parametro primo.
 *
 * \param this sEmpleados* elemento del cual se obtendra primo.
 * \return int primo
 *
 */
int get_int_primo(sNumeroNatural* this);

/** \brief Setea el parametro cadena1.
 *
 * \param this sNumeroNatural* elemento en el cual será seteado cadena1.
 * \param cadena1 char* campo a setear.
 * \return int Retorna -1 si el elemento o cadena1 son null.
 *
 */
int set_string_nombre(sNumeroNatural* this, char* nombre);

/** \brief Consigue el parametro cadena1.
 *
 * \param this sEmpleados* elemento del cual se obtendra cadena1.
 * \return char* cadena1
 *
 */
char* get_string_nombre(sNumeroNatural* this);

// AMB

/** \brief Realiza la alta de un elemento.
 *
 * \param this ArrayList* Lista dinámica que contiene las direcciones de memoria de los elementos.
 * \return int -1 en caso de error, 0 si es correcto.
 *
 */
int altaStruct(ArrayList* this);

/** \brief Busca el id maximo.
 *
 * \param this ArrayList* Lista dinamica que contiene las direcciones de memoria de los elementos.
 * \return int -1 en caso de error o ID maxima.
 *
 */
int maxID(ArrayList* this);

/** \brief Modificacion de un elemento.
 *
 * \param this ArrayList* Lista dinámica que contiene las direcciones de memoria de los elementos.
 * \return int -1 en caso de error. 0 si se cancela la modificacion. 1 si se modifico correctamente.
 *
 */
int modificacionStruct(ArrayList* this);

/** \brief Busca el indice de la lista dinamica segun id.
 *
 * \param this ArrayList* Lista dinámica que contiene las direcciones de memoria de los elementos.
 * \param idToSearch int
 * \return int -1 en caso de error o el indice a buscar.
 *
 */
int indexByID(ArrayList* this, int idToSearch);

/** \brief Realiza una baja.
 *
 * \param this ArrayList* Lista dinámica que contiene las direcciones de memoria de los elementos.
 * \return int -1 en caso de error. 0 si se cancela la baja o 1 si la baja se realiza correctamente.
 *
 */
int bajaStruct(ArrayList* this);

// Funciones


/** \brief Comprueba si un numero es primo.
 *
 * \param num int
 * \return int
 *
 */
int esPrimo(int num);

int criterioRepetidos(ArrayList* repetidos, ArrayList* noRepetidos);

/** \brief Menu en pantalla.
 *
 * \param menu char* String con opciones.
 * \return int Opcion elegida.
 *
 */
int menuSwitch(char* menu, int min, int max);

/** \brief Muestra un listado de elementos.
 *
 * \param this ArrayList* Lista dinámica que contiene las direcciones de memoria de los elementos.
 * \param columnas char* Columnas separadoras de campos.
 * \return int Retorna -1 si la lista dinamica es null, 0 si no lo es.
 *
 */
int mostrarLista(ArrayList* this, char* columnas);

/** \brief Muestra un elemento.
 *
 * \param this sNumeroNatural* Elemento a mostrar.
 * \return int Retorna -1 si el elemento es null, 0 si no lo es.
 *
 */
int mostrarUno(sNumeroNatural* this);

/** \brief Funcion que comprueba segun criterio.
 *
 * \param item void* elemento a comprobar.
 * \return int Retorna 1 si el elemento cumple con el criterio, 0 si no es así,
 *
 */
int funcionQueFiltra(void* item);

// Archivos

/** \brief Carga en memoria los datos de un archivo.
 *
 * \param this ArrayList* Lista dinámica que contendrá las direcciones de memoria de los datos cargados.
 * \return int
 *
 */
int lecturaDeDatos(ArrayList* this);

/** \brief Carga en memoria los datos de un archivo binario.
 *
 * \param this ArrayList* Lista dinámica que contendrá la direccion los datos cargados.
 * \return int
 *
 */
int lecturaDeDatosBIN(ArrayList* this);

/** \brief Reescribe el archivo con los cambios realizados.
 *
 * \param this ArrayList* Lista dinámica que contiene las direcciones de memoria de los datos a escribir.
 * \return void
 *
 */
int actualizarArchivo(ArrayList* this, char* nombre);

/** \brief Reescribe el archivo binario con los cambios realizados.
 *
 * \param this ArrayList* Lista dinámica que contiene las direcciones de memoria de los datos a escribir.
 * \return void
 *
 */
int actualizarArchivoBIN(ArrayList* this, char* nombre);

// Comparadores

/** \brief Funcion criterio según entero,
 *
 * \param E1 void* elemento a comparar A
 * \param E2 void* elemento a comparar B
 * \return int Retorna valores de strcmp (-1, 0, 1 según comparacion (<, > o =) de E1 con E1)
 *
 */
int compararEntero(void* E1, void* E2);

/** \brief Funcion criterio según cadena,
 *
 * \param E1 void* elemento a comparar A
 * \param E2 void* elemento a comparar B
 * \return int Retorna valores de strcmp (-1, 0, 1 según comparacion (ASCII <, > o =) de E1 con E1)
 *
 */
int compararCadena(void* E1, void* E2);
