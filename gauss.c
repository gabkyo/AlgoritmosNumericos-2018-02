#include <stdio.h>
#include <stdlib.h>
#include "gauss.h"
#include "organizacao.h"


void pivotear(double **matriz, int j,int n){
    double temp,max=matriz[j][j];
    int k=j;
    for (int i = j+1; i < i+3 && i<n; ++i) {
            if (matriz[i][j]>max) {
                    max=matriz[i][j];
                    k=j;
            }
    }
    if (k!=j) {
            for (int i = j; i < j+5 && i<n; ++i) {
                    temp=matriz[j][i]; matriz[j][i]=matriz[j][k]; matriz[j][k]=temp;
            }
    }
}

void triangularizacao(int n, double **matriz, double *b, int *cG, int *cS){
    *cG = *cS = 0;
    for (int i = 0; i < n; ++i) {
        pivotear(matriz, i,n);
        for (int j = i+1; j<=i+2 && j<n; j++) { //colunas
            double m = (matriz[j][i]/matriz[i][i]);
            for (int k = i; k<n; k++) { //linhas
                if(matriz[j][k] != 0.0){
                    matriz[j][k] -= (matriz[i][k])*m; //OPERACAO EM A
                    *cG = *cS += 2;
                }
            }
            if(b[j]!=0.0 || b[i]!= 0.0){
                b[j] -= b[i]*m; //OPERACAO EM B
                *cG = *cS += 3;
            }else {
                *cG = *cS += 2;
            }
        }
    }
}


void gauss(int n, double **matriz, double *b, double *x, int *cG){
    //SUBSTITUICAO REGRESSIVA
    x[n-1]= b[n-1]/matriz[n-1][n-1];
    *cG += 1;
    double soma;
    for(int i=n-2; i>=0; i--){ 
        soma = b[i];
        for(int j=i+1; j<n; j++){
            if(x[j]!=0.0 && matriz[i][j]!=0.0){
                soma += -matriz[i][j]*x[j];
                *cG += 2;
            }
        }
        x[i]= soma/matriz[i][i];
        *cG += 1;
    }
}


