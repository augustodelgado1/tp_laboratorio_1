

#ifndef ECONFEDERACION_H_
#define ECONFEDERACION_H_

#include "eJugador.h"



/// @fn int ObtenerIDConfederacion()
/// @brief Permite obtener un id autoicremental
///
/// @return el incremento del id
int ObtenerIDConfederacion();

/// @fn int CargaForzadaDeConfederacion(eConfederacion[], int, int, char[], char[], int)
/// @brief realiza una carga forzada de una confederacion validando que los campos sean correctos y que haya espacio en la lista
///
/// @param eConfederacion[] el array de Confederaciones
/// @param int el tamanio del array de Confederaciones
/// @param int el id de confederaciones
/// @param char[] nombre  de confederaciones
/// @param char[] region  de confederaciones
/// @param int anio de creacion  de confederaciones
/// @return [-1] si no pudo realizar la carga forzada , [1] si pudo realizar la carga forzada
int CargaForzadaDeConfederacion(eConfederacion listaDeConfederaciones[],int sizeDeConfederaciones,int id,char nombre[],char region[],int anioCreacion);

/// @fn int SubMenuDeConfederaciones(eConfederacion[], int)
/// @brief Mustra el subMenu del Abm de Confederaciones y Permite ingresar una opcion al usuario
///
/// @param eConfederacion[] el array de Confederaciones
/// @param int el tamanio del array de Confederaciones
/// @return [-1] ai Hubo ERROR , [1] si esta ok
int SubMenuDeConfederaciones(eConfederacion listaDeConfederaciones[],int sizeDeConfederacion);

/// @fn int AltaDeConfederacion(eConfederacion[], int)
/// @brief Permite dar de cargar un elemento en el array de Confederaciones validando que haya espacio en el array
///
/// @param eConfederacion[] el array de Confederaciones
/// @param int el tamanio del array de Confederaciones
/// @return [-2] si no hay espacio en el array, [-1] si no pudo agregarlo  , [1] si se agrego el elemento
int AltaDeConfederacion(eConfederacion listaDeConfederaciones[],int sizeDeConfederacion);

/// @fn int InicializarListaDeConfederaciones(eConfederacion[], int)
/// @brief Inicializa el campo isEmpty de todos los elementos de la lista en 0
///
/// @param eConfederacion[] el array de Confederaciones
/// @param int el tamanio del array de Confederaciones
/// @return [-1] ai Hubo ERROR , [1] si esta ok
int InicializarListaDeConfederaciones(eConfederacion listaDeConfederaciones[],int sizeDeConfederaciones);

/// @fn int eConfederacion_MostraLista([], int)
/// @brief Muestra la lista de confederaciones cargadas
///
/// @param eConfederacion[] el array de Confederaciones
/// @param int el tamanio del array de Confederaciones
/// @return [-1] si no hay elementos en la lista , [1] si hay elementos en la lista
int MostraListaDeConfederaciones(eConfederacion listaDeConfederaciones[],int sizeDeConfederacion);

/// @fn int BajaDeConfederacion(eConfederacion listaDeConfederaciones[],int sizeDeConfederaciones);
/// @brief Elimina un elemento cargado de la lista de confederaciones
///
/// @param eConfederacion[] el array de confederaciones
/// @param int el tamanio del array de confederaciones
/// @return [-1] si no pudo eliminarlo , [0] si se cancelo la eliminacion , [1] si se elimino el elemento
int BajaDeConfederacion(eConfederacion listaDeConfederaciones[],int sizeDeConfederaciones);

/// @fn int CargarUnaConfederacion(eConfederacion* unaConfederacion);
/// @brief Permite pedir una Confederacion validando que se ingrese todos sus campos correctamente
///
/// @param eConfederacion* el puntero a la Confederaciones
/// @return[-1] si hubo error ,[1] si no hubo error
int CargarUnaConfederacion(eConfederacion* unaConfederacion);

/// @fn int ModificarUnaConfederacion(eConfederacion[], int)
/// @brief Permite modificar una confederacion de la lista de Confederaciones
///
/// @param eConfederacion[] el array de confederaciones
/// @param int el tamanio del array de confederaciones
/// @return [-1] si no pudo Modificarlo , [0] si se cancelo la modificacion , [1] si se modifico el elemento
int ModificarUnaConfederacion(eConfederacion listaDeConfederaciones[],int sizeDeConfederaciones);

/// @fn int BuscarConfederacionLibre(eConfederacion[], int)
/// @brief Busca y devuelve el primer elemento que no esta cargado de la lista
///
/// @param eConfederacion[] el array de confederaciones
/// @param int el tamanio del array de confederaciones
/// @return [-1] si no encontro un elemento libre en la lista, el indice donde
int BuscarConfederacionLibre(eConfederacion listaDeConfederaciones[],int sizeDeConfederacion);

/// @fn int CantidadDeConfederacionesCargadas(eConfederacion[], int)
/// @brief Recorre el array de confederaciones y cuenta cuantas confederaciones que estan cargadas en el array
///
/// @param eConfederacion[] el array de confederaciones
/// @param int el tamanio del array de confederaciones
/// @return la cantidad de confederaciones que estan cargadas en el array
int CantidadDeConfederacionesCargadas(eConfederacion listaDeConfederaciones[],int sizeDeConfederaciones);

/// @fn int BuscarIdDeConfederacion(eConfederacion[], int, int)
/// @brief Busca un id determinado en el array de confederaciones
///
/// @param eConfederacion[] el array de confederaciones
/// @param int el tamanio del array de confederaciones
/// @param int el id a buscar en la lista
/// @return [-1] si no encontro el id , [el indice]  donde encontro el id
int BuscarIdDeConfederacion(eConfederacion listaDeConfederacions[],int sizeDeConfederacions,int id);

/// @fn int PedirConfederacion([], int)
/// @brief Permite pedir una Confederacion validando que pertenezca a la lista de  Confederacion
///
/// @param eConfederacion[] el array de Confederaciones
/// @param int el tamanio del array de Confederaciones
/// @return[-1] si hubo error ,[1] si no hubo error
int PedirConfederacion(eConfederacion[],int );

/// @fn void MostrarUnaConfederacion(eConfederacion)
/// @brief Permite Muestra todos los campos de una estructura del tipo eConfederacion
///
/// @param eConfederacion una confederacion a mostrar
void MostrarUnaConfederacion(eConfederacion unaCofederacion);


#endif /* ECONFEDERACION_H_ */
