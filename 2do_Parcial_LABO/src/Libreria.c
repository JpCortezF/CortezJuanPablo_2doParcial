#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_get.h"
#include "Libreria.h"
#include "Origen.h"

eCompras* lib_new()
{
	eCompras* newLibrery;

	newLibrery = (eCompras*)malloc(sizeof(eCompras));
	return newLibrery;
}
eCompras* lib_newParameters(char* buyCodeStr,char* description,char* idOrigenStr,char* unitaryPriceStr,char* amountStr,char* totalPurchase)
{
	eCompras* newLibrery;

	newLibrery = lib_new();

	if(newLibrery!=NULL && buyCodeStr !=NULL && description !=NULL && idOrigenStr !=NULL && unitaryPriceStr !=NULL && amountStr !=NULL && totalPurchase !=NULL)
	{
		lib_setBuyCode(newLibrery, atoi(buyCodeStr));
		lib_setDescription(newLibrery, description);
		lib_setIdOrigen(newLibrery, atoi(idOrigenStr));
		lib_setUnitaryPrice(newLibrery, atof(unitaryPriceStr));
		lib_setIdAmount(newLibrery, atoi(amountStr));
		lib_setTotalPurchase(newLibrery, atof(totalPurchase));
	}
	return newLibrery;
}
int lib_setBuyCode(eCompras* this, int buyCode)
{
	int retorno=-1;

	if(this!=NULL && buyCode >= 0)
	{
		this->buyCode = buyCode;
	}
	return retorno;
}
int lib_getBuyCode(eCompras* this, int* buyCode)
{
	int retorno=-1;

	if(this!=NULL && buyCode!=NULL)
	{
		*buyCode = this->buyCode;
	}
	return retorno;
}
int lib_setDescription(eCompras* this, char* description)
{
	int retorno=-1;

	if(this!=NULL && strlen(description) > 0)
	{
		strcpy(this->description, description);
		retorno=0;
	}
	return retorno;
}
int lib_getDescription(eCompras* this, char* description)
{
	int retorno=-1;

	if(this!=NULL && strlen(description) > 0)
	{
		strcpy(description, this->description);
		retorno=0;
	}
	return retorno;
}
int lib_setIdOrigen(eCompras* this, int idOrigen)
{
	int retorno=-1;

	if(this!=NULL && idOrigen >= 0)
	{
		this->idOrigen = idOrigen;
	}
	return retorno;
}
int lib_getIdOrigen(eCompras* this, int* idOrigen)
{
	int retorno=-1;

	if(this!=NULL && idOrigen!=NULL)
	{
		*idOrigen = this->idOrigen;
	}
	return retorno;
}
int lib_setUnitaryPrice(eCompras* this, float unitaryPrice)
{
	int retorno=-1;

	if(this!=NULL && unitaryPrice >= 0)
	{
		this->unitaryPrice = unitaryPrice;
	}
	return retorno;
}
int lib_getUnitaryPrice(eCompras* this, float* unitaryPrice)
{
	int retorno=-1;

	if(this!=NULL && unitaryPrice >= 0)
	{
		*unitaryPrice = this->unitaryPrice;
	}
	return retorno;
}
int lib_setIdAmount(eCompras* this, int amount)
{
	int retorno=-1;

	if(this!=NULL && amount >= 0)
	{
		this->amount = amount;
	}
	return retorno;
}
int lib_getIdAmount(eCompras* this, int* amount)
{
	int retorno=-1;

	if(this!=NULL && amount!=NULL)
	{
		*amount = this->amount;
	}
	return retorno;
}
int lib_setTotalPurchase(eCompras* this, float totalPurchase)
{
	int retorno=-1;

	if(this!=NULL && totalPurchase >= 0)
	{
		this->totalPurchase = totalPurchase;
	}
	return retorno;
}
int lib_getTotalPurchase(eCompras* this, float* totalPurchase)
{
	int retorno=-1;

	if(this!=NULL && totalPurchase >= 0)
	{
		*totalPurchase = this->totalPurchase;
	}
	return retorno;
}
void* set_TotalPurchease(void* pElement)
{
	int amount;
	float unitaryPrice;
	float totalPurchase;

	lib_getIdAmount(pElement, &amount);
	lib_getUnitaryPrice(pElement, &unitaryPrice);
	lib_getTotalPurchase(pElement, &totalPurchase);

	totalPurchase = amount * unitaryPrice;
	lib_setTotalPurchase(pElement, totalPurchase);

	return pElement;
}
int compareByDescription(void* pElement, void* pElement2)
{
	int retorno=-1;
	char description[30];
	char description2[30];

	if(pElement!=NULL && pElement2!=NULL)
	{
		lib_getDescription(pElement, description);
		lib_getDescription(pElement2, description2);
		if(strcmp(description, description2) > 0)
		{
			retorno = 1;
		}
		if(strcmp(description, description2) < 0)
		{
			retorno = 0;
		}
	}
	return retorno;
}
