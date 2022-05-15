#include "Numericas.h"

int CalculateTotalPassengers(Passenger listaDePasjeros[], int size){
    int contador;
    contador = 0;

    for(int i=0; i<size; i++)
   	{
   	    if(listaDePasjeros[i].isEmpty == 1){
   	    	contador++;
   	    }
   	}

    return contador;

}

int CalculateTotal(Passenger listaDePasjeros[], int size){
    float suma;
    suma = 0;

    for(int i=0;i<size;i++){
    	if(listaDePasjeros[i].isEmpty == 1){
    	suma += listaDePasjeros[i].price;
    	}

    }

    return suma;

}

float CalculateAverage(float primerNumero,float segundoNumero){
	float promedio;

	promedio = 0;

	if(segundoNumero != 0){
	promedio = primerNumero / segundoNumero;
	}

	return promedio;
}

int LookingOlder(Passenger listaDePasjeros[], int size,float promedio){
	int flag;
	int cantidadDePrecios;

    flag = 0;
    cantidadDePrecios = 0;

    for(int i=0;i<size;i++){
        if(listaDePasjeros[i].isEmpty == 1 && listaDePasjeros[i].price > promedio)
            {
                cantidadDePrecios++;
        	    flag = 1;
            }

    }

    printf("\n\nla cantidad De Pasajeros que superan el precio promedio son %d\n\n ",cantidadDePrecios);

    return flag;
}


