#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = NULL;
    this = (LinkedList*) malloc(sizeof(LinkedList));
    if(this!=NULL)
    {
    	this->pFirstNode = NULL;
    	this->size = 0;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int retorno = -1;
    if(this!=NULL)
    {
    	retorno=this->size;
    }
    return retorno;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* auxNode=NULL;
	if(this!=NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
	{
		auxNode=this->pFirstNode; // Le asigno el primer elemento del Nodo
		for(int i=0; i<nodeIndex; i++) // Sale cuando llegamos al nodo en el indice que buscamos
		{
			auxNode = auxNode->pNextNode; // Voy pisando el auxNode y sale cuando pisa el indice que yo le pedi
		}
	}
    return auxNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* newNode=NULL;
    Node* prevNode=NULL;

    if(this!=NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
        newNode = (Node*)malloc(sizeof(Node));
		if(newNode!=NULL)
		{
			if(nodeIndex==0)
			{	// getNode me devuelve un puntero a Nodo en un indice especifico
				newNode->pNextNode = getNode(this, nodeIndex); // (donde quiero agregar el nuevo Nodo)
				this->pFirstNode = newNode; // apunto el linkedList al nuevo Nodo (indice: nodeIndex)
			}
			else
			{	// getNode me devuelve un puntero a Nodo en un indice especifico
				newNode->pNextNode = getNode(this, nodeIndex); // (donde quiero agregar el nuevo Nodo)
				prevNode = getNode(this, nodeIndex-1); // en prevNode guardo el Nodo anterior (indice -1)
				prevNode->pNextNode = newNode; // apunto el prevNode al nuevo Nodo (indice: nodeIndex)
			}
			newNode->pElement = pElement; // asigno el elemento a pElement que me llega por parametro
			this->size++; // aumento en +1 el size de la LinkedList
			returnAux=0;
		}
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this!=NULL)
    {
    	returnAux = addNode(this, ll_len(this), pElement); // ll_len(this) me retorna el ultimo indice cargado en la lista
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada ???
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNode = NULL;

    if(this!=NULL && index >= 0 && index < ll_len(this))
    {
    	pNode = getNode(this, index);
    	returnAux = pNode->pElement;
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pNode = NULL;

    if(this!=NULL && index >= 0 && index < ll_len(this))
    {
    	pNode = getNode(this, index);
    	pNode->pElement = pElement;
    	returnAux=0;
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pNode;
    Node* auxNode;

    if(this!=NULL && index >= 0 && index < ll_len(this))
    {
    	pNode = getNode(this, index);
    	if(index==0)
    	{
    		this->pFirstNode = pNode->pNextNode;
    	}
    	else
    	{
    		auxNode = getNode(this, index-1);
    		auxNode->pNextNode = pNode->pNextNode;
    	}
    	free(pNode);
		this->size--;
    	returnAux=0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
    	for(int i=0; i<ll_len(this); i++)
    	{
    		ll_remove(this, i);
    	}
    	returnAux=0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
    	for(int i=0; i<ll_len(this); i++)
    	{
    		free(this);
    	}
    	returnAux=0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* pNode = NULL;

    if(this!=NULL)
    {
    	for(int i=0; i<ll_len(this); i++)
    	{
    		pNode = getNode(this, i); // obtengo el nodo en esa posicion
        	if(pNode->pElement == pElement) // comparo con el que me llega por parametro
        	{
        		returnAux = i;
        		break;
        	}
    	}
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
		returnAux=0; // si NO esta vacia
    	if(ll_len(this) == 0)
    	{
    		returnAux=1; // SI esta vacia
    	}
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this!=NULL && index >= 0 && index < ll_len(this))
    {
    	addNode(this, index, pElement);
    	returnAux=0;
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    Node* pNode = NULL;

    if(this!=NULL && index >= 0 && index < ll_len(this))
    {
    	pNode = getNode(this, index);
    	returnAux = pNode->pElement;
    	ll_remove(this, index);
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* pNode = NULL;
    if(this!=NULL)
    {
    	returnAux=0;
    	for(int i=0; i<ll_len(this); i++)
    	{
    		pNode = getNode(this, i);
    		if(pNode->pElement == pElement)
    		{
    			returnAux=1;
    		}
    	}
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    void* pElement = NULL;

    if(this!=NULL && this2!=NULL)
    {
    	returnAux=1;
    	for(int i=0;i<ll_len(this2); i++) // recorro this2
    	{
    		pElement = ll_get(this2, i); // con ll_get tomo los elementos de this2 en cada iteracion
			if(!ll_contains(this, pElement)) // llamo ll_contains para comparar y entra cuando encuentra un elemento distinto
			{
				returnAux=0;
			}

    	}
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* pElement = NULL;
    if(this!=NULL && from >= 0 && from < ll_len(this) && to > from && to <= ll_len(this))
    {
    	cloneArray = ll_newLinkedList();
    	if(cloneArray!=NULL)
    	{
    		for(int i=from; i<to; i++)
			{
				pElement = ll_get(this, i);
				ll_add(cloneArray, pElement);
			}
    	}
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if(this!=NULL)
    {
    	cloneArray = ll_subList(this, 0, ll_len(this));
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    void* pElement = NULL;
    void* pElement2 = NULL;


    if((this!=NULL && pFunc!=NULL) && (order == 0 || order == 1))
    {
    	for(int i=0; i<ll_len(this)-1; i++)
    	{
    		for(int j=i+1; j<ll_len(this); j++)
    		{
    			pElement = ll_get(this, i);
				pElement2 = ll_get(this, j);
				if(pFunc((pElement),(pElement2)) > 0 && order == 1)
				{
					ll_set(this, i, pElement2);
					ll_set(this, j, pElement);
					returnAux=0;
				}
				else if (pFunc((pElement),(pElement2)) < 0 && order == 0)
				{
					ll_set(this, i, pElement2);
					ll_set(this, j, pElement);
					returnAux=0;
				}
    		}
    	}
    }
    return returnAux;
}
/**
 * La funci�n �ll_map� recibir� una lista y una funci�n �pFunc�.
 * se deber�n iterar todos los elementos de la lista y pas�rselos a la funci�n �pFunc� que recibir� el elemento y le calcular� el
campo totalCompra, el retorno de �pFunc� se agregar� a la lista resultado, esta nueva lista ser�
devuelta por ll_map.
 * @param this Puntero a la lista
 * @param pFunc Puntero a funcion
 * @return crea una nueva lista y la retorna
 */
LinkedList* ll_map (LinkedList* this, void*(*pFunc)(void*))
{
	void* pElement = NULL;
	void* auxElement = NULL;
	LinkedList* listaResultado = NULL;
	if(this!=NULL && pFunc!=NULL)
	{
		listaResultado = ll_newLinkedList();
		if(listaResultado!=NULL)
		{
			for(int i=0; i<ll_len(this); i++)
			{
				pElement = ll_get(this, i);
				if(pElement!=NULL)
				{
					auxElement = pFunc(pElement);
					ll_add(listaResultado, auxElement);
				}
			}
		}
	}
    return listaResultado;
}
/**
 * La funci�n �ll_filter� recibir� una lista y una funci�n �pFunc�. se deber� iterar todos los
	elementos de la lista y pas�rselos a la funci�n �pFunc�. la funci�n �pFunc� devolver� 1 si ese
	�tem se debe agregar a la lista resultado o 0 si no debe agregarse.
 * @param this Puntero a la lista
 * @param pFunc Puntero a funcion
 * @return generar� la nueva lista resultado, agregar� a la misma los �tems correspondientes y la devolver�.
 */
LinkedList* ll_filter (LinkedList* this, int(*pFunc)(void*))
{
	void* pElement = NULL;
	LinkedList* listaResultado = NULL;

	if(this!=NULL && pFunc!=NULL)
	{
		listaResultado = ll_newLinkedList();
		if(listaResultado!=NULL)
		{
			for(int i=0; i<ll_len(this); i++)
			{
				pElement = ll_get(this, i);
				if(pElement!=NULL)
				{
					if(pFunc(pElement) == 1)
					{
						ll_add(listaResultado, pElement);
					}
				}
			}
		}
	}
	return listaResultado;
}
