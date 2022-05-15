/*
 * @brief Contiene las altas,baja,modificaciones y los listados  de una aerolines de vuelos
 */
#include "Menu.h"

struct{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;

}typedef Passenger;

/// @fn Passenger GetAPassenger()
/// @brief Permite cargar los datos de un pasajero
///
/// @return (-1) si no encontro espacio libres en el array , de lo contrario retorna el indice
int GetPassenger(Passenger listaDePasajeros[], int size);

/// @fn void InitThePassangerList(Passenger[], int)
/// @brief Permite hacodear la lista de pasajeros
///
/// @param Passenger[]  la lista de pasajeros
/// @param int la longitud del array
void InitThePassangerList(Passenger array[],int size);

/// @fn int initPassengers(Passenger*, int)
/// @brief Inicializa todas las posiciones del array en libre (0)
///
/// @param Passenger[]  la lista de pasajeros
/// @param int la longitud del array
/// @return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien
int initPassengers(Passenger *list, int len);

/// @fn int Passenger_estado(Passenger array[], int size);
/// @brief recorre la lista de pasajeros y retorna si encontro una posicion del array en ocupado (1)
///
/// @param Passenger[]
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
void CalculateTotalPassages(Passenger listaDePasajeros[], int size);

/// @fn int CargarListaDePasajeros(Passenger[], int)
/// @brief Permite ingresar datos
///
/// @param Passenger[]  la lista de pasajeros
/// @param int la longitud del array
/// @return -1 si no encontro espacio , sino retorna el indice
int CargarListaDePasajeros(Passenger listaDePasajeros[], int size);

//ALTA

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

int printListFlycode(Passenger* list, int length);

/// @fn void printTypePassenger(int)
/// @brief Muestra los tipos de vuelo
///
/// @param int los tipos de vuelos
void printTypePassenger(int);

/// @fn void printStatusFlight(int)
/// @brief Muetra los estados de vuelo
///
/// @param int el estado de vuelo
void printStatusFlight(int statusFlight);


//MODIFICACION

/// @fn int Passenger_estado(Passenger array[], int size);
/// @brief Busca el Id y devuelve la posición del índice del array
///
/// @param Passenger[] la lista de pasajeros
/// @param int la longitud del array
/// @param int el id que se ingreso
/// @return (-1) si no lo encotro , si lo encontro la posición del índice del array
int findPassengerById(Passenger* list, int len,int id);

/// @fn int Modificar(Passenger[], int)
/// @brief Modifica el valor de  un elemento o varios de la estructura
///
/// @param Passenger[] la lista de pasajeros
/// @param int la longitud del array
/// @return (1) Si se realizo una modificacion ,(0) Si se cancelo una modificacion,(-1) si no encontro el id
int Modify(Passenger array[], int size);

//BAJA
/// @fn int removePassenger(Passenger*, int, int)
/// @brief Eliminar un Pasajero por Id (colocar el indicador isEmpty en 1)
/// @param Passenger[] la lista de pasajeros
/// @param int la longitud del array
///param id int
///return int Retorna (-1) si Error [Longitud no válida o puntero NULL o si no puede encontrar un pasajero] - (0) si está bien
int removePassenger(Passenger* list, int len, int id);

/// @fn int printPassenger(Passenger*, int)
/// @brief imprime el contenido de la matriz de pasajeros
///
/// @param Passenger[] la lista de pasajeros
/// @param int la longitud del array
/// @return int Retorna (-1) si Error [Longitud no válida o puntero NULL o si no puede encontrar un pasajero] - (0) si está bien
int printPassenger(Passenger* list, int length);


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
int sortPassengersByCode(Passenger* list, int len, int order);


