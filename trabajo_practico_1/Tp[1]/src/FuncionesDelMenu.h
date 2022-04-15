/**
 * @def FUNCIONESDELMENU_H_
 * @brief Esta bibloteca contiene las funciones que realiza el menu
 *
 * @Autor Augusto Delgado
 * @Division B
 */

#ifndef FUNCIONESDELMENU_H_
#define FUNCIONESDELMENU_H_

#include "Validaciones.h"
#include "Calcular__Costos.h"
#include <stdio.h>

/// @fn int OpcionesDelMenu(float, float, float)
/// @brief nos informa sobre las ditintas opciones de un menu y ademas nos permite seleccionar que opcion
/// queremos realizar
///
/// @param float el valor de la variable para informarlo
/// @param float el valor de la variable para informarlo
/// @param float el valor de la variable para informarlo
/// @return Int el numero de la opcion que elegimos realizar
int OpcionesDelMenu (float kilometros,float precioAerolineas,float precioLatam);

/// @fn void SepararTexto(void)
/// @brief esta funcion permite Separar el texto anadiendo una linea de guiones y saltos de linaes
///
void SepararTexto (void);


/// @fn void InformarResultados(char[], float, float, float, float, float)
/// @brief esta funcion permite informar los resultados de los costos de distintos medios de pago
/// (targeta de credito,Tarjeta de debito, Bitcoin),el precio total y el precio untario
///
/// @param char[] el mensaje indicandole de que producto
/// @param float el precio del producto
/// @param float el precio pagando con Tarjeta de debito
/// @param float el precio pagando con Tarjeta de credito
/// @param float el precio pagando con bitcoin
/// @param float el precio unitario
void InformarResultados (char[],float ,float ,float ,float ,float );

/// @fn void CargaForzadaDeDatos(float, float, float)
/// @brief permite calcular los costos de ditintos medios de pagos, el precio total y el precio untario llamando a
/// otras funciones y ademas muestra sus los resultados
///
/// @param kilometros  el valor de la variable
/// @param precioAerolineas el precio del producto
/// @param precioLatam el precio del producto
void  CargaForzadaDeDatos(float,float,float);


#endif /* FUNCIONESDELMENU_H_ */

/*
 * Augusto Delgado
 * Div B
 */
