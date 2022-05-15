#include "Menu.h"

int menu(){
    int opcion;

    printf("                                               Menu de Opciones");
	printf("\n                                            -----------------------");
	printf("\n                                    ------------------------------------------");
	printf("\n                                      >>----->> 1.Cargar Datos");
	printf("\n                                      >>----->> 2.Modificar Datos");
	printf("\n                                      >>----->> 3.Eliminar un Pasajero");
	printf("\n                                      >>----->> 4.Informar");
	printf("\n                                      >>----->> 5.Salir");
	printf("\n                                    ----------------------------------------\n");
    opcion = GetInt("                                             Ingrese una opcion: " ,"Error ingrese una opcion valida" ,1, 5);

    return opcion;
}

int menuDeModificacion(){
    int opcion;

    printf("                                               Menu de Opciones");
	printf("\n                                            -----------------------");
	printf("\n                                    ------------------------------------------");
	printf("\n                                      >>----->> ¿Que Quiere Modificar?");
	printf("\n                                      >>----->> 1.Modificar el nombre");
	printf("\n                                      >>----->> 2.Modificar el apellido");
	printf("\n                                      >>----->> 3.Eliminar un Pasajero");
	printf("\n                                      >>----->> 4.Modificar el tipo de vuelo");
	printf("\n                                      >>----->> 5.Modificar el codigo de vuelo");
	printf("\n                                      >>----->> 6.Modificar el estado del vuelo");
	printf("\n                                      >>----->> 7.Volver al menu");
	printf("\n                                    ----------------------------------------\n");
    opcion = GetInt("                                             Ingrese una opcion: " ,"Error ingrese una opcion valida" ,1, 7);

    return opcion;
}

void ConvertidorDeMayusculas(char* cadena){


    for(int i = 0; cadena[i] != '\0';i++){

        if(cadena[i] == ' '){
            cadena[i+1] = toupper(cadena[i+1]);
            break;
        }

    }
}

void ImprimirResultados(char mensaje[]){
    printf("                         ***Listado de Pasajeros***   \n");
	printf("\n======================================================================================\n");
    printf("%s",mensaje);
	printf("\n======================================================================================\n");
}

/*
 * Augusto Delgado
 * Div B
 */

