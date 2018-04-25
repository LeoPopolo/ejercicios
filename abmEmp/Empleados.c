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

void menuListas(eEmpleado listaem[], eSector listase[], int tame, int tams)
{
    for(int i=0; i<50; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(listaem[i].idSector == listase[j].id && listaem[i].isEmpty == 0)
            {
                printf("%d\t%s\t%d\t%.2f\t%d/%d/%d\t%s\n", listaem[i].legajo, listaem[i].nombre, listaem[i].edad, listaem[i].sueldo, listaem[i].fechaIng.dia, listaem[i].fechaIng.mes, listaem[i].fechaIng.anio, listase[j].descripcion);
            }
        }
    }
}

void hardcodeo(eSector sectores[])
{
    eSector nuevosector;

    nuevosector.id = 1;
    nuevosector.isEmpty = 0;
    strcpy(nuevosector.descripcion, "RRHH");
    sectores[0] = nuevosector;

    nuevosector.id = 2;
    nuevosector.isEmpty = 0;
    strcpy(nuevosector.descripcion, "Administracion");
    sectores[1] = nuevosector;

    nuevosector.id = 3;
    nuevosector.isEmpty = 0;
    strcpy(nuevosector.descripcion, "Sistemas");
    sectores[2] = nuevosector;

    nuevosector.id = 4;
    nuevosector.isEmpty = 0;
    strcpy(nuevosector.descripcion, "Deposito");
    sectores[3] = nuevosector;

    nuevosector.id = 5;
    nuevosector.isEmpty = 0;
    strcpy(nuevosector.descripcion, "Compras");
    sectores[4] = nuevosector;
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

    system("cls");
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

void alta(eEmpleado lista[], int tam, eSector listas[])
{
    eEmpleado nuevalista;
    eSector nuevosector;
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
            printf("Ingresa sector: \n1.RRHH\n2.Sistemas\n3.Administracion\n4.Deposito\n5.Compras");
            scanf("%d", &nuevosector.id);

            nuevosector.isEmpty = 0;

            system("cls");
            printf("Empleado agregado!\n");
            system("pause");
        }
    }
    lista[libre] = nuevalista;
    listas[libre] = nuevosector;
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
    int opcion;

    mostrarTodos(lista, tam);

    printf("\nIngrese legajo a buscar: ");
    scanf("%d", &legajo);
    esta = buscarLegajo(lista, tam, legajo);
    if(esta != -1)
    {
        system("cls");
        mostrar(lista[esta]);
        printf("\nDesea modificar este empleado? s/n");
        fflush(stdin);
        respuesta = getch();
        if(respuesta == 's')
        {
            system("cls");
            printf("1-sueldo\n2-nombre\n3-edad\ningrese opcion: ");
            scanf("%d", &opcion);
            switch(opcion)
            {
            case 1:
                printf("\nIngrese sueldo: ");
                scanf("%f", &lista[esta].sueldo);
                printf("\nModificacion exitosa.\n");
                system("pause");
                break;
            case 2:
                printf("\nIngrese nombre: ");
                fflush(stdin);
                scanf("%[^\n]", lista[esta].nombre);
                printf("\nModificacion exitosa.\n");
                system("pause");
                break;
            case 3:
                printf("\nIngrese edad: ");
                scanf("%d", &lista[esta].edad);
                printf("\nModificacion exitosa.\n");
                system("pause");
                break;
            }

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

void ordenar(eEmpleado lista[], int tam)
{
    eEmpleado aux;

    for(int i=0;i<tam-1;i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(strcmp(lista[i].nombre, lista[j].nombre)>0)
            {
                aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
        }
    }
    printf("\nLista ordenada!\n");
    system("pause");
}
