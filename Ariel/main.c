#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int legajo;
    char nombre[20];
} eAlumno;

typedef struct
{
    int id;
    char descripcion[20];
} eMateria;

typedef struct
{
    int legajo;
    int idMateria;
} eInscripcion;
//int maximoInscriptos(eInscripcion I[],int tamI,eMateria M[],int tamM);
void mostrarAlumnosconMaterias(eAlumno A[],int tamA,eInscripcion I[],int tamI,eMateria[],int tamM);
int cantidadInscriptos(int materia, eInscripcion I[],int tam);
void mostrarMateriasConCantidadDeInscriptos(eInscripcion I[],int tamI,eMateria M[],int tamM);
void materiaMasCursada(eInscripcion I[],int tamI,eMateria M[],int tamM);
int main()
{
    eAlumno Alumnos[]= {{1, "Jose"}, {3, "Alberto"}, {4, "Juan"}, {7, "Luis"}, {10, "Ana"}, {9, "Silvia"}, {8, "Maria"}, {15, "Sofia"}, {18, "Martin"}, {11, "Dalia"}};
    eMateria Materias[]= {{1, "Progamacion"}, {2, "Matematicas"},{3, "Quimica"}, {4, "Fisica"}, {5, "Electronica"}};
    eInscripcion Inscripciones[]= {{1,2}, {1,3}, {3,2}, {4,4}, {3,5}, {3,1}, {4,1}, {1,1}, {8,1}, {9,3}, {10,2}, {10,5}, {10, 3}, {8, 1}, {1,2}};
    mostrarAlumnosconMaterias(Alumnos,10,Inscripciones,15,Materias,5);
    mostrarMateriasConCantidadDeInscriptos(Inscripciones,15,Materias,5);
    materiaMasCursada(Inscripciones,15,Materias,5);
    return 0;
}
void mostrarAlumnosconMaterias(eAlumno A[],int tamA,eInscripcion I[],int tamI,eMateria M[],int tamM)
{
    printf("---Alumnos con Materias---\n\n");
    for(int i=0; i<tamA; i++)
    {
        printf("\t%s\n",A[i].nombre);
        for(int j=0; j<tamI; j++)
        {
            if(A[i].legajo==I[j].legajo)
            {
                for(int k=0; k<tamM; k++)
                {
                    if(I[j].idMateria==M[k].id)
                    {
                        printf("\t\t%s\n",M[k].descripcion);
                        break;
                    }
                }
            }
        }
    }
}
void mostrarMateriasConCantidadDeInscriptos(eInscripcion I[],int tamI,eMateria M[],int tamM)
{
    int cantidad;
    printf("\n---Cantidad de alumnos inscriptos por materia---\n\n");
    for (int i=0;i<tamM;i++)
    {
        printf("\t%s: ",M[i].descripcion);
        cantidad=cantidadInscriptos(M[i].id,I,tamI);
        printf("%d\n\n",cantidad);
    }
}
int cantidadInscriptos(int materia, eInscripcion I[],int tam)
{
    int cantidad=0;
    for(int i=0;i<tam;i++)
    {
        if(I[i].idMateria==materia)
        {
            cantidad++;
        }
    }
    return cantidad;
}
int maximoInscriptos(eInscripcion I[],int tamI,eMateria M[],int tamM)
{
    int maximo;
    int flag=0;
    int cantidad;
    for(int i=0;i<tamM;i++)
    {
    cantidad=cantidadInscriptos(M[i].id,I,tamI);
    if(cantidad>maximo || flag==0)
    {
        maximo=cantidad;
        flag=1;
    }
    }
    return maximo;
}
void materiaMasCursada(eInscripcion I[],int tamI,eMateria M[],int tamM)
{
    int cantidad;
    cantidad=maximoInscriptos(I,tamI,M,tamM);
    printf("\n---Materia mas cursada---\n\n");
    for(int i=0;i<tamM;i++)
    {
        if(cantidad==cantidadInscriptos(M[i].id,I,tamI))
        {
            printf("%s\n",M[i].descripcion);
        }
    }
}
