#include "Calcular__Costos.h"
#define BITCOIN 4606954.55

float CalcularPagoTarjetaDebito(float precio){
	float descunto;

	descunto = precio * 0.90;

	return descunto;

}

float CalcularPagoTarjetaCredito(float precio){
	float interes;

	interes = precio * 1.25;

	return interes;


}

float CalcularPagoBitcoin(float precio){
	float precioConBitcoin;

	precioConBitcoin = precio / BITCOIN;

	return precioConBitcoin;

}

float CalcularPrecioUnitario(float kilometros ,float precio){
	float precioUnitario;

	precioUnitario = precio / kilometros;

	return precioUnitario;

}

float CalcularDiferencia(float primerNumero ,float segundoNmero){
	float diferencia;

	if(primerNumero > segundoNmero){
		diferencia = primerNumero - segundoNmero;
	}else{
		diferencia = segundoNmero - primerNumero;
	}

	return diferencia;
}

/*
Augusto Delgado
Div 1B
*/
