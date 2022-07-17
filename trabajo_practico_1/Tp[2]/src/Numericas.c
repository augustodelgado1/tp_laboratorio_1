#include "Numericas.h"

int ContadorPasajeros(Passenger* list, int len){
    int contador;

    contador = 0;

    for (int i = 0; i < len; i++) {

        if(list[i].isEmpty){

            contador++;
        }
    }

    return contador;

}

float Suma(Passenger* list, int len){
    float acumulador;

    acumulador = 0;

    for (int i = 0; i < len; i++) {

        if(list[i].isEmpty){

            acumulador += list[i].price;

        }
    }

    return acumulador;

}

float CalcualarPromedio(float primerNumero ,int segundoNumero){
    float promedio;

    promedio = 0;

    if(segundoNumero != 0){

       promedio = (float) primerNumero / segundoNumero;

    }

    return promedio;
}

int BucarMayor(Passenger* list, int len,float promedio){
    int contador;

    contador = 0;

    if(len > 0)
    {
        for (int i = 0; i < len; i++) {

            if(list[i].isEmpty == 1 && list[i].price > promedio)
            {

                contador++;

            }
        }
    }

    return contador;

}


