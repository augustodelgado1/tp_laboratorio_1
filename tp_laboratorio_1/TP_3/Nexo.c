/*
 * Nexo.c
 *
 *  Created on: 1 nov. 2022
 *      Author: alumno
 */
#include "Nexo.h"
#include "Menu.h"

int Nexo_MostrarJugadoresConSeleccion(Jugador* unJugador,Seleccion* unaSeleccion)
{
	int estado;
	int id;
	char nombreCompleto[MAX_NOMBRE];
	int edad;
	char posicion[MAX_POSICION];
	char nacionalidad[MAX_NACIONALIDAD];
	int idSeleccion;
	char pais[MAX_PAIS];
	estado = ERROR;

	if(unJugador != NULL && unaSeleccion != NULL &&
	jug_GetUnJugador(unJugador,&id, nombreCompleto,&edad, posicion, nacionalidad,&idSeleccion) != ERROR
	&& selec_getPais(unaSeleccion, pais) != ERROR)
	{
		printf("%-4d |  %-25s | %-10d | %-20s | %-25s | %-20s |\n",id,nombreCompleto,edad,posicion,nacionalidad,pais);
		estado = OK;
		MostrarUnMensajeRepetidasVeces("-", 130);
		printf("\n");
	}

	return estado;

}
