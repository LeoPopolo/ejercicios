#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"

int parseo(FILE*, ArrayList*);

int main()
{
    FILE *f;
    ArrayList *pList;
    int respuesta;

    pList = al_newArrayList();

    f = fopen("destinatarios.csv", "r");

    if(f==NULL)
    {
        printf("no se encontro el archivo.\n");
    }
    else
    {
        printf("el archivo fue cargado con exito.\n");
    }
    respuesta = menu();
    parseo(f, pList);

    return 0;
}

int menu()
{
    int respuesta;
    printf("\nmenu: \n\n1-Cargar destinatarios.\n2-Cargar lista negra.\n3-Depurar.\n4-Listar.\n\ningrese opcion: ");
    scanf("%d", &respuesta);

    do
    {
        switch(respuesta)
        {
            case 1:
            printf("Cargar destinatarios.");
            break;
            case 2:
            printf("Cargar lista negra.");
            break;
            case 3:
            printf("Depurar.");
            break;
            case 4:
            printf("Listar.");
            break;
            default:
            printf("opcion invalida.\n");
            break;
        }
    }while(!respuesta);

    return respuesta;
}

int parseo(FILE* pFile, ArrayList* this)
{
    char auxNombre[20];
    char auxEmail[50];

    if(pFile == NULL || this == NULL){
            return -1;
    }
    while(!feof(pFile)){
         fscanf(pFile, "%[^,],%s\n", auxInt, auxNombre, auxApellido, auxEmpty);

    return ;
}
