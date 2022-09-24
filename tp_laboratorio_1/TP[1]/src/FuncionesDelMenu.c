/*
 * FuncionesDelMenu.c
 *
 *  Created on: 17 sep. 2022
 *      Author: alumno
 */
#include "FuncionesDelMenu.h"

int IngresarCostos(int* costoDeHopedaje,int* costoDeComida,int* costoDeTransporte){

    int opcion;
    int retorno;
    int estado;

    estado = -1;

    do{
                MostarUnMensaje("\t-- Costos de Mantenimiento --");
			    printf("Ingrese que costos de Mantenimiento desea Ingresar"
                      "\n1.Costo de hospedaje -> %d "
                      "\n2.Costo de comida -> %d "
                      "\n3.Costo de transporte -> %d"
                      "\n4.Volver Al Menu Principal"
    		          "\n---------------------------------------------------",*costoDeHopedaje,*costoDeComida,*costoDeTransporte);

    			retorno = getInt(&opcion,"\nIngrese Una Opcion: ", "Error Ingrese Una opcion Valida: ",1, 4, 5);

    			if(retorno != -1)
    			{
    			    switch(opcion)
    			    {
    			        case 1:

                            if(getInt(costoDeHopedaje,"Ingrese el costo De Hopedaje ","Error Ingrese Un costo Valido: ",1,1000000,5) == 1)
                            {
                                printf("\nSe cargo correctamente el costo De Hopedaje\n\n");
                            }else{
                                printf("\n\nError -- No Se Pudo Cargar el costo -- Error\n\n");
                            }

                        break;

                        case 2:

                            if(getInt(costoDeComida,"Ingrese el costo de Comida ","Error Ingrese Un costo Valido: ",1,1000000,1) == 1)
                            {
                                printf("\nSe cargo correctamente el costo de Comida \n\n");
                            }else{
                                printf("\n\nError -- No Se Pudo Cargar el costo -- Error\n\n");
                            }
                        break;

                        case 3:

                            if(getInt(costoDeTransporte,"Ingrese el costo de Transporte ","Error Ingrese Un costo Valido: ",1,1000000,1) == 1)
                            {
                                printf("\nSe cargo correctamente el costo de Transporte\n\n");
                            }else{
                                printf("\n\nError -- No Se Pudo Cargar el costo -- Error\n\n");
                            }

                        break;
    			    }

    			}else{

    			    printf("\n\nError -- No Se Ingreso una opcion Valida -- Error\n\n");
    			    break;
    			}

    	}while(opcion != 4);

    	if(*costoDeHopedaje > 0 && *costoDeComida > 0 && *costoDeTransporte > 0){

    	    estado = 1;
    	}

    return estado;
}

int ValidarPosicion(int* posicion,int* contadorArqueros,int* contadorDefensores,int* contadorMediocampista,int* contadorDelanteros)
{
    int estado;

    estado = -1;

            switch(*posicion){

                case 1:

                if(*contadorArqueros < 2)
                {
                    (*contadorArqueros)++;
                    estado = 1;
                }
                    break;

                case 2:

                if(*contadorDefensores < 8)
                {
                    (*contadorDefensores)++;
                    estado = 1;
                }
                    break;

               case 3:

               if(*contadorMediocampista < 8)
                {
                    (*contadorMediocampista)++;
                    estado = 1;
                }
                    break;

                case 4:

                if(*contadorDelanteros < 4)
                {
                    (*contadorDelanteros)++;
                    estado = 1;
                }
                    break;

            }

    return estado;
}

int PedirConfederacion(int* confederacion,int* contadorAFC,int* contadorCONCACAF,int* contadorCONMEBOL,int* contadorUEFA,int* contadorOFC,int* contadorCAF){

    int estado;

    estado = getInt(confederacion,"1.AFC\n2.CAF\n3.CONCACAF\n4.CONMEBOL\n5.UEFA\n6.OFC\nIngrese la confederacion del jugador : ", "Error Ingrese un numero valido: ", 1,6,2);

    if(estado != -1){

        switch(*confederacion){

    	case 1:
        (*contadorAFC)++;
            break;

        case 2:
        (*contadorCAF)++;
            break;

        case 3:
        (*contadorCONCACAF)++;
            break;

        case 4:
        (*contadorCONMEBOL)++;
            break;

        case 5:
        (*contadorUEFA)++;
            break;

        case 6:
        (*contadorOFC)++;
            break;

        }

    }

    return estado;
}

int CalcularCostosMercados(int contadorAFC,int contadorCONCACAF,int contadorCONMEBOL,int contadorOFC,int contadorUEFA,int contadorCAF,int contadorJugadores,
float* promedioAFC,float* promedioCONCACAF,float* promedioCONMEBOL,float* promedioOFC,float* promedioUEFA,float* promedioCAF){

    int estado;

    estado = -1;

    if(CalcularDivision(contadorAFC,contadorJugadores,promedioAFC) != -1
    && CalcularDivision(contadorCONCACAF,contadorJugadores,promedioCONCACAF) != -1
    && CalcularDivision(contadorCONMEBOL,contadorJugadores,promedioCONMEBOL) != -1
    && CalcularDivision(contadorOFC,contadorJugadores,promedioOFC) != -1
    && CalcularDivision(contadorUEFA,contadorJugadores,promedioUEFA) != -1
    && CalcularDivision(contadorCAF,contadorJugadores,promedioCAF) != -1)
    {
        estado = 1;
    }

    return estado;
}

int CalcularAumento(int contadorAFC,int contadorCONCACAF,int contadorCONMEBOL,int contadorCAF,int contadorUEFA,int contadorOFC,int sumaCostos,int* aumento)
{
    int totalCosto;

    if(contadorUEFA > contadorAFC && contadorUEFA > contadorCONCACAF
    && contadorUEFA > contadorCONMEBOL && contadorUEFA > contadorCAF
    && contadorUEFA > contadorOFC)
    {
        *aumento = CalcularMultiplicacion(sumaCostos,1.35);
        totalCosto = CalcularSuma(sumaCostos,*aumento);
    }

    return totalCosto;
}

int InformarResultados(float promedioUEFA,float promedioCONMEBOL,float promedioCONCACAF,float promedioAFC,float promedioOFC,float promedioCAF,int contadorJugadores,int sumaCostos,int totalCosto,int aumento){
   int estado;

   estado = -1;

    if(sumaCostos > 0 && contadorJugadores > 0){

        MostarUnMensaje("\t-- Informar Resultados -- ");
				     printf("Porcentaje Uefa %.2f\n"
			                "Porcentaje CONMEBOL: %.2f\n"
                            "Porcentaje CONCACAF: %.2f\n"
                            "Porcentaje AFC: %.2f\n"
                            "Porcentaje OFC: %.2f\n"
                            "Porcentaje CAF: %.2f\n",promedioUEFA,promedioCONMEBOL,
                            promedioCONCACAF,promedioAFC,promedioOFC,promedioCAF);
        estado = 1;

        if(aumento > 0){

            printf("El costo de mantenimiento era %d y recibio un aumento de %d ,y su nuevo valor es %d",sumaCostos,aumento,totalCosto);

	    }else{

            printf("El costo de mantenimiento es %d",sumaCostos);
        }

	}

      return estado;
}

void MostarUnMensaje(char mensaje[]){

    printf("\n+-------------------------------------------------------+\n");
    printf("%s",mensaje);
    printf("\n+-------------------------------------------------------+\n");

}
