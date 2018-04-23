#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "Empleados.h"

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
    printf("%d\t%s\t%d\t%.2f\t%d/%d/%d\n", lista.legajo, lista.nombre, lista.edad, lista.sueldo, lista.fechaIng.dia, lista.fechaIng.mes, lista.fechaIng.anio);
}

void mostrarTodos(eEmpleado lista[], int tam)
{
    int flag = -1;

    printf("Legajo\tNombre\tEdad\tSueldo\t\tFecha de ingreso\n\n");

    for(int i=0; i<tam; i++)
    {
        if(lista[i].isEmpty == 0)
        {
            mostrar(lista[i]);
            flag = 1;
        }
    }
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
            printf("Ingrese nombre: ");
            fflush(stdin);
            scanf("%[^\n]", nuevalista.nombre);
            printf("Ingrese edad: ");
            scanf("%d", &nuevalista.edad);
            printf("Ingrese sueldo: ");
            scanf("%f", &nuevalista.sueldo);
            printf("Ingrese fecha de ingreso: ");
            printf("\nDia: ");
            scanf("%d", &nuevalista.fechaIng.dia);
            printf("Mes: ");
            scanf("%d", &nuevalista.fechaIng.mes);
            printf("Anio: ");
            scanf("%d", &nuevalista.fechaIng.anio);

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
