#ifndef GAUSS_H_
#define GAUSS_H_

    void triangularizacao(int n, double **matriz, double *b, int *ce, int *cs);
    void pivotear(double **matriz, int i,int n);
    void eliminacao(int n, double **matriz, double *b, double *x, int *ce);

#endif /* GAUSS_H_ */

