typedef struct
{
    int idProd;
    char descripcion[51];
    float importe;
    int cantidad;
    int idProv;
    int estado;

}eProductos;

typedef struct
{
    int idProv;
    char descripcion[51];

}eProveedor;

/** \brief funcion para hardcodear la estructura productos
 *
 * \param lista del array
 * \return void
 *
 */

void hardcodeProv(eProveedor lista[]);

/** \brief funcion que inicializa variables de la estructura
 *
 * \param array de estructura productos
 * \param tamaño del array
 * \return void
 *
 */

void inicializarVariables(eProductos vec[], int tam);

/** \brief funcion que busca un espacio libre
 *
 * \param array de la estructura
 * \param tamaño del array
 * \return posicion libre
 *
 */

int buscarLibre(eProductos lista[], int tam);

/** \brief funcion que busca un id
 *
 * \param array de la estructura
 * \param tam del array
 * \param id a buscar
 * \return id encontrado
 *
 */

int buscarId(eProductos lista[], int tam, int Id);

/** \brief muestra un producto con su proveedor
 *
 * \param array del producto
 * \param array de proveedores
 * \return void
 *
 */

void mostrar(eProductos lista, eProveedor proveedores);

/** \brief funcion que muestra el array completo
 *
 * \param array de la estructura producto
 * \param tamaño de la primera estructura
 * \param array de la estructura proveedor
 * \param tamaño de la segunda estructura
 * \return flag
 *
 */

int mostrarTodos(eProductos lista[], int tam1, eProveedor proveedores[], int tam2);

/** \brief funcion para dar de alta un elemento
 *
 * \param array de la estructura productos
 * \param tamaño del array
 * \param id a buscar
 * \param array de proveedores
 * \return void
 *
 */

void alta(eProductos lista[], int tam, int Id, eProveedor proveedores[]);
/** \brief funcion para modificar un elemento
 *
 * \param array de la estructura productos
 * \param tamaño del array
 * \param array de proveedores
 * \return void
 *
 */
void modificacion(eProductos lista[], int tam, eProveedor proveedores[]);
/** \brief funcion para dar de baja un elemento
 *
 * \param array de la estructura productos
 * \param tamaño del array
 * \param array de proveedores
 * \return void
 *
 */
void baja(eProductos lista[], int tam, eProveedor proveedores[]);

/** \brief muestra todos los proveedores
 *
 * \param array de proveedores
 * \param tamaño del array
 * \return void
 *
 */

void mostrarProveedores(eProveedor lista[], int tam);

/** \brief muestra un proveedor
 *
 * \param array del proveedor
 * \return void
 *
 */

void mostrarProveedor(eProveedor lista);

/** \brief funcion que cuenta la cantidad de productos que tienen mas de 10 unideades
 *
 * \param numero de stock
 * \param array de productos
 * \param tamaño del array
 * \return cantidad de productos
 *
 */

int cantidadStockMenos10(int cantidad, eProductos lista[], int tam);

/** \brief funcion que cuenta la cantidad de productos que tienen menos de 10 unideades
 *
 * \param numero de stock
 * \param array de productos
 * \param tamaño del array
 * \return cantidad de productos
 *
 */
int cantidadStockMas10(int cantidad, eProductos lista[], int tam);

/** \brief muestra la cantidad de productos que tienen mas de 10 unidades
 *
 * \param array de productos
 * \return void
 *
 */

void mostrarProductosMas10(eProductos lista[]);

/** \brief muestra la cantidad de productos que tienen menos de 10 unidades
 *
 * \param array de productos
 * \return void
 *
 */
void mostrarProductosMenos10(eProductos lista[]);

/** \brief funcion que acumula los precios de todos los productos
 *
 * \param array de productos
 * \param tamaño del array
 * \return acumulador de importes
 *
 */

float acumulador(eProductos lista[], int tam);

/** \brief muestra la cantidad de productos que no superan el promedio total
 *
 * \param array de productos
 * \param tamaño del array
 * \return void
 *
 */

void mostrarCantidadProductosNoSuperanProm(eProductos lista[], int tam);

/** \brief muestra la cantidad de productos que superan el promedio total
 *
 * \param array de productos
 * \param tamaño del array
 * \return void
 *
 */
void mostrarCantidadProductosSuperanProm(eProductos lista[], int tam);

/** \brief muestra la descripcion de los productos que tienen menos de 10 unidades
 *
 * \param array de productos
 * \return void
 *
 */

void mostrarProductosMenos10Des(eProductos lista[]);

/** \brief muestra la descripcion de los productos que tienen mas de 10 unidades
 *
 * \param array de productos
 * \return void
 *
 */
void mostrarProductosMas10Des(eProductos lista[]);

/** \brief muestra la descripcion de los productos que su importe no supera el promedio total
 *
 * \param array de productos
 * \param tamaño del array
 * \return void
 *
 */

void mostrarCantidadProductosNoSuperanPromDes(eProductos lista[], int tam);

/** \brief muestra la descripcion de los productos que su importe supera el promedio total
 *
 * \param array de productos
 * \param tamaño del array
 * \return void
 *
 */

void mostrarCantidadProductosSuperanPromDes(eProductos lista[], int tam);

/** \brief muestra todos los productos de todos los proveedores
 *
 * \param array de proveedores
 * \param array de productos
 * \return void
 *
 */

void productosDeProveedores(eProveedor lista[], eProductos listaP[]);

/** \brief funcion que calcula el promedio de los importes de todos los productos
 *
 * \param array de productos
 * \param tamaño del array
 * \return promedio de los importes
 *
 */

float promedio(eProductos lista[], int tam);

/** \brief contador de todos los productos ingresados
 *
 * \param array de productos
 * \param tamaño del array
 * \return contador
 *
 */

int cantidadTotalProductos(eProductos lista[], int tam);

/** \brief contador de la cantidad de productos que superan el promedio total
 *
 * \param array de productos
 * \param tamaño del array
 * \return contador
 *
 */

int cantidadProductosSuperanProm(eProductos lista[], int tam);

/** \brief contador de la cantidad de productos que no superan el promedio total
 *
 * \param array de productos
 * \param tamaño del array
 * \return contador
 *
 */
int cantidadProductosNoSuperanProm(eProductos lista[], int tam);

/** \brief muestra la descripcion de los productos que superan el promedio total
 *
 * \param array de productos
 * \param tamaño del array
 * \return void
 *
 */

void mostrarCantidadProductosSuperanProm(eProductos lista[], int tam);

/** \brief muestra la descripcion de los productos que no superan el promedio total
 *
 * \param array de productos
 * \param tamaño del array
 * \return void
 *
 */

void mostrarCantidadProductosNoSuperanProm(eProductos lista[], int tam);

/** \brief contador de productos de un proveedor determinado
 *
 * \param id del proveedor a buscar
 * \param array de productos
 * \param tamaño del array
 * \return contador
 *
 */

int cantidadProductosBusqueda(int proveedor, eProductos lista[], int tam);

/** \brief busca los productos de un proveedor determinado
 *
 * \param array de proveedores
 * \param tamaño del array de proveedores
 * \param array de productos
 * \param tamaño del array de productos
 * \return void
 *
 */

void buscarProductosDeProveedor(eProveedor lista[], int tam, eProductos listaP[], int tamP);

/** \brief cuenta la maxima cantidad de productos de un proveedor determinado
 *
 * \param array de proveedores
 * \param tamaño del array de proveedores
 * \param array de productos
 * \param tamaño del array de productos
 * \return cantidad de productos
 *
 */

int maximoProductos(eProveedor lista[], int tam, eProductos lista2[], int tam2);

/** \brief cuenta la minima cantidad de productos de un proveedor determinado
 *
 * \param array de proveedores
 * \param tamaño del array de proveedores
 * \param array de productos
 * \param tamaño del array de productos
 * \return cantidad de productos
 *
 */

int minimoProductos(eProveedor lista[], int tam, eProductos lista2[], int tam2);

/** \brief muestra el proveedor con mas productos
 *
 * \param array de proveedores
 * \param tamaño del array de proveedores
 * \param array de productos
 * \param tamaño del array de productos
 * \return void
 *
 */

void proveedorConMasProductos(eProveedor proveedor[], int tamPROV, eProductos productos[], int tamPROD);

/** \brief muestra el proveedor con mas productos
 *
 * \param array de proveedores
 * \param tamaño del array de proveedores
 * \param array de productos
 * \param tamaño del array de productos
 * \return void
 *
 */

void proveedorConMenosProductos(eProveedor proveedor[], int tamPROV, eProductos productos[], int tamPROD);

/** \brief muestra los proveedores cuyo producto en el array tenga menos de 10 unidades
 *
 * \param array de proveedores
 * \param tamaño del array de proveedores
 * \param array de productos
 * \param tamaño del array de productos
 * \return void
 *
 */


void mostrarProveedorConProductoMenos10(eProveedor listaPROV[], int tamPROV, eProductos listaPROD[], int tamPROD);

/** \brief funcion que devuelve el precio del producto mas caro
 *
 * \param lista de productos
 * \param tamaño del array
 * \return precio del producto
 *
 */

float precioMasCaro(eProductos lista[], int tam);

/** \brief muestra el producto mas caro
 *
 * \param lista de productos
 * \param tamaño del array
 * \return void
 *
 */

void mostrarProductoMasCaro(eProductos lista[], int tam);

/** \brief funcion que devuelve el precio del producto mas barato
 *
 * \param lista de productos
 * \param tamaño del array
 * \return precio del producto
 *
 */

float precioMasBarato(eProductos lista[], int tam);

/** \brief muestra el producto mas barato
 *
 * \param lista de productos
 * \param tamaño del array
 * \return void
 *
 */
void mostrarProductoMasBarato(eProductos lista[], int tam);


