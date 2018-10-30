#include <stdio.h>
#include <stdlib.h>
#include "organizacao.h"
#include "gauss.h"
#include "seidel.h"

int operacoes = 0; //numero de operacoes realizadas

//i linha j colunaaaa



int main(int argc, char const *argv[]){
    int n, ce, cs;
    double dA, dB, dC, dD, Dp, **matriz, *b, *x;
    

    pegarValores(&n, &dA, &dB, &Dp, &dC, &dD);
    prepararSistemaLinear(n, dA, dB, Dp, dC, dD, &matriz, &b, &x);
    

    printf("\n\nn= %d. \ndA= %lf. \ndB= %lf. \ndC= %lf. \ndD= %lf. \nDp= %lf.\n", n, dA, dB, dC, dD, Dp);
    fflush(stdout);
    
    //TRIANGULARIZACAO
    triangularizacao(n, matriz, b, &ce, &cs);
    
    
    eliminacao(n, matriz, b, x, &ce);
    
    //FAZER MAIS DE UMA VEZ...
    inicio(matriz,b,n);
    
    liberarTudo(n, &matriz, &b, &x);
    
    printf("\n\n%d\n", ce);
    fflush(stdout);
    
    return 0;
}
