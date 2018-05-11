#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>
#include "productos.h"
#include "input.h"

int main()
{
    eProveedor proveedores[5];
    eProductos productos[50];
    inicializarVariables(productos, 50);
    hardcodeProv(proveedores);
    int salir = 0, id = 1;

    do
    {
        system("cls");
        switch(menu())
        {
        case 1:
            alta(productos, 50, id, proveedores);
            id++;
            break;
        case 2:
            modificacion(productos, 50, proveedores);
            break;
        case 3:
            baja(productos, 50, proveedores);
            break;
        case 4:
            system("cls");
            switch(menuOpcion4())
            {
            case 1:
                mostrarCantidadProductosSuperanProm(productos, 10);
                break;
            case 2:
                mostrarCantidadProductosNoSuperanProm(productos, 10);
                break;
            case 3:
                mostrarProductosMenos10(productos);
                break;
            case 4:
                mostrarProductosMas10(productos);
                break;
            case 5:
                break;
            }
            break;
        case 5:
            switch(menuOpcion5())
            {
            case 1:
                mostrarTodos(productos, 50, proveedores, 5);
                break;
            case 2:
                mostrarProductosMenos10Des(productos);
                break;
            case 3:
                mostrarProductosMas10Des(productos);
                break;
            case 4:
                mostrarCantidadProductosNoSuperanPromDes(productos, 50);
                break;
            case 5:
                mostrarCantidadProductosSuperanPromDes(productos, 50);
                break;
            case 6:
                mostrarProveedorConProductoMas10(proveedores, 5, productos, 50);
                break;
            case 7:
                productosDeProveedores(proveedores, productos);
                break;
            case 8:
                buscarProductosDeProveedor(proveedores, 5, productos, 50);
                break;
            case 9:
                proveedorConMasProductos(proveedores, 5, productos, 50);
                break;
            case 10:
                proveedorConMenosProductos(proveedores, 5, productos, 50);
                break;
            case 13:
                break;
            }

            break;
        case 6:
            salir = 1;
            break;
        }
    }
    while(salir != 1);

    return 0;
}
