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

/// @fn int menu()
/// @brief Muesta las opciones del menu principal , pide que elija una opcion y retorna cual eligio
///
/// @return int la opcion ingresada
int menu();

/// @fn int menuDeModificacion()
/// @brief Muesta las opciones del menu de modificaciones , pide que elija una opcion y retorna cual eligio
///
/// @return int la opcion ingresada
int menuDeModificacion();

/// @fn void ConvertidorDeMayusculas(char*)
/// @brief recorre la cadena y si encuntra un espacio el siguiente caracter lo convierte en mayuscula
///
/// @param char[] el string con letras
void ConvertidorDeMayusculas(char* );

/// @fn void ImprimirResultados()
/// @brief Imprime los resultados del menu indicando que es cada resultado
/// @param char[] el mensaje indicando que es cada resultado
void ImprimirResultados(char[]);







#endif /* MENU_H_ */
