#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "ArrayList.h"
#include "funciones.h"

int menu()
{
    char opcion[20];
    int esNum;

    system("cls");
    printf("1- Cargar archivo de destinatarios.\n2- Cargar lista negra.\n3- Depurar lista.\n4- Listar destinatarios.\n5- Salir.\n\nIngrese opcion: ");
    fflush(stdin);
    scanf("%[^\n]", opcion);
    esNum = validar_num(opcion);

    while(esNum == 1)
    {
        system("cls");
        printf("1- Cargar archivo de destinatarios.\n2- Cargar lista negra.\n3- Depurar lista.\n4- Listar destinatarios.\n5- Salir.\n\nIngrese opcion: ");
        fflush(stdin);
        scanf("%[^\n]", opcion);
        esNum = validar_num(opcion);
    }

    esNum = atoi(opcion);

    return esNum;
}

void parsear_archivo(ArrayList* pList)
{
    int cant;
    char auxName[30], auxEmail[40];
    char* path = (char*) malloc(sizeof(char)*96);
    FILE* f = NULL;
    eDestinatario* listaDes;
    if(pList != NULL)
    {
        if(path != NULL)
        {
            do
            {
                printf("Ingrese nombre del archivo: ");
                fflush(stdin);
                scanf("%[^\n]", path);
            }
            while(strlen(path) > 95);
        }
        else
        {
            printf("No se puede guardar el nombre.\n");
            system("pause");
        }

        f = fopen(path, "r");

        if(f != NULL)
        {
            while(!feof(f))
            {
                cant = fscanf(f, "%[^,],%[^\n]\n", auxName, auxEmail);
                listaDes = newDestinatario();

                if(cant != 2)
                {
                    printf("No se pudo cargar el archivo.\n");
                    system("pause");
                    break;
                }
                else
                {
                    strcpy(listaDes->name, auxName);
                    strcpy(listaDes->email, auxEmail);
                    pList->add(pList, listaDes);
                }

            }
            printf("Archivo cargado.\n");
            system("pause");

        }
        else
        {
            printf("no se pudo abrir el archivo.\n");
            system("pause");
        }
    }


}

void parsear_archivo_black(ArrayList* pList)
{
    int cant;
    char auxName[30], auxEmail[40];
    char* path = (char*) malloc(sizeof(char)*96);
    FILE* f = NULL;
    eDestinatario* listaDes;

    if(pList != NULL)
    {
        if(path != NULL)
        {
            do
            {
                printf("Ingrese nombre del archivo: ");
                fflush(stdin);
                scanf("%[^\n]", path);
            }
            while(strlen(path) > 95);
        }
        else
        {
            printf("No se puede guardar el nombre.\n");
            system("pause");
        }

        f = fopen(path, "r");

        if(f != NULL)
        {
            while(!feof(f))
            {
                cant = fscanf(f, "%[^,],%[^\n]\n", auxName, auxEmail);
                listaDes = newDestinatario();

                if(cant != 2)
                {
                    printf("No se pudo cargar el archivo.\n");
                    system("pause");
                    break;
                }
                else
                {
                    strcpy(listaDes->name, auxName);
                    strcpy(listaDes->email, auxEmail);
                    pList->add(pList, listaDes);
                }
            }
            printf("Archivo cargado.\n");
            system("pause");

        }
        else
        {
            printf("no se pudo abrir el archivo.\n");
            system("pause");
        }
    }

}

void depurar(ArrayList* lista, ArrayList* listaNegra, ArrayList* listaNueva, int* par)
{
    int i,j, vacio = 0;
    int flagAdd;
    eDestinatario* destinatarioA;
    eDestinatario* destinatarioB;
    if(*par == 0)
    {
        if(lista!=NULL && listaNegra!=NULL && listaNueva != NULL)
        {
            for(i=0; i<(lista->len(lista)); i++)
            {
                destinatarioA=lista->get(lista,i);
                flagAdd=0;
                for(j=0; j<(listaNegra->len(listaNegra)); j++)
                {
                    destinatarioB=listaNegra->get(listaNegra,j);
                    if(strcmp(destinatarioA->email,destinatarioB->email)==0 && strcmp(destinatarioA->name,destinatarioB->name)==0)
                    {
                        vacio = 1;
                        flagAdd=1;
                        break;
                    }
                }
                if(flagAdd==0)
                {
                    listaNueva->add(listaNueva,destinatarioA);
                }
            }
            if(vacio == 0)
            {
                printf("Lista vacia.\n");
                system("pause");
            }
            else
            {
                printf("Lista depurada.\n");
                system("pause");
                *par = 1;
            }
        }
    }
    else
    {
        printf("la lista ya ha sido depurada.\n");
        system("pause");
    }



}

void mostrarListaDepurada(ArrayList* lista)
{
    int i, salida = 0;
    eDestinatario* aux = NULL;
    aux = newDestinatario();

    system("cls");
    if(aux!= NULL)
    {
        for(i=0; i<lista->len(lista); i++)
        {
            aux = lista->get(lista, i);

            printf("%-3d %-20s\t%-30s\n",i+1 ,aux->name, aux->email);
            salida = 1;
        }
    }
    if(salida == 0)
    {
        printf("no hay elementos para mostrar\n");
        system("pause");
    }
    fflush(stdin);
    system("pause");

}

eDestinatario* newDestinatario()
{
    eDestinatario* aux = NULL;

    aux = (eDestinatario*) malloc(sizeof(eDestinatario));

    return aux;
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

