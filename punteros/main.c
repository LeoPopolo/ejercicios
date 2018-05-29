#include <stdio.h>
#include <stdlib.h>

void funcion1(int vec[], int tam);
void funcion2(int vec[], int tam);
void funcion3(int* vec, int tam);
void funcion4(int* vec, int tam);

int main()
{
    int vec[5], i;

    for(i=0; i<5; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", (vec + i));
    }

    funcion1(vec, 5);
    funcion2(vec, 5);
    funcion3(vec, 5);
    funcion4(vec, 5);

    system("pause");

    return 0;
}

void funcion1(int vec[], int tam)
{
    int i;

    printf("\nNumeros ingresados funcion 1: \n");

    for(i=0; i<5; i++)
    {
        printf("%d\n", vec[i]);
    }
}

void funcion2(int vec[], int tam)
{
    int i;

    printf("\nNumeros ingresados funcion 2: \n");

    for(i=0; i<5; i++)
    {
        printf("%d\n", *(vec+i));
    }
}

void funcion3(int* vec, int tam)
{
    int i;

    printf("\nNumeros ingresados funcion 3: \n");

    for(i=0; i<5; i++)
    {
        printf("%d\n", vec[i]);
    }
}

void funcion4(int* vec, int tam)
{
    int i;

    printf("\nNumeros ingresados funcion 4: \n");

    for(i=0; i<5; i++)
    {
        printf("%d\n", *(vec+i));
    }
}
