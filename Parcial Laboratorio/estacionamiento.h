typedef struct
{
    int idDuenio;
    char nombYAp[20];
    char direccion[40];
    char tarjeta[20];
    int estado;
}eDuenio;

typedef struct
{
    char patente[10];
    int marca;
    int idDuenio;
    int horarioEnt;
    int estado;
}eAuto;

int menu();
void inicializarvector(eDuenio lista[],int tam);
int buscarLibre(eDuenio lista[],int tam);
int buscarDuenio(int id, eDuenio lista[],int tam);
void altaDuenio(eDuenio lista[],int tam);
int buscarAuto(char patente[], eAuto lista[],int tam);
int buscarLibreAuto(eAuto lista[],int tam);
int buscarLibre(eDuenio lista[],int tam);
void inicializarvectorAuto(eAuto lista[],int tam);
void ingresoAuto(eAuto lista[],int tam);
void mostrarAutosCDuenio(eDuenio D[],int tamD,eAuto A[],int tamA);
