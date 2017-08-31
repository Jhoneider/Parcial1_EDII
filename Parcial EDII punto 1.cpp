#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct productos 
{
	int cantidad;
	int precio;
	int importe;
};

struct proveedores 
{
	char nombre[30];
	char telefono[30];
	char direccion[30];
	productos productoproveedor;
}; proveedores proveedor[100];

int main(int argc, char *argv[]) {
	printf("PARCIAL ESTRUCTURA DE DATOS II \n");
	printf("punto 1. \n");
	int contadorproveedor=0;
	int indexado=0;
	char ingresarotroprov='n';
	do{
		contadorproveedor++;
		printf("ingrese el nombre del proveedor %d : ",contadorproveedor);
		fflush(stdin);
		scanf("%s",proveedor[indexado].nombre);
		printf("\n ingrese el telefono del proveedor %d : ",contadorproveedor);
		fflush(stdin);
		scanf("%s",proveedor[indexado].telefono);
		printf("\n ingrese la direccion del proveedor %d : ",contadorproveedor);
		fflush(stdin);
		scanf("%s",proveedor[indexado].direccion);
		printf("\n ingrese la cantidad de productos : ",contadorproveedor);
		fflush(stdin);
		scanf("%d",&proveedor[indexado].productoproveedor.cantidad);
		printf("\n ingrese el precio unitario del producto : ",contadorproveedor);
		fflush(stdin);
		scanf("%d",&proveedor[indexado].productoproveedor.precio);
		proveedor[indexado].productoproveedor.importe = proveedor[indexado].productoproveedor.cantidad * proveedor[indexado].productoproveedor.precio;
		indexado++;
		fflush(stdin);
		printf("\n Desea ingresar otro proveedor? (s). si  (n). no :");
		scanf("%c",&ingresarotroprov);
		
	}while(ingresarotroprov=='s');
	
	//muestra los datos del proveedor y el importe total
	for(int i = 0; i < contadorproveedor;i++){
		printf("PROVEEDOR %d \n",i+1);
		printf("NOMBRE: %s",proveedor[i].nombre);
		printf("\n DIRECCION: %s",proveedor[i].direccion);
		printf("\n TELEFONO: %s",proveedor[i].telefono);
		printf("\n IMPORTE TOTAL: %d",proveedor[i].productoproveedor.importe);
		printf("\n\n");
	}
	
	printf("\n\n");
	//el mas barato
	int masbarato=800000000;
	int posicionmasbarato=0;
	for(int i = 0; i < contadorproveedor;i++){
		if(proveedor[i].productoproveedor.importe<masbarato){
			masbarato=proveedor[i].productoproveedor.importe;
			posicionmasbarato=i;
		}
	}
	printf("EL PROVEEDOR MAS BARATO ES %s ",proveedor[posicionmasbarato].nombre);
	
	int mascaro=0;
	int posicionmascaro=0;
	for(int i = 0; i < contadorproveedor;i++){
		if(proveedor[i].productoproveedor.importe>mascaro){
			mascaro=proveedor[i].productoproveedor.importe;
			posicionmascaro=i;
		}
	}
	printf("\n EL PROVEEDOR MAS CARO ES %s ",proveedor[posicionmascaro].nombre);
	
	printf("\n\n");
	
	//ver total productos
	printf("PRODUCTOS");
	int sumatoria=0;
	for(int i = 0; i < contadorproveedor;i++){
		
		printf("\n PROVEEDOR: %s  CANTIDAD: %d VALOR UNITARIO : %d",proveedor[i].nombre,proveedor[i].productoproveedor.cantidad,proveedor[i].productoproveedor.precio);
		sumatoria+=proveedor[i].productoproveedor.importe;
	}
	printf("\n El costo total es : %d",sumatoria);
	
	
	return 0;
}

