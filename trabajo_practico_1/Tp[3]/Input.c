#include "Input.h"


int GetNumeroFlotante(float *numero,char mensaje[], char mensajeError[], int minimo,int reitentos){
    int estado;
	int auxiliar;

	if(numero != NULL){

	estado = -1;
	printf("%s",mensaje);

    	do{
    	    if((!GetFloat(&auxiliar)) && auxiliar >= minimo){
        		  *numero = auxiliar;
        		  estado = 0;
        		  break;
        	}

            printf("%s",mensajeError);
            reitentos--;

    	}while(reitentos > 0);


    }

	return estado;
}

int GetNumero(int* numero,char mensaje[],char mensajeError[] ,int minimo,int maximo,int reitentos){

	int estado;
	int auxiliar;

	estado = -1;

	if(numero != NULL){

	printf("%s",mensaje);

    	do{

            if(getInt(&auxiliar) == 0 && auxiliar >= minimo && auxiliar <= maximo){
            	*numero = auxiliar;
            	 estado = 0;
            	 break;
            }

            printf("%s",mensajeError);
            reitentos--;
        }while(reitentos >= 0);

	}


	return estado;
}


char GetChar (char mensaje[]){

    char datoIngresado;

    printf("%s",mensaje);
	fflush(stdin);
	scanf("%c",&datoIngresado);
	datoIngresado = tolower(datoIngresado);

	return datoIngresado;
}

int GetNombre(char mensaje[],char mensajeError[],char cadena[],int size){
     int auxiliar;

   printf("%s",mensaje);
   auxiliar = MyGets(cadena,size);

   while(auxiliar == -1 || isLetter (cadena) == 0){
        printf("%s",mensajeError);
        auxiliar = MyGets(cadena,size);

    }

    ConvertidorDeMinusculas(cadena);
    ConvertidorDeMayusculas(cadena);

    return auxiliar;
}

int GetAlphanumeic(char mensaje[],char mensajeError[],char string[],int size){
	int auxiliar;

	printf("%s",mensaje);
	auxiliar = MyGets(string,size);

    while(auxiliar == -1  || (isLetter(string) != 0 ||  IsNaN(string,size) != 0) ){
        printf("%s",mensajeError);
    	auxiliar = MyGets(string,size);
    }

    return auxiliar;
}

char PreguntarSoN(char mensaje[],char mensajeError[]){

	char respuesta;

	respuesta = GetChar (mensaje);

    while(respuesta != 's' && respuesta != 'n'){

		respuesta = GetChar (mensajeError);

	}

    return respuesta;

}

void ConvertidorDeMinusculas(char *nombre){

	for (int i = 0; *(nombre+i) != '\0'; i++) {

        *(nombre+i) = tolower(*(nombre+i));

    }
}

void ConvertidorDeMayusculas(char nombre[]){

    nombre[0] = toupper(nombre[0]);

    for (int i = 0; nombre[i] != '\0'; i++) {

        if((!isalpha(nombre[i]))){
           nombre[i+1] = toupper(nombre[i+1]);

        }

    }
}
