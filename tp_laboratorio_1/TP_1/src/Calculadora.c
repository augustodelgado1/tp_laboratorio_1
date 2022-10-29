#include "Calculadora.h"

int CalcularDivision(int primerNumero,int segundoNumero,float* resultado)
{
	int estado;

	estado = -1;

	if(segundoNumero != 0){

		*resultado =  (float) primerNumero / segundoNumero;
		  estado = 1;
	}

	return estado;
}

int CalcularSuma(int primerNumero,int segundoNumero)
{
	int resultado;

	resultado = primerNumero + segundoNumero;

	return resultado;

}

int CalcularResta(int primerNumero,int segundoNumero)
{
	int resultado;

	if(primerNumero >= segundoNumero){
		resultado = primerNumero - segundoNumero;
	}else{
		resultado = segundoNumero - primerNumero;
	}

	return resultado;

}

int CalcularMultiplicacion(int primerNumero,float segundoNumero){

	int resultado;

	resultado = primerNumero * segundoNumero;

	return resultado;

}


