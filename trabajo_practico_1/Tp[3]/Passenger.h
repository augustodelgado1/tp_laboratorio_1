/*
 *
 */
#include "Menu.h"

#ifndef PASSENGER_H_
#define PASSENGER_H_

#define MAX_NOMBRE 50
#define MAX_TIPO_DE_PASAJERO 15
#define MAX_CODIGO_DE_VUELO 12

typedef struct
{
	int id;
	char nombre[MAX_NOMBRE];
	char apellido[MAX_NOMBRE];
	float precio;
	char tipoPasajero[MAX_TIPO_DE_PASAJERO];
	char statusFlight[MAX_TIPO_DE_PASAJERO];
	char codigoVuelo[MAX_CODIGO_DE_VUELO];

}Passenger;

/// @fn Passenger Passenger_new*()
/// @brief es el contructor de pasajeros
/// Permite reservar memoria para una estructura del tipo pasajero
/// y retorna el puntero a donde se reservo ese espacio de memoria o NULL si no encontro espacio
///
/// @return el puntero a donde se reservo el espacio de memoria o NULL si no encontro espacio
Passenger* Passenger_new();

/// @fn Passenger Passenger_newParametros*(char*, char*, char*, char*, char*, char*, char*)
/// @brief valida y setea los datos en una estructura de tipo persona
/// y la retorna o retorna NULL si no se pudieron cargar los datos
///
/// @return un pasajero con los datos cargados o NULL si no se pudieron cargar los datos
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellido,char* precio,
		char* tipoPasajeroStr,char*codigoVuelo,char* statusFlight);

/// @fn int Passenger_PedirTipoVuelo(char*, int)
/// @brief Permite pedir el tipo De Vuelo mostrando los distintos tipo de vuelos y validando que
/// se ingrese un tipo de vuelo valido
///
/// @param char* Donde se va a guardar el tipo de vuelo ingresado
/// @param int el tamaño del array
/// @return int [-1] si hubo error , [0] si se pudo realizar cargar
int Passenger_PedirTipoVuelo(char* tipoVuelo,int size);

/// @fn int Passenger_PedirEstadoDeVuelo(char*, int)
/// @brief Permite pedir el estado De Vuelo mostrando los distintos estados de vuelos y validando que
/// se ingrese un estado de vuelo valido
///
/// @param char* Donde se va a guardar el estado de vuelo ingresado
/// @param int el tamaño del array
/// @return int [-1] si hubo error , [0] si se pudo realizar cargar
int Passenger_PedirEstadoDeVuelo(char* estadoDeVuelo,int size);

/// @fn void Passenger_delete(Passenger*)
/// @brief borra un pasajero
///
/// @param int [-1] si hubo error , [0] si se pudo realizar cargar
int Passenger_delete(Passenger*);

/// @fn int Passenger_setId(Passenger*, int)
/// @brief Permite guardar el id en el campo de la estructura
///
/// @param Passenger* el puntero a la estructura del tipo pasajero donde se va a guardar ese id
/// @param int donde esta guardado el id
/// @return int [-1] si hubo error , [0] si se pudo realizar cargar
int Passenger_setId(Passenger* this,int id);

/// @fn int Passenger_getId(Passenger*, int*)
/// @brief Permite obtener el id , guardado en el campo de la estructura
///
/// @param Passenger* el puntero a la estructura del tipo pasajero, que contiene el id a guardar
/// @param int* donde se va guardar
/// @return int [-1] si hubo error , [0] si se pudo realizar cargar
int Passenger_getId(Passenger* this,int* id);


/// @fn int PassengerNew(int*, char*, char*, float*, char*, char*, char*)
/// @brief Permite cargar un pasajero y retorna si se pudo cargar
///
/// @return int [-1] si hubo error , [0] si se pudo realizar cargar
int PassengerNew(int* id,char* nombre ,char* apellido,float* precio,char* codigoVuelo
		,char* statusFlight,char* tipoPasajero);


/// @fn int Passenger_setNombre(Passenger*, char*)
/// @brief permite guardar el nombre en el campo de la estructura
///
/// @param this el puntero a la estructura del tipo pasajero donde se va a guardar ese nombre
/// @param char* donde esta guardado el nombre
/// @return int [-1] si hubo error , [0] si se pudo guardar
int Passenger_setNombre(Passenger* this,char* nombre);

/// @fn int Passenger_getNombre(Passenger*, char*)
/// @brief permite obtener el nombre guardado en el campo de la estructura
///
/// @param Passenger* el puntero a la estructura del tipo pasajero, que contiene el nombre a guardar
/// @param char*  donde se va guardar
/// @return int [-1] si hubo error , [0] si se pudo realizar cargar
int Passenger_getNombre(Passenger* this,char* nombre);


/// @fn int Passenger_setApellido(Passenger*, char*)
/// @brief permite guardar el nombre en el campo de la estructura
///
/// @param Passenger* el puntero a la estructura del tipo pasajero
/// @param char* el string que contiene el apellido que se va a guardar en el campo de la estructura
/// @return int [-1] si hubo error , [0] si se pudo realizar cargar
int Passenger_setApellido(Passenger* this,char* apellido);

/// @fn int Passenger_getApellido(Passenger*, char*)
/// @brief permite obtener el apellido guardado en el campo de la estructura
///
/// @param Passenger* el puntero a la estructura del tipo pasajero
/// @param char* donde se va a guardar el apellido
/// @return int [-1] si hubo error , [0] si se pudo realizar cargar
int Passenger_getApellido(Passenger* this,char* apellido);


/// @fn int Passenger_setApellido(Passenger*, char*)
/// @brief permite guardar el nombre en el campo de la estructura
///
/// @param Passenger* el puntero a la estructura del tipo pasajero
/// @param char* el string que contiene el nombre que se va a guardar en el campo de la estructura
/// @return int [-1] si hubo error , [0] si se pudo realizar cargar
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);

/// @fn int Passenger_getCodigoVuelo(Passenger*, char*)
/// @brief permite obtener el codigoVuelo guardado en el campo de la estructura
///
/// @param Passenger* el puntero a la estructura del tipo pasajero
/// @param char* donde se va a guardar
/// @return int [-1] si hubo error , [0] si se pudo realizar cargar
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);


/// @fn int Passenger_getNombre(Passenger*, char*)
/// @brief permite guardar el tipo de pasajero en el campo de la estructura
///
/// @param Passenger* el puntero a la estructura del tipo pasajero
/// @param char*  el string que contiene el nombre que se va a guardar en el campo de la estructura
/// @return int [-1] si hubo error , [0] si se pudo guardar
int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);

/// @fn int Passenger_getNombre(Passenger*, char*)
/// @brief permite obtener el tipoPasajero guardado en el campo de la estructura
///
/// @param Passenger* el puntero a la estructura del tipo pasajero
/// @param char* donde se va a guardar el tipoPasajero
/// @return int [-1] si hubo error , [0] si se pudo guardar
int Passenger_getTipoPasajero(Passenger* this,char*tipoPasajero);


/// @fn int Passenger_setApellido(Passenger*, char*)
/// @brief permite guardar el precio en el campo de la estructura
///
/// @param Passenger* el puntero a la estructura del tipo pasajero
/// @param float*  el flotante que contiene el precio que se va a guardar en el campo de la estructura
/// @return int [-1] si hubo error , [0] si se pudo realizar cargar
int Passenger_setPrecio(Passenger* this,float precio);

/// @fn int Passenger_getNombre(Passenger*, char*)
/// @brief permite obtener el precio guardado en el campo de la estructura
///
/// @param Passenger* el puntero a la estructura del tipo pasajero
/// @param float* donde se va a guardar el precio
/// @return int [-1] si hubo error , [0] si se pudo guardar
int Passenger_getPrecio(Passenger* this,float* precio);


/// @fn int Passenger_setApellido(Passenger*, char*)
/// @brief Permite guardar el string en la entidad verificando que sea distinto de NULL
///
/// @param Passenger* el puntero a la estructura del tipo pasajero
/// @param char*
/// @return int [-1] si hubo error , [0] si se pudo realizar cargar
int Passenger_setStatusFlight(Passenger* ,char* );

/// @fn int Passenger_getNombre(Passenger*, char*)
/// @brief permite guardar el estado de vuelo en el campo de la estructura
///
/// @param Passenger* el puntero a la estructura del tipo pasajero
/// @param char* donde se va a guardar el estado de vuelo
/// @return int [-1] si hubo error , [0] si se pudo guardar
int Passenger_getStatusFlight(Passenger* ,char*);

/// @fn int Passenger_Verificar_Gets(Passenger*, int*, char*, char*, float*, char*, char*, char*)
/// @brief Recibe una lista y permite obtener los campos guardados en el campo de la estructura ,
/// validando que se hayan podido guardar
///
/// @return int [-1] si hubo error , [0] si se pudo guardar
int Passenger_Verificar_Gets(Passenger*unPasajero,int* id,char* nombre ,char* apellido,float* precio,char* codigoVuelo
,char* statusFlight,char* tipoPasajero);

/// @fn int PassengerNewWithParameters(Passenger*, int, char*, char*, float, char*, char*, char*)
/// @brief permite guardar en los campos de la estructura el contenido de los parametros
/// , verificando si se pudo cargar o no.
/// si no se pudo cargar borra el pasajero
///
/// @return int [-1] si hubo error , [0] si se pudo guardar
int PassengerNewWithParameters(Passenger*unPasajero,int id,char* nombre ,char* apellido,float precio,char* codigoVuelo
		,char* statusFlight,char* tipoPasajero);

/// @fn int PassengerCompareByName(void*, void*)
/// @brief compara el campo nombre de la estructura
///
/// @param void*
/// @param void*
/// @return int [1] si la primer cadena es mayor, [-1] si la segunda cadena es mayor , [0] si son iguales
int PassengerCompareByName(void*,void*);

/// @fn int PassengerCompareById(void*, void*)
/// @brief compara el campo id de la estructura
///
/// @param void*
/// @param void*
/// @return int [1] si la primer cadena es mayor, [-1] si la segunda cadena es mayor , [0] si son iguales
int PassengerCompareById(void*,void*);

/// @fn int PassengerCompareByName(void*, void*)
/// @brief compara el campo nombre de la estructura
///
/// @param void*
/// @param void*
/// @return int [1] si la primer cadena es mayor, [-1] si la segunda cadena es mayor , [0] si son iguales
int PassengerCompareByLastName(void* p1,void* p2);

/// @fn int PassengerCompareByPrecio(void* p1,void* p2);
/// @brief compara el campo Precio de la estructura
///
/// @param void*
/// @param void*
/// @return int [1] si la primer cadena es mayor, [-1] si la segunda cadena es mayor , [0] si son iguales
int PassengerCompareByPrecio(void* p1,void* p2);

/// @fn void PassengerPrintOne(Passenger*)
/// @brief Muestra un pasajero
///
/// @param UnPasajero
void PassengerPrintOne(Passenger* UnPasajero);


#endif /* PASSENGER_H_ */
