#include "Numericas.h"
#define LIBRE 0
#define OCUPADO 1

void InitThePassangerList(Passenger array[],int size){

	 Passenger auxiliar[23] = {{1000,"Pablo Rozetti","Ferrand",100.50,"B11",2,1,OCUPADO},{1001,"Pedro Emilio","Aguilar",500.50,"S11",3,2,OCUPADO},
	    {1002,"Paula Marta","Lopez",500.50,"N51",1,1,OCUPADO},{1003,"Roberto Julio","Zopez",150.10,"N51",2,1,OCUPADO},{1004,"Laura Monica","Lopez",700.22,"N51",2,1,OCUPADO}};


    for(int i = 0;i<5;i++){
        array[i] = auxiliar[i];

    }
}

int initPassengers(Passenger *list, int len) {
	int retorno;

	retorno = -1;

	if(list != NULL && len >= 0){

		for(int i=0;i<len;i++){

			list[i].isEmpty = LIBRE;

		}

		retorno = 0;
	}

	return retorno;
}

int Passengers_SearchFree(Passenger listaDePasajeros[], int size) {
	 int index;
     index = -1;
     int id;

    id = 1000;

    for(int i=0; i<size; i++)
	{
	    if(!listaDePasajeros[i].isEmpty){
	        index = i;
	        listaDePasajeros[index].id = id+i;
	        break;
	    }
	}

	return index;
}

int GetPassenger(Passenger listaDePasajeros[], int size){

	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int retorno;

	id = 1000;

    GetSring("Ingrese un nombre ", "Error ingrese un nombre valido ",name, 51);
    strlwr(name);
    ConvertidorDeMayusculas(name);
	GetSring("Ingrese un Apellido ", "Error ingrese un nombre valido ",lastName, 51);

	strlwr(lastName);
	ConvertidorDeMayusculas(lastName);

	price = GetFloat("ingrese precio ", "Error ", 1);
	typePassenger = GetInt("\n1.Primera Clase\n2.Segunda Clase\n3.Tercera Clase\n\nIgrese el tipo de pasajero ","Error ingrese un tipo de pasajero valido  ", 1, 3);
	statusFlight = GetInt("\n1.Activo\n2.Demorado\n3.Desconocido\n4.Cancelado\n\nIgrese el tipo de pasajero ","Error ingrese un codigo valido: ", 1, 4);
	GetAlphanumeic("Igrese el codigo de vuelo (Alphanumerico) ","Error ingrese un codigo valido (Alphanumerico) ",flycode, 10);

	retorno = addPassenger(listaDePasajeros, size,id,name, lastName,price,typePassenger,flycode,statusFlight);

	return retorno;
}

int addPassenger(Passenger *list, int len, int id, char name[], char lastName[],float price, int typePassenger, char flycode[],int statusFlight)
{
	int retorno;
	int index;

	    index = Passengers_SearchFree(list,len);
		retorno = -1;

		if(list != NULL && len >= 0){

		    if(index != -1){
		    strcpy(list[index].name,name);

		    strcpy(list[index].lastName,lastName);
		    list[index].price = price;
		    list[index].typePassenger = typePassenger;
		    strcpy(list[index].flycode,flycode);

		    list[index].statusFlight = statusFlight;

		    list[index].isEmpty = OCUPADO;
		     retorno = 0;
			}

		}
		return retorno;
}

int Passengers_Status(Passenger array[], int size) {
	 int estado;
     estado = -1;

    for(int i=0; i<size; i++)
	{
	    if(array[i].isEmpty){
	        estado = 1;
	        break;
	    }
	}

    if(estado == -1){
        printf("\n\nSe deben ingresar datos para poder seleccionar esta opcion\n\n");
    }

	return estado;
}

int findPassengerById(Passenger* list, int len,int id)
{
	int retorno;

	retorno = -1;

	if (list != NULL && len >= 0 && id >= 0) {

		for (int i = 0; i < len; i++) {

		    if (list[i].isEmpty == OCUPADO && list[i].id == id) {
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int Modify(Passenger listaDePasajeros[], int size){

    int modifico;
    int index;
    Passenger auxiliar;
    int opcion;
    char respuesta;
    int i;
    int id;

    modifico = -1;
    i=0;

    printPassenger(listaDePasajeros,size);

    id = GetInt("Ingrese el id del usuario que quiere modificar ", " Error",10, 1000000);

    index = findPassengerById(listaDePasajeros,size,id);

    if(index == -1){
        printf("no existe una persona con el id: %d\n", id);

    }else{
        auxiliar = listaDePasajeros[index];

    do{
        opcion = menuDeModificacion();

        switch(opcion)
        {

        case 1:
        GetSring("Ingrese el nuevo nombre ", "Error ingrese un nombre valido",auxiliar.name, 51);
        break;

        case 2:
        GetSring("Ingrese el nuevo Apellido ", "Error ingrese un nombre valido",auxiliar.lastName, 51);
        break;

        case 3:
        auxiliar.price = GetFloat("ingrese el precio a Modificar ", "Error ingrese un precio valido ", 1);
        break;

        case 4:

        auxiliar.typePassenger = GetInt("\n1.Primera Clase\n2.Segunda Clase\n3.Tercera Clase\nIgrese el tipo de pasajero a Modificar  ","Error ingrese un codigo valido: ", 1, 10000);
        break;

        case 5:
        GetAlphanumeic("Igrese el codigo de vuelo a Modificar (Alphanumerico) ","Error ingrese un codigo valido (Alphanumerico): ", auxiliar.flycode, 10);
        break;

        case 6:
        auxiliar.statusFlight = GetInt("\n1.Activo\n2.Demorado\n3.Desconocido\n4.Cancelado\nIgrese un estado ","Error ingrese un Estado valido: ", 1, 10000);
        break;

        }

        i++;

    }while(opcion != 7);

    }

    if(i != 1 && opcion == 7){
    	respuesta = GetChar("\nDesea guardar cambios? (s o n) ", "Error solo (s o n) ", 's', 'n');

    }

    respuesta = tolower(respuesta);

    if(respuesta == 's'){
    	listaDePasajeros[index] = auxiliar;
        modifico = 1;
    }else{
        if(respuesta == 'n'){
        modifico = 0;
        }

    }

    return modifico;

}

int removePassenger(Passenger *list, int len, int id) {
	int retorno;
	int index;
	char respuesta;

	retorno = -1;

	if (list != NULL && len >= 0 && id >= 0) {

	index = findPassengerById(list, len, id);

		if (index == -1){
		    printf("no existe una persona con el id: %d\n", id);
		}else{

		    printf("Este es el usuario que va a dar de baja\n%d %s %s \t %.2f \t %d \t %s\n",
		    list[index].id , list[index].name ,list[index].lastName, list[index].price, list[index].typePassenger,list[index].flycode);

		   respuesta = GetChar("Esta seguro que quiere dar de baja este usuario(s o n)","Solo (s o n)", 's', 'n');

		if(respuesta == 's') {
				list[index].isEmpty = LIBRE;
				retorno = 0;

			}
		}

	}


	return retorno;

}

int printPassenger(Passenger* list, int length)
{
	int retorno;

	retorno = -1;

	if (Passengers_Status(list, length) != -1) {

	if (list != NULL && length >= 0) {
		ImprimirResultados(" id      Name       LastName    Price   FlyCode  TypePassenger   StatusFligth             ");

		for (int i=0; i < length; i++) {

			if (list[i].isEmpty) {
				printf("\n%-4d %10s %10s %.2f %10s ",list[i].id,list[i].name,list[i].lastName,list[i].price,list[i].flycode);
				printTypePassenger(list[i].typePassenger);
				printStatusFlight(list[i].statusFlight);
				printf("\n-----------------------------------------------------------------------------------\n");
				retorno = 0;

			}
		}
	}

	}
	return retorno;
}

int printListFlycode(Passenger* list, int length)
{
	int retorno;

	retorno = -1;

	if (list != NULL && length >= 0) {
		printf("   FlyCode    StatusFligth ");
		 printf("\n------------------------------------------\n");

		for (int i=0; i < length; i++) {

			if (list[i].isEmpty && list[i].statusFlight == 1) {
			    printf(" %s \t",list[i].flycode);
			    printStatusFlight(list[i].statusFlight);
			    printf("\n-----------------------------\n");
				retorno = 0;

			}
		}
	}
	return retorno;
}

void printTypePassenger(int typePassenger){

	switch(typePassenger){
	        case 1:
	        printf(" %10s","Primera Clase");
	        break;
	        case 2:
	        printf(" %10s", "Segunda Clase");
	        break;
	        case 3:
	        printf(" %10s", "Tercera Clase");
	        break;
	    }

}

void printStatusFlight(int statusFlight){

	 switch(statusFlight){
	        case 1:
	        printf(" %10s","Activo");
	        break;
	        case 2:
	        printf(" %10s","Demorado");
	        break;
	        case 3:
	        printf(" %10s","Desconocido");
	        break;
	        case 4:
	        printf(" %10s","Cancelado");
	        break;
		}
}

void CalculateTotalPassages(Passenger listaDePasajeros[], int size){
	float promedio;
	float totalDeLosPasajes;
	int cantidadDePasajeros;

	cantidadDePasajeros = CalculateTotalPassengers(listaDePasajeros,size);

	totalDeLosPasajes = CalculateTotal(listaDePasajeros,size);

	promedio = CalculateAverage(totalDeLosPasajes,cantidadDePasajeros);

	printf("\nEl total de los pasajes es %.2f ",totalDeLosPasajes);
	printf("\nEl promedio de los pasajes es %.2f",promedio);

	LookingOlder(listaDePasajeros,size,promedio);
}

int sortPassengers(Passenger* list, int len, int order)
{
    Passenger buffer;
	int flagSwap;
	int retorno;
	int auxiliar;

	    retorno = -1;

	    if(list != NULL && len > 0){


	        do{
	            flagSwap = 0;

	        for(int i = 0; i<len-1;i++){
	        	auxiliar = strcmp(list[i].lastName,list[i+1].lastName);

	        	if(((auxiliar > 0 || (!auxiliar && list[i].typePassenger > list[i+1].typePassenger)) && (order == 1))
	        		|| ((auxiliar < 0 || (!auxiliar && list[i].typePassenger < list[i+1].typePassenger)) && (!order)))
	        		{

	        	    flagSwap = 1;
	                buffer = list[i];
	                list[i] = list[i+1];
	                list[i+1] = buffer;
	        		}

	        } //Fin del for

		} while (flagSwap);

	        printf("\n\nLista de pasajeros ordenada Albeticamente por apellido desde A-Z\n\n");
	        printPassenger(list,len);

		retorno = 0;
	}

	return retorno;
}

/*
int sortPassengersByCode(Passenger* list, int len, int order)
{
        Passenger buffer;
	    int flagSwap;
	    int retorno;

	    retorno = -1;

	    if(list != NULL && len > 0){

	    	if(Passengers_Status(list,len) != -1){

	        do{
	            flagSwap = 0;

	        for(int i = 0; i<len-1;i++){

				if((((list[i].flycode < list[i+1].flycode || (list[i].flycode == list[i+1].flycode && list[i].statusFlight < list[i+1].statusFlight))) && (order)) ||
					((list[i].flycode > list[i+1].flycode || (list[i].flycode == list[i+1].flycode && list[i].statusFlight > list[i+1].statusFlight)) && (!order)))

				{
				    flagSwap = 1;
					buffer = list[i];
					list[i] = list[i + 1];
					list[i+1] = buffer;
				}

			} //Fin del for
		} while (flagSwap);

		retorno = 0;

		printf("\n\nLista de pasajeros ordenada Por codigo de vuelo");
	   printPassenger(list,len);

	}
	    }
	return retorno;
}

*/











