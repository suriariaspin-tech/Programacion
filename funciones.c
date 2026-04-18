#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"


// funcion para asignar nombre a cada sucursal
void NombrarSucursal(char nombres[3][50], char name[50], int sucursal){
    strcpy(nombres[sucursal], name); // Copia el nombre de la sucursal al vector de nombres de sucursales
}

// funcion para asignar nombre al producto dentro de la sucrusal
void NombreProducto(char productos[3][10][50], char name[50], int sucursal, int producto){
    strcpy(productos[sucursal][producto], name); // Copia el nombre del producto al vector de nombres de productos por sucursal
}

// funcion para definir la cantidad de producto por sucursal
void cantidad(int cantidadesproducto[3][10], int cantidadprodu, int sucursal, int producto){
    cantidadesproducto[sucursal][producto] = cantidadprodu; // Coloca la cantidad del producto a la matriz de cantidades por sucursal
}

// funcion para poner el precio de cada producto
void PrecioProdu(float precios[3][10], float price, int sucursal, int producto){
    precios[sucursal][producto] = price; // Coloca el precio del producto a la matriz de precios por sucursal
}

// funcion para calcular precio total de cada sucursal
void CalcularPrecioTotal(float precioporsucursal[3], float preciototal, int sucursal){
    precioporsucursal[sucursal] = preciototal; // Coloca el precio total de la sucursal a la matriz de precios totales por sucursal
}

// funcion para calcular precio promedio de cada sucursal
void CalcularPrecioPromedio(float promediosucursal[3], float precio, int sucursal, int numero_productos){
    promediosucursal[sucursal] = precio/numero_productos; // Calcula el precio promedio dividiendo el precio total entre el número de productos de la sucursal
}

// funcion para limpiar el buffer después de usar scanf y evitar que el siguiente fgets se salte
void LimpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n') { } // Limpia el buffer hasta encontrar un salto de línea
}

// funcion para encontrar el producto más caro y más barato de cada sucursal
void EncontrarMayorMenor(float precios[3][10], char productos[3][10][50], char sucursales[3][50], int numero_productos[3]) {
    for (int i = 0; i < 3; i++) {
        if (numero_productos[i] == 0) {
            printf("\nLa sucursal %s no tiene productos\n", sucursales[i]);
            continue;
        }
        float mayor = precios[i][0]; // variable para guardar el precio del producto más caro
        float menor = precios[i][0]; // variable para guardar el precio del producto más barato
        int indiceMayor = 0, indiceMenor = 0; // variables para guardar el índice del producto más caro y más barato

        for (int j = 1; j < numero_productos[i]; j++) { //BUCLE para comparar los precios de cada producto en la sucursal y encontrar el mayor y menor
            if (precios[i][j] > mayor) {
                mayor = precios[i][j];
                indiceMayor = j;
            }
            if (precios[i][j] < menor) {
                menor = precios[i][j];
                indiceMenor = j;
            }
        }

        printf("\nProducto mas caro en la sucursal %s: %s - Precio: %.2f\n", sucursales[i], productos[i][indiceMayor], mayor);
        printf("Producto mas barato en la sucursal %s: %s - Precio: %.2f\n", sucursales[i], productos[i][indiceMenor], menor);
    }
}
// funcion para mostrar el total de unidades vendidas por cada sucursal
void MostrarTotalUnidades(int cantidades[3][10], char sucursales[3][50], int numero_productos[3]) {
    for (int i = 0; i < 3; i++) { // BUCLE para calcular el total de unidades vendidas en cada sucursal sumando las cantidades de cada producto
        int totalUnidades = 0;
        for (int j = 0; j < numero_productos[i]; j++) {
            totalUnidades += cantidades[i][j];
        }
        printf("\nTotal de unidades vendidas en la sucursal %s: %d\n", sucursales[i], totalUnidades);
    }
}
// función para buscar un producto por su nombre y mostrar su precio y cantidad en cada sucursal
void BuscarProducto(char productos[3][10][50], float precios[3][10], int cantidades[3][10], char sucursales[3][50], int numero_productos[3]) {
    char buscar[50]; // variable para guardar el nombre del producto a buscar
    printf("\nIngrese el nombre del producto que desea buscar: ");
    ValidarTexto(buscar, 50); // Para verificar que el texto no esté vacío y no contenga caracteres no permitidos 

    int encontrado = 0; // Variable para indicar si el producto fue encontrado

    printf("\nResultados de la búsqueda para el producto '%s':\n", buscar);
    for (int i = 0; i < 3; i++) { // BUCLE para buscar el producto en cada sucursal comparando el nombre del producto con el nombre a buscar
        for (int j = 0; j < numero_productos[i]; j++) {
            if (strcmp(productos[i][j], buscar) == 0) {
                printf("Producto encontrado en la Sucursal: %s - Precio: %.2f - Cantidad: %d\n", sucursales[i], precios[i][j], cantidades[i][j]);
                encontrado = 1;
            }
        }
    }
    if (!encontrado) {
        printf("Producto no encontrado.\n"); // Mensaje si el producto no se encuentra en ninguna sucursal
    }
}
// función para validar los valores ingresados sea un número entero y positivo para cantidad
void ValidarCantidad(int *cantidad) {
    while (scanf("%d", cantidad) != 1 || *cantidad < 0) { // BUCCLE para validar que la cantidad sea un entero y positivo
        printf("Valor invalido, no puede ingresar numeros negativos: ");
        while (getchar() != '\n'); // Limpiar el buffer de entrada
    }
}
// función para validar que el precio ingresado sea un número flotante y positivo para precio
void ValidarPrecio(float *precio) {
    while (scanf("%f", precio) != 1 || *precio < 0) { // BUCLE para validar que el precio sea un número flotante y positivo
        printf("Valor invalido, no puede ingresar numeros negativos: ");
        while (getchar() != '\n'); // Limpiar el buffer de entrada
    }
}
// fucnión para leer que el texto ingresado y verificar que no sea vacío
void ValidarTexto(char texto[], int tamaño) {
    do
    {
        fgets(texto, tamaño, stdin);
        texto[strcspn(texto, "\n")] = 0; // Limpia el salto de línea
        if (strlen(texto) == 0) { // Validar que el texto no esté vacío
            printf("La entrada no puede estar vacia. Por favor, ingrese un texto valido: ");
        } else if (!TextoValido(texto))
        {
            printf("El nombre no puede contener caracteres especiales. Por favor, ingrese un nombre valido: ");
        }
    } while (strlen(texto) == 0 || !TextoValido(texto)); // BUCLE para validar que el texto no esté vacío y que no contenga caracteres no permitidos
}

// función para validar que el texto ingresado no contenga caracteres no permitidos (solo letras, números y espacios)
int TextoValido(char texto[]) {
    for (int i = 0; texto[i] != '\0'; i++) {
        if (!isalpha(texto[i]) && !isspace(texto[i])) {
            return 0;
        }
    }
    return 1;
}
