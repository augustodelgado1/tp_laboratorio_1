

#ifndef EAUXILIAR_H_
#define EAUXILIAR_H_

#include "eJugador.h"

/// @fn int InicializarListaDeJugadores(eJugador[], int)
/// @brief Inicializa el campo isEmpty del array auxiliar en 0
///
/// @param eAuxiliar[] el array de auxiliar
/// @param int el tamanio del array
/// @return [-1] si Hubo ERROR, [1] si esta OK
int InicializarListaAuxiliar(eAuxiliar arrayAuxiliar[],int sizeAuxiliar);

/// @fn int BuscarMayorAcumulado(eAuxiliar[], int, int*)
/// @brief Recorre el array auxiliar y busca la mayor cantidad acumulada
///
/// @param eAuxiliar[] el array de auxiliar
/// @param int el tamanio del array
/// @param int* el puntero donde se va a guardar el maximo
/// @return [-1] si hubo error en los parametros ,  [1] si esta OK
int BuscarMayorAcumulado(eAuxiliar arrayAuxiliar[],int sizeAuxiliar,int* maximo);

/// @fn int BuscarMayorCantidad(eAuxiliar[], int, int*)
/// @brief Recorre el array auxiliar y busca la mayor cantidad
///
/// @param eAuxiliar[] el array de auxiliar
/// @param int el tamanio del array
/// @param int* el puntero donde se va a guardar el maximo
/// @return [-1] si hubo error en los parametros ,  [1] si esta OK
int BuscarMayorCantidad(eAuxiliar arrayAuxiliar[],int sizeAuxiliar,int* maximo);

/// @fn int BuscarLibreAuxiliar(eAuxiliar[], int)
/// @brief Recorre el array auxiliar y busca un espacio libre
///
/// @param eAuxiliar[] el array de auxiliar
/// @param int el tamanio del array
/// @return [-1] si no encontro el espacio libre , el indice donde lo encontro
int BuscarLibreAuxiliar(eAuxiliar arrayAuxiliar[],int sizeAuxiliar);

/// @fn int CalcularPorcentajeArrayAuxiliar(eAuxiliar[], int, int)
/// @brief Calcula el porcentaje de la cantidad contada
///
/// @param eAuxiliar[] el array de auxiliar
/// @param int el tamanio del array
/// @param cantidad
/// @return [-1] si hubo error en los parametros ,  [1] si esta OK
int CalcularPorcentajeArrayAuxiliar(eAuxiliar arrayAuxiliar[],int sizeAuxiliar,int cantidad);


#endif
