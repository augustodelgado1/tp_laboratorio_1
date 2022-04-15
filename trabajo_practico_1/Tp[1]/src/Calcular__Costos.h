/**
 * @def CALCULAR_COSTOS_H_
 * @brief Esta bibloteca contiene funciones que permiten calcular costos de distintos medios de pago,
 *  tambien permite calcular el precio unitario y la diferncia.
 *
 * @Autor : Augusto Delgado
 * @Division B
 *
 */

#ifndef CALCULAR__COSTOS_H_
#define CALCULAR__COSTOS_H_

#include <stdio.h>

/// @fn float CalcularPagoTarjetaDebito(float)
/// @brief permite calcular el precio pagando con tarjeta De debito,realizando un descuento del 10% y devulve el resultado
///
/// @param float el numero ingresado
/// @return float El resultado del descuento con Tarjeta de Debito
float CalcularPagoTarjetaDebito(float);

/// @fn float CalcularPagoTarjetaCredito(float)
/// @brief permite calcular el pago con Tarjeta de credito , realizando un aumento del 25% y devulve el resultado
///
/// @param float el numero ingresado
/// @return float El total del precio pagando con targeta de credito
float CalcularPagoTarjetaCredito(float);

/// @fn float CalcularPagoBitcoin(float)
/// @brief Esta funcion permite calcular el precio pagando con bitcoin y devulve el resultado
///
/// @param float el precio ingresado
/// @return  float El resultado en bitcoin
float CalcularPagoBitcoin(float);

/// @fn float CalcularPrecioUnitario(float, float)
/// @brief esta funcion permite calcular el precio y devuelve el resultado
///
/// @param float el precio total
/// @param float la can
/// @return float el resultado de la division
float CalcularPrecioUnitario(float,float);

/// @fn float CalcularDiferencia(float, float)
/// @brief esta funcion permite calcular la diferencia entre dos numeros flotantes y devuelve el resultado
///
/// @param float el valor del numero
/// @param float el valor del numero
/// @return float devuelve el resultado de la diferencia
float CalcularDiferencia(float,float );


#endif /* CALCULAR__COSTOS_H_ */
