#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 3

typedef struct
{
    int DNI;
    char nombre[20];
    float peso;
} ePersona;

void mostrarPersonas(ePersona unaPersona[]);
void pedirDatos(ePersona unaPersona[]);
void mostrarPersona(ePersona unaPersona);
void listarPersonas(ePersona unaPersona[]);

int main()
{
    ePersona unaPersona[TAM];

    pedirDatos(unaPersona);
    listarPersonas(unaPersona);
    mostrarPersonas(unaPersona);

    return 0;
}
void pedirDatos(ePersona unaPersona[])
{
    int i;
    char aux;

    for(i=0; i<TAM; i++)
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(unaPersona[i].nombre);

        aux = unaPersona[i].nombre[0];
        aux = toupper(aux);
        unaPersona[i].nombre[0] = aux;

        printf("Ingrese DNI: ");
        scanf("%d", &unaPersona[i].DNI);
        printf("Ingrese peso: ");
        scanf("%f", &unaPersona[i].peso);
        system("cls");
    }
}

void mostrarPersonas(ePersona unaPersona[])
{
    printf("Nombre\t\tDNI\t\tPeso");
    printf("\n------------------------------------------------------------\n");
    int i;

    for(i=0; i<TAM; i++)
    {
        mostrarPersona(unaPersona[i]);
    }
}
void mostrarPersona(ePersona unaPersona)
{
    printf("%s\t\t%d\t\t%.2f\t\t\n", unaPersona.nombre,unaPersona.DNI, unaPersona.peso);
}

void listarPersonas(ePersona unaPersona[])
{
    int i;
    int j;
    ePersona aux;

    for(i=0; i<TAM-1; i++)
    {
        for(j=i+1; j<TAM; j++)
        {
            if(strcmp(unaPersona[i].nombre, unaPersona[j]. nombre)>0)
            {
                aux = unaPersona[i];
                unaPersona[i] = unaPersona[j];
                unaPersona[j] = aux;
            }
            if(strcmp(unaPersona[i].nombre, unaPersona[j].nombre)==0)
            {
                if(unaPersona[i].DNI > unaPersona[j].DNI)
                {
                    aux = unaPersona[i];
                    unaPersona[i] = unaPersona[j];
                    unaPersona[j] = aux;
                }
            }
        }
    }
}
