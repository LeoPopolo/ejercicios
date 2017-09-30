#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"

void variablesCero(eProgramador lista1[],int i, int tamProg)
{
    for(i=0; i<tamProg; i++)
    {
        strcpy(lista1[i].nombre,"\0");
        lista1[i].sueldo=0;
        lista1[i].estado=0;
        lista1[i].idProg=0;
    }

}

void inicializarVariables(eProgramador lista1[],int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        variablesCero(lista1,i, 3);
    }
}

int buscarProgramador(int id, eProgramador lista1[],int tam)
{
    int i;
    int flag=-1;

    for(i=0; i<tam; i++)
    {
        if(lista1[i].estado==1 && lista1[i].idProg==id)
        {
            flag=i;
            break;
        }
    }
    return flag;
}

void mostrarProgram(eProgramador lista1[], eCategoria lista2[], eProyecto lista3 [], ePPC lista4[], int tamProg, int tamProy, int tamCat)
{
    int id;
    int i, j, k;
    int estaProg;
    float sueldo;

    printf("Ingrese el id: ");
    scanf("%d", &id);
    estaProg = buscarProgramador(id, lista1, tamProg);
    sueldo = calcularSueldo(lista1, lista3, lista2, lista4, tamProg);

    if(estaProg != -1)
    {
        printf("id\tnombre\t\tproyecto\tcategoria\tsueldo\n");
        printf("----------------------------------------------------------------------\n");
        printf("%d\t%s\t\t",lista1[estaProg].idProg, lista1[estaProg].nombre);

        for(j=0; j<tamProy; j++)
        {
            if(id == lista4[j].idProy)
            {
                for(k=0; k<tamProy; k++)
                {
                    if(lista4[k].idProy == lista3[k].idProy)
                    {
                        printf("%s\t", lista3[estaProg].nombreProy);
                        break;
                    }
                }
            }
        }
        for(i=0; i<tamCat; i++)
        {
            if(id == lista2[i].idCat)
            {
                printf("\t%s\t\t%.2f",lista2[estaProg].nombreCat, sueldo);
            }
        }
    }
    else
    {
        printf("el programador no existe.");
    }
    printf("\n\n");
}

int calcularSueldo(eProgramador lista1[], eCategoria lista2[], eProyecto lista3[], ePPC lista4[], int tamProg)
{
    int i;
    float result;

    for(i=0; i<tamProg; i++)
    {
        lista1[i].sueldo = lista2[i].valorPH * lista3[i].hsProy;
        result = lista1[i].sueldo;
    }

    return result;
}

