#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "estacionamiento.h"

#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTROS 4

int menu()
{
    int opcion;

    system("cls");
    printf("\t\t\t**ESTACIONAMIENTO**\n\n");
    printf("1.Alta de duenio.\n");
    printf("2.Modificacion de duenio.\n");
    printf("3.Ingreso del automovil.\n");
    printf("4.Egreso del automovil.\n");
    printf("5.Informe.\n");
    printf("\nIngrese opcion: ");
    scanf("%d",&opcion);
    while(opcion < 1 || opcion > 5)
    {
        printf("Error. opcion incorrecta.\nIngrese nuevamente: ");
        scanf("%d",&opcion);
    }

    return opcion;
}

void inicializarvector(eDuenio lista[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        lista[i].estado=0;
    }
}
void inicializarvectorAuto(eAuto lista[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        lista[i].estado=0;
    }
}
int buscarLibre(eDuenio lista[],int tam)
{
    int indice=-1;
    for(int i=0; i<tam; i++)
    {
        if(lista[i].estado==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
int buscarLibreAuto(eAuto lista[],int tam)
{
    int indice=-1;
    for(int i=0; i<tam; i++)
    {
        if(lista[i].estado==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
int buscarAuto(char patente[], eAuto lista[],int tam)
{
    int indice=-1;
    for(int i=0; i<tam; i++)
    {
        if(lista[i].patente==patente && lista[i].estado==1)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
int buscarDuenio(int id, eDuenio lista[],int tam)
{
    int indice=-1;
    for(int i=0; i<tam; i++)
    {
        if(lista[i].idDuenio==id && lista[i].estado==1)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

void mostrarAutosCDuenio(eDuenio D[],int tamD,eAuto A[],int tamA)
{
    printf("---Autos con Duenios---\n\n");
    printf("\nMarca\tPatente\tNombre y apellido\tDireccion\tTarjeta\n");
    printf("\n-------------------------------------------------------------------------------\n");
    for(int i=0; i<tamA; i++)
    {
        if(A[i].estado==1)
        {
            printf("%s\t%s\t",A[i].marca, A[i].patente);
        }
        for(int j=0; j<tamD; j++)
        {
            if(D[i].idDuenio==A[j].idDuenio && A[j].estado == 1)
            {
                printf("\t%s\t\t%s\t%s\t\n",D[j].nombYAp, D[j].direccion, D[j].tarjeta);
                break;
            }
        }
    }
}
void altaDuenio(eDuenio lista[],int tam)
{
    int lugar;
    int id;
    int esta;
    lugar = buscarLibre(lista,tam);
    if(lugar==-1)
    {
        printf("\nNo hay lugar en el sistema.\n");
    }
    else
    {
        printf("\nIngrese Id: ");
        fflush(stdin);
        scanf("%d",&id);
        esta = buscarDuenio(id,lista,tam);
        if(esta!=-1)
        {
            printf("\nEl ID: %d ya se encuentra registrado en el sistema. \n",id);
        }
        else
        {
            lista[lugar].idDuenio=id;
            printf("Ingrese nombre y apellido: ");
            fflush(stdin);
            gets(lista[lugar].nombYAp);
            printf("Ingrese direccion domiciliaria: ");
            gets(lista[lugar].direccion);
            printf("Nro de tarjeta de credito: ");
            gets(lista[lugar].tarjeta);
            lista[lugar].estado=1;
            lista[lugar].idDuenio=lugar;
        }
    }
}
void ingresoAuto(eAuto lista[],int tam)
{
    int lugar;
    char patente[10];
    int esta;
    lugar=buscarLibreAuto(lista,tam);
    if(lugar==-1)
    {
        printf("\nNo hay lugar en el sistema.\n");
    }
    else
    {
        printf("\nIngrese patente: ");
        fflush(stdin);
        gets(patente);
        esta=buscarAuto(patente,lista,tam);
        if(esta!=-1)
        {
            printf("\nLa patente: %s ya se encuentra registrada en el sistema. \n",patente);
        }
        else
        {
            strcpy(lista[lugar].patente,patente);
            printf("Ingrese marca del automovil: \n1.Alpha Romeo\t2.Ferrari\t3.Audi\t   4.Otro. ");
            scanf("%d",&lista[lugar].marca);
            printf("Ingrese ID de dueño del auto: ");
            scanf("%d",&lista[lugar].idDuenio);
            printf("Horario de entrada (24hs): ");
            scanf("%d",&lista[lugar].horarioEnt);
            lista[lugar].estado=1;
        }
    }
}
