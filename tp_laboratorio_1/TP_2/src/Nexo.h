
#ifndef NEXO_H_
#define NEXO_H_

#include "eConfederacion.h"
#include "eAuxiliar.h"
#include "Calculadora.h"


/// @fn int SubMenuDeListados(eJugador[], int, eConfederacion[], int)
/// @brief Mustra un sub menu de listado y permite ingresar una opcion
/// permitiendo validar que se ingrese una opcion valida
///
/// @param eJugador[] el array de jugadores
/// @param int  el tamanio del array de jugadores
/// @param eConfederacion[] el array de confederaciones
/// @param int el tamanio del array de confederaciones
/// @return [-1] si hubo error , [1] si esta ok
int SubMenuDeListados(eJugador listaDeJugadores[],int size,eConfederacion listaDeConfederaciones[],int sizeDeConfederaciones,eAuxiliar arrayAuxiliar[],int sizeAuxiliar);


/// @fn int BajaDeJugador(eJugador[], int, eConfederacion[], int)
/// @brief Elimina un elemento cargado de la lista de jugadores
///
/// @param eJugador[] el array de jugadores
/// @param int  el tamanio del array de jugadores
/// @param eConfederacion[] el array de confederaciones
/// @param int el tamanio del array de confederaciones
/// @return [-1] si no pudo eliminarlo , [0] si se cancelo la eliminacion , [1] si se elimino el elemento
int BajaDeJugador(eJugador listaDeJugadores[], int len,eConfederacion listaDeConfederaciones[],int sizeDeConfederaciones);

/// @fn int ModificarUnJugador(eJugador[], int, eConfederacion[], int)
/// @brief  Modifica un elemento cargado de la lista de jugadores
///
/// @param eJugador[] el array de jugadores
/// @param int  el tamanio del array de jugadores
/// @param eConfederacion[] el array de confederaciones
/// @param int el tamanio del array de confederaciones
/// @return [-1] si no pudo Modificarlo , [0] si se cancelo la modificacion , [1] si se modifico el elemento
int ModificarUnJugador(eJugador listaDeJugador[], int size,eConfederacion listaDeConfederaciones[],int sizeDeConfederacion);

/// @fn int AltaDeJugador(eJugador[], int, eConfederacion[], int)
/// @brief Permite dar de cargar un elemento en el array de jugadores validando que haya espacio en el array
///
/// @param eJugador[] el array de jugadores
/// @param int  el tamanio del array de jugadores
/// @param eConfederacion[] el array de confederaciones
/// @param int el tamanio del array de confederaciones
/// @param int* el puntero al id del jugador
/// @return [-2] si nop hay espacio en el array, [-1] si no pudo agregarlo  , [1] si se agrego el elemento
int AltaDeJugador(eJugador listaDeJugadores[], int len,eConfederacion listaDeConfederaciones[],int sizeDeConfederaciones);

/// @fn int PedirUnJugador(eJugador*, eConfederacion[], int)
/// @brief Permite cargar un jugador validando que se haya ingresado los datos correctamente
///
/// @param eJugador* un puntero al jugador
/// @param eConfederacion[] el array de confederaciones
/// @param int el tamanio del array de confederaciones
/// @return  [-1] si hubo Error, [1]  si los datos se ingresaron correctamente
int PedirUnJugador(eJugador* unJugador,eConfederacion listaDeConfederaciones[],int sizeDeConfederaciones);

/// @fn int MostrarListaDeJugadores(eJugador[], int, eConfederacion[], int)
/// @brief si la lista no esta vacia Muestra la lista de jugadores
///
/// @param eJugador[] el array de jugadores
/// @param int  el tamanio del array de jugadores
/// @param eConfederacion[] el array de confederaciones
/// @param int el tamanio del array de confederaciones
/// @return [-1] si la lista esta vacia , [1]  si pudo mostrar la lista
int MostrarListaDeJugadores(eJugador listaDeJugador[],int size,eConfederacion listaDeConfederaciones[],int sizeDeConfederacion);

/// @fn void MostrarUnJugador(eJugador, eConfederacion)
/// @brief Muestra un jugador
///
/// @param unJugador
/// @param una Confederacion
void MostrarUnJugador(eJugador unJugador,eConfederacion unaConfederacion);

/// @fn int InitList([], int,[], int, int)
/// @brief Realiza una carga forzada en el array de jugadores y de confederaciones
///
/// @param eJugador[] el array de jugadores
/// @param int  el tamanio del array de jugadores
/// @param eConfederacion[] el array de confederaciones
/// @param int el tamanio del array de confederaciones
/// @param el maximo de lugares que se quiere cargar
/// @return [-1] si no pudo realizar la carga forzada, [1]  si pudo realizar la carga forzada
int CargaForazada(eJugador listaDeJugadores[],int size ,eConfederacion listaDeConfederaciones[],int sizeDeConfederaciones,int maximo);

/// @fn int OrdenarPorNombreDeConfederaciones(eJugador[], int, eConfederacion[], int)
/// @brief Ordena el array de jugadores Albeticamente por nombre de confederaciones y nombre de jugador
///
/// @param eJugador[] el array de jugadores
/// @param int  el tamanio del array de jugadores
/// @param eConfederacion[] el array de confederaciones
/// @param int el tamanio del array de confederaciones
/// @return [-1] si hubo error en los parametros , [1] si esta ok
int OrdenarPorNombreDeConfederaciones(eJugador listaDeJugadores[],int size,eConfederacion listaDeConfederaciones[],int sizeDeConfederaciones);

/// @fn int MostrarJugadoresDeUnaRegion(eConfederacion[], int, eJugador[], int, char[])
/// @brief Mustra los jugadores que pertenecen a una region determinada
///
/// @param eConfederacion[] el array de confederaciones
/// @param int el tamanio del array de confederaciones
/// @param eJugador[] el array de jugadores
/// @param int  el tamanio del array de jugadores
/// @param char[] la region de  a buscar los jugadores
/// @return [-1] si hubo error en los parametros , [1] si esta ok
int MostrarJugadoresDeUnaRegion(eConfederacion listaDeConfederaciones[],int sizeDeConfederaciones,eJugador listaDeJugadores[],int sizeDeJugadores,char region[]);

/// @fn int MostrarRegionConMasJugadores(eAuxiliar[], int, eConfederacion[], int, eJugador[], int)
/// @brief Mustra la region que tiene mas jugadores, con sus jugadores
///
/// @param eAuxiliar[]  un array auxiliar
/// @param sizeAuxiliar  el tamanio del  array auxiliar
/// @param eConfederacion[] el array de confederaciones
/// @param int el tamanio del array de confederaciones
/// @param eJugador[] el array de jugadores
/// @param int  el tamanio del array de jugadores
/// @return [-1] si hubo error en los parametros , [1] si esta ok
int MostrarRegionConMasJugadores(eAuxiliar arrayAuxiliar[],int sizeAuxiliar,eConfederacion listaDeConfederaciones[],int sizeDeConfederaciones,eJugador listaDeJugadores[],int sizeDeJugadores);

/// @fn int CantidadDeJugadoresDeCadaRegion(eAuxiliar[], int, eConfederacion[], int, eJugador[], int)
/// @brief Cuenta la cantidad de jugadores da cada region
///
/// @param eAuxiliar[]  un array auxiliar
/// @param sizeAuxiliar  el tamanio del  array auxiliar
/// @param eConfederacion[] el array de confederaciones
/// @param int el tamanio del array de confederaciones
/// @param eJugador[] el array de jugadores
/// @param int  el tamanio del array de jugadores
/// @return [-1] si hubo error en los parametros , [1] si esta ok
int CantidadDeJugadoresDeCadaRegion(eAuxiliar arrayAuxiliar[],int sizeDeAuxiliar,eConfederacion listaDeConfederaciones[],int sizeDeConfederaciones,eJugador listaDeJugadores[],int sizeDeJugadores);


/// @fn int ContarJugadoresDeCadaRegion(eJugador[], int, eConfederacion[], int, char[])
/// @brief Cuenta la cantidad de jugadores que pernecen a una region determinada
///
/// @param eJugador[] el array de jugadores
/// @param int  el tamanio del array de jugadores
/// @param eConfederacion[] el array de confederaciones
/// @param int el tamanio del array de confederaciones
/// @param char[] la region de  a buscar los jugadores
/// @return [-1] si hubo error en los parametros , [1] si esta ok
int ContarJugadoresDeCadaRegion(eJugador listaDeJugadores[],int sizeDeJugadores,eConfederacion listaDeConfederaciones[],int sizeDeConfederaciones,char region[]);


/// @fn int CantidadDeJugadoresPorCadaConfederacion(eConfederacion[], int, eJugador[], int, eAuxiliar[], int)
/// @brief Cuenta la cantidad  de jugadores de cada region y la guarda en un array auxiliar
///
/// @param eConfederacion[] el array de confederaciones
/// @param int el tamanio del array de confederaciones
/// @param eJugador[] el array de jugadores
/// @param int  el tamanio del array de jugadores
/// @param eAuxiliar[]  un array auxiliar
/// @param sizeAuxiliar  el tamanio del  array auxiliar
/// @return [-1] si hubo error en los parametros , [1] si esta ok
int CantidadDeJugadoresPorCadaConfederacion(eConfederacion listaDeConfederaciones[],int sizeDeConfederaciones,eJugador listaDeJugadores[],int size,eAuxiliar arrayAuxiliar[],int sizeAuxiliar);

/// @fn int MostrarListaDeConderacionesConJugadores(eConfederacion[], int, eJugador[], int)
/// @brief Muestra la lista de confederaciones y los jugadores que forman parte de esa confederacion
///
/// @param eConfederacion[] el array de confederaciones
/// @param int el tamanio del array de confederaciones
/// @param eJugador[] el array de jugadores
/// @param int  el tamanio del array de jugadores
/// @return [-1] si hubo error en los parametros , [1] si esta ok
int MostrarListaDeConderacionesConJugadores(eConfederacion listaDeConfederaciones[],int sizeDeConfederaciones,eJugador listaDeJugadores[],int sizeDeJugadores);

/// @fn int MostrarListaDeJugadoresMaximoPromedio(eJugador[], int, eConfederacion[], int, float)
/// @brief Muetra los jugadores que cobran mas que el promedio pasada por parametro
///
/// @param eConfederacion[] el array de confederaciones
/// @param int el tamanio del array de confederaciones
/// @param eJugador[] el array de jugadores
/// @param int  el tamanio del array de jugadores
/// @param float promedio a comparar con el sueldo de los jugadores
/// @return [-1] si hubo error en los parametros , [1] si esta ok
int MostrarListaDeJugadoresMaximoPromedio(eJugador listaDeJugadores[],int sizeDeJugadores,eConfederacion listaDeConfederaciones[],int sizeDeConfederaciones,float);

/// @fn int TotalDeAniosDeContratoDeConfederaciones(eConfederacion[], int, eJugador[], int, eAuxiliar[], int)
/// @brief Cuenta la cantidad de contratos de cada confederacion y la guarda en un array auxiliar
///
/// @param eConfederacion[] el array de confederaciones
/// @param int el tamanio del array de confederaciones
/// @param eJugador[] el array de jugadores
/// @param int  el tamanio del array de jugadores
/// @param eAuxiliar[]  un array auxiliar
/// @param sizeAuxiliar  el tamanio del  array auxiliar
/// @return [-1] si hubo error en los parametros , [1] si esta ok
int TotalDeAniosDeContratoDeConfederaciones(eConfederacion listaDeConfederaciones[],int sizeDeConfederaciones,eJugador listaDeJugadores[],int size,eAuxiliar arrayAuxiliar[],int sizeAuxiliar);

/// @fn int MostrarConfederacionConMayorCantidad(eAuxiliar[], int, eConfederacion[], int, int)
/// @brief Mustra la confederacion que contiene mayor cantidad de anios de contrato
///
/// @param eAuxiliar[]  un array auxiliar
/// @param sizeAuxiliar  el tamanio del  array auxiliar
/// @param eConfederacion[] el array de confederaciones
/// @param int el tamanio del array de confederaciones
/// @param int el maximo a comparar
/// @return [-1] si hubo error en los parametros , [1] si esta ok
int MostrarConfederacionConMayorCantidad(eAuxiliar arrayAuxiliar[],int sizeAuxiliar,eConfederacion listaDeConfederaciones[],int sizeDeConfederaciones,int maximo);

/// @fn int MostrarPorcetajeDeJugadoresPorConfedecion(eJugador[], int, eConfederacion[], int, eAuxiliar[], int)
/// @brief Muestra el porcentaje de jugadores de cada confederacion
///
/// @param eJugador[] el array de jugadores
/// @param int  el tamanio del array de jugadores
/// @param eConfederacion[] el array de confederaciones
/// @param int el tamanio del array de confederaciones
/// @param eAuxiliar[]  un array auxiliar
/// @param sizeAuxiliar  el tamanio del  array auxiliar
/// @return  [-1] si hubo error en los parametros , [1] si esta ok
int MostrarPorcetajeDeJugadoresPorConfedecion(eJugador listaDeJugadores[], int len,eConfederacion listaDeConfederaciones[],int sizeDeConfederaciones,eAuxiliar arrayAuxiliar[],int sizeAuxiliar);

#endif /* NEXO_H_ */
