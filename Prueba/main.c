#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"
#define TAM 5
#define TAMA 10
#define TAMAL 15
int main()
{
    int flag=1;
    int opcion;
    ePersona persona[TAM];
    eAlquiler alquiler[TAMA];
    eAlquila alquila[TAMAL];
    inicializarvector(persona,TAM);
    inicializarvectorAlquiler(alquiler,TAMA);
    do
    {
        system("cls");
        printf("Opciones:\n\n");
        printf("1.Alta del cliente.\n");
        printf("2.Modificar datos del cliente.\n");
        printf("3.Baja del cliente.\n");
        printf("4.Nuevo alquiler.\n");
        printf("5.Fin del alquiler.\n");
        printf("6.INFORMAR.\n");
        printf("7.Salir\n\n");
        printf("Ingrese opcion: ");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            system("cls");
            printf("ALTA CLIENTE\n\n");
            altaPersona(persona,TAM);
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            printf("MODIFICAR CLIENTE\n\n");
            modificarPersona(persona,TAM);
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            printf("BAJA CLIENTE\n\n");
            bajaPersona(persona,TAM);
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            printf("NUEVO ALQUILER\n\n");
            nuevoAlquiler(alquiler,TAMA,persona,TAM,alquila,TAMAL);
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
            printf("FINALIZAR ALQUILER\n\n");
            finalizarAlquiler(alquiler,TAMA,persona,TAM,alquila,TAMAL);
            system("pause");
            system("cls");
            break;
        case 6:
            system("cls");
            printf("LISTADO DE CLIENTES\n\n");
            mostrarPersonas(persona,TAM);
            clienteCMasAlq(alquila,TAMAL, alquiler,TAMA);
            getch();
            break;
        case 7:
            printf("Chau!!");
            flag=0;
            break;
        default:
            printf("Opcion Invalida!!\n");
            system("pause");
        }
    }while(flag==1);
}
