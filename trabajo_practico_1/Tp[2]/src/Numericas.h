/*
 *  @brief contiene funciones que calculan la cantidad total de pasajeros , el promedio y el precio total.
 *
 */
#include "ArrayPassenger.h"

/// @fn int CantidadTotalDePasajeros(Passenger[], int)
/// @brief rrecorre la lista de pasajeros y cuenta cuantos se ingresaron y devuelve el total
///
/// @param Passenger[] la lista de pasajeros
/// @param int la longitud del array
/// @return int la cantidad total de pasajeros
int ContadorPasajeros(Passenger* list, int len);

/// @fn float Suma(Passenger[], int)
/// @brief rrecorre la lista de pasajeros  y suma todos los precios ingresados y devuelve el total
///
/// @param Passenger[] la lista de pasajeros
/// @param int la longitud del array
/// @return float la suma total de los precios
float Suma(Passenger* list, int len);

/// @fn int BucarMayor(Passenger* list, int len,float promedio);
/// @brief Busca el/los precio que supera el promedio
///
/// @param Passenger[] la lista de pasajeros
/// @param int la longitud del array
/// @param float el promedio total de los precios
/// @return [0] si no encontro un precio que supere al promedio , si no retorna la cantidad de pasajeros que supere al promedio
int BucarMayor(Passenger* list, int len,float promedio);

/// @fn float CalcularPromedio(float, float)
/// @brief permite calcular el promedio y retorna el resultado
///
/// @param primerNumero el total de los precios
/// @param segundoNumero la cantidad de pasajeros
/// @return el resultado del promedio o (0) si no se pudo relalizar el promedio
float CalcualarPromedio(float primerNumero ,int segundoNumero);
