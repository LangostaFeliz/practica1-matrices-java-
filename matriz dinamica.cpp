#include<stdio.h>
#include<stdlib.h>

struct matriz{
	int renglon;
	int columna;
};
int i,j;
struct matriz M[2];

void asignar_valor(int **m1,struct matriz M); 
void imprimir(int **a,struct matriz M);
void asignar_tamano();
void suma_matriz(int **m1,int **m2,int **m3,struct matriz M);
void resta_matriz(int **m1,int **m2,int **m3,struct matriz M);
void multiplicar_matriz(int **m1,int **m2,int **m3,struct matriz M);
int validacion(struct matriz SIZE1, struct matriz SIZE2,int booleano);
void transpuesta_matriz(int** m1, int** m3, struct matriz M);
void libera_memoria(int** ptM,struct matriz M);

int main(void){
	//pointer que apunta la direcion de la direcion la matriz
	int **m1=NULL;
	int **m2=NULL;
	int **m3=NULL;
	
	
	asignar_tamano();//captura la dimension de los matrices
	
	//asignacion de la memoria para que pueden pasar los matrices con dimension predefinido a parametro. 
	m1 =(int**)malloc(M[0].renglon*sizeof(int*));
	for(i=0; i<M[0].columna;i++)
	m1[i] = (int*)malloc(M[0].columna*sizeof(int));
		
	m2 =(int**)malloc(M[1].renglon*sizeof(int*));	
	for(i=0; i<M[1].columna;i++)
	m2[i] = (int*)malloc(M[1].columna*sizeof(int));
	
	m3 =(int**)malloc(M[1].renglon*sizeof(int*));	
	for(i=0; i<M[1].columna;i++)
	m3[i] = (int*)malloc(M[1].columna*sizeof(int));

	
	asignar_valor(m1,M[0]);        //captura los valores de la matriza con rand.
	printf("Los valor de matriz 1 es: \n");
	imprimir(m1,M[0]);
	
	asignar_valor(m2,M[1]);
	printf("Los valor de matriz 2 es: \n");
	imprimir(m2,M[1]);
	
	printf("El resultado de la matriz transpuesta con el matriz 1 : \n");
	transpuesta_matriz(m1,m3,M[0]);
	imprimir(m3,M[0]);
	
	printf("El resultado de la suma de dos matriz es : Matriz 1 + Matriz 2 = :\n");
	if(	validacion(M[0],M[1],1)==1) {suma_matriz(m1,m2,m3,M[0]);imprimir(m3,M[1]);}
	else printf("No son cuadradas, no se puede realizar la suma \n");
	
	printf("El resultado de la resta de dos matriz es : Matriz 1 - Matriz 2 = :\n");
	if(	validacion(M[0],M[1],1)==1) {resta_matriz(m1,m2,m3,M[0]);imprimir(m3,M[1]);}
	else printf("No son cuadradas, no se puede realizar la resta\n");
	
	printf("El resultado de la multiplicacion de dos matriz es : Matriz 1 * Matriz 2 = :\n");
	if(validacion(M[0],M[1],0)==1)  {multiplicar_matriz(m1,m2,m3,M[0]);imprimir(m3,M[1]);}
	else printf("no se puede multiplicar");
	
	libera_memoria(m1,M[0]);
	libera_memoria(m2,M[1]);
 	libera_memoria(m3,M[1]);

	
	return 0;
}

void asignar_valor(int** m1,struct matriz M){
		for(i = 0;i <M.renglon; i++)
		for(j = 0;j <M.columna; j++)
		m1[i][j] = rand()%10;
}

void imprimir(int **a,struct matriz M)
{	for(i=0;i<M.renglon;i++){ 
		for(j=0;j<M.columna;j++){ 
		printf("%d  ",a[i][j]);} 
		printf("\n") ;
	} 
}
void asignar_tamano(){
	
	//captura el tamano de matriz
	printf("introduce el numero de renglon para matriz 1 : ");
	scanf("%d",&M[0].renglon);
	printf("introduce el numero decolumna para matriz 1 : ");
	scanf("%d",&M[0].columna);
	
	printf("introduce el numero de renglon para matriz 2 : ");
	scanf("%d",&M[1].renglon);
	printf("introduce el numero de columna para matriz 2 : ");
	scanf("%d",&M[1].columna);
}

void suma_matriz(int **m1,int **m2,int **m3,struct matriz M)
{
	for(i=0;i<M.renglon;i++)
		for(j=0;j<M.columna;j++)
		m3[i][j]=m1[i][j]+m2[i][j];
}

void resta_matriz(int **m1,int **m2,int **m3,struct matriz M)
{
	for(i=0;i<M.renglon;i++)
		for(j=0;j<M.columna;j++)
		m3[i][j]=m1[i][j]-m2[i][j];
}



int validacion(struct matriz SIZE1, struct matriz SIZE2,int booleano){
	if(booleano==1) { if((SIZE1.renglon==SIZE2.renglon)&&(SIZE1.columna==SIZE2.columna)) return 1;}
	
	if(booleano==0) { if((SIZE1.renglon==SIZE2.columna)) return 1; }
}

void multiplicar_matriz(int **m1,int **m2,int **m3,struct matriz M){
		int k;
		for(i = 0;i<M.renglon;i++){
		for(j = 0; j<M.columna;j++){
			for(k=0;k<M.renglon;k++){
			m3[i][j]+=m1[i][k] * m2[k][j];
			}
			
		}
	}
}

void transpuesta_matriz(int** m1, int** m3, struct matriz M){
	for(i = 0; i<M.renglon; i++)
		for(j = 0; j< M.columna; j++)
			m3[j][i]=m1[i][j];
}

void libera_memoria(int** ptM,struct matriz M){
	for(i=0;i<M.columna;i++)
	free(ptM[i]);
	free(ptM);
}


