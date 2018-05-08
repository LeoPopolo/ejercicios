
typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;

typedef struct
{
    char categoria;
    char nombre[31];
    int edad;
    int isEmpty;
    int Id;
    float sueldo;
    eFecha fechaIng;
    int idSector;

} estructuraUno;


typedef struct
{
    int id;
    char descripcion[51];
    int isEmpty;

} estructuraDos;

int menu();
void inicializarVariables(estructuraUno vec[], int tam);
int buscarLibre(estructuraUno lista[], int tam);
int buscarId(estructuraUno lista[], int tam, int Id);
void mostrar(estructuraUno lista, estructuraDos sectores, int i);
int mostrarTodos(estructuraUno lista[], int tam1, estructuraDos sectores[], int tam2, int flagORD);
void alta(estructuraUno lista[], int tam, int Id);
void baja(estructuraUno lista[], int tam, estructuraDos sectores[]);
void modificacion(estructuraUno lista[], int tam, estructuraDos sectores[]);
void ordenamiento(estructuraUno emp[], int tam);
void gotoxy(int x,int y);
void hardcodeo(estructuraDos sectores[]);
int menuOpcion();
void mostrarEst1(estructuraUno listae[], int tam1, estructuraDos listas[], int tam2);
int validarLetra(char opcion[]);
//int buscarDNI(estructuraUno lista[], int tam, char DNI[]);
int cantidadEmpleados(int sector, estructuraUno emp[],int tam);
void mostrarEst1ConCantidadDestructuraUnos(estructuraUno emp[],int tam1,estructuraDos sec[],int tam2);
void inicializarEst2(estructuraDos sec[], int tam);
int maximoEmpleados(estructuraUno emp[],int tam1,estructuraDos sec[],int tam2);
void sectorConMasEmpleados(estructuraUno emp[],int tam1,estructuraDos sec[],int tam2);
//void login();
int ingresoEdadVal();
void validarNombre(int tam);
