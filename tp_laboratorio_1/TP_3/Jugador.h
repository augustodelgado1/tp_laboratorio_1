#include "LinkedList.h"

#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED

#define  ERROR -1
#define  LIBRE 0
#define  OK 1
#define  MAX_NOMBRE 100
#define  MAX_POSICION 30
#define  MAX_NACIONALIDAD 30


typedef struct
{
	int id;
	char nombreCompleto[MAX_NOMBRE];
	int edad;
	char posicion[MAX_POSICION];
	char nacionalidad[MAX_NACIONALIDAD];
	int idSeleccion;
}Jugador;


/// @brief es el contructor de jugadores
/// Permite reservar memoria para una estructura del tipo jugador
/// y retorna el puntero a donde se reservo ese espacio de memoria o NULL si no encontro espacio
///
/// @return el puntero a donde se reservo el espacio de memoria o NULL si no encontro espacio
Jugador* jug_new();

/// @fn Jugador jug_newParametros*(char*, char*, char*, char*, char*, char*)
/// @brief valida y setea los datos en una estructura de tipo jugador y la retorna o  NULL si hubo error en los parametros al setear los datos
///
///
/// @return un jugador con los datos cargados o NULL si no se pudieron cargar los datos
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr);

/// @fn int jug_delete(Jugador*)
/// @brief libera los datos de un jugador y el jugador, verificando que el jugador sea distinto de NULL
///
/// @param Jugador* un puntero al Jugador
void jug_delete(Jugador* unJugador);


/// @fn int jug_setId(Jugador* this,int id);
/// @brief Permite guardar el id en el campo de la estructura
///
/// @param Jugador* el puntero a la estructura del tipo jugador donde se va a guardar ese id
/// @param int donde esta guardado el id
/// @return int [-1] si hubo error en los parametros en los parametros, [1] si se pudo realizar cargar
int jug_setId(Jugador* this,int id);

/// @fn int jug_getId(Jugador* this,int* id);
/// @brief Permite obtener el id , guardado en el campo de la estructura
///
/// @param Jugador* el puntero a la estructura del tipo jugador, que contiene el id a guardar
/// @param int* donde se va guardar
/// @return int [-1] si hubo error en los parametros en los parametros, [1] si se pudo realizar cargar
int jug_getId(Jugador* this,int* id);

/// @fn int jug_SetUnJugador(Jugador*, int, char*, int, char*, char*, int)
/// @brief Permite guardar los datos de  un jugador  y retorna si se pudo guardarlos
///
/// @return int [-1] si hubo error al guardar los dato, [1] si se pudo realizar cargar
int jug_SetUnJugador(Jugador* unJugador,int id,char* nombreCompleto,int edad, char* posicion, char* nacionalidad, int idSelccion);

/// @fn int jug_GetUnJugador(Jugador*, int*, char*, int*, char*, char*, int*)
/// @brief Permite obtener los datos de  un jugador  y retorna si se pudo obtener
///
/// @return int [-1] si hubo error al obtener los dato, [1] si se pudo realizar cargar
int jug_GetUnJugador(Jugador* unJugador,int *id,char* nombreCompleto,int* edad, char* posicion, char* nacionalidad, int *idSelccion);


/// @fn int jug_setNombreCompleto(Jugador* this,char* nombreCompleto);
/// @brief permite guardar el nombre en el campo de la estructura
///
/// @param this el puntero a la estructura del tipo jugador donde se va a guardar ese nombre
/// @param char* donde esta guardado el nombre
/// @return int [-1] si hubo error en los parametros , [1] si se pudo guardar
int jug_setNombreCompleto(Jugador* this,char* nombreCompleto);

/// @fn int Jugador_getNombre(Jugador*, char*)
/// @brief permite obtener el nombre guardado en el campo de la estructura
///
/// @param Jugador* el puntero a la estructura del tipo jugador, que contiene el nombre a guardar
/// @param char*  donde se va guardar
/// @return int [-1] si hubo error en los parametros , [1] si se pudo realizar cargar
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto);


/// @fn int jug_setPosicion(Jugador* this,char* posicion);
/// @brief permite guardar la posicion en el campo de la estructura
///
/// @param Jugador* el puntero a la estructura del tipo jugador donde se va a guardar
/// @param char* donde esta guardado el nombre
/// @return int [-1] si hubo error en los parametros , [1] si se pudo guardar
int jug_setPosicion(Jugador* this,char* posicion);

/// @fn int Jugador_getNombre(Jugador*, char*)
/// @brief permite obtener la posicion guardada en el campo de la estructura
///
/// @param Jugador* el puntero a la estructura del tipo jugador
/// @param char*  donde se va guardar
/// @return int [-1] si hubo error en los parametros , [1] si se pudo realizar cargar
int jug_getPosicion(Jugador* this,char* posicion);

/// @fn int jug_setNacionalidad(Jugador* this,char* nacionalidad);
/// @brief permite guardar la nacionalidad en el campo de la estructura
///
/// @param Jugador* el puntero a la estructura del tipo jugador donde se va a guardar
/// @param char* donde esta guardado el nombre
/// @return int [-1] si hubo error en los parametros , [1] si se pudo guardar
int jug_setNacionalidad(Jugador* this,char* nacionalidad);

/// @fn int jug_getNacionalidad(Jugador* this,char* nacionalidad);
/// @brief permite obtener la nacionalidad guardada en el campo de la estructura
///
/// @param Jugador* el puntero a la estructura del tipo jugador
/// @param char*  donde se va guardar
/// @return int [-1] si hubo error en los parametros , [1] si se pudo realizar cargar
int jug_getNacionalidad(Jugador* this,char* nacionalidad);

/// @fn int jug_setEdad(Jugador* this,int edad);
/// @brief permite guardar la edad en el campo de la estructura
///
/// @param Jugador* el puntero a la estructura del tipo jugador donde se va a guardar
/// @param int donde esta guardado el nombre
/// @return int [-1] si hubo error en los parametros , [1] si se pudo guardar
int jug_setEdad(Jugador* this,int edad);

/// @fn int jug_getEdad(Jugador* this,int* edad);
/// @brief permite obtener la edad guardado en el campo de la estructura
///
/// @param Jugador* el puntero a la estructura del tipo jugador
/// @param int*  donde se va guardar
/// @return int [-1] si hubo error en los parametros , [1] si se pudo realizar cargar
int jug_getEdad(Jugador* this,int* edad);


/// @fn int jug_setNombreCompleto(Jugador* this,char* nombreCompleto);
/// @brief permite guardar el id de seleccion en el campo de la estructura
///
/// @param Jugador* el puntero a la estructura del tipo jugador donde se va a guardar
/// @param int donde esta guardado el nombre
/// @return int [-1] si hubo error en los parametros , [1] si se pudo guardar
int jug_setIdSeleccion(Jugador* this,int idSeleccion);

/// @fn int jug_getSIdSeleccion(Jugador* this,int* idSeleccion);
/// @brief permite obtener el id de seleccion guardado en el campo de la estructura
///
/// @param Jugador* el puntero a la estructura del tipo jugador
/// @param int*  donde se va guardar el id de seleccion
/// @return int [-1] si hubo error en los parametros , [1] si se pudo realizar cargar
int jug_getSIdSeleccion(Jugador* this,int* idSeleccion);

/// @fn int jug_CompararPorNombre(void* unPunteroVoid,void* otroPunteroVoid);
/// @brief compara un nombre de un jugador con el nombre de otro jugador
///
/// @param void* un jugador que se va a comparar
/// @param void* otro jugador que se va a comparar
/// @return int [1] si la primer cadena es mayor, [-1] si la segunda cadena es mayor , [0] si son iguales
int jug_CompararPorNombre(void* unPunteroVoid,void* otroPunteroVoid);

/// @fn int jug_CompararPorEdad(void* unPunteroVoid,void* otroPunteroVoid);
/// @brief compara una edad de un jugador con la edad de otro jugador
///
/// @param void* un jugador que se va a comparar
/// @param void* otro jugador que se va a comparar
/// @return int [1] si la primer edad es mayor, [-1] si la segunda edad es mayor , [0] si son iguales
int jug_CompararPorEdad(void* unPunteroVoid,void* otroPunteroVoid);


/// @fn int jug_CompararPorEdad(void* unPunteroVoid,void* otroPunteroVoid);
/// @brief compara una Nacionalidades de un jugador con la Nacionalidad de otro jugador
///
/// @param void* un jugador que se va a comparar
/// @param void* otro jugador que se va a comparar
/// @return int [1] si la primer cadena es mayor, [-1] si la segunda cadena es mayor , [0] si son iguales
int jug_CompararPorNacionalidad(void* unPunteroVoid,void* otroPunteroVoid);

/// @fn int jug_PedirUnJugador(Jugador*, int)
/// @brief Valida que se ingresen correctamente los datos de un jugador
///
/// @param Jugador* un puntero al jugador
/// @param int el id del jugador
/// @return [1] si se ingresaron correctamnte los datos , [-1] si hubo error en los parametros al ingresar los datos
int jug_PedirUnJugador(Jugador* unJugador,int id);

/// @fn int jug_MostrarUnJugador(Jugador*)
/// @brief Muestra un jugador
///
/// @param Jugador* un puntero al jugador
/// @return int [-1] si hubo error en los parametros , [1] si se pudo realizar cargar
int jug_MostrarUnJugador(Jugador* this);
int  jug_PedirPosicion(char posicion[],int size);
int  jug_PedirNacionalidad(char nacionalidad[],int size);


#endif // jug_H_INCLUDED
