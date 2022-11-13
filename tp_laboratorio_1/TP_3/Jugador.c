
#include "Jugador.h"
#include "Menu.h"


Jugador* jug_new()
{
	Jugador*  unJugador;

	unJugador = (Jugador*) malloc(sizeof(Jugador)*1);

	return unJugador;
}

void jug_delete(Jugador* unJugador)
{
	if(unJugador != NULL)
	{
		free(unJugador);
		unJugador = NULL;
	}
}

Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr)
{
	Jugador* unJugador = jug_new();


	if(unJugador == NULL || nombreCompletoStr == NULL || edadStr == NULL ||  posicionStr == NULL || nacionalidadStr  == NULL || idSelccionStr  == NULL||
	jug_SetUnJugador(unJugador, atoi(idStr),nombreCompletoStr,atoi(edadStr), posicionStr, nacionalidadStr, atoi(idSelccionStr)) == ERROR)
	{
		jug_delete(unJugador);
	}

	return unJugador;
}

int jug_SetUnJugador(Jugador* unJugador,int id,char* nombreCompleto,int edad, char* posicion, char* nacionalidad, int idSeleccion)
{
	int estado;
	estado = OK;

	if(jug_setId(unJugador, id) == ERROR || jug_setNombreCompleto(unJugador, nombreCompleto) == ERROR ||
			jug_setEdad(unJugador, edad) == ERROR || jug_setPosicion(unJugador, posicion) == ERROR
			|| jug_setNacionalidad(unJugador, nacionalidad) == ERROR ||  jug_setIdSeleccion(unJugador, idSeleccion)== ERROR)
		{
		  estado = ERROR;
		}

	return estado;
}

int jug_GetUnJugador(Jugador* unJugador,int *id,char* nombreCompleto,int* edad, char* posicion, char* nacionalidad, int *idSelccion)
{
	int estado;
	estado = OK;

	if(jug_getId(unJugador, id) == ERROR || jug_getNombreCompleto(unJugador, nombreCompleto) == ERROR ||
		jug_getEdad(unJugador, edad) == ERROR || jug_getPosicion(unJugador, posicion) == ERROR
		|| jug_getNacionalidad(unJugador, nacionalidad) == ERROR ||  jug_getSIdSeleccion(unJugador,idSelccion) == ERROR)
		{
		  estado = ERROR;
		}

	return estado;
}

int jug_setId(Jugador* this,int id)
{
	int estado;
	 estado = ERROR;
	   if(this != NULL && id >= 0)
	   {
	       this->id = id;
	       estado = OK;
	    }

	return estado;

}

int jug_getId(Jugador* this,int* id)
{
	int estado;
	estado = ERROR;

	   if(this != NULL && id != NULL)
	   {
	       *id =this->id;
	       estado = OK;
	    }

	return estado;
}

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int estado;
    estado = ERROR;


		   if(this != NULL && nombreCompleto  != NULL )
		   {
			   strcpy(this->nombreCompleto,nombreCompleto);
			   estado = OK;
		   }


		return estado;
}

int jug_getNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int estado;
	estado = ERROR;

	   if(this != NULL && nombreCompleto != NULL)
	   {
		   strncpy(nombreCompleto,this->nombreCompleto,MAX_NOMBRE);
		   estado = OK;
		}

		return estado;

}


int jug_setPosicion(Jugador* this,char* posicion)
{
	int estado;
   estado = ERROR;

	   if(this != NULL && posicion != NULL)
	   {
		   strncpy(this->posicion,posicion,MAX_POSICION);
		   estado = OK;
		}
			return estado;
}

int jug_getPosicion(Jugador* this,char* posicion)
{
	int estado;
	estado = ERROR;

	   if(this != NULL && posicion != NULL)
	   {
		   strncpy(posicion,this->posicion,MAX_POSICION);
		   estado = OK;
		}

		return estado;
}


int jug_setNacionalidad(Jugador* this,char* nacionalidad)
{
	int estado;
	estado = ERROR;

	   if(this != NULL && nacionalidad != NULL)
	   {
		   strncpy(this->nacionalidad,nacionalidad,MAX_NACIONALIDAD);
		   estado = OK;
		}

	return estado;
}

int jug_getNacionalidad(Jugador* this,char* nacionalidad)
{
	int estado;
	estado = ERROR;

	   if(this != NULL && nacionalidad != NULL)
	   {
		   strncpy(nacionalidad,this->nacionalidad,MAX_NACIONALIDAD);
		   estado = OK;
		}

		return estado;
}

int jug_setEdad(Jugador* this,int edad)
{
	int estado;
	estado = ERROR;

	   if(this != NULL && edad > 0)
	   {
		   this->edad = edad;
		   estado = OK;
		}

	   return estado;
}

int jug_getEdad(Jugador* this,int* edad)
{
	int estado;
	estado = ERROR;

	   if(this != NULL && edad > 0)
	   {
		   *edad = this->edad;
		   estado = OK;
		}

		   return estado;
}

int jug_setIdSeleccion(Jugador* this,int idSeleccion)
{
	int estado;
	estado = ERROR;

	   if(this != NULL && idSeleccion >= 0)
	   {
			this->idSeleccion = idSeleccion;
		   estado = OK;
		}

	   return estado;
}

int jug_getSIdSeleccion(Jugador* this,int* idSeleccion)
{
	int estado;
	estado = ERROR;

		   if(this != NULL && idSeleccion > 0)
		   {
			   *idSeleccion = this->idSeleccion;
			   estado = OK;
			}

		   return estado;
}

int jug_PedirUnJugador(Jugador* unJugador,int id)
{
		char nombreCompleto[MAX_NOMBRE];
		int edad;
		char posicion[MAX_POSICION];
		char nacionalidad[MAX_NACIONALIDAD];
		int estado;
		estado = ERROR;

		 if(unJugador != NULL && GetNombre("Ingrese el nombre del Jugador : ","Error Ingrese un nombre valido: ",nombreCompleto,MAX_NOMBRE) == 0
			&& GetNumero(&edad,"Ingrese la edad del jugador (16-50): " , "Error ingrese una de edad valida: ", 16, 50, 2) == 0
			&& jug_PedirPosicion(posicion,MAX_POSICION) != ERROR
			&& jug_PedirNacionalidad(nacionalidad,MAX_NACIONALIDAD) != ERROR
			&& jug_SetUnJugador(unJugador, id, nombreCompleto, edad, posicion, nacionalidad, LIBRE) != ERROR)
		 {
			 estado = OK;
		 }

		 return estado;
}

int jug_MostrarUnJugador(Jugador* this)
{
	int estado;
	int id;
	char nombreCompleto[MAX_NOMBRE];
	int edad;
	char posicion[MAX_POSICION];
	char nacionalidad[MAX_NACIONALIDAD];
	int idSeleccion;
	estado = ERROR;

	if(this != NULL && jug_GetUnJugador(this,&id, nombreCompleto,&edad, posicion, nacionalidad,&idSeleccion) != ERROR && idSeleccion == LIBRE)
	{
		printf("%-4d |  %-25s | %-10d | %-20s | %-25s | %-20s |\n",id,nombreCompleto,edad,posicion,nacionalidad,"No Convocado");
		MostrarUnMensajeRepetidasVeces("-", 130);
		printf("\n");
		estado = OK;
	}

	return estado;
}




int jug_CompararPorNombre(void* unPunteroVoid,void* otroPunteroVoid)
{
	int estado;
	Jugador* unJugador;
	Jugador* otroJugador;
	char nombreUnJugador[200];
	char nombreOtroJugador[200];

	unJugador = (Jugador*)  unPunteroVoid;
	otroJugador = (Jugador*)  otroPunteroVoid;

	if(unJugador != NULL && jug_getNombreCompleto(unJugador, nombreUnJugador) != ERROR && jug_getNombreCompleto(otroJugador, nombreOtroJugador) != ERROR )
	{
		estado = 0;

		if(strcmpi(nombreUnJugador,nombreOtroJugador) > 0)
		{
			estado = 1;
		}else{

			if(strcmpi(nombreUnJugador,nombreOtroJugador) < 0)
			{
				estado = -1;
			}
		}

	}

	return estado;
}

int jug_CompararPorEdad(void* unPunteroVoid,void* otroPunteroVoid)
{
	int estado;
	Jugador* unJugador;
	Jugador* otroJugador;
	int edadDeUnJugador;
	int edadDeOtroJugador;

	unJugador = (Jugador*)  unPunteroVoid;
	otroJugador = (Jugador*)  otroPunteroVoid;

	if(unJugador != NULL && jug_getEdad(unJugador,&edadDeUnJugador) != ERROR && jug_getEdad(otroJugador,&edadDeOtroJugador) != ERROR )
	{
		estado = 0;

		if(edadDeUnJugador > edadDeOtroJugador)
		{
			estado = 1;
		}else{

			if(edadDeUnJugador < edadDeOtroJugador)
			{
				estado = -1;
			}
		}

	}

	return estado;
}

int jug_CompararPorNacionalidad(void* unPunteroVoid,void* otroPunteroVoid)
{
	int estado;
	Jugador* unJugador;
	Jugador* otroJugador;
	char nacionalidadDeUnJugador[200];
	char nacionalidadDeOtroJugador[200];

	unJugador = (Jugador*)  unPunteroVoid;
	otroJugador = (Jugador*)  otroPunteroVoid;

	if(unJugador != NULL && jug_getNombreCompleto(unJugador, nacionalidadDeUnJugador) != ERROR && jug_getNombreCompleto(otroJugador, nacionalidadDeOtroJugador) != ERROR )
	{
		estado = 0;

		if(strcmpi(nacionalidadDeUnJugador,nacionalidadDeOtroJugador) > 0)
		{
			estado = 1;
		}else{

			if(strcmpi(nacionalidadDeUnJugador,nacionalidadDeOtroJugador) < 0)
			{
				estado = -1;
			}
		}
	}

	return estado;
}



 int  jug_PedirPosicion(char posicion[],int size){

	int auxiliar;
	int estado;

	estado = ERROR;

	ImprimirCabecera("\t\t-- Lista de posiciones --\n", "1,Portero\n"
																						"2,Defensa central\n"
																						"3,Mediocentro\n"
																						"4,Delantero centro\n"
																						"5.Pivote\n", "*", "*", 50);

		if(GetNumero(&auxiliar, "Ingrese el id de pocision: ", "\nError ingrese una posicion Valida: ", 1,5, 2) == 0){
			estado = OK;

			switch(auxiliar)
			{
			case 1:
				strcpy(posicion,"Portero");
				break;

			case 2:
				strcpy(posicion,"Defensa central");
				break;

			case 3:
				strcpy(posicion,"Mediocentro");
				break;

			case 4:
				strcpy(posicion,"Delantero centro");
				break;

			case 5:
				strcpy(posicion,"Pivote");
				break;
			}
		}

	return estado;

}


 int  jug_PedirNacionalidad(char nacionalidad[],int size){

	int auxiliar;
	int estado;

	estado = ERROR;

	ImprimirCabecera("\t\t -- Lista de nacionalidades --\n", "1,Argentino\n "
																								"2,Brasilero\n "
																								"3,Ururguayo\n"
																								"4,Qatari\n "
																								"5.Australiano\n", "*", "*", 50);

		if(GetNumero(&auxiliar, "Ingrese el id de pocision: ", "\nError ingrese una posicion Valida: ", 1,5, 2) == 0){
			estado = OK;

			switch(auxiliar)
			{
			case 1:
				strcpy(nacionalidad,"Argentino");
				break;

			case 2:
				strcpy(nacionalidad,"Brasilero");
				break;

			case 3:
				strcpy(nacionalidad,"Ururguayo");
				break;

			case 4:
				strcpy(nacionalidad,"Qatari");
				break;

			case 5:
				strcpy(nacionalidad,"Australiano");
				break;
			}
		}

	return estado;

}




