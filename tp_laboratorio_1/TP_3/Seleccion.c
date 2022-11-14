#include "Seleccion.h"
#include "Jugador.h"
#include "Menu.h"

Seleccion* selec_new()
{
	Seleccion*  unaSeleccion;

	unaSeleccion = (Seleccion*) malloc(sizeof(Seleccion)*1);

	return unaSeleccion;
}

Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr)
{
	Seleccion*  unaSeleccion;
	int id;
	unaSeleccion = selec_new();

	if(idStr != NULL && paisStr != NULL && confederacionStr  != NULL &&   convocadosStr != NULL &&
	(id = atoi(idStr)) > 0 && selec_setConvocados(unaSeleccion, atoi(convocadosStr)) != ERROR)
	{
		unaSeleccion->id = id;
		strncpy(unaSeleccion->pais, paisStr,MAX_PAIS);
		strncpy(unaSeleccion->confederacion, confederacionStr,MAX_CONFEDERACION);

	}

	return unaSeleccion;
}

int selec_GetUnaSeleccion(Seleccion* unaSeleccion,int* id,char* pais,char* confederacion, int* convocados)
{
	int estado;
	estado = OK;

	if(selec_getId(unaSeleccion, id) == ERROR || selec_getPais(unaSeleccion, pais) == ERROR || selec_getConvocados(unaSeleccion, convocados) == ERROR
	|| selec_getConfederacion(unaSeleccion, confederacion) == ERROR)
	{
	  estado = ERROR;
	}

	return estado;
}

void selec_delete(Seleccion* this){

		if(this != NULL)
		{
			free(this);
			this = NULL;
		}
}

int selec_getId(Seleccion* this,int* id)
{
	 int estado;
	 estado = ERROR;

	   if(this != NULL && id  != NULL)
	   {
		   *id = this->id;
		   estado = OK;
	   }

	return estado;
}

int selec_getPais(Seleccion* this,char* pais)
{
	int estado;
	estado = ERROR;

	   if(this != NULL && pais != NULL)
	   {
		   strncpy(pais,this->pais,MAX_PAIS);
		   estado = OK;
		}
	   return estado;
}
int selec_getConfederacion(Seleccion* this,char* confederacion)
{
	 int estado;
    estado = ERROR;

		   if(this != NULL &&  confederacion != NULL)
		   {
			   strncpy(confederacion,this->confederacion,MAX_CONFEDERACION);
			   estado = OK;
		  }
		return estado;
}

int selec_setConvocados(Seleccion* this,int convocados)
{
	int estado;
    estado = ERROR;

    if(this != NULL && convocados >= 0)
    {
    	this->convocados = convocados;
    	estado = OK;
    }

	return estado;
}

int selec_getConvocados(Seleccion* this,int* convocados)
{
	int estado;
    estado = ERROR;

    if(this != NULL && convocados != NULL)
    {
    	*convocados = this->convocados;
    	estado = OK;
    }

	return estado;
}

int selec_MostrarUnaSeleccion(Seleccion* unaSeleccion)
{
	int id;
	char pais[MAX_PAIS];
	char confederacion[MAX_CONFEDERACION];
	int convocados;
	int estado;
	estado = ERROR;

	if(unaSeleccion != NULL && selec_GetUnaSeleccion(unaSeleccion,&id, pais, confederacion,&convocados) != ERROR)
	{
		printf("%-4d | %-20s | %-20s | %-18d |\n",id, pais, confederacion, convocados);
		MostrarUnMensajeRepetidasVeces("-", 73);
		printf("\n");
		estado = OK;
	}

	return estado;
}

int selec_CompararPorConfederacion(void* unaPunateroVoid,void* otraPunateroVoid)
{
	int estado;
	Seleccion* unaSeleccion;
	Seleccion* otraSeleccion;
	char confederacionDeUnaSeleccion[200];
	char confederacionDeOtraSeleccion[200];

	unaSeleccion = (Seleccion*)  unaPunateroVoid;
	otraSeleccion = (Seleccion*)  otraPunateroVoid;

	if(unaSeleccion != NULL && selec_getConfederacion(unaSeleccion, confederacionDeUnaSeleccion) != ERROR && selec_getConfederacion(otraSeleccion,confederacionDeOtraSeleccion) != ERROR )
	{
		estado = 0;

		if(strcmpi(confederacionDeOtraSeleccion,confederacionDeOtraSeleccion) > 0)
		{
			estado = 1;
		}else{

			if(strcmpi(confederacionDeOtraSeleccion,confederacionDeOtraSeleccion) < 0)
			{
				estado = -1;
			}
		}
	}

	return estado;
}

int selec_CompararPorId(void* unaPunateroVoid,void* otraPunateroVoid)
{
	int estado;
	Seleccion* unaSeleccion;
	Seleccion* otraSeleccion;
	int idDeSeleccion;
	int idDeOtraSeleccion;

	unaSeleccion = (Seleccion*)  unaPunateroVoid;
	otraSeleccion = (Seleccion*)  otraPunateroVoid;

	if(unaSeleccion != NULL && selec_getId(unaSeleccion,&idDeSeleccion) != ERROR && selec_getId(otraSeleccion,&idDeOtraSeleccion) != ERROR )
	{
		estado = 0;

		if(idDeSeleccion > idDeOtraSeleccion)
		{
			estado = 1;
		}else{

			if(idDeSeleccion < idDeOtraSeleccion)
			{
				estado = -1;
			}
		}
	}

	return estado;
}

int selec_PedirConfederacion(char confederacion[],int size){

	int auxiliar;
	int estado;
	estado = ERROR;

	ImprimirCabecera("\t\t -- Lista de confederaciones -- \n", "1,AFC\n"
																					"2,CAF\n"
																					"3,CONMEBOL\n"
																					"4,UEFA\n"
																					"5,CONCACAF\n", "*", "*", 50);

	if(GetNumero(&auxiliar, "Ingrese el id de nacionalidad: ", "\nError ingrese una posicion Valida: ", 1,5, 2) == 0){
		estado = OK;
		switch(auxiliar)
		{
		case 1:
			strcpy(confederacion,"AFC");
			break;

		case 2:
			strcpy(confederacion,"CAF");
			break;

		case 3:
			strcpy(confederacion,"CONMEBOL");
			break;

		case 4:
			strcpy(confederacion,"UEFA");
			break;

		case 5:
			strcpy(confederacion,"CONCACAF");
			break;
		}

	}

	return estado;
}
