#include <stdio.h>
#include <stdlib.h>
#include "utn_get.h"
#include "Libreria.h"
#include "Origen.h"


int parser_LibraryFromText(FILE* pFile, LinkedList* pArrayLibreria)
{
	int retorno=-1;
	char id[10];
	char description[30];
	char idOrigen[10];
	char unitaryPrice[10];
	char amount[10];
	char totalPurchase[30];
	eCompras* aLibrary;

	if(pArrayLibreria!=NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,description,idOrigen,unitaryPrice,amount,totalPurchase);
		while(!feof(pFile))
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,description,idOrigen,unitaryPrice,amount,totalPurchase);
			aLibrary = lib_newParameters(id, description, idOrigen, unitaryPrice, amount, totalPurchase);
			ll_add(pArrayLibreria, aLibrary);
		}
		retorno=0;
	}
	return retorno;
}

int parser_OrigenFromText(FILE* pFile, LinkedList* pArrayOrigen)
{
	int retorno=-1;
	char id[10];
	char description[30];
	Origen* aOrigen = NULL;

	if(pArrayOrigen!=NULL)
	{
		while(!feof(pFile))
		{
			fscanf(pFile,"%[^,],%[^\n]\n",id,description);
			aOrigen = origen_newParameters(id, description);
			ll_add(pArrayOrigen, aOrigen);
		}
		retorno=0;
	}
	return retorno;
}
