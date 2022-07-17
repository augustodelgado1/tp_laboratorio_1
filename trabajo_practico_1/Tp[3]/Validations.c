
#include "Validations.h"


int getInt(int* numero){

    int estado;
    char buffer[50];

    estado = -1;

    if((!MyGets(buffer,sizeof(buffer)))
    && IsNaN(buffer,sizeof(buffer)) != 0)
    {
       *numero = atoi(buffer);
       estado = 0;

    }

    return estado;
}

int GetFloat(int* numero){

    int estado;
    char buffer[50];

    estado = -1;

    if((!MyGets(buffer,sizeof(buffer)))
    && isFloat(buffer) != 0)
    {
       *numero  = atof(buffer);
       estado = 0;

    }

    return estado;
}


int IsNaN(char *string,int size) {

	int retorno;
	int i = 0;

	retorno = 1;

	for (; i<size && string[i] != '\0'; i++) {

	    if (i == 0 && (string[0] == '-' || string[0] == '+')) {

    		continue;
	    }

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


int MyGets(char string[],int size)
{
	int retorno;

	retorno = -1;

	if(string != NULL && size > 0){
		fflush(stdin);
    	if(fgets(string,size,stdin) != NULL && string[strlen(string)-1] == '\n'){

        	string[strlen(string)-1] = '\0';
        	retorno = 0;

    	}
	}


	return retorno;
}

