#include "LinkedList.h"

#ifndef PARSER_H_
#define PARSER_H_

/**
 * Lee desde el archivo y los agrega a la LinkedList
 * @param pFile puntero a FILE
 * @param pArrayLibreria puntero a la LinkedList
 * @return retorna -1 como ERROR y 0 si la lista que le llega es != de NULL
 */
int parser_LibraryFromText(FILE* pFile , LinkedList* pArrayLibreria);

/**
 * Lee desde el archivo y los agrega a la LinkedList
 * @param pFile puntero a FILE
 * @param pArrayOrigen puntero a la LinkedList
 * @return retorna -1 como ERROR y 0 si la lista que le llega es != de NULL
 */
int parser_OrigenFromText(FILE* pFile , LinkedList* pArrayOrigen);


#endif /* PARSER_H_ */
