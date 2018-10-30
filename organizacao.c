#include <stdio.h>
#include <stdlib.h>
#include "organizacao.h"

void pegarValores(int *n, double *dA, double *dB, double *Dp, double *dC, double *dD){

    while (1){
        printf("Insira Dimensao n(>=3):\n");
        fflush(stdout);
        scanf("%d", n);
        if (*n < 3){
            printf("Valor Invalido! n= %d\n", *n);
            fflush(stdout);
        }
        else{
            break;
        }
    }

    while (1){
        printf("Insira dA(!=0): \n");
        fflush(stdout);
        scanf("%lf", dA);
        if (*dA == 0.0){
            printf("Valor Invalido! dA= 0.\n");
            fflush(stdout);
        }
        else{
            break;
        }
    }

    while (1){
        printf("Insira dB(!=0): \n");
        fflush(stdout);
        scanf("%lf", dB);
        if (*dB == 0.0){
            printf("Valor Invalido! dB= 0.\n");
            fflush(stdout);
        }
        else{
            break;
        }
    }

    while (1){
        printf("Insira dC(!=0): \n");
        fflush(stdout);
        scanf("%lf", dC);
        if (*dC == 0.0){
            printf("Valor Invalido! dC= 0.\n");
            fflush(stdout);
        }
        else{
            break;
        }
    }

    while (1){
        printf("Insira dD(!=0): \n");
        fflush(stdout);
        scanf("%lf", dD);
        if (*dD == 0.0){
            printf("Valor Invalido! dD= 0.\n");
            fflush(stdout);
        }
        else{
            break;
        }
    }

    while (1){
        printf("Insira Dp(!=0): \n");
        fflush(stdout);
        scanf("%lf", Dp);
        if (*Dp == 0.0){
            printf("Valor Invalido! Dp= 0.\n");
            fflush(stdout);
        }
        else{
            break;
        }
    }
}


void prepararSistemaLinear(int n, double dA, double dB, double Dp, double dC, double dD, double ***matriz, double **b){
        *b=(double*)malloc(sizeof(double) * n);
        double **matrizAux, *bAux;
        matrizAux = (double**)malloc(sizeof(double*) *n);
        bAux = *b;
        
    	for (int i = 0; i < n; ++i) { //ALOCAR E PREENCHER MATRIZ 
		matrizAux[i]=(double*)malloc(sizeof(double)*n);
		for (int j = 0; j < n; ++j) {
			if(i-j==2){
				matrizAux[i][j]=dA;
			}else if (i-j==1) {
				matrizAux[i][j]=dB;
			}else if (i==j) {
				matrizAux[i][j]=Dp;
			}else if (i-j==-2) {
				matrizAux[i][j]=dD;
			}else if (i-j==-1) {
				matrizAux[i][j]=dC;
			}else{
				matrizAux[i][j]=0;
			}
		}
	}
        *matriz = matrizAux;
        
        int soma;
        for(int i=0; i<n; i++){
            soma = 0;
            for(int j=0; j<n; j++){
                soma += matrizAux[i][j];
            }
            bAux[i] = soma;
        }
}

void liberarTudo(int n, double ***matriz, double **b){
    double **matrizAux;
    matrizAux = *matriz;
    	for (int i = 0; i < n; ++i) { //MOSTRAR MATRIZ
            free(matrizAux[i]);
	}
    free(*b);
    free(matrizAux);
    
    *matriz = NULL;
    *b = NULL; 
}
    
            
            
    