/*
 @brief Contiene las funcines que se encargan del ingreso y validacion de datos
 */
#ifndef INPUT_H_
#define INPUT_H_

#include "Validations.h"

/// @fn float PedirFlotanteYValidar(char[], char[], int)
/// @brief Permite ingresar un numero flotante y valida el  minimo de rango
///
/// @param float* Donde se va a guardar el numero ingresado
/// @param char[] el mensaje que indica que debe ingresar
/// @param char[] el mensaje que indica que debe ingresar un numero dentro del rango pedido
/// @param int es el minimo de rango
/// @param int la cantidad de reitentos
/// @return [0] si se pudo ingresar correctamente , sino [-1]
int GetNumeroFlotante(float *numero,char mensaje[], char mensajeError[], int minimo,int reitentos);

/// @fn int PedirEnteroYValidar(char[], char[], int, int)
/// @brief Permite ingresar un numero entero y valida el minimo de rango
///
/// @param int* Donde se va a guardar el numero ingresado
/// @param char[] el mensaje que indica que debe ingresar
/// @param char[] el mensaje que indica que debe ingresar un numero valido dentro del rango pedido
/// @param int  es el minimo de rango
/// @param int  es el maximo de rango
/// @param int la cantidad de reitentos
/// @return [0] si se pudo ingresar correctamente , sino [-1]
int GetNumero (int *numero,char mensaje[], char mensajeError[], int minimo, int maximo,int);

/// @fn int PedirEnteroYValidar(char[], char[], int, int)
/// @brief Permite ingresar un caracter y valida que este dentro del rango el minimo  y maximo
///
/// @param char[] el mensaje que indica que debe ingresar
/// @param char[] el mensaje que indica que debe ingresar un numero valido dentro del rango pedido
/// @return el caracter ingresado
char GetChar (char mensaje[]);

/// @fn void GetSring(char[], char[], char[], int)
/// @brief Permite ingresar un stringh y valida que no se pase del maximo de la cadena
///
/// @param char[] el mensaje que indica que debe ingresar
/// @param char[] el mensaje que indica que debe ingresar
/// @param char[] la cadena donde se va guarda
/// @param int el largo de la cadena
void GetSring (char mensaje[], char mensajeError[], char cadena[], int size);

/// @fn void GetSring(char[], char[], char[], int)
/// @brief Permite ingresar un stringh y valida que no se pase del maximo de la cadena
///
/// @param char[] el mensaje que indica que debe ingresar
/// @param char[] el mensaje que indica que debe ingresar
/// @param char[] la cadena donde se va guarda
/// @param int el largo de la cadena
int GetNombre(char mensaje[], char mensajeError[], char cadena[], int size);

/// @fn int GetAlphanumeic(char[], char[], char[], int)
/// @brief Permite ingresar un stringh y valida que no se pase del maximo de la cadena
///
/// @param char[] el mensaje que indica que debe ingresar
/// @param char[] el mensaje que indica que debe ingresar
/// @param char[] la cadena donde se va guarda
/// @param int el largo de la cadena
/// @return si se pudo ingresar correctamente
int GetAlphanumeic(char mensaje[],char mensajeError[],char string[],int size);

/// @fn int PreguntarSoN(char*, char[], char[], int)
/// @brief Paermite igresar una respuesta validando que se igual a (s o n)
///
/// @param char[] el mensaje que indica que debe ingresar
/// @param char[] el mensaje que indica que debe ingresar un numero dentro del rango pedido
/// @return (s o n)
char PreguntarSoN(char mensaje[],char mensajeError[]);

/// @fn void ConvertidorDeMayusculas(char*)
/// @brief Convierte todas las iniciciales de palabra en Mayusculas de string
///
/// @param char[] el string de letras
void ConvertidorDeMayusculas(char *);

/// @fn void ConvertidorDeMinusculas(char*)
/// @brief Convierte todas la letra de un string el Minusculas
///
/// @param char[] el string de letras
void ConvertidorDeMinusculas(char[]);

#endif /* INPUT_H_ */
