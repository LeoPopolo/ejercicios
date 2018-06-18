#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "funciones.h"
#include "ArrayList.h"


int main()
{
    ArrayList* lista = al_newArrayList();
    int opcion;
    cargarArchivo(lista);
    system("cls");
    printf("Bienvenido.\n\ncargando datos...");
    Sleep(1000);

    do
    {
        system("cls");

        switch(opcion = menu(lista))
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
            ordenar(lista);
            break;
        case 6:
            guardarArchivo(lista);
            break;
        default:
            printf("\nOpcion incorrecta.\n");
            Sleep(1000);
            break;
        }
    }
    while(opcion != 6);

    return 0;
}
