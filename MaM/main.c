#include <stdio.h>
#include <stdlib.h>

/*
    -alumnos con materias.
    -cantidad de inscriptos a materias.
    -materias con mas inscriptos.
    -materias con alumnos.
*/

typedef struct{
    int legajo;
    char nombre[20];
}eAlumno;

typedef struct{
    int id;
    char descripcion[20];
}eMateria;

typedef struct{
    int legajo;
    int idMateria;
}eInscripcion;

void mostrarAlumnoCMateria(eAlumno lista1[], eMateria lista2[], eInscripcion lista3[], int tamAlum, int tamMat, int tamInsc);
void mostrarMateriasInscrip(eMateria lista1[], int tamMat, eInscripcion lista2[], int tamInsc);
int cantInscriptos(int materia, eInscripcion lista[], int tam);

int main()
{
    eAlumno Alumnos[]={{1, "Jose"}, {3, "Alberto"}, {4, "Juan"}, {7, "Luis"}, {10, "Ana"}, {9, "Silvia"}, {8, "Maria"}, {15, "Sofia"}, {18, "Martin"}, {11, "Dalia"}};
    eMateria Materias[]={{1, "Programacion"}, {2, "Matematicas"},{3, "Quimica"}, {4, "Fisica"}, {5, "Electronica"}};
    eInscripcion Inscripciones[]={{1,2}, {1,3}, {3,2}, {4,4}, {3,5}, {3,1}, {4,1}, {1,1}, {8,1}, {9,3}, {10,2}, {10,5}, {10, 3}, {8, 2}, {1,2}};

    mostrarAlumnoCMateria(Alumnos,Materias,Inscripciones, 10, 5, 15);
    mostrarMateriasInscrip(Materias, 5, Inscripciones, 15);

    return 0;
}

void mostrarAlumnoCMateria(eAlumno lista1[], eMateria lista2[], eInscripcion lista3[], int tamAlum, int tamMat, int tamInsc)
{
    int i, j, k;

    printf("--alumnos con materias--\n\n");
    for(i=0; i<tamAlum; i++)
    {
        printf("%s\t\n", lista1[i].nombre);
        for(j=0; j<tamInsc; j++)
        {
            if(lista1[i].legajo == lista3[j].legajo)
            {
                for(k=0; k<tamMat; k++)
                {
                    if(lista3[j].idMateria == lista2[k].id)
                    {
                        printf("\t\t%s\n", lista2[k].descripcion);
                    }
                }
            }
        }
    }
}

void mostrarMateriasInscrip(eMateria lista1[], int tamMat, eInscripcion lista2[], int tamInsc)
{
    int cantidad = 0;
    int i;

    printf("\n\n--inscripciones de materias--\n\n");
    for(i=0;i<tamMat;i++)
    {
        printf("\t%s: ",lista1[i].descripcion);

        cantidad=cantInscriptos(lista1[i].id,lista2,tamInsc);

        printf("%d\n\n",cantidad);
    }
}

int cantInscriptos(int materia, eInscripcion lista[], int tam)
{
    int cantidad = 0;
    int i;

    for(i=0; i<tam; i++)
    {
        if(lista[i].idMateria == materia)
        {
            cantidad++;
        }
    }
    return cantidad;
}
