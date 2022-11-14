#include <stdio.h>
#include <stdlib.h>
#include "utn_get.h"
#include "Informes.h"
#include "LinkedList.h"
#include "Libreria.h"
#include "Origen.h"
#include "parser.h"


int controller_chargeLibraryModoTexto(char* path, LinkedList* pArrayLibrary)
{
	int retorno=-1;
	FILE* pFile;

	if(pArrayLibrary!=NULL)
	{
		if((pFile=fopen(path,"r"))!=NULL)
		{
			ll_clear(pArrayLibrary);
			parser_LibraryFromText(pFile, pArrayLibrary);
			puts("\n-> Se cargo desde el archivo correctamente!!");
			retorno=0;
		}
		else{
			puts("\nOcurrio un error con la apertura del archivo .csv");
		}
		fclose(pFile);
	}
	return retorno;
}

int controller_chargeOrigenModoTexto(char* path, LinkedList* pArrayOrigen)
{
	int retorno=-1;
	FILE* pFile;

	if(pArrayOrigen!=NULL)
	{
		if((pFile=fopen(path,"r"))!=NULL)
		{
			ll_clear(pArrayOrigen);
			parser_OrigenFromText(pFile, pArrayOrigen);
			retorno=0;
		}
		else{
			puts("\nOcurrio un error con la apertura del archivo .csv");
		}
	}
	fclose(pFile);
	return retorno;
}

int controller_totalPurchase(LinkedList* pArrayLibrary, LinkedList* pArrayResultado)
{
	int retorno=-1;

	if(pArrayLibrary!=NULL)
	{
		if(!ll_isEmpty(pArrayLibrary))
		{
			pArrayResultado = ll_map(pArrayLibrary, set_TotalPurchease);
			puts("\n-> Compras calculadas correctamente!!");
		}
		else{
			puts("\n-> Primero tenes que hacer la carga del archivo.");
		}
		retorno=0;
	}
	return retorno;
}

int controller_filterAndSaveByType(char* path,LinkedList* pArrayLibrary,LinkedList* pArrayFilter,LinkedList* pArrayOrigen)
{
	int retorno=-1;
	int len;
	int origen;
	int buyCode;
	char description[30];
	float unitaryPrice;
	int amount;
	float totalPurchase;

	FILE* pFile;
	eCompras* buyFilter = NULL;
	if(pArrayLibrary!=NULL)
	{
		if(!ll_isEmpty(pArrayLibrary))
		{
			len = ll_len(pArrayLibrary);
			if((pFile=fopen(path,"w"))!=NULL)
			{
				utn_getNumberInt(&origen,"\n1. ADMINISTRACION\n2. TALLER\n3. VENTAS\n->: ","Error, ingrese una opcion valida...",1,3,200);
				for(int i=0; i<len;i++)
				{
					buyFilter = ll_get(pArrayLibrary, i);
					lib_getBuyCode(buyFilter, &buyCode);
					lib_getDescription(buyFilter, description);
					lib_getUnitaryPrice(buyFilter, &unitaryPrice);
					lib_getIdAmount(buyFilter, &amount);
					lib_getTotalPurchase(buyFilter, &totalPurchase);
					switch(origen)
					{
						case 1:
							pArrayFilter = ll_filter(pArrayLibrary, filterAdministracion);
							break;
						case 2:
							pArrayFilter = ll_filter(pArrayLibrary, filterTaller);
							break;
						case 3:
							pArrayFilter = ll_filter(pArrayLibrary, filterVentas);
							break;
					}
				}
				len = ll_len(pArrayFilter);
				for(int j=0; j<len;j++)
				{
					buyFilter = ll_get(pArrayFilter, j);
					lib_getBuyCode(buyFilter, &buyCode);
					lib_getDescription(buyFilter, description);
					lib_getUnitaryPrice(buyFilter, &unitaryPrice);
					lib_getIdAmount(buyFilter, &amount);
					lib_getTotalPurchase(buyFilter, &totalPurchase);
					fprintf(pFile,"%d,%s,%d,%.2f,%d,%.2f\n",buyCode,description,origen,unitaryPrice,amount,totalPurchase);
				}
				printfListLibrary(pArrayFilter, pArrayOrigen);
				fclose(pFile);
			}
		}
		else{
			puts("\n-> Primero tenes que hacer la carga del archivo.");
		}
		retorno=0;
	}
	return retorno;
}
int controller_ComprasSaveAsTxt(char* path, LinkedList* pArrayLibrary)
{
	int retorno=-1;
	int len;
	int origen;
	int buyCode;
	char description[30];
	float unitaryPrice;
	int amount;
	float totalPurchase;

	FILE* pFile;
	eCompras* unaCompra;
	if(pArrayLibrary!=NULL)
	{
		if(!(ll_isEmpty(pArrayLibrary)))
		{
			len = ll_len(pArrayLibrary);
			if((pFile=fopen(path,"w"))!=NULL)
			{
				fprintf(pFile,"%s,%s,%s,%s,%s,%s\n","buyCode","description","origen","unitaryPrice","amount","totalPurchase");
				for(int i=0; i<len; i++)
				{
					unaCompra = ll_get(pArrayLibrary, i);
					lib_getBuyCode(unaCompra, &buyCode);
					lib_getDescription(unaCompra, description);
					lib_getIdOrigen(unaCompra, &origen);
					lib_getUnitaryPrice(unaCompra, &unitaryPrice);
					lib_getIdAmount(unaCompra, &amount);
					lib_getTotalPurchase(unaCompra, &totalPurchase);
					fprintf(pFile,"%d,%s,%d,%.2f,%d,%.2f\n",buyCode,description,origen,unitaryPrice,amount,totalPurchase);
				}
				puts("\nCambios guardados correctamente!!");
			}
			else{
				puts("\nHa ocurrido un error al abrir el archivo...");
			}
		}
		else{
			puts("\n-> Primero tenes que hacer la carga del archivo.");
		}
		retorno=0;
		fclose(pFile);
	}
	return retorno;
}
int controller_ListOrderByDescription(LinkedList* pArrayLibrary, LinkedList* pArrayOrigen)
{
	int retorno=-1;

	if(pArrayLibrary!=NULL)
	{
		if(!ll_isEmpty(pArrayLibrary))
		{
			ll_sort(pArrayLibrary, compareByDescription, 1);
			printfListLibrary(pArrayLibrary,pArrayOrigen);
			puts("\n-> Lista ordenada de manera ascendete...");
		}
		else{
			puts("\n-> Primero tenes que hacer la carga del archivo.");
		}
		retorno=0;
	}
	return retorno;
}
