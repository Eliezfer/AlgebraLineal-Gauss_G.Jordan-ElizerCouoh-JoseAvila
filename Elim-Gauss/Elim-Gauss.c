#include <stdio.h>
#include <stdlib.h>

double** definirMatriz(int, int);
void lecturaDatos(double**,int,int, FILE* );
int verificar0 (double **p, int n, int columna, int fila);
void cambioFila(double **p,int fila1, int fila2, int NoCol);
void Gauss(double **p, int fila, int columna);

int main(int argc, char *argv[]) {
	double **p;
	int filas, columnas;
	FILE* fichero = fopen("input1.txt", "rt");;
	FILE* output = fopen("output1.txt", "w");
	if(fichero == NULL){
		printf("Error en la apertura del archivo");
	}

	fscanf(fichero, "%d %d", &filas, &columnas); //obtine las filas y columnas del archivo .txt para las funciones//
	
	p = definirMatriz(filas, (columnas+1));
	
	lecturaDatos(p,filas,(columnas+1), fichero);
	
	Gauss(p,filas,(columnas+1));
	
	for(int m = 0; m < filas; m++){//se guarda la matriz en el archivo output //
		for(int n = 0; n < (columnas+1); n++){
			fprintf(output,"%.3lf ",p[m][n]);
		}
		fprintf(output,"\n");
	}
	fclose(fichero);
	fclose(output);
	for (int m=0; m<filas; m++)
		free (p[m]);
	free(p);
	
	return 0;
}


double** definirMatriz(int filas, int columnas)  /**se define la matriz dinamica**/
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

void lecturaDatos(double** p, int filas, int columnas,FILE* fichero)/**le los datos del archivo txt**/
{
	int i,j;
	for(i=0;i<filas;i++){
		for (j = 0; j<columnas; j++){
			fscanf(fichero,"%lf",&p[i][j]);
		}
	}
}

int verificar0 (double **p, int n, int columna, int fila)/**verifica que el pivote no haya cero si es 
	así se cambia las de filas en el primer numero diferente de cero que encuentre en la columna devuelve si ubo un cambio o no**/
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

void Gauss(double **p, int fila, int columna)/**procedimiento escalonado Gauss*/
{
	int m,x, d;
	double A,B; 
	double C, Aux;
	for(int n=0; n<(fila);n++){ //verifica los ceros del pivote si debajo de la columna no se encontro cero el pivote se mueve//
		x=verificar0(p,n, columna, fila);
		if(x==1){
			m=n;
			d=(m+1);
		}
		else if (x==0){
			m=n++;
			d=n;
		}
		A=p[m][n];
		for( int i=d; i<fila;i++){ //convierte en cero la columna del pivote
			B=p[i][n];
			C=(B/A)*(-1);
			for(int j=0; j<columna; j++){
				Aux=C*p[m][j]+p[i][j];
				p[i][j]=Aux;
			}
		}
	}	
}

void cambioFila(double **p,int fila1, int fila2, int NoCol)/**cambia de filas la matriz cuando
	se necesite para la funcion verificar0*/
{
	int aux=0;
	for(int columna=0 ;columna<NoCol;columna++){
		aux=p[fila1][columna];
		p[fila1][columna]=p[fila2][columna];
		p[fila2][columna]=aux;
	}
}
