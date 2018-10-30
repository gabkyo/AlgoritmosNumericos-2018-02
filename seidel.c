#include <stdio.h>
#include <stdlib.h>
#include "seidel.h"
#include <math.h>

double tol=pow(10,-10);

bool terminar(double xi,double x0){
	double temp=fabs(xi-x0)/fabs(xi);
	if(temp<=tol){
		return true;
	}
	return false;
}


void inicio(double **matriz,double *b,int n){
	double *x=(double*)malloc(sizeof(double)*n),x0;
	for (int i = 0; i < n; i++) {
		x[i]=b[i]/matriz[i][i];
	}
	while(true){
		for (int i = 0; i < n; i++) {
			x0=x[i];
			x[i]=b[i];
			for (int j = 0; j < n; j++) {
				x[i]-=matriz[i][j] * x[j];
			}
			x[i]=x[i]/matriz[i][i];
			if(terminar(x[i],x0)){
				//acabou
				printf("\nSeidel\nxo%d: %lf\n",i,x0);
				for (int j = 0; j < n; ++j) {
					printf("%lf\n",x[j]);
					fflush(stdout);
				}
				free(x);
				return;
			}

		}
	}
}
