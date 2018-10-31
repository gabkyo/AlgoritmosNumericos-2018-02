#ifndef GAUSS_H_
#define GAUSS_H_

    void triangularizacao(int n, double **matriz, double *b, int *ce, int *cS);
    void pivotear(double **matriz, int i,int n);
    void gauss(int n, double **matriz, double *b, double *x, int *cG);

#endif /* GAUSS_H_ */

