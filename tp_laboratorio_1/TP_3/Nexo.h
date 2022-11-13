/*
 * Nexo.h
 *
 *  Created on: 1 nov. 2022
 *      Author: alumno
 */

#ifndef NEXO_H_
#define NEXO_H_
#include "Jugador.h"
#include "Seleccion.h"
/// @fn int Nexo_MostrarJugadoresConSeleccion(Jugador*, Seleccion*)
/// @brief Muestra un jugador convocado con su seleccion
///
/// @param Jugador* el jugador a mostrar
/// @param Seleccion* la seleccion del jugador a mostrar
/// @return [-1] si hubo error al intentar mostrar un dato, [1] si esta ok
int Nexo_MostrarJugadoresConSeleccion(Jugador*,Seleccion*);

#endif /* NEXO_H_ */
