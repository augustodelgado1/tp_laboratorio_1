
#include "Nexo.h"

int ObtenerIDJugador()
{
    static int idIncremental = 1;

    return idIncremental++;
}

int InicializarListaDeJugadores(eJugador listaDeJugadores[], int size)
{
	int estado;

	estado = ERROR;

	if(listaDeJugadores != NULL && size >= 0){

		for(int i=0;i<size;i++){
			listaDeJugadores[i].isEmpty = LIBRE;
		}

		estado = OK;
	}

	return estado;
}

int BuscarLibre(eJugador listaDeJugadores[],int size)
{
	int estado;

	estado = ERROR;

	if(listaDeJugadores != NULL && size >= 0)
	{
		for (int i=0;i<size;i++)
		{
			if(listaDeJugadores[i].isEmpty == LIBRE)
			{
				estado = i;
				break;
			}
		}
	}

	return estado;
}

int OrdenarListaDeJugadoresPorSalario(eJugador listaDeJugadores[],int sizeDeJugadores)
{
	    eJugador unJugador;
		int estado;

		estado = ERROR;

		if(listaDeJugadores != NULL && sizeDeJugadores >= 0)
		{
			for (int i = 0; i < sizeDeJugadores-1; i++) {
				for (int j = i+1; j < sizeDeJugadores; j++) {

					if(listaDeJugadores[i].isEmpty == OCUPADO && listaDeJugadores[i].salario < listaDeJugadores[j].salario)
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

int BuscarUnJugadorPorId(eJugador listaDeJugador[], int size,int id)
{
	int estado;

	 estado = ERROR;

	if(size > 0)
	{
		for (int i = 0;i<size;i++) {

    		if (listaDeJugador[i].isEmpty == OCUPADO && listaDeJugador[i].id == id) {
    			estado = i;
    			break;
    		}
    	}

	}

	return estado;
}

int CargarForzadaDeJugador(eJugador listaDeJugadores[],int sizeDeJugadores,int id,char nombre[],char posicion[],short numeroCamiseta,int idConfederacion,float salario,short aniosContrato)
{
	int indexDeJugador;
	int estado;
	estado = ERROR;
	indexDeJugador =  BuscarLibre(listaDeJugadores, sizeDeJugadores);

	if(indexDeJugador != ERROR && id >= 0 && nombre != NULL && posicion != NULL && numeroCamiseta > 0 && idConfederacion > 0 && salario >= 0 && aniosContrato >= 0)
	{
		listaDeJugadores[indexDeJugador].id = id;
		strcpy(listaDeJugadores[indexDeJugador].nombre,nombre);
		strcpy(listaDeJugadores[indexDeJugador].posicion,posicion);
		listaDeJugadores[indexDeJugador].numeroCamiseta = numeroCamiseta;
		listaDeJugadores[indexDeJugador].salario = salario;
		listaDeJugadores[indexDeJugador].idConfederacion = idConfederacion;
		listaDeJugadores[indexDeJugador].aniosContrato = aniosContrato;
		listaDeJugadores[indexDeJugador].isEmpty = OCUPADO;
		estado = OK;
	}

	return estado;
}

int OrdenarListaDeJugadoresPorId(eJugador listaDeJugador[],int size)
{
	eJugador unJugador;
	int estado;

	estado = ERROR;

	if(listaDeJugador != NULL && size >= 0)
	{
		for (int i = 0; i < size-1; i++) {
			for (int j = i+1; j < size; j++) {

				if(listaDeJugador[i].isEmpty == OCUPADO && listaDeJugador[i].id > listaDeJugador[j].id)
				{
						unJugador = listaDeJugador[i];
						listaDeJugador[i] = listaDeJugador[j];
						listaDeJugador[j] = unJugador;
				}
			}
		}

		estado = OK;
	}

	return estado;
}

int  MostrarListaDeJugadoresDeUnaConfederacion(eJugador listaDeJugadores[],int sizeDeJugadores,int idDeConfederacion)
{
	int estado;

	estado = ERROR;

	if(listaDeJugadores != NULL && sizeDeJugadores >= 0 && idDeConfederacion >= 0)
	{

		for (int i = 0; i < sizeDeJugadores; i++) {

			if(listaDeJugadores[i].isEmpty == OCUPADO && listaDeJugadores[i].idConfederacion == idDeConfederacion)
			{

				     printf("\t\t\t\t|%-25s | %-24s | %-14d | %-25.2f | %10d",listaDeJugadores[i].nombre,
																													listaDeJugadores[i].posicion,
																													listaDeJugadores[i].numeroCamiseta,
																													listaDeJugadores[i].salario,
																													listaDeJugadores[i].aniosContrato);
				 printf("\n\t\t\t\t--------------------------------------------------------------------------------------------------------------\n\n");

			}

		}

	estado = OK;
   }

    return estado;

}

float CalcularTotalDeSalario(eJugador listaDeJugadores[],int sizeDeJugadores)
{
	float acumuladorDeSalario;

	acumuladorDeSalario = 0;

		for (int i = 0; i < sizeDeJugadores; i++) {

			if(listaDeJugadores[i].isEmpty == OCUPADO)
			{
				acumuladorDeSalario += listaDeJugadores[i].salario;
			}
		}

		return acumuladorDeSalario;
}

int ContarJugadoresDeUnaConfederacion(eJugador listaDeJugadores[],int sizeDeJugadores,int idDeConfederacion)
{
	int contador;

	contador = 0;

	if(listaDeJugadores != NULL && sizeDeJugadores >= 0 && idDeConfederacion >= 0)
	{
		for (int i = 0; i < sizeDeJugadores; i++) {

			if(listaDeJugadores[i].isEmpty == OCUPADO
			&& listaDeJugadores[i].idConfederacion == idDeConfederacion)
			{
			    contador++;
			}
		}

	}

    return contador;
}

int CantidadDeJugadoresCargados(eJugador listaDeJugadores[],int sizeDeJugadores)
{
	int contadorDeJugadores;

	contadorDeJugadores = ERROR;

	if(listaDeJugadores != NULL && sizeDeJugadores > 0)
	{
		contadorDeJugadores = 0;
		for (int i = 0; i < sizeDeJugadores; i++) {

				if(listaDeJugadores[i].isEmpty == OCUPADO)
				{
					contadorDeJugadores++;
				}
		}
	}

	return contadorDeJugadores;
}

int AcumularAniosContratoDeUnaConfederacion(eJugador listaDeJugadores[],int sizeDeJugadores,int idDeConfederacion)
{
	int acumulador;

	acumulador = 0;

	if(listaDeJugadores != NULL && sizeDeJugadores >= 0 && idDeConfederacion >= 0)
	{
		for (int i = 0; i < sizeDeJugadores; i++) {

			if(listaDeJugadores[i].isEmpty == OCUPADO
			&& listaDeJugadores[i].idConfederacion == idDeConfederacion)
			{
			    acumulador += listaDeJugadores[i].aniosContrato;
			}
		}

	}

    return acumulador;
}

int PedirPosicion(char posicion[],int size){

	int auxiliar;
	int estado;

	estado = ERROR;

	ImprimirCabecera("\n\n\tIngrese la posicion\n","1.Arquero"
															"\n2.Defensor"
															"\n3.Mediocampista"
															"\n4.Delantero\n","*", "*", 30);
	if(!GetNumero(&auxiliar, "Ingrese la posicion: ", "\nError ingrese una posicion Valida: ", 1,4, 2)){

		switch(auxiliar){
		case 1:
			strncpy(posicion,"Arquero",size);
			break;
		case 2:
			strncpy(posicion,"Defensor",size);
			break;
		case 3:
			strncpy(posicion,"Mediocampista",size);
			break;
		case 4:
		    strncpy(posicion,"Delantero",size);
		    break;
		}

		estado = OK;

	}

	return estado;

}





