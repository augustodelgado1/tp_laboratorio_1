#include "FuncionesDelMenu.h"

int OpcionesDelMenu (float kilometros ,float precioAerolineas,float precioLatam){

	int opcion;

	printf("   Menu de Opciones\n");
	printf("----------------------\n");
	printf("1. Ingresar Kil?metros");

	if(kilometros > 0){
		printf("(km = %.2f)\n)",kilometros);
	}else{
		printf("(km = X)\n");
	}

	printf("2. Ingresar Precio de Vuelos ");

	if(precioAerolineas > 0 || precioLatam > 0){
		printf("(Aerol?neas = %.2f , Latam = %.2f)\n",precioAerolineas, precioLatam);
	}else{
		printf("(Aerol?neas = Y, Latam = Z)\n");
	}

	printf("3. Calcular todos los costos \n");
	printf("4. Informar Resultados \n");
	printf("5. Carga forzada de datos \n");
	printf("6. Salir \n");
	printf("-------------------------\n");

	opcion = PedirEnteroYValidar("Ingrese el numero de la opci?n que desea realizar ","Error ingrese una opci?n valida ", 1, 6);

	return opcion;
}

void SepararTexto (void){
	printf("-------------------------\n");
	printf("\n\n\n");
}

void InformarResultados (char mensaje[],float numero,float pagoTarjetaDebito,float pagoTarjetaCredito,float pagoBitcoin,float precioUnitario){

	printf(" %s  %.2f \n",mensaje,numero);

	printf("a)Precio con tarjeta de d?bito: %.2f \n",pagoTarjetaDebito);
	printf("b)Precio con tarjeta de cr?dito: %.2f \n",pagoTarjetaCredito);
	printf("c)Precio pagando con Bitcoin: %f BTC \n",pagoBitcoin);
	printf("d)Precio unitario: %.2f \n", precioUnitario);
}

void  CargaForzadaDeDatos(float kilometros,float precioAerolineas, float precioLatam){

	float pagoTarjetaDebitoAerolineas;
	float pagoTarjetaCreditoAerolineas;
	float pagoBitcoinAerolineas;
	float pagoTarjetaDebitoLatam;
	float pagoTarjetaCreditoLatam;
	float pagoBitcoinLatam;
	float precioUnitarioAerolineas;
	float precioUnitarioLatam;
	float diferencia;


	pagoTarjetaDebitoAerolineas = CalcularPagoTarjetaDebito(precioAerolineas);
	pagoTarjetaCreditoAerolineas = CalcularPagoTarjetaCredito(precioAerolineas);
	pagoBitcoinAerolineas = CalcularPagoBitcoin(precioAerolineas);
	precioUnitarioAerolineas = CalcularPrecioUnitario(kilometros,precioAerolineas);

	pagoTarjetaDebitoLatam = CalcularPagoTarjetaDebito(precioLatam);
	pagoTarjetaCreditoLatam = CalcularPagoTarjetaCredito(precioLatam);
	pagoBitcoinLatam = CalcularPagoBitcoin(precioLatam);
	precioUnitarioLatam = CalcularPrecioUnitario(kilometros, precioLatam);

	diferencia = CalcularDiferencia(precioAerolineas, precioLatam);

	InformarResultados("\n\nAerol?neas: ", precioAerolineas,pagoTarjetaDebitoAerolineas, pagoTarjetaCreditoAerolineas,
			pagoBitcoinAerolineas, precioUnitarioAerolineas);
	InformarResultados("\nLatam: ", precioLatam, pagoTarjetaDebitoLatam,
			pagoTarjetaCreditoLatam, pagoBitcoinLatam, precioUnitarioLatam);

	printf("la diferencia es %.2f \n", diferencia);

}
/*
 * Augusto Delgado
 * Div B
 */
