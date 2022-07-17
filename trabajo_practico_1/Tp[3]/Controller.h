/*
 * @brief  Contiene las funciones de un abm que se encargan del manejo de la lista de pasajeros y tambien
 * contiene las funciones que se encargan del manejo de archivos
 *
 *
 */
#ifndef CONTROLLER
#define CONTROLLER

#include "LinkedList.h"
#include "Passenger.h"
#include "Parser.h"


/// @fn int idMaximo(char*)
/// @brief Busca el maximo id y lo retorna
///
/// @param path el archivo donde va a buscar el maximo id
/// @return [-1] si no pudo abrir el arhivo , sino retorna el maxmo id
int idMaximo(char* path);


/// @fn int controller_ObtenerUltimoId(char*, int*)
/// @brief Permite obtener el ultimo id
///
/// @param path el archivo que quiere abrir
/// @param int* donde se va guardar el ultimo id
/// @return [-1] si no pudo abrir el archivo, [0] si pudo abrir el arhivo
int controller_ObtenerUltimoId(char* path, int* id);

/// @fn int controller_IdMaxFile(char*, int)
/// @brief Guarda el ultimo id en un nuevo archivo
///
/// @param path el archivo donde se va guardar el ultimo id
/// @param int el ultimo id
/// @return [-1] si no pudo abrir el archivo, [0] si pudo abrir el arhivo
int controller_IdMaxFile(char* path,int id);


/// @fn int controller_loadFromText(char*, LinkedList*)
/// @brief Permite abrir un archivo (modo texto) y traer los datos a memoria
///
/// @param char* el archivo donde que va abrir
/// @param LinkedList* la lista donde va a guardar los datos
/// @return [-1] si no pudo abrir el archivo, [0] si pudo abrir el arhivo
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);

/// @fn int controller_loadFromBinary(char*, LinkedList*)
/// @brief Permite abrir un archivo (modo binario) y  traer los datos a memoria
///
/// @param char* el archivo donde que va abrir
/// @param LinkedList* la lista donde va a guardar los datos
/// @return [-1] si no pudo abrir el archivo, [0] si pudo abrir el arhivo
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);

/// @fn int controller_addPassenger(LinkedList*)
/// @brief Permite realizar el alta de pasajero validando que se hayan ingresado los datos correctamente
///
/// @param LinkedList* la lista donde va a guardar los datos
/// @return [-1] si no se pudo guardar los datos  , [0] si se pudieron guardar los datos
int controller_addPassenger(LinkedList* pArrayListPassenger);

/// @fn int controller_editPassenger(LinkedList*)
/// @brief Pemite modificar un pasajero de la lista mostrando un menu donde le permite modificar
/// el campo que desee y validando se hayan ingresado los datos correctamente
///
/// @param LinkedList* la lista donde va a guardar los datos
/// @return [-3] si no hay elementos en la lista ,[-2] si no encontro el id ,
/// [0] si cancelo la modificacion,[1] si se modifico el pasajero
int controller_editPassenger(LinkedList* pArrayListPassenger);

/// @fn int controller_removePassenger(LinkedList*)
/// @brief Permite eliminar un pasajero de la lista , validando que exista ese pasajero ingresado
///
///
/// @param LinkedList* la lista donde va a guardar los datos
/// @return [-3] si no hay elementos en la lista ,[-2] si no encontro el id ,
/// [0] si cancelo la baja,[1] si se elimino el pasajero
int controller_removePassenger(LinkedList* pArrayListPassenger);

/*
 * @fn int controller_ListPassenger(LinkedList*)
 * @brief Muetra los elementos de la lista y verifica que el puntero sea distinto de NULL
 * y que haya elementos en la lista
 *
 * @param LinkedList* la lista
 *  return int [-1] si vino NULL o [0] si esta bien
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger);



/** @brief Ordena el array de forma ascendente o decendente , mostrando un menu donde
 * al usuario se la da opcion de ordenar por distintos criterios
 * ej: por id,por nombre,etc;
 *
 * @param pArrayListPassenger LinkedList* el puntero a la lista
 * @return int [-1] si vino NULL o [0] si esta bien
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger);

/// @fn int controller_saveAsText(char*, LinkedList*)
/// @brief Permite Guardar los datos en el archivo (modo texto)
///
/// @param char* el archivo donde se va a guardar los datos
/// @param LinkedList* el puntero a la lista
/// @return int [-2] si no existe la lista  o [-1] si no se pudo abrir el archivo,
/// [0] si se guardaron los datos correctamente
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);


/// @fn int controller_saveAsBinary(char*, LinkedList*)
/// @brief Permite Guardar los datos en el archivo (modo Binario)
///
/// @param char* el archivo donde se va a guardar los datos
/// @param LinkedList* el puntero a la lista
/// @return int [-2] si no existe la lista  o [-1] si no se pudo abrir el archivo,
/// [0] si se guardaron los datos correctamente
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);

/// @fn int PassengerOneAdd(Passenger*)
/// @brief Valida que se ingresen correctamente los datos de un pasajero
///
/// @param Passenger* el puntero al pasajero donde se va a guardar los datos
/// @return int [-1] si no se pudo ingresar correctamente los datos o [0] si esta bien
int PassengerOneAdd(Passenger* Pasajero);

/// @fn int controller_Get_IndexByPassengerId(LinkedList*, int)
/// @brief Busca un id en la lista pasada por parametro y retorna el indice donde lo encontro
///
/// @param LinkedList* el puntero a la lista
/// @param int el id a buscar
/// @return [-1] si no encontro el id o el indice al que pertenece ese id
int controller_Get_IndexByPassengerId(LinkedList* pArrayListPassenger,int id);

#endif
