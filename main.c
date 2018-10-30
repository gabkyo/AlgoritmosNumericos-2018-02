#include <stdio.h>
#include <stdlib.h>
#include "gauss.h"

int operacoes = 0; //numero de operacoes realizadas

//i linha j coluna

void pegaValores(int *n, double *dA, double *dB, double *dC, double *dD, double *Dp){
    *n = 0;
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

int main(int argc, char const *argv[])
{
    int *n;
    double *dA, *dB, *dC, *dD, *Dp;

    n = (int*) malloc(sizeof (int));
    dA = (double*) malloc(sizeof (double));
    dB = (double*) malloc(sizeof (double));
    dC = (double*) malloc(sizeof (double));
    dD = (double*) malloc(sizeof (double));
    Dp = (double*) malloc(sizeof (double));


    pegaValores(n, dA, dB, dC, dD, Dp);

    printf("\n\nn= %d. \ndA= %lf. \ndB= %lf. \ndC= %lf. \ndD= %lf. \nDp= %lf.\n", *n, *dA, *dB, *dC, *dD, *Dp);
    fflush(stdout);
    eliminacao(*dA, *dB, *Dp, *dC, *dD, *n);
    free(n);
    free(dA);
    free(dB);
    free(dC);
    free(dD);
    free(Dp);
    return 0;
}
