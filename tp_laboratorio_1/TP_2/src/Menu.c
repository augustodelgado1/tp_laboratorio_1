#include "Menu.h"

void menu(char mensajeDeBienvenida[],char mensaje[]){

	printf("\n+-------------------------------------------------------+\n");
    printf("                  %15s ",mensajeDeBienvenida);
    printf("\n+-------------------------------------------------------+");
	printf("%s",mensaje);
	printf("\n+-------------------------------------------------------+\n");
}

void ImprimirCabecera(char cabecera[],char mensaje[],char segundoMensaje[],char tercerMensaje[],int cantidadDeVeces){
	    printf("%s",cabecera);
	    MostrarUnMensajeRepetidasVeces(segundoMensaje,cantidadDeVeces);
		printf("\n%s",mensaje);
		MostrarUnMensajeRepetidasVeces(tercerMensaje,cantidadDeVeces);
		printf("\n");
}

int MostrarUnMensajeRepetidasVeces(char mensaje[],int cantidadDeVeces)
{
	int estado;
	estado = -1;

	if(mensaje != NULL && cantidadDeVeces > 0)
	{
		for(int i=0;i<cantidadDeVeces;i++)
		{
			printf("%s",mensaje);
		}
		estado = 1;
	}

	return estado;
}


