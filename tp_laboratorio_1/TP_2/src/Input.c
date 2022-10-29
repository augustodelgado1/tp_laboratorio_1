#include "Input.h"


int GetNumeroFlotante(float *numero,char mensaje[], char mensajeError[], int minimo,int maximo,int reitentos){
    int estado;
	int auxiliar;

	if(numero != NULL && minimo<maximo && reitentos >= 0){

	estado = -1;
	printf("%s",mensaje);

    	do{
    	    if((!GetFloat(&auxiliar)) && auxiliar <= maximo && auxiliar >= minimo ){
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

	if(numero != NULL && minimo<maximo && reitentos >= 0){

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

int GetEnteroCorto(short* numero,char mensaje[],char mensajeError[] ,int minimo,int maximo,int reitentos)
{
	int estado;
	short auxiliar;

	estado = -1;

	if(numero != NULL && minimo<maximo && reitentos >= 0){

		printf("%s",mensaje);

			do{

				if(getShort(&auxiliar) == 0 && auxiliar >= minimo && auxiliar <= maximo){
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

   while(auxiliar == -1 || isLetter (cadena) == -1){
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

    while(auxiliar == -1  || (isLetter(string) != -1 ||  IsNaN(string) != 0) ){
        printf("%s",mensajeError);
    	auxiliar = MyGets(string,size);
    }

    return auxiliar;
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

int ValidarChar(char* respuesta,char mensaje[],char mensajeError[],char primerLetra , char segudaLetra,int reitentos){

	char auxiliarChar;
	int estado;

	estado = -1;
	auxiliarChar = GetChar (mensaje);

	do{

	    if(auxiliarChar == primerLetra || auxiliarChar == segudaLetra)
	    {
	       *respuesta = auxiliarChar;
	       estado = 1;
	       break;
	    }

	    auxiliarChar = GetChar (mensajeError);
	    reitentos--;
	}while(reitentos >= 0);

    return estado;
}




int ValidarFecha(int dia,int mes,int anio)
{
    int estado;

    estado = -1;

    if ( mes >= 1 && mes <= 12 )
    {
        switch (mes)
        {
            case  1 :
            case  3 :
            case  5 :
            case  7 :
            case  8 :
            case 10 :
            case 12 :

            if (dia >= 1 && dia <= 31)
            {
              estado = 1;
            }

            break;

            case  4 :
            case  6 :
            case  9 :
            case 11 :

                if ( dia >= 1 && dia <= 30 )
                {
                  estado = 1;
                }

                break;

            case  2 :


                  if ( dia >= 1 && dia <= 29 )
                   {
                     estado = 1;
                   }else{

                    if ( dia >= 1 && dia <= 28 )
                    {
                        estado = 1;
                    }
                }

        }

    }

    return estado;

}

