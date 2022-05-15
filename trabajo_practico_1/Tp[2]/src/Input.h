/*
 * @brief Contiene las funciones que permiten el ingreso de datos  y validarlos dentro de un rango especifico
 *
 * @Autor : Augusto Delgado
 * @Division B
 */

#ifndef INPUT_H_
#define INPUT_H_

#include "Validations.h"

/// @fn float PedirFlotanteYValidar(char[], char[], int)
/// @brief Permite ingresar un numero flotante y valida el  minimo de rango
///
/// @param char[] el mensaje que indica que debe ingresar
/// @param char[] el mensaje que indica que debe ingresar un numero dentro del rango pedido
/// @param int es el minimo de rango
/// @return float el numero flotante que fue ingresado
float GetFloat (char mensaje[],char mensajeError[] ,int minimo);

/// @fn int PedirEnteroYValidar(char[], char[], int, int)
/// @brief Permite ingresar un numero entero y valida el minimo de rango
///
/// @param char[] el mensaje que indica que debe ingresar
/// @param char[] el mensaje que indica que debe ingresar un numero valido dentro del rango pedido
/// @param int  es el minimo de rango
/// @param int  es el maximo de rango
/// @return int el numero entero que fue ingresado
int GetInt(char mensaje[],char mensajeError[] ,int minimo,int maximo);

/// @fn int PedirEnteroYValidar(char[], char[], int, int)
/// @brief Permite ingresar un caracter y valida que este dentro del rango el minimo  y maximo
///
/// @param char[] el mensaje que indica que debe ingresar
/// @param char[] el mensaje que indica que debe ingresar un numero valido dentro del rango pedido
/// @param int  es el minimo de rango
/// @param int  es el maximo de rango
/// @return int el numero entero que fue ingresado
char GetChar (char mensaje[],char mensajeError[] ,char minimo,char maximo);

/// @fn void GetSring(char[], char[], char[], int)
/// @brief Permite ingresar un Sring , valida que no se pase del largo de la cadena y que solo se ingrese letras
///
/// @param char[] el mensaje que indica que debe ingresar
/// @param char[] el mensaje que indica que debe ingresar
/// @param char[] la cadena donde se va guarda
/// @param int el largo de la cadena
void GetSring(char mensaje[],char mensajeError[],char cadena[],int size);

/// @fn void GetAlphanumeic(char[], char[], char[], int)
/// @brief Permite ingresar un Sring , valida que no se pase del largo de la cadena y que solo se ingrese letras y numeros
///
/// @param char[] el mensaje que indica que debe ingresar
/// @param char[] el mensaje que indica que debe ingresar
/// @param char[] la cadena donde se va guarda
/// @param int el largo de la cadena
void GetAlphanumeic(char mensaje[],char mensajeError[],char cadena[],int size);

#endif /* INPUT_H_ */
