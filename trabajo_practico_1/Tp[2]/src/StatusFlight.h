/*
 * @brief Contiene las funciones que se encargan del manejo del estado de vuelo
 *
 *  Created on: 6 jul. 2022
 *      Author: alumno
 */

#ifndef STATUSFLIGHT_H_
#define STATUSFLIGHT_H_

#include "ArrayPassenger.h"

/// @fn void printlistStatus(StatusFlight[], int)
/// @brief Mustra los elementos de la lista de estados de vuelos
///
/// @param StatusFlight[] la lista de estados de vuelos
/// @param size el tamaño del array
void printlistStatus(StatusFlight listStatus[],int sizeStatus);

/// @fn int StatusPassengerId(StatusFlight[], int, int)
/// @brief Busca en la lista si existe el id pasado por parametro y devuelve el indice del donde lo encontro
///
/// @param StatusFlight[] la lista de estados de vuelos
/// @param size el tamaño del array
/// @param int el id a buscar
/// @return [-1] si no existe el id , sino el indice del donde lo encontro
int StatusPassengerId(StatusFlight list[],int size,int id);


#endif /* STATUSFLIGHT_H_ */
