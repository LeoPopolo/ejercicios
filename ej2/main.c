#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validarCadena(char cadena[], int tam);
void mostrarNombres(char cadena[][30], int tam);
void ordenarNombres(char cadena[][30], int tam);

int main()
{
    char nombre[5][30];
    char aux[100];
    int i;
    int tam= 5;

    for(i=0; i<5; i++)
    {
        printf("ingrese nombre: ");
        fflush(stdin);
        gets(aux);

        while( validarCadena(aux, 20) )
        {
            printf("error. nombre demasiado largo, reingrese: ");
            fflush(stdin);
            gets(aux);
        }

        strcpy(nombre[i], aux);
    }
    mostrarNombres(nombre, tam);
    ordenarNombres(nombre, tam);
    mostrarNombres(nombre, tam);

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

void mostrarNombres(char cadena[][30], int tam)
{
    int i;

    printf("\nnombres: \n\n");

    for(i=0; i<5; i++)
    {
        printf("%s\n", cadena[i]);
    }
}

void ordenarNombres(char cadena[][30], int tam)
{
    int i;
    int j;
    char aux[20];

    for(i=0; i<tam-1;i++)
    {
        for(j=i+1; j<tam;j++)
        {
            if(strcmp(cadena[i],cadena[j])>0)
            {
                strcpy(aux,cadena[j]);
                strcpy(cadena[j],cadena[i]);
                strcpy(cadena[i],aux);
            }
        }
    }

}




