
#include "ArrayList.h"

typedef struct
{
    int edad;
    char nombre[30];
    float altura;
    char DNI[12];
} ePersona;

ePersona* newPersona();
int setEdad(ePersona*, int);
int getEdad(ePersona*);
int setAltura(ePersona*, float);
float getAltura(ePersona*);
int setNombre(ePersona*, char*);
char* getNombre(ePersona*);
int setDNI(ePersona*, char*);
char* getDNI(ePersona*);
void alta(ArrayList*);
void mostrar(ArrayList*);
void mostrarUno(ePersona*);
int buscarDNI(ArrayList*, char*);
void baja(ArrayList*);
void Modificacion(ArrayList*);
void guardarArchivo(ArrayList*);
FILE* crearArchivo(char*);
FILE* leerArchivo(char*);
void cargarArchivo(ArrayList*);
int menu(ArrayList*);
int validar_num(char*);
void gotoxy(int x, int y);
void pintarLineas(ArrayList*);
int compararPersonas(void*,void*);
void ordenar(ArrayList* this);
