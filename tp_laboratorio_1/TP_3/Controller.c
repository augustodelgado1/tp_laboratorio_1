#include "LinkedList.h"
#include "Menu.h"
#include "Nexo.h"
#include "Controller.h"
#include "parser.h"


 int controller_BuscarIdMaximo(char* path)
 {
	 FILE* pArchivo = NULL;
 	int id;
 	char cadena[400];
	char ultimoId[400];
 	int maximo;
 	int retorno;

 	maximo = ERROR;

 	if(path != NULL)
 	{
 		pArchivo = fopen(path,"r");

 		if(pArchivo != NULL && fscanf(pArchivo,"%[^\n]",cadena) == OK)
 		{
 			for (int i = 0; (!feof(pArchivo)) ; i++) {

 				retorno = fscanf(pArchivo,"%[^,] %[^\n]",ultimoId,cadena);
 				id = atoi(ultimoId);

     			if(retorno == 2 && id != 0 && (id > maximo || i == 0))
     			{
     				maximo = id;
     			}
 			}
 			fclose(pArchivo);
 		}
 	}

 	return maximo;
 }


int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	FILE* pArchivo = NULL;
	int estado;
	estado = ERROR;

	if(pArrayListJugador != NULL && path != NULL && (pArchivo = fopen(path,"r")) != NULL)
	{
		estado =  parser_JugadorFromText(pArchivo, pArrayListJugador);
		fclose(pArchivo);
	}

    return estado;
}

int controller_GuardarUltimoId(char* path,int id)
{
	FILE* pArchivo = NULL;
	int estado;
	estado = ERROR;

		if(path != NULL && id > 0 && (pArchivo = fopen(path,"w")) != NULL)
		{
				fprintf(pArchivo,"%d\n",id);
				fclose(pArchivo);
				estado = OK;
		}

	return estado;
}

int controller_ObtenerUltimoId(char* path)
{
	FILE* pArchivo = NULL;
	char ultimoId[200];
	int id;
	id = ERROR;

		if(path != NULL && (pArchivo = fopen(path,"r")) != NULL )
		{
				fscanf(pArchivo,"%s",ultimoId);
				id = atoi(ultimoId);
				fclose(pArchivo);
		}

	return id;
}

int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
{
	    FILE* pArchivo = NULL;
		int estado;
		estado = ERROR;

		if(pArrayListJugador != NULL && path != NULL && (pArchivo = fopen(path,"r+b")) != NULL)
		{
					estado = parser_JugadorFromBinary(pArchivo, pArrayListJugador);
					fclose(pArchivo);
		}

    return estado;
}

int controller_agregarJugador(LinkedList* pArrayListJugador)
{
	int estado;
	int id;
	Jugador* unJugador = jug_new();
	estado = ERROR;

	if(pArrayListJugador != NULL && (id =  controller_ObtenerUltimoId("Id_Jugadores_Maximo.txt")) != ERROR)
	{
			id++;
			if(jug_PedirUnJugador(unJugador,id) != ERROR && controller_GuardarUltimoId("Id_Jugadores_Maximo.txt", id) != ERROR
				&& ll_add(pArrayListJugador, unJugador) != ERROR)
			{
				ImprimirCabecera("\n\n\t\t\t\t\t-- Nuevo de Jugadores -- \n","ID   | Nombre 	                  | Edad       | Posicion             | Nacionalidad   		  | Seleccion \n","=", "-", 130);
				jug_MostrarUnJugador(unJugador);
				estado = OK;
			}
	}

    return estado;
}


int controller_BuscarIdDeJugador(LinkedList* pArrayListJugador,int idABuscar){

	 int idDeJugador;
	 int size;
	 Jugador* unJugador;
	 int index;
	 index = ERROR;

	 if(pArrayListJugador != NULL && (size = ll_len(pArrayListJugador)) > 0)
	 {
		 for (int i = 0; i < size; i++) {

			 if((unJugador = (Jugador*) ll_get(pArrayListJugador, i))  != NULL
			&& jug_getId(unJugador,&idDeJugador) != ERROR && idDeJugador  == idABuscar)
			 {
				 index = i;
				 break;
			 }
		}
	 }

	 return index;
 }

int controller_editarJugador(LinkedList* pArrayListJugador)
{
	int idDeJugador;
	int index;
	Jugador* unJugador = NULL;
	int opcion;
	char respuesta;
	int retorno;
	char nombreCompleto[MAX_NOMBRE];
	int edad;
	char posicion[MAX_POSICION];
	char nacionalidad[MAX_NACIONALIDAD];
	int idSeleccion;
	retorno = ERROR;

	if(pArrayListJugador != NULL && GetNumero(&idDeJugador, "Ingrese el id de jugador que desea Modificar:  ", "Error ingrese un id valido: ", 1, 10000000, 5) != ERROR &&
	(index = controller_BuscarIdDeJugador(pArrayListJugador,idDeJugador)) != ERROR && (unJugador = (Jugador*) ll_get(pArrayListJugador, index)) != NULL
	&& jug_GetUnJugador(unJugador,&idDeJugador, nombreCompleto,&edad, posicion, nacionalidad,&idSeleccion) != ERROR)
	{
			do{
																menu("Menu  De Modificacion",
																"\n[1].Modificar el Nombre\n"
																"[2].Modificar la edad\n"
																"[3].Modificar la nacionalidad\n"
																"[4].Modificar la pocision\n"
																"[5].Volver al Menu Principal");

					if(!GetNumero(&opcion, "Ingrese Una opcion: ","ingrese Una opcion valida:  ",1, 5, 2))
					{
							switch(opcion)
							{
								case 1:
								retorno = GetNombre("Ingrese el nuevo nombre: ","Error ingrese un nombre valido",nombreCompleto,MAX_NOMBRE);
									break;

								case 2:
									retorno = GetNumero(&edad,"Ingrese la edad del jugador (16-50): " , "Error ingrese una de edad valida: ", 16, 50, 2);
									break;

								case 3:
									retorno = jug_PedirNacionalidad(nacionalidad, MAX_NACIONALIDAD);
									break;

								case 4:
									retorno = jug_PedirPosicion(posicion,MAX_POSICION) ;
									break;

								case 5:
									if(ValidarChar(&respuesta,"¿Esta seguro que desea volver al menu principal? (s o n):  ","Ingrese una opcion valida (s o n): ",'s' , 'n',2) == ERROR)
									{
										printf("\n\n\t\t\tError -- No se ingreso una opcion valida -- Error");
									}
									break;
								}

							if(retorno >= 0 && opcion != 5 && jug_SetUnJugador(unJugador, idDeJugador, nombreCompleto, edad, posicion, nacionalidad, idSeleccion) != ERROR)
							{
								printf("Se modifico exitosamente!!!!!!\n");
								retorno = index;
							}else{

								if(retorno == ERROR && opcion != 5)
								{
									printf("No se pudo realizar la modificacion\n");
								}

							}
					}

			}while(respuesta != 's');
	}

	return retorno;
}

int controller_removerJugador(LinkedList* pArrayListJugador)
{
	int estado;
	int index;
	char respuesta;
	Jugador* unJugador = NULL;
	index = ERROR;

	if(pArrayListJugador != NULL && (index = controller_GetIdJugador(pArrayListJugador, "Ingrese el id de jugador que desea Eliminar:  ", "Error ese id no existe: ", 2)) != ERROR && (unJugador =  (Jugador*) ll_get(pArrayListJugador, index))  != NULL
		&& (estado = ValidarChar(&respuesta,"¿Esta seguro que desea eliminar este jugador? (s o n): ","Ingrese una opcion valida (s o n): ",'s' , 'n',2)) != ERROR)
	{
	   switch(respuesta)
	   {
	   case 's':
		   ll_remove(pArrayListJugador, index);
		   break;

	   case 'n':
		   index = -2;
		  break;
	   }
	}

    return index;
}

int controller_MenuDeListados(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion)
{
		int opcion;
		char respuesta;
		int retorno;
		int estado;

		estado = ERROR;

		if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
		{
			estado = OK;

			do{
																			menu("Menu  De Listados ",
																			"\n[1].Lista de Jugadores\n"
																			"[2].Lista De Selecciones\n"
																			"[3] Lista de Jugadores convocados\n"
																			"[4].Volver al Menu Principal");

					if((estado = GetNumero(&opcion, "Ingrese Una opcion: ","ingrese Una opcion valida:  ",1, 4, 2)) == 0)
					{
							switch(opcion)
							{
								case 1:
									retorno = controller_MostrarListaDeJugadores(pArrayListJugador,pArrayListSeleccion);
									break;

								case 2:
									retorno = controller_listarSelecciones(pArrayListSeleccion);
									break;

								case 3:
									if(controller_listarConvocados(pArrayListJugador,pArrayListSeleccion) == ERROR)
									{
										printf("No hay Jugadores convovcados");
									}
									break;

								case 4:
									if(ValidarChar(&respuesta,"¿Esta seguro que desea volver al menu principal? (s o n): ","Ingrese una opcion valida (s o n): ",'s' , 'n',2) == ERROR)
									{
										printf("\n\n\t\t\tError -- No se ingreso una opcion valida -- Error");
									}
									break;
								}

						if(retorno == ERROR && opcion != 4)
						{
							printf("Se produjo un error al intentar mostrar la lista \n");
						}
					}

			}while(respuesta != 's' && estado != ERROR);
		}

		 return estado;
}

int controller_listarJugadores(LinkedList* pArrayListJugador)
{
	int estado;
	int size;
	estado = -2;
	int idSeleccion;
	Jugador* unJugador = NULL ;

	if(pArrayListJugador != NULL && (size = ll_len(pArrayListJugador)) > 0)
	{
		estado = OK;
		ImprimirCabecera("\t\t\t\t\t-- Lista de Jugadores -- \n","ID   | Nombre 	                  | Edad       | Posicion             | Nacionalidad   		  | 		Seleccion  		 | \n","=", "-", 130);

			for (int i = 0; i < size; i++) {

				if((unJugador = (Jugador*) ll_get(pArrayListJugador, i)) != NULL
					&& jug_getSIdSeleccion(unJugador,&idSeleccion)  != ERROR && idSeleccion == LIBRE)
				{
					jug_MostrarUnJugador(unJugador);
				}
			}
	}

    return estado;
}

int controller_ordenarJugadores(LinkedList* pArrayListJugador)
{
		int opcion;
		int retorno;
		int order;
		char respuesta;
		retorno = ERROR;

		if(pArrayListJugador != NULL)
		{
			do
			{
																								menu("Menu  De Ordenamiento",
																									"\n[1].Jugadores Ordenados por nacionalidad\n"
																									"[2].Jugadores Ordenados por edad\n"
																									"[3].Jugadores Ordenados por nombre\n"
																									"[4].Volver al Menu de ordenamiento");

			if(GetNumero(&opcion, "Ingrese Una opcion: ","ingrese Una opcion valida:  ",1, 4, 2) == 0
			&& (opcion == 4 || GetNumero(&order,"Ingrese de que manera desea ordenar la lista (0.Ascendente,1.Decendente): ","Error ingrese Una opcion valida (0.Ascendente,1.Decendente): ",0,1,2) == 0) )
			{
					switch(opcion)
					{
						case 1:
						retorno = ll_sort(pArrayListJugador, jug_CompararPorNacionalidad, order);
							break;

						case 2:
							retorno = ll_sort(pArrayListJugador, jug_CompararPorEdad, order);
							break;

						case 3:
							retorno = ll_sort(pArrayListJugador, jug_CompararPorNombre, order);
							break;

						case 4:
							if((retorno = ValidarChar(&respuesta,"¿Esta seguro que desea volver al menu principal? (s o n): ","Ingrese una opcion valida (s o n): ",'s' , 'n',2)) == ERROR)
							{
								printf("\n\n\t\t\tError -- No se ingreso una opcion valida -- Error");
							}
							break;
					}
				}
			}while(opcion != 4 && respuesta != 's');
		}

		return retorno;
}


int controller_ordenarListas(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion)
{
	int estado;
	int opcion;
	char respuesta;
	estado = ERROR;

	if(pArrayListJugador != NULL &&  pArrayListSeleccion != NULL)
	{
		estado = OK;

		do{

																			menu("Menu  De Ordenamiento",
																			"\n[1].Ordenar Jugadores"
																			"\n[2].Ordenadar lista de selecciones por confederacion"
																			"\n[3].Listar jugadores\n"
																			"[4].Listar Selecciones\n"
																			"[5].Volver al Menu Principal");

						if((estado = GetNumero(&opcion, "Ingrese Una opcion: ","ingrese Una opcion valida:  ",1, 5, 2)) == 0)
						{
								switch(opcion)
								{
									case 1:
										controller_ordenarJugadores(pArrayListJugador);
										break;

									case 2:
										controller_ordenarSelecciones(pArrayListSeleccion);
										break;

									case 3:
										controller_MostrarListaDeJugadores(pArrayListJugador,pArrayListSeleccion);
										break;

									case 4:
										controller_listarSelecciones(pArrayListSeleccion);
										break;

									case 5:
										if(ValidarChar(&respuesta,"¿Esta seguro que desea volver al menu principal? (s o n): ","Ingrese una opcion valida (s o n): ",'s' , 'n',2) == ERROR)
										{
											printf("\n\n\t\t\tError -- No se ingreso una opcion valida -- Error");
										}
										break;
									}
						    }

				}while(respuesta != 's');
	}

	return estado;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
	FILE* pArchivo = NULL;
	int estado;
	int size;
	int id;
	char nombreCompleto[MAX_NOMBRE];
	int edad;
	char posicion[MAX_POSICION];
	char nacionalidad[MAX_NACIONALIDAD];
	int idSeleccion;
	Jugador* unJugador = NULL;

		estado = ERROR;
		size = ll_len(pArrayListJugador);

		if(pArrayListJugador != NULL && path != NULL && size > 0)
		{
			pArchivo = fopen(path,"w");

			if(pArchivo != NULL && fprintf(pArchivo,"id,nombreCompleto,edad,posicion,nacionalidad,idSelecion\n") != ERROR)
			{
				estado = OK;
				for (int i = 0; i < size; i++) {

					unJugador = (Jugador*) ll_get(pArrayListJugador, i);

					if(unJugador == NULL || jug_GetUnJugador(unJugador,&id, nombreCompleto,&edad, posicion,nacionalidad,&idSeleccion) != OK
					|| fprintf(pArchivo,"%d,%s,%d,%s,%s,%d\n",id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion) == ERROR)
					{
						estado = ERROR;
						break;
					}

				}
				fclose(pArchivo);
			}
		}

		return estado;
}

int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador)
{
	FILE* pArchivo = NULL;
	int estado;
	int size;
	Jugador* unJugador = NULL;

	estado = ERROR;
	size = ll_len(pArrayListJugador);

		if(pArrayListJugador != NULL && path != NULL && size > 0)
		{
			pArchivo = fopen(path,"w+b");

			if(pArchivo != NULL)
			{
				estado = OK;

				for (int i = 0; i < size; i++) {

					if((unJugador = (Jugador*) ll_get(pArrayListJugador, i)) == NULL
					|| fwrite(unJugador,sizeof(Jugador),1,pArchivo) != OK)
					{
						estado = ERROR;
						break;
					}
				}
				fclose(pArchivo);
			}
		}

    return estado;
}

int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
	FILE* pArchivo = NULL;
	int estado;
	estado = ERROR;

	if(pArrayListSeleccion != NULL && path != NULL && (pArchivo = fopen(path,"r")) != NULL)
	{
			estado = parser_SeleccionFromText(pArchivo, pArrayListSeleccion);
			fclose(pArchivo);
	}
    return estado;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_editarSeleccion(LinkedList* pArrayListSeleccion)
{
		int index;
		Seleccion* unaSeleccion = NULL;
		int convocados;

		if(pArrayListSeleccion == NULL ||
		(index = controller_GetIdSeleccion(pArrayListSeleccion, "Ingrese el id de jugador que desea convocar:  ",  "Error ingrese un id valido: ", 2)) == ERROR
		|| (unaSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, index)) == NULL
		|| selec_getConvocados(unaSeleccion,&convocados) == ERROR || convocados >=  22 )
		{
			convocados++;
			selec_setConvocados(unaSeleccion, convocados);
			index = ERROR;
		}

		return index;
}

int controller_CantidadJugadoresConvocadosPorSeleccion(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador)
{
	int sizeDeJugadores;
	int sizeDeSelecciones;
	Seleccion* unaSeleccion = NULL;
	int idSeleccion;
	int estado;
	int jugadoresConvocados;

		estado = ERROR;
		if(pArrayListJugador != NULL &&  pArrayListSeleccion != NULL && (sizeDeJugadores = ll_len(pArrayListJugador)) > 0 &&
		(sizeDeSelecciones = ll_len(pArrayListSeleccion)) > 0)
		{
				jugadoresConvocados = 0;
				estado = OK;

			for (int i = 0; i < sizeDeSelecciones; i++) {

				unaSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, i);

				if(unaSeleccion == NULL || selec_getId(unaSeleccion,&idSeleccion) == ERROR ||
				(jugadoresConvocados = controller_CantdadJugadoresConcadosDeUnaSeleccion(pArrayListJugador,idSeleccion)) < 0 ||
				selec_setConvocados(unaSeleccion, jugadoresConvocados) == ERROR)
				{
					estado = ERROR;
					break;
				}
			}
		}

		return estado;
}

int controller_CantdadJugadoresConcadosDeUnaSeleccion(LinkedList* pArrayListJugador,int idSeleccion)
{
	int sizeDeJugadores;
	int idDeSeleccionDeJugador;
	Jugador* unJugador = NULL;
	int jugadoresConvocados;

		jugadoresConvocados = ERROR;

		if(pArrayListJugador != NULL &&  (sizeDeJugadores = ll_len(pArrayListJugador)) > 0)
		{
			jugadoresConvocados = 0;

			for (int i = 0; i < sizeDeJugadores; i++) {

				unJugador = (Jugador*) ll_get(pArrayListJugador, i);

				if(unJugador != NULL && jug_getSIdSeleccion(unJugador,&idDeSeleccionDeJugador) != ERROR &&
				idSeleccion == idDeSeleccionDeJugador)
				{
					jugadoresConvocados++;
				}
			}
		}

		return jugadoresConvocados;
}

int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
	int estado;
	int cantidadDeSelecciones;
	Seleccion* unaSeleccion = NULL;
	estado = -2;

		if(pArrayListSeleccion != NULL && (cantidadDeSelecciones = ll_len(pArrayListSeleccion)) > 0)
		{
			estado = OK;
			ImprimirCabecera("\t\t\t -- Lista De Selecciones --\n", "ID   |	 	PAIS 	    |	 CONFEDERACION 	   |   CONVOCADOS 	|\n", "=", "-", 73);

			for (int i = 0; i < cantidadDeSelecciones; i++) {

					if((unaSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, i)) == NULL
					|| selec_MostrarUnaSeleccion(unaSeleccion) == ERROR)
					{
						estado = ERROR;
						break;
					}
				}
		}

	    return estado;
}


int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
	int retorno;
	int order;
	retorno = ERROR;

	if(pArrayListSeleccion != NULL &&
	GetNumero(&order,"Ingrese de que manera desea ordenar la lista (0.Ascendente,1.Decendente): ","Error ingrese Una opcion valida (0.Ascendente,1.Decendente): ",0,1,2) == 0)
	{
		retorno = ll_sort(pArrayListSeleccion,selec_CompararPorConfederacion, order);
	}

    return retorno;
}

int controller_listarConvocados( LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int sizeDeJugadores;
	int sizeDeSelecciones;
	Jugador* unJugador = NULL;
	Seleccion* unaSeleccion = NULL;
	int idSeleccion;
	int indexDeSeleccion;
	int estado;

	estado = ERROR;
	if(pArrayListJugador != NULL &&  pArrayListSeleccion != NULL && (sizeDeJugadores = ll_len(pArrayListJugador)) > 0
		&& (sizeDeSelecciones = ll_len(pArrayListSeleccion)) > 0 && controller_CantidadDeJugadoresConvocados(pArrayListJugador, pArrayListSeleccion) > 0)
	{
			estado = OK;
			ImprimirCabecera("\t\t\t\t\t-- Lista de Jugadores -- \n","ID   | Nombre 	                  | Edad       | Posicion             | Nacionalidad   		  | Seleccion  		 		| \n","=", "-", 125);

			for (int i = 0; i < sizeDeJugadores; i++) {

				unJugador = (Jugador*) ll_get(pArrayListJugador, i);

				if(unJugador != NULL && jug_getSIdSeleccion(unJugador,&idSeleccion) != ERROR &&
				(indexDeSeleccion = controller_BuscarIdDeSeleccion(pArrayListSeleccion, idSeleccion)) != ERROR
				&&  (unaSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, indexDeSeleccion)) != NULL)
				{
						Nexo_MostrarJugadoresConSeleccion(unJugador, unaSeleccion);
				}
			}
	}

	return estado;
}


int controller_MostrarListaDeJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int sizeDeJugadores;
	int sizeDeSelecciones;
	Jugador* unJugador = NULL;
	Seleccion* unaSeleccion = NULL;
	int idSeleccion;
	int indexDeSeleccion;
	int estado;

	estado = ERROR;
	if(pArrayListJugador != NULL &&  pArrayListSeleccion != NULL && (sizeDeJugadores = ll_len(pArrayListJugador)) > 0 && (sizeDeSelecciones = ll_len(pArrayListSeleccion)) >= 0)
	{
			ImprimirCabecera("\t\t\t\t\t-- Lista de Jugadores -- \n","ID   | Nombre 	                  | Edad       | Posicion             | Nacionalidad   		  | Seleccion  		 		| \n","=", "-", 125);
			estado = OK;

			for (int i = 0; i < sizeDeJugadores; i++) {

				unJugador = (Jugador*) ll_get(pArrayListJugador, i);

				if(unJugador != NULL && (jug_getSIdSeleccion(unJugador,&idSeleccion) == ERROR ||
				 (indexDeSeleccion = controller_BuscarIdDeSeleccion(pArrayListSeleccion, idSeleccion)) == ERROR
				|| (unaSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, indexDeSeleccion)) == NULL ||
				Nexo_MostrarJugadoresConSeleccion(unJugador, unaSeleccion)  == ERROR))
				{
					jug_MostrarUnJugador(unJugador);
				}
			}
	}

	return estado;
}

int controller_BuscarIdDeSeleccion(LinkedList* pArraySeleccion,int idABuscar)
{
	int idSeleccion;
	 int size;
	 Seleccion* unaSeleccion;
	 int index;

		 index = ERROR;
		 size = ll_len(pArraySeleccion);

		 if(pArraySeleccion != NULL && size > 0)
		 {
			 for (int i = 0; i < size; i++) {

				 if((unaSeleccion = (Seleccion*) ll_get(pArraySeleccion, i))  != NULL
				&& selec_getId(unaSeleccion,&idSeleccion) != ERROR && idSeleccion  == idABuscar)
				 {
					 index = i;
					 break;
				 }
			}
		 }

	return index;
}

int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
	FILE* pArchivo = NULL;
	int estado;
	int size;
	int id;
	char pais[MAX_PAIS];
	char confederacion[MAX_CONFEDERACION];
	int convocados;
	Seleccion* unaSeleccion = NULL;

			estado = ERROR;

		if(pArrayListSeleccion != NULL && path != NULL && (size = ll_len(pArrayListSeleccion)) > 0)
		{
			pArchivo = fopen(path,"w");

			if(pArchivo != NULL && fprintf(pArchivo,"id,pais,confederacion,convocados\n") != ERROR)
			{
				estado = OK;
				for (int i = 0; i < size; i++) {

					unaSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, i);

					if(unaSeleccion == NULL || selec_GetUnaSeleccion(unaSeleccion,&id, pais, confederacion,&convocados) == ERROR ||
					fprintf(pArchivo,"%d,%s,%s,%d\n",id,pais,confederacion,convocados) == ERROR)
					{
						estado = ERROR;
						break;
					}

				}
				fclose(pArchivo);
			}
		}

		return estado;
}

int controller_ConvocarJugador(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador )
{
	int idSeleccion;
	int estado;
	int index;
	int indexDeSeleccion;
	char respuesta;
	Jugador* unJugador = NULL;
	Seleccion* unaSeleccion = NULL;

		estado = ERROR;
		if(pArrayListJugador != NULL &&  pArrayListSeleccion != NULL)
		{
			controller_listarJugadores(pArrayListJugador);
			index = controller_GetIdJugador(pArrayListJugador, "Ingrese el id del jugador que desea convocar:  ", "Error ingrese un numero valido: ", 1);

			if(index != ERROR  && (unJugador = (Jugador*) ll_get(pArrayListJugador, index)) != NULL  && jug_getSIdSeleccion(unJugador,&idSeleccion) != ERROR
				&& controller_BuscarIdDeSeleccion(pArrayListSeleccion, idSeleccion) == ERROR && (indexDeSeleccion = controller_editarSeleccion(pArrayListSeleccion)) != ERROR
				&& (unaSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, indexDeSeleccion)) != NULL)
				{
					ImprimirCabecera("\n\n\t\t\t\t\t-- Jugador Seleccionado -- \n","ID   | Nombre 	                  | Edad       | Posicion             | Nacionalidad   		  | Seleccion \n","=", "-", 130);
					Nexo_MostrarJugadoresConSeleccion(unJugador, unaSeleccion);

					estado = ValidarChar(&respuesta,"¿Esta seguro que desea convocar a este jugador a esta seleccion? (s o n): ","Ingrese una opcion valida (s o n): ",'s' , 'n',2);

						switch(respuesta)
						{
							case 's':
							if(selec_getId(unaSeleccion,&idSeleccion) != ERROR && jug_setIdSeleccion(unJugador, idSeleccion) != ERROR)
							{
								estado = OK;
							}
							break;

							case 'n':
							estado = 0;
							break;
						}
				}
		    }

		return estado;
}

LinkedList*  controller_FiltraListaDeJugadores(LinkedList* pArrayListJugador,LinkedList* pArrayListSelecciones,char confederacionIngresada[])
{
	LinkedList* listaFiltrada;
	Jugador* unJugador = NULL;
	Seleccion* unaSeleccion = NULL;
	int size;
	char confederacion[MAX_CONFEDERACION];
	int indiceDeSeleccion;
	int idSeleccionAuxiliar;
	size = ll_len(pArrayListJugador);
	listaFiltrada = ll_newLinkedList();


	if(pArrayListJugador != NULL && listaFiltrada != NULL && size > 0)
	{
		for (int i = 0; i < size; i++) {

			unJugador = (Jugador*) ll_get(pArrayListJugador, i);

			if(unJugador != NULL && jug_getSIdSeleccion(unJugador,&idSeleccionAuxiliar) != ERROR
			&& (indiceDeSeleccion = controller_BuscarIdDeSeleccion(pArrayListSelecciones, idSeleccionAuxiliar)) != ERROR
			&& (unaSeleccion = ll_get(pArrayListSelecciones, indiceDeSeleccion)) != NULL
			&& selec_getConfederacion(unaSeleccion, confederacion) != ERROR && strcmpi(confederacion,confederacionIngresada)  == 0)
			{
				ll_add(listaFiltrada, unJugador);
			}
		}
	}

	return listaFiltrada;
}

int controller_MenuDeConvocarJugador(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador )
{
	int opcion;
	int retorno;
	char respuesta;
	int cantidadDeJugadores;
	retorno = ERROR;
	cantidadDeJugadores = ll_len(pArrayListJugador);

	if(pArrayListSeleccion != NULL && pArrayListJugador != NULL )
	{
		do{
																   menu("Convocar Jugadores",
																	  "\n[1].Convocar un Jugador"
																	  "\n[2].Quitar de la seleccion un jugador"
																	  "\n[3].Volver al menu principal");
			controller_CantidadJugadoresConvocadosPorSeleccion(pArrayListSeleccion, pArrayListJugador);
			if((retorno = GetNumero(&opcion, "Ingrese una opcion: ","Ingrese Una opcion valida: ",1, 3, 2)) != ERROR)
			{
				switch(opcion)
				{
				case 1:

					if(cantidadDeJugadores >= controller_CantidadDeJugadoresConvocados(pArrayListJugador,pArrayListSeleccion))
					{
						if(controller_ConvocarJugador(pArrayListSeleccion,pArrayListJugador) == OK)
						{
							printf("Se convoco con exito al jugador");
						}else{
							printf("Se produjo un error al intentar convocar un jugador");
						}
					}else{
						printf("No se puede convocar mas jugadores");
					}
				   break;

				case 2:

				if(controller_CantidadDeJugadoresConvocados(pArrayListJugador,pArrayListSeleccion) > 0)
				{
					switch(controller_DesconvocarJugador(pArrayListSeleccion, pArrayListJugador))
					{
					case -1:
						printf("Se produjo un error al intentar desconvocar un jugador");
						break;

					case 0:
						printf("Se cancelo la desenvocacion");
						break;

					case 1:
						printf("Se desconvoco con exito el jugador");
						break;
					}
				}else{
					printf("Debe Convocar a un jugador para acceder a esta opcion");
				}
					break;

				case 3:
					if(ValidarChar(&respuesta,"¿Esta seguro que desea volver al menu principal? (s o n): ","Ingrese una opcion valida (s o n): ",'s' , 'n',2) == ERROR)
					{
						printf("\n\n\t\t\tError -- No se ingreso una opcion valida -- Error");
					}
					break;
				}

			}
		 }while(retorno != ERROR && respuesta != 's');
	}

	return retorno;
}

int controller_CantidadDeJugadoresConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int sizeDeJugadores;
	Jugador* unJugador = NULL;
	int idSeleccion;
	int jugadoresConvocados;

	jugadoresConvocados = ERROR;

	if(pArrayListJugador != NULL &&  pArrayListSeleccion != NULL && (sizeDeJugadores = ll_len(pArrayListJugador)) > 0)
	{
		jugadoresConvocados = 0;

			for (int i = 0; i < sizeDeJugadores; i++) {

				unJugador = (Jugador*) ll_get(pArrayListJugador, i);

				if(unJugador != NULL && jug_getSIdSeleccion(unJugador,&idSeleccion) != ERROR &&
				controller_BuscarIdDeSeleccion(pArrayListSeleccion, idSeleccion) != ERROR)
				{
						jugadoresConvocados++;
				}
			}
	}

	return jugadoresConvocados;
}

int controller_DesconvocarJugador(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador )
{
	int estado;
	int idSeleccion;
	int indexDeJugador;
	int indexDeSeleccion;
	char respuesta;
	Jugador* unJugador = NULL;
	Seleccion* unaSeleccion = NULL;
	estado = ERROR;

	if(pArrayListSeleccion != NULL && pArrayListJugador != NULL && controller_listarConvocados(pArrayListJugador, pArrayListSeleccion) != ERROR)
	{
		if((indexDeJugador = controller_GetIdJugador(pArrayListJugador, "Ingrese el id del jugador que desea desconvocar:  ", "Error ingrese un numero valido: ", 2)) != ERROR &&
		(unJugador = (Jugador*) ll_get(pArrayListJugador, indexDeJugador)) != NULL && jug_getSIdSeleccion(unJugador,&idSeleccion) != ERROR
		&& (indexDeSeleccion = controller_BuscarIdDeSeleccion(pArrayListSeleccion, idSeleccion)) != ERROR && (unaSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, indexDeSeleccion)) != NULL)
		{
			ImprimirCabecera("\n\n\t\t\t\t\t-- Jugador Seleccionado -- \n","ID   | Nombre 	                  | Edad       | Posicion             | Nacionalidad   		  | Seleccion \n","=", "-", 130);
			Nexo_MostrarJugadoresConSeleccion(unJugador, unaSeleccion);

			ValidarChar(&respuesta,"¿Esta seguro que desea desconvocar a este jugador? (s o n): ","Ingrese una opcion valida (s o n): ",'s' , 'n',2);

				switch(respuesta)
				{
					case 's':
					if(jug_setIdSeleccion(unJugador,LIBRE) != ERROR)
					{
						estado = OK;
					}
					break;

					case 'n':
					estado = 0;
					break;
				}
		}

	}

	return estado;
}


int controller_GetIdJugador(LinkedList* pArrayListJugador,char mensaje[],char mensajeError[],int reitentos)
{
	int index;
	int idDeJugador;

	index = ERROR;

		if(pArrayListJugador != NULL && reitentos >= 0 && GetNumero(&idDeJugador, mensaje,mensajeError, 1, 10000, 2) == 0){

	    	do{
	            if((index = controller_BuscarIdDeJugador(pArrayListJugador, idDeJugador)) != ERROR){

	            	 break;
	            }
	            GetNumero(&idDeJugador, mensajeError,mensajeError, 1, 10000, 2);
	            reitentos--;
	        }while(reitentos >= 0);

		}
		return index;
}


int controller_GetIdSeleccion(LinkedList* pArrayListSeleccion,char mensaje[],char mensajeError[],int reitentos)
{
	int index;
	int idABuscar;

	index = ERROR;

		if(pArrayListSeleccion != NULL && reitentos >= 0 && ll_sort(pArrayListSeleccion, selec_CompararPorId, 1) != ERROR
	  && controller_listarSelecciones(pArrayListSeleccion) != ERROR && GetNumero(&idABuscar, mensaje,mensajeError, 1, 10000, 2) == 0){

	    	do{
	            if((index = controller_BuscarIdDeSeleccion(pArrayListSeleccion, idABuscar)) != ERROR){

	            	 break;

	            }
	            GetNumero(&idABuscar, mensajeError,mensajeError, 1, 10000, 2);
	            reitentos--;
	        }while(reitentos >= 0);

		}
		return index;
}





