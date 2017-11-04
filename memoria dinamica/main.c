#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *numero, num;

    printf("N£mero de elementos del vector: ");
    scanf("%d", &num);

    numero = (int*)malloc(num * sizeof(int));

    if(numero==NULL)
    {
        printf("no se pudo reservar espacio en memoria.");
    }
    else
    {
        printf("se pudo reservar memoria correctamente.");
    }

    return 0;
}
