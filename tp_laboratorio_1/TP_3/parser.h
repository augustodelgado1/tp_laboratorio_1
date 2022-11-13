
#ifndef PARSER_H_
#define PARSER_H_

#include "LinkedList.h"

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param  char* un archivo de donde se va obtener los datos
 * \param  LinkedList* la lista de jugadores
 * \return int [-1] si hubo error al cargar los datos ,[1] si esta se cargaron correctamente
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador);

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param  char* un archivo de donde se va obtener los datos
 * \param  LinkedList* la lista de jugadores
 * \return int [-1] si hubo error al cargar los datos ,[1] si esta se cargaron correctamente
 *
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador);


/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param  char* un archivo de donde se va obtener los datos
 * \param  LinkedList* la lista de selecciones
 * \return int [-1] si hubo error al cargar los datos ,[1] si esta se cargaron correctamente
 *
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion);


#endif /* PARSER_H_ */
