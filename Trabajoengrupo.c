/*
Autores: Nicolas Menendez, Joel Cruz y Suri Arias
Fecha: 15/04/2026
Descripcion: 
*/

#include <stdio.h>
#include <string.h>
char nombresucursal[50]; //variable para el nombre de la sucursal
char nombreproducto[50]; //variable para el nombre del producto
int cantidadproducto; // "" para la cantidad del producto
float precioproducto; // precio del producto
char sucursalproductos[3][10][50];// matriz con 3 columnas (las sucursals) y 10 filas para los productos y sus respectivos nombres
int cantidadproductos[3][10]; // matriz con 3 columnas que representan las sucurslaes y 10 filas para la cantidad de cada producto por sucursal
float precioproductos[3][10];// matriz con 3 columnas y 10 filas donde se guardara el precio de cada producto
//funcion para asignar nombre a la sucursal
void NombrarSucursal(char nombres[3][10][50], char name[50], int sucursal, int producto){
    strcpy(nombres[sucursal][producto], name);
}
// funcion para definir la cantidad de producto por sucursal
void cantidad(int cantidadesproducto[3][10], int cantidadprodu, int sucursal, int producto){
    cantidadesproducto[sucursal][producto] = cantidadprodu;
}    
// funcion para poner el precio de cada producto
void PrecioProdu(float precios[3][10], float price, int sucursal, int producto){
    precios[sucursal][producto] = price;
}  

int main() {
    for (int i = 0; i < 3; i++) { //BUCLE PARA TOMAR LOS DATOS DE LAS SUCURSALES
        printf("Indica el nombre de la Sucursal %d", i);
        fgets(nombresucursal,50, stdin);
        for (int j = 0; j < 4; j++) { // BUCLE PRA TOMAR LOS DATOS DE LOS PRODUCTOS DE LAS SUCURSALES Y LOS PRECIOS DE LOS PRODCUTOS
            printf("Indica el nombre del producto %d para la sucursal %s", j, nombresucursal);
            fgets(nombreproducto,50,stdin);
            printf("Indica la cantidad de producto disponible de %s ",nombreproducto);
            scanf("%d",&cantidadproducto);
            printf("Indica el precio del producto %s", nombreproducto);
            scanf("%f",&precioproducto);
            //utilizacion de funciones luego del bucle para guardar los datos
            NombrarSucursal(sucursalproductos,nombresucursal,i,j);
            cantidad(cantidadproductos,cantidadproducto,i,j);
            PrecioProdu(precioproductos,precioproducto,i,j);
        }

    }
    printf("Try programiz.pro");

    return 0;
}
