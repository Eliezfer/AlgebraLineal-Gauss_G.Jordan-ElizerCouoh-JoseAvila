#include <stdio.h>
#include <stdlib.h>

double** definirMatriz(int, int);
void lecturaDatos(double**,int,int, FILE* );
int verificar0 (double **p, int n, int columna, int fila);
void verificar1 (double **p, int n, int columna,int fila);
void cambioFila(double **p,int fila1, int fila2, int NoCol);
void GaussJordan(double **p,int fila, int columna);

int main(int argc, char *argv[]) {
	
	double **p;
	int filas, columnas, nMatrices, i=0;
	FILE* fichero=fopen("input2.txt", "rt");
	FILE* output = fopen("output2.txt", "w");
	if(fichero == NULL){
		printf("Error en la apertura del archivo");
	}
	fscanf(fichero, "%d", &nMatrices); //lee la cantidad de matrices en el archivo//
	while(i<nMatrices){
		fscanf(fichero, "%d %d", &filas, &columnas); //lee las ilas y columnas para enviar a las funciones
		
		p = definirMatriz(filas, (columnas+1));
		
		lecturaDatos(p,filas,(columnas+1), fichero);
		
		GaussJordan(p,filas,(columnas+1));
		
		for(int m = 0; m < filas; m++){ //guardo los datos de la matriz en el archivo output//
			for(int n = 0; n < (columnas+1); n++){
				fprintf(output,"%.3lf ",p[m][n]);
			}
			fprintf(output,"\n");
		}
		fprintf(output,"\n");
		for (int m=0; m<filas; m++)
			free (p[m]);
		free(p);
		i++;
	}
	fclose(fichero);
	fclose(output);
	
	return 0;
}

double** definirMatriz(int filas, int columnas) /**se define la matriz dinamica**/
{
	double **matriz;
	int i;
	matriz=(double**)malloc(filas*sizeof(double*));
	for(i=0;i<filas;i++)
	{
		matriz[i]=(double*)malloc(columnas*sizeof(double));
	}
	return matriz;
}

void lecturaDatos(double** p, int filas, int columnas,FILE* fichero) /**le los datos del archivo txt**/
{
	int i,j;
	for(i=0;i<filas;i++){
		for (j = 0; j<columnas; j++){
			fscanf(fichero,"%lf",&p[i][j]);
		}
	}
}

int verificar0 (double **p, int n, int columna, int fila) /**verifica que el pivote no haya cero si es 
	así se cambia las de filas en el primer numero diferente de cero que encuentre en la columna**/
{
	int b=0;
	for(int i=(n+1);i<fila;i++){
		
		if ((p[n][n]!=0)|| (n==fila)){
			b=1;
			break;
		}
		else if (p[i][n]!=0){
			cambioFila(p,n,i, columna);
			b=1;
		}		
	}
	return b;
}
void verificar1 (double **p, int n, int columna,int fila) /**verifica si en la columna del pibote hay algun 1 que 
	favoresca el procedimiento para la forma escalonada y hace un cambio de filas si se encuentra**/
{
	for(int i=(n+1);i<fila;i++){
		
		if ((p[n][n]==1) || (n==fila)){
			break;
		}
		else if (p[i][n]==1){
			cambioFila(p,n,i, columna);
		}
	}
}

void cambioFila(double **p,int fila1, int fila2, int NoCol)/**cambia de filas la matriz cuando se necesite
	ya sea para la funcion verificar0 o verificar1**/
{
	int aux=0;
	for(int columna=0 ;columna<NoCol;columna++){
		aux=p[fila1][columna];
		p[fila1][columna]=p[fila2][columna];
		p[fila2][columna]=aux;
	}
	
}
void GaussJordan(double **p,int fila, int columna)/**procedimiento de gauss jordan**/
{
	int x=0;
	double Aux, C, A, B;

	for(int i=0;i<fila;i++ ){
		
		while(x==0){   //veirifica el 0 y 1 en los pivotes// 
			verificar1(p,i,columna,fila);	
			x=verificar0(p, i, columna,fila);//si no se encuentra cero se cambia de fila y se toma el otro pivote para verificar//
			if(x==0){
				i++;
			}
		}
		if(p[i][i]==0){
			break;
		}
		A=p[i][i]; 
			for(int j=0; j<columna; j++){  //convierte el pivote en 1//
				Aux=p[i][j]/A;
				p[i][j]=Aux;
			}
			for(int n=0;n<fila;n++){ //convierte en cero los demas elementos de la columna del pivote pivote//
				if(n!=i){
					B=p[n][i];
					C=(B)*(-1);
					for(int j=0; j<columna; j++){
						Aux=C*p[i][j]+p[n][j];
						p[n][j]=Aux;
					}
				}
			}
	}
}
