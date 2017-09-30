typedef struct
{
    int idProg;
    char nombre[30];
    float sueldo;
    int estado;
}eProgramador;

typedef struct
{
    int idCat;
    char nombreCat[12];
    int valorPH;
    int estado;
}eCategoria;

typedef struct
{
    int idProy;
    char nombreProy[30];
    int hsProy;
    int estado;
}eProyecto;

typedef struct
{
    int idProg;
    int idCat;
    int idProy;
}ePPC;

void mostrarProgram(eProgramador lista1[], eCategoria lista2[], eProyecto lista3 [], ePPC lista4[], int tamProg, int tamProy, int tamCat);
int buscarProgramador(int id, eProgramador lista1[],int tam);
void inicializarVariables(eProgramador lista1[],int tam);
void variablesCero(eProgramador lista1[],int i, int tam);
int calcularSueldo(eProgramador lista1[], eCategoria lista2[], eProyecto lista3[], ePPC lista4[], int tamProg);
