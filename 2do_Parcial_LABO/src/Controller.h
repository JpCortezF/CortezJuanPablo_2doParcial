
/**
 * Carga los datos de las compras desde el archivo data.csv (modo texto)
 * @param path recibe la ruta del archivo
 * @param pArrayLibrary puntero a la lista LinkedList
 * \return la funcion retorna -1 como ERROR si la lista es NULL o si no pudo abrir el archivo
 * y 0 si salio correctamente
 */
int controller_chargeLibraryModoTexto(char* path, LinkedList* pArrayLibrary);

/**
 * Carga los datos de los orignes desde el archivo origines.csv (modo texto)
 * @param path recibe la ruta del archivo
 * @param pArrayOrigen puntero a la lista LinkedList
 * \return la funcion retorna -1 como ERROR si la lista es NULL o si no pudo abrir el archivo
 * y 0 si salio correctamente
 */
int controller_chargeOrigenModoTexto(char* path, LinkedList* pArrayOrigen);

/**
 * Le asigno a pArrayResultado el retorno de 'll_map'
 * @param pArrayLibrary puntero a la lista LinkedList
 * @return retona -1 si la lista que le llega es NULL y 0 si funciono correctamente
 */
int controller_totalPurchase(LinkedList* pArrayLibrary);

/**
 * Pregunta al usuario que origen quiere filtrar y luego lo muestra
 * @param path recibe la ruta del archivo
 * @param pArrayLibrary puntero a la lista LinkedList
 * @param pArrayFilter puntero a la lista LinkedList
 * @param pArrayOrigen puntero a la lista LinkedList
 * @return -1 como ERROR y 0 si la lista que le llega es != de NULL
 */
int controller_filterAndSaveByType(char* path,LinkedList* pArrayLibrary,LinkedList* pArrayFilter,LinkedList* pArrayOrigen);

/**
 * Recorre la cantidad de compras cargadas y en cada iteracion hace un fprintf en el arhicvo
 * @param path recibe la ruta del archivo
 * @param pArrayLibrary puntero a la lista LinkedList
 * @return -1 como ERROR y 0 si la lista que le llega es != de NULL
 */
int controller_ComprasSaveAsTxt(char* path, LinkedList* pArrayLibrary);

/**
 * Ordena la lista pasada por parametro por su descripcion y lo muestra
 * @param pArrayLibrary puntero a la lista LinkedList
 * @param pArrayOrigen puntero a la lista LinkedList
 * @return -1 como ERROR y 0 si la lista que le llega es != de NULL
 */
int controller_ListOrderByDescription(LinkedList* pArrayLibrary, LinkedList* pArrayOrigen);
