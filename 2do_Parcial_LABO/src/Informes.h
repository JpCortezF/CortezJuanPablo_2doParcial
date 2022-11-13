#include "LinkedList.h"
#include "Libreria.h"

#ifndef INFORMES_H_
#define INFORMES_H_

/**
 * Cabecera de los campos de la estructura eCompras
 */
void printHeadboar(void);

/**
 * Imprime una compra de la estructura eCompras
 * @param aLibrary puntero a la estructura eCompras
 * @param pArrayOrigen puntero a la lista LinkedList
 */
void printOneLibrary(eCompras* aLibrary, LinkedList* pArrayOrigen);

/**
 * Imprime la lista de compras de la estructura eCompras
 * @param pArrayLibrary puntero a la lista LinkedList
 * @param pArrayOrigen puntero a la lista LinkedList
 * @return retorna -1 si la lista que llega por parametro es NULL y 0 como BIEN
 */
int printfListLibrary(LinkedList* pArrayLibrary,LinkedList* pArrayOrigen);

#endif /* INFORMES_H_ */
