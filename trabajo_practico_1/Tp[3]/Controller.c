#include "Controller.h"


int idMaximo(char* path)
{
	FILE* auxFile;
	char idTxt[100];
	int id;
	int auxiliar;
	int flag;

	flag = 0;
	auxFile = fopen(path,"r");

	do{

		if(fscanf(auxFile, "%[^\n]\n", idTxt) == 1){

			id = atoi(idTxt);

			if(id > auxiliar || !flag){
				auxiliar = id;
				flag = 1;
			}
		}

	}while(!feof(auxFile));

	return auxiliar;

}

int controller_ObtenerUltimoId(char* path, int* id)
{
	FILE* auxFile;
	int estado = -1;
	char idTxt[128];

	auxFile = fopen(path, "r");

	if (auxFile != NULL)
	{
		do{


			if (fscanf(auxFile, "%[^\n]\n", idTxt) == 1)
			{
				*id = atoi(idTxt);

				estado = 0;
			}

		}while(!feof(auxFile));

		fclose(auxFile);
	}

	return estado;
}


int controller_IdMaxFile(char* path,int id)
{
	int estado = -1;
	int ultimoId;

	FILE* auxFile = fopen(path, "w");

	if (auxFile != NULL)
	{
		ultimoId = id;
		ultimoId++;
		fprintf(auxFile,"%d\n",ultimoId);

		fclose(auxFile);
		estado = 0;
	}
    return estado;
}

int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pAuxArchivo;
	int estado;

	estado = -2;

	if(pArrayListPassenger != NULL && path != NULL){

		pAuxArchivo = fopen(path,"r");
		estado = -1;

	if(pAuxArchivo != NULL){

		if(!parser_PassengerFromText(pAuxArchivo, pArrayListPassenger))
		{
			estado = 0;
		}

		fclose(pAuxArchivo);
	}

	}

	return estado;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* auxArchivo = NULL;
	int estado;

	estado = -1;

	if(pArrayListPassenger != NULL && path != NULL)
		{
			auxArchivo = fopen(path,"r+b");

			if(auxArchivo != NULL && (!parser_PassengerFromBinary(auxArchivo, pArrayListPassenger)))
			{
				estado = 0;
			}

			fclose(auxArchivo);
		}

	return estado;
}

int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* unPasajero;
	int estado;
	int id;
	char nombre[MAX_NOMBRE];
	char apellido[MAX_NOMBRE];
	float precio;
	char tipoPasajero[MAX_TIPO_DE_PASAJERO];
	char statusFlight[MAX_TIPO_DE_PASAJERO];
	char codigoVuelo[MAX_CODIGO_DE_VUELO];
	unPasajero = Passenger_new();

	estado = -2;

	if(pArrayListPassenger != NULL && unPasajero != NULL){

	estado = -1;
	controller_ObtenerUltimoId("idmaximo.csv",&id);

	   if((!PassengerNew(&id,nombre,apellido,&precio,codigoVuelo,statusFlight,tipoPasajero)) &&
			(!PassengerNewWithParameters(unPasajero,id,nombre,apellido, precio, codigoVuelo,statusFlight,tipoPasajero))){

				ll_add(pArrayListPassenger, unPasajero);
				controller_IdMaxFile("idmaximo.csv",id);
				ImprimirCabecera("Nuevo Pasajero","id -- Nombre -- Apellido -- Precio -- Codigo De Vuelo -- Tipo De Pasajero  -- Estado de Vuelo");
				PassengerPrintOne(unPasajero);
				estado = 0;
			}
}

	return estado;
}

int PassengerNew(int* id,char* nombre ,char* apellido,float* precio,char* codigoVuelo,char* statusFlight,char* tipoVuelo)
{

	int estado;

	estado = -1;

	if(id != NULL && nombre != NULL && apellido != NULL && precio != NULL && codigoVuelo != NULL &&
		statusFlight != NULL && tipoVuelo != NULL)
	{

		if(GetNombre("ingrese el nombre ", "Error ",nombre, MAX_NOMBRE) == 0
		&& GetNombre("ingrese el apellido ", "Error ",apellido, MAX_NOMBRE) == 0
		&& GetNumeroFlotante(precio, "ingrese el precio ", "Error ", 1, 5) == 0
		&& Passenger_PedirTipoVuelo(tipoVuelo, MAX_TIPO_DE_PASAJERO) == 0
		&& Passenger_PedirEstadoDeVuelo(statusFlight, MAX_TIPO_DE_PASAJERO) == 0
		&& GetAlphanumeic("ingrese codigo ", "Error " ,codigoVuelo, MAX_CODIGO_DE_VUELO) == 0)
				{

					estado = 0;
				}
	}


	return estado;

}

int controller_Get_IndexByPassengerId(LinkedList* pArrayListPassenger,int id)
{
	int estado;
	Passenger* unPasajero;
	int len;
	int auxiliarId;

	estado = -1;

	len = ll_len(pArrayListPassenger);

	if(len > 0){

		for(int i=0;i<len;i++){

			unPasajero = (Passenger*) ll_get(pArrayListPassenger,i);

			if(Passenger_getId(unPasajero,&auxiliarId) == 0 && auxiliarId == id)
			   {
				 estado = i;
				 break;
			   }
		}

	}


    return estado;
}


int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int id;
	char nombre[MAX_NOMBRE];
	char apellido[MAX_NOMBRE];
	float precio;
	char tipoVuelo[MAX_TIPO_DE_PASAJERO];
	char statusFlight[MAX_TIPO_DE_PASAJERO];
	char codigoVuelo[MAX_CODIGO_DE_VUELO];
	int index;
	int estado;
	int opcion;
	char respuesta;
	int i =0;
	Passenger* unPasajero = NULL;
	Passenger auxiliar;

	estado = -3;

	if(pArrayListPassenger != NULL && controller_ListPassenger(pArrayListPassenger) == 0){

		GetNumero(&id,"Ingrese el id que desea Modificar: ","Ingrese un id valido ",1, 100000,2);

		index = controller_Get_IndexByPassengerId(pArrayListPassenger, id);

		estado = -2;

		if(index >= 0){

			unPasajero = (Passenger*) ll_get(pArrayListPassenger, index);

			if(unPasajero != NULL){

				auxiliar = *(unPasajero);
				estado = -1;

				do{
									menu(&opcion,"Menu De Modificaciones"
														,"\n¿Que Quiere modificar?"
														 "\n\n[1].Modificar el nombre "
														 "\n[2].Modificar el apellido."
														 "\n[3].Modificar el precio"
														 "\n[4].Modificar el tipo de pasajero"
														 "\n[5].Modificar el estado de pasajero"
														 "\n[6].Modificar el codigo vuelo"
														 "\n[7].Modificar todo los datos"
														 "\n[8].Volver Al Menu Principal ", 1, 8);

						switch(opcion)
						{

							case 1:

								if((!GetNombre("ingrese el nuvo nombre ","Error ingrese un nombre valido",nombre,MAX_NOMBRE))
									&& (!Passenger_setNombre(&auxiliar, nombre)))
								{
									printf("\nSe Modifico el apellido\n\n");
								}else{
									printf("\nNo se pudo realizar Modificacion\n\n");
								}

							break;

							case 2:

								if((!GetNombre("ingrese el nuvo apellido ","Error ingrese un apellido valido",apellido,MAX_NOMBRE))
								&& (!Passenger_setApellido(&auxiliar, apellido))){

									printf("\nSe Modifico el apellido\n\n");
								}else{
									printf("\nNo se pudo realizar Modificacion\n\n");
								}

							break;

							case 3:

								if((!GetNumeroFlotante(&precio, "ingrese el precio ", "Error Ingrese un precio valido ", 0,2))
								&& (!Passenger_setPrecio(&auxiliar, precio))){

									printf("\nSe Modifico el precio\n\n");
								}else{
									printf("\nNo se pudo realizar Modificacion\n\n");
								}

							break;

							case 4:

								if((!Passenger_PedirTipoVuelo(tipoVuelo, MAX_TIPO_DE_PASAJERO))
								&& (!Passenger_setTipoPasajero(&auxiliar, tipoVuelo))){

									printf("\nSe Modifico el tipo de Vuelo\n\n");
								}else{
									printf("\nNo se pudo realizar Modificacion\n\n");
								}

							break;

							case 5:

								if((!Passenger_PedirEstadoDeVuelo(statusFlight, MAX_TIPO_DE_PASAJERO))
									&& (!Passenger_setStatusFlight(&auxiliar, statusFlight))){

									printf("\nSe Modifico el estado de pasajero\n\n");
								}else{
									printf("\nNo se pudo realizar Modificacion\n\n");
								}

							break;

							case 6:

								if((!GetAlphanumeic("ingrese el codigo Vuelo  ","Error Ingrese un codigo Vuelo valido ",codigoVuelo,MAX_CODIGO_DE_VUELO))
								&& (!Passenger_setCodigoVuelo(&auxiliar, codigoVuelo))){

									printf("\nSe Modifico el codigo Vuelo\n\n");
								}else{
									printf("\nNo se pudo realizar Modificacion\n\n");
								}

							break;

							case 7:

								if((!PassengerNew(&id, nombre, apellido, &precio, codigoVuelo, statusFlight, tipoVuelo))
								&& (!PassengerNewWithParameters(&auxiliar, id, nombre, apellido, precio, codigoVuelo, statusFlight, tipoVuelo))){
									printf("\nSe Modifico con exito!!\n\n");
								}else{
									printf("\nNo se pudo realizar Modificacion\n\n");
								}

							break;
						}

						i++;

				}while(opcion != 8);
			}

		}

		if(i>0){

			ImprimirCabecera("Pasajero Anterior","id -- Nombre -- Apellido -- Precio -- Codigo De Vuelo -- Tipo De Vuelo  -- Estado de Vuelo ");
			PassengerPrintOne(unPasajero);

			ImprimirCabecera("Pasajero Actualizado","id -- Nombre -- Apellido -- Precio -- Codigo De Vuelo -- Tipo De Vuelo  -- Estado de Vuelo");
			PassengerPrintOne(&auxiliar);

			respuesta = PreguntarSoN("\n\n¿Desea guardar los cambios? (s o n): " ,"Error solo (s o n): ");

				if(respuesta == 's'){
					*unPasajero = auxiliar;
					ll_set(pArrayListPassenger, index, unPasajero);
					estado = 0;
				}
		}

	}

    return estado;
}

/** \brief Elimina un elemento de la lista de pasajero (si encontro el id)
 *
 * \param pArrayListPassenger LinkedList* el puntero a la lista
 * \return int [0] Si Pudo eliminar el pasajero o [-1] Si se cancelo la baja o [-2] Si no encontro el id
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int id;
	int idMaximo;
	int index;
	int estado;
	char respuesta;
	Passenger* unPasajero = NULL;

	estado = -3;

	if(!ll_isEmpty(pArrayListPassenger)){

		controller_ListPassenger(pArrayListPassenger);

		GetNumero(&id,"Ingrese el id del Usuario que desea eliminar ","Ingrese un id valido ",1, 100000,2);
		index = controller_Get_IndexByPassengerId(pArrayListPassenger, id);

		estado = -2;

			if(index >= 0){

				unPasajero = (Passenger*) ll_get(pArrayListPassenger, index);

				ImprimirCabecera("Vas a eliminar a este Pasajero","id -- Nombre -- Apellido -- Precio -- Tipo De Vuelo  -- Estado de Vuelo  -- Codigo De Vuelo");
				PassengerPrintOne(unPasajero);

				respuesta = PreguntarSoN("\n\n¿Esta seguro que quiere dar de baja este usuario? (s o n): " ,"Error solo (s o n): ");

				switch(respuesta){
				case 's':
					controller_ObtenerUltimoId("idmaximo.csv",&idMaximo);

					if(id >= idMaximo){
						controller_IdMaxFile("idmaximo.csv", id);
					}

				    ll_remove(pArrayListPassenger, index);
					estado = 0;
					break;

				case 'n':
					estado = -1;
					break;
			}
		}
	}

	return estado;
}


int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* unPasajero;
	int len;
	int estado;

	estado = -1;

	if(pArrayListPassenger != NULL){

	len = ll_len(pArrayListPassenger);

		if(len > 0){

			ImprimirCabecera("Lista De Pasajeros","id -- Nombre -- Apellido -- Precio -- Codigo De Vuelo -- Tipo De Pasajero  -- Estado de Vuelo");

			for(int i=0;i<len;i++){

				unPasajero = (Passenger*) ll_get(pArrayListPassenger, i);

				PassengerPrintOne(unPasajero);
			}
			estado = 0;
		}

	}


	return estado;
}


int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int opcion;
	int flag;
	int estado;

	flag = ll_isEmpty(pArrayListPassenger);
	estado = -1;

	if(pArrayListPassenger != NULL && (!flag)){

		estado = 0;


		do{
					menu(&opcion,"Menu De Ordenamiento"
									,"\n¿Como Quiere Ordenar la lista de Pasajeros?"
									 "\n\n[1].Por id "
									 "\n[2].Por nombre"
									 "\n[3].por apellido "
									 "\n[4].por precio"
									 "\n[5].Volver al menu Principal ", 1, 5);

					if(opcion != 5){
					  menu(&flag, "De que manera desea ordenar  ",
							  "\n[0].Decendente\n"
							  "[1].Acendente", 0, 1);
					}

				switch(opcion)
				{

					case 1:
						ll_sort(pArrayListPassenger,PassengerCompareById,flag);
						break;

					case 2:
						ll_sort(pArrayListPassenger,PassengerCompareByName,flag);
						break;

					case 3:
						ll_sort(pArrayListPassenger,PassengerCompareByLastName,flag);
						break;

					case 4:
						ll_sort(pArrayListPassenger,PassengerCompareByPrecio, flag);
						break;
				}

				if(opcion != 5){

					controller_ListPassenger(pArrayListPassenger);
				}

			}while(opcion != 5);

	}

	return estado;
}


int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pArchivo;
	int estado;
	int len;
	Passenger* unPasajero = NULL;
	int id;
	char nombre[MAX_NOMBRE];
	char apellido[MAX_NOMBRE];
	float precio;
	char tipoPasajero[MAX_TIPO_DE_PASAJERO];
	char statusFlight[MAX_TIPO_DE_PASAJERO];
	char codigoVuelo[MAX_CODIGO_DE_VUELO];

	estado = -2;

	if(pArrayListPassenger != NULL && path != NULL && (!ll_isEmpty(pArrayListPassenger))){

		pArchivo = fopen(path,"w+");
		estado = -1;

		if(pArchivo != NULL){

			len = ll_len(pArrayListPassenger);
			fprintf(pArchivo,"id,name,lastname,price,flycode,typePassenger,statusFlight");

				for(int i=0;i<len;i++){

					unPasajero = (Passenger*) ll_get(pArrayListPassenger, i);

					if(unPasajero != NULL && (!Passenger_Verificar_Gets(unPasajero,&id,
							nombre ,apellido,&precio,codigoVuelo,statusFlight,tipoPasajero))){

						fprintf(pArchivo,"%d,%s,%s,%2.2f,%s,%s,%s\n",id,nombre,
																							apellido,
																							precio,
																							codigoVuelo,
																							tipoPasajero,
																							statusFlight);
					}
				}

				estado = 0;
				fclose(pArchivo);
		}

	}


    return estado;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	    FILE* pFileBinary;
		int estado;
		int len;
		Passenger* unPasajero = NULL;
		int id;
		char nombre[MAX_NOMBRE];
		char apellido[MAX_NOMBRE];
		float precio;
		char tipoPasajero[MAX_TIPO_DE_PASAJERO];
		char statusFlight[MAX_TIPO_DE_PASAJERO];
		char codigoVuelo[MAX_CODIGO_DE_VUELO];

		estado = -2;

		if(pArrayListPassenger != NULL && path != NULL && ll_isEmpty(pArrayListPassenger) == 0){

		pFileBinary = fopen(path,"w+b");

		estado = -1;

			if(pFileBinary != NULL){

				len = ll_len(pArrayListPassenger);

				for(int i=0;i<len;i++){

					unPasajero = (Passenger*) ll_get(pArrayListPassenger, i);

					if(unPasajero != NULL && (!Passenger_Verificar_Gets(unPasajero,&id,nombre ,
							apellido,&precio,codigoVuelo
							,statusFlight,tipoPasajero))){

						fwrite((unPasajero+i),sizeof(Passenger),1,pFileBinary);

					}
				}
				estado = 0;
				fclose(pFileBinary);
			}
		}

    return estado;
}

