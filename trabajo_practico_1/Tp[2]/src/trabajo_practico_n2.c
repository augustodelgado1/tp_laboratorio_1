#include "ArrayPassenger.h"

#define MAX_PASSANGERS 2000
#define MAX_STATUS 4
#define MAX_TYPE 3

int main(void) {
	setbuf(stdout,NULL);

	Passenger listaDePasajeros[MAX_PASSANGERS];
	StatusFlight auxiliarStatus[MAX_STATUS]  = {{1,"Activo"},{2,"Cancelado"},{3,"Demorado"},{4,"En Horario"}};
	TypePassenger auxiliarDeType[MAX_TYPE] = {{1, "Primera Clase"} , {2, "Economico"} , {3, "Premium"}};
	int opcion;
	int id;
	int index;
	int bandera;

	initPassengers(listaDePasajeros, MAX_PASSANGERS);
	bandera = 0;

	    do{
	    			                      menu(&opcion,"Menu Principal",
	    					    		              "\n1.ingresar datos\n"
	    					    		              "2.Modificar\n"
	    					    		              "3.Dar de baja un Pasajero\n"
	    					    		              "4.Informar\n"
	    					    		              "5.carga Forzada\n"
	    					    		              "6.Salir\n",1,6);

	    		    switch(opcion){
	    		    case 1:

	    		    switch(AltaDePasajero(listaDePasajeros,MAX_PASSANGERS,auxiliarDeType,MAX_TYPE,auxiliarStatus,MAX_STATUS)){
	    	        	case -2:
	    	        		printf("\nNo hay mas espacio\n\n");
	    	        		break;
	    	        	case 0:
	    	        		printf("\nSe Cargo con exito.\n\n");
	    	        		break;
	    	        	default:
	    	        	    printf("\nNo se pudo realizar el Alta\n\n");
	    	        	    break;
	    	        	}
	    		        	break;

	    		        case 2:

	    		        	switch(Modify(listaDePasajeros,MAX_PASSANGERS,auxiliarDeType,MAX_TYPE,auxiliarStatus,MAX_STATUS))
	    		        	    {
	    	        	       case -1:
	    	        	       printf("\nNo se pudo realizar la modificacion.\n\n");
	    	        	          break;
	    	        	       case 0:
	    	        	    		printf("\nSe Cancelo la modificacion.\n\n");
	    	        	    		break;
	    	        	       case 1:
	    	        	    	    printf("\nModificacion exitosa.\n\n");
	    	        	    	    break;

	    	        	    	default:
	    	        	    	printf("\nDebe cargar Un pasajero.\n\n");
	    	        	    		break;
	    		        	    }

	    		        	break;

	    		        case 3:

	    		        if(MostrarPassenger(listaDePasajeros,MAX_PASSANGERS,auxiliarDeType,MAX_TYPE,auxiliarStatus,MAX_STATUS) == 1){

	    		        	GetNumero(&id,"\ningrese el id que desea eliminar ","\nError Ingrese id que desea eliminar ",1,2000,2);
	    		        	index = findPassengerById(listaDePasajeros, MAX_PASSANGERS, id);

	        		        switch(removePassenger(listaDePasajeros,MAX_PASSANGERS,index))
	        		        	    {
	    		        	       case -1:
	    		        	       printf("\nNo se pudo realizar la baja\n\n");
	    		        	          break;

	    		        	       case 0:
	    		        	    	printf("\nSe Cancelo la baja.\n\n");
	    		        	    	  break;

	    		        	    	case 1:
	    		        	    	printf("\nbaja exitosa.\n\n");
	    		        	    	  break;
	        		        	   }

	    		        }else{
	    		            printf("\nDebe cargar Un pasajero.\n\n");
	    		        }

	    		        break;

	    		        case 4:

	        		        if(Passengers_Status(listaDePasajeros,MAX_PASSANGERS) != -1){

	        		        SubMenu(listaDePasajeros,MAX_PASSANGERS,auxiliarDeType,MAX_TYPE,auxiliarStatus,MAX_STATUS,opcion);

	        		        }else{
	        		            printf("\n\nDebe cargar Un pasajero.\n\n");
	        		        }

	    		        break;

	    		        case 5:
	        		        if(bandera == 0 && CargaForzada(listaDePasajeros,MAX_PASSANGERS) == 0){

	        		            printf("Se pudo realizar la Carga Forzada\n");
	        		            bandera = 1;
	        		        }else{
	        		            printf("No se pudo realizar la Carga Forzada\n");
	        		        }
	    		        break;

	    		       case 6:
	    			   printf("\nSaliendo..........\n");
	    			   break;

	    		    }

	    		    }while(opcion != 6);

	    	return EXIT_SUCCESS;
}


