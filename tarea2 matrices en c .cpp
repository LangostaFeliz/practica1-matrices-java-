#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define ren 10
#define col 10
struct matriz{
	int renglon;
	int columna;
}; 
int i,j;
int matriz1[ren][col];
int matriz2[ren][col];
int M_transpuesta[ren][col];
int M_suma[ren][col];
int M_resta[ren][col];
int M_multiplicar[ren][col];
struct matriz matrizInt[2];
void getSIZE();
void IniciarMatriz();
void imprimir_matriz1and2();
void Matriz_Transpuesta();
void suma_matriz();
void resta_matriz();
void multiplicar_matriz();
void getSIZE(){
	printf("introduce el numero de renglon de matriz 1 : ");
	scanf("%d",&matrizInt[0].renglon);
	printf("introduce el numero de columa de matriz 1 : ");
	scanf("%d",&matrizInt[0].columna);
	printf("introduce el numero de renglon de matriz 2 : ");
	scanf("%d",&matrizInt[1].renglon);
	printf("introduce el numero de columa de matriz 2 : ");
	scanf("%d",&matrizInt[1].columna);
}

void IniciarMatriz(){
	
	for( i=0;i<matrizInt[0].renglon;i++){
		for( j=0;j<matrizInt[0].columna;j++)
		matriz1[i][j]=rand()%10;
	}
	for( i=0;i<matrizInt[0].renglon;i++){
		for( j=0;j<matrizInt[0].columna;j++)
		matriz2[i][j]=rand()%10;
	}
}

void imprimir_matriz1and2()
{	
printf("matriz 1 : \n");
	for( i=0;i<matrizInt[0].renglon;i++){{
		for( j=0;j<matrizInt[0].columna;j++)
		printf("%d  ",matriz1[i][j]);
	}printf("\n");}

printf("matriz 2 : \n");	
		for( i=0;i<matrizInt[1].renglon;i++){{
		for( j=0;j<matrizInt[1].columna;j++)
		printf("%d  ",matriz2[i][j]);
	}printf("\n");}
}

void Matriz_Transpuesta(){
	
	printf("Matriz transpuesta de matriz 1 : \n");
	for( i=0;i<matrizInt[1].renglon;i++){
		for( j=0;j<matrizInt[1].columna;j++){
		
		M_transpuesta[j][i]=matriz1[i][j];
	}}
	
	for( i=0;i<matrizInt[1].renglon;i++){{
		for( j=0;j<matrizInt[1].columna;j++){
		
		printf("%d  ",M_transpuesta[i][j]);
	}}printf("\n");}
}

void suma_matriz(){
	
	for(i = 0;i<matrizInt[0].renglon;i++){
		for(j = 0; j<matrizInt[0].columna;j++){
			M_suma[i][j]=matriz1[i][j]+matriz2[i][j];
		}
	}
	
	printf("La suma de matriz 1 y matriz 2 es : \n");
	for( i=0;i<matrizInt[1].renglon;i++){{
		for( j=0;j<matrizInt[1].columna;j++){
		
		printf("%d  ",M_suma[i][j]);
	}}printf("\n");}
	
	
}

void multiplicar_matriz(){
	int k;
	for(i = 0;i<matrizInt[0].renglon;i++){
		for(j = 0; j<matrizInt[0].columna;j++){
			for(k=0;k<matrizInt[0].renglon;k++){
			M_multiplicar[i][j]+=matriz1[i][j]*matriz2[i][j];
			}
			
		}
	}
	
	printf("La multiplicacion de matriz 1 y matriz 2 es : \n");
	for( i=0;i<matrizInt[1].renglon;i++){{
		for( j=0;j<matrizInt[1].columna;j++){
		
		printf("%d  ",M_multiplicar[i][j]);
	}}printf("\n");}
	
	
}

void resta_matriz(){
	
	for(i = 0;i<matrizInt[0].renglon;i++){
		for(j = 0; j<matrizInt[0].columna;j++){
			M_resta[i][j]=matriz1[i][j]-matriz2[i][j];
		}
	}
	
	printf("La resta de matriz 1 y matriz 2 es : \n");
	for( i=0;i<matrizInt[1].renglon;i++){{
		for( j=0;j<matrizInt[1].columna;j++){
		
		printf("%d  ",M_resta[i][j]);
	}}printf("\n");}
	
	
}

int main()
{	
	
	getSIZE();
	IniciarMatriz();
	imprimir_matriz1and2();
	 Matriz_Transpuesta();
	if((matrizInt[0].renglon==matrizInt[1].renglon)&&(matrizInt[0].columna==matrizInt[1].columna)) {
	suma_matriz();resta_matriz();}
	else printf("No son cuadradas, no se puede realizar la suma y la resta");
	if(matrizInt[0].renglon == matrizInt[0].columna) multiplicar_matriz();
	else printf("no son multiplicable");
}

