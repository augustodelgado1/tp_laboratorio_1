#include "input.h"

int getInt(int* numero,char mensaje[],char mensajeError[],int minimo,int maximo,int reitentos)
{
	int returnAux;
	int auxiliar;

	returnAux = -1;

	if(numero != NULL && mensaje != NULL && mensajeError != NULL && minimo<maximo && reitentos >= 0){

		auxiliar = -1;

		printf("%s",mensaje);
		fflush(stdin);
		scanf("%d",&auxiliar);

		do{


			if(auxiliar >= minimo && auxiliar <=  maximo){
				*numero =  auxiliar;
				returnAux = 1;
				break;
				}

		printf("%s",mensajeError);
		fflush(stdin);
		scanf("%d",&auxiliar);
		reitentos--;

		}while(reitentos >= 0);




	}

	return returnAux;

}

int getFloat(float* numero,char mensaje[],char mensajeError[],float minimo,float maximo,int reitentos)
{
	int returnAux;
	float auxiliar;

	returnAux = -1;

	if(numero != NULL && mensaje != NULL && mensajeError != NULL && minimo<maximo && reitentos >= 0){

		returnAux = 0;
		auxiliar = -1;

		printf("%s",mensaje);
		fflush(stdin);
		scanf("%f",&auxiliar);

		do{


			if(auxiliar >= minimo && auxiliar <=  maximo){
				*numero =  auxiliar;
				returnAux = 1;
				break;
				}

		printf("%s",mensajeError);
		fflush(stdin);
		scanf("%f",&auxiliar);
		reitentos--;

		}while(reitentos >= 0);
	}

	return returnAux;

}

int getChar(char* caracter,char mensaje[],char mensajeError[],char minimo,char maximo,int reitentos)
{
	int returnAux;
	char auxiliar;

	returnAux = -1;

	if(caracter != NULL && mensaje != NULL && mensajeError != NULL && minimo<maximo && reitentos >= 0){

		returnAux = 0;

		printf("%s",mensaje);
		fflush(stdin);
		scanf("%c",&auxiliar);

		do{


			if(auxiliar >= minimo && auxiliar <=  maximo){
				*caracter =  auxiliar;
				returnAux = 1;
				break;
				}

		printf("%s",mensajeError);
		fflush(stdin);
		scanf("%c",&auxiliar);
		reitentos--;

		}while(reitentos >= 0);




	}

	return returnAux;

}


