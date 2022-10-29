#include "eConfederacion.h"

int ObtenerIDConfederacion()
{
	static int idIncremental = 100;

	return idIncremental++;
}


int SubMenuDeConfederaciones(eConfederacion listaDeConfederaciones[],int sizeDeConfederacion)
{
	char respuesta;
	int retorno;
	int opcion;

		do{
												 menu("Menu De Confederaciones",
														  "\n[1].Alta De Confederacion\n"
														  "[2].Baja De Confederacon\n"
														  "[3].Modificar una confederacion\n"
														  "[4].Mostrar lista de confederaciones\n"
														  "[5].Volver al Menu Principal");

				   retorno = GetNumero(&opcion, "Ingrese Una opcion: ","ingrese Una opcion valida: ",1, 5, 2);

				   if(retorno != ERROR)
					{
						switch(opcion)
						{
							case 1:

								switch(AltaDeConfederacion(listaDeConfederaciones,sizeDeConfederacion)){
											case -2:
												printf("\n\nNo hay mas espacio\n");
												break;
											case 1:
												printf("\n\nSe Cargo con exito\n");
												break;
											default:
												printf("\n\nNo se pudo realizar el Alta\n");
												break;
											}

								break;

							case 2:

								 if(MostraListaDeConfederaciones(listaDeConfederaciones,sizeDeConfederacion) != ERROR)
								{
									 switch(BajaDeConfederacion(listaDeConfederaciones, sizeDeConfederacion))
									{
										case 0:
											printf("\nSe Cancelo la modificacion\n");
											break;

										case 1:
											printf("\nBaja exitosa\n");
											break;

										default:
											printf("\nNo se realizo la baja.\n");
											break;
									}

								}else{
									printf("Debe cargar al menos una Confederacion para dar de baja");
								}


								break;

							case 3:

								if(MostraListaDeConfederaciones(listaDeConfederaciones,sizeDeConfederacion) != ERROR)
								{
									switch(ModificarUnaConfederacion(listaDeConfederaciones,sizeDeConfederacion)){
											case 0:
												printf("\nSe Cancelo la modificacion\n");
												break;

											case 1:
												printf("\nModificacion exitosa.\n");
											  break;

											default:
											printf("\nNo se realizo la modificacion.\n");
												break;
											}

								}else{
									 printf("Debe cargar al menos una Confederacion  para realizar modificacion\n");
								}
								break;

							case 4:

								if(MostraListaDeConfederaciones(listaDeConfederaciones,sizeDeConfederacion) == ERROR)
								{
									printf("Debe cargar al menos una Confederacion  para mostrar la lista\n");
								}

								break;

							case 5:

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

int CargaForzadaDeConfederacion(eConfederacion listaDeConfederaciones[],int sizeDeConfederaciones,int id,char nombre[],char region[],int anioCreacion)
{
	int indexDeConfederacion;
	int estado;
	estado = ERROR;
	indexDeConfederacion =  BuscarConfederacionLibre(listaDeConfederaciones, sizeDeConfederaciones);

		if(indexDeConfederacion != ERROR && id >= 0 && nombre != NULL && region != NULL  && anioCreacion > 0)
		{
			listaDeConfederaciones[indexDeConfederacion].id = id;
			strcpy(listaDeConfederaciones[indexDeConfederacion].nombre,nombre);
			strcpy(listaDeConfederaciones[indexDeConfederacion].region,region);
			listaDeConfederaciones[indexDeConfederacion].anioCreacion = anioCreacion;
			listaDeConfederaciones[indexDeConfederacion].isEmpty = OCUPADO;
			estado = OK;
		}

		return estado;
}

int InicializarListaDeConfederaciones(eConfederacion listaDeConfederaciones[],int sizeDeConfederaciones)
{
	int estado;

	estado = ERROR;
	if(listaDeConfederaciones != NULL && sizeDeConfederaciones > 0)
	{
		for (int i = 0; i < sizeDeConfederaciones; i++)
			{
				listaDeConfederaciones[i].isEmpty = LIBRE;
			}
		estado = OK;
	}

	return estado;
}

int BajaDeConfederacion(eConfederacion listaDeConfederaciones[],int sizeDeConfederaciones){

	int estado;
	int index;
	char respuesta;
	int id;

	estado = ERROR;

	if(!GetNumero(&id,"\ningrese el id que desea eliminar ","\nError Ingrese id que desea eliminar ",1,1000000,2)){
    	    index = BuscarIdDeConfederacion(listaDeConfederaciones, sizeDeConfederaciones, id);

        	if(index >= 0 && listaDeConfederaciones[index].isEmpty == OCUPADO)
        	{

        		ImprimirCabecera("\t\t\tVas A dar de baja a esta confederacion\n"," ID |	      NOMRES        |	         REGION	          |	  ANIO CREACION      |\n","=", "-", 86);
        		MostrarUnaConfederacion(listaDeConfederaciones[index]);

        		estado = ValidarChar(&respuesta,"\n\n¿Esta seguro que quiere dar de baja esta confederacion? (s o n) ","Ingrese una opcion valida (s o n): ",'s' , 'n',2);


                switch(respuesta){
                    case 's':
                    listaDeConfederaciones[index].isEmpty = LIBRE;
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

int AltaDeConfederacion(eConfederacion listaDeConfederaciones[],int sizeDeConfederacion)
{
	int index;
	int estado;
	index = BuscarConfederacionLibre(listaDeConfederaciones,sizeDeConfederacion);
	estado = -2;

	if(index != ERROR)
	{
		estado = ERROR;
			if(CargarUnaConfederacion(&listaDeConfederaciones[index]) != ERROR)
			{
				listaDeConfederaciones[index].id = ObtenerIDConfederacion();
				estado = OK;
				ImprimirCabecera("\n\n\t\t\t ------- Nueva Confederacion -------\n","  ID |	      NOMRES        |	         REGION	          |	  ANIO CREACION      |\n","=","-",86);
				MostrarUnaConfederacion(listaDeConfederaciones[index]);
			}
	}

	return estado;
}

int ModificarUnaConfederacion(eConfederacion listaDeConfederaciones[],int sizeDeConfederaciones)
{
	int index;
	int estado;
	int opcion;
	char respuesta;
	int retorno;
	eConfederacion unaConfedracion;
	int id;
	int contadorDeCambios;

	retorno = GetNumero(&id,"Ingrese el id que desea Modificar: ","Ingrese un id valido: ",1, 100000,2);
    index = BuscarIdDeConfederacion(listaDeConfederaciones, sizeDeConfederaciones, id);
	estado = ERROR;
	contadorDeCambios =0;

		if(retorno != ERROR && index >= 0 && listaDeConfederaciones[index].isEmpty == OCUPADO){

			unaConfedracion = listaDeConfederaciones[index];

			do{
																	menu("Menu De Modificaciones"
																	,"\n¿Que Quiere modificar?"
																	 "\n\n[1].Modificar el nombre"
																	 "\n[2].Modificar la region"
																	 "\n[3].Modificar el anio de creacion"
																	 "\n[4].Volver a cargar todos los datos"
																	 "\n[5].Volver Al Menu Principal");

				if(!GetNumero(&opcion, "Ingrese Una opcion: ","ingrese Una opcion valida: ",1, 7, 2))
				{
					switch(opcion)
					{
						case 1:
						retorno = GetNombre("Ingrese el nuevo nombre: ","Error ingrese un nombre valido: ",unaConfedracion.nombre,MAX_NOMBRE_CONFEDERACION);
						    break;

						case 2:
							retorno = GetNombre("Ingrese la nuevo region: ","Error ingrese una region valido: ",unaConfedracion.region,MAX_REGION);
							break;

						case 3:
							retorno =	GetNumero(&unaConfedracion.anioCreacion,"Ingrese el anio de creacion: ","Error Ingrese un  anio de creacion valido (1000 - 2023): ", 1000, 2023, 2);
							break;

						case 4:
							retorno = CargarUnaConfederacion(&unaConfedracion);
						    break;

						case 5:

    						if(contadorDeCambios > 0)
    						{
    							ImprimirCabecera("\t\t\tConfederacion Anterior\n","  ID |	      NOMRES        |	         REGION	          |	  ANIO CREACION      |\n","=","-",86);
    						    MostrarUnaConfederacion(listaDeConfederaciones[index]);

    						    ImprimirCabecera("\t\t\tConfederacion Actualizada\n","  ID |	      NOMRES        |	         REGION	          |	  ANIO CREACION      |\n","=","-",86);
    						    MostrarUnaConfederacion(unaConfedracion);

    						    retorno = ValidarChar(&respuesta,"¿Esta seguro que desea volver al menu principal? (s o n): ","Ingrese una opcion valida (s o n): ",'s' , 'n',2);
    						}
						    break;
					    }


					if(retorno >= 0 && opcion != 5)
					{
					    printf("Se modifico exitosamente!!!!!!\n");
					    ImprimirCabecera("\t\t\tConfederacion Actualizada\n","  ID |	      NOMRES        |	         REGION	          |	  ANIO CREACION      |\n","=","-",86);
					     MostrarUnaConfederacion(unaConfedracion);
					    contadorDeCambios++;
					}else{

					    if(retorno == ERROR && opcion != 5)
					    {
					        printf("No se pudo realizar la modificacion\n");
					    }
					}

				}

		}while(opcion != 5);

    		switch(respuesta)
    		{
        		case 's':
        		listaDeConfederaciones[index] = unaConfedracion;
    		    estado = OK;
        		break;

        		case 'n':
        		estado = 0;
        		break;
    		}

		}


	return estado;
}

int CargarUnaConfederacion(eConfederacion* unaConfederacion)
{
	int estado;
	eConfederacion unaConfederacionAuxiliar;
	estado = ERROR;

	unaConfederacionAuxiliar.id = unaConfederacion->id;

	if(GetNombre("Ingrese el nombre de la confederacion: ", "Error ingrese un nombre valido: ",unaConfederacionAuxiliar.nombre, MAX_NOMBRE_CONFEDERACION)   != ERROR &&
		GetNombre("Ingrese la region de la confederacion: ", "Error ingrese una region valida: ",unaConfederacionAuxiliar.region, MAX_REGION) != ERROR &&
		GetNumero(&unaConfederacionAuxiliar.anioCreacion,"Ingrese el anio de creacion (1000 - 2023): ","Error Ingrese un  anio de creacion valido (1000 - 2023): ", 1000, 2023, 2) == 0)
	{
		unaConfederacionAuxiliar.isEmpty = OCUPADO;
		estado = OK;
		*unaConfederacion = unaConfederacionAuxiliar;
	}

	return estado;
}

int BuscarConfederacionLibre(eConfederacion listaDeConfederaciones[],int sizeDeConfederacion)
{
	int index;

	index = ERROR;

	for (int i = 0; i < sizeDeConfederacion; i++)
	{
		if(listaDeConfederaciones[i].isEmpty == LIBRE)
		{
			index = i;
			break;
		}
	}

	return index;
}

int MostraListaDeConfederaciones(eConfederacion listaDeConfederaciones[],int sizeDeConfederacion)
{
	int estado;

	estado = ERROR;

	if(CantidadDeConfederacionesCargadas(listaDeConfederaciones,sizeDeConfederacion) > 0)
		{
			ImprimirCabecera("\t\t\tLista De Confederaciones\n","  ID |	      NOMRES        |	         REGION	          |	  ANIO CREACION      |\n","=","-",86);
				for (int i =0;i<sizeDeConfederacion;i++){

					if(listaDeConfederaciones[i].isEmpty == OCUPADO)
					{
						 MostrarUnaConfederacion(listaDeConfederaciones[i]);
					}
				}
				MostrarUnMensajeRepetidasVeces("-", 86);
				printf("\n\n");
			estado = OK;
		}

	return estado;
}

void MostrarUnaConfederacion(eConfederacion unaCofederacion)
{
	       printf("|%3d | %-20s | %-27s | %15d %10s\n",unaCofederacion.id,
																						unaCofederacion.nombre,
																						unaCofederacion.region,
																						unaCofederacion.anioCreacion,"|");
}

int PedirConfederacion(eConfederacion listaDeConfederaciones[],int sizeDeConfederacion){
    int id;
    int index;

    index = ERROR;

    if(MostraListaDeConfederaciones(listaDeConfederaciones,sizeDeConfederacion) != ERROR
    && GetNumero(&id,"ingrese el id del Confederacion: ","Error ingrese un id Valido: ",1,10000,2) == 0)
    {
        index =  BuscarIdDeConfederacion(listaDeConfederaciones,sizeDeConfederacion,id);

        while(index == ERROR){
            printf("---- No se encontro el id ----\n");
            MostraListaDeConfederaciones(listaDeConfederaciones,sizeDeConfederacion);
            GetNumero(&id,"ingrese el id Confederacion: ","Error ingrese un id Valido: ",1,10000,2);
            index = BuscarIdDeConfederacion(listaDeConfederaciones,sizeDeConfederacion,id);
        }
    }

    return index;
}

int CantidadDeConfederacionesCargadas(eConfederacion listaDeConfederaciones[],int sizeDeConfederaciones)
{
	int cantidadDeConfederaciones;

	cantidadDeConfederaciones = 0;

	  if(listaDeConfederaciones  != NULL && sizeDeConfederaciones > 0)
		{
			  for (int i =0;i<sizeDeConfederaciones;i++)
			  {
				  if(listaDeConfederaciones[i].isEmpty == OCUPADO )
				 {
					  cantidadDeConfederaciones++;
				 }

			  }
		}

	  return cantidadDeConfederaciones;
}

int BuscarIdDeConfederacion(eConfederacion listaDeConfederaciones[],int sizeDeConfederaciones,int id)
{
	int index;

	index = ERROR;

	if(sizeDeConfederaciones >= 0 && id >= 0)
	{
		for (int i =0;i<sizeDeConfederaciones;i++) {

			if(listaDeConfederaciones[i].isEmpty == OCUPADO && listaDeConfederaciones[i].id == id)
			{
				index = i;
				break;
			}
		}
	}

	return index;
}


