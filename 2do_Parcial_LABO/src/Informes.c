#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_get.h"
#include "Libreria.h"
#include "Origen.h"

void printHeadboar(void)
{
	puts("|=====================================================================================================");
	puts("|  Codigo |       Descripcion        |      Origen     | Precio Unitario | Cantidad |  Compra Total  |");
	puts("|---------|--------------------------|-----------------|-----------------|----------|----------------|");
}
void printOneLibrary(eCompras* aLibrary, LinkedList* pArrayOrigen)
{
	int index;
	int buyCode;
	char description[30];
	char origen[30];
	int idOrigen;
	float uniraryPrice;
	int amount;
	float totalPurchase;
	Origen* aOrigen;
	if(aLibrary!=NULL)
	{
		lib_getBuyCode(aLibrary, &buyCode);
		lib_getDescription(aLibrary, description);
		lib_getIdOrigen(aLibrary, &idOrigen);
		lib_getUnitaryPrice(aLibrary, &uniraryPrice);
		lib_getIdAmount(aLibrary, &amount);
		lib_getTotalPurchase(aLibrary, &totalPurchase);
		index = findDescriptionById(pArrayOrigen, idOrigen);
		aOrigen = ll_get(pArrayOrigen, index);
		origen_getDescription(aOrigen, origen);
		printf("|   %3d   | %24s | %15s |     %7.2f     |    %3d   |   %8.2f     |\n",buyCode,description,origen,uniraryPrice,amount,totalPurchase);
	}
}
int printfListLibrary(LinkedList* pArrayLibrary,LinkedList* pArrayOrigen)
{
	int retorno=-1;
	int amount;
	eCompras* aLibrary;
	if(pArrayLibrary!=NULL)
	{
		if(!ll_isEmpty(pArrayLibrary))
		{
			amount=ll_len(pArrayLibrary);
			printHeadboar();
			for(int i=0; i<amount;i++)
			{
				aLibrary = ll_get(pArrayLibrary, i);
				printOneLibrary(aLibrary,pArrayOrigen);
			}
			puts("|=====================================================================================================");
			utn_getNumberInt(&amount,"\nIngrese '1' para volver al menu principal: ","\nERROR.",1,1,200);
		}
		else{
			puts("\n-> Primero tenes que hacer la carga del archivo.");
		}
		retorno=0;
	}
	return retorno;
}
