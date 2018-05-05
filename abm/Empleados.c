#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>
#include "Empleados.h"

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
    printf("--Empleados--\n\n");
    gotoxy(30, 3);
    printf("1. Alta empleado");
    gotoxy(30, 4);
    printf("2. Baja empleado");
    gotoxy(30, 5);
    printf("3. Modificar empleado");
    gotoxy(30, 6);
    printf("4. Listar...");
    gotoxy(30, 7);
    printf("5. Ordenar ascendentemente");
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

void mostrarSectores(eEmpleado listae[], int tamE, eSector listas[], int tamS)
{

    char aux[13];

    system("cls");

    for(int i=0; i<tamS; i++)
    {
        printf("%s: \n", listas[i].descripcion);
        for(int j=0; j<tamE; j++)
        {
            if(listae[j].idSector == listas[i].id && listae[j].isEmpty == 0)
            {
                if(listae[j].categoria == 'a')
                {
                    strcpy(aux, "Junior");
                }
                if(listae[j].categoria == 'b')
                {
                    strcpy(aux, "Semisenior");
                }
                if(listae[j].categoria == 'c')
                {
                    strcpy(aux, "Senior");
                }
                printf("\tNombre: %s\tCategoria: %s\tSueldo: %.2f\n\n", listae[j].nombre, aux, listae[j].sueldo);
            }
        }
    }
    printf("\n\n");
    system("pause");
}

void inicializarSectores(eSector sec[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        sec[i].id = 0;
    }
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

/*int buscarDNI(eEmpleado lista[], int tam, char DNI[])
{
    int flag = -1;

    for(int i=0; i<tam; i++)
    {
        if(lista[i].DNI == DNI && lista[i].isEmpty == 0)
        {
            flag = i;
            break;
        }
    }

    return flag;
}*/

void mostrar(eEmpleado lista, eSector sectores, int i)
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

    gotoxy(0, i);
    printf("%d", lista.legajo);
    gotoxy(7, i);
    printf("%s", lista.nombre);
    gotoxy(29, i);
    printf("%d", lista.edad);
    gotoxy(34, i);
    printf("%.2f", lista.sueldo);
    gotoxy(44, i);
    printf("%s", aux);
    gotoxy(57, i);
    printf("%d/%d/%d", lista.fechaIng.dia, lista.fechaIng.mes, lista.fechaIng.anio);
    gotoxy(77, i);
    printf("%s", sectores.descripcion);
}

int mostrarTodos(eEmpleado lista[], int tame, eSector sectores[], int tams)
{
    int flag = -1, cont = 3;

    eEmpleado aux;

    for(int i=0; i<tame-1; i++)
    {
        for(int j=i; j<tame; j++)
        {
            if(lista[i].legajo > lista[j].legajo)
            {
                aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
        }
    }

    system("cls");
    gotoxy(0, 1);
    printf("Legajo");
    gotoxy(7, 1);
    printf("Nombre y Apellido");
    gotoxy(29, 1);
    printf("Edad");
    gotoxy(34, 1);
    printf("Sueldo");
    gotoxy(44, 1);
    printf("Categoria");
    gotoxy(57, 1);
    printf("Fecha de ingreso");
    gotoxy(77, 1);
    printf("Sector");

    for(int i=0; i<tame; i++)
    {
        for(int j=0; j<tams; j++)
        {
            if(lista[i].idSector == sectores[j].id && lista[i].isEmpty == 0)
            {
                cont++;
                mostrar(lista[i], sectores[j], cont);
                flag = 1;
            }
        }
    }
    printf("\n\n\n\n\n");
    if(flag != 1)
    {
        system("cls");
        printf("No hay empleados para mostrar.\n");
    }
    system("pause");

    return flag;

}

void alta(eEmpleado lista[], int tam, int legajo)
{
    eEmpleado nuevalista;
    int esta, libre;

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
        /*printf("Ingrese legajo: ");
        scanf("%d", &legajo*/
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
            do
            {
                printf("\n1.RRHH\n2.Administracion\n3.Sistemas\n4.Deposito\n5.Compras\n\nIngresa sector: ");
                scanf("%d", &nuevalista.idSector);
            }
            while(nuevalista.idSector > 5);

            nuevalista.isEmpty = 0;

            system("cls");
            printf("Empleado agregado!\n");
            system("pause");
        }
    }
    lista[libre] = nuevalista;
}

void baja(eEmpleado lista[], int tam, eSector sectores[])
{
    int legajo;
    char respuesta = 'n';
    int esta, flagEsta = 0;

    if((flagEsta = mostrarTodos(lista, tam, sectores, 5)) == 1)
    {
        printf("\nIngrese legajo a buscar: ");
        scanf("%d", &legajo);
        esta = buscarLegajo(lista, tam, legajo);
        if(esta != -1)
        {
            system("cls");
            mostrar(lista[esta], sectores[esta], 1);
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


}

void modificacion(eEmpleado lista[], int tam, eSector sectores[])
{
    int legajo;
    char respuesta = 'n';
    int esta, opcion, flagEsta;

    if((flagEsta = mostrarTodos(lista, tam, sectores, 5)) == 1)
    {
        printf("\nIngrese legajo a buscar: ");
        scanf("%d", &legajo);
        esta = buscarLegajo(lista, tam, legajo);
        if(esta != -1)
        {
            system("cls");
            mostrar(lista[esta], sectores[esta], 1);
            printf("\nDesea modificar el sueldo de este empleado? s/n");
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
            if(strcmp(emp[i].nombre, emp[j].nombre) == 0)
            {
                if(emp[i].edad > emp[j].edad)
                {
                    aux = emp[i];
                    emp[i] = emp[j];
                    emp[j] = aux;
                }
            }
        }
    }
    system("cls");
    printf("Lista ordenada!\n");
    system("pause");
}

int menuOpcion()
{
    int opcion;

    system("cls");
    printf("1-Listar todos los empleados\n2-Listar sectores con empleados\n3-Salir\nIngrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
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

int cantidadEmpleados(int sector, eEmpleado emp[],int tam)
{
    int cantidad=0;
    for(int i=0;i<tam;i++)
    {
        if(emp[i].idSector==sector)
        {
            cantidad++;
        }
    }
    return cantidad;
}

void mostrarSectoresConCantidadDeEmpleados(eEmpleado emp[],int tamE,eSector sec[],int tamS)
{
    int cantidad;
    printf("\n---Cantidad de empleados por sector---\n\n");
    for (int i=0;i<tamS;i++)
    {
        printf("\t%s: ",sec[i].descripcion);
        cantidad=cantidadEmpleados(sec[i].id,emp,tamE);
        printf("%d\n\n",cantidad);
    }
    system("pause");
}
