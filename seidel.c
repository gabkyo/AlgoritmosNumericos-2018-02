#include <stdio.h>
#include <stdlib.h>
#include "seidel.h"
#include <math.h>

#define tol 0.00000000001

bool terminar(double xi, double x0){
    double temp=fabs(xi-x0)/fabs(xi);
    if(temp<=tol){
        return true;
    }
    return false;
}


void seidel(double **matriz, double *b, int n, double *xSeidel, int *cS){
    double *xA=(double*)malloc(sizeof(double)*n);
    double soma;
    int contador;

    //VALOR INICIAL
    for (int i= 0; i < n; i++) {
        xSeidel[i] = b[i]/matriz[i][i];
        xA[i] = 1;
        *cS += 1;
    }
    
    //ITERACOES
    while(true) {
        for (int i = 0; i < n; i++) {
            soma = 0;
            for (int j = 0; j < n; j++) {
                if(i!=j && matriz[i][j]!=0.0 && xSeidel[j]!=0.0){
                    soma += matriz[i][j]*xSeidel[j];
                    *cS+=2;
                }
            }
            if(soma!=0.0){
                xSeidel[i] = (b[i] - soma) / matriz[i][i];
                *cS += 2;
            }else{
                xSeidel[i] = b[i] / matriz[i][i];
                *cS += 1;
            }
        }
       

        //CONFERE SE ACABOU E ATUALIZA X-ANTIGO
        contador = 1;
        for(int i = 0; i < n ; i++) {
            if(!terminar(xSeidel[i], xA[i])){
                break;
            }else{
                contador++;
                printf("\n\n CONTADORSS: %d\n", contador);
            }     
            if(contador == n){//TRUE = ACABOU
                free(xA);
                return;
            } 
            xA[i] = xSeidel[i];
        } 
    }
}