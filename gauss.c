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

void triangularizacao(int n, double **matriz, double *b, int *ce, int *cs){
    *ce = *cs = 0;
    for (int i = 0; i < n; ++i) { 
        pivotear(matriz, i,n);          
        printf("%d\n",i);
        fflush(stdout);
        for (int j = i+1; j<=i+2 && j<n; j++) { //colunas
            double m = (matriz[j][i]/matriz[i][i]);
            for (int k = i; k<n; k++) { //linhas
                matriz[j][k] -= (matriz[i][k])*m; //OPERACAO EM A
                *ce = *cs += 2; //CONTAGEM DE OPERACOES EM A
            }
            b[j] -= b[i]*m; //OPERACAO EM B
            *ce = *cs += 2; // CONTAGENS OPERACOES EM B
        }
    }
}

void eliminacao(int n, double **matriz, double *b, double *x, int *ce){
    //SUBSTITUICAO REGRESSIVA
    x[n-1]= b[n-1]/matriz[n-1][n-1]; 
    double soma;
    for(int i=n-2; i>=0; i--){ 
        soma = b[i];
        for(int j=i+1; j<n; j++){
            soma = soma - matriz[i][j]*x[j];
            *ce += 2; 
        }
        x[i]= soma/matriz[i][i];
    }

    mostrarMatriz(n, matriz, b);
    
    //MOSTRAR X
    for (int i = 0; i < n; ++i) { 
            printf("%.2lf\n",x[i]);
    } 
}

void gaussSeidel(int n, double **matriz, double *b, double *x, int *cs){
    cs = 0;
}
