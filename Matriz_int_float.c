#include<stdio.h>
#include<stdlib.h>

struct tipo{
	int **M_int;
	float **M_float;
};

struct matriz{
	int renglon;
	int columna;
	struct tipo M_tipo;
};

//prototipo
//	int
void captura_tamano(struct matriz *M);
void memoria_int(struct matriz *M);
void valida_m3_int(struct matriz m1,struct matriz m2, struct matriz *m3);
void asignar_valor_int(struct matriz M);
void imprimir_int(struct matriz M);
int validacion(struct matriz M1, struct matriz M2,int booleano);
void suma_int(struct matriz m1,struct matriz m2, struct matriz m3);
void resta_int(struct matriz m1,struct matriz m2, struct matriz m3);
void multiplicar_int(struct matriz m1,struct matriz m2, struct matriz m3);
void transpuesta_int(struct matriz m1, struct matriz m3);
// 	float
void memoria_float(struct matriz *M);
void asigna_valor_float(struct matriz M);
void imprimir_float(struct matriz M);
void suma_float(struct matriz m4,struct matriz m5, struct matriz m6);
void resta_float(struct matriz m4,struct matriz m5, struct matriz m6);
void multiplicar_int(struct matriz m1,struct matriz m2, struct matriz m3);
void multiplicar_float(struct matriz m4,struct matriz m5, struct matriz m6);
void transpuesta_float(struct matriz m4, struct matriz m6);

int main(){
	struct matriz m1,m2,m3,m4,m5,m6;
	captura_tamano(&m1);
	captura_tamano(&m2);
	memoria_int(&m1);
	memoria_int(&m2);
	valida_m3_int(m1,m2,&m3);
	memoria_int(&m3);
	asignar_valor_int(m1);
	imprimir_int(m1);
	asignar_valor_int(m2);
	imprimir_int(m2);
	if(validacion(m1,m2,1)==1) {suma_int(m1,m2,m3);imprimir_int(m3);}
	else printf("no se suma");
	if(validacion(m1,m2,1)==1) {resta_int(m1,m2,m3);imprimir_int(m3);}
	else printf("no se resta");
	if(validacion(m1,m2,0)==1) {multiplicar_int(m1,m2,m3);imprimir_int(m3);}
	else printf("no se multiplica");
	transpuesta_int(m1,m3);
	imprimir_int(m3);
	//  matriz con dato float
	captura_tamano(&m4);
	captura_tamano(&m5);
	memoria_float(&m4);
	memoria_float(&m5);
	asigna_valor_float(m4);
	imprimir_float(m4);
	asigna_valor_float(m5);
	imprimir_float(m5);
	valida_m3_int(m4,m5,&m6);
	memoria_float(&m6);
	if(validacion(m4,m5,1)==1) {suma_float(m4,m5,m6);imprimir_float(m6);}
	else printf("no se suma");
	if(validacion(m4,m5,1)==1) {resta_float(m4,m5,m6);imprimir_float(m6);}
	else printf("no se resta");
	if(validacion(m1,m2,0)==1) {multiplicar_float(m4,m5,m6);imprimir_float(m6);}
	else printf("no se multiplica");
	transpuesta_float(m4,m6);
	imprimir_float(m6);
	
	

	
}

void captura_tamano(struct matriz *M){
	scanf("%d",&M->renglon);
	scanf("%d",&M->columna);
}

void memoria_int(struct matriz *M){
	M->M_tipo.M_int= (int**)malloc(M->renglon*sizeof(int*));
	for(int i=0; i<M->columna;i++)
	M->M_tipo.M_int [i] = (int*)malloc(M->columna*sizeof(int));
}

void valida_m3_int(struct matriz m1,struct matriz m2, struct matriz *m3){
	if((m1.renglon>m2.renglon)&&(m1.renglon==m2.renglon)) m3->renglon=m1.renglon;
	else m3->renglon=m2.renglon;
	if((m1.columna>m2.renglon)&&(m1.columna>m2.renglon)) m3->columna=m1.columna;
	else m3->columna=m2.columna;
}
void asignar_valor_int(struct matriz M){
	for(int i=0;i<M.renglon;i++)
		for(int j=0;j<M.columna;j++)
		M.M_tipo.M_int[i][j] = rand()%10;
		
}
void imprimir_int(struct matriz M){
		for(int i=0;i<M.renglon;i++){
		{
		for(int j=0;j<M.columna;j++)
			printf("%d ",M.M_tipo.M_int[i][j]);}
			printf("\n");
}printf("\n");
}

int validacion(struct matriz M1, struct matriz M2,int booleano){
	if(booleano==1) { if((M1.renglon==M2.renglon)&&(M1.columna==M2.columna)) return 1;}
	
	if(booleano==0) { if((M1.renglon==M2.columna)) return 1; }
}

void suma_int(struct matriz m1,struct matriz m2, struct matriz m3){
		for(int i=0;i<m1.renglon;i++)
		for(int j=0;j<m2.columna;j++)
		m3.M_tipo.M_int[i][j]=m1.M_tipo.M_int[i][j]+m2.M_tipo.M_int[i][j];
}

void resta_int(struct matriz m1,struct matriz m2, struct matriz m3){
		for(int i=0;i<m1.renglon;i++)
		for(int j=0;j<m2.columna;j++)
		m3.M_tipo.M_int[i][j]=m1.M_tipo.M_int[i][j]-m2.M_tipo.M_int[i][j];
}

void multiplicar_int(struct matriz m1,struct matriz m2, struct matriz m3){
	
		for(int i = 0;i<m1.renglon;i++){
		for(int j = 0; j<m2.columna;j++){
			for(int k=0;k<m1.renglon;k++){
			m3.M_tipo.M_int[i][j]+=m1.M_tipo.M_int[i][k] * m2.M_tipo.M_int[k][j];
			}
			
		}
	}
}

void transpuesta_int(struct matriz m1, struct matriz m3){
	for(int i = 0; i<m1.renglon; i++)
		for(int j = 0; j<m1.columna; j++)
			m3.M_tipo.M_int[j][i]=m1.M_tipo.M_int[i][j];
}

void memoria_float(struct matriz *M){
	M->M_tipo.M_float= (float**)malloc(M->renglon*sizeof(float*));
	for(int i=0; i<M->columna;i++)
	M->M_tipo.M_float [i] = (float*)malloc(M->columna*sizeof(float));
}

void asigna_valor_float(struct matriz M){
		for(int i=0;i<M.renglon;i++)
		for(int j=0;j<M.columna;j++)
		M.M_tipo.M_float[i][j] = (rand()/(double)(RAND_MAX))*10;
}

void imprimir_float(struct matriz M){
		for(int i=0;i<M.renglon;i++){
		{
		for(int j=0;j<M.columna;j++)
			printf("%f ",M.M_tipo.M_float[i][j]);}
			printf("\n");
}printf("\n");
}

void suma_float(struct matriz m4,struct matriz m5, struct matriz m6){
		for(int i=0;i<m4.renglon;i++)
		for(int j=0;j<m5.columna;j++)
		m6.M_tipo.M_float[i][j]=m4.M_tipo.M_float[i][j]+m5.M_tipo.M_float[i][j];
}

void resta_float(struct matriz m4,struct matriz m5, struct matriz m6){
		for(int i=0;i<m4.renglon;i++)
		for(int j=0;j<m5.columna;j++)
		m6.M_tipo.M_float[i][j]=m4.M_tipo.M_float[i][j]-m5.M_tipo.M_float[i][j];
}

void multiplicar_float(struct matriz m4,struct matriz m5, struct matriz m6){
	
		for(int i = 0;i<m4.renglon;i++){
		for(int j = 0; j<m5.columna;j++){
			for(int k=0;k<m4.renglon;k++){
			m6.M_tipo.M_float[i][j]+=m4.M_tipo.M_float[i][k] * m5.M_tipo.M_float[k][j];
			}
			
		}
	}
}

void transpuesta_float(struct matriz m4, struct matriz m6){
	for(int i = 0; i<m4.renglon; i++)
		for(int j = 0; j<m4.columna; j++)
			m6.M_tipo.M_float[j][i]=m4.M_tipo.M_float[i][j];
}



