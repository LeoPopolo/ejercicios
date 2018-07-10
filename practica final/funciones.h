typedef struct
{
   int id;
   char nombre[30];
   char apellido[30];
   char dni[12];

}eCliente;

typedef struct
{
    char descripcion[17];
    float costo;
    int cantidad;
    char fechaVenta[9];
    int idCliente;
}eProducto;

int menu(ArrayList* this);
eCliente* newCliente();
eProducto* newProducto();
int getID(eCliente* lista);
int setID(eCliente* lista, int id);
char* getDNI(eCliente* lista);
int setDNI(eCliente* lista, char* dni);
char* getNombre(eCliente* lista);
int setNombre(eCliente* lista, char* nombre);
char* getApellido(eCliente* lista);
int setApellido(eCliente* lista, char* apellido);
void alta(ArrayList* this);
void baja(ArrayList* this, ArrayList* ventas);
void Modificacion(ArrayList* this);
int validar_num(char* opcion);
int dniExiste(ArrayList* this, char* dni);
int idRepetido(ArrayList* this, int id);
int buscarID(ArrayList* this, int id);
void mostrarUno(eCliente* lista);
void mostrar(ArrayList* this);
void ordenar(ArrayList* this);
int compararPersonas(void* personaA,void* personaB);
FILE* abrirArchivo(char* path);
char* cargarArchivo();
void parsearArchivo(ArrayList* this);
void venta(ArrayList* thisC, ArrayList* thisV);
char* getProducto(eProducto* lista);
int setProducto(eProducto* lista, char* descripcion);
float getCosto(eProducto* lista);
int setCosto(eProducto* lista, int costo);
int getCantidad(eProducto* lista);
int setCantidad(eProducto* lista, int cantidad);
char* getFecha(eProducto* lista);
int setFecha(eProducto* lista, char* fecha);
FILE* abrirArchivoW(char* path);
void informeDeVenta(ArrayList* ventas);
int compararImportes(void* productoA,void* productoB);
void ordenarV(ArrayList* this);
int getIDc(eProducto* lista);
int setIDc(eProducto* lista, int id);
int buscarProd(ArrayList* this, char* desc);
void mostrarUnProducto(eProducto* lista);
void mostrarP(ArrayList* this);
int buscarProdFecha(ArrayList* this, char* desc);
void informeDeVentaFecha(ArrayList* ventas);
FILE* crearArchivo(char* path);
FILE* leerArchivo(char* path);
void guardarArchivo(ArrayList* this);
void cargarArchivob(ArrayList* this);
void cargarArchivov(ArrayList* this);
void guardarArchivov(ArrayList* this);
int clienteTieneVentas(ArrayList* lista, int id);
int menuCase9();
void menuCase9Switch(ArrayList* lista, ArrayList* ventas);
void gotoxy(int x, int y);
