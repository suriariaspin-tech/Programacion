#ifndef FUNCIONES_H
#define FUNCIONES_H

void NombrarSucursal(char nombres[3][50], char name[50], int sucursal);
void NombreProducto(char productos[3][10][50], char name[50], int sucursal, int producto);
void cantidad(int cantidadesproducto[3][10], int cantidadprodu, int sucursal, int producto);
void PrecioProdu(float precios[3][10], float price, int sucursal, int producto);
void CalcularPrecioTotal(float precioporsucursal[3], float preciototal, int sucursal);
void CalcularPrecioPromedio(float promediosucursal[3], float precio, int sucursal, int numero_productos);
void LimpiarBuffer();
void EncontrarMayorMenor(float precios[3][10], char productos[3][10][50], char sucursales[3][50], int numero_productos[3]);
void MostrarTotalUnidades(int cantidades[3][10], char sucursales[3][50], int numero_productos[3]);
void BuscarProducto(char productos[3][10][50], float precios[3][10], int cantidades[3][10], char sucursales[3][50], int numero_productos[3]);
void ValidarCantidad(int *cantidad);
void ValidarPrecio(float *precio);
void ValidarTexto(char texto[], int tamaño);
int TextoValido(char texto[]);
#endif