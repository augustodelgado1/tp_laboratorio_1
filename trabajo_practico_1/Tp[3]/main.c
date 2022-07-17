#include "Controller.h"
/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);
    int option;
    int flag = 0;
    char respuesta;
    int bandera;
    LinkedList* listaPasajeros = ll_newLinkedList();

    bandera = 0;

    do{
    	        menu(&option,"Menu Principal", "\n[1]. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)\n"
    	        		                                       "[2]. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario)\n"
    	        		                                       "[3]. Alta de pasajero\n"
    	        		                                       "[4]. Modificar datos de pasajero\n"
    	        		                                       "[5]. Baja de pasajero\n"
    	        		                                       "[6]. Listar pasajeros\n"
    	       		                                           "[7]. Ordenar pasajeros\n"
    	       		                                           "[8]. Guardar los datos de los pasajeros en el archivo data.csv (modo texto)\n"
    	       		                                           "[9]. Guardar los datos de los pasajeros en el archivo data.csv (modo binario)\n"
    	      		                                           "[10]. Salir", 1, 10);

    	 switch(option)
        {

        case 1:
        	if(!controller_loadFromText("data.csv", listaPasajeros)){

        		printf("Se Cargaron los datos Correctamente\n");

        	}else{

        		printf("No se pudo Cargar los datos\n");
        	}

        	break;
        case 2:

        	if(flag == 1){

				if((!controller_loadFromBinary("data.bin", listaPasajeros))){

					printf("Se Cargaron los datos Correctamente\n");

				}else{

					printf("No se pudo Cargar los datos\n");
				}

        }else{
        	printf("Debe Guardar los datos en binario para leerlos (OPCION 9)\n");
        }

        	break;
		case 3:

			if(bandera == 0){

				bandera = idMaximo("data.csv");
				controller_IdMaxFile("idmaximo.csv",bandera);
			}

			switch(controller_addPassenger(listaPasajeros)){
			case 0:
				printf("Alta exitosa!!!\n");
				flag = 0;
				break;
		   default:
				printf("No se pudo realizar el Alta\n");
				break;
			}



			break;
		case 4:

			switch(controller_editPassenger(listaPasajeros)){
				case -2:
					printf("\nNo se pudo realizar la modificacion.\n\n");
					break;
				case -1:
					printf("\nSe  cancelo la baja \n\n");
					break;
				case 0:
					printf("\nModificacion exitosa.\n\n");
					break;
				default:
					printf("Debe dar de alta un pasajero\n\n");
					break;
				}

			break;
		case 5:

			switch (controller_removePassenger(listaPasajeros)) {
			case -2:
				printf("\nNo se encontro el id\n");
				break;
			case -1:
				printf("\nNo se Pudo realizar la baja\n");
				break;
			case 0:
				printf("\nbaja exitosa.\n\n");
				break;
			default:
				printf("Debe dar de alta un pasajero\n\n");
				break;
			}


			break;

		case 6:

			if(controller_ListPassenger(listaPasajeros) == -1){

				printf("No hay elementos en la lista \n");
			}

			break;
		case 7:

			if(controller_sortPassenger(listaPasajeros) == -1){

				printf("Debe dar de alta un pasajero\n\n");
			}

			break;
		case 8:

			switch (controller_saveAsText("data.csv", listaPasajeros)) {
				case -1:
					printf("\nNo se Pudo abrir el archivo\n");
					break;
				case 0:
					printf("Se guardaron correctamente los datos");
					flag = 1;
					break;
				default:
					printf("No se registro datos ningun pasajero \n\n");
					break;
				}


			break;
		case 9:

			switch (controller_saveAsBinary("data.bin", listaPasajeros)) {
				case -1:
					printf("\nNo se Pudo abrir el archivo\n");
					break;
				case 0:
					printf("Se guardaron correctamente los datos");
					flag = 1;
					break;
				default:
					printf("No se registro  datos ningun pasajero\n\n");
					break;
				}

			break;

		case 10:
			if(flag != 1){

				respuesta = PreguntarSoN( "¿Esta seguro que quiere Salir del programa sin guardar los datos? (s o n) ","Error ingrese solo solo (s o n): ");
			}
			break;
        }

    }while(respuesta != 's');

    ll_deleteLinkedList(listaPasajeros);



    return EXIT_SUCCESS;
}
