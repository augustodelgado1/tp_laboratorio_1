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

/// @fn int getInt(int*)
/// @brief valida que un string contenga solo numeros y lo guarda en la variable recibida por parametro
///
/// @param int* donde se va a guardar el entero que contiene el string
/// @return int (-1) si no se pudo guardar el string, de caso contrario retorna (0)
int getInt(int* numero);

/// @fn int GetFloat(int*)
/// @brief Valida que un string contenga un numero flotante y lo guarda en la variable recibida por parametro
///
/// @param int* donde se va a guardar el numero flotante que contiene el string
/// @return int (-1) si no se pudo guardar el string, de caso contrario retorna (0)
int GetFloat(int* numero);

/// @fn int IsNaN(char*)
/// @brief Verifica que una string contenga solo numeros
///
/// @param char* es el string
/// @return int (1) si el string contiene solo numeros , de caso contrario retorna (0)
int IsNaN(char*,int);

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


/// @fn int MyGets(char[], char[], int)
/// @brief Permite ingresar un string y valida que no se pase del tamaño del sting
///
/// @param char[] donde se va a guardar el lo que se ingreso
/// @param int el tamaño del sting
/// @return int (-1) si no se pudo ingresar el string , de caso contrario retorna (0)
int MyGets(char string[],int size);



#endif /* VALIDATIONS_H_ */
