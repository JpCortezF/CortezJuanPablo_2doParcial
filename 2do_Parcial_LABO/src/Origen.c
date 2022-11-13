#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_get.h"
#include "Libreria.h"
#include "Origen.h"

Origen* origen_new()
{
	Origen* newOrigen = NULL;
	newOrigen = (Origen*)malloc(sizeof(Origen));

	return newOrigen;
}
Origen* origen_newParameters(char* idStr,char* description)
{
	Origen* newOrigen = NULL;
	newOrigen = origen_new();

	if(newOrigen!=NULL)
	{
		origen_setId(newOrigen, atoi(idStr));
		origen_setDescription(newOrigen, description);
	}
	return newOrigen;
}
int origen_setId(Origen* this, int id)
{
	int retorno=-1;

	if(this!=NULL && id > 0)
	{
		this->id = id;
		retorno=0;
	}
	return retorno;
}
int origen_getId(Origen* this, int* id)
{
	int retorno=-1;

	if(this!=NULL && id!=NULL)
	{
		*id = this->id;
		retorno=0;
	}
	return retorno;
}
int origen_setDescription(Origen* this, char* description)
{
	int retorno=-1;

	if(this!=NULL && strlen(description)>0)
	{
		strcpy(this->description,description);
		retorno=0;
	}
	return retorno;
}
int origen_getDescription(Origen* this, char* description)
{
	int retorno=-1;

	if(this!=NULL && strlen(description)>0)
	{
		strcpy(description,this->description);
		retorno=0;
	}
	return retorno;
}
int filterAdministracion(void* pElement)
{
	int retorno=0;
	int id;

	lib_getIdOrigen(pElement, &id);
	if(id == 1)
	{
		retorno=1;
	}
	return retorno;
}
int filterTaller(void* pElement)
{
	int retorno=0;
	int id;

	lib_getIdOrigen(pElement, &id);
	if(id == 2)
	{
		retorno=1;
	}
	return retorno;
}
int filterVentas(void* pElement)
{
	int retorno=0;
	int id;

	lib_getIdOrigen(pElement, &id);
	if(id == 3)
	{
		retorno=1;
	}
	return retorno;
}
int findDescriptionById(LinkedList* pArrayOrigen, int id)
{
	int index=-1;
	int auxId;
	int len;
	Origen* aOrigen;

	if(pArrayOrigen!=NULL)
	{
		len = ll_len(pArrayOrigen);
		for(int i=0; i<len;i++)
		{
			aOrigen = ll_get(pArrayOrigen, i);
			origen_getId(aOrigen, &auxId);
			if(auxId == id)
			{
				index = ll_indexOf(pArrayOrigen, aOrigen);
				break;
			}
		}
	}
	return index;
}
