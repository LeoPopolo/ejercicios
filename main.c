#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"

int main()
{
    eProgramador lista1 [] = {{.idProg = 1, .nombre = "Juan", .estado = 1},{.idProg = 2, .nombre = "Miguel", .estado = 1},{.idProg = 3, .nombre = "Maria", .estado = 1}};
    eProyecto lista3 [] = {{.idProy = 1, .nombreProy = "Android", .hsProy = 50},{.idProy = 2, .nombreProy = "iOS", .hsProy = 65},{.idProy = 3, .nombreProy = "Windows Phone", .hsProy = 70}};
    eCategoria lista2 [] = {{.idCat = 1, .nombreCat = "Junior", .valorPH = 50},{.idCat = 2, .nombreCat = "SemiSenior", .valorPH = 75},{.idCat = 3, .nombreCat = "Senior", .valorPH = 100}};
    ePPC lista4 [] = {{ 1, 1, 1}, {2, 2, 2}, {3, 3, 3}};

    mostrarProgram(lista1, lista2, lista3 , lista4, 3, 3, 3);


    return 0;
}
