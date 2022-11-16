#include "Menu.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Nexo.h"


int main()
{
	setbuf(stdout,NULL);
	LinkedList* listaJugadores = ll_newLinkedList();
	LinkedList* listaAuxiliar = ll_newLinkedList();
	LinkedList* listaDeJugadoresFilrada = ll_newLinkedList();
	LinkedList* listaDeSelecciones = ll_newLinkedList();
	Jugador* unJugador = NULL;
    int banderaBinaria;
    int bandera;
    int id;
    int cantidadJugadoresConvocados;
    int cantidadDeConvocadosGuardados;
    int retorno;
    int opcion;
    int indexDeJugador;
    int cantidadJugadores;
    int cantidadDeJugadoresGuardados;
    char respuesta;
    char confederacion[MAX_CONFEDERACION];

    id = controller_BuscarIdMaximo("jugadores.csv");
   	controller_GuardarUltimoId("Id_Jugadores_Maximo.txt", id);
   	banderaBinaria = 0;
   	bandera = 0;
   	cantidadDeJugadoresGuardados = 0;
   	cantidadDeConvocadosGuardados = 0;

    if(listaJugadores != NULL && listaDeSelecciones != NULL)
    {

		do{
																			menu("Menu Principal",
																				  "\n[1].Cargar  Archivos CSV"
																				  "\n[2].Alta de Jugador\n"
																				  "[3].Modificar Jugador\n"
																				  "[4].Baja de Jugador\n"
																				  "[5].Listados\n"
																				  "[6].Convocar jugadores\n"
																				  "[7].Ordenamientos\n"
																				  "[8].Generar un archivo binario\n"
																				  "[9].Cargar Archivo binario\n"
																				  "[10].Guardar Archivos CSV\n"
																				  "[11].Salir");

		   retorno = GetNumero(&opcion, "Ingrese una opcion: ","Ingrese Una opcion valida: ",1, 11, 2);
		   controller_CantidadJugadoresConvocadosPorSeleccion(listaDeSelecciones, listaJugadores);
		   cantidadJugadoresConvocados = controller_CantidadDeJugadoresConvocados(listaJugadores, listaDeSelecciones);
		   cantidadJugadores = ll_len(listaJugadores);

		   if(retorno != ERROR)
		   {
				switch(opcion)
				{
				  case 1:

						if(bandera == 0 && controller_cargarJugadoresDesdeTexto( "jugadores.csv", listaJugadores) != ERROR  &&
						controller_cargarSeleccionesDesdeTexto("selecciones.csv", listaDeSelecciones) != ERROR)
						{
							bandera = 1;
							cantidadDeJugadoresGuardados = ll_len(listaJugadores);
							cantidadDeConvocadosGuardados = controller_CantidadDeJugadoresConvocados(listaJugadores, listaDeSelecciones);
							printf("Los archivos se cargaron correctamente");
						}else{
							printf("Se produjo un error al intentar cargar los archivos");
						}

						break;

					case 2:

						if(controller_agregarJugador(listaJugadores) == OK)
						{
							printf("\nSe agreago un jugador a la lista con exitoo!!!");
						}else{
							printf("\nSe produjo un error al intentar realizar el Alta");
						}

						break;

					case 3:
						if(controller_MostrarListaDeJugadores(listaJugadores, listaDeSelecciones) == OK)
						{
							indexDeJugador = controller_editarJugador(listaJugadores);
							switch(indexDeJugador)
							{
							case -2:
								printf("No se realizaron cambios");
								break;
							case -1:
								printf("Se produjo un error al intentar realizar la modificacion");
								break;
							default:
								ImprimirCabecera("\t\t\t\t\t-- Jugador Actualizado -- \n","ID   | Nombre 	                  | Edad       | Posicion             | Nacionalidad   		  | Seleccion \n","=", "-", 130);
								if((unJugador = (Jugador*) ll_get(listaJugadores, indexDeJugador)) != NULL &&
								controller_MostrarSeleccionDeJugador(unJugador,listaDeSelecciones) == ERROR)
								{
									jug_MostrarUnJugador(unJugador);
								}
								break;
							}
						}else{
							printf("Debe Cargar al menos un jugador para poder acceder al Menu de Modificaciones");
						}


						break;

					case 4:
						if(controller_MostrarListaDeJugadores(listaJugadores, listaDeSelecciones) == OK
						&& (listaAuxiliar = ll_clone(listaJugadores)) != NULL)
						{
							indexDeJugador = controller_removerJugador(listaAuxiliar);
							switch(indexDeJugador)
							{
							case -2:
								printf("Se cancelo la baja\n");
								break;
							case -1:
								printf("No se pudo realizar la baja\n");
								break;
							default:
								ImprimirCabecera("\n\n\t\t\t\t\t-- Jugador Borrado -- \n","ID   | Nombre 	                  | Edad       | Posicion             | Nacionalidad   		  | Seleccion \n","=", "-", 130);
								if((unJugador = (Jugador*) ll_pop(listaJugadores, indexDeJugador)) != NULL &&
								controller_MostrarSeleccionDeJugador(unJugador,listaDeSelecciones) == ERROR)
								{
									jug_MostrarUnJugador(unJugador);
								}
								break;
							}
							ll_clear(listaAuxiliar);
						}else{
							printf("Debe Ingresar al menos un jugador para podera acceder a la baja");
						}

							break;

					case 5:
							if((retorno = ll_isEmpty(listaJugadores)) == 0 && (retorno = ll_isEmpty(listaDeSelecciones)) == 0
							&& controller_MenuDeListados(listaJugadores, listaDeSelecciones) == ERROR)
							{
								printf("Error -- Se produjo un error en el menu de listados -- Error");
							}
							break;

					case 6:
							if((retorno = ll_isEmpty(listaJugadores)) == 0 && (retorno = ll_isEmpty(listaDeSelecciones)) == 0
								&& controller_MenuDeConvocarJugador(listaDeSelecciones,listaJugadores ) == ERROR)
							{
								printf("Error -- Se produjo un error en el menu de convocados -- Error");
							}
							break;

					case 7:
							if((retorno = ll_isEmpty(listaJugadores)) == 0 && (retorno = ll_isEmpty(listaDeSelecciones)) == 0
							&& controller_ordenarListas(listaJugadores,listaDeSelecciones) == ERROR )
							{
								printf("Error -- Se produjo un error en el menu de ordenamiento -- Error");
							}
							break;

					case 8:
						if(ll_isEmpty(listaJugadores) == 0 && ll_isEmpty(listaDeSelecciones) == 0
				        && selec_PedirConfederacion(confederacion,MAX_CONFEDERACION) != ERROR
						&& (listaDeJugadoresFilrada = controller_FiltraListaDeJugadores(listaJugadores, listaDeSelecciones,confederacion)) != NULL
						&& ll_isEmpty(listaDeJugadoresFilrada) == 0)
						{
							if(controller_guardarJugadoresModoBinario("jugadores.bn", listaDeJugadoresFilrada) != ERROR
							&&  ll_clear(listaDeJugadoresFilrada) != ERROR)
							{
								banderaBinaria = 1;
								printf("El archivo  binario se guardo correctamente");
							}else{
								printf("Error -- Se produjo un error al intentar crear el arhivo binario -- Error");
							}
						}else{
							printf("Debe convocar al menos un jugador de esa confederacion ingresada para poder guardar los archivos en binarios\n");
						}

						break;

					case 9:

						if(banderaBinaria == 1 )
						{
							if(controller_cargarJugadoresDesdeBinario("jugadores.bn", listaDeJugadoresFilrada) == ERROR
							|| controller_MostrarListaDeJugadores(listaDeJugadoresFilrada, listaDeSelecciones) == ERROR
							|| ll_clear(listaDeJugadoresFilrada) == ERROR)
							{
								printf("Se produjo un error al intentar cargar el arhivo binario");
							}
						}else{
							printf("Debe Cargar el achivo binario para Imprimirlo (OPCION 8)");
						}
						 break;

					case 10:
						if((retorno = ll_isEmpty(listaJugadores)) == 0 && (retorno = ll_isEmpty(listaDeSelecciones)) == 0)
						{
							if(controller_guardarJugadoresModoTexto("jugadores.csv", listaJugadores) != ERROR
							&& controller_guardarSeleccionesModoTexto("selecciones.csv", listaDeSelecciones) != ERROR)
							{
								cantidadDeConvocadosGuardados = controller_CantidadDeJugadoresConvocados(listaJugadores, listaDeSelecciones);
								cantidadDeJugadoresGuardados = ll_len(listaJugadores);
								printf("Los cambios realizados se guradaron correctamente");
							}else{
								printf("Se produjo un error al intentar guradar los cambios realizados");
							}
						}
						  break;

					case 11:
							if(((cantidadJugadores != cantidadDeJugadoresGuardados || cantidadJugadoresConvocados != cantidadDeConvocadosGuardados) && ValidarChar(&respuesta,"¿Esta seguro que desea salir del programa sin guardar los cambios?  (s o n): ", "Ingrese una opcion valida (s o n): ", 's', 'n', 2) == ERROR)
							|| (cantidadJugadores == cantidadDeJugadoresGuardados && cantidadJugadoresConvocados == cantidadDeConvocadosGuardados && ValidarChar(&respuesta,"¿Esta seguro que desea salir del programa?  (s o n): ", "Ingrese una opcion valida (s o n): ", 's', 'n', 2) == ERROR))
							{
								printf("\n\n\t\t\tError -- No se ingreso una opcion valida -- Error");
							}
							break;
				}

				if(retorno == 1)
				 {
					 printf("Debe Cargar al menos un jugador y una seleccion para poder acceder a esta opcion");
				 }
		   }
		}while(respuesta != 's' && retorno != ERROR);

		 ll_clear(listaJugadores);
		 ll_deleteLinkedList(listaDeJugadoresFilrada);
		 ll_deleteLinkedList(listaAuxiliar);
		 ll_deleteLinkedList(listaJugadores);
		 ll_clear(listaDeSelecciones);
		 ll_deleteLinkedList(listaDeSelecciones);
    }



    return 0;
}
