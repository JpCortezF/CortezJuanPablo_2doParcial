/*
 ============================================================================
 Name        : Juan Pablo Cortez Fernandez
 Version     : Version FINAL
 Description : Segundo parcial de laboratorio I
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn_get.h"
#include "Informes.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Libreria.h"
#include "Origen.h"
#include "parser.h"

int main(void) {
	setbuf(stdout, NULL);
    int option;
    char file[10];
    LinkedList* pArrayLibrary = ll_newLinkedList();
    LinkedList* pArrayOrigen = ll_newLinkedList();
    LinkedList* pArrayResultado = NULL;
    LinkedList* pArrayFilter = NULL;
    do
     {
 		printf("\n----------------------\n");
 		printf("\n   Menu principal  \n\n");
 		printf("1. Cargar archivo\n");
 		printf("2. Imprimir lista\n");
 		printf("3. Asignar totales\n");
 		printf("4. Filtrar por tipo\n");
 		printf("5. Mostrar compras\n");
 		printf("6. Guardar compras\n");
 		printf("7. SALIR\n");
 		utn_getNumberInt(&option, "Ingresar una opcion: ", "\nError, ingrese una opcion valida...\n",1,7,20);

 		switch(option)
 		{
			case 1:
				utn_getString(file,"\nIngrese 'data.csv' para cargar el archivo: ","\nIngrese un string mas corto...",200);
				controller_chargeLibraryModoTexto(file, pArrayLibrary);
				controller_chargeOrigenModoTexto("origenes.csv", pArrayOrigen);
				break;
			case 2:
				printfListLibrary(pArrayLibrary,pArrayOrigen);
				break;
			case 3:
				controller_totalPurchase(pArrayLibrary);
				break;
			case 4:
				controller_filterAndSaveByType("filtrados.csv",pArrayLibrary,pArrayFilter,pArrayOrigen);
				break;
			case 5:
				controller_ListOrderByDescription(pArrayLibrary,pArrayOrigen);
				break;
			case 6:
				controller_ComprasSaveAsTxt(file, pArrayLibrary);
				break;
 		}
     }while(option!=7);
    ll_deleteLinkedList(pArrayLibrary);
    ll_deleteLinkedList(pArrayOrigen);
    ll_deleteLinkedList(pArrayResultado);
    ll_deleteLinkedList(pArrayFilter);
	return 0;
}
