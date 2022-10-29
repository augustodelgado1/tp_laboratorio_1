
#include "Nexo.h"

int SubMenuDeListados(eJugador listaDeJugadores[],int sizeDeJugadores,eConfederacion listaDeConfederaciones[],int sizeDeConfederaciones,eAuxiliar arrayAuxiliar[],int sizeAuxiliar)
{
	    int opcion;
	    int retorno;
	    char respuesta;
	    int maximo;
	    float promedio;
	   float totalDeSalario;
	   int cantidadDeJugadores;

	    do{
										 menu("Menu De Listado",
									  "\n[1].Listado de los jugadores ordenados alfabéticamente por nombre de confederación y nombre de jugador\n"
									  "[2].Listado de confederaciones con sus jugadores\n"
									  "[3].Total y promedio de todos los salarios y cuántos jugadores cobran más del salario promedio\n"
									  "[4].Informar la confederación con mayor cantidad de años de contratos total\n"
									  "[5].Informar porcentaje de jugadores por cada confederación\n"
									  "[6].Informar cual es la región con más jugadores y el listado de los mismos\n"
									  "[7].Volver al Menu Principal");

	       retorno = GetNumero(&opcion, "Ingrese Una opcion: ","ingrese Una opcion valida: ",1, 7, 2);

	       if(retorno != ERROR)
	        {
	            switch(opcion)
	            {
	                case 1:

							if(OrdenarPorNombreDeConfederaciones(listaDeJugadores, sizeDeJugadores, listaDeConfederaciones, sizeDeConfederaciones) == ERROR
							|| MostrarListaDeJugadores(listaDeJugadores, sizeDeJugadores, listaDeConfederaciones, sizeDeConfederaciones) == ERROR)
							{
								printf("\nNo se pudo ordenar la lista de jugadores");
							}

	                	break;

	                case 2:
	                	if(MostrarListaDeConderacionesConJugadores(listaDeConfederaciones,sizeDeConfederaciones,listaDeJugadores,sizeDeJugadores) == ERROR)
						{
	                		printf("\nNo se pudo lista las confederaciones");
						}

	                    break;
	                case 3:

	                	 totalDeSalario = CalcularTotalDeSalario(listaDeJugadores,sizeDeJugadores);
	                	 cantidadDeJugadores = CantidadDeJugadoresCargados(listaDeJugadores,sizeDeJugadores);

	                	 if(CalcularDivision(totalDeSalario, cantidadDeJugadores,&promedio) != ERROR)
	                	 {
	                		 MostrarUnMensajeRepetidasVeces("*", 135);
	                		 printf("\n\t\t\t\t\t\tEl Total de Salario es %.2f\n"
							 "\t\t\t\t\t\tEl promedio de todos los Salario es %.2f\n",totalDeSalario,promedio);
	                		 MostrarUnMensajeRepetidasVeces("*", 135);

								switch (MostrarListaDeJugadoresMaximoPromedio(listaDeJugadores,sizeDeJugadores,listaDeConfederaciones,sizeDeConfederaciones,promedio)) {
										case ERROR:
											printf("\n\t\t\tNo se pudo listar\n");
											break;
										case 0:
											printf("\n\t\t\tNo existe Ningun jugador que cobre mas que el salario promedio\n");
											break;
								}
	                	 }

	                	break;

	                case 4:

	                	if(InicializarListaAuxiliar(arrayAuxiliar,sizeAuxiliar) == ERROR
	                		|| TotalDeAniosDeContratoDeConfederaciones(listaDeConfederaciones, sizeDeConfederaciones, listaDeJugadores, sizeDeJugadores, arrayAuxiliar, sizeAuxiliar) == ERROR
	                		|| BuscarMayorAcumulado(arrayAuxiliar, sizeAuxiliar,&maximo) == ERROR ||
	                		MostrarConfederacionConMayorCantidad(arrayAuxiliar, sizeAuxiliar, listaDeConfederaciones, sizeDeConfederaciones, maximo) == ERROR)
	                		{
	                			printf("\n\t\t\tHubo error al intentar motrar el listado\n");
	                		}


	                    break;

	                case 5:

	                	if(InicializarListaAuxiliar(arrayAuxiliar,sizeAuxiliar) == ERROR || CantidadDeJugadoresPorCadaConfederacion(listaDeConfederaciones, sizeDeConfederaciones, listaDeJugadores, sizeDeJugadores, arrayAuxiliar, sizeAuxiliar) == ERROR
	                			|| CalcularPorcentajeArrayAuxiliar(arrayAuxiliar, sizeAuxiliar,CantidadDeConfederacionesCargadas(listaDeConfederaciones, sizeDeConfederaciones)) == ERROR ||
	                		MostrarPorcetajeDeJugadoresPorConfedecion(listaDeJugadores,sizeDeJugadores, listaDeConfederaciones, sizeDeConfederaciones, arrayAuxiliar, sizeAuxiliar) == ERROR)
	                	{
	                		printf("\n\t\t\tHubo error al intentar motrar el listado\n");
	                	}

	                	break;

	                case 6:

	                	if(MostrarRegionConMasJugadores(arrayAuxiliar, sizeAuxiliar,listaDeConfederaciones,sizeDeConfederaciones,listaDeJugadores,sizeDeJugadores) == ERROR)
	                	{
	                		printf("\n\t\t\tHubo error al intentar motrar el listado\n");
	                	}

	                    break;

	                case 7:

	                	if(ValidarChar(&respuesta,"¿Esta seguro que desea volver al menu principal? (s o n): ","Ingrese una opcion valida (s o n): ",'s' , 'n',2) == ERROR)
						{
							printf("\n\n\t\t\tError -- No se ingreso una opcion valida -- Error\n\n");
						}

	                    break;
	            }
	        }

	    }while(respuesta != 's' && retorno != ERROR);

	    return retorno;

}

int CargaForazada(eJugador listaDeJugadores[],int sizeDeJugadores,eConfederacion listaDeConfederaciones[],int sizeDeConfederaciones,int maximo)
{
    int estado;
    estado = ERROR;

    eJugador auxiliarJugadores[ ] = {{101,"Pablo Rogelio","Delantero",6,105,1000000,5,1},
															{102,"Karim Benzema","Delantero",1,104,500000,30,1},
															{103,"Lionel Messi","Delantero",10,101,2000,10,1},
															{104,"Enzo Fernandez","Mediocampista",23,102,20,1,1},
															{105,"Martin Perez","Delantero",31,101,100000,30,1},
                                                            {106,"Enzo Perez","Mediocampista",4,105,5000,20,1}};

    eConfederacion auxiliarDeConfederacion[ ]= {{100,"CONMEBOL","SUDAMERICA",1916,OCUPADO},
																				  {101,"UEFA","EUROPA",1954,OCUPADO},
																				  {102,"AFC","ASIA",1954,OCUPADO},
																				  {103,"CAF","AFRICA",1957,OCUPADO},
																				  {104,"CONCAF","NORTE Y CENTRO AMERICA",1961,OCUPADO},
																				  {105,"OFC","OCEANIA",1966,OCUPADO}};;



	if(sizeDeJugadores > maximo && sizeDeConfederaciones >= maximo)
	{
		 estado = OK;

        for(int i = 0;i<maximo;i++){

        	if(CargarForzadaDeJugador(listaDeJugadores,sizeDeJugadores,ObtenerIDJugador(),auxiliarJugadores[i].nombre,auxiliarJugadores[i].posicion,auxiliarJugadores[i].numeroCamiseta,auxiliarJugadores[i].idConfederacion,
        			auxiliarJugadores[i].salario,auxiliarJugadores[i].aniosContrato) == ERROR
        	||  CargaForzadaDeConfederacion(listaDeConfederaciones, sizeDeConfederaciones,ObtenerIDConfederacion(),auxiliarDeConfederacion[i].nombre,
        			auxiliarDeConfederacion[i].region,auxiliarDeConfederacion[i].anioCreacion) == ERROR)
        	{
        		estado = ERROR;
        		break;
        	}
        }

    }

    return estado;
}

int AltaDeJugador(eJugador listaDeJugadores[], int len,eConfederacion listaDeConfederaciones[],int sizeDeConfederaciones)
{
	int index;
	int estado;
	int indexDeConfederacion;

	estado = -2;

	index = BuscarLibre(listaDeJugadores,len);

	if(index != ERROR){

	    estado = ERROR;

	    if(PedirUnJugador(&listaDeJugadores[index],listaDeConfederaciones,sizeDeConfederaciones) != ERROR)
	    {
	    	listaDeJugadores[index].id = ObtenerIDJugador();
	    	ImprimirCabecera("\t\t\t\t\tNuevo Jugador\n","ID | Nombre 	               | Posicion             | Camiseta   | Confederacion        | Salario              |  Anio Contratacion \n","=", "-", 135);
	        indexDeConfederacion = BuscarIdDeConfederacion(listaDeConfederaciones, sizeDeConfederaciones,  listaDeJugadores[index].idConfederacion);
	        MostrarUnJugador(listaDeJugadores[index],listaDeConfederaciones[indexDeConfederacion]);
	        estado = OK;
	    }

	}
	return estado;
}


int PedirUnJugador(eJugador* unJugador,eConfederacion listaDeConfederaciones[],int sizeDeConfederaciones)
{
	    eJugador unJugadorAuxiliar;
	    int estado;
	    int indexConfederacion;
	    estado = ERROR;

	    if(unJugador != NULL){

		unJugadorAuxiliar.id = unJugador->id;

	        if(GetNombre("Ingrese el nombre del Jugador : ","Error Ingrese el nombre ",unJugadorAuxiliar.nombre,MAX_NOMBRE) == 0
			&& PedirPosicion(unJugadorAuxiliar.posicion,MAX_POSICION) != ERROR
			&& GetEnteroCorto(&unJugadorAuxiliar.numeroCamiseta,"Ingrese numero de camiseta (1-99): ","Error ingrese un numero valido: ", 1, 99, 2) == 0
			&& (indexConfederacion = PedirConfederacion(listaDeConfederaciones,sizeDeConfederaciones)) != ERROR
			&& GetNumeroFlotante(&unJugadorAuxiliar.salario, "Ingrese el salario del Jugador: ","Error ingrese un numero valido: ",1,10000000,2) == 0
			&& GetEnteroCorto(&unJugadorAuxiliar.aniosContrato,"ingrese el anio de Contrato (1-40): ","Error ingrese un anio Contrato valido: ",1,40,3) == 0)
	        {
	        	unJugadorAuxiliar.idConfederacion = listaDeConfederaciones[indexConfederacion].id;
	        	unJugadorAuxiliar.isEmpty = OCUPADO;
	           estado = OK;
	          *unJugador = unJugadorAuxiliar;
	        }
		}

	return estado;
}


int ModificarUnJugador(eJugador listaDeJugadores[], int size,eConfederacion listaDeConfederaciones[],int sizeDeConfederacion)
{
	int index;
	int estado;
	int opcion;
	char respuesta;
	int retorno;
	eJugador unJugador;
	int id;
	int contadorDeCambios;
	int indexConfederacion;
	int indexConfederacionAnterior;

	retorno = GetNumero(&id,"Ingrese el id que desea Modificar: ","Ingrese un id valido: ",1, 100000,2);
    index = BuscarUnJugadorPorId(listaDeJugadores,size,id);
	estado = ERROR;
	contadorDeCambios =0;

		if(retorno != ERROR && index >= 0 && listaDeJugadores[index].isEmpty == OCUPADO){

			unJugador = listaDeJugadores[index];

			do{
																	menu("Menu De Modificaciones"
																	,"\n¿Que Quiere modificar?"
																	 "\n\n[1].Modificar el nombre "
																	 "\n[2].Modificar la posicion"
																	 "\n[3].Modificar el Numero De Camiseta"
																	 "\n[4].Modificar la cofederacion"
																	 "\n[5].Modificar el salario"
																	 "\n[6].Modificar el anio de contarato"
																	 "\n[7].Volver Al Menu Principal ");

				if(!GetNumero(&opcion, "Ingrese Una opcion: ","ingrese Una opcion valida:  ",1, 7, 2))
				{
					switch(opcion)
					{
						case 1:
						retorno = GetNombre("Ingrese el nuevo nombre: ","Error ingrese un nombre valido",unJugador.nombre,MAX_NOMBRE);
						    break;

						case 2:
							retorno = PedirPosicion(unJugador.posicion,MAX_POSICION);
							break;

						case 3:
							retorno = GetEnteroCorto(&unJugador.numeroCamiseta,"Ingrese numero de camiseta (1-99): ","Error ingrese un numero valido (1-99): ",1, 99, 2);
							break;

						case 4:
							indexConfederacion = PedirConfederacion(listaDeConfederaciones,sizeDeConfederacion);
							if(indexConfederacion != ERROR)
							{
								unJugador.idConfederacion = listaDeConfederaciones[indexConfederacion].id;
								retorno = OK;
							}

						    break;

						case 5:
							retorno = GetNumeroFlotante(&unJugador.salario, "Ingrese el salario: ","Error ingrese un numero valido: ",1,10000000,2);
						    break;

						case 6:
							retorno = GetEnteroCorto(&unJugador.aniosContrato,"ingrese el anio de Contrato (1-40): ","Error ingrese un anio valido (1-40): ",1,40,3);
						    break;

						case 7:

    						if(contadorDeCambios > 0)
    						{
    						    ImprimirCabecera("\t\t\t\t\t\tJugador Anterior\n","ID | Nombre 	               | Posicion             | Camiseta   | Confederacion        | Salario              |  Anio Contratacion \n","=", "-", 140);
    						    indexConfederacionAnterior = BuscarIdDeConfederacion(listaDeConfederaciones, sizeDeConfederacion, listaDeJugadores[index].idConfederacion);
    						    MostrarUnJugador(listaDeJugadores[index],listaDeConfederaciones[indexConfederacionAnterior]);

    						    ImprimirCabecera("\t\t\t\t\t\tJugador Actualizado\n","ID | Nombre 	               | Posicion             | Camiseta   | Confederacion        | Salario              |  Anio Contratacion \n","=", "-", 140);
                        		indexConfederacion = BuscarIdDeConfederacion(listaDeConfederaciones, sizeDeConfederacion,unJugador.idConfederacion);
                        		MostrarUnJugador(unJugador,listaDeConfederaciones[indexConfederacion]);

                        		retorno = ValidarChar(&respuesta,"¿Esta seguro que desea volver al menu principal? (s o n): ","Ingrese una opcion valida (s o n): ",'s' , 'n',2);
    						}
						    break;
					    }


					if(retorno >= 0 && opcion != 7)
					{
					    printf("Se modifico exitosamente!!!!!!\n");
					    ImprimirCabecera("\t\t\t\t\t\tJugador Actualizado\n","ID | Nombre 	               | Posicion             | Camiseta   | Confederacion        | Salario              |  Anio Contratacion \n","=", "-", 130);
						indexConfederacion = BuscarIdDeConfederacion(listaDeConfederaciones, sizeDeConfederacion,unJugador.idConfederacion);
					    MostrarUnJugador(unJugador,listaDeConfederaciones[indexConfederacion]);
					    contadorDeCambios++;
					}else{

					    if(retorno == ERROR)
					    {
					        printf("No se pudo realizar la modificacion\n");
					    }
					}

				}

		}while(opcion != 7);

    		switch(respuesta)
    		{
        		case 's':
        		listaDeJugadores[index] = unJugador;
    		    estado = OK;
        		break;

        		case 'n':
        		estado = 0;
        		break;
    		}

		}


	return estado;
}

int BajaDeJugador(eJugador listaDeJugadores[], int len,eConfederacion listaDeConfederaciones[],int sizeDeConfederaciones){

	int estado;
	int index;
	char respuesta;
	int indexDeConfederacion;
	int id;
	estado = -2;

	if(!GetNumero(&id,"\ningrese el id que desea eliminar: ","\nError Ingrese id que desea eliminar ",1,2000,2)){
    	    index = BuscarUnJugadorPorId(listaDeJugadores,len,id);

        	if(index >= 0 && listaDeJugadores[index].isEmpty == OCUPADO)
        	{

        	ImprimirCabecera("Vas A dar de baja a este usuario\n","ID | Nombre 	               | Posicion             | Camiseta   | Confederacion        | Salario              |  Anio Contratacion \n","=", "-", 130);
        	indexDeConfederacion = BuscarIdDeConfederacion(listaDeConfederaciones, sizeDeConfederaciones, listaDeJugadores[index].idConfederacion);
        	MostrarUnJugador(listaDeJugadores[index],listaDeConfederaciones[indexDeConfederacion]);

        	estado = ValidarChar(&respuesta,"¿Esta seguro que desea eliminar esta confederacion? (s o n): ","Ingrese una opcion valida (s o n): ",'s' , 'n',2);


                switch(respuesta){
                    case 's':
                    listaDeJugadores[index].isEmpty = LIBRE;
                	estado = OK;
                    break;

                    case 'n':
                    estado = 0;
                    break;
                }
    	    }
	    }

	return estado;
}

int MostrarListaDeJugadores(eJugador listaDeJugador[],int size,eConfederacion listaDeConfederaciones[],int sizeDeConfederacion)
{
	int indexConfederacion;
	int estado;

	estado = ERROR;

	if(CantidadDeJugadoresCargados(listaDeJugador, size) > 0)
	{
		ImprimirCabecera("\t\t\t\t\t\tLista De Jugadores\n","ID | Nombre 	               | Posicion             | Camiseta   | Confederacion        | Salario              |  Anio Contratacion \n","=", "-", 135);
		for (int i = 0;i<size;i++) {

			indexConfederacion = BuscarIdDeConfederacion(listaDeConfederaciones, sizeDeConfederacion, listaDeJugador[i].idConfederacion);

			if(listaDeJugador[i].isEmpty == OCUPADO && indexConfederacion != ERROR){
					 MostrarUnJugador(listaDeJugador[i],listaDeConfederaciones[indexConfederacion]);
			 }


		}
		estado = OK;
	}

	return estado;
}

void MostrarUnJugador(eJugador unJugador,eConfederacion unaConfederacion)
{
		printf("|%-2d| %-25s | %-20s | %-10hd | %-20s | %-20.2f | %10hd\n",unJugador.id,
																													unJugador.nombre,
																													unJugador.posicion,
																													unJugador.numeroCamiseta,
																													unaConfederacion.nombre,
																													unJugador.salario,
																													unJugador.aniosContrato);
		MostrarUnMensajeRepetidasVeces("-", 140);
		printf("\n");
}



//1)
int OrdenarPorNombreDeConfederaciones(eJugador listaDeJugadores[],int size,eConfederacion listaDeConfederaciones[],int sizeDeConfederaciones)
{
    int indiceDeConfederacion;
    int indiceDeConfederacionSiguiente;
    eJugador unJugador;
    int estado;

    estado = ERROR;

    if(listaDeJugadores != NULL && size >= 0 && listaDeConfederaciones != NULL && sizeDeConfederaciones >= 0)
    {
        for (int i = 0; i <size-1; i++) {
            for (int j = i+1; j < size; j++) {

            	indiceDeConfederacion = BuscarIdDeConfederacion(listaDeConfederaciones,sizeDeConfederaciones,listaDeJugadores[i].idConfederacion);
                indiceDeConfederacionSiguiente = BuscarIdDeConfederacion(listaDeConfederaciones,sizeDeConfederaciones,listaDeJugadores[j].idConfederacion);

                if(listaDeJugadores[i].isEmpty == OCUPADO && indiceDeConfederacion != ERROR && indiceDeConfederacionSiguiente != ERROR
                && ((strcmp(listaDeConfederaciones[indiceDeConfederacion].nombre,listaDeConfederaciones[indiceDeConfederacionSiguiente].nombre) > 0)
                || (strcmp(listaDeConfederaciones[indiceDeConfederacion].nombre,listaDeConfederaciones[indiceDeConfederacionSiguiente].nombre) == 0
                && strcmp(listaDeJugadores[i].nombre,listaDeJugadores[j].nombre) > 0)))
                {
                    unJugador = listaDeJugadores[i];
                    listaDeJugadores[i] = listaDeJugadores[j];
                    listaDeJugadores[j] = unJugador;
                }

            }
        }
        estado = OK;

    }

    return estado;

}
//2)
int MostrarListaDeConderacionesConJugadores(eConfederacion listaDeConfederaciones[],int sizeDeConfederaciones,eJugador listaDeJugadores[],int sizeDeJugadores)
{
	int estado;

	estado = ERROR;

	if(CantidadDeConfederacionesCargadas(listaDeConfederaciones, sizeDeConfederaciones) > 0)
	{
		estado = OK;

		for(int i=0; i<sizeDeConfederaciones;i++){

		        if(listaDeConfederaciones[i].isEmpty == OCUPADO && ContarJugadoresDeUnaConfederacion(listaDeJugadores, sizeDeJugadores,listaDeConfederaciones[i].id) > 0){

		        	ImprimirCabecera("\t\t\t\tLista De Confederaciones\n"," ID |	      NOMRES        |	         REGION	          |	  ANIO CREACION      |\n","=","-",86);
		        	MostrarUnaConfederacion(listaDeConfederaciones[i]);
		        	MostrarUnMensajeRepetidasVeces("-", 86);
					 ImprimirCabecera("\n\n\t\t\t\t\t\t\t\t\t------------- Lista De Jugadores -------------\n\t\t\t\t","\t\t\t\t|         Nombre 	   |        Posicion          |     Camiseta   |        Salario            |     Anio Contratacion\n\t\t\t\t ","=", "-", 135);
		        	 MostrarListaDeJugadoresDeUnaConfederacion(listaDeJugadores,sizeDeJugadores,listaDeConfederaciones[i].id);
		        }
		}

	}
	return estado;
}

int MostrarConfederacionConMayorCantidad(eAuxiliar arrayAuxiliar[],int sizeAuxiliar,eConfederacion listaDeConfederaciones[],int sizeDeConfederaciones,int maximo)
{
    int indexConfederacion;
    int estado;
    estado = ERROR;

    if(arrayAuxiliar != NULL && sizeAuxiliar > 0 && listaDeConfederaciones != NULL && sizeDeConfederaciones > 0)
    {
    	ImprimirCabecera("\n\n\t\t\t-- La Confederacion Con Mayor Cantidad de Anios de contratos --\n","  ID |	      NOMRES        |	         REGION	          |	  ANIO CREACION      |   		ANIO DE CONTRATOS  		| \n","=", "-", 135);

		for (int i = 0; i <sizeAuxiliar; i++)
		{
			indexConfederacion = BuscarIdDeConfederacion(listaDeConfederaciones,sizeDeConfederaciones,arrayAuxiliar[i].id);

			if(arrayAuxiliar[i].estado == OCUPADO && indexConfederacion != ERROR && arrayAuxiliar[i].acumulador == maximo)
			{
			    printf("%4d | %-15s      | %-27s | %-15d %10s %-48d |\n",listaDeConfederaciones[indexConfederacion].id,listaDeConfederaciones[indexConfederacion].nombre,listaDeConfederaciones[indexConfederacion].region,listaDeConfederaciones[indexConfederacion].anioCreacion,"|",arrayAuxiliar[i].acumulador);
				MostrarUnMensajeRepetidasVeces( "-", 135);
			    break;
			}
		}
		estado = OK;
    }

    return estado;
}

//5) Informar porcentaje de jugadores por cada confederación.
int MostrarPorcetajeDeJugadoresPorConfedecion(eJugador listaDeJugadores[], int sizeJugadores,eConfederacion listaDeConfederaciones[],int sizeDeConfederaciones,eAuxiliar arrayAuxiliar[],int sizeAuxiliar)
{
	int estado;

	estado = ERROR;

	if(arrayAuxiliar != NULL && sizeAuxiliar >= 0 && listaDeConfederaciones != NULL && sizeDeConfederaciones >= 0 && listaDeJugadores != NULL && sizeJugadores >= 0)
	{
		ImprimirCabecera("\t\t\t\t\t\t---------- Lista De Confederaciones ----------\n","  ID |	      NOMRES        |	         REGION	          |	  ANIO CREACION      |   PORCENTAJE DE JUGADORES  |\n","=", "-", 135);

		for (int i = 0; i <sizeAuxiliar; i++)
		{
				 if(arrayAuxiliar[i].estado == OCUPADO && arrayAuxiliar[i].id == listaDeConfederaciones[i].id && arrayAuxiliar[i].porcentaje > 0)
				 {
					 printf("|%3d | %-20s | %-27s | %-22d   | %-26.2f %-10s\n",listaDeConfederaciones[i].id,
																													 listaDeConfederaciones[i].nombre,
																													 listaDeConfederaciones[i].region,
																													 listaDeConfederaciones[i].anioCreacion,
																													 arrayAuxiliar[i].porcentaje,"|");

					 MostrarUnMensajeRepetidasVeces( "-", 135);
					 printf("\n");
				 }
		}

				estado = OK;
	}

	return estado;
}

int TotalDeAniosDeContratoDeConfederaciones(eConfederacion listaDeConfederaciones[],int sizeDeConfederaciones,eJugador listaDeJugadores[],int size,eAuxiliar arrayAuxiliar[],int sizeAuxiliar)
{
    int estado;
    int indexAuxiliar;
    estado = ERROR;

    if(listaDeConfederaciones != NULL && sizeDeConfederaciones > 0 && listaDeJugadores != NULL && size > 0 && arrayAuxiliar != NULL && sizeDeConfederaciones <= sizeAuxiliar)
    {
        for (int i = 0; i <sizeDeConfederaciones; i++)
        {
        	indexAuxiliar = BuscarLibreAuxiliar(arrayAuxiliar, sizeAuxiliar);

        	if(listaDeConfederaciones[i].isEmpty == OCUPADO && ContarJugadoresDeUnaConfederacion(listaDeJugadores,size,listaDeConfederaciones[i].id) > 0 && indexAuxiliar != ERROR )
            {
                arrayAuxiliar[indexAuxiliar].id = listaDeConfederaciones[i].id;
                arrayAuxiliar[indexAuxiliar].acumulador = AcumularAniosContratoDeUnaConfederacion(listaDeJugadores,size,listaDeConfederaciones[indexAuxiliar].id);
                arrayAuxiliar[indexAuxiliar].estado = OCUPADO;
            }
        }
        estado = OK;
    }

    return estado;

}

int CantidadDeJugadoresPorCadaConfederacion(eConfederacion listaDeConfederaciones[],int sizeDeConfederaciones,eJugador listaDeJugadores[],int size,eAuxiliar arrayAuxiliar[],int sizeAuxiliar)
{
    int estado;
    int indexAuxiliar;
    estado = ERROR;

    if(listaDeConfederaciones != NULL && sizeDeConfederaciones > 0 && listaDeJugadores != NULL && size > 0 && arrayAuxiliar != NULL && sizeDeConfederaciones >= 0  && sizeAuxiliar >= 0)
    {
        for (int i = 0; i <sizeDeConfederaciones; i++)
        {
        	indexAuxiliar = BuscarLibreAuxiliar(arrayAuxiliar, sizeAuxiliar);
            if(listaDeConfederaciones[i].isEmpty == OCUPADO && indexAuxiliar != ERROR)
            {
                arrayAuxiliar[indexAuxiliar].id = listaDeConfederaciones[i].id;
                arrayAuxiliar[indexAuxiliar].contador = ContarJugadoresDeUnaConfederacion(listaDeJugadores,size,listaDeConfederaciones[indexAuxiliar].id);
                arrayAuxiliar[indexAuxiliar].estado = OCUPADO;
            }

        }
        estado = OK;
    }

    return estado;
}

int CantidadDeJugadoresCobranMasDelSalarioPromedio(eJugador listaDeJugadores[],int sizeDeJugadores,float promedio)
{
	int cantidad;

	cantidad = 0;

	if(listaDeJugadores != NULL && sizeDeJugadores >= 0)
	{
			for (int i = 0; i < sizeDeJugadores; i++) {

				if(listaDeJugadores[i].isEmpty == OCUPADO && listaDeJugadores[i].salario > promedio)
				{
					cantidad++;
				}
			}
	}

	return cantidad;
}

int MostrarListaDeJugadoresMaximoPromedio(eJugador listaDeJugadores[],int sizeDeJugadores,eConfederacion listaDeConfederaciones[],int sizeDeConfederaciones,float promedio)
{
    int indexDeConferederacion;
    int contador;
    int estado;

    estado = ERROR;

    if(listaDeJugadores != NULL && sizeDeJugadores > 0 && listaDeConfederaciones != NULL && sizeDeConfederaciones > 0 )
    {
       estado = 0;
       contador = CantidadDeJugadoresCobranMasDelSalarioPromedio(listaDeJugadores,sizeDeJugadores,promedio);

        if(contador > 0 && OrdenarListaDeJugadoresPorSalario(listaDeJugadores, sizeDeJugadores) != ERROR)
        {
        	ImprimirCabecera("\n\n\t\t\t\t\tLista De Jugadores Que Cobran mas que el salario Promedio\n","ID | Nombre 	               | Posicion             | Camiseta   | Confederacion        | Salario              |  Anio Contratacion \n","=", "-", 135);
            for (int i = 0; i <sizeDeJugadores; i++) {

               indexDeConferederacion = BuscarIdDeConfederacion(listaDeConfederaciones,sizeDeConfederaciones,listaDeJugadores[i].idConfederacion);

               if(listaDeJugadores[i].isEmpty == OCUPADO && listaDeJugadores[i].salario > promedio && indexDeConferederacion != ERROR)
               {
                   MostrarUnJugador(listaDeJugadores[i],listaDeConfederaciones[indexDeConferederacion]);
               }
            }
            estado = OK;
        }
    }

    return estado;
}


int MostrarRegionConMasJugadores(eAuxiliar arrayAuxiliar[],int sizeAuxiliar,eConfederacion listaDeConfederaciones[],int sizeDeConfederaciones,eJugador listaDeJugadores[],int sizeDeJugadores)
{
	int estado;
	int maximo;
	 estado = ERROR;

	    if(CantidadDeJugadoresDeCadaRegion(arrayAuxiliar, sizeAuxiliar, listaDeConfederaciones,
	    		sizeDeConfederaciones,listaDeJugadores, sizeDeJugadores) != ERROR && BuscarMayorCantidad(arrayAuxiliar, sizeAuxiliar, &maximo) != ERROR)
	    {
	    	ImprimirCabecera("\n\n- La Region Con Mayor Cantidad de Jugadores  --\n","|	      REGION	     |	 \n","=", "-", 30);

			for (int i = 0; i <sizeDeConfederaciones; i++)
			{
				if(arrayAuxiliar[i].estado == OCUPADO  && arrayAuxiliar[i].contador == maximo )
				{
				    printf("|%-28s|\n",listaDeConfederaciones[i].region);
					MostrarUnMensajeRepetidasVeces( "-", 30);
					ImprimirCabecera("\n\n\t\t\t\t\t\t\t\t\t------------- Lista De Jugadores -------------\n\t\t\t\t","\t\t\t\t|         Nombre 	   |        Posicion          |     Camiseta   |        Salario            |     Anio Contratacion\n\t\t\t\t","=", "-", 135);
					MostrarJugadoresDeUnaRegion(listaDeConfederaciones,sizeDeConfederaciones,listaDeJugadores,sizeDeJugadores,listaDeConfederaciones[i].region);
					break;
				}
			}
			estado = OK;
	    }

	    return estado;
}

int MostrarJugadoresDeUnaRegion(eConfederacion listaDeConfederaciones[],int sizeDeConfederaciones,eJugador listaDeJugadores[],int sizeDeJugadores,char region[])
{
	 int estado;
	 estado = ERROR;

	 if(listaDeConfederaciones !=  NULL && sizeDeConfederaciones >= 0 && listaDeJugadores !=  NULL && sizeDeJugadores >= 0 && region != NULL)
	 {
		 estado = OK;
	    for (int i = 0; i < sizeDeConfederaciones; i++) {

	       if(listaDeConfederaciones[i].isEmpty == OCUPADO
	       && strcmp(region,listaDeConfederaciones[i].region) == 0)
	       {
	    	   MostrarListaDeJugadoresDeUnaConfederacion(listaDeJugadores, sizeDeJugadores, listaDeConfederaciones[i].id);
	        }
	    }
	 }

	    return estado;
}

int CantidadDeJugadoresDeCadaRegion(eAuxiliar arrayAuxiliar[],int sizeDeAuxiliar,eConfederacion listaDeConfederaciones[],int sizeDeConfederaciones,eJugador listaDeJugadores[],int sizeDeJugadores)
{
    int indexAuxiliar;
    int estado;
    estado = ERROR;

    if(InicializarListaAuxiliar(arrayAuxiliar,sizeDeAuxiliar) != ERROR)
    {
		for (int i = 0; i <sizeDeConfederaciones; i++) {

			indexAuxiliar = BuscarLibreAuxiliar(arrayAuxiliar,sizeDeAuxiliar);
			arrayAuxiliar[indexAuxiliar].contador = 0;

			if(listaDeConfederaciones[i].isEmpty == OCUPADO)
			{
				arrayAuxiliar[indexAuxiliar].contador = ContarJugadoresDeCadaRegion(listaDeJugadores,sizeDeJugadores,listaDeConfederaciones,sizeDeConfederaciones,listaDeConfederaciones[i].region);
				arrayAuxiliar[indexAuxiliar].estado = OCUPADO;
			}
		}
		estado = OK;
    }

    return estado;
}

int ContarJugadoresDeCadaRegion(eJugador listaDeJugadores[],int sizeDeJugadores,eConfederacion listaDeConfederaciones[],int sizeDeConfederaciones,char region[])
{
    int cantidadDeJugadores;
    cantidadDeJugadores = 0;

    for (int i = 0; i < sizeDeConfederaciones; i++) {

       if(listaDeConfederaciones[i].isEmpty == OCUPADO
       && strcmp(region,listaDeConfederaciones[i].region) == 0)
       {
    	   cantidadDeJugadores += ContarJugadoresDeUnaConfederacion(listaDeJugadores,sizeDeJugadores,listaDeConfederaciones[i].id);
        }
    }

    return cantidadDeJugadores;
}


