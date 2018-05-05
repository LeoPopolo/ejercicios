#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>
#include "Empleados.h"

#define TAM 50

int main()
{
    system("color f0");
    eEmpleado lista[TAM];
    eSector sectores[5];
    inicializarVariables(lista, TAM);
    inicializarSectores(sectores, 5);
    hardcodeo(sectores);
    int salir = 0, legajo = 1;


    do
    {
        system("cls");
        switch(menu())
        {
        case 1:
            alta(lista, TAM, legajo);
            legajo++;
            break;
        case 2:
            baja(lista, TAM, sectores);
            break;
        case 3:
            modificacion(lista, TAM, sectores);
            break;
        case 4:

            do
            {
                switch(menuOpcion())
                {
                case 1:
                    mostrarTodos(lista, TAM, sectores, 5);
                    break;
                case 2:
                    mostrarSectoresConCantidadDeEmpleados(lista, 50, sectores, 5);
                    mostrarSectores(lista, TAM, sectores, 5);
                    break;
                case 3:
                    salir = 1;
                    break;
                }
            }
            while(salir != 1);

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
