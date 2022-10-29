#ifndef EFIGURITAS_H_
#define EFIGURITAS_H_

#include "Menu.h"

#define  ERROR -1
#define  LIBRE 0
#define  OCUPADO 1
#define  OK 1
#define  MAX_NOMBRE 40
#define  MAX_EQUIPOS 10
#define  MAX_POSICION 20
#define  MAX_NOMBRE_CONFEDERACION 50
#define MAX_JUGADORES 3000
#define MAX_CONFEDERACIONES 10
#define  MAX_AUXILIAR 50
#define  MAX_REGION 50
#define  MAX_DESCRIPCION 50

typedef struct
{
	int id;
	char nombre[MAX_REGION];
	char region[MAX_REGION];
	int anioCreacion;
	short isEmpty;
}eConfederacion;

typedef struct
{
    int id;
    int contador;
    int acumulador;
    float porcentaje;
    int estado;
}eAuxiliar;

typedef struct
{
    int id;
    char nombre[MAX_NOMBRE];
    char posicion[MAX_POSICION];
    short numeroCamiseta;
	int idConfederacion; //(char[])
	float salario; //(float)
	short aniosContrato; //(float)
	short isEmpty;
}eJugador;

/// @fn int CargarForzadaDeJugador(eJugador[], int, int, char[], char[], short, int, float, short)
/// @brief realiza una carga forzada de un Jugador validando que los campos sean correctos y que haya espacio en la lista
///
/// @param eJugador[] el array de jugadores
/// @param int el tamanio del array
/// @param int el id de jugador
/// @param char[] nombre  del jugador
/// @param char[] posicion del jugador
/// @param short numeroCamiseta del jugador
/// @param int idConfederacion del jugador
/// @param float salario del jugador
/// @param short aniosContrato del jugador
/// @return [-1] si no pudo realizar la carga forzada , [1] si pudo realizar la carga forzada
int CargarForzadaDeJugador(eJugador listaDeJugadores[],int sizeDeJugadores,int id,char nombre[],char posicion[],short numeroCamiseta,int idConfederacion,float salario,short aniosContrato);

/// @fn int BuscarUnJugadorPorId(eJugador[], int, int)
/// @brief Busca un id determinado en el array de jugadores
///
/// @param eJugador[] el array de jugadores
/// @param int el tamanio del array
/// @param int el id a buscar en la lista
/// @return [-1] si no encontro el id , [el indice]  donde encontro el id
int BuscarUnJugadorPorId(eJugador listaDeJugador[], int size,int id);

/// @fn int OrdenarListaDeJugadoresPorId(eJugador[], int)
/// @brief Ordena la lista de jugadores Por Salario
///
/// @param eJugador[] el array de jugadores
/// @param int el tamanio del array
/// @return [-1] si Hubo ERROR, [1] si esta OK
int OrdenarListaDeJugadoresPorSalario(eJugador listaDeJugadores[],int sizeDeJugadores);

/// @fn int OrdenarListaDeJugadoresPorId(eJugador[], int)
/// @brief Ordena la lista de jugadores por id
///
/// @param eJugador[] el array de jugadores
/// @param int el tamanio del array
/// @return [-1] si Hubo ERROR, [1] si esta OK
int OrdenarListaDeJugadoresPorId(eJugador listaDeJugador[],int size);

/// @fn int InicializarListaDeJugadores(eJugador[], int)
/// @brief Inicializa el campo isEmpty del array de jugadores en 0
///
/// @param eJugador[] el array de jugadores
/// @param int el tamanio del array
/// @return [-1] si Hubo ERROR, [1] si esta OK
int InicializarListaDeJugadores(eJugador listaDeJugadores[], int size);

/// @fn int BuscarLibre(eJugador[], int)
/// @brief Busca un espacio libre en el array de jugadores
///
/// @param eJugador[] el array de jugadores
/// @param int  el tamanio del array de jugadores
/// @return [-1] si no encotro espacio,el [indice] donde encotro el espacio
int BuscarLibre(eJugador [],int );

/// @fn int PedirPosicion(char[], int)
/// @brief Permite pedir una posicion Validando que se ingrese una opcion valida
///
/// @param char[] el string
/// @param int el tamanio del string
/// @return  [-1] si Hubo ERROR, [1] si esta OK
int PedirPosicion(char posicion[],int size);

/// @fn int MostrarListaDeJugadoresDeUnaConfederacion(eJugador[], int, int)
/// @brief Mustra los jugadores que forman parte de una confederacion determinada
///
/// @param eJugador[] el array de jugadores
/// @param int  el tamanio del array de jugadores
/// @param int el id de confederacion a buscar
/// @return [-1] si Hubo ERROR, [1] si esta OK
int  MostrarListaDeJugadoresDeUnaConfederacion(eJugador listaDeJugadores[],int sizeDeJugadores,int idDeConfederacion);

/// @fn int AcumularAniosContratoDeUnaConfederacion(eJugador[], int, int)
/// @brief Calcula la cantidad total de anios de contratos por cada confederacion
///
/// @param eJugador[] el array de jugadores
/// @param int  el tamanio del array de jugadores
/// @param int el id de confederacion a calcular
/// @return la cantidad total de anios de contratos por cada confederacion
int AcumularAniosContratoDeUnaConfederacion(eJugador listaDeJugadores[],int sizeDeJugadores,int idDeConfederacion);

/// @fn int CantidadDeJugadoresCargados(eJugador[], int)
/// @brief Cuenta la cantidad de jugadores que estan cargados en el array de jugadores
///
/// @param eJugador[] el array de jugadores
/// @param int  el tamanio del array de jugadores
/// @return la cantidad de jugadores que estan cargados
int CantidadDeJugadoresCargados(eJugador listaDeJugadores[],int sizeDeJugadores);

/// @fn float CalcularTotalDeSalario(eJugador[], int)
/// @brief Calcula la cantidad total de salario del el array de jugadores
///
/// @param eJugador[] el array de jugadores
/// @param int  el tamanio del array de jugadores
/// @return la cantidad total de salario del el array de jugadores
float CalcularTotalDeSalario(eJugador listaDeJugadores[],int sizeDeJugadores);

/// @fn int ContarJugadoresDeUnaConfederacion(eJugador[], int, int)
/// @brief Cuenta la cantidad de jugadores que forman parte de una confederacion determinada
///
/// @param eJugador[] el array de jugadores
/// @param int el tamanio del array
/// @param int el id de la confederacion a contar
/// @return la cantidad de jugadores que forman parte de la confederacion pasada por parametro
int ContarJugadoresDeUnaConfederacion(eJugador listaDeJugadores[],int sizeDeJugadores,int idDeConfederacion);

/// @fn int ObtenerIDJugador()
/// @brief Permite obtener el id de forma automatica
///
/// @return el incremnto del id
int ObtenerIDJugador();


#endif /* EFIGURITAS_H_ */
