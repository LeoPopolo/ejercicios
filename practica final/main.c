#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include "ArrayList.h"
#include "funciones.h"

int main()
{
    printf("Bienvenido. Cargando datos.\n");
    ArrayList* lista = al_newArrayList();
    ArrayList* ventas = al_newArrayList();
    int opcion;

    do
    {
        system("cls");

        switch(opcion = menu(lista))
        {
        case 1:
            alta(lista);
            break;
        case 2:
            Modificacion(lista);
            break;
        case 3:
            baja(lista);
            break;
        case 4:
            mostrar(lista);
            system("pause");
            break;
        case 5:
            parsearArchivo(lista);
            break;
        case 6:
            venta(lista, ventas);
            break;
        case 7:
            informeDeVenta(ventas);
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        default:
            printf("\nOpcion incorrecta.\n");
            Sleep(1000);
            break;
        }
    }
    while(opcion != 10);

    return 0;
}
