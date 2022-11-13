/**
 * @def MENU_H_
 * @brief  Esta bibloteca contiene las opciones del menu y
 *
 * @Autor : Augusto Delgado
 * @Division B
 */

#ifndef MENU_H_
#define MENU_H_

#include "Input.h"

/// @fn int menu(int*, char[], char[], int, int)
/// @brief Muestra un menu
///
/// @param int* Donde se va a guarda la opcion ingresada
/// @param char[] mensajeDeBienvenida
/// @param char[]
/// @param int el minimo de opciones que va tener el menu
/// @param int el maximo de opciones que va tener el menu
/// @return si se ingreso la opcion correctamente
void menu(char mensajeDeBienvenida[],char mensaje[]);

/// @fn void ImprimirCabecera(char*)
/// @brief Mustra un mensaje con una cabecera
///
/// @param char[] el Mensaje que indica que se va a mostrar
/// @param char[] el mensaje indicando los datos
/// @param char[] el mensaje a mostrar
/// @param char[] el mensaje a mostrar
/// @param int la cantidad de veces que se quiere mostrar el mensaje
void ImprimirCabecera(char cabecera[],char mensaje[],char segundoMensaje[],char tercerMensaje[],int cantidadDeVeces);

/// @fn int MostrarUnMensajeRepetidasVeces(char[], int)
/// @brief Mostra un mensje determinada cantidad veces
///
/// @param char[] el mensaje a mostrar
/// @param int la cantidad de veces que se quiere mostrar el mensaje
/// @return [-1] si hubo ERROR, [1] SI ESTA OK
int MostrarUnMensajeRepetidasVeces(char mensaje[],int cantidadDeVeces);





#endif /* MENU_H_ */
