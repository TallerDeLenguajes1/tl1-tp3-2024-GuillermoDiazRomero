#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define LISTA 5

typedef struct
{
    int ProductoID;       // Numerado en ciclo iterativo
    int Cantidad;         // entre 1 y 10
    char *TipoProducto;   // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} Producto;

typedef struct
{
    int ClienteID;               // Numerado en el ciclo iterativo
    char *NombreCliente;         // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos          // El tamaño de este arreglo depende de la variable
    // “CantidadProductosAPedir"
} Cliente;

void cargarClientes(Cliente *c, int cant);
// Punto 4
void main()
{
    char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};
    int cantClientes, respuesta;
    srand(time(NULL));
    // Punto 4i
    do
    {
        printf("\nIngrese la cantidad de clientes: ");
        scanf("%d", &cantClientes);
    } while (cantClientes < 1 || cantClientes > 5);

    // Punto 4ii
    do
    {
        puts("\nDesea cargar los datos? (1 para si y 0 para no):");
        scanf("%d", &respuesta);
    } while (respuesta != 0 && respuesta != 1);
    if (respuesta == 1)
    {
        Cliente *clien = malloc(cantClientes * sizeof(Cliente));
        fflush(stdin);

        cargarClientes(clien, cantClientes);

        free(clien);
    }
}

void cargarClientes(Cliente *c, int cant)
{
    char nombre[30];
    int longitud, cantidad;
    for (int i = 0; i < cant; i++)
    {
        // ID
        c[i].ClienteID = i;
        // NOMBRE
        printf("\nIngrese su Nombre: ");
        gets(nombre);
        fflush(stdin);
        longitud = strlen(nombre) + 1;
        c[i].NombreCliente = (char *)malloc(longitud * sizeof(char));
        strcpy(c[i].NombreCliente, nombre);
        // Cantidad de Productos a pedir
        c[i].CantidadProductosAPedir = 1 + rand() % 5;
        // Productos
        c[i].Productos = (int *)malloc(c[i].CantidadProductosAPedir * sizeof(int));
        cantidad = c[i].CantidadProductosAPedir;
        for (int j = 0; j < cantidad; j++){
            c[i].Productos[j].ProductoID = j;
        }
        
    }
}

typedef struct
{
    int ProductoID;       // Numerado en ciclo iterativo
    int Cantidad;         // entre 1 y 10
    char *TipoProducto;   // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} Producto;
