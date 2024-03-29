
#include "Nexo.h"
/// @fn int controller_cargarJugadoresDesdeTexto(char*, LinkedList*)
/// @brief Carga los datos de los jugadores desde el archivo generado en modo texto
///
/// @param char* el nombre del archivo
/// @param LinkedList* la lista de jugadores
/// @return [-1] si hubo error en los parametros, [1] si esta ok
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador);


/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
/// @param char* el nombre del archivo
/// @param LinkedList* la lista de jugadores
/// @return [-1] si hubo error en los parametros, [1] si esta ok
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador);

/// @fn int controller_agregarJugador(LinkedList*)
/// @brief valida que se igresen correctamente los datos de la estructura jugador y agreaga el elemento a la lista de jugadores
///
/// @param  LinkedList* la lista de jugadores
/// @return [-1] si hubo error , [1] si esta ok
int controller_agregarJugador(LinkedList* pArrayListJugador);

/// @fn int controller_editarJugador(LinkedList*)
/// @brief Pemite modificar un jugador  de la lista ,mostrando un menu donde le permite modificar
/// el dato que desee y validando se hayan ingresado los datos correctamente
///
/// @param  LinkedList* la lista de jugadores
/// @return [-2] sino se realizo ningun cambio,[-1] si hubo error , [el Indice] del jugador que se edito
int controller_editarJugador(LinkedList* pArrayListJugador);

/// @fn int controller_BuscarIdDeJugador(LinkedList*, int)
/// @brief  Busca si el id pasado por parametro pertenece a un jugador
///
/// @param LinkedList* la lista de jugadores
/// @param int el id a buscar
/// @return [-1] si no lo encontro, sino el [Indice] del jugador que contiene ese id
int controller_BuscarIdDeJugador(LinkedList* pArrayListJugador,int idABuscar);

/// @fn int controller_removerJugador(LinkedList*)
/// @brief Borra un jugador de la lista de jugadores
///
/// @param LinkedList* la lista de jugadores
/// @return  [-1] si hubo error , [el Indice] del jugador que se borro
int controller_removerJugador(LinkedList* pArrayListJugador);

/// @fn int controller_MenuDeListados(LinkedList*, LinkedList*)
/// @brief permite elegir una opcion de un Menu de lista  y Imprime la lista que se eligio
///
/// @param LinkedList* la lista de jugadores
/// @param  LinkedList* la lista de Selecciones
/// @return [-1] si hubo error en los parametos , [1] si esta ok
int controller_MenuDeListados(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion);

/// @fn int controller_listarJugadores(LinkedList*)
/// @brief lista los jugadores que no estan convocados
///
/// @param LinkedList* la lista de jugadores
/// @return [-1] si hubo error en los parametos , [1] si esta ok
int controller_listarJugadores(LinkedList* pArrayListJugador);

/// @fn int controller_ordenarJugadores(LinkedList*)
/// @brief  Permite ordenar la lista de jugadores
///
/// @param  LinkedList* la lista de jugadores
/// @return [-1] si hubo error en los parametos , [1] si esta ok
int controller_ordenarJugadores(LinkedList* pArrayListJugador);

/// @fn int controller_guardarJugadoresModoTexto(char*, LinkedList*)
/// @brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
///
/// @param char* el nombre del archivo
/// @param LinkedList* la lista de jugadores
/// @return [-1] si hubo error en los parametros, [1] si esta ok
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador);

/// @fn int controller_guardarJugadoresModoBinario(char*, LinkedList*)
/// @brief Guarda los datos de los jugadores en el archivo binario.
///
/// @param char* el nombre del archivo
/// @param LinkedList* la lista de jugadores
/// @return [-1] si hubo error en los parametros, [1] si esta ok
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador);

/// @fn int controller_cargarSeleccionesDesdeTexto(char*, LinkedList*)
/// @brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
///
/// @param char* el nombre del archivo
/// @param LinkedList* la lista de selecciones
/// @return [-1] si hubo error en los parametros, [1] si esta ok
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion);

/// @fn int controller_editarSeleccion(LinkedList* pArrayListSeleccion);
/// @brief Permite ingresar un id validando que ese id pertenezca a la lista pasada por parametro
///
/// @param  LinkedList* la lista de selecciones
/// @return [-1] si hubo error en el ingreseo de datos, sino el [indice] donde se encuentra el id
int controller_editarSeleccion(LinkedList* pArrayListSeleccion);

/// @fn int controller_CantidadJugadoresConvocadosPorSeleccion(LinkedList*, LinkedList*)
/// @brief reccore la lista de selecciones y cuenta cuantos jugadores estan convocados en cada seleccion y guarda la cantidad en el
/// campo convocados de la estructura selecciones
///
/// @param LinkedList* la lista de selecciones
/// @param  LinkedList* la lista de jugadores
/// @return [-1] si hubo error en los parametros, [1] si esta ok
int controller_CantidadJugadoresConvocadosPorSeleccion(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador);

/// @fn int controller_CantdadJugadoresConcadosDeUnaSeleccion(LinkedList*, int)
/// @brief reccore la lista de jugadores y cuenta cuantos jugadores coiciden con el id de seleccion pasado por parametro
///  y devuelve la cantidad
///
/// @param  LinkedList* la lista de jugadores
/// @param int el id de seleccion a compar
/// @return int la cantidad de jugadores que conto
int controller_CantdadJugadoresConcadosDeUnaSeleccion(LinkedList* pArrayListJugador,int idSeleccion);

/// @fn LinkedList controller_FiltraListaDeJugadores*(LinkedList*, LinkedList*, char[])
/// @brief  crea un nuevo linkedlist y agrega los jugadores convocados de una confederación en concreto.
///
//// @param  LinkedList* la lista de jugadores
/// @param LinkedList* la lista de selecciones
/// @param char[] confederacion a comparar
/// @return [-1] si hubo error en los parametros, [1] si esta ok
LinkedList*  controller_FiltraListaDeJugadores(LinkedList* pArrayListJugador,LinkedList* pArrayListSelecciones,char confederacionIngresada[]);

/// @fn int controller_listarSelecciones(LinkedList*)
/// @brief Muestra la lista de selecciones
///
/// @param LinkedList* la lista de selecciones
/// @return [-2] si hubo error en los parametros ,[-1] si hubo error al intentar mostrar un elemento, [1] si esta ok
int controller_listarSelecciones(LinkedList* pArrayListSeleccion);

/// @fn int controller_ordenarSelecciones(LinkedList*)
/// @brief Ordena la lista de selecciones por confederacion
///
/// @param  LinkedList* la lista de selecciones
/// @return [-1] si hubo error en los parametros, [1] si esta ok
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion);

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
/// @param char* el nombre del archivo
/// @param LinkedList* la lista de selecciones
/// @return [-1] si hubo error en los parametros, [1] si esta ok
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion);

/// @fn int controller_ConvocarJugador(LinkedList*, LinkedList*)
/// @brief Permite convocar un jugador validando que se igresaron correctamente los datos
///
/// @param LinkedList* la lista de selecciones
/// @param LinkedList* la lista de jugadores
/// @return [-1] si hubo error en el ingreseo de datos,[-2] si se cancelo la convocacion, [indice] si esta ok
int controller_ConvocarJugador(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador );

/// @fn int controller_MenuDeConvocarJugador(LinkedList*, LinkedList*)
/// @brief Muestra un menu donde le permite convocar o desconvocar un jugador de la lista
///
/// @param LinkedList* la lista de selecciones
/// @param  LinkedList* la lista de jugadores
/// @return [-1] si hubo error en los parametros, [1] si esta ok
int controller_MenuDeConvocarJugador(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador );

/// @fn int controller_CantidadDeJugadoresConvocados(LinkedList*, LinkedList*)
/// @brief Cuenta la cantidad de jugadores convocados que hay en la lista y devuelve la cantidad
///
/// @param LinkedList* la lista de jugadores
/// @param  LinkedList* la lista de selecciones
/// @return [-1] si hubo error en los parametros, sino devuelve la cantidad de convocados que conto
int controller_CantidadDeJugadoresConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/// @fn int controller_DesconvocarJugador(LinkedList*, LinkedList*)
/// @brief Permite desconvocar a un jugador , validando que se ingrese un jugador que este convocado
///
/// @param LinkedList* la lista de selecciones
/// @param LinkedList* la lista de jugadores
/// @return [-1] si hubo error en el ingreseo de datos,[-2] si se cancelo la convocacion, [indice] si esta ok
int controller_DesconvocarJugador(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador );

/// @fn int controller_GetIdJugador(LinkedList*, char[], char[], int)
/// @brief Permite ingresar un id validando que ese id pertenezca a la lista pasada por parametro
///
/// @param  LinkedList* la lista de jugadores
/// @param char[] el mensaje que indica que debe ingresar
/// @param char[] el mensaje que indica que debe ingresar un numero valido dentro del rango pedido
/// @param int cantidad de reitentos
/// @return [-1] si hubo error en el ingreseo de datos, sino el indice donde se encuentra el id
int controller_GetIdJugador(LinkedList* pArrayListJugador,char mensaje[],char mensajeError[],int reitentos);

/// @fn int controller_ObtenerUltimoId(char*)
/// @brief Lee un numero del archivo y lo retorna
///
/// @param char* el nombre del archivo
/// @param LinkedList* la lista de jugadores
/// @return  [-1] si hubo error en los parametros, el id que leyo del archivo
int controller_ObtenerUltimoId(char* path);

///	@brief Busca el id maximo en el arhivo csv de jugadores y lo devuelve
/// @param char* el nombre del archivo
/// @return [-1] si hubo error en los parametros, [id maximo] si esta ok
int controller_BuscarIdMaximo(char* path);

/// @fn int controller_GuardarUltimoId(char*, int)
/// @brief Guarda el un archivo el id pasado por parametro
///
/// @param char* el nombre del archivo donde se va a guardar el id
/// @param int el id que se va a guardar
/// @return [-1] si hubo error en los parametros ,[1] si esta ok
int controller_GuardarUltimoId(char* path,int id);

/// @fn int controller_listarConvocados(LinkedList*, LinkedList*)
/// @brief  Muetra todos los jugadores convocados de la lista , verifica que el puntero sea distinto de NULL  y que haya elementos en la lista
///
///* @param LinkedList* la lista de jugadores
/// @param LinkedList* la lista de selecciones
/// @return int [-1] si vino NULL o [0] si esta bien
int controller_listarConvocados( LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);


/// @fn int controller_MostrarListaDeJugadores(LinkedList*, LinkedList*)
/// @brief Muetra todos  los elementos de la lista y verifica que el puntero sea distinto de NULL
///* y que haya elementos en la lista
/// *
///* @param LinkedList* la lista de jugadores
/// @param LinkedList* la lista de selecciones
/// @return int [-1] si vino NULL o [0] si esta bien
int controller_MostrarListaDeJugadores( LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/// @fn int controller_BuscarIdDeSeleccion(LinkedList* pArraySeleccion,int idABuscar);
/// @brief Busca un id en la lista pasada por parametro y retorna el indice donde lo encontro
///
/// @param LinkedList* el puntero a la lista
/// @param int el id a buscar
/// @return [-1] si no encontro el id o el indice al que pertenece ese id
int controller_BuscarIdDeSeleccion(LinkedList* pArraySeleccion,int idABuscar);


/// @fn int controller_MostrarSeleccionDeJugador(Jugador*, LinkedList*)
/// @brief Muestra un jugador con su seleccion
///
/// @param Jugador* el jugador a listar con su seleccion
/// @param LinkedList* el puntero a la lista de selecciones
/// @return [-1] si no pudo mostrar el jugador , [1] si pudo mostrar el jugador
int controller_MostrarSeleccionDeJugador(Jugador* unJugador, LinkedList* pArrayListSeleccion);

/** @brief Ordena la listas de forma ascendente o decendente , mostrando un menu donde
 * al usuario se la da opcion de ordenar por distintos criterios
 *
 * @param LinkedList*  el puntero a la lista de jugadores
 * @param LinkedList*  el puntero a la lista de selecciones
 * @return int [-1] si vino NULL o [0] si esta bien
 */
int controller_ordenarListas(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion);


