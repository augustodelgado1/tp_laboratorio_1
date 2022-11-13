#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"


int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
	 	 char idStr[200];
	    char nombreCompletoStr[200];
	    char edadStr[200];
	    char posicionStr[200];
		char nacionalidadStr[200];
		char idSelccionStr[200];
	    Jugador* unJugador = NULL;
	    int estado;

	    estado = ERROR;

	   if(pFile != NULL && pArrayListJugador != NULL && fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idStr,nombreCompletoStr,edadStr,posicionStr,nacionalidadStr,idSelccionStr) == 6)
	   {
			   estado = OK;
			  while(!feof(pFile))
			  {
				   if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idStr,nombreCompletoStr,edadStr,posicionStr,nacionalidadStr,idSelccionStr) != 6 ||
					 (unJugador = jug_newParametros(idStr, nombreCompletoStr, edadStr, posicionStr, nacionalidadStr, idSelccionStr)) == NULL
					|| ll_add(pArrayListJugador, unJugador) == ERROR)
				   {
					   estado = ERROR;
					   break;
				   }
			  }
	    }


    return estado;
}


int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador)
{
	        Jugador* unJugador = NULL;
		    int estado;
		    estado = ERROR;

	   if(pFile != NULL && pArrayListJugador != NULL )
	   {
			   estado = OK;
			  while(!feof(pFile))
			  {
				  if((unJugador = jug_new()) != NULL && fread(unJugador,sizeof(Jugador),1,pFile) == OK)
				  {
					  ll_add(pArrayListJugador, unJugador);
				  }
		   }
		}

    return estado;
}

int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	    char idStr[200];
		char paisStr[200];
		char confederacionStr[200];
		char convocadosStr[200];
	    int estado;
	    Seleccion* unaSeleccion = NULL;
	    estado = ERROR;

	       if(pFile != NULL && pArrayListSeleccion != NULL && fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idStr,paisStr, confederacionStr, convocadosStr) == 4)
		   {
				  estado = OK;
				  while(!feof(pFile))
				  {
					   if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idStr, paisStr, confederacionStr, convocadosStr) != 4
						|| (unaSeleccion = selec_newParametros(idStr,paisStr, confederacionStr, convocadosStr)) == NULL
						|| ll_add(pArrayListSeleccion, unaSeleccion) == ERROR)
					   {

						   estado = ERROR;
						   break;
					   }
				  }
		    }

    return estado;
}

