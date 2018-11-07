#include <stdio.h>
#include <stdlib.h>
#include "gauss.h"
#include "organizacao.h"


void pivotear(double **matriz, double *b, int j, int n){
    int max;
    double aux;
    
    max=j;
    for(int i=j; i<=j+2 && i<n; i++){
        if(matriz[i][j] > matriz[max][j]) {
            max=i;
        }       
    }
    if(max != j){
        for(int x=j; x<n; x++) {
            aux=matriz[max][x]; matriz[max][x]=matriz[j][x]; matriz[j][x]=aux;      
        }
        aux=b[max]; b[max]=b[j]; b[j]=aux;
    }
}

void triangularizacao(int n, double **matriz, double *b, int *cG){
    *cG = 0;
    double m =0 ;
  
    for (int i = 0; i < n; ++i) { 
        pivotear(matriz, b, i, n); 
        //mostrarMatriz(n, matriz, b);
        for (int j = i+1; j<=i+2 && j<n; j++) { //colunas
            m = matriz[j][i]/matriz[i][i];
            *cG += 1;
            
            for (int k = i; k<=i+4 && k<n; k++) { //linhas
                matriz[j][k] -= (matriz[i][k])*m; //OPERACAO EM A
                *cG += 2;
            }
            
            b[j] -= b[i]*m; //OPERACAO EM B
            *cG += 2;
        }
    }
}

void gauss(int n, double **matriz, double *b, double *xGauss, int *cG){
    //TRIANGULARIZACAO
    triangularizacao(n, matriz, b, cG);
    
    
    //SUBSTITUICAO REGRESSIVA
    xGauss[n-1]= b[n-1]/matriz[n-1][n-1]; //CALCULO XN
    *cG += 1;

    double soma;
    for(int i=n-2; i>=0; i--){ 
        soma = b[i];
        for(int j=i+1; j<=i+4 && j<n; j++){         
            soma -= matriz[i][j]*xGauss[j];
            *cG += 2; 
        }
        xGauss[i] = soma/matriz[i][i];
            *cG += 1;

    }
}