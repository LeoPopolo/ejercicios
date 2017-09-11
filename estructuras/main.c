#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validarCadena(char cadena[], int tam);

int main()
{
    char nombre[30];
    char aux[100];

    printf("ingrese nombre: ");
    gets(aux);

    while( validarCadena(aux, 20) )
    {
        printf("error. nombre demasiado largo, reingrese: ");
        gets(aux);
    }

    strcpy(nombre, aux);

    printf("el nombre es: %s", nombre);

    return 0;
}
int validarCadena(char cadena[], int tam)
{
    int esValido = 0;

    if(strlen(cadena)>20)
    {
        esValido = 1;
    }

    return esValido;
}
