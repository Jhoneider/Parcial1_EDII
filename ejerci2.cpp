#include <stdio.h>
#include <stdlib.h>

void pedir_datos();
void imprimir_datos();

int Filas, Columnas, **p_matriz1, **fibo;

int main(){
	pedir_datos();
	imprimir_datos();
	free(p_matriz1);
	free(fibo);
	printf("\n\n");
	system("pause");
	return 0;
}

void pedir_datos(){
	printf("\nIngrese Cantidad de Filas: ");
	scanf("%d", &Filas);
	printf("\nIngrese Cantidad de Columnas: ");
	scanf("%d", &Columnas);
	
	p_matriz1 = (int **)malloc(Filas * sizeof(int *));
	for(int x = 0; x < Columnas; x++){
		p_matriz1[x] = (int *)malloc(Columnas * sizeof(int ));
	}
	
	fibo = (int **)malloc(Filas * sizeof(int *));
	for(int x = 0; x < Columnas; x++){
		fibo[x] = (int *)malloc(Columnas * sizeof(int ));
	}
	
	for(int a=0; a<Filas; a++){
		for(int b=0; b<Columnas; b++){
			int n1=0;
			int n2=0;
			int suma;
			suma=n1+n2;
			n1=n2;
			n2=suma;
			(*(*(fibo+b)+a))=0;
			(*(*(fibo+b)+a)) = ((suma+b)+a);
			(*(*(fibo+0)+0)) = 1;
		}
	}
}

void imprimir_datos(){
	
	printf("\nMatriz Fibonacci\n\n");
	for(int f = 0; f < Filas; f += 1){
		for(int c = 0; c < Columnas; c++){
			printf(" %d ",(*(*(fibo+c)+f)));
		}
		printf("\n");
	}
}
