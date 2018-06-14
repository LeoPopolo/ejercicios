typedef struct
{
    char name[20];
    char email[30];
}eDestinatario;

void parsear_archivo(ArrayList* );
void parsear_archivo_black(ArrayList* );
void depurar(ArrayList* , ArrayList* , ArrayList* , int*);
void mostrarListaDepurada(ArrayList* );
int menu();
eDestinatario* newDestinatario();
int validar_num(char* opcion);
