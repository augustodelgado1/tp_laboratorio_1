/*
 * @brief Contiene las funciones que se encargan del manejo del tipo de vuelos
 *
 *  Created on: 6 jul. 2022
 *      Author: alumno
 */

#ifndef TYPEPASSENGER_H_
#define TYPEPASSENGER_H_

#include "ArrayPassenger.h"

/// @fn int StatusPassengerId(StatusFlight[], int, int)
/// @brief Busca en la lista si existe el id pasado por parametro y devuelve el indice del donde lo encontro
///
/// @param TypePassenger[] la lista de Tipos de vuelos
/// @param size el tamaño del array
/// @param int el id a buscar
/// @return [-1] si no existe el id , sino el indice del donde lo encontro
int BusquedarIdDetype(TypePassenger listaDeTipos[],int sizeType,int id);

/// @fn void printListType(TypePassenger[], int)
/// @brief Mustra los elementos de la lista de Tipos de vuelos
///
/// @param TypePassenger[] la lista de Tipos de vuelos
/// @param size el tamaño del array
void printListType(TypePassenger listaDeTipos[],int sizeType);


#endif /* TYPEPASSENGER_H_ */
