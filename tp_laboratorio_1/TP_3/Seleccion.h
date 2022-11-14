#include "LinkedList.h"

#ifndef selec_H_INCLUDED
#define selec_H_INCLUDED

#define  MAX_PAIS 30
#define  MAX_CONFEDERACION 30

typedef struct
{
	int id;
	char pais[MAX_PAIS];
	char confederacion[MAX_CONFEDERACION];
	int convocados;
}Seleccion;

/// @brief es el contructor de selecciones
/// Permite reservar memoria para una estructura del tipo selecciones
/// y retorna el puntero a donde se reservo ese espacio de memoria o NULL si no encontro espacio
///
/// @return el puntero a donde se reservo el espacio de memoria o NULL si no encontro espacio
Seleccion* selec_new();

/// @fn Seleccion selec_newParametros*(char*, char*, char*, char*)
/// @brief valida y setea los datos en una estructura de tipo seleccion y la retorna o  NULL si hubo error en los parametros al setear los datos
///
/// @return Seleccion* una Seleccion con los datos cargados o NULL si no se pudieron cargar los datos
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr);

/// @fn void selec_delete(Seleccion*);
/// @brief libera una seleccion,verificando que la seleccion sea distinto de NULL
///
/// @param Seleccion* un puntero ala seleccion
void selec_delete(Seleccion*);

/// @fn int selec_GetUnaSeleccion(Seleccion*, int*, char*, char*, int*)
/// @brief Permite obtener una todos los datos que guarda la selecion pasada por parametro
///
/// @return [-1] si no pudo obtener los datos, [1] si pudo obtener los datos
int selec_GetUnaSeleccion(Seleccion* unaSeleccion,int* id,char* pais,char* confederacion, int* convocados);

/// @fn int selec_getId(Seleccion*, int*)
/// @brief permite obtener un id guardado en el campo de la estructura
///
/// @param Seleccion* el puntero a la estructura del tipo seleccion
/// @param int*  donde se va guardar el id de seleccion
/// @return int [-1] si hubo error en los parametros , [1] si se pudo realizar cargar
int selec_getId(Seleccion* this,int* id);

/// @fn int jug_getSIdSeleccion(Seleccion* this,int* idSeleccion);
/// @brief permite obtener un pais guardado en el campo de la estructura
///
/// @param Seleccion* el puntero a la estructura del tipo seleccion
/// @param int*  donde se va guardar el id de seleccion
/// @return int [-1] si hubo error en los parametros , [1] si se pudo realizar cargar
int selec_getPais(Seleccion* this,char* pais);

/// @fn int jug_getSIdSeleccion(Seleccion* this,int* idSeleccion);
/// @brief permite obtener una confederacion guardado en el campo de la estructura
///
/// @param Seleccion* el puntero a la estructura del tipo seleccion
/// @param int*  donde se va guardar el id de seleccion
/// @return int [-1] si hubo error en los parametros , [1] si se pudo realizar cargar
int selec_getConfederacion(Seleccion* this,char* confederacion);

/// @fn int selec_setConvocados(Seleccion*, int)
/// @brief Permite guardar en el campo convocados de una seleccion pasada por parametro  ,el entero pasado por parametro
///
/// @param Seleccion* el puntero a la estructura del tipo seleccion
/// @param int*  donde se va guardar el id de seleccion
/// @return int [-1] si hubo error en los parametros , [1] si se pudo realizar cargar
int selec_setConvocados(Seleccion* this,int convocados);

/// @fn int selec_getConvocados(Seleccion*, int*)
/// @brief Permite obtener lo que guarda la seleccion pasada por parametro en el campo convocados
///
/// @param Seleccion* el puntero a la estructura del tipo seleccion
/// @param int*  donde se va guardar el id de seleccion
/// @return int [-1] si hubo error en los parametros , [1] si se pudo realizar cargar
int selec_getConvocados(Seleccion* this,int* convocados);

/// @fn int selec_MostrarUnaSeleccion(Seleccion*)
/// @brief Muestra una seleccion
///
/// @param Seleccion* un puntero a la seleccion
/// @return [-1] si hubo error al intentar mostrar algun dato
int selec_MostrarUnaSeleccion(Seleccion* unaSeleccion);

/// @fn int selec_CompararPorConfederacion(void*, void*)
/// @brief Compara una confederacion con otra confederacion
///
/// @param void* una seleccion
/// @param void* otra seleccion
/// @return int [1] si la primer cadena es mayor, [-1] si la segunda cadena es mayor , [0] si son iguales
int selec_CompararPorConfederacion(void* unaPunateroVoid,void* otraPunateroVoid);

/// @fn int selec_CompararPorId(void*, void*)
/// @brief Compara un id con otro id
///
/// @param void* una seleccion
/// @param void* otra seleccion
/// @return int [1] si la primer id es mayor, [-1] si la segundo id es mayor , [0] si son iguales
int selec_CompararPorId(void* unaPunateroVoid,void* otraPunateroVoid);

/// @fn int  selec_PedirConfederacion(char confederacion[],int size);
/// @brief Permite igresar una confederacion y la guarda dentro de la cadena pasada por parametro
///
/// @param char* donde se va a guardar
/// @param int el tamanio de la cadena
/// @return  int [1] si se ingreso correctamente , [-1] si hubo error al igresar el dato
int selec_PedirConfederacion(char confederacion[],int size);

#endif // selec_H_INCLUDED
