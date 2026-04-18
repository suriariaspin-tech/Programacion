/*
Autores: Nicolas Menendez, Joel Cruz y Suri Arias
Fecha: 15/04/2026
Descripcion: Este programa permite ingresar datos de tres sucursales, incluyendo el nombre de la sucursal, el número de productos, 
el nombre de cada producto, la cantidad disponible y el precio de cada producto. Luego, el programa calcula y muestra el precio total 
del inventario en cada sucursal, el precio promedio de los productos en cada sucursal, el producto más caro y más barato en cada sucursal,
y el total de unidades vendidas por producto en cada sucursal. Además, permite buscar un producto por su nombre y mostrar su precio y 
cantidad en cada sucursal.
*/

#include <stdio.h>
#include <string.h>
#include "funciones.h"

char nombresucursal[50]; //variable para el nombre de la sucursal
char nombreproducto[50]; //variable para el nombre del producto
int cantidadproducto; // variable para la cantidad del producto
float precioproducto; // precio del producto
float preciototal; //precio total de una sucursal
float preciototalporsucursal[3]; // vector con los precios totales por sucursal
float preciopromediosucursal[3];// vector para calcular el precio promedio por sucursal
// Cambiamos el nombre de la matriz para que guarde los NOMBRES de los productos por sucursal
int numero_productos[3]; // variable para el número de productos por sucursal
char sucursalnombre[3][50]; // vector con 3 columnas (las sucursales) para los nombres de las sucrusales
char nombreproductoporsucursal[3][10][50];// matriz con 3 columnas y 10 filas para representar los productos de cada sucursal y guardar el nombre de cada producto por sucursal
int cantidadproductos[3][10]; // matriz con 3 columnas que representan las sucursales y 10 filas para la cantidad de cada producto por sucursal
float precioproductos[3][10]; // matriz con 3 columnas y 10 filas donde se guardara el precio de cada producto


int main() {
    int opcion; // variable para la opción del menú
    int datosIngresados = 0; // Variable para verificar si los datos han sido ingresados

    do
    {
        printf("\nMenu:\n 1. Ingresar datos de las sucursales\n 2. Mostrar resultados\n 3. Buscar producto\n 4. Salir\n Seleccione una opcion: ");
        scanf("%d", &opcion);
        LimpiarBuffer(); // Función para limpiar el buffer después de leer la opción para evitar que el siguiente fgets se salte

        switch (opcion) {
            case 1:
                // Para ingresar datos de las sucursales
                for (int i = 0; i < 3; i++) { // BUCLE PARA TOMAR LOS DATOS DE LAS SUCURSALES
                    printf("\nIndica el nombre de la Sucursal %d: ", i+1);
                    ValidarTexto(nombresucursal, 50);
                    NombrarSucursal(sucursalnombre, nombresucursal, i);

                    preciototal = 0; // se reinicia el valor de precio total cada vez que vamos a una nueva sucursal

                    printf("Indica el numero de productos (maximo 10) en la sucursal %s: ", nombresucursal); // Le pedimos al usuario el número de productos por sucursal
                    ValidarCantidad(&numero_productos[i]); // Para validar que el número de productos sea positivo
                    while (numero_productos[i] > 10 || numero_productos[i] <= 0) { // Para validar que el número de productos no sea mayor a 10 ni menor o igual a 0
                        printf("El numero de productos no puede ser mayor a 10 ni negativo. Por favor, ingrese un número valido: ");
                        ValidarCantidad(&numero_productos[i]);
                    }

                    LimpiarBuffer(); // Función para limpiar el buffer después de leer la opción para evitar que el siguiente fgets se salte

                    for (int j = 0; j < numero_productos[i]; j++) { // BUCLE PARA TOMAR LOS DATOS DE LOS PRODUCTOS DE LAS SUCURSALES Y LOS PRECIOS
                        printf("Indica el nombre del producto %d para la sucursal %s: ", j+1, nombresucursal);
                        ValidarTexto(nombreproducto, 50); // Llamada a función para validar que el nombre del producto no esté vacío ni tenga caracteres no permitidos

                        printf("Indica la cantidad de producto disponible de %s: ", nombreproducto);
                        ValidarCantidad(&cantidadproducto); // Llamada a función para validar que la cantidad sea un número entero y positivo

                        printf("Indica el precio del producto %s: ", nombreproducto);
                        ValidarPrecio(&precioproducto); // Llamada a función para validar que el precio sea un número flotante y positivo

                        preciototal += precioproducto * cantidadproducto; // Se acumula el precio total de la sucursal multiplicando el precio por la cantidad de cada producto
            
                        LimpiarBuffer(); // Función para limpiar el buffer después de leer la opción para evitar que el siguiente fgets se salte

                        // Llamada a funciones dentro del bucle para guardar los datos en las matrices
                        NombreProducto(nombreproductoporsucursal,nombreproducto, i, j);
                        cantidad(cantidadproductos, cantidadproducto, i, j);
                        PrecioProdu(precioproductos, precioproducto, i, j);
                    }
                    // Llamada a funciones para calcular el precio total y el precio promedio por sucursal
                    CalcularPrecioTotal(preciototalporsucursal,preciototal,i);
                    CalcularPrecioPromedio(preciopromediosucursal, preciototal,i, numero_productos[i]);
                }
                datosIngresados = 1;
                break;

            case 2:
                // Para mostrar resultados
                if (!datosIngresados) { // Para verificar si los datos han sido ingresados antes de mostrar los resultados
                    printf("No se han ingresado los datos de las sucursales. Por favor, ingrese los datos primero.\n");
                    break; // Se sale del case para que el usuario pueda ingresar los datos
                }

                printf("\nResultados:\n");
                for (int i = 0; i < 3; i++) { // BUCLE PARA MOSTRAR LOS RESULTADOS DE CADA SUCURSAL
                printf("\nSucursal: %s\n", sucursalnombre[i]);
                printf("Precio total del inventario en la sucursal: %.2f\n", preciototalporsucursal[i]);
                printf("Precio promedio de todos los productos en la sucursal: %.2f\n", preciopromediosucursal[i]);
                }

                // Llamada a las funciones para mostrar el producto más caro y más barato y el total de unidades vendidas
                EncontrarMayorMenor(precioproductos, nombreproductoporsucursal, sucursalnombre, numero_productos);
                MostrarTotalUnidades(cantidadproductos, sucursalnombre, numero_productos);

                break;
            case 3:
                // Para buscar un producto por su nombre y mostrar su precio y cantidad en cada sucursal
                if (!datosIngresados) { // Para verificar si los datos han sido ingresados antes de permitir la búsqueda de productos
                    printf("No se han ingresado los datos de las sucursales. Por favor, ingrese los datos primero.\n");
                    break; // Se sale del case para que el usuario pueda ingresar los datos
                }

                BuscarProducto(nombreproductoporsucursal, precioproductos, cantidadproductos, sucursalnombre, numero_productos);
                break;
            case 4:
                printf("Salió del programa...\n");
                break;

            default:
                printf("Opcion no valida. Por favor, seleccione una opcion valida.\n");
        }
    } while (opcion != 4);

    return 0;
}