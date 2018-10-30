#include <stdio.h>
#include <stdlib.h>
#include "organizacao.c"
#include "gauss.c"

int operacoes = 0; //numero de operacoes realizadas

//i linha j coluna



int main(int argc, char const *argv[]){
    int n;
    double dA, dB, dC, dD, Dp, **matriz, *b;


    pegarValores(&n, &dA, &dB, &Dp, &dC, &dD);
    prepararSistemaLinear(n, dA, dB, Dp, dC, dD, &matriz, &b);


    printf("\n\nn= %d. \ndA= %lf. \ndB= %lf. \ndC= %lf. \ndD= %lf. \nDp= %lf.\n", n, dA, dB, dC, dD, Dp);
    fflush(stdout);

    eliminacao(n, matriz, b);

    liberarTudo(n, &matriz, &b);


    return 0;
}
