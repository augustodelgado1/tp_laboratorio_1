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

/// @fn Seleccion selec_new*()
/// @brief
///
/// @return
Seleccion* selec_new();
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr);
int selec_delete(Seleccion*);

int selec_GetUnaSeleccion(Seleccion* unaSeleccion,int* id,char* pais,char* confederacion, int* convocados);

int selec_getId(Seleccion* this,int* id);

int selec_getPais(Seleccion* this,char* pais);

int selec_getConfederacion(Seleccion* this,char* confederacion);

int selec_getIsEmpty(Seleccion* this,int* isEmpty);

int selec_setConvocados(Seleccion* this,int convocados);
int selec_getConvocados(Seleccion* this,int* convocados);

int selec_MostrarUnaSeleccion(Seleccion* unaSeleccion);
int selec_CompararPorConfederacion(void* unaPunateroVoid,void* otraPunateroVoid);
int selec_CompararPorId(void* unaPunateroVoid,void* otraPunateroVoid);
int selec_PedirConfederacion(char confederacion[],int size);

#endif // selec_H_INCLUDED
