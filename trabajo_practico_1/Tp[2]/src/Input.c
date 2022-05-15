
#include "Input.h"

float GetFloat (char mensaje[],char mensajeError[] ,int minimo){

	float datoIngresado;
	char buffer[5900];

	printf("%s",mensaje);
	fflush(stdin);
	scanf("%[^\n]",buffer);

	datoIngresado = atof(buffer);

	while(isFloat(buffer) ==  0){
		printf("%s",mensajeError);
		fflush(stdin);
		scanf("%[^\n]", buffer);

		datoIngresado = atof(buffer);
	}

	return datoIngresado;
}

int GetInt(char mensaje[],char mensajeError[] ,int minimo,int maximo){

	int datoIngresado;
	char buffer[5900];

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%[^\n]", buffer);


	datoIngresado = atoi(buffer);

	while(strlen(buffer) >= 5900 || IsNaN(buffer) == 0 || datoIngresado < minimo || datoIngresado > maximo){
	    printf("%s",mensajeError);
		fflush(stdin);
		scanf("%[^\n]", buffer);
		datoIngresado = atoi(buffer);
	}


	return datoIngresado;
}

char GetChar (char mensaje[],char mensajeError[] ,char minimo,char maximo){

    char datoIngresado;

	printf("%s",mensaje);
	fflush(stdin);
	scanf("%c",&datoIngresado);
	datoIngresado = tolower(datoIngresado);

	while(datoIngresado != minimo && datoIngresado != maximo){
		printf("%s",mensajeError);
		fflush(stdin);
		scanf("%c",&datoIngresado);
		datoIngresado = tolower(datoIngresado);
	}

	return datoIngresado;
}

void GetSring(char mensaje[],char mensajeError[],char string[],int size){


    printf("%s",mensaje);
    fflush(stdin);
    scanf("%[^\n]",string);

    while(strlen(string) >= size || isLetter (string) == 0){
      printf("%s",mensajeError);
      fflush(stdin);
      scanf("%[^\n]",string);
    }
}

void GetAlphanumeic(char mensaje[],char mensajeError[],char string[],int size){


    printf("%s",mensaje);
    fflush(stdin);
    scanf("%[^\n]",string);

    while(strlen(string) >= size || isLetter (string) == 1 || IsNaN(string) == 1 ){
      printf("%s",mensajeError);
      fflush(stdin);
      scanf("%[^\n]",string);
    }
}
