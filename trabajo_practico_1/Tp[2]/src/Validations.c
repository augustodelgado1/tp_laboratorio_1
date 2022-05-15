
#include "Validations.h"

int IsNaN(char *string) {

	int retorno;
	int i = 0;

	retorno = 1;

	if (string[0] == '-') {
		i = 1;
	}

	for (; string[i] != '\0'; i++) {

		if (!isdigit(string[i])) {
			retorno = 0;
		}

	}

	return retorno;
}

int isLetter (char *string) {

	int retorno;
	retorno = 1;

	for (int i=0; string[i] != '\0'; i++) {


		if ((string[i] != ' ') && (string[i] < 'a' || string[i] > 'z') && (string[i] < 'A' || string[i] > 'Z') ) {

			retorno = 0;
		}

	}

	return retorno;
}

int isFloat(char*string){

	int retorno;
	int i;
	int cantidadPuntos;

	cantidadPuntos = 0;
	retorno = 1;

	for(i=0;string[i] != '\0';i++)
	   {

	       if (string[i] == '.' && cantidadPuntos == 0)
	       {
	           cantidadPuntos++;
	           i++;

	       }

	      if (!isdigit(string[i])) {
			   retorno = 0;
		  }

	   }


	return retorno;
}

