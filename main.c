#include <stdio.h>
#include <stdlib.h>
#include "organizacao.h"
#include "gauss.h"
#include "seidel.h"

int main(int argc, char const *argv[]){
    int n, cG, cS;
    double dA, dB, dC, dD, Dp, **matriz, *b, *xGauss, *xSeidel;
    

    pegarValores(&n, &dA, &dB, &Dp, &dC, &dD);
    prepararSistemaLinear(n, dA, dB, Dp, dC, dD, &matriz, &b, &xGauss, &xSeidel);
    

    printf("\n\nn= %d. \ndA= %lf. \ndB= %lf. \nDp= %lf. \ndC= %lf. \ndD= %lf.\n", n, dA, dB, Dp, dC, dD);
    fflush(stdout);
    
    //ITERATIVO DE DEIDEL
    seidel(matriz, b, n, xSeidel, &cS);
    
    //ELIMINACAO DE GAUUS
    gauss(n, matriz, b, xGauss, &cG);

    //SAIDA
    mostrarSaida(n, xGauss, cG, xSeidel, cS);
    
    //LIBERAR MEMORIA
    liberarTudo(n, &matriz, &b, &xGauss, &xSeidel);
    return 0;
}