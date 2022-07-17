#include "Menu.h"

int menu(int* opcion,char mensajeDeBienvenida[],char mensaje[],int minimo,int maximo){
	int estado;

	estado = -1;

    if(opcion != NULL){

    printf("\n+-------------------------------------------------------+\n");
    printf("                |  %10s |",mensajeDeBienvenida);
    printf("\n+-------------------------------------------------------+");
	printf("%s",mensaje);
	printf("\n+-------------------------------------------------------+");

	 if(!GetNumero(opcion,"\n\nIngrese una opcion: " ,
	    "Error ingrese una opcion valida " ,minimo, maximo,2)){
	        estado = 0;
	    }
    }

    return estado;
}



void ImprimirCabecera(char cabecera[],char mensaje[]){
	printf("\n\t\t------- %10s ---------\n",cabecera);
	printf("\n======================================================================================\n");
    printf("%s",mensaje);
	printf("\n======================================================================================\n");
}

/*
 * Augusto Delgado
 * Div B
 */

