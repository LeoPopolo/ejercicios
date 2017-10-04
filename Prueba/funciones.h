typedef struct
{
    int id;
    int dni;
    char nombre[20];
    char apellido[20];
    int estado;
}ePersona;
typedef struct
{
    char operador[20];
    int equipo;
    int tiempo;
    int estado;
    int tiemporeal;
}eAlquiler;
typedef struct
{
    int id;
    int equipo;
    int estado;
}eAlquila;
int buscarDni(int dni, ePersona lista[],int tam);
void inicializarvector(ePersona lista[],int tam);
int buscarId(int id, ePersona lista[],int tam);
void inicializarvectorAlquiler(eAlquiler lista[],int tam);
int buscarLibreAlquiler(eAlquiler lista[],int tam);
void altaPersona(ePersona lista[],int tam);
int buscarLibre(ePersona lista[],int tam);
int buscarPersona(int id, ePersona lista[],int tam);
void mostrarPersona(ePersona lista);
int mostrarPersonas(ePersona lista[],int tam);
void modificarPersona(ePersona lista[],int tam);
void bajaPersona(ePersona lista[], int tam);
void nuevoAlquiler(eAlquiler alquiler[],int tamA,ePersona lista[],int tamP,eAlquila alquila[],int tamal);
void finalizarAlquiler(eAlquiler alquiler[], int tamA,ePersona lista[],int tamP,eAlquila alquila[],int tamal);
int buscarEquipo(int equipo,eAlquila alquila[],int tam);
void clienteCMasAlq(eAlquila a[],int tamA, eAlquiler Al[],int tamAl);
