#include "Numericas.h"
#include "StatusFlight.h"
#include "TypePassenger.h"

int ObtenerId(){

   static int id = 0;

   id++;

  return id;

}

int initPassengers(Passenger *list, int len) {
	int retorno;

	retorno = -1;

	if(list != NULL && len >= 0){

		for(int i=0;i<len;i++){

			list[i].isEmpty = LIBRE;

		}

		retorno = 0;
	}

	return retorno;
}

int Passengers_SearchFree(Passenger listaDePasajeros[], int size) {
	 int index;
     index = -1;


    for(int i=0; i<size; i++)
	{
	    if(!listaDePasajeros[i].isEmpty){
	        index = i;

	        break;
	    }
	}

	return index;
}



int addPassenger(Passenger *list, int len, int id, char name[],
char lastName[],float price, int typePassenger, char flycode[],int statusFlight)
{
	int retorno;
	int index;
	Passenger unPasajero;

	index = Passengers_SearchFree(list,len);

	retorno = -1;

	if(list != NULL && len >= 0){

		unPasajero.id = id;
		strcpy(unPasajero.name,name);
		strcpy(unPasajero.lastName,lastName);
		unPasajero.price = price;
		unPasajero.idDeTypePassenger =  typePassenger;
		strcpy(unPasajero.flycode,flycode);
		unPasajero.idDeStausFlight =  statusFlight;
		unPasajero.isEmpty = OCUPADO;

		list[index] = unPasajero;

		}

		return retorno;
}

int findPassengerById(Passenger* list, int len,int id)
{
	int retorno;

	retorno = -1;

	if (list != NULL && len > 0 && id >= 0) {

		for (int i = 0; i < len; i++) {

		    if (list[i].isEmpty == OCUPADO && list[i].id == id) {
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int CargaForzada(Passenger *list, int len){

    int estado;
    Passenger listaDePasajeros[] = {{1,"Alejandro", "Lopez",2155,"A44" ,1,2,1},
	                                   {2,"Alexis", "Lopez",2911,"P44" ,1,2,1},
	                                   {3,"Gaston", "Perez",2582, "R44" ,1,2,1},
		                               {4,"Pablo", "Rosas",266, "B84" ,1,2,1},
		                               {5,"Emilio", "Duarte",266, "Z44" ,1,2,1},
		                               {6,"Maria", "Lopez",259, "N47" ,1,2,1}};

    estado = -1;

    if(list != NULL && len > 0){
        estado = 0;

        for (int i = 0; i < 6; i++) {
            addPassenger(list,len,listaDePasajeros[i].id,listaDePasajeros[i].name,listaDePasajeros[i].lastName,
            listaDePasajeros[i].price,listaDePasajeros[i].idDeTypePassenger,listaDePasajeros[i].flycode,listaDePasajeros[i].idDeStausFlight);
            ObtenerId();
        }

    }

    return estado;
}

void SubMenu(Passenger *list, int len,TypePassenger listType[],int sizeType,StatusFlight listStatus[],int sizeStatus,int opcion){
    int order;
    order = -1;
    do{
        menu(&opcion,"Menu listado",
    				  "\n1.Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero"
    				  "\n2.Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio"
    				  "\n3.Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’"
    				  "\n4.Volver al Menu Principal",0,4);

        switch(opcion)
        {
           case 1:

               if(!GetNumero(&order,"¿De que manera quiere ordenar?(0.Decendente/1.Acendente): ","Error solo (0.Decendente/1.Acendente): " ,0,1,2))
               {
                  sortPassengers(list,len,order);
               }else{
                printf("\nNo se Pudo Ordenar");
        	   }

              break;
           case 2:

        		CalculateTotalPassages(list,len);
        		break;

        	case 3:

        	 if(!GetNumero(&order,"¿De que manera quiere ordenar?(0.Decendente/1.Acendente): ","Error solo (0.Decendente/1.Acendente): " ,0,1,2))
        	 {
        	     sortPassengersFly(list,len,order);
        	 }else{
              printf("\nNo se Pudo Ordenar");
        	 }
        	   break;
        }

        if(opcion != 2 && order != -1){

            MostrarPassenger(list,len,listType,sizeType,listStatus,sizeStatus);

        }

    }while(opcion != 4);

}


int AltaDePasajero(Passenger list[], int len,TypePassenger listType[],int sizeType,StatusFlight listStatus[],int sizeStatus)
{
	int index;
	int estado;

	estado = -2;

	index = Passengers_SearchFree(list,len);

	if(index >= 0 && index<len){

		estado = -1;

	   if(!PedirUnPasajero(&list[index],&list[index].id,listType,sizeType,listStatus,sizeStatus))
	   {
	       list[index].id = ObtenerId();
	       estado = 0;
	   }

	}
	return estado;
}

int PedirUnPasajero(Passenger *listaDePasajero,int* id,TypePassenger listType[],int sizeType,StatusFlight listStatus[],int sizeStatus){
	Passenger unPasajero;
	int estado;
	int auxiliar;
	int indexType;
	int indexStatus;

	estado = -1;

	if(GetNombre("Ingrese el nombre (solo letras)  ","Error Ingrese el nombre (solo letras) ",unPasajero.name,MAX_NOMBRE) == 0
	   && GetNombre("Ingrese el apellido (solo letras) : ","Error Ingrese el apellido (solo letras): ",unPasajero.lastName,MAX_NOMBRE) == 0
	   && GetNumeroFlotante(&unPasajero.price,"ingrese el precio (mayor que 0): ","Error Ingrese el precio ",1,2) == 0
	   && GetAlphanumeic("ingrese el codigo Vuelo:  ","Error Ingrese un codigo Vuelo valido: ",unPasajero.flycode,10) == 0)
   {
       printListType(listType,sizeType);

       if(!GetNumero(&unPasajero.idDeTypePassenger,"ingrese tipo de pasajero ","Error Ingrese tipo de pasajero: ",1,sizeType,2)){

          indexType = BusquedarIdDetype(listType,sizeType,unPasajero.idDeTypePassenger);

          if(indexType != -1){
        	  unPasajero.idDeTypePassenger = indexType;
          }

          printlistStatus(listStatus,sizeStatus);

          if(!GetNumero(&unPasajero.idDeStausFlight,"\nIngrese tipo de pasajero ","\nError Ingrese tipo de pasajero: ",1,sizeStatus,2)){

            indexStatus = StatusPassengerId(listStatus,sizeStatus,unPasajero.idDeStausFlight);

				if(indexStatus != -1){

					 unPasajero.idDeStausFlight = indexStatus;
					 auxiliar = 1;
				}
            }
       }
   }

   if(auxiliar == 1)
    {

       unPasajero.id = *id;
       unPasajero.isEmpty = OCUPADO;
       *listaDePasajero = unPasajero;
       estado = 0;

    }

   return estado;
}

int Passengers_Status(Passenger array[], int size) {
	 int estado;
     estado = -1;

    for(int i=0; i<size; i++)
	{
	    if(array[i].isEmpty == 1){
	        estado = 1;
	        break;
	    }
	}

    return estado;
}

int Modify(Passenger list[], int len,TypePassenger listType[],int sizeType,StatusFlight listStatus[],int sizeStatus)
{
    Passenger auxiliarPasajero;
    int modifico;
    int opcion;
    char respuesta;
    int i = 0;
    int index;
    int indexType;
    int indexStatus;
    int id;

    modifico = -2;

    if(MostrarPassenger(list,len,listType,sizeType,listStatus,sizeStatus) != -1){

		modifico = -1;
		GetNumero(&id,"\ningrese el id que desea modificar ","Error Ingrese id que desea modificar ",1,2000,2);
		index = findPassengerById(list,len,id);

        if(index >= 0 && list[index].isEmpty == 1)
        {
            auxiliarPasajero = list[index];

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

    				if((!GetNombre("ingrese el nuvo nombre ","Error ingrese un nombre valido",auxiliarPasajero.name,MAX_NOMBRE)))
    				{
    					printf("\nSe Modifico el nombre");
    				}else{
    					printf("\nNo se pudo realizar Modificacion\n\n");
    				}

    				break;

    			case 2:

    				if((!GetNombre("ingrese el nuvo apellido ","Error ingrese un apellido valido",auxiliarPasajero.lastName,MAX_NOMBRE))){

    					printf("\nSe Modifico el apellido\n\n");
    				}else{
    					printf("\nNo se pudo realizar Modificacion\n\n");
    				}

    				break;

    			case 3:

    				if((!GetNumeroFlotante(&auxiliarPasajero.price, "ingrese el precio ", "Error Ingrese un precio valido ", 1,2))){

    					printf("\nSe Modifico el precio\n\n");
    				}else{
    					printf("\nNo se pudo realizar Modificacion\n\n");
    				}

    			break;

    			case 4:

        			printListType(listType,sizeType);

                    if(!GetNumero(&auxiliarPasajero.idDeTypePassenger,"ingrese tipo de pasajero ","Error Ingrese tipo de pasajero: ",1,sizeType,2)){

                      indexType = BusquedarIdDetype(listType,sizeType,auxiliarPasajero.idDeTypePassenger);
                      auxiliarPasajero.idDeTypePassenger = indexType;
                      printf("\nSe Modifico el tipo de pasajero\n\n");
                    }else{
                        printf("\nNo se pudo realizar Modificacion\n\n");
                    }

    			break;

    			case 5:

    			    printlistStatus(listStatus,sizeStatus);

                    if(!GetNumero(&auxiliarPasajero.idDeStausFlight,"Error ingrese el estado del vuelo: ","Error Ingrese estado de pasajero: ",1,sizeStatus,2)){

                        indexStatus = StatusPassengerId(listStatus,sizeStatus,auxiliarPasajero.idDeStausFlight);
                        auxiliarPasajero.idDeStausFlight = indexStatus;
                        printf("\nSe Modifico el estado del vuelo\n\n");
                    }else{
                        printf("\nNo se pudo realizar Modificacion\n\n");
                    }

    			break;

    			case 6:

        		    if((!GetAlphanumeic("ingrese el codigo Vuelo:  ","Error Ingrese un codigo Vuelo valido: ",auxiliarPasajero.flycode,10)))
        		    {
        		        printf("\nSe Modifico el codigo Vuelo\n\n");
        			}else{
        			    printf("\nNo se pudo realizar Modificacion\n\n");
        			}

    			break;

    			case 7:

    			if(!PedirUnPasajero(&auxiliarPasajero,&auxiliarPasajero.id,listType,sizeType,listStatus,sizeStatus))
            	   {
            	       printf("\nSe Modificaron todos los datos\n\n");
            	   }else{
            	      printf("\nNo se pudo realizar Modificacion\n\n");
            	   }

    			break;
            }

            i++;

            }while(opcion != 8);

                if(i > 1){
                	ImprimirCabecera("Pasajero Anterior","ID -- NOMBRE -- APELLIDO - PRECIO - TIPO DE VUELO - ESTADO DE VUELO - CODIGO DE VUELO ");
                    PassengerOnePrint(list[index]);
                    ImprimirCabecera("Pasajero Actualizado","ID -- NOMBRE -- APELLIDO - PRECIO - TIPO DE VUELO - ESTADO DE VUELO - CODIGO DE VUELO ");
                    PassengerOnePrint(auxiliarPasajero);

                    respuesta = PreguntarSoN("\n\nDesea guardar cambios? (s o n)" ,"Error solo (s o n)");
                }

    }

    if(respuesta == 's'){

    	list[index] = auxiliarPasajero;
        modifico = 1;

    }else{

        if(respuesta == 'n'){

            modifico = 0;

        }
    }

    }

    return modifico;
}




int removePassenger(Passenger *list, int len, int id){
	int retorno;
	int index;
	char respuesta;

	retorno = -2;

	if(list != NULL && len > 0 && id >= 0){

	    retorno = -1;

	    index = findPassengerById(list, len, id);

	    if(index >= 0 && list[index].isEmpty == 1){

	    	    ImprimirCabecera("Vas A Eliminar A Este Pasajero ","ID -- NOMBRE -- APELLIDO - PRECIO - TIPO DE VUELO - ESTADO DE VUELO - CODIGO DE VUELO");
        	    PassengerOnePrint(list[index]);

        	    respuesta = PreguntarSoN("\n¿Esta seguro que quiere eliminar el id? (s o n) " ,"Error solo (s o n)");

        	    if(respuesta == 's') {

    				list[index].isEmpty = LIBRE;
    				retorno = 1;

        	    }else{

        	        if(respuesta == 'n'){

        	           retorno = 0;
        	        }

        	    }
	    }
	}

	return retorno;

}

int printPassenger(Passenger* list, int length)
{
	int retorno;

	retorno = -1;

	if (Passengers_Status(list, length) != -1) {

    	if (list != NULL && length >= 0) {

    	    for (int i=0; i < length; i++) {

    			if (list[i].isEmpty) {

    				PassengerOnePrint(list[i]);
    				retorno = 0;

    			}
    		}
    	}
	}
	return retorno;
}

int CalculateTotalPassages(Passenger listaDePasajeros[], int size){
	float promedio;
	float totalDeLosPasajes;
	int cantidadDePasajeros;
	int cantidadDeMayor;
	int estado;

	cantidadDePasajeros = ContadorPasajeros(listaDePasajeros,size);

	totalDeLosPasajes = Suma(listaDePasajeros,size);

	promedio = CalcualarPromedio(totalDeLosPasajes,cantidadDePasajeros);

		estado = -1;

		if(promedio != 0 && totalDeLosPasajes != 0)
		{
			printf("El total de los pasajes es %.2f\n",totalDeLosPasajes);
			printf("El promedio de los pasajes es %.2f\n",promedio);
			cantidadDeMayor = BucarMayor(listaDePasajeros,size,promedio);
			printf("la cantidad De Pasajeros que superan el precio promedio son %d\n",cantidadDeMayor);
			estado = 1;
		}



	return estado;

}

void PassengerOnePrint(Passenger list){

    if(list.isEmpty == OCUPADO){

		printf("\n%-4d %10s %7s %.2f %10s %4d  %4d",list.id,
																				list.name,
																				list.lastName,
																				list.price,
																				list.flycode,
																				list.idDeTypePassenger,
																				list.idDeStausFlight);

		printf("\n-----------------------------------------------------------------------------------\n");

    }
}

int MostrarPassenger(Passenger list[],int size,TypePassenger listaDeTipos[],int sizeType,StatusFlight listaDeStatus[],int sizeDeStatus)
{
    int estado;
    int j;
    int k;

    estado = -1;

    if (Passengers_Status(list,size) != -1 && list != NULL && size >= 0) {

    ImprimirCabecera("Lista De Pasajeros","ID - NOMBRE - APELLIDO - PRECIO - TIPO DE VUELO - ESTADO DE VUELO - CODIGO DE VUELO ");
    estado = 1;

        for (int i = 0; i <size; i++) {

            if(list[i].isEmpty == 1){

                j = BusquedarIdDetype(listaDeTipos,sizeType,list[i].idDeTypePassenger);
                k = StatusPassengerId(listaDeStatus,sizeDeStatus,list[i].idDeStausFlight);

                if(j != -1 && k != -1){

                printf("\n%-4d %-10s %-4s %.2f %10s %10s %10s",list[i].id,
																							list[i].name,
																							list[i].lastName,
																							list[i].price,
																							listaDeTipos[j].descripcion,
																							listaDeStatus[k].descripcion,
																							list[i].flycode);
                printf("\n-----------------------------------------------------------------------------------\n");

                }
            }
        }
    }

    return estado;

}


int sortPassengers(Passenger* list, int len, int order)
{
    Passenger buffer;
	int flagSwap;
	int retorno;
	int auxiliar;

	    retorno = -1;

	    if(list != NULL && len > 0){


	        do{
	            flagSwap = 0;

	        for(int i = 0; i<len-1;i++){

	        	if(list[i].isEmpty == 1)
	        	{
					auxiliar = strcmp(list[i].lastName,list[i+1].lastName);

					if(((auxiliar > 0 || (!auxiliar && list[i].idDeTypePassenger > list[i+1].idDeTypePassenger)) && (order == 1))
						|| ((auxiliar < 0 || (!auxiliar && list[i].idDeTypePassenger < list[i+1].idDeTypePassenger)) && (!order)))
						{

						flagSwap = 1;
						buffer = list[i];
						list[i] = list[i+1];
						list[i+1] = buffer;
						}
	        	}

	        } //Fin del for

		} while (flagSwap);

	      retorno = 0;
	}

	return retorno;
}

int sortPassengersFly(Passenger* list, int len, int order){
    Passenger unPasajero;
    int auxiliar;
    int estado;

    estado = -1;

    if(list != NULL && len > 0 && (order == 1 || order == 0)){

        estado = 0;

        for (int i = 0; i < len-1; i++) {

            for (int j = i+1; j < len; j++) {

                auxiliar = strcmp(list[i].flycode,list[j].flycode);

                if(list[i].isEmpty)
                {
                    if((auxiliar < 0 || (auxiliar == 0 && list[i].idDeStausFlight < list[j].idDeStausFlight)) && (order == 1)){

                    unPasajero = list[i];
                    list[i] = list[j];
                    list[j] = unPasajero;

                    }else{

                        if((auxiliar > 0 || (auxiliar == 0 && list[i].idDeStausFlight > list[j].idDeStausFlight)) && (order == 0))
                        {

                           unPasajero = list[i];
                           list[i] = list[j];
                           list[j] = unPasajero;

                        }
                    }
                }
            }
        }
    }

    return estado;
}





