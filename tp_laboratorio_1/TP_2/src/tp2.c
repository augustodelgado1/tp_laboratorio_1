

#include "Nexo.h"

int main(void) {
	setbuf(stdout,NULL);

	 eJugador listaDeJugadores[MAX_JUGADORES];
	 eConfederacion listaDeConfederaciones[MAX_CONFEDERACIONES];
	 eAuxiliar arrayAuxiliar[MAX_AUXILIAR];
	 int opcion;
	 int retorno;
	char respuesta;
	int bandera;

	bandera = 0;

	if(InicializarListaDeJugadores(listaDeJugadores, MAX_JUGADORES)  != 	ERROR
	&& InicializarListaDeConfederaciones(listaDeConfederaciones,MAX_CONFEDERACIONES) != ERROR)
	{
		do{
																 menu("Menu Principal",
																	  "\n[1].Alta de Jugador\n"
																	  "[2].Dar De baja un jugador\n"
																	  "[3].Modificar Jugador\n"
																	  "[4].Informes\n"
																	  "[5].Carga forzada\n"
																	  "[6].Menu de Confederaciones\n"
																	  "[7].Salir");

				   retorno = GetNumero(&opcion, "Ingrese una opcion: ","Ingrese Una opcion valida: ",1, 7, 2);

				   if(retorno != ERROR)
					{
						switch(opcion)
						{
							case 1:
								if(CantidadDeConfederacionesCargadas(listaDeConfederaciones,MAX_CONFEDERACIONES) > 0
								&& CantidadDeJugadoresCargados(listaDeJugadores, MAX_JUGADORES) <= MAX_JUGADORES)
								{
									switch(AltaDeJugador(listaDeJugadores, MAX_JUGADORES,listaDeConfederaciones,MAX_CONFEDERACIONES)){
										case -2:
											printf("\n\nNo hay mas espacio");
											break;
										case 1:
											printf("\n\nSe Cargo con exito");
											break;
										default:
											printf("\n\nNo se pudo realizar el Alta");
											break;
										}
								}else{
									printf("No hay confederaciones cargadas");
								}

								break;

							case 2:

								if(OrdenarListaDeJugadoresPorId(listaDeJugadores, MAX_JUGADORES) != ERROR
								&& MostrarListaDeJugadores(listaDeJugadores, MAX_JUGADORES,listaDeConfederaciones,MAX_CONFEDERACIONES) != ERROR)
								{
									switch(BajaDeJugador(listaDeJugadores, MAX_JUGADORES,listaDeConfederaciones,MAX_CONFEDERACIONES))
									{
										case 0:
											printf("\nSe Cancelo la modificacion");
											break;

										case 1:
											printf("\nBaja exitosa");
											break;

										default:
											printf("\nNo se pudo realizar la baja");
											break;
									}

								}else{
									printf("Debe cargar al menos un jugador para dar de baja");
								}

								break;

							case 3:

								if(OrdenarListaDeJugadoresPorId(listaDeJugadores, MAX_JUGADORES) != ERROR
								&& MostrarListaDeJugadores(listaDeJugadores, MAX_JUGADORES,listaDeConfederaciones,MAX_CONFEDERACIONES) != ERROR)
								{
									switch(ModificarUnJugador(listaDeJugadores, MAX_JUGADORES,listaDeConfederaciones,MAX_CONFEDERACIONES)){
											case 0:
												printf("\nSe Cancelo la modificacion");
												break;

											case 1:
												printf("\nModificacion exitosa");
											  break;

											default:
											printf("\nNo se pudo realizar la modificacion");
												break;
											}

								}else{
									 printf("Debe cargar al menos un jugador para realizar modificacion ");
								}

								break;

							case 4:

								if(CantidadDeJugadoresCargados(listaDeJugadores, MAX_JUGADORES) > 0
										&& CantidadDeConfederacionesCargadas(listaDeConfederaciones, MAX_CONFEDERACIONES) > 0)
								{
									if(SubMenuDeListados(listaDeJugadores, MAX_JUGADORES,listaDeConfederaciones,MAX_CONFEDERACIONES,arrayAuxiliar,MAX_AUXILIAR) == ERROR)
									{
										printf("\n\n\t\t\tError -- No se ingreso una opcion valida -- Error\n\n");
									}

								}else{
									printf("\nDebe cargar al menos un jugador para listar");
								}

								break;
							case 5:

								if(bandera == 0 && CargaForazada(listaDeJugadores,MAX_JUGADORES,listaDeConfederaciones,MAX_CONFEDERACIONES,6) != ERROR)
								{
									printf("Se realizo correctamente la carga forzada");
									bandera = 1;
								}else{
									printf("No se pudo realizar la carga forzada");
								}

								break;

							case 6:

								if(SubMenuDeConfederaciones(listaDeConfederaciones,MAX_CONFEDERACIONES) == ERROR)
								{
									printf("\n\n\t\t\tError -- No se ingreso una opcion valida -- Error");
								}

								break;

							case 7:

								if(ValidarChar(&respuesta,"¿Esta seguro que desea salir del programa? (s o n): ","Ingrese una opcion valida (s o n): ",'s' , 'n',2) == ERROR)
								{
									printf("\n\n\t\t\tError -- No se ingreso una opcion valida -- Error");
								}

								break;

						}
					}

				}while(respuesta != 's' && retorno != ERROR);
	}

	return EXIT_SUCCESS;
}
