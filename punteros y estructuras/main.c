#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nombre[21];
    int nota;
}eAlumno;

void mostrarCadena(char *punteroCadena);

int main()
{
    //char cadena[] = "a b c d e f g h i j k l m n o p q r s t u v w x y z";
    eAlumno alumno;
    eAlumno* pAlumno = &alumno;
    eAlumno alumn [3];
    eAlumno* pAlumn = alumn;
    int i;

    //manera 1
    /*printf("Ingrese nombre del alumno: ");
    scanf("%[^\n]", pAlumno->nombre);
    printf("Ingrese nota del alumno: ");
    scanf("%d", &pAlumno->nota);

    printf("\n\nNombre: %s\tNota: %d\n", pAlumno->nombre, pAlumno->nota);*/

    //manera 2
    /*printf("Ingrese nombre del alumno: ");
    scanf("%[^\n]", (*pAlumno).nombre);
    printf("Ingrese nota del alumno: ");
    scanf("%d", &(*pAlumno).nota);

    printf("\n\nNombre: %s\tNota: %d\n", (*pAlumno).nombre, (*pAlumno).nota);*/

    //manera 3 (vectores)
    /*for(i=0; i<3; i++)
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        scanf("%[^\n]", alumn[i].nombre);
        printf("Ingrese nota: ");
        scanf("%d", &alumn[i].nota);
    }

    for(i=0; i<3; i++)
    {
        printf("\nNombre: %s. Edad: %d\n", alumn[i].nombre, alumn[i].nota);
    }*/

    //manera 4 (con notacion de punteros)
    /*for(i=0; i<3; i++)
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        scanf("%[^\n]", (*(pAlumn+i)).nombre);
        printf("Ingrese nota: ");
        scanf("%d", &(*(pAlumn+i)).nota);
    }

    for(i=0; i<3; i++)
    {
        printf("\nNombre: %s.\t Nota: %d\n", (*(pAlumn+i)).nombre, (*(pAlumn+i)).nota);
    }*/

    //manera 5 operador flecha
    /*for(i=0; i<3; i++)
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        scanf("%[^\n]", (pAlumn+i)->nombre);
        printf("Ingrese nota: ");
        scanf("%d", &(pAlumn+i)->nota);
    }

    for(i=0; i<3; i++)
    {
        printf("\nNombre: %s.\t Nota: %d\n", (pAlumn+i)->nombre, (pAlumn+i)->nota);
    }*/

    //mostrarCadena(cadena);

    return 0;
}

void mostrarCadena(char *punteroCadena)
{
    while(*punteroCadena != '\0')
    {
        printf("%c", *punteroCadena);
        punteroCadena++;
    }
}
