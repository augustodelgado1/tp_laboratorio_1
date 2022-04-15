#include "Menu.h"
#define FALSE 0
#define TRUE 1

void menu(){

	    float kilometros;
		float precioAerolineas;
		float precioLatam;
		float pagoTarjetaDebitoAerolineas;
		float pagoTarjetaCreditoAerolineas;
		float pagoBitcoinAerolineas;
		float pagoTarjetaDebitoLatam;
		float pagoTarjetaCreditoLatam;
		float pagoBitcoinLatam;
		float precioUnitarioAerolineas;
		float precioUnitarioLatam;
		float diferencia;
		int opcion;
		int flag;

		kilometros = 0;
		precioLatam = 0;
		precioAerolineas = 0;
		flag = FALSE;

		do {
			opcion = OpcionesDelMenu(kilometros,precioAerolineas,precioLatam);

			switch (opcion) {
			case 1:
				kilometros = PedirFlotanteYValidar("\nIngrese la cantidad de Kilómetros: ","Error ingrese una cantidad valida ", 1);
				SepararTexto();
				break;
			case 2:
				precioAerolineas = PedirFlotanteYValidar("\ningrese el Precio de Vuelo Aerolineas Argentinas ","\nError ingrese un precio valido  ", 1);
				precioLatam = PedirFlotanteYValidar("\ningrese el Precio de Vuelo Latam ","\nError ingrese un precio valido  ", 1);
				SepararTexto();
				break;
			case 3:
				if (kilometros != 0 && precioLatam != 0 && precioAerolineas != 0) {
				pagoTarjetaDebitoAerolineas = CalcularPagoTarjetaDebito(precioAerolineas);
				pagoTarjetaCreditoAerolineas = CalcularPagoTarjetaCredito(precioAerolineas);
				pagoBitcoinAerolineas = CalcularPagoBitcoin(precioAerolineas);
				precioUnitarioAerolineas = CalcularPrecioUnitario(kilometros,precioAerolineas);

				pagoTarjetaDebitoLatam = CalcularPagoTarjetaDebito(precioLatam);
				pagoTarjetaCreditoLatam = CalcularPagoTarjetaCredito(precioLatam);
				pagoBitcoinLatam = CalcularPagoBitcoin(precioLatam);
				precioUnitarioLatam = CalcularPrecioUnitario(kilometros,precioLatam);

				diferencia = CalcularDiferencia(precioAerolineas, precioLatam);
					printf("Se ha calculado todos los costos\n");

					flag = TRUE;
				} else {
					printf("\nDebe ingresar todos los costos para poder calcularlos\n");
				}
				SepararTexto();
				break;
			case 4:
				if (flag == TRUE) {
					InformarResultados("\n\nAerolíneas:  ",precioAerolineas,pagoTarjetaDebitoAerolineas,pagoTarjetaCreditoAerolineas, pagoBitcoinAerolineas,precioUnitarioAerolineas);
					InformarResultados("\nLatam:  ",precioLatam,pagoTarjetaDebitoLatam,pagoTarjetaCreditoLatam, pagoBitcoinLatam,precioUnitarioLatam);
					printf("la diferencia es %.2f \n",diferencia);
					}else{
					printf("\nSe deben calcular todos los costos para poder mostrar los resultados\n");
				}
				SepararTexto();
				break;
			case 5:
			kilometros = 7090;
			precioAerolineas = 162965;
			precioLatam = 159339;

			CargaForzadaDeDatos(kilometros,precioAerolineas,precioLatam);

			SepararTexto();
				break;
			}
		} while (opcion != 6);
}
/*
 * Augusto Delgado
 * Div B
 */
