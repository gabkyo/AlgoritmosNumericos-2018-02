#include <stdio.h>
#include <stdlib.h>
#include "seidel.h"
#include <math.h>

#define tol 0.0000000001

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

    //VALORES INICIAIS
    for (int i= 0; i < n; i++) {
        xSeidel[i] = b[i]/matriz[i][i];
        *cS += 1;
        xA[i] = 1;
    }
    
    //ITERACOES
    while(true) {
        for (int i = 0; i < n; i++) {
            soma = 0;
            for (int j = i-2; j <= i+2; j++) {
                if(i!=j && j>=0){
                    soma += matriz[i][j]*xSeidel[j];
                    *cS+=2;
                }
            }
            xSeidel[i] = (b[i]-soma) / matriz[i][i];
            *cS += 2;             
        }
       

        //CONFERE SE ACABOU ATRAVES DA TOLERANCIA
        contador = 1;
        for(int i = 0; i < n ; i++) {
            if(terminar(xSeidel[i], xA[i])){
                contador++;
            }else{
                break;
            }     
            if(contador == n){//TRUE = ACABOU
                free(xA);
                return;
            } 
        } 
        
        //ATUALIZA X-ANTIGO
        for(int i = 0; i < n ; i++){
            xA[i] = xSeidel[i];
        }
        
    }
}