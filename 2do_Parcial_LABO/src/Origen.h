#include "LinkedList.h"

#ifndef ORIGEN_H_
#define ORIGEN_H_

typedef struct
{
	int id;
	char description[20];
}Origen;

/**
 * reserva espacio de memoria para UN origen
 * @return
 */
Origen* origen_new();

/**
 * Recibe parametros char y los setters se encargan de castearlos al tipo que corresponda
 * @param idStr de tipo char donde se van a settear el id
 * @param description de tipo char donde se van a settear el description
 * @return retorna -1 si no pudo reservar espacio y 0 si funciono correctamente
 */
Origen* origen_newParameters(char* idStr,char* description);

/**
 * Le asigna a this en el campo que corresponda lo que recibe por parametro
 * @param this puntero a la estructura Origen
 * @param id de tipo int
 * @return retorna -1 como ERROR y 0 para indicar que no hubo errores
 */
int origen_setId(Origen* this, int id);

/**
 * Le asigna al puntero ID el valor que tiene this en el campo que corresponda
 * @param this puntero a la estructura Origen
 * @param id puntero de tipo int
 * @return retorna -1 como ERROR y 0 para indicar que no hubo errores
 */
int origen_getId(Origen* this, int* id);

/**
 * Le asigna a this en el campo que corresponda lo que recibe por parametro
 * @param this puntero a la estructura Origen
 * @param description de tipo char
 * @return retorna -1 como ERROR y 0 para indicar que no hubo errores
 */
int origen_setDescription(Origen* this, char* description);

/**
 * Le asigna al puntero description el valor que tiene this en el campo que corresponda
 * @param this puntero a la estructura Origen
 * @param description puntero de tipo char
 * @return retorna -1 como ERROR y 0 para indicar que no hubo errores
 */
int origen_getDescription(Origen* this, char* description);

/**
 * Filtra por idOrigen
 * @param pElement puntero al elemento
 * @return retorna 0 como ERROR y 1 indicando que filtro correctamente
 */
int filterAdministracion(void* pElement);
/**
 * Filtra por idOrigen
 * @param pElement puntero al elemento
 * @return retorna 0 como ERROR y 1 indicando que filtro correctamente
 */
int filterTaller(void* pElement);
/**
 * Filtra por idOrigen
 * @param pElement puntero al elemento
 * @return retorna 0 como ERROR y 1 indicando que filtro correctamente
 */
int filterVentas(void* pElement);

/**
 * Recorre la lista que llega por parametro y devuelve la coincidencia con el ID que llega por parametro
 * @param pArrayOrigen puntero a la lista LinkedList
 * @param id tipo de int
 * @return retorna -1 como ERROR. Si encuentra la coincidencia devuelve la posicion
 */
int findDescriptionById(LinkedList* pArrayOrigen, int id);

#endif /* ORIGEN_H_ */
