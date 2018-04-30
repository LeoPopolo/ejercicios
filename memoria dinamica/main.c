#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *num;
    int *auxnum;
    int opcion, cantidad = 0, nuevacantidad;

    num = (int*) malloc(sizeof(int));
    if(num == NULL)
    {
        printf("No hay memoria");
        exit(1);
    }
    while(1)
    {
        printf("ingrese un numero: ");
        scanf("%d", num+cantidad);
        cantidad++;
        printf("si desea ingresar otro numero ingrese 1: ");
        scanf("%d", &opcion);
        if(opcion == 1)
        {
            nuevacantidad = sizeof(int) * cantidad+2;
            auxnum = realloc(num, nuevacantidad+1);
            if (auxnum == NULL)
            {
                printf("\nNo hay lugar en memoria\n");
                break;
            }
            num = auxnum;
        }
        else
        {
            break;
        }
    }
    for(int i = 0; i < cantidad; i++)
    {
        printf("%d\n", *(num+i));
    }
    free(num);

    return 0;
}


/*
#include <stdio.h>
#include <stdlib.h>
struct persona
{
    char nombre[50];
    int edad;
};
int main()
{
    int seguirCargando;
    int i;
    int auxNuevaLogitud;
    int logitudPersonas = 1;
    struct persona* pArrayPersona;
    struct persona* pAuxPersona;
// Creamos el array de personas
    pArrayPersona = malloc(sizeof(struct persona));
    if (pArrayPersona == NULL)
    {
        printf("\nNo hay lugar en memoria\n");
        exit(0);
    }
    while(1)
    {
        printf("\nIngrese nombre: ");
        scanf("%s",(pArrayPersona+logitudPersonas-1)->nombre);
        printf("\nIngrese edad: ");
        scanf("%d",&((pArrayPersona+logitudPersonas-1)->edad));
        printf("\nSi desea cargar otra persona ingrese (1): ");
        scanf("%d",&seguirCargando);
        if(seguirCargando == 1)
        {
// Calculamos el nuevo tamaño del array
            auxNuevaLogitud = sizeof(struct persona) * logitudPersonas+1;
// Redimencionamos la lista
            pAuxPersona = realloc( pArrayPersona, auxNuevaLogitud);
            if (pAuxPersona == NULL)
            {
                printf("\nNo hay lugar en memoria\n");
                break;
            }
            logitudPersonas++; //Incremento el contador de personas
            pArrayPersona = pAuxPersona;
        }
        else
        {
            break;
        }
    }

    for(i = 0; i < logitudPersonas; i++)
    {
        printf("\nNombre: %s - ",(pArrayPersona+i)->nombre);
        printf("Edad: %d",(pArrayPersona+i)->edad);
    }
    free(pArrayPersona); // Liberamos la memoria
    return 0;
}
*/
