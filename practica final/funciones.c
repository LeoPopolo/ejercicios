#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include "ArrayList.h"
#include "funciones.h"

int menu(ArrayList* this)
{
    char opcion[20];
    int esNum;

    system("cls");
    printf("Personas cargadas: %d", this->len(this));
    printf("\n\n1.Alta\n2.Modificacion\n3.Baja\n4.Mostrar clientes\n5.Importar clientes desde archivo .csv\n6.Realizar una venta\n7.Generar informe de ventas por producto\n8.Generar informe de ventas por fecha\n9.Informar...\n10.Guardar y salir\n\ningrese: ");

    fflush(stdin);
    scanf("%[^\n]", opcion);
    esNum = validar_num(opcion);

    while(esNum == 1)
    {
        system("cls");
        printf("Personas cargadas: %d", this->len(this));
        printf("\n\n1.Alta\n2.Modificacion\n3.Baja\n4.Mostrar clientes\n5.Importar clientes desde archivo .csv\n6.Realizar una venta\n7.Generar informe de ventas por producto\n8.Generar informe de ventas por fecha\n9.\nInformar...\n10.Guardar y salir\n\ningrese: ");
        fflush(stdin);
        scanf("%[^\n]", opcion);
        esNum = validar_num(opcion);
    }

    esNum = atoi(opcion);

    return esNum;
}

eCliente* newCliente()
{
    eCliente* aux = (eCliente*) malloc(sizeof(eCliente));

    if(aux != NULL)
    {
        strcpy(aux->nombre, "");
        strcpy(aux->apellido, "");
        strcpy(aux->dni, "");
        aux->id = 0;
    }

    return aux;
}

int idRepetido(ArrayList* this, int id)
{
    int i, retorno = 0;
    eCliente* aux;

    for(i=0; i<this->len(this); i++)
    {
        aux = (eCliente*) this->get(this, i);

        if(id == aux->id)
        {
            retorno = 1;
            break;
        }
    }

    return retorno;
}

int dniExiste(ArrayList* this, char* dni)
{
    int i, retorno = 0;
    eCliente* aux;

    for(i=0; i<this->len(this); i++)
    {
        aux = (eCliente*) this->get(this, i);

        if(strcmp(aux->dni, dni) == 0)
        {
            retorno = 1;
            break;
        }
    }

    return retorno;
}

int setApellido(eCliente* lista, char* apellido)
{
    int aux = -1;

    if(lista != NULL)
    {
        if(strlen(apellido) > 0 && strlen(apellido) < 30)
        {
            strcpy(lista->apellido, apellido);
            aux = 0;
        }
    }

    return aux;
}

char* getApellido(eCliente* lista)
{
    char* aux = (char*) malloc(sizeof(char)*30);

    if(lista != NULL && aux != NULL)
    {
        strcpy(aux, lista->apellido);
    }
    return aux;
}

int setNombre(eCliente* lista, char* nombre)
{
    int aux = -1;

    if(lista != NULL)
    {
        if(strlen(nombre) > 0 && strlen(nombre) < 30)
        {
            strcpy(lista->nombre, nombre);
            aux = 0;
        }
    }

    return aux;
}

char* getNombre(eCliente* lista)
{
    char* aux = (char*) malloc(sizeof(char)*30);

    if(lista != NULL && aux != NULL)
    {
        strcpy(aux, lista->nombre);
    }

    return aux;
}

int setFecha(eProducto* lista, char* fecha)
{
    int aux = -1;

    if(lista != NULL)
    {
        if(strlen(fecha) > 4 && strlen(fecha) < 9)
        {
            strcpy(lista->fechaVenta, fecha);
            aux = 0;
        }
    }

    return aux;
}

char* getFecha(eProducto* lista)
{
    char* aux = (char*) malloc(sizeof(char)*9);

    if(lista != NULL && aux != NULL)
    {
        strcpy(aux, lista->fechaVenta);
    }

    return aux;
}

int setDNI(eCliente* lista, char* dni)
{
    int aux = -1;

    if(lista != NULL)
    {
        if(strlen(dni) > 5 && strlen(dni) < 11 && validar_num(dni) == 0)
        {
            strcpy(lista->dni, dni);
            aux = 0;
        }
    }

    return aux;
}

char* getDNI(eCliente* lista)
{
    char* aux = (char*) malloc(sizeof(char)*30);

    if(lista != NULL && aux != NULL)
    {
        strcpy(aux, lista->dni);
    }
    return aux;
}

int setProducto(eProducto* lista, char* descripcion)
{
    int aux = -1;

    if(lista != NULL)
    {
        if(strlen(descripcion) > 0 && strlen(descripcion) < 17)
        {
            strcpy(lista->descripcion, descripcion);
            aux = 0;
        }
    }

    return aux;
}

char* getProducto(eProducto* lista)
{
    char* aux = (char*) malloc(sizeof(char)*17);

    if(lista != NULL && aux != NULL)
    {
        strcpy(aux, lista->descripcion);
    }
    return aux;
}

int setCosto(eProducto* lista, int costo)
{
    int aux = -1;

    if(lista != NULL)
    {
        if(costo > 0)
        {
            lista->costo = costo;
            aux = 0;
        }
    }

    return aux;
}

float getCosto(eProducto* lista)
{
    float aux;

    if(lista != NULL)
    {
        aux = lista->costo;
    }
    return aux;
}

int setCantidad(eProducto* lista, int cantidad)
{
    int aux = -1;

    if(lista != NULL)
    {
        if(cantidad > 0)
        {
            lista->cantidad = cantidad;
            aux = 0;
        }
    }

    return aux;
}

int getCantidad(eProducto* lista)
{
    int aux;

    if(lista != NULL)
    {
        aux = lista->cantidad;
    }
    return aux;
}

int setIDc(eProducto* lista, int id)
{
    int aux = -1;

    if(lista != NULL)
    {
        if(id >= 0)
        {
            lista->idCliente = id;
            aux = 0;
        }
    }

    return aux;
}

int getIDc(eProducto* lista)
{
    int aux;

    if(lista != NULL)
    {
        aux = lista->idCliente;
    }
    return aux;
}

int setID(eCliente* lista, int id)
{
    int aux = -1;

    if(lista != NULL)
    {
        if(id > 0)
        {
            lista->id = id;
            aux = 0;
        }
    }

    return aux;
}

int getID(eCliente* lista)
{
    int aux;

    if(lista != NULL)
    {
        aux = lista->id;
    }
    return aux;
}

int buscarID(ArrayList* this, int id)
{
    int aux = -1, i;
    eCliente* cliente = newCliente();

    if(this != NULL)
    {
        for(i=0; i<this->len(this); i++)
        {
            cliente = (eCliente*)this->get(this, i);
            if(id == cliente->id)
            {
                aux = i;
                break;
            }
        }
    }

    return aux;
}

void alta(ArrayList* this)
{
    eCliente* lista;
    int id;
    char nombre[30], dni[12], apellido[30];

    if(this != NULL)
    {
        lista = newCliente();

        if(lista != NULL)
        {
            do
            {
                printf("Ingrese nombre: ");
                fflush(stdin);
                scanf("%[^\n]", nombre);
            }
            while(setNombre(lista, nombre) == -1);
            do
            {
                printf("Ingrese apellido: ");
                fflush(stdin);
                scanf("%[^\n]", apellido);
            }
            while(setApellido(lista, apellido) == -1);
            do
            {
                printf("Ingrese DNI: ");
                fflush(stdin);
                scanf("%[^\n]", dni);
                if(dniExiste(this, dni) == 1)
                {
                    printf("el dni ya existe.\n\n");
                }
            }
            while(setDNI(lista, dni) == -1 || dniExiste(this, dni) == 1);
            id = (this->len(this)) + 1;
            while(idRepetido(this, id) == 1)
            {
                id++;
            }

            lista->id = id;

            this->add(this, lista);
            printf("\nAlta exitosa.\nid: %d\n\n", id);
            system("pause");
        }
    }
}

int clienteTieneVentas(ArrayList* lista, int id)
{
    eProducto* prod = newProducto();
    int i;

    for(i=0; i<lista->len(lista); i++)
    {
        prod = lista->get(lista, i);

        if(prod->idCliente == id)
        {
            return 1;
        }
    }

    return 0;
}

void baja(ArrayList* this, ArrayList* ventas)
{
    eCliente* lista = newCliente();
    int buscar, id, venta;
    char opcion;

    if(this != NULL && lista != NULL && this->isEmpty(this) != 1)
    {
        mostrar(this);
        printf("\ningrese id a buscar: ");
        fflush(stdin);
        scanf("%d", &id);
        venta = clienteTieneVentas(ventas, id);
        buscar = buscarID(this, id);
        if(buscar == -1 || venta == 1)
        {
            system("cls");
            if(buscar == -1)
            {
                printf("No se encontro el dni.\n\n");
            }
            if(venta == 1)
            {
                printf("No se puede eliminar a un cliente con ventas realizadas.\n\n");
            }
            system("pause");
        }
        else
        {
            lista = (eCliente*)this->get(this, buscar);
            system("cls");
            printf("\ndesea eliminar esta persona? s/n\n\n");
            mostrarUno(lista);
            fflush(stdin);
            opcion = getch();
            if(opcion == 's')
            {
                this->remove(this, buscar);
            }
            printf("\nBaja exitosa.\n\n");
            system("pause");
        }
    }
    else if(this->isEmpty(this) == 1)
    {
        printf("No hay datos cargados.\n\n");
        system("pause");
    }
}

FILE* abrirArchivo(char* path)
{
    FILE* f;

    f = fopen(path,"r");

    if(f==NULL)
    {
        printf("No existe el archivo.\n");
        system("pause");
    }

    return f;
}

char* cargarArchivo()
{
    char* nombre =(char*) malloc(sizeof(char)*50);

    if(nombre != NULL)
    {
        printf("Ingrese nombre del archivo: ");
        fflush(stdin);
        scanf("%[^\n]", nombre);
    }

    return nombre;
}

void parsearArchivo(ArrayList* this)
{
    eCliente* lista;
    char path[50];
    char encabezado[100];
    char nombre[30], apellido[30], dni[12];
    int cantidad, id;

    strcpy(path, cargarArchivo());

    FILE* f = abrirArchivo(path);

    if(f != NULL)
    {
        rewind(f);
        fscanf(f, "%[^\n]\n", encabezado);
        while(!feof(f))
        {
            lista = newCliente();

            cantidad = fscanf(f, "%[^,],%[^,],%[^\n]\n", nombre, apellido, dni);

            if(!dniExiste(this, dni) && cantidad == 3)
            {
                id = (this->len(this)) + 1;
                while(idRepetido(this, id) == 1)
                {
                    id++;
                }

                setID(lista, id);
                setNombre(lista, nombre);
                setApellido(lista, apellido);
                setDNI(lista, dni);

                this->add(this, lista);

            }

        }
        printf("Archivo cargado.\n");
        system("pause");
    }
}

void Modificacion(ArrayList* this)
{
    eCliente* lista = newCliente();
    int buscar, eleccion;
    char dni[12], opcion, nombre[30], apelldo[30];
    int id;

    if(this != NULL && lista != NULL && this->isEmpty(this) != 1)
    {
        mostrar(this);
        printf("\ningrese id a buscar: ");
        fflush(stdin);
        scanf("%d", &id);
        buscar = buscarID(this, id);
        if(buscar == -1)
        {
            printf("No se encontro el id.\n\n");
            system("pause");
        }
        else
        {
            lista = this->get(this, buscar);
            system("cls");
            printf("\ndesea modificar esta persona? s/n\n\n");
            mostrarUno(lista);
            fflush(stdin);
            opcion = getch();
            if(opcion == 's' )
            {
                do
                {
                    system("cls");
                    printf("1-Nombre\n2-Apellido\n3-DNI\n4-Volver\n\nIngrese opcion: ");
                    scanf("%d", &eleccion);
                    switch(eleccion)
                    {
                    case 1:
                        do
                        {
                            printf("Ingrese nombre: ");
                            fflush(stdin);
                            scanf("%[^\n]", nombre);
                        }
                        while(setNombre(lista, nombre) == -1);
                        break;
                    case 2:
                        do
                        {
                            printf("Ingrese apellido: ");
                            fflush(stdin);
                            scanf("%[^\n]", apelldo);
                        }
                        while(setApellido(lista, apelldo) == -1);
                        break;
                    case 3:
                        do
                        {
                            printf("Ingrese DNI: ");
                            fflush(stdin);
                            scanf("%[^\n]", dni);
                        }
                        while(setDNI(lista, dni) == -1);
                        break;
                    case 4:
                        break;
                    default:
                        printf("Opcion incorrecta.\n");
                        Sleep(1000);
                        break;
                    }

                }
                while(opcion < 4);
                printf("\nModificacion exitosa.\n\n");
                system("pause");
            }

        }
    }
    if(this->isEmpty(this) == 1)
    {
        printf("No hay datos cargados.\n\n");
        system("pause");
    }
}

void venta(ArrayList* thisC, ArrayList* thisV)
{
    char producto[17], fecha[9];
    int id, buscar, cantidad;
    float costo;
    eProducto* listap;

    if(thisC != NULL && thisV != NULL && thisC->isEmpty(thisC) == 0)
    {
        mostrar(thisC);

        printf("Ingrese id de cliente: ");
        scanf("%d", &id);

        buscar = buscarID(thisC, id);

        if(buscar != -1)
        {
            listap = newProducto();
            do
            {
                printf("Ingrese codigo de producto: ");
                fflush(stdin);
                scanf("%[^\n]", producto);
            }
            while(setProducto(listap, producto) != 0);

            do
            {
                printf("Ingrese costo unitario de producto: ");
                scanf("%f", &costo);
            }
            while(setCosto(listap, costo) != 0);

            do
            {
                printf("Ingrese cantidad de productos: ");
                scanf("%d", &cantidad);
            }
            while(setCantidad(listap, cantidad) != 0);

            do
            {
                printf("Ingrese fecha de venta. (DD-MM-AA): ");
                fflush(stdin);
                scanf("%[^\n]", fecha);
            }
            while(setFecha(listap, fecha) != 0);

            setIDc(listap, id);

            thisV->add(thisV, listap);

            printf("Venta realizada.\n");
            system("pause");
        }
    }
    if(thisC->isEmpty(thisC) == 1)
    {
        printf("No hay clientes para realizar una venta.\n");

        system("pause");
    }


}

FILE* abrirArchivoW(char* path)
{
    strcat(path, ".csv");

    FILE* f;

    if((f = fopen(path, "w"))==NULL)
    {
        printf("Se creara el archivo,\n");
        Sleep(1000);
    }

    return f;
}

int buscarProd(ArrayList* this, char* desc)
{
    int i, retorno = -1;
    eProducto* prod = newProducto();

    if(prod != NULL && this != NULL && desc != NULL)
    {
        for(i=0; i<this->len(this); i++)
        {
            prod = this->get(this, i);

            if(strcmp(prod->descripcion, desc) == 0)
            {
                retorno = 1;
                break;
            }
        }
    }

    return retorno;
}

int buscarProdFecha(ArrayList* this, char* desc)
{
    int i, retorno = -1;
    eProducto* prod = newProducto();

    if(prod != NULL && this != NULL && desc != NULL)
    {
        for(i=0; i<this->len(this); i++)
        {
            prod = this->get(this, i);

            if(strcmp(prod->fechaVenta, desc) == 0)
            {
                retorno = 1;
                break;
            }
        }
    }

    return retorno;
}

void informeDeVentaFecha(ArrayList* ventas)
{
    char descripcion[17], nombreArchivo[25];
    eProducto* prod = newProducto();
    int i, existe;
    FILE* f;
    printf("Ingrese fecha a informar ventas: ");
    fflush(stdin);
    scanf("%[^\n]", descripcion);

    existe = buscarProdFecha(ventas, descripcion);

    strcpy(nombreArchivo, descripcion);

    f = abrirArchivoW(nombreArchivo);

    if(f != NULL && ventas->isEmpty(ventas) != 1 && existe == 1)
    {
        rewind(f);
        ordenarV(ventas);
        fprintf(f,"Id Cliente,Id Producto,Importe total,Fecha de venta\n");
        for(i=0; i<ventas->len(ventas); i++)
        {
            prod = ventas->get(ventas, i);

            if(strcmp(prod->fechaVenta, descripcion) == 0)
            {
                fprintf(f, "%d,%s,%.2f,%s\n", getIDc(prod), getProducto(prod), (getCantidad(prod)*getCosto(prod)),getFecha(prod));
            }
        }
        system("cls");
        printf("Archivo generado.\n");

        fclose(f);
    }

    if(existe == -1)
    {
        printf("\nNo hay productos vendidos en esa fecha.\n");
    }
    if(ventas->isEmpty(ventas) == 1)
    {
        printf("\nNo hay ventas.\n");
    }
    if(f == NULL)
    {
        printf("\nNo se pudo generar el archivo.\n");
    }
    system("pause");

}

void informeDeVenta(ArrayList* ventas)
{
    char descripcion[17], nombreArchivo[25];
    eProducto* prod = newProducto();
    int i, existe;
    printf("Ingrese codigo de producto a informar: ");
    fflush(stdin);
    scanf("%[^\n]", descripcion);

    existe = buscarProd(ventas, descripcion);

    strcpy(nombreArchivo, descripcion);

    FILE* f = abrirArchivoW(nombreArchivo);

    if(f != NULL && ventas->isEmpty(ventas) != 1 && existe == 1)
    {
        rewind(f);
        ordenarV(ventas);
        fprintf(f,"Id Cliente,Id Producto,Importe total,Fecha de venta\n");
        for(i=0; i<ventas->len(ventas); i++)
        {
            prod = ventas->get(ventas, i);

            if(strcmp(prod->descripcion, descripcion) == 0)
            {
                fprintf(f, "%d,%s,%.2f,%s\n", getIDc(prod), getProducto(prod), (getCantidad(prod)*getCosto(prod)),getFecha(prod));
            }
        }
        system("cls");
        printf("Archivo generado.\n");

        fclose(f);
    }
    if(ventas->isEmpty(ventas) == 1)
    {
        printf("\nNo hay ventas.\n");
    }
    if(existe == -1)
    {
        printf("\nNo hay un producto con ese codigo.\n");
    }
    system("pause");

}

int validar_num(char* opcion)
{
    int i, flag = 0, size;

    size = strlen(opcion);

    for(i=0; i<size; i++)
    {
        if(*(opcion+i) < 48  || *(opcion+i) > 57)
        {
            flag = 1;
            break;
        }
    }

    return flag;
}

void ordenarV(ArrayList* this)
{
    this->sort(this,compararImportes,1);
}

int compararImportes(void* productoA,void* productoB)
{
    if(productoA != NULL && productoB != NULL)
    {
        eProducto* proA = (eProducto*) productoA;
        eProducto* proB = (eProducto*) productoB;
        if((proA->costo*proA->cantidad) < (proB->costo*proB->cantidad))
        {
            return 1;
        }
    }
    return 0;
}

void ordenar(ArrayList* this)
{
    this->sort(this,compararPersonas,1);
}

int compararPersonas(void* personaA,void* personaB)
{
    if(personaA != NULL && personaB != NULL)
    {
        eCliente* perA = (eCliente*) personaA;
        eCliente* perB = (eCliente*) personaB;
        return strcmp(perA->apellido, perB->apellido);
    }
    return 0;
}

void productoMasVendido(ArrayList* lista)
{
    eProducto* prod = newProducto();
    int columnas = lista->len(lista), j;

    char **productos;
    productos = (char **)malloc (17*sizeof(char*));

    for (j=0; j<17; j++)
        productos[j] = (char *) malloc (columnas*sizeof(char));

    if(productos != NULL)
    {
        for(int i=0; i<lista->len(lista); i++)
        {
            prod = lista->get(lista, i);

        }
    }
}

void clienteConMasCompras(ArrayList* ventas)
{

}

int menuCase9()
{
    char opcion[20];
    int esNum;

    system("cls");
    printf("\n1.Producto con mayor numero de ventas\n2.Cliente que mas productos ha comprado\n3.Volver\n\ningrese: ");
    fflush(stdin);
    scanf("%[^\n]", opcion);
    esNum = validar_num(opcion);

    while(esNum == 1)
    {
        system("cls");
        printf("\n1.Producto con mayor numero de ventas\n2.Cliente que mas productos ha comprado\n3.Volver\n\ningrese: ");
        fflush(stdin);
        scanf("%[^\n]", opcion);
        esNum = validar_num(opcion);
    }

    esNum = atoi(opcion);

    return esNum;
}

void menuCase9Switch(ArrayList* lista, ArrayList* ventas)
{
    int opcion;

    do
    {
        switch(opcion = menuCase9())
        {
        case 1:
            productoMasVendido(lista);
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            printf("\nOpcion incorrecta.\n");
            Sleep(1000);
        }
    }
    while(opcion != 3);

}

/*void mostrarUnProducto(eProducto* lista)
{
    printf("%-5d%-20s%-11.2f%-3d\n", getIDc(lista), getProducto(lista), getCosto(lista), getCantidad(lista));
}

void mostrarP(ArrayList* this)
{
    int i;
    eProducto* lista = newProducto();

    if(this != NULL && lista != NULL)
    {
        system("cls");
        if(this->isEmpty(this) == 1)
        {
            printf("La lista esta vacia.\n");
        }
        else
        {
            ordenar(this);
            printf("Id   producto            costo u    cantidad\n\n");
            for(i=0; i<this->len(this); i++)
            {
                lista = (eProducto*)this->get(this, i);
                mostrarUnProducto(lista);
            }
        }
        printf("\n\n");
    }
}*/

void mostrarUno(eCliente* lista)
{
    printf("%-5d%-20s%-20s%-10s\n", getID(lista), getNombre(lista), getApellido(lista), getDNI(lista));
}

void mostrar(ArrayList* this)
{
    int i;
    eCliente* lista = newCliente();

    if(this != NULL && lista != NULL)
    {
        system("cls");
        if(this->isEmpty(this) == 1)
        {
            printf("La lista esta vacia.\n");
        }
        else
        {
            ordenar(this);
            printf("Id   Nombre              Apellido            DNI       \n\n");
            for(i=0; i<this->len(this); i++)
            {
                lista = (eCliente*)this->get(this, i);
                mostrarUno(lista);
            }
        }
        printf("\n\n");
    }
}



eProducto* newProducto()
{
    eProducto* aux = (eProducto*) malloc(sizeof(eProducto));

    if(aux != NULL)
    {
        strcpy(aux->fechaVenta, "");
        strcpy(aux->descripcion, "");
        aux->costo = 0;
        aux->cantidad = 0;
        aux->idCliente = 0;
    }

    return aux;
}

FILE* leerArchivo(char* path)
{
    FILE* archivo;

    if((archivo = fopen(path, "rb")) == NULL)
    {
        printf("\nNo se pudo abrir el archivo\n");
    }

    return archivo;
}

FILE* crearArchivo(char* path)
{
    FILE* archivo;

    if((archivo = fopen(path, "wb")) == NULL)
    {
        printf("\nNo se pudo abrir el archivo\n");
    }

    return archivo;
}

void cargarArchivov(ArrayList* this)
{
    FILE* archivo = leerArchivo("datosv.bin");
    eProducto aux;
    int validar;
    eProducto* lista;
    rewind(archivo);
    if(archivo != NULL)
    {
        while (!feof(archivo))
        {
            validar = fread(&aux, sizeof(eProducto), 1, archivo);
            lista = newProducto();
            if(validar == 1 && lista != NULL)
            {
                strcpy(lista->descripcion, aux.descripcion);
                strcpy(lista->fechaVenta, aux.fechaVenta);
                lista->idCliente = aux.idCliente;
                lista->costo = aux.costo;
                lista->cantidad = aux.cantidad;
                this->add(this, lista);
            }

            if(validar!=1)
            {
                if(feof(archivo))
                {
                    break;
                }
                else
                {
                    printf("No leyo el ultimo registro\n");
                    system("pause");
                    break;
                }
            }

        }
        printf("\nArchivo cargado.\n\n");
        system("pause");

        fclose(archivo);
    }
}

void guardarArchivov(ArrayList* this)
{
    int i;
    eProducto* lista;
    FILE* f = crearArchivo("datosv.bin");

    if(this != NULL)
    {
        if(f != NULL)
        {
            rewind(f);
            for (i=0; i < this->len(this); i++)
            {
                lista = (eProducto*)this->get(this, i);

                fwrite(lista, sizeof(eProducto), 1, f);
            }
            fclose(f);
        }
    }
}

void cargarArchivob(ArrayList* this)
{
    FILE* archivo = leerArchivo("datos.bin");
    eCliente aux;
    int validar;
    eCliente* lista;
    rewind(archivo);
    if(archivo != NULL)
    {
        while (!feof(archivo))
        {
            validar = fread(&aux, sizeof(eCliente), 1, archivo);
            lista = newCliente();
            if(validar == 1 && lista != NULL)
            {
                strcpy(lista->nombre, aux.nombre);
                strcpy(lista->apellido, aux.apellido);
                strcpy(lista->dni, aux.dni);
                lista->id = aux.id;
                this->add(this, lista);
            }

            if(validar!=1)
            {
                if(feof(archivo))
                {
                    break;
                }
                else
                {
                    printf("No leyo el ultimo registro\n");
                    system("pause");
                    break;
                }
            }

        }
        printf("\nArchivo cargado.\n\n");
        system("pause");

        fclose(archivo);
    }
}

void guardarArchivo(ArrayList* this)
{
    int i;
    eCliente* lista;
    FILE* f = crearArchivo("datos.bin");

    if(this != NULL)
    {
        if(f != NULL)
        {
            rewind(f);
            for (i=0; i < this->len(this); i++)
            {
                lista = (eCliente*)this->get(this, i);

                fwrite(lista, sizeof(eCliente), 1, f);
            }
            fclose(f);
        }
    }
}

void gotoxy(int x, int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}
