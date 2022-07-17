#include "TypePassenger.h"


void printListType(TypePassenger listaDeTipos[],int sizeType){

    if(sizeType > 0){

        for (int i = 0; i < sizeType; i++) {

            printf("%-4d %-10s\n",listaDeTipos[i].idDeTypePassenger,listaDeTipos[i].descripcion);

        }

    }
}


int BusquedarIdDetype(TypePassenger listaDeTipos[],int sizeType,int id){

    int index;

    for (int i = 0; i < sizeType; i++) {

        if(listaDeTipos[i].idDeTypePassenger == id){

            index = i;
            break;
        }
    }

    return index;
}
