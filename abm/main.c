#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include "Empleados.h"

#define TAM 50


int main()
{
    eEmpleado lista[TAM];
    inicializarVariables(lista, TAM);

    do
    {
        system("cls");
        switch(menu())
        {
        case 1:
            alta(lista, TAM);
            break;
        case 2:
            baja(lista, TAM);
            break;
        case 3:
            modificacion(lista, TAM);
            break;
        case 4:
            mostrarTodos(lista, TAM);
            system("pause");
            break;
        case 5:
            ordenamiento(lista, TAM);
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
