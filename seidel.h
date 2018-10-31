#ifndef SEIDEL_H_
#define SEIDEL_H_
#include <stdbool.h>

void seidel(double **matriz, double *b, int n, int *cs);
bool terminar(double xi, double x0);


#endif /* SEIDEL_H_ */
