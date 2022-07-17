/*
  \brief Contiene los parser que se encargan de traer los datos de un archivo a memoria ,
  parseando los datos que contiene

 */
#ifndef PARSER
#define PARSER


/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
    \param FILE* el puntero al archivo
 * \param pArrayListPassenger LinkedList* el puntero a la lista
 * \return int [-1] si vino NULL o [0] si esta bien
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger);


/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param FILE* el puntero al archivo
 * \param pArrayListPassenger LinkedList* el puntero a la lista
 * \return int [-1] si vino NULL o [0] si esta bien
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger);



#endif
