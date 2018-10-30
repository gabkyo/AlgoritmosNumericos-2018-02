#ifndef ORGANIZACAO_H
#define ORGANIZACAO_H

#ifdef __cplusplus
extern "C" {
#endif

void pegarValores(int *n, double *dA, double *dB, double *Dp, double *dC, double *dD);
void prepararSistemaLinear(int n, double dA, double dB, double Dp, double dC, double dD, double ***matriz, double **b);
void liberarTudo(int n, double ***matriz, double **b);

#ifdef __cplusplus
}
#endif

#endif /* ORGANIZACAO_H */

