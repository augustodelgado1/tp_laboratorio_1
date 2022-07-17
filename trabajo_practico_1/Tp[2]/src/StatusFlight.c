/*
 * StatusFlight.c
 *
 *  Created on: 6 jul. 2022
 *      Author: alumno
 */
#include "StatusFlight.h"

void printlistStatus(StatusFlight listStatus[],int sizeStatus){

    if(sizeStatus > 0){

        for (int i = 0; i < sizeStatus; i++) {

            printf("\n%-4d %-10s",listStatus[i].idDeStausFlight,listStatus[i].descripcion);

        }

    }
}

int StatusPassengerId(StatusFlight list[],int size,int id){
    int index;

    for (int i = 0; i < size; i++) {

        if(list[i].idDeStausFlight == id){

            index = i;
            break;
        }
    }

    return index;
}
