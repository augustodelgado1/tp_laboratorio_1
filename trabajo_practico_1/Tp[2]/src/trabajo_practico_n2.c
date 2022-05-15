#include "ArrayPassenger.h"

#define MAX_PASSANGERS 2000

int main(void) {
	setbuf(stdout,NULL);

	Passenger listaDePasajeros[MAX_PASSANGERS];
	int opcion;
	int id;

	    initPassengers(listaDePasajeros, MAX_PASSANGERS);

	    InitThePassangerList(listaDePasajeros, MAX_PASSANGERS);

		do{
		    opcion = menu();

		    switch(opcion){
		        case 1:

		        if(GetPassenger(listaDePasajeros, MAX_PASSANGERS) == -1){
		            printf("\nNo hay mas pasajes disponibles\n\n");
		        }else{
		            printf("\nSe Cargo con exito!!\n\n");
		        }

		        	break;
		        case 2:

		        if(Passengers_Status(listaDePasajeros,MAX_PASSANGERS) != -1){

		        	switch(Modify(listaDePasajeros,MAX_PASSANGERS)){
		        	case 0:
		        		printf("\nSe Cancelo la modificacion.\n\n");
		        		break;
		        	case 1:
		        	    printf("\nModificacion exitosa.\n\n");
		        	    break;
		        	}
		        }

		        break;

		        case 3:

		              if(printPassenger(listaDePasajeros,MAX_PASSANGERS) != -1){

		             id = GetInt("Ingrese el id que quiere dar de baja ", " Error ingrese un id valido ",0,3000);

		             if(removePassenger(listaDePasajeros,MAX_PASSANGERS,id) == 1){
		        		printf("\nSe elimino con exito\n\n\n\n");

		             }else{
		                 printf("\nNo se pudo elimino el usuario\n\n\n");
		             }

		             }

		        break;

		        case 4:
		        if (Passengers_Status(listaDePasajeros,MAX_PASSANGERS) != -1) {

		        if(printPassenger(listaDePasajeros,MAX_PASSANGERS) != -1){

		        	sortPassengers(listaDePasajeros,MAX_PASSANGERS,1);
		        	CalculateTotalPassages(listaDePasajeros,MAX_PASSANGERS);
		        	//sortPassengersByCode(listaDePasajeros,MAX_PASSANGERS,1);
		        	printListFlycode(listaDePasajeros,MAX_PASSANGERS);
		        }

		        break;

		       case 5:
			   printf("Saliendo..........");
			   break;
		        }
		    }

		    }while(opcion != 5);

		return EXIT_SUCCESS;

}


