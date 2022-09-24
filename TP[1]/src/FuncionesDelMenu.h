/*
 * FuncionesDelMenu.h
 *
 *  Created on: 17 sep. 2022
 *      Author: alumno
 */

#ifndef FUNCIONESDELMENU_H_
#define FUNCIONESDELMENU_H_

#include "input.h"
#include "Calculadora.h"

/// @fn int IngresarCostos(int*, int*, int*)
/// @brief Permite ingresar los costos en un sub menu aparte
///
/// @return [-1] si no se ingresaron todos los costos [1] si se ingresaron todos los costos
int IngresarCostos(int* costoDeHopedaje,int* costoDeComida,int* costoDeTransporte);

/// @fn void MostarUnMensaje(char[])
/// @brief Muestra un mensaje decorado con guiones
///
void MostarUnMensaje(char mensaje[]);

/// @fn int ValidarPosicion(int*, int*, int*, int*, int*)
/// @brief Valida que se ingrese una pocision valida y que no se pase de la cantidad de posicion
///
/// @return [-1] si hubo Error , [1] si salio ok
int ValidarPosicion(int* posicion,int* contadorArqueros,int* contadorDefensores,int* contadorMediocampista,int* contadorDelanteros);

/// @fn int CalcularCostosMercados(int, int, int, int, int, int, int, float*, float*, float*, float*, float*, float*)
/// @brief Permite calcular los costos del mercado
///
/// @return [-1] si hubo Error , [1] si salio ok
int CalcularCostosMercados(int contadorAFC,int contadorCONCACAF,int contadorCONMEBOL,int contadorOFC,int contadorUEFA,int contadorCAF,int contadorJugadores,
float* promedioAFC,float* promedioCONCACAF,float* promedioCONMEBOL,float* promedioOFC,float* promedioUEFA,float* promedioCAF);

/// @fn int InformarResultados(float, float, float, float, float, float, int, int, int, int)
/// @brief Informa los resultados de los calculos
///
/// @return [-1] si hubo Error , [1] si salio ok
int InformarResultados(float promedioUEFA,float promedioCONMEBOL,float promedioCONCACAF,float promedioAFC,float promedioOFC,float promedioCAF,int contadorJugadores,int,int,int);

/// @fn int PedirConfederacion(int*, int*, int*, int*, int*, int*, int*)
/// @brief Permite Pedir una confederacion y valida que se ingrese correctamente
///
/// @return [-1] si hubo Error , [1] si salio ok
int PedirConfederacion(int* confederacion,int* contadorAFC,int* contadorCONCACAF,int* contadorCONMEBOL,int* contadorUEFA,int* contadorOFC,int* contadorCAF);

/// @fn int CalcularAumento(int, int, int, int, int, int, int, int*)
/// @brief Compara todos los contadores y si se cumple la condicion realiza un aumento del 35%
///            y devuelve el total de los costos con el aumento incluido
///
/// @return [-1] si hubo Error , [1]  el total de los costos con el aumento incluido
int CalcularAumento(int contadorAFC,int contadorCONCACAF,int contadorCONMEBOL,int contadorCAF,int contadorUEFA,int contadorOFC,int sumaCostos,int* aumento);



#endif /* FUNCIONESDELMENU_H_ */
