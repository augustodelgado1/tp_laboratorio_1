/*
 @brief Contiene las funcines que se encargan del ingreso y validacion de datos
 */
#ifndef INPUT_H_
#define INPUT_H_

#include "Validations.h"


int GetEnteroCorto(short* numero,char mensaje[],char mensajeError[] ,int minimo,int maximo,int reitentos);
/// @fn float PedirFlotanteYValidar(char[], char[], int)
/// @brief Permite ingresar un numero flotante y valida el  minimo de rango
///
/// @param float* Donde se va a guardar el numero ingresado
/// @param char[] el mensaje que indica que debe ingresar
/// @param char[] el mensaje que indica que debe ingresar un numero dentro del rango pedido
/// @param int es el minimo de rango
/// @param int la cantidad de reitentos
/// @return [0] si se pudo ingresar correctamente , sino [-1]
int GetNumeroFlotante(float *numero,char mensaje[], char mensajeError[], int minimo,int maximo,int reitentos);

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

/// @fn int ValidarChar(char* respuesta,char mensaje[],char mensajeError[],char primerLetra , char segudaLetra,int reitentos);
/// @brief Paermite igresar un char validando que se igual a una letra u otra letra pasada por parametro
///
/// @param char* donde se va a gurdar la letra que ingreso el usuario
/// @param char[] el mensaje que indica que debe ingresar
/// @param char[] el mensaje que indica que debe ingresar un numero dentro del rango pedido
/// @param una letra a validar que se ingrese
/// @param otra letra como segunda opcion
/// @param la cantidad de reitentos
/// @return [-1] si hubo ERROR , [1] si se ingreso correctamente
int ValidarChar(char* respuesta,char mensaje[],char mensajeError[],char primerLetra , char segudaLetra,int reitentos);

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

/// @fn int ValidarFecha(int, int, int)
/// @brief Valida que si la fecha que se ingreso es valida
///
/// @param dia
/// @param mes
/// @param anio
/// @return [-1] si no es una fecha valida,[1] si es una fecha valida
int ValidarFecha(int dia,int mes,int anio);

#endif /* INPUT_H_ */
