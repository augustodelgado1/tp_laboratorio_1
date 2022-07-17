#include "LinkedList.h"
#include "Passenger.h"
#include "Parser.h"



int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	  char id[1000];
	  char nombre[1000];
	  char apellido[1000];
	  char precio[1000];
	  char tipoPasajero[1000];
	  char codigoVuelo[1000];
	  char statusFlight[1000];
	  int estado;
	  int falsaLectura;
	  int i;
	  Passenger* UnPasajero = NULL;

	  estado = -1;

	  if(pFile != NULL && pArrayListPassenger != NULL){

	falsaLectura = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
			  id,nombre,apellido,precio,tipoPasajero,codigoVuelo,statusFlight);

	i = 0;

	  do{

		  if(falsaLectura == 7 && fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
				  id,nombre,apellido,precio,codigoVuelo,tipoPasajero,statusFlight) == 7){

			  UnPasajero = Passenger_newParametros
			  (id, nombre, apellido, precio, tipoPasajero, codigoVuelo,statusFlight);

			  if(UnPasajero != NULL){

			  ll_add(pArrayListPassenger, UnPasajero);
			  estado = 0;
			  }

		  }else{

			Passenger_delete(UnPasajero);
			break;
		  }

		  i++;

		}while(i<10);
//!feof(pFile)
	  }

	  return estado;
}

int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int estado;
	Passenger* unPasajero = NULL;

	estado = -1;

	 if(pFile != NULL && pArrayListPassenger != NULL){

	do{

		unPasajero = Passenger_new();

		if (unPasajero != NULL && fread(unPasajero, sizeof(Passenger), 1, pFile) == 1)
			 {
				 ll_add(pArrayListPassenger, unPasajero);
				 estado = 0;
			 }else{
				 Passenger_delete(unPasajero);
				 break;
			 }
		 }while(!feof(pFile));
	 }



    return estado;
}
