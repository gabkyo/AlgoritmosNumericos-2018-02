#include <stdio.h>
#include <stdlib.h>
#include "gauss.h"


void pivotear(double **matriz, int j,int n){
	double temp,max=matriz[j][j];
	int k=j;
	for (int i = i+1; i < i+3 && i<n; ++i) {
		if (matriz[i][j]>max) {
			max=matriz[i][j];
			k=j;
			//operacao+1
		}
	}
	if (k!=j) {
		for (int i = j; i < j+5 && i<n; ++i) {
			temp=matriz[j][i]; matriz[j][i]=matriz[j][k]; matriz[j][k]=temp;
			//operacao+1
		}
	}
	printf("ok\n");
	fflush(stdout);

}



void eliminacao(int n, double **matriz, double *b){
    int k;
	for (int i = 0; i < n; ++i) { //MOSTRAR MATRIZ
		for (int j = 0; j < n; ++j) {
			printf("%.2lf ",matriz[i][j]);
                        fflush(stdout);
		}
		printf("  %lf\n", *b);
                fflush(stdout);
	}
	printf("ok\n");
	fflush(stdout);
        
        
	for (int i = 0; i < n; ++i) { //METODO DE GAUSS
		pivotear(matriz, i,n);          
		printf("%d\n",i);
		fflush(stdout);
		for (int j = i+1; j<=i+2 && j<n; j++) { //colunas
                    double m = (matriz[j][i]/matriz[i][i]);
			for (int k = i; k<n; k++) { //linhas
				matriz[j][k] -= (matriz[i][k])*m;
				//Akj=Akj-Aki*Aij/Aii
				//operacao+2
			}  
		}
	}
        
	printf("ok\n");
	fflush(stdout);
	for (int i = n-1; i >=0; --i) { //SOLUCIONAR PARA B
		b[i]=matriz[i][i];
		for (int j = i+1; j < i+5 && j<n; ++j) {
			if (matriz[j][i]!=0) {
				b[i]-=matriz[j][i]*b[j];
				//operacao+1
			}
		}
	}
	printf("ok\n");
	fflush(stdout);
        
	for (int i = 0; i < n; ++i) { //MOSTRAR MATRIZ
		for (int j = 0; j < n; ++j) {
			printf("%.2lf ",matriz[i][j]);
		}
		printf("\n");
	}
	printf("ok\n");
	fflush(stdout);
        
        
	for (int i = 0; i < n; ++i) { //MOSTRAR b
		printf("%.2lf\n",b[i]);
	}
        
}