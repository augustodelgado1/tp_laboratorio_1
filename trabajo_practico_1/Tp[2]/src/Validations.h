/*
 *
 * @brief Contiene funciones que validan el ingreso de datos
 *
 * @Autor : Augusto Delgado
 * @Division B
 */

#ifndef VALIDATIONS_H_
#define VALIDATIONS_H_

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/// @fn int IsNaN(char*)
/// @brief Verifica que una string contenga solo numeros
///
/// @param char* es el string
/// @return int (1) si el string contiene solo numeros , de caso contrario retorna (0)
int IsNaN(char*);

/// @fn int isLetter(char*)
/// @brief Verifica que una string contenga solo letas
///
/// @param char* es el string
/// @return int (1) si la string contiene solo letras , de caso contrario retorna (0)
int isLetter (char *);

/// @fn int isFloat(char*)
/// @brief Verifica que una cadena contenga solo numeros o un punto
///
/// @param char* es el string
/// @return int (1) si la string contiene es un numero flotante  , de caso contrario retorna (0)
int isFloat(char*);



#endif /* VALIDATIONS_H_ */
