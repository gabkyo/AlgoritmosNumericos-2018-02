#include <stdio.h>
#include <stdlib.h>
#include "seidel.h"
#include <math.h>

#define tol 0.00000000001

bool terminar(double xi,double x0){
    double temp=fabs(xi-x0)/fabs(xi);
    if(temp<=tol){
        return true;
    }
    return false;
}


void seidel(double **matriz,double *b,int n, int *cs){
    double *x=(double*)malloc(sizeof(double)*n);
    double *xA=(double*)malloc(sizeof(double)*n);
    double soma;
    int contador;

    //VALOR INICIAL
    for (int i= 0; i < n; i++) {
        x[i] = b[i]/matriz[i][i];
        xA[i] = 1;
        *cs += 1;
    }
    
    //ITERACOES
    while(true) {
        for (int i = 0; i < n; i++) {
            soma = 0;
            for (int j = 0; j < n; j++) {
                if(i!=j){
                    soma += matriz[i][j]*xA[j];
                    *cs+=2;
                }
            }
            x[i] = (b[i] - soma) / matriz[i][i];
            *cs += 2;
        }
       

        //CONFERE SE ACABOU E ATUALIZA X-ANTIGO
        contador = 1;
        for(int i = 0; i < n ; i++) {
            if(!terminar(x[i], xA[i])){
                break;
            }else{
                contador++;
            }     
            if(contador == n){//TRUE = ACABOU
                printf("\n\n");
                for (int j = 0; j < n; j++) {
                        printf("%.2lf\n",x[j]);
                        fflush(stdout);
                }
                free(x);
                free(xA);
                return;
            } 
            xA[i]=x[i];
        } 
    }
}