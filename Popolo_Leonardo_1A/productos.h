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
int cantidadStockMenos10(int cantidad, eProductos lista[], int tam);
int cantidadStockMas10(int cantidad, eProductos lista[], int tam);
void mostrarProductosMas10(eProductos lista[]);
void mostrarProductosMenos10(eProductos lista[]);
float acumulador(eProductos lista[], int tam);
void mostrarCantidadProductosNoSuperanProm(eProductos lista[], int tam);
void mostrarCantidadProductosSuperanProm(eProductos lista[], int tam);
void mostrarProductosMenos10Des(eProductos lista[]);
void mostrarProductosMas10Des(eProductos lista[]);
void mostrarCantidadProductosNoSuperanPromDes(eProductos lista[], int tam);
void mostrarCantidadProductosSuperanPromDes(eProductos lista[], int tam);
void productosDeProveedores(eProveedor lista[], eProductos listaP[]);
float promedio(eProductos lista[], int tam);
int cantidadTotalProductos(eProductos lista[], int tam);
int cantidadProductosSuperanProm(eProductos lista[], int tam);
int cantidadProductosNoSuperanProm(eProductos lista[], int tam);
void mostrarCantidadProductosSuperanProm(eProductos lista[], int tam);
void mostrarCantidadProductosNoSuperanProm(eProductos lista[], int tam);
void buscarProductosDeProveedor(eProveedor lista[], int tam, eProductos listaP[], int tamP);
int cantidadProductosBusqueda(int proveedor, eProductos lista[], int tam);
int maximoProductos(eProveedor lista[], int tam, eProductos lista2[], int tam2);
int minimoProductos(eProveedor lista[], int tam, eProductos lista2[], int tam2);
void proveedorConMasProductos(eProveedor proveedor[], int tamPROV, eProductos productos[], int tamPROD);
void proveedorConMenosProductos(eProveedor proveedor[], int tamPROV, eProductos productos[], int tamPROD);
void mostrarProveedorConProductoMas10(eProveedor listaPROV[], int tamPROV, eProductos listaPROD[], int tamPROD);
