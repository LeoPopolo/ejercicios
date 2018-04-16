#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nombre[20];
    int legajo;
    float sueldo;
    char sexo;

} eEmpleado;

void mostrar(eEmpleado unEmpleado);
void mostrarTodos(eEmpleado emp[]);
void ordenar(eEmpleado emp[]);

int main()
{
    eEmpleado unEmpleado[3] = {{"Leo", 1234, 20000, 'm'},{"Juan", 1235, 15000, 'm'},{"Maria", 1236, 18000, 'f'}};

    printf("Nombre\tLegajo\tSueldo\t\tSexo\n\n");
    printf("-------------------------------------------\n");

    ordenar(unEmpleado);
    mostrarTodos(unEmpleado);

}

void mostrar(eEmpleado unEmpleado)
{

    /* printf("ingrese nombre: ");
     gets(unEmpleado.nombre);
     printf("ingrese legajo: ");
     scanf("%d", &unEmpleado.legajo);
     printf("ingrese sueldo: ");
     scanf("%f", &unEmpleado.sueldo);
     printf("ingrese sexo: ");
     fflush(stdin);
     scanf("%c", &unEmpleado.sexo);
     system("cls");*/


    printf("%s\t%d\t$%.2f\t%c\n", unEmpleado.nombre, unEmpleado.legajo, unEmpleado.sueldo, unEmpleado.sexo);
}

void mostrarTodos(eEmpleado emp[])
{
    for(int i=0; i<3; i++)
    {
        mostrar(emp[i]);
    }
}

void ordenar(eEmpleado emp[])
{
    eEmpleado aux;

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(strcmp(emp[j].nombre, emp[i].nombre)>0)
            {
                strcpy(aux.nombre, emp[i].nombre);
                strcpy(emp[i].nombre, emp[j].nombre);
                strcpy(emp[j].nombre, aux.nombre);

                aux.legajo = emp[i].legajo;
                emp[i].legajo = emp[j].legajo;
                emp[j].legajo = aux.legajo;

                aux.sexo = emp[i].sexo;
                emp[i].sexo = emp[j].sexo;
                emp[j].sexo = aux.sexo;

                aux.sueldo = emp[i].sueldo;
                emp[i].sueldo = emp[j].sueldo;
                emp[j].sueldo = aux.sueldo;
            }
        }
    }
}
