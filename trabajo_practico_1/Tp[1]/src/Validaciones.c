#include "Validaciones.h"

float PedirFlotanteYValidar (char mensaje[],char mensajeError[] ,int minimo){

	float datoIngresado;

	printf("%s",mensaje);
	scanf("%f",&datoIngresado);

	while(datoIngresado < minimo){
		printf("%s",mensajeError);
		scanf("%f",&datoIngresado);
	}

	return datoIngresado;
}

int PedirEnteroYValidar (char mensaje[],char mensajeError[] ,int minimo,int maximo){

	int datoIngresado;

	printf("%s",mensaje);
	scanf("%d",&datoIngresado);

	while(datoIngresado < minimo || datoIngresado > maximo){
		printf("%s",mensajeError);
		scanf("%d",&datoIngresado);
	}

	return datoIngresado;
}
