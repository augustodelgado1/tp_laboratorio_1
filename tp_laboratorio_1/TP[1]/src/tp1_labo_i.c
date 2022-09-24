
#include "FuncionesDelMenu.h"

int main(void) {

	setbuf(stdout,NULL);

	 int opcion;
	 int salir;
	 int retorno;
	 int costoDeHospedaje;
	 int costoDeComida;
	 int costoDeTransporte;
	 int sumaCostos;
	 int totalCosto;
	 int bandera;
	 int posicion;
	 int aumento;
	 int contadorArqueros;
     int contadorDefensores;
     int contadorMediocampista;
     int contadorDelanteros;
     int contadorAFC;
     int contadorCONCACAF;
     int contadorCONMEBOL;
     int contadorUEFA;
     int contadorOFC;
     int contadorCAF;
     int contadorJugadores;
     int confederacion;
     int numeroDeCamiseta;
     int retornoCalculos;
	 float promedioAFC;
     float promedioCONCACAF;
     float promedioCONMEBOL;
     float promedioUEFA;
     float promedioOFC;
     float promedioCAF;

	costoDeHospedaje = 0;
    costoDeComida = 0;
    costoDeTransporte = 0;
    contadorJugadores = 0;
    bandera = 0;

    contadorArqueros = 0;
    contadorDefensores = 0;
    contadorMediocampista = 0;
    contadorDelanteros = 0;

    contadorAFC = 0;
    contadorCONCACAF = 0;
    contadorCONMEBOL = 0;
    contadorUEFA = 0;
    contadorOFC = 0;
    contadorCAF = 0;

	do{

	    MostarUnMensaje("\t\t-- Menu Principal --");
		printf("1.Ingreso de los costos de Mantenimiento"
				"\n CostoDeHospedaje -> %d"
				"\n CostoDeComida -> %d "
				"\n CostoDeTransporte -> %d"
		 		"\n2.Carga de jugadores"
		 		"\n Arqueros -> %d\n"
	    		" Defensores -> %d\n"
 	    	    " Mediocampistas -> %d\n"
	    		" Delanteros -> %d"
				"\n3. Realizar todos los calculos"
				"\n4. Informar todos los resultados"
				"\n5. Salir"
				"\n--------------------------------------------",costoDeHospedaje,costoDeComida,costoDeTransporte,contadorArqueros,contadorDefensores,contadorMediocampista,contadorDelanteros);


		retorno = getInt(&opcion,"\nIngrese Una Opcion: ", "Error Ingrese Una opcion Valida: ",1, 10, 2);

		if(retorno != -1)
		{
	        switch (opcion) {
    		case 1:
    			bandera = IngresarCostos(&costoDeHospedaje,&costoDeComida,&costoDeTransporte);
    		    break;

    		case 2:

    		if(contadorJugadores <= 22 && getInt(&posicion,"1.Arquero --> Max: 2\n2.Defensor --> Max: 8\n3.Mediocampista --> Max: 8\n4.Delanteros --> Max: 4\nIngrese la posicion del jugador : ", "Error Ingrese un numero valido: ", 1,5,2) != -1
    		&& getInt(&numeroDeCamiseta,"Ingrese Una Numero de camiseta: ", "Error Ingrese Un Numero Valido: ",1,50, 2)
    		&& PedirConfederacion(&confederacion,&contadorAFC,&contadorCONCACAF,&contadorCONMEBOL,&contadorUEFA,&contadorOFC,&contadorCAF) != -1)
    	    {
    	        while(ValidarPosicion(&posicion,&contadorArqueros,&contadorDefensores,&contadorMediocampista,&contadorDelanteros) == -1)
	            {
	                printf("1.Arquero --> Max: 2\n2.Defensor --> Max: 8\n3.Mediocampista --> Max: 8 \n4.Delanteros --> Max: 4\n");
	                getInt(&posicion,"Reigrese la posicion del jugador : ", "Error Ingrese un numero valido: ", 1,5,2);
	            }

	           printf("\n\n-- Se Ingresaron los datos correctamente -- \n\n");
    	       contadorJugadores++;

    	    }else{

    	        printf("\nError -- No se Pudo Realizar la Carga de jugador -- Error\n");
    	    }

    		 break;

    		case 3:

    		    if(bandera > 0 && contadorJugadores > 0){

    		        sumaCostos = CalcularSuma(costoDeHospedaje,costoDeComida);
                    sumaCostos = CalcularSuma(sumaCostos,costoDeTransporte);
    		        retornoCalculos = CalcularCostosMercados(contadorAFC,contadorCONCACAF,contadorCONMEBOL,contadorOFC,contadorUEFA,contadorCAF,
    		        contadorJugadores,&promedioAFC,&promedioCONCACAF,&promedioCONMEBOL,&promedioOFC,&promedioUEFA,&promedioCAF);
    			    totalCosto = CalcularAumento(contadorAFC,contadorCONCACAF,contadorCONMEBOL,contadorCAF,contadorUEFA,contadorOFC,sumaCostos,&aumento);

    			    if(retornoCalculos != -1 && sumaCostos > 0)
    			    {
    			        printf("\nLos Calculos se realizaron correctamente\n\n");

    			    }else{

    			        printf("Error -- Se produjo Un error al realizar los Calculos -- Error");
    			    }

    		    }else{

    			    printf("\nError -- Debe Ingresar a la opcion 1 y 2 -- Error\n\n");
    			}

    			break;

    		case 4:

    			if(InformarResultados(promedioUEFA,promedioCONMEBOL,promedioCONCACAF,promedioAFC,promedioOFC,promedioCAF,contadorJugadores,sumaCostos,totalCosto,aumento) == -1){

    			    printf("\nError -- Debe realizar los Calculos (opcion 3) para mostrar los resultados -- Error\n\n");
                }

                break;

    		case 5:

    			if(getInt(&salir,"¿Esta Seguro que quiere salir? (1.Si , 2.No) ", "Error -- Error Ingrese una opcion valida -- Error", 1, 2, 5) == -1)
    			{
    			    printf("\nError -- No se Pudo Ingresar una opcion valida -- Error\n\n");
    			}

    		    break;
	        }
		}

	}while(salir != 1 && retorno != -1);

	return EXIT_SUCCESS;
}


