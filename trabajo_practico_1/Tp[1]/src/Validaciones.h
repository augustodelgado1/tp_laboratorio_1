/**
 * @def VALIDACION_H_
 * @brief Contiene funciones que permite ingresar numero y validarlos dentro de un rango especifico
 *
 * @Autor : Augusto Delgado
 * @Division B
 */
#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

#include <stdio.h>

/// @fn float PedirFlotanteYValidar(char[], char[], int)
/// @brief Permite ingresar un numero flotante y valida el  minimo de rango
///
/// @param char[] el mensaje que indica que debe ingresar
/// @param char[] el mensaje que indica que debe ingresar un numero dentro del rango pedido
/// @param int es el minimo de rango
/// @return float el numero flotante que fue ingresado
float PedirFlotanteYValidar (char mensaje[],char mensajeError[] ,int minimo);

/// @fn int PedirEnteroYValidar(char[], char[], int, int)
/// @brief Permite ingresar un numero entero y valida el minimo de rango
///
/// @param char[] el mensaje que indica que debe ingresar
/// @param char[] el mensaje que indica que debe ingresar un numero valido dentro del rango pedido
/// @param int  es el minimo de rango
/// @param int  es el maximo de rango
/// @return int el numero entero que fue ingresado
int PedirEnteroYValidar (char mensaje[],char mensajeError[] ,int minimo,int maximo);


#endif /* VALIDACIONES_H_ */
