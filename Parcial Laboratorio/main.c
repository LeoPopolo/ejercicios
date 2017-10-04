#include <stdio.h>
#include <stdlib.h>
#include "estacionamiento.h"
#include <conio.h>

int main()
{
    int salir = 1;
    eDuenio lista1[20] = {{.idDuenio = 1, .nombYAp = "Juan", .direccion = "Falsa 123", .tarjeta = "1234 1234", .estado = 1}, {.idDuenio = 2, .nombYAp = "Pepe", .direccion = "SiempreViva 23", .tarjeta = "2345 2345", .estado = 1}};
    eAuto lista2[20] = {{.patente = "ALJ 892", .marca = "Ferrari",.idDuenio = 1,.horarioEnt = 15, .estado = 1},{.patente = "PHT 023", .marca = "Audi", .idDuenio = 2, .horarioEnt = 21, .estado = 1}};
    inicializarvector(lista1, 20);

    do
    {
        switch(menu())
        {
        case 1:
            system("cls");
            altaDuenio(lista1, 20);
            getch();
            break;
        case 2:

            break;
        case 3:
            system("cls");
            ingresoAuto(lista2, 20);
            getch();
            break;
        case 4:

            break;
        case 5:
            system("cls");
            mostrarAutosCDuenio(lista1,20,lista2,20);
            getch();
            break;
        }
    }
    while(salir);

    return 0;
}
