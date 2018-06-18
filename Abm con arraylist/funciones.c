#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "funciones.h"
#include "ArrayList.h"

int menu(ArrayList* this)
{
    char opcion[20];
    int esNum;

    system("cls");
    printf("Personas cargadas: %d", this->len(this));
    printf("\n\n1.Alta\n2.Baja\n3.Modificacion\n4.Mostrar\n5.Ordenar lista\n6.Guardar y salir\n\ningrese: ");

    fflush(stdin);
    scanf("%[^\n]", opcion);
    esNum = validar_num(opcion);

    while(esNum == 1)
    {
        system("cls");
        printf("1.Alta\n2.Baja\n3.Modificacion\n4.Mostrar\n5.Ordenar lista\n6.Guardar y salir\n\ningrese: ");
        fflush(stdin);
        scanf("%[^\n]", opcion);
        esNum = validar_num(opcion);
    }

    esNum = atoi(opcion);

    return esNum;
}

int setEdad(ePersona* lista, int edad)
{
    int aux = -1;

    if(lista != NULL)
    {
        if(edad > 0 && edad < 151)
        {
            lista->edad = edad;
            aux = 0;
        }
    }

    return aux;
}

int getEdad(ePersona* lista)
{
    int aux;

    if(lista != NULL)
    {
        aux = lista->edad;
    }
    return aux;
}

int setNombre(ePersona* lista, char* nombre)
{
    int aux = -1;

    if(lista != NULL)
    {
        if(strlen(nombre) > 0 && strlen(nombre) < 30)
        {
            strcpy(lista->nombre, nombre);
            aux = 0;
        }
    }

    return aux;
}

char* getNombre(ePersona* lista)
{
    char* aux = (char*) malloc(sizeof(char)*30);

    if(lista != NULL && aux != NULL)
    {
        strcpy(aux, lista->nombre);
    }
    return aux;
}

int dniExiste(ArrayList* this, char* dni)
{
    int i, retorno = 0;
    ePersona* aux;

    for(i=0; i<this->len(this); i++)
    {
        aux = (ePersona*) this->get(this, i);

        if(strcmp(aux->DNI, dni) == 0)
        {
            retorno = 1;
            break;
        }
    }

    return retorno;
}

int setDNI(ePersona* lista, char* dni)
{
    int aux = -1;

    if(lista != NULL)
    {
        if(strlen(dni) > 5 && strlen(dni) < 11  && validar_num(dni) == 0)
        {
            strcpy(lista->DNI, dni);
            aux = 0;
        }
    }

    return aux;
}

char* getDNI(ePersona* lista)
{
    char* aux = (char*) malloc(sizeof(char)*30);

    if(lista != NULL && aux != NULL)
    {
        strcpy(aux, lista->DNI);
    }
    return aux;
}

int setAltura(ePersona* lista, float altura)
{
    int aux = -1;

    if(lista != NULL)
    {
        if(altura > 0 && altura < 3)
        {
            lista->altura = altura;
            aux = 0;
        }
    }

    return aux;
}

float getAltura(ePersona* lista)
{
    float aux;

    if(lista != NULL)
    {
        aux = lista->altura;
    }
    return aux;
}

void alta(ArrayList* this)
{
    ePersona* persona;
    int edad;
    float altura;
    char nombre[30], dni[12];

    if(this != NULL)
    {
        persona = newPersona();

        if(persona != NULL)
        {
            do
            {
                printf("Ingrese edad: ");
                scanf("%d", &edad);
            }
            while(setEdad(persona, edad) == -1);
            do
            {
                printf("Ingrese nombre: ");
                fflush(stdin);
                scanf("%[^\n]", nombre);
            }
            while(setNombre(persona, nombre) == -1);
            do
            {
                printf("Ingrese DNI: ");
                fflush(stdin);
                scanf("%[^\n]", dni);
                if(dniExiste(this, dni) == 1)
                {
                    printf("el dni ya existe.\n\n");
                }
            }
            while(setDNI(persona, dni) == -1 || dniExiste(this, dni) == 1);
            do
            {
                printf("Ingrese altura: ");
                scanf("%f", &altura);
            }
            while(setAltura(persona, altura) == -1);
            this->add(this, persona);
            printf("\nAlta exitosa.\n\n");
            system("pause");
        }
    }
}

int buscarDNI(ArrayList* this, char* dni)
{
    int aux = -1, i;
    ePersona* persona = newPersona();

    if(this != NULL && dni != NULL)
    {
        for(i=0; i<this->len(this); i++)
        {
            persona = (ePersona*)this->get(this, i);
            if(strcmp(persona->DNI, dni) == 0)
            {
                aux = i;
            }
        }
    }

    return aux;
}

void baja(ArrayList* this)
{
    ePersona* lista = newPersona();
    int buscar;
    char dni[12], opcion;

    if(this != NULL && lista != NULL && this->isEmpty(this) != 1)
    {
        mostrar(this);
        printf("\ningrese dni a buscar: ");
        fflush(stdin);
        scanf("%[^\n]", dni);
        buscar = buscarDNI(this, dni);
        if(buscar == -1)
        {
            printf("No se encontro el dni.\n\n");
            system("pause");
        }
        else
        {
            lista = (ePersona*)this->get(this, buscar);
            system("cls");
            printf("\ndesea eliminar esta persona? s/n\n\n");
            mostrarUno(lista);
            fflush(stdin);
            opcion = getch();
            if(opcion == 's')
            {
                this->remove(this, buscar);
            }
            printf("\nBaja exitosa.\n\n");
            system("pause");
        }
    }
    else if(this->isEmpty(this) == 1)
    {
        printf("No hay datos cargados.\n\n");
        system("pause");
    }
}

void Modificacion(ArrayList* this)
{
    ePersona* lista = newPersona();
    int buscar, eleccion;
    char dni[12], opcion, nombre[30];
    int edad;
    float altura;

    if(this != NULL && lista != NULL && this->isEmpty(this) != 1)
    {
        mostrar(this);
        printf("\ningrese dni a buscar: ");
        fflush(stdin);
        scanf("%[^\n]", dni);
        buscar = buscarDNI(this, dni);
        if(buscar == -1)
        {
            printf("No se encontro el dni.\n\n");
            system("pause");
        }
        else
        {
            lista = this->get(this, buscar);
            system("cls");
            printf("\ndesea modificar esta persona? s/n\n\n");
            mostrarUno(lista);
            fflush(stdin);
            opcion = getch();
            if(opcion == 's' )
            {
                do
                {
                    system("cls");
                    printf("1-Nombre\n2-Edad\n3-Altura\n4-DNI\n5-Volver\n\nIngrese opcion: ");
                    scanf("%d", &eleccion);
                    switch(eleccion)
                    {
                    case 1:
                        do
                        {
                            printf("Ingrese nombre: ");
                            fflush(stdin);
                            scanf("%[^\n]", nombre);
                        }
                        while(setNombre(lista, nombre) == -1);
                        break;
                    case 2:
                        do
                        {
                            printf("Ingrese edad: ");
                            scanf("%d", &edad);
                        }
                        while(setEdad(lista, edad) == -1);
                        break;
                    case 3:
                        do
                        {
                            printf("Ingrese altura: ");
                            fflush(stdin);
                            scanf("%f", &altura);
                        }
                        while(setAltura(lista, altura) == -1);
                        break;
                    case 4:
                        do
                        {
                            printf("Ingrese DNI: ");
                            fflush(stdin);
                            scanf("%[^\n]", dni);
                        }
                        while(setDNI(lista, dni) == -1);
                        break;
                    case 5:
                        break;
                    }

                }
                while(opcion < 5);
                printf("\nModificacion exitosa.\n\n");
                system("pause");
            }

        }
    }
    if(this->isEmpty(this) == 1)
    {
        printf("No hay datos cargados.\n\n");
        system("pause");
    }
}

void mostrarUno(ePersona* lista)
{
    printf("%-5d%-20s%-5.2f %10s\n", getEdad(lista), getNombre(lista), getAltura(lista), getDNI(lista));
}

void pintarLineas(ArrayList* this)
{
    int i, size;
    size = this->len(this) +2;

    for(i=0; i<size; i++)
    {
        gotoxy(4, i);
        printf("%c", 186);
        gotoxy(24, i);
        printf("%c", 186);
        gotoxy(31, i);
        printf("%c", 186);
        gotoxy(42, i);
        printf("%c", 186);
    }
    for(i=0; i<43; i++)
    {
        gotoxy(i, size);
        printf("%c", 205);
    }
    gotoxy(4, size);
    printf("%c", 202);
    gotoxy(24, size);
    printf("%c", 202);
    gotoxy(31, size);
    printf("%c", 202);
    gotoxy(42, size);
    printf("%c", 188);
}

void mostrar(ArrayList* this)
{
    int i;
    ePersona* lista = newPersona();

    if(this != NULL && lista != NULL)
    {
        system("cls");
        if(this->isEmpty(this) == 1)
        {
            printf("La lista esta vacia.\n");
        }
        else
        {
            printf("Edad Nombre              Altura DNI       \n\n");
            for(i=0; i<this->len(this); i++)
            {
                lista = (ePersona*)this->get(this, i);
                mostrarUno(lista);
            }
            pintarLineas(this);
        }
        printf("\n\n");

    }
}

ePersona* newPersona()
{
    ePersona* aux = (ePersona*) malloc(sizeof(ePersona));

    if(aux != NULL)
    {
        strcpy(aux->nombre, "");
        strcpy(aux->DNI, "");
        aux->edad = 0;
        aux->altura = 0;
    }

    return aux;
}

FILE* leerArchivo(char* path)
{
    FILE* archivo;

    if((archivo = fopen(path, "rb")) == NULL)
    {
        printf("\nNo se pudo abrir el archivo\n");
    }

    return archivo;
}

FILE* crearArchivo(char* path)
{
    FILE* archivo;

    if((archivo = fopen(path, "wb")) == NULL)
    {
        printf("\nNo se pudo abrir el archivo\n");
    }

    return archivo;
}

void guardarArchivo(ArrayList* this)
{
    int i;
    ePersona* lista;
    FILE* f = crearArchivo("lista.bin");

    if(this != NULL)
    {
        if(f != NULL)
        {
            rewind(f);
            for (i=0; i < this->len(this); i++)
            {
                lista = (ePersona*)this->get(this, i);

                fwrite(lista, sizeof(ePersona), 1, f);
            }
            fclose(f);
        }
    }
}

void cargarArchivo(ArrayList* this)
{
    FILE* archivo = leerArchivo("lista.bin");
    ePersona aux;
    int validar;
    ePersona* lista;
    rewind(archivo);
    if(archivo != NULL)
    {
        while (!feof(archivo))
        {
            validar = fread(&aux, sizeof(ePersona), 1, archivo);
            lista = newPersona();
            if(validar == 1 && lista != NULL)
            {
                strcpy(lista->nombre, aux.nombre);
                strcpy(lista->DNI, aux.DNI);
                lista->edad = aux.edad;
                lista->altura = aux.altura;
                this->add(this, lista);
            }

            if(validar!=1)
            {
                if(feof(archivo))
                {
                    break;
                }
                else
                {
                    printf("No leyo el ultimo registro\n");
                    system("pause");
                    break;
                }
            }

        }
        printf("\nArchivo cargado.\n\n");
        system("pause");

        fclose(archivo);
    }
}

int validar_num(char* opcion)
{
    int i, flag = 0, size;

    size = strlen(opcion);

    for(i=0; i<size; i++)
    {
        if(*(opcion+i) < 48  || *(opcion+i) > 57)
        {
            flag = 1;
            break;
        }
    }

    return flag;
}

void ordenar(ArrayList* this)
{
    this->sort(this,compararPersonas,1);

    printf("lista ordenada!!\n\n");
    system("pause");
}

int compararPersonas(void* personaA,void* personaB)
{
    if(personaA != NULL && personaB != NULL){

    ePersona* perA = (ePersona*) personaA;
    ePersona* perB = (ePersona*) personaB;
    return strcmp(perA->nombre, perB->nombre);
    }
    return 0;
}

void gotoxy(int x, int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}

