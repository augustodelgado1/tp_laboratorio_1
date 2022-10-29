
#ifndef INPUT_H_
#define INPUT_H_

#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>

/// @fn int getInt(int*, char[], char[], int, int, int)
/// @brief Permite ingresar un entero dentro de un rango valido
///
/// @param el Entero donde se va a guardar el dato
/// @param El Mensaje que indica que dato se va guardar
/// @param Mensaje Error que indica que el dato debe estar dentro de un rango valido
/// @param un rango minimo
/// @param un rango maximo
/// @param la cantidad de reitentos para que reigrese el dato
/// @return [1] si se ingreso correctamente el dato, [-1] si hubo error
int getInt(int* numero,char mensaje[],char mensajeError[],int minimo,int maximo,int reitentos);

/// @fn int getFloat(float* numero,char mensaje[],char mensajeError[],float minimo,float maximo,int reitentos);
/// @brief Permite ingresar un flotante dentro de un rango valido
///
/// @param el flotante donde se va a guardar el dato
/// @param El Mensaje que indica que dato se va guardar
/// @param Mensaje Error que indica que el dato debe estar dentro de un rango valido
/// @param un rango minimo
/// @param un rango maximo
/// @param la cantidad de reitentos para que reigrese el dato
/// @return [1] si se ingreso correctamente el dato, [-1] si hubo error
int getFloat(float* numero,char mensaje[],char mensajeError[],float minimo,float maximo,int reitentos);

/// @fn int getInt(int*, char[], char[], int, int, int)
/// @brief Permite ingresar un caracter dentro de un rango valido
///
/// @param el caracter donde se va a guardar el dato
/// @param El Mensaje que indica que dato se va guardar
/// @param Mensaje Error que indica que el dato debe estar dentro de un rango valido
/// @param un rango minimo
/// @param un rango maximo
/// @param la cantidad de reitentos para que reigrese el dato
/// @return [1] si se ingreso correctamente el dato, [-1] si hubo error
int getChar(char* caracter,char mensaje[],char mensajeError[],char minimo,char maximo,int reitentos);



#endif /* INPUT_H_ */
