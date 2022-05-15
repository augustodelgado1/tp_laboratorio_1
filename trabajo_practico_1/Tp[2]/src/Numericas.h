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
/// @return la cantidad total de pasajeros
int CalculateTotalPassengers(Passenger listaDePasjeros[], int size);

/// @fn float Sumador(Passenger[], int)
/// @brief rrecorre la lista de pasajeros  y suma todos los precios ingresados y devuelve el total
///
/// @param Passenger[] la lista de pasajeros
/// @param int la longitud del array
/// @return el total de los precios
int CalculateTotal(Passenger listaDePasjeros[], int size);

/// @fn int BusquedaDelMayor(Passenger[], int, float)
/// @brief Busca el/los precio que supera el promedio
///
/// @param Passenger[] la lista de pasajeros
/// @param int la longitud del array
/// @param float el promedio total de los precios
/// @return [1] si encontro un precio que supere al promedio , de lo contrario [0]
int LookingOlder(Passenger listaDePasjeros[], int size,float promedio);

/// @fn float CalcularPromedio(float, float)
/// @brief permite calcular el promedio y retorna el resultado
///
/// @param primerNumero el total de los precios
/// @param segundoNumero la cantidad de pasajeros
/// @return el resultado del promedio o (0) si no se pudo relalizar el promedio
float CalculateAverage(float primerNumero,float segundoNumero);
