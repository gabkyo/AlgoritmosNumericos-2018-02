#include <stdio.h>
#include <stdlib.h>

int operacoes=0; //numero de operacoes realizadas


void pegaValores(int n, double *dA, double *dB, double *dC, double *dD, double *Dp){
	*n = 0;
	while(1){
		printf("Insira dimensão n\n");
		fflush(stdout);
		scanf("%i", &n);
		if(n<3){
			printf("Número inválido!\n");
		} else {
			break;
		}
	}

	printf("Insira os valores de dA:\n");
	fflush(stdout);
	for (int i = 0; i < n; i++) {
		scanf("%lf", &(dA[i]));
	}

	printf("Insira os valores de dB:\n");
	fflush(stdout);
	for (int i = 0; i < n; i++) {
		scanf("%lf", &(dB[i]));
	}

	printf("Insira os valores de Dp:\n");
	fflush(stdout);
	for (int i = 0; i < n; i++) {
		scanf("%lf", &(Dp[i]));
	}

	printf("Insira os valores de dC:\n");
	fflush(stdout);
	for (int i = 0; i < n; i++) {
		scanf("%lf", &(dC[i]));
	}

	printf("Insira os valores de dD:\n");
	fflush(stdout);
	for (int i = 0; i < n; i++) {
		scanf("%lf", &(dD[i]));
	}


}

int main(int argc, char const *argv[]){

	int *n;
	double *dA,*dB,*dC,*dD,*Dp;


	n = (int*) malloc(sizeof(int));
	dA = (double*)malloc(sizeof(double)*n);
	dB = (double*)malloc(sizeof(double)*n);
	dC = (double*)malloc(sizeof(double)*n);
	dD = (double*)malloc(sizeof(double)*n);
	Dp = (double*)malloc(sizeof(double)*n);


	pegaValores();

	free(n);
	free(dA);
	free(dB);
	free(dC);
	free(dD);
	free(Dp);
	return 0;
}
