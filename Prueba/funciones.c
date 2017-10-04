#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>
#include <conio.h>
#include <ctype.h>
void inicializarvector(ePersona lista[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        lista[i].estado=0;
    }
}
void inicializarvectorAlquiler(eAlquiler lista[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        lista[i].estado=0;
    }
}
int buscarLibre(ePersona lista[],int tam)
{
    int indice=-1;
    for(int i=0; i<tam; i++)
    {
        if(lista[i].estado==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
int buscarLibreAlquiler(eAlquiler lista[],int tam)
{
    int indice=-1;
    for(int i=0; i<tam; i++)
    {
        if(lista[i].estado==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
int buscarDni(int dni, ePersona lista[],int tam)
{
    int indice=-1;
    for(int i=0; i<tam; i++)
    {
        if(lista[i].dni==dni&&lista[i].estado==1)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
int buscarId(int id, ePersona lista[],int tam)
{
    int indice=-1;
    for(int i=0; i<tam; i++)
    {
        if(lista[i].id==id&&lista[i].estado==1)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
int buscarEquipo(int equipo,eAlquila alquila[],int tam)
{
    int indice=-1;
    for(int i=0; i<tam; i++)
    {
        if(alquila[i].equipo==equipo&&alquila[i].estado==1)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
void altaPersona(ePersona lista[],int tam)
{
    int lugar;
    int dni;
    int esta;
    lugar=buscarLibre(lista,tam);
    if(lugar==-1)
    {
        printf("\nNo hay lugar en el sistema.\n");
    }
    else
    {
        printf("\nIngrese DNI: ");
        fflush(stdin);
        scanf("%d",&dni);
        esta=buscarDni(dni,lista,tam);
        if(esta!=-1)
        {
            printf("\nEl DNI: %d ya se encuentra registrado en el sistema. \n",dni);
        }
        else
        {
            lista[lugar].dni=dni;
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(lista[lugar].nombre);
            printf("Ingrese apellido: ");
            fflush(stdin);
            gets(lista[lugar].apellido);
            lista[lugar].estado=1;
            lista[lugar].id=lugar;
            printf("\nCliente Agregado con exito! Su ID es: %d\n\n",lista[lugar].id);
        }
    }
}
void mostrarPersona(ePersona lista)
{
    printf("\n%d\t%s\t%s\t\t%d\n",lista.dni,lista.nombre,lista.apellido,lista.id);
}
int mostrarPersonas(ePersona lista[],int tam)
{
    int i;
    int flag=0;
    printf("\nDNI\tNombre\tApellido\tId\t\n");
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==1)
        {
            mostrarPersona(lista[i]);
            flag=1;
        }
    }
    return flag;
}
void modificarPersona(ePersona lista[],int tam)
{
    int id;
    int indice;
    char confirma;
    int flag;
    flag=mostrarPersonas(lista,tam);
    if(flag==0)
    {
        printf("\nNo hay datos cargados en el sistema\n");
    }
    else
    {
        printf("\nIngrese ID del cliente a modificar: ");
        scanf("%d",&id);
        indice=buscarId(id,lista,tam);
        if(indice!=-1)
        {
            system("cls");
            printf("El cliente ingresado es: \n");
            mostrarPersona(lista[indice]);
            printf("\nEsta seguro que desea modificar este Cliente? s/n: ");
            fflush(stdin);
            scanf("%c",&confirma);
            if(confirma=='s')
            {
                printf("\nIngrese nuevo nombre: ");
                fflush(stdin);
                gets(lista[indice].nombre);
                printf("\nIngrese nuevo apellido: ");
                fflush(stdin);
                gets(lista[indice].apellido);
                printf("\n\nCliente modificado con exito!!!\n\n");
            }
            else
            {
                printf("\naccion cancelada.\n");
            }
        }
        else
        {
            printf("\nID no encontrada.\n");
        }
    }
}
void bajaPersona(ePersona lista[], int tam)
{
    int id;
    int indice;
    char confirma;
    int flag;
    flag=mostrarPersonas(lista,tam);
    if(flag==0)
    {
        printf("\nNo hay datos cargados en el sistema\n");
    }
    else
    {
        printf("\nIngrese ID: ");
        scanf("%d",&id);
        indice=buscarId(id,lista,tam);
        if(indice!=-1)
        {
            mostrarPersona(lista[indice]);
            printf("\nConfirma la baja? s/n: ");
            fflush(stdin);
            confirma=getchar();
            if(confirma=='s')
            {
                lista[indice].estado=0;
                printf("\nCliente Eliminado\n");
            }
            else
            {
                printf("\nBaja cancelada por el usuario\n");
            }
        }
        else
        {
            printf("\nID no encontrada.\n");
        }
    }
}
void nuevoAlquiler(eAlquiler alquiler[],int tamA,ePersona lista[],int tamP,eAlquila alquila[],int tamal)
{
    int lugar;
    int equipo;
    int esta;
    int id;
    lugar=buscarLibreAlquiler(alquiler,tamA);
    if(lugar==-1)
    {
        printf("\nNo hay lugar en el sistema.\n");
    }
    else
    {
        printf("\nIngrese ID del Cliente que alquila: ");
        scanf("%d",&id);
        esta=buscarId(id,lista,tamA);
        if(esta==-1)
        {
            printf("\nNo existe el cliente\n");
        }
        else
        {
            printf("\n1-AMOLADORA\n2-MEZCLADORA\n3-TALADRO\n\nIngrese numero de equipo: ");
            scanf("%d",&equipo);
            if(equipo==1 || equipo==2 || equipo==3)
            {
                alquiler[lugar].equipo=equipo;
                printf("\nIngrese tiempo de alquiler: ");
                scanf("%d",&alquiler[lugar].tiempo);
                printf("Ingrese el Operador: ");
                fflush(stdin);
                gets(alquiler[lugar].operador);
                lista[lugar].estado=1;
                alquiler[lugar].estado=1;
                alquila[lugar].equipo=alquiler[lugar].equipo;
                alquila[lugar].id=lista[lugar].id;
                alquila[lugar].estado=1;
                printf("\nAlquiler agregado con exito!\n\n");
            }
            else
            {
                printf("OPCION INVALIDA!!\n\n");
            }
        }
    }
}
void finalizarAlquiler(eAlquiler alquiler[], int tamA,ePersona lista[],int tamP,eAlquila alquila[],int tamal)
{
    int id;
    int indice;
    int equipo;
    int equipoindice;
    printf("\nIngrese el ID del Cliente que dejara de alquilar: ");
    scanf("%d",&id);
    indice=buscarId(id,lista,tamP);
    if(indice!=-1)
    {
        printf("\n1-AMOLADORA\n2-MEZCLADORA\n3-TALADRO\n\nIngrese numero de equipo a finalizar alquiler: ");
        scanf("%d",&equipo);
        if(equipo==1 || equipo==2 || equipo==3)
        {
            equipoindice=buscarEquipo(equipo,alquila,tamal);
            if(equipoindice!=-1)
            {
                alquila[indice].estado=0;
                printf("\nTiempo alquilado: ");
                scanf("%d",&alquiler[indice].tiemporeal);
                printf("\nAlquiler FINALIZADO\n\n");
            }
            else
            {
                printf("\nNo ah sido alquilado!\n");
            }
        }
        else
        {
            printf("OPCION INVALIDA!!\n\n");
        }

    }
    else
    {
        printf("\nID no encontrada.\n");
    }
}
int cantidadAlq(int alquiler, eAlquila a[],int tam)
{
    int cantidad=0;
    for(int i=0;i<tam;i++)
    {
        if(a[i].equipo==alquiler)
        {
            cantidad++;
        }
    }
    return cantidad;
}
int maximoAlq(eAlquila alquila[],int tamA,ePersona P[],int tamP)
{
    int maximo;
    int flag=0;
    int cantidad;
    for(int i=0;i<tamP;i++)
    {
    cantidad=cantidadAlq(alquila[i].equipo,P,tamP);
    if(cantidad>maximo || flag==0)
    {
        maximo=cantidad;
        flag=1;
    }
    }
    return maximo;
}
void clienteCMasAlq(eAlquila a[],int tamA, eAlquiler Al[],int tamAl)
{
    int cantidad;
    cantidad=maximoAlq(a,tamA, Al,tamAl);
    printf("\n---cliente con mas aquileres---\n\n");
    for(int i=0;i<tamA;i++)
    {
        if(cantidad==cantidadAlq(a[i].id,Al,tamAl))
        {
            printf("\n%s\n");//falta
        }
    }
}
