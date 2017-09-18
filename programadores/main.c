#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct{
    int id;
    char nombre[20];
    char categoria;
    int proyecto;
    int estado;
}
eProgramador;



//a = Senior
//b = SemiSenior
//c = Junior

int menu();
void inicializarVector(eProgramador[], int tam);
void mostrarProgramador(eProgramador campo);
void mostrarProgramadores(eProgramador campo[], int tam);
int buscarLibre(eProgramador campo[], int tam);
int buscarProgramador(int id, eProgramador campo[], int tam);
void altaProgramador(eProgramador campo[], int tam);
void bajaProgramador(eProgramador campo[], int tam);

int main()
{
    eProgramador equipo[50];
    inicializarVector(equipo, 50);
    int salir = 1;
    int tam = 2;

    do{
        switch(menu()){

    case 1:
        system("cls");
        altaProgramador(equipo, tam);

        break;

    case 2:
         system("cls");
        printf("Opcion2");
        getch();


        break;
    case 3:
         system("cls");
        bajaProgramador(equipo, tam);
        getch();

        break;

    case 4:
         system("cls");
        // inicializarVector(equipo,5);
         mostrarProgramadores(equipo, 5);
         getch();
        break;



    case 5:
      salir = 0;



        break;

        }

    }while(salir);
    return 0;
}


    int menu(){
        int opcion;
        system("cls");
        printf("\n***Programadores***\n\n\n");
        printf("1- Alta Programador\n");
        printf("2- Modificacion Programador\n");
        printf("3- Baja Programador\n");
        printf("4- Listado Programadores\n");
        printf("5- Salir\n");
        printf("\n\nIngrese opcion: ");
        scanf("%d", &opcion);

        return opcion;

    }
void inicializarVector(eProgramador campo[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        campo[i].id = 0;
        campo[i].estado = 0;
    }

}
void mostrarProgramador(eProgramador campo)
{
    char cat[11];


        if(campo.categoria == 'a')
        {
            strcpy(cat, "Senior");
        }
        else if(campo.categoria == 'b')
        {
            strcpy(cat, "Semisenior");
        }
        else
        {
            strcpy(cat, "Junior");
        }

    printf("%d\t%s\t%s\t%d\t", campo.id, campo.nombre, cat, campo.proyecto);

}
void mostrarProgramadores(eProgramador campo[], int tam)
{
    int i;
    int flag = 0;

    printf("\nId\tNombre\tCategoria\tProyecto\t\n");
    for(i=0; i<tam; i++)
    {
        if(campo[i].estado == 1)
        {
            mostrarProgramador(campo[i]);
            flag = 1;
        }

    }
    if(flag == 0)
    {
        system("cls");
        printf("\nNo hay programadores para mostrar.\n");
    }
}
int buscarLibre(eProgramador campo[], int tam)
{
    int i;
    int flag = 0;

    for(i=0; i<tam; i++)
    {
        if(campo[i].estado == 0)
        {
            flag = i;
            break;
        }
    }

    return flag;
}
int buscarProgramador(int id, eProgramador campo[], int tam)
{
    int i;
    int indice = -1;


    for(i=0; i<tam; i++)
    {
        if(campo[i].id == id  && campo[i].estado == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}
void altaProgramador(eProgramador campo[], int tam)
{
    eProgramador nuevoProgramador;
    int esta;
    int libre;
    int id;


    libre = buscarLibre(campo, tam);

    if(libre == -1)
    {
        printf("No hay espacio disponible.\n");
    }
    else
    {

        printf("ingrese id: ");
        scanf("%d", &id);
        esta = buscarProgramador(id, campo, tam);
    }
        if(esta != -1)
        {
            printf("el id ya existe.");
            getch();
        }
        else
        {
            nuevoProgramador.id = id;
            printf("ingrese nombre: ");
            fflush(stdin);
            gets(nuevoProgramador.nombre);
            printf("ingrese categoria: a- Senior b- Semisenior c- Junior ");
            nuevoProgramador.categoria = getch();
            printf("\ningrese proyecto: ");
            scanf("%d", &nuevoProgramador.proyecto);
            nuevoProgramador.estado = 1;
        }


    campo[libre] = nuevoProgramador;
}

void bajaProgramador(eProgramador campo[], int tam)
{
    int id;
    char respuesta = 'n';
    int esta;

        printf("ingrese id: ");
        scanf("%d", &id);
        esta = buscarProgramador(id, campo, tam);
        if(esta != -1)
        {
            mostrarProgramadores(campo, tam);
            printf("\nconfirmar baja? ");
            respuesta = getch();
            if(respuesta == 's')
            {
                campo[esta].estado = 0;
                printf("\nbaja con exito.");
            }
            else
            {
                printf("\nno se pudo dar de baja.");
            }
        }

}
