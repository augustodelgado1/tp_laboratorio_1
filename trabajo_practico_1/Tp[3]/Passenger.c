
#include "Passenger.h"

Passenger* Passenger_new(){

	Passenger *unPasajero;

	unPasajero = (Passenger*) malloc(sizeof(Passenger)*1);

	return unPasajero;
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,
		char* tipoPasajeroStr,char*codigoVueloStr,char* statusFlight){

		Passenger *unPasajero = Passenger_new();

		PassengerNewWithParameters(unPasajero,atoi(idStr),nombreStr,apellidoStr,atof(precioStr),codigoVueloStr
		,statusFlight,tipoPasajeroStr);



		return unPasajero;

}

int PassengerNewWithParameters(Passenger*unPasajero,int id,char* nombre ,char* apellido,float precio,char* codigoVuelo
		,char* statusFlight,char* tipoPasajero){

	int estado;
	estado = -1;


	   if(Passenger_setId(unPasajero,id) == 0 &&
		Passenger_setNombre(unPasajero,nombre)  == 0 &&
		Passenger_setApellido(unPasajero,apellido)   == 0 &&
		Passenger_setPrecio(unPasajero,precio)  == 0  &&
		Passenger_setCodigoVuelo(unPasajero,codigoVuelo)  == 0 &&
		Passenger_setStatusFlight(unPasajero,statusFlight)  == 0 &&
		Passenger_setTipoPasajero(unPasajero, tipoPasajero) == 0)
		{
		   estado = 0;

		}else{

			Passenger_delete(unPasajero);

		}

	return estado;
}


int Passenger_Verificar_Gets(Passenger*unPasajero,int* id,char* nombre ,char* apellido,float* precio,char* codigoVuelo
		,char* statusFlight,char* tipoPasajero){

	int estado;
	estado = -1;

	  if(Passenger_getId(unPasajero,id) == 0 &&
		Passenger_getNombre(unPasajero,nombre) == 0 &&
		Passenger_getApellido(unPasajero,apellido) == 0 &&
		Passenger_getPrecio(unPasajero,precio) == 0 &&
		Passenger_getCodigoVuelo(unPasajero,codigoVuelo) == 0 &&
		Passenger_getStatusFlight(unPasajero,statusFlight) == 0 &&
		Passenger_getTipoPasajero(unPasajero, tipoPasajero) == 0)
		{
		  estado = 0;
		}else{
			Passenger_delete(unPasajero);
		}

	return estado;
}

int Passenger_setId(Passenger* this,int id){
	int estado;
	estado = -1;

	if(this != NULL && id > 0)
	{
		estado = 0;
		this->id = id;
	}

	return estado;
}

int Passenger_getId(Passenger* this,int* id){
	int estado;

	estado = -1;

	if(this != NULL && id != NULL){

		*id = this->id;
		  estado = 0;
	}

	return estado;
}

int Passenger_setNombre(Passenger* this,char* nombre){

	    int estado;
		estado = -1;

		if(this != NULL && nombre  != NULL )
		{
			estado = 0;

			strncpy(this->nombre,nombre,MAX_NOMBRE);

		}

	return estado;
}
int Passenger_getNombre(Passenger* this,char* nombre){

	int estado;
	estado = -1;

		if(this != NULL && nombre  != NULL)
		{
			estado = 0;
			strncpy(nombre,this->nombre,MAX_NOMBRE);
		}

		return estado;
}

int Passenger_setApellido(Passenger* this,char* apellido){
	 int estado;
	estado = -1;

	if(this != NULL && apellido  != NULL)
	{
		estado = 0;
		strncpy(this->apellido,apellido,MAX_NOMBRE);
	}

			return estado;
}

int Passenger_getApellido(Passenger* this,char* apellido){

	   int estado;
		estado = -1;

		if(this != NULL && apellido  != NULL)
		{
			estado = 0;
			strncpy(apellido,this->apellido,MAX_NOMBRE);
		}

				return estado;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo){

	   int estado;
	   estado = -1;

		if(this != NULL && codigoVuelo  != NULL)
		{
			estado = 0;
			strncpy(this->codigoVuelo,codigoVuelo,MAX_CODIGO_DE_VUELO);
		}

	return estado;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo){

	 int estado;
	 estado = -1;

		if(this != NULL && codigoVuelo  != NULL)
		{
			estado = 0;
			strncpy(codigoVuelo,this->codigoVuelo,MAX_CODIGO_DE_VUELO);
		}

		return estado;


}
int Passenger_setPrecio(Passenger* this,float precio){
	    int estado;
		estado = -1;

		if(this != NULL && precio  > 0)
		{
			estado = 0;
			this->precio = precio;
		}

		return estado;
}

int Passenger_getPrecio(Passenger* this,float* precio){
	int estado;
	estado = -1;

		if(this != NULL && precio  > 0)
		{
			estado = 0;
		   *precio = this->precio;
		}

		return estado;
}

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero){
	int estado;
	estado = -1;

		if(this != NULL && tipoPasajero  != NULL)
		{
			estado = 0;
			strncpy(this->tipoPasajero,tipoPasajero,MAX_TIPO_DE_PASAJERO);
		}

		return estado;
}



int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero){
	int estado;
	estado = -1;

		if(this != NULL && tipoPasajero  != NULL)
		{

		estado = 0;
		strncpy(tipoPasajero,this->tipoPasajero,MAX_CODIGO_DE_VUELO);

		}

		return estado;
}


int Passenger_setStatusFlight(Passenger* this,char* statusFlight){
	int estado;
	estado = -1;

		if(this != NULL && statusFlight  != NULL)
		{

		estado = 0;
		strncpy(this->statusFlight,statusFlight,MAX_TIPO_DE_PASAJERO);

		}

		return estado;
}

int Passenger_getStatusFlight(Passenger* this,char* statusFlight){
	int estado;
	estado = -1;

		if(this != NULL && statusFlight  != NULL)
		{

		estado = 0;
		strncpy(statusFlight,this->statusFlight,MAX_TIPO_DE_PASAJERO);

		}

		return estado;
}

int Passenger_PedirTipoVuelo(char* tipoVuelo,int size){

	int auxiliar;
	int estado;

	estado = -1;

	if(!GetNumero(&auxiliar, "\n1.First Class"
			                    "\n2.Executive Class"
			                     "\n3.EconomyClass"
			                      "\nIngrese Tipo de vuelo: ", "\nError ingrese un Tipo de vuelo Valido: ", 1, 3, 2)){

		switch(auxiliar){
		case 1:
			strncpy(tipoVuelo,"FirstClass",size);
			break;
		case 2:
			strncpy(tipoVuelo,"ExecutiveClass",size);
			break;
		case 3:
			strncpy(tipoVuelo,"EconomyClass",size);
			break;
		}

		estado = 0;

	}

	return estado;

}

int Passenger_PedirEstadoDeVuelo(char* estadoDeVuelo,int size){

	int auxiliar;
	int estado;

	estado = -1;

	if(!GetNumero(&auxiliar,"\n1.Aterrizado"
								"\n2.En Horario"
								"\n3.En Vuelo "
								"\n4.Demorado"
								"\nIngrese un Estado De Vuelo:  ", "\nError ingrese un Estado De Vuelo Valido: ", 1, 4, 2)){

		switch(auxiliar){
		case 1:
			strncpy(estadoDeVuelo,"Aterrizado",size);
			break;
		case 2:
			strncpy(estadoDeVuelo,"En Horario",size);
			break;
		case 3:
			strncpy(estadoDeVuelo,"En Vuelo",size);
			break;
		case 4:
			strncpy(estadoDeVuelo,"Demorado",size);
			break;
		}

		estado = 0;

	}

	return estado;

}

int PassengerCompareById(void* p1,void* p2){
	Passenger* unPasajero;
	Passenger* otroPasajero;
	int primerId;
	int segundoId;
	int comparo;
	comparo = 0;

	if(p1 != NULL && p2 != NULL ){

		unPasajero = (Passenger* ) p1;
		otroPasajero = (Passenger* ) p2;

		if((!Passenger_getId(unPasajero,&primerId)) && (!Passenger_getId(otroPasajero,&segundoId))){

			if(primerId > segundoId){

				comparo = 1;
			}else{

				if(primerId < segundoId){

				comparo = -1;


				}
		}
	}
}


	return comparo;
}


int PassengerCompareByName(void* p1,void* p2){
	Passenger* unPasajero;
	Passenger* otroPasajero;
	char nombre[MAX_NOMBRE];
	char otroNombre[MAX_NOMBRE];
	int comparo;

	if(p1 != NULL && p2 != NULL ){

	unPasajero = (Passenger* ) p1;
	otroPasajero = (Passenger* ) p2;

		if((!Passenger_getNombre(unPasajero, nombre)) && (!Passenger_getNombre(otroPasajero, otroNombre))){

			comparo = strncmp(nombre,otroNombre,MAX_NOMBRE);

			if(comparo > 0){

				comparo = 1;

			}else{

				if(comparo < 0){

					comparo = -1;
				}

			}
		}
	}

	return comparo;

}

int PassengerCompareByLastName(void* p1,void* p2){
	Passenger* unPasajero;
	Passenger* otroPasajero;
	char nombre[MAX_NOMBRE];
	char otroNombre[MAX_NOMBRE];
	int comparo = 0;

	if(p1 != NULL && p2 != NULL){

	unPasajero = (Passenger* ) p1;
	otroPasajero = (Passenger* ) p2;


	if((!Passenger_getNombre(unPasajero, nombre)) && (!Passenger_getNombre(otroPasajero, otroNombre))){

		comparo = strncmp(nombre,otroNombre,MAX_NOMBRE);

			if (comparo > 0) {

				comparo = 1;

			}else{

				if (comparo < 0){

					comparo = -1;
				}
			}
	    }
	}

	return comparo;
}

int PassengerCompareByPrecio(void* p1,void* p2){
	Passenger* unPasajero;
	Passenger* otroPasajero;
	float precio;
	float otroPrecio;
	int comparo = 0;

	if(p1 != NULL && p2 != NULL){

	unPasajero = (Passenger* ) p1;
	otroPasajero = (Passenger* ) p2;


		if((!Passenger_getPrecio(unPasajero,&precio)) && (!Passenger_getPrecio(otroPasajero,&otroPrecio))){

			if (precio > otroPrecio) {

					comparo = 1;

				}else{

					if (precio < otroPrecio){

						comparo = -1;
					}
				}
		 }
	}

	return comparo;
}

int Passenger_delete(Passenger* unPasajero){

	int estado;

	estado = -1;

	if(unPasajero != NULL){

		free(unPasajero);
		unPasajero = NULL;
		estado = 1;
	}

	return estado;
}


void PassengerPrintOne(Passenger* unPasajero){

	int id;
	char nombre[MAX_NOMBRE];
	char apellido[MAX_NOMBRE];
	float precio;
	char tipoPasajero[MAX_TIPO_DE_PASAJERO];
	char statusFlight[MAX_TIPO_DE_PASAJERO];
	char codigoVuelo[MAX_CODIGO_DE_VUELO];

	if((!Passenger_Verificar_Gets(unPasajero,&id,nombre ,apellido,&precio,codigoVuelo,statusFlight,tipoPasajero))){

    printf("%-4d %10s %5s %2.2f %-10s %-10s %-10s \n",
																		id,
																		nombre,
																		apellido,
																		precio,
																		codigoVuelo,
																		tipoPasajero,
																		statusFlight);
	printf("\n-----------------------------------------------------------------------------------\n");

	}


}
