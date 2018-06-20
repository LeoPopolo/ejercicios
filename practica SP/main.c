#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "ArrayList.h"
#include "funciones.h"

int main()
{
    ArrayList* lista = al_newArrayList();
    ArrayList* listaNegra = al_newArrayList();
    ArrayList* listaNueva = al_newArrayList();
    int opcion;

    do
    {
        system("cls");
        switch(opcion = menu())
        {
        case 1:
            parsear_archivo(lista);
            break;
        case 2:
            parsear_archivo_black(listaNegra);
            break;
        case 3:
            depurar(lista, listaNegra, listaNueva);
            break;
        case 4:
            mostrarListaDepurada(listaNueva);
            break;
        case 5:
            break;
        default:
            printf("Opcion incorrecta.\n");
            system("pause");
            break;
        }

    }
    while(opcion != 5);

    return 0;
}
