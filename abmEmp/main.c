#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "Empleados.h"

#define TAM 50

/**
    1. listar todos los empleados

    recorrer las dos listas. primer for empleados, segundo for sectores
    if(emp[i].idSector == sec[j].id)
        estructura empleado = [i]
        estructura sector = [j]

    2. listar los sectores por empleado

    recorrer las dos listas. primer for sectores, segundo for empleados
    if(emp[j].idSector == sec[i].id)
        estructura empleado = [j]
        estructura sector = [i]


**/

int main()
{
    eEmpleado lista[TAM];
    eSector sectorLista[5];
    inicializarVariables(lista, TAM);
    hardcodeo(sectorLista);

    do
    {
        system("cls");
        switch(menu())
        {
        case 1:
            alta(lista, TAM, sectorLista);
            break;
        case 2:
            baja(lista, TAM);
            break;
        case 3:
            modificacion(lista, TAM);
            break;
        case 4:
            menuListas(lista, sectorLista, 50, 5);
            //mostrarTodos(lista, TAM);
            system("pause");
            break;
        case 5:
            ordenar(lista, TAM);
            break;
        case 6:
            exit(1);
            break;
        default:
            printf("opcion incorrecta.");
            getch();
            break;

        }
    }
    while(1);

    return 0;
}

