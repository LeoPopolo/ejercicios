
typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;

typedef struct
{
    char nombre[31];
    int edad;
    int isEmpty;
    int legajo;
    float sueldo;
    eFecha fechaIng;
    int idSector;

} eEmpleado;

typedef struct
{
    int id;
    char descripcion[51];
    int isEmpty;

} eSector;

int menu();
void inicializarVariables(eEmpleado vec[], int tam);
int buscarLibre(eEmpleado lista[], int tam);
int buscarLegajo(eEmpleado lista[], int tam, int legajo);
void mostrar(eEmpleado lista);
void mostrarTodos(eEmpleado lista[], int tam);
void alta(eEmpleado lista[], int tam, eSector listas[]);
void baja(eEmpleado lista[], int tam);
void modificacion(eEmpleado lista[], int tam);
void hardcodeo(eSector sectores[]);
void ordenar(eEmpleado lista[], int tam);
void menuListas(eEmpleado listaem[], eSector listase[], int tame, int tams);
