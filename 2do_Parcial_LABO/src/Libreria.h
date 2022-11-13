#include "LinkedList.h"

#ifndef LIBRERIA_H_
#define LIBRERIA_H_

typedef struct
{
	int buyCode;
	char description[30];
	int idOrigen;
	float unitaryPrice;
	int amount;
	float totalPurchase;
}eCompras;

/**
 * reserva espacio de memoria para UNA compra
 * @return
 */
eCompras* lib_new();

/**
 * Recibe parametros char y los setters se encargan de castearlos al tipo que corresponda
 * @param buyCodeStr de tipo char donde se van a settear el buyCode
 * @param description de tipo char donde se van a settear el description
 * @param idOrigenStr de tipo char donde se van a settear el idOrigen
 * @param unitaryPriceStr de tipo char donde se van a settear el unitaryPrice
 * @param amountStr de tipo char donde se van a settear el amount
 * @param totalPurchase de tipo char donde se van a settear el totalPurchase
 * @return retorna -1 si no pudo reservar espacio y 0 si funciono correctamente
 */
eCompras* lib_newParameters(char* buyCodeStr,char* description,char* idOrigenStr,char* unitaryPriceStr,char* amountStr,char* totalPurchase);

/**
 * Le asigna a this en el campo que corresponda lo que recibe por parametro
 * @param this puntero a la estructura eCompras
 * @param buyCode de tipo int
 * @return retorna -1 como ERROR y 0 para indicar que no hubo errores
 */
int lib_setBuyCode(eCompras* this, int buyCode);

/**
 * Le asigna al puntero buyCode el valor que tiene this en el campo que corresponda
 * @param this puntero a la estructura eCompras
 * @param buyCode puntero de tipo int
 * @return retorna -1 como ERROR y 0 para indicar que no hubo errores
 */
int lib_getBuyCode(eCompras* this, int* buyCode);

/**
 * Le asigna a this en el campo que corresponda lo que recibe por parametro
 * @param this puntero a la estructura eCompras
 * @param description de tipo char
 * @return retorna -1 como ERROR y 0 para indicar que no hubo errores
 */
int lib_setDescription(eCompras* this, char* description);

/**
 * Le asigna al puntero description el valor que tiene this en el campo que corresponda
 * @param this puntero a la estructura eCompras
 * @param description de tipo char
 * @return retorna -1 como ERROR y 0 para indicar que no hubo errores
 */
int lib_getDescription(eCompras* this, char* description);

/**
 * Le asigna a this en el campo que corresponda lo que recibe por parametro
 * @param this puntero a la estructura eCompras
 * @param idOrigen de tipo int
 * @return retorna -1 como ERROR y 0 para indicar que no hubo errores
 */
int lib_setIdOrigen(eCompras* this, int idOrigen);

/**
 * Le asigna al puntero idOrigen el valor que tiene this en el campo que corresponda
 * @param this puntero a la estructura eCompras
 * @param idOrigen puntero de tipo int
 * @return retorna -1 como ERROR y 0 para indicar que no hubo errores
 */
int lib_getIdOrigen(eCompras* this, int* idOrigen);

/**
 * Le asigna a this en el campo que corresponda lo que recibe por parametro
 * @param this puntero a la estructura eCompras
 * @param totalPurchase de tipo float
 * @return retorna -1 como ERROR y 0 para indicar que no hubo errores
 */
int lib_setUnitaryPrice(eCompras* this, float unitaryPrice);

/**
 * Le asigna al puntero unitaryPrice el valor que tiene this en el campo que corresponda
 * @param this puntero a la estructura eCompras
 * @param unitaryPrice puntero de tipo float
 * @return retorna -1 como ERROR y 0 para indicar que no hubo errores
 */
int lib_getUnitaryPrice(eCompras* this, float* unitaryPrice);

/**
 * Le asigna al puntero ID el valor que tiene this en el campo que corresponda
 * @param this puntero a la estructura eCompras
 * @param amount de tipo int
 * @return retorna -1 como ERROR y 0 para indicar que no hubo errores
 */
int lib_setIdAmount(eCompras* this, int amount);

/**
 * Le asigna al puntero amount el valor que tiene this en el campo que corresponda
 * @param this puntero a la estructura eCompras
 * @param amount puntero de tipo int
 * @return retorna -1 como ERROR y 0 para indicar que no hubo errores
 */
int lib_getIdAmount(eCompras* this, int* amount);

/**
 * Le asigna a this en el campo que corresponda lo que recibe por parametro
 * @param this puntero a la estructura eCompras
 * @param totalPurchase de tipo float
 * @return retorna -1 como ERROR y 0 para indicar que no hubo errores
 */
int lib_setTotalPurchase(eCompras* this, float totalPurchase);

/**
 * Le asigna al puntero totalPurchase el valor que tiene this en el campo que corresponda
 * @param this puntero a la estructura eCompras
 * @param totalPurchase puntero de tipo float
 * @return retorna -1 como ERROR y 0 para indicar que no hubo errores
 */
int lib_getTotalPurchase(eCompras* this, float* totalPurchase);

/**
 * settea un campo de la estructura y lo devuelve
 * @param pElement puntero a elemento
 */
void* set_TotalPurchease(void* pElement);

/**
 *
 * @param pElement puntero a elemento
 * @param pElement2 puntero a elemento
 * @return retorna (-1) Si alguno de los elementos es NULL
 * 				   ( 0) Si el 2do elemento es mayor que el 1er elemento
 *   			   ( 1) Si el 1er elemento es mayor que el 2do elemento
 */
int compareByDescription(void* pElement, void* pElement2);

#endif /* LIBRERIA_H_ */
