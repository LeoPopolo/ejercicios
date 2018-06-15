#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "ArrayList.h"

typedef struct
{
    int edad;
    char nombre[30];
    float altura;
    char DNI[12];
} ePersona;

ePersona* newPersona();
int setEdad(ePersona* lista, int edad);
int getEdad(ePersona* lista);
int setAltura(ePersona* lista, float altura);
float getAltura(ePersona* lista);
int setNombre(ePersona* lista, char* nombre);
char* getNombre(ePersona* lista);
int setDNI(ePersona* lista, char* dni);
char* getDNI(ePersona* lista);
void alta(ArrayList* this);
void mostrar(ArrayList* this);
void mostrarUno(ePersona* lista);
int buscarDNI(ArrayList* this, char* dni);
void baja(ArrayList* this);
void Modificacion(ArrayList* this);

int main()
{
    ArrayList* lista = al_newArrayList();
    int opcion;

    do
    {
        system("cls");
        printf("1.Alta\n2.Baja\n3.Modificacion\n4.mostrar\n5.Salir\n\ningrese: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            alta(lista);
            break;
        case 2:
            baja(lista);
            break;
        case 3:
            Modificacion(lista);
            break;
        case 4:
            mostrar(lista);
            system("pause");
            break;
        case 5:
            break;
        }
    }
    while(opcion < 5);

    return 0;
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

int setDNI(ePersona* lista, char* dni)
{
    int aux = -1;

    if(lista != NULL)
    {
        if(strlen(dni) > 5 && strlen(dni) < 11)
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
            }
            while(setDNI(persona, dni) == -1);
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
            persona = this->get(this, i);
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

    if(this != NULL && lista != NULL)
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
}

void Modificacion(ArrayList* this)
{
    ePersona* lista = newPersona();
    int buscar;
    char dni[12], opcion, nombre[30];

    if(this != NULL && lista != NULL)
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
            printf("\ndesea modificar el nombre de esta persona? s/n\n\n");
            mostrarUno(lista);
            fflush(stdin);
            opcion = getch();
            if(opcion == 's')
            {
                do
                {
                    system("cls");
                    printf("Ingrese nombre: ");
                    fflush(stdin);
                    scanf("%[^\n]", nombre);
                }
                while(setNombre(lista, nombre) == -1);
            }
            printf("\nModificacion exitosa.\n\n");
            system("pause");
        }
    }

}

void mostrarUno(ePersona* lista)
{
    printf("%-5d%-20s%-4.2f%10s\n", getEdad(lista), getNombre(lista), getAltura(lista), getDNI(lista));
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
            printf("Edad    Nombre\t\t\tAltura\tDNI\n\n");
            for(i=0; i<this->len(this); i++)
            {
                lista = (ePersona*)this->get(this, i);
                mostrarUno(lista);
            }
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
