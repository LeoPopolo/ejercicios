#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include "Empleados.h"

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
    int opcion;

    printf("--Empleados--\n\n");
    printf("1. Alta empleados");
    printf("\n2. Baja empleados");
    printf("\n3. Modificar sueldo");
    printf("\n4. Listar empleados");
    printf("\n5. Ordenar ascendentemente");
    printf("\n6. Salir");
    printf("\nIngrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void inicializarVariables(eEmpleado vec[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].legajo = 0;
        vec[i].isEmpty = 1;
    }
}

int buscarLibre(eEmpleado lista[], int tam)
{
    int flag = -1;

    for(int i=0; i < tam; i++)
    {
        if(lista[i].isEmpty == 1)
        {
            flag = i;
        }
    }

    return flag;
}

int buscarLegajo(eEmpleado lista[], int tam, int legajo)
{
    int flag = -1;

    for(int i=0; i<tam; i++)
    {
        if(lista[i].legajo == legajo && lista[i].isEmpty == 0)
        {
            flag = i;
            break;
        }
    }

    return flag;
}

void mostrar(eEmpleado lista)
{
    char aux[13];

    if(lista.categoria == 'a')
    {
        strcpy(aux, "Junior");
    }
    if(lista.categoria == 'b')
    {
        strcpy(aux, "Semisenior");
    }
    if(lista.categoria == 'c')
    {
        strcpy(aux, "Senior");
    }

    gotoxy(0, 3);
    printf("%d", lista.legajo);
    gotoxy(7, 3);
    printf("%s", lista.nombre);
    gotoxy(32, 3);
    printf("%d", lista.edad);
    gotoxy(37, 3);
    printf("%.2f", lista.sueldo);
    gotoxy(47, 3);
    printf("%s", aux);
    gotoxy(60, 3);
    printf("%d/%d/%d", lista.fechaIng.dia, lista.fechaIng.mes, lista.fechaIng.anio);
}

void mostrarTodos(eEmpleado lista[], int tam)
{
    int flag = -1;
    system("cls");
    gotoxy(0, 1);
    printf("Legajo");
    gotoxy(7, 1);
    printf("Nombre y Apellido");
    gotoxy(32, 1);
    printf("Edad");
    gotoxy(37, 1);
    printf("Sueldo");
    gotoxy(47, 1);
    printf("Categoria");
    gotoxy(60, 1);
    printf("Fecha de ingreso");

    for(int i=0; i<tam; i++)
    {
        if(lista[i].isEmpty == 0)
        {
            mostrar(lista[i]);
            flag = 1;
        }
    }
    printf("\n\n");
    if(flag != 1)
    {
        system("cls");
        printf("No hay empleados para mostrar.\n");
    }

}

void alta(eEmpleado lista[], int tam)
{
    eEmpleado nuevalista;
    int esta, libre, legajo;

    libre = buscarLibre(lista, tam);

    if(libre == -1)
    {
        system("cls");
        printf("No hay espacio para cargar.");
    }
    else
    {
        system("cls");
        printf("**ALTA**\n\n");
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);
        esta = buscarLegajo(lista, tam, legajo);
        if(esta != -1)
        {
            printf("\nYa existe el Legajo.\n");
            system("pause");
        }
        else
        {

            nuevalista.legajo = legajo;
            printf("Ingrese nombre y apellido: ");
            fflush(stdin);
            scanf("%[^\n]", nuevalista.nombre);
            while(strlen(nuevalista.nombre) > 28)
            {
                system("cls");
                printf("Nombre demasiado largo. Reingrese: ");
                fflush(stdin);
                scanf("%[^\n]", nuevalista.nombre);
            }
            printf("Ingrese edad: ");
            scanf("%d", &nuevalista.edad);
            while(nuevalista.edad > 150)
            {
                printf("Reingrese edad: ");
                scanf("%d", &nuevalista.edad);
            }
            printf("Ingrese sueldo: ");
            scanf("%f", &nuevalista.sueldo);
            printf("\na-Junior\nb-Semisenior\nc-Senior\nIngrese categoria: ");
            fflush(stdin);
            scanf("%c", &nuevalista.categoria);
            while(nuevalista.categoria != 'a' && nuevalista.categoria != 'b' && nuevalista.categoria != 'c')
            {
                printf("Categoria incorrecta.\n\na-Junior\nb-Semisenior\nc-Senior\nReingrese categoria: ");
                fflush(stdin);
                scanf("%c", &nuevalista.categoria);
            }
            printf("Ingrese fecha de ingreso: ");
            printf("\nDia: ");
            scanf("%d", &nuevalista.fechaIng.dia);
            while(nuevalista.fechaIng.dia > 30)
            {
                printf("\nReingrese dia: ");
                scanf("%d", &nuevalista.fechaIng.dia);
            }
            printf("Mes: ");
            scanf("%d", &nuevalista.fechaIng.mes);
            while(nuevalista.fechaIng.mes > 12)
            {
                printf("\nReingrese mes: ");
                scanf("%d", &nuevalista.fechaIng.mes);
            }
            printf("Anio: ");
            scanf("%d", &nuevalista.fechaIng.anio);

            while(nuevalista.fechaIng.anio > 2018)
            {
                printf("\nReingrese anio: ");
                scanf("%d", &nuevalista.fechaIng.anio);
            }

            nuevalista.isEmpty = 0;

            system("cls");
            printf("Empleado agregado!\n");
            system("pause");
        }
    }
    lista[libre] = nuevalista;
}

void baja(eEmpleado lista[], int tam)
{
    int legajo;
    char respuesta = 'n';
    int esta;

    mostrarTodos(lista, tam);

    printf("\nIngrese legajo a buscar: ");
    scanf("%d", &legajo);
    esta = buscarLegajo(lista, tam, legajo);
    if(esta != -1)
    {
        system("cls");
        mostrar(lista[esta]);
        printf("\nConfirmar baja? s/n");
        fflush(stdin);
        respuesta = getch();
        if(respuesta == 's')
        {
            lista[esta].isEmpty = 1;
            printf("\nBaja con exito.\n");
            system("pause");
        }
        else
        {
            printf("\nOpcion cancelada.\n");
            system("pause");
        }
    }
    else
    {
        system("cls");
        printf("no existe el legajo.\n");
        system("pause");
    }
}

void modificacion(eEmpleado lista[], int tam)
{
    int legajo;
    char respuesta = 'n';
    int esta;

    mostrarTodos(lista, tam);

    printf("\nIngrese legajo a buscar: ");
    scanf("%d", &legajo);
    esta = buscarLegajo(lista, tam, legajo);
    if(esta != -1)
    {
        system("cls");
        mostrar(lista[esta]);
        printf("\nDesea modificar el sueldo de este empleado? s/n");
        fflush(stdin);
        respuesta = getch();
        if(respuesta == 's')
        {
            printf("\nIngrese sueldo: ");
            scanf("%f", &lista[esta].sueldo);
            printf("\nModificacion exitosa.\n");
            system("pause");
        }
        else
        {
            printf("\nOpcion cancelada.\n");
            system("pause");
        }
    }
    else
    {
        system("cls");
        printf("no existe el legajo.\n");
        system("pause");
    }
}

void ordenamiento(eEmpleado emp[], int tam)
{
    eEmpleado aux;

    for(int i=0; i<tam-1; i++)
    {
        for(int j=i; j<tam; j++)
        {
            if(strcmp(emp[i].nombre, emp[j].nombre) > 0)
            {
                aux = emp[i];
                emp[i] = emp[j];
                emp[j] = aux;
            }
        }
    }
    system("cls");
    printf("Lista ordenada!\n");
    system("pause");
}
