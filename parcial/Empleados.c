#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>
#include "Empleados.h"

void hardcodeo(estructuraDos lista[])
{
    estructuraDos nuevosector;

    nuevosector.id = 1;
    nuevosector.isEmpty = 0;
    strcpy(nuevosector.descripcion, "RRHH");
    lista[0] = nuevosector;

    nuevosector.id = 2;
    nuevosector.isEmpty = 0;
    strcpy(nuevosector.descripcion, "Administracion");
    lista[1] = nuevosector;

    nuevosector.id = 3;
    nuevosector.isEmpty = 0;
    strcpy(nuevosector.descripcion, "Sistemas");
    lista[2] = nuevosector;

    nuevosector.id = 4;
    nuevosector.isEmpty = 0;
    strcpy(nuevosector.descripcion, "Deposito");
    lista[3] = nuevosector;

    nuevosector.id = 5;
    nuevosector.isEmpty = 0;
    strcpy(nuevosector.descripcion, "Compras");
    lista[4] = nuevosector;
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
    printf("1. ");
    gotoxy(30, 4);
    printf("2. ");
    gotoxy(30, 5);
    printf("3. ");
    gotoxy(30, 6);
    printf("4. ");
    gotoxy(30, 7);
    printf("5. ");
    gotoxy(30, 8);
    printf("6. Salir");
    gotoxy(30, 9);
    printf("Ingrese opcion: ");
    scanf("%s", opcion);

    while (validarLetra(opcion)== 1)
    {
        printf("Usted no puede ingresar un caracter!\nIngrese un numero ente 1 y :");
        scanf("%s",opcion);
    }

    datoInt = atoi(opcion);

    return datoInt;
}

void mostrarEst1(estructuraUno lista1[], int tam1, estructuraDos lista2[], int tam2)
{

    char aux[13];

    system("cls");

    for(int i=0; i<tam2; i++)
    {
        printf("%s: \n", lista2[i].descripcion);
        for(int j=0; j<tam1; j++)
        {
            if(lista1[j].idSector == lista2[i].id && lista1[j].isEmpty == 0)
            {
                /*if(lista1[j].categoria == 'a')
                {
                    strcpy(aux, "Junior");
                }
                if(lista1[j].categoria == 'b')
                {
                    strcpy(aux, "Semisenior");
                }
                if(lista1[j].categoria == 'c')
                {
                    strcpy(aux, "Senior");
                }*/
                //printf("\tNombre: %s\tCategoria: %s\tSueldo: %.2f\n\n", lista1[j].nombre, aux, lista1[j].sueldo);
            }
        }
    }
    printf("\n\n");
    system("pause");
}

void inicializarEst2(estructuraDos sec[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        sec[i].id = 0;
    }
}

void inicializarVariables(estructuraUno vec[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].Id = 0;
        vec[i].isEmpty = 1;
    }
}

int buscarLibre(estructuraUno lista[], int tam)
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

int buscarId(estructuraUno lista[], int tam, int Id)
{
    int flag = -1;

    for(int i=0; i<tam; i++)
    {
        if(lista[i].Id == Id && lista[i].isEmpty == 0)
        {
            flag = i;
            break;
        }
    }

    return flag;
}

/*int buscarDNI(estructuraUno lista[], int tam, char DNI[])
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

void mostrar(estructuraUno lista, estructuraDos sectores, int i)
{
    char aux[13];

    /*if(lista.categoria == 'a')
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
    }*/

    gotoxy(0, i);
    printf("%d", lista.Id);
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

int mostrarTodos(estructuraUno lista[], int tam1, estructuraDos sectores[], int tam2, int flagOrd)
{
    int flag = -1, cont = 3, flagNEO = 1;

    estructuraUno aux;

    if(flagOrd == 0)
    {
        while(flagNEO == 1)
        {
            flagNEO = 0;
            for(int j=1; j<tam1; j++)
            {
                if(lista[j].Id < lista[j - 1].Id)
                {
                    aux = lista[j];
                    lista[j] = lista[j - 1];
                    lista[j - 1] = aux;
                    flagNEO = 1;
                }
            }
        }
    }



    system("cls");
    gotoxy(0, 1);
    printf("Id");
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

    for(int i=0; i<tam1; i++)
    {
        for(int j=0; j<tam2; j++)
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

void alta(estructuraUno lista[], int tam, int Id)
{
    estructuraUno nuevalista;
    int libre;

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
        /*printf("Ingrese Id: ");
        scanf("%d", &Id);*/

        nuevalista.Id = Id;
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

        nuevalista.edad = ingresoEdadVal();
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
    lista[libre] = nuevalista;
}

void baja(estructuraUno lista[], int tam, estructuraDos sectores[])
{
    int Id;
    char respuesta = 'n';
    int esta, flagEsta = 0;

    if((flagEsta = mostrarTodos(lista, tam, sectores, 5, 0)) == 1)
    {
        printf("\nIngrese Id a buscar: ");
        scanf("%d", &Id);
        esta = buscarId(lista, tam, Id);
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
            printf("no existe el Id.\n");
            system("pause");
        }
    }


}

void modificacion(estructuraUno lista[], int tam, estructuraDos sectores[])
{
    int Id;
    char respuesta = 'n';
    int esta, opcion, flagEsta;

    if((flagEsta = mostrarTodos(lista, tam, sectores, 5, 0)) == 1)
    {
        printf("\nIngrese Id a buscar: ");
        scanf("%d", &Id);
        esta = buscarId(lista, tam, Id);
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
            printf("no existe el Id.\n");
            system("pause");
        }
    }

}

void ordenamiento(estructuraUno emp[], int tam)
{
    int flagNEO = 1;
    estructuraUno aux;

    while(flagNEO == 1)
    {
        flagNEO = 0;
        for(int j=1; j<tam; j++)
        {
            if(strcmp(emp[j].nombre, emp[j-1].nombre) < 0)
            {
                aux = emp[j];
                emp[j] = emp[j - 1];
                emp[j - 1] = aux;
                flagNEO = 1;
            }
            if(strcmp(emp[j].nombre, emp[j-1].nombre) == 0)
            {
                if(emp[j].edad < emp[j-1].edad)
                {
                    aux = emp[j];
                    emp[j] = emp[j - 1];
                    emp[j - 1] = aux;
                    flagNEO = 1;
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
    printf("1-Listar todos los empleados\n2-Listar sectores con empleados\n3-Mostrar cantidad de empleados por sector\n4-Sector con mas empleados\n5-Salir\nIngrese opcion: ");
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

int cantidadEmpleados(int sector, estructuraUno emp[],int tam)
{
    int cantidad=0;
    for(int i=0; i<tam; i++)
    {
        if(emp[i].idSector==sector && emp[i].isEmpty == 0)
        {
            cantidad++;
        }
    }
    return cantidad;
}

void mostrarEst1ConCantidadDestructuraUnos(estructuraUno emp[],int tam1,estructuraDos sec[],int tam2)
{
    int cantidad;
    printf("\n---Cantidad de empleados por sector---\n\n");
    for (int i=0; i<tam2; i++)
    {
        printf("\t%s: ",sec[i].descripcion);
        cantidad=cantidadEmpleados(sec[i].id,emp,tam1);
        printf("%d\n\n",cantidad);
    }
    system("pause");
}

int maximoEmpleados(estructuraUno emp[],int tam1,estructuraDos sec[],int tam2)
{
    int maximo;
    int flag=0;
    int cantidad;
    for(int i=0; i<tam2; i++)
    {
        cantidad=cantidadEmpleados(sec[i].id,emp,tam1);
        if(cantidad>maximo || flag==0)
        {
            maximo=cantidad;
            flag=1;
        }
    }
    return maximo;
}

void sectorConMasEmpleados(estructuraUno emp[],int tam1,estructuraDos sec[],int tam2)
{
    int cantidad;
    cantidad=maximoEmpleados(emp,tam1,sec,tam2);
    printf("\n\n---Sector con mas empleados---\n\n");
    for(int i=0; i<tam2; i++)
    {
        if(cantidad==cantidadEmpleados(sec[i].id,emp,tam1))
        {
            printf("%s(%d)\n",sec[i].descripcion, cantidad);
        }
    }
    printf("\n");
    system("pause");
}

/*void login()
{
    char usuario[30];
    char contrasenia[20];

    do
    {
        system("cls");
        gotoxy(30, 2);
        printf("Iniciarse");
        gotoxy(30, 4);
        printf("Usuario: ");
        fflush(stdin);
        gets(usuario);
    }
    while(strcmp(usuario, "leopopolo")!=0 || strlen(usuario) > 30);

    do
    {
        system("cls");
        gotoxy(30, 2);
        printf("Iniciarse");
        gotoxy(30, 4);
        printf("Usuario: %s", usuario);
        gotoxy(30, 5);
        printf("Contrasenia: ");
        fflush(stdin);
        gets(contrasenia);
    }
    while(strcmp(contrasenia, "1234")!=0 || strlen(contrasenia) > 20);

}*/

int ingresoEdadVal()
{
    char opcion[30];
    int datoInt;

    printf("Ingrese edad: ");
    scanf("%s", opcion);

    while (validarLetra(opcion)== 1)
    {
        printf("Usted no puede ingresar un caracter!\nIngrese una edad valida: ");
        scanf("%s",opcion);
    }

    datoInt = atoi(opcion);

    return datoInt;
}
//funciones para muchos a muchos
/*void alumnosConMaterias(eMateria materia[], eAlumno alumno[], AlumyMate enlace[])
{
    printf("Alumno\tDNI\tMateria\n\n");
    for(int i=0; i<TAMA; i++)
    {
        printf("\n%s\t%s\n\t",alumno[i].nombre,alumno[i].dni);
        for(int j=0; j<(TAMM+TAMA); j++)
        {
            if(alumno[i].idA == enlace[j].idAl)
            {

                for(int k=0; k<TAMM; k++)
                {
                    if(enlace[j].idMa == materia[k].idM)
                    {
                        printf("\t%s\n\t",materia[k].descripcion);
                    }
                }
            }
        }
    }
}

void materiasConAlumnos(eMateria materia[], eAlumno alumno[], AlumyMate enlace[])
{
    for(int i=0; i<TAMM; i++)
    {
        printf("\n%s\n",materia[i].descripcion);
        for(int j=0; j<(TAMM+TAMA); j++)
        {
            if(materia[i].idM == enlace[j].idMa)
            {


                for(int k=0; k<TAMA; k++)
                {
                    if(enlace[j].idAl == alumno[k].idA)
                    {
                        printf("\n\t%s\t%s",alumno[k].nombre,alumno[k].dni);
                    }
                }
            }
        }
    }
}

void mostrarMateriasConCantidadDeInscriptos(AlumyMate I[],int tamI,eMateria M[],int tamM)
{
    int cantidad;
    printf("\n---CANTIDAD DE ALUMNOS INSCRIPTOS POR MATERIA---\n\n");
    for (int i=0;i<tamM;i++)
    {
        printf("\t%s: ",M[i].descripcion);
        cantidad=cantidadInscriptos(M[i].idM,I,tamI);
        printf("%d\n\n",cantidad);
    }
}
int cantidadInscriptos(int materia, AlumyMate I[],int tam)
{
    int cantidad=0;
    for(int i=0;i<tam;i++)
    {
        if(I[i].idMa==materia)
        {
            cantidad++;
        }
    }
    return cantidad;
}
int maximoInscriptos(AlumyMate I[],int tamI,eMateria M[],int tamM)
{
    int maximo;
    int flag=0;
    int cantidad;
    for(int i=0;i<tamM;i++)
    {
    cantidad=cantidadInscriptos(M[i].idM,I,tamI);
    if(cantidad>maximo || flag==0)
    {
        maximo=cantidad;
        flag=1;
    }
    }
    return maximo;
}
void materiaMasCursada(AlumyMate I[],int tamI,eMateria M[],int tamM)
{
    int cantidad;
    cantidad=maximoInscriptos(I,tamI,M,tamM);
    printf("\n\n---MATERIAS MAS CURSADAS---\n\n");
    for(int i=0;i<tamM;i++)
    {
        if(cantidad==cantidadInscriptos(M[i].idM,I,tamI))
        {
            printf("%s\n",M[i].descripcion);
        }
    }
}*/
