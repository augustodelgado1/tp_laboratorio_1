/*
 * @brief Contiene las altas,baja,modificaciones y los listados  de una aerolines de vuelos
 */
#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include "Menu.h"

#define LIBRE 0
#define OCUPADO 1
#define MAX_NOMBRE 51
#define MAX_DESCRIPCION 30
#define MAX_DESCRIPCION 30

struct{
	int idDeStausFlight;
	char descripcion[MAX_DESCRIPCION];

}typedef StatusFlight;

struct{
	int idDeTypePassenger;
	char descripcion[MAX_DESCRIPCION];

}typedef TypePassenger;

struct{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int idDeTypePassenger;
	int idDeStausFlight;
	int isEmpty;

}typedef Passenger;

//ALTA

/// @fn int AltaDePasajero(Passenger[], int, TypePassenger[], int, StatusFlight[], int)
/// @brief Agrega un pasajero a la lista verificando que los datos se ingresen correctamente
///
/// @param Passenger la lista de pasajeros
/// @param la cantidad de elementos de la lista
/// @param la lista de tipos de vuelo
/// @param el tamaño de la lista de tipos de vuelo
/// @param la lista de estados de vuelo
/// @param el tamaño de la lista de estados de vuelo
/// @return [-2] si no encontro espacio en el array ,[-1] si no pudo anadirlo a la lista, [1] si pudo anadirlo a la lista
int AltaDePasajero(Passenger list[], int len,TypePassenger listType[],int sizeType,StatusFlight listStatus[],int sizeStatus);

/// @fn int PedirUnPasajero(Passenger*, int*, TypePassenger[], int, StatusFlight[], int)
/// @brief Pide los datos de un pasajero y verifica que los datos se ingresen correctamente
///
/// @param Passenger la lista de pasajeros
/// @param el id Del pasajero
/// @param la lista de tipos de vuelo
/// @param el tamaño de la lista de tipos de vuelo
/// @param la lista de estados de vuelo
/// @param el tamaño de la lista de estados de vuelo
/// @return [-1] si no se ingresaron correctamente los datos, [1] si se ingresaron correctamente los datos
int PedirUnPasajero(Passenger *listaDePasajero,int* id,TypePassenger listType[],int sizeType,StatusFlight listStatus[],int sizeStatus);

/// @fn int CargaForzada(Passenger*, int)
/// @brief Guarda en la lista de pasajeros 6 pasajero harcodeados
///
/// @param Passenger la lista de pasajeros
/// @param la cantidad de elementos de la lista
/// @return [0] si pudo relizar la carga forzada, sino [-1]
int CargaForzada(Passenger *list, int len);

/// @fn int initPassengers(Passenger*, int)
/// @brief Inicializa todas las posiciones del array en libre (0)
///
/// @param Passenger[]  la lista de pasajeros
/// @param int la longitud del array
/// @return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien
int initPassengers(Passenger *list, int len);

/// @fn int addPassenger(Passenger*, int, int, char[], char[], float, int, char[], int)
/// @brief agrega en una lista existente de pasajeros los valores recibidos como parámetros en la primera posición vacía
///
/// @param Passenger[] la lista de pasajeros
/// @param int la longitud del array
/// @param int el id del pasajero
/// @param char[] el nombre del pasajero
/// @param char[] el apellido del pasajero
/// @param float el precio del pasajero
/// @param int el tipo de pasajero
/// @param char[] flycode el codigo de vuelo del pasajero
/// @param int el nesta del vuelo
/// @return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien
int addPassenger(Passenger* list, int len, int id, char name[],char
lastName[],float price,int typePassenger, char flycode[],int);


//MODIFICACION

/// @fn int Modificar(Passenger[], int)
/// @brief Modifica el valor de  un elemento o varios de la estructura
///
/// @param Passenger[] la lista de pasajeros
/// @param int la longitud del array
/// @return (1) Si se realizo una modificacion ,(0) Si se cancelo una modificacion,(-1) si no encontro el id,(-2) si la lista no tiene elementos
int Modify(Passenger list[], int len,TypePassenger listType[],int sizeType,StatusFlight listStatus[],int sizeStatus);

//BAJA
/// @fn int removePassenger(Passenger*, int, int)
/// @brief Eliminar un Pasajero por Id
/// @param Passenger[] la lista de pasajeros
/// @param int la longitud del array
/// @param int el id que quiere eliminar
/// @return int Retorna (-1) si Error [Longitud no válida o puntero NULL o si no puede encontrar un pasajero] - (0) si está bien
int removePassenger(Passenger* list, int len, int id);


//APARTE


/// @fn int Passenger_estado(Passenger array[], int size);
/// @brief recorre la lista de pasajeros y retorna si encontro una posicion del array en ocupado
///
/// @param Passenger[] la lista de pasajeros
/// @param int la longitud del array
/// @return (-1) si no la encotro , (1) si la encotro
int Passengers_Status(Passenger[], int size);

/// @fn int Passengers_SearchFree(Passenger[], int)
/// @brief recorre el array de la lista de pasajeros y retorna si encontro una posicion del array en libre (0)
///
/// @param Passenger la lista de pasajeros
/// @param size  la longitud del array
/// @return  (-1) si no encotro , si encontro retorna el indice
int Passengers_SearchFree(Passenger[], int size);

/// @fn void CalculateTotalPassages(Passenger[], int)
/// @brief Calcula el promedio de el total de precios y el total de pasajeros y mustra el listado
///
/// @param Passenger[] la lista de pasajeros
/// @param int la longitud del array
int CalculateTotalPassages(Passenger listaDePasajeros[], int size);

/// @fn int Passenger_estado(Passenger array[], int size);
/// @brief Busca el Id y devuelve la posición del índice del array
///
/// @param Passenger[] la lista de pasajeros
/// @param int la longitud del array
/// @param int el id que se ingreso
/// @return (-1) si no lo encotro , si lo encontro la posición del índice del array
int findPassengerById(Passenger* list, int len,int id);

/// @fn void SubMenu(Passenger*, int, TypePassenger[], int, StatusFlight[], int, int)
/// @brief Muestra sub menu y permite elegir opciones
///
/// @param Passenger la lista de pasajeros
/// @param la cantidad de elementos de la lista
/// @param la lista de tipos de vuelo
/// @param el tamaño de la lista de tipos de vuelo
/// @param la lista de estados de vuelo
/// @param el tamaño de la lista de estados de vuelo
void SubMenu(Passenger *list, int len,TypePassenger listType[],int sizeType,StatusFlight listStatus[],int sizeStatus,int opcion);

/// @fn int MostrarPassenger(Passenger[], int, TypePassenger[], int, StatusFlight[], int)
/// @brief Muetra la lista de pasajeros indicado el tipo de vuelo y el estado
///
/// @param Passenger la lista de pasajeros
/// @param la cantidad de elementos de la lista
/// @param la lista de tipos de vuelo
/// @param el tamaño de la lista de tipos de vuelo
/// @param la lista de estados de vuelo
/// @param el tamaño de la lista de estados de vuelo
/// @return int Retorna (-1) si Error [Longitud no válida o puntero NULL o si no puede encontrar un pasajero] - (1) si está bien
int MostrarPassenger(Passenger list[],int size,TypePassenger listaDeTipos[],int sizeType,StatusFlight listaDeStatus[],int sizeDeStatus);


/// @fn int printPassenger(Passenger*, int)
/// @brief imprime el contenido de la matriz de pasajeros
///
/// @param Passenger[] la lista de pasajeros
/// @param int la longitud del array
/// @return int Retorna (-1) si Error [Longitud no válida o puntero NULL o si no puede encontrar un pasajero] - (0) si está bien
int printPassenger(Passenger* list, int length);

/// @fn void PassengerOnePrint(Passenger)
/// @brief Muestra Un pasajero
///
/// @param Passenger la lista de pasajeros
void PassengerOnePrint(Passenger list);

/// @fn int sortPassengers(Passenger*, int, int)
/// @brief Ordenar los elementos de la array  de pasajeros, el orden de los argumentos indicar orden ARRIBA o ABAJO
///
/// @param list la lista de pasajeros
/// @param len la longitud del array
/// @param int [1] indica ARRIBA - [0] indica ABAJO
/// @return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bi
int sortPassengers(Passenger* list, int len, int order);

/// @fn int sortPassengersByCode(Passenger*, int, int)
/// @brief Ordenar los elementos de la array  de pasajeros, el orden de los argumentos indicar orden ARRIBA o ABAJO
///
/// @param list la lista de pasajeros
/// @param len la longitud del array
/// @param int [1] indica ARRIBA - [0] indica ABAJO
/// @return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien
int sortPassengersFly(Passenger* list, int len, int order);


#endif

