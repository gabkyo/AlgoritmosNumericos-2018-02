#include <stdio.h>
#include <stdlib.h>
#include "organizacao.h"
#include "gauss.h"

int operacoes = 0; //numero de operacoes realizadas

//i linha j coluna



int main(int argc, char const *argv[]){
    int n, ce, cs;
    double dA, dB, dC, dD, Dp, **matriz, *b, *x;
    

    pegarValores(&n, &dA, &dB, &Dp, &dC, &dD);
    prepararSistemaLinear(n, dA, dB, Dp, dC, dD, &matriz, &b, &x);
    

    printf("\n\nn= %d. \ndA= %lf. \ndB= %lf. \ndC= %lf. \ndD= %lf. \nDp= %lf.\n", n, dA, dB, dC, dD, Dp);
    fflush(stdout);
    
    //TRIANGULARIZACAO
    triangularizacao(n, matriz, b);
    
    
    eliminacao(n, matriz, b, x, &ce);
    
    //FAZER MAIS DE UMA VEZ...
    gaussSeidel(n, matriz, b, x, &cs);
    
    liberarTudo(n, &matriz, &b, &x);
    
    return 0;
}
