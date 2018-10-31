#include <stdio.h>
#include <stdlib.h>
#include "organizacao.h"
#include "gauss.h"
#include "seidel.h"

int operacoes = 0; //numero de operacoes realizadas

int main(int argc, char const *argv[]){
    int n, ce, cs;
    double dA, dB, dC, dD, Dp, **matriz, *b, *x;
    

    pegarValores(&n, &dA, &dB, &Dp, &dC, &dD);
    prepararSistemaLinear(n, dA, dB, Dp, dC, dD, &matriz, &b, &x);
    

    printf("\n\nn= %d. \ndA= %lf. \ndB= %lf. \ndC= %lf. \ndD= %lf. \nDp= %lf.\n", n, dA, dB, dC, dD, Dp);
    fflush(stdout);
    
    //TRIANGULARIZACAO
    triangularizacao(n, matriz, b, &ce, &cs);
    
    //METODOS
    eliminacao(n, matriz, b, x, &ce);
    seidel(matriz, b, n, &cs);
    
    //MOSTRANDO ITERACOES
    printf("\n\nce: %d.\ncs: %d.", ce, cs);
    fflush(stdout);
    
    liberarTudo(n, &matriz, &b, &x);
    return 0;
}
