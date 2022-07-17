/**
 * @def MENU_H_
 * @brief  Esta bibloteca contiene funciones que mustran un menu y que muestra una cabecera
 *
 * @Autor : Augusto Delgado
 * @Division B
 */

#ifndef MENU_H_
#define MENU_H_

#include "Input.h"

/// @fn int menu(int*, char[], char[], int, int)
/// @brief Permite Motrar un sub menu y seleccionar una opcion
///
/// @param int* donde se va a guardar la opcion la cual se ingreso
/// @param char mensaje De Bienvenida
/// @param char las ditintas opciones del menu
/// @param int el minimo de opciones
/// @param int el maximo de opciones
/// @return [-1] si no se ingreso una opcion dentro del rango , [0] si se ingreso una opcion valida
int menu(int*,char mensajeDeBienvenida[],char mensaje[],int minimo,int maximo);

/// @fn void ImprimirCabecera(char cabecera[],char mensaje[]);
/// @brief Muestra una cabecera
/// @param char[] mensaje que indica que va a mostrar
/// @param char[] el mensaje indicando que es cada resultado
void ImprimirCabecera(char cabecera[],char mensaje[]);



#endif /* MENU_H_ */
