#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>
#include "input.h"
#include "productos.h"

void gotoxy(int x,int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}

int menu()
{
    char opcion[30];
    int datoInt;

    gotoxy(35, 1);
    printf("--Proveedores--\n\n");
    gotoxy(30, 3);
    printf("1. Alta de producto");
    gotoxy(30, 4);
    printf("2. Modificar producto");
    gotoxy(30, 5);
    printf("3. Baja de producto");
    gotoxy(30, 6);
    printf("4. Informar...");
    gotoxy(30, 7);
    printf("5. Listar...");
    gotoxy(30, 8);
    printf("6. Salir");
    gotoxy(30, 9);
    printf("Ingrese opcion: ");
    scanf("%s", opcion);

    while (validarLetra(opcion)== 1)
    {
        printf("Usted no puede ingresar un caracter!\nIngrese un numero ente 1 y 6:");
        scanf("%s",opcion);
    }

    datoInt = atoi(opcion);

    return datoInt;
}

int ingresoCantVal()
{
    char opcion[30];
    int datoInt;

    printf("Ingrese cantidad de productos: ");
    scanf("%s", opcion);

    while (validarLetra(opcion)== 1)
    {
        printf("Usted no puede ingresar un caracter!\nIngrese una cantidad valida: ");
        scanf("%s",opcion);
    }

    datoInt = atoi(opcion);

    return datoInt;
}

int validarLetra(char opcion[])
{
    int flag = 0,cant,i;

    cant = strlen(opcion);

    for(i=0; i<cant; i++)
    {
        if(!isdigit(opcion[i]))
        {
            flag = 1;
            break;
        }
    }
    return flag;
}

int menuOpcion4()
{
    int opcion;

    system("cls");
    printf("Informar:\n\n1. Total y promedio de los importes. Y cuantos productos superan ese promedio\n");
    printf("2. Total y promedio de los importes. Y cuantos productos no superan ese promedio\n");
    printf("3. Cantidad de productos cuyo stock es menor o igual a 10\n");
    printf("4. Cantidad de productos cuyo stock es mayor a 10\n");
    printf("5. Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int menuOpcion5()
{
    int opcion;

    system("cls");
    printf("Informar:\n\n1. Listado de los productos\n");
    printf("2. Listado de productos cuyo stock es menor o igual a 10\n");
    printf("3. Listado de productos cuyo stock es mayor a 10\n");
    printf("4. Listado de productos cuyo importe no supera el promedio\n");
    printf("5. Listado de productos cuyo importe supera el promedio\n");
    printf("6. Listado de proveedores cuyo producto es menor a 10\n");
    printf("7. Todos los productos de un proveedor\n");
    printf("8. Productos de proveedor a buscar\n");
    printf("9. Proveedor con mas productos\n");
    printf("10. Proveedor con menos productos\n");
    printf("11. Proveedor con el producto mas caro\n");
    printf("12. Proveedor con el producto mas barato\n");
    printf("13. Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
