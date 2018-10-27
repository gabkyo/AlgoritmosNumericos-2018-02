#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[]){
	int n;
	double *dA,*dB,*dC,*dD,*Dp;

	printf("Insira dimensão n\n");
	fflush(stdout);
	scanf("%i",&n);
	if(n<1){
		printf("Número inválido!\n");
		exit(1);
	}

	dA=(double*)malloc(sizeof(double)*n);
	dB=(double*)malloc(sizeof(double)*n);
	dC=(double*)malloc(sizeof(double)*n);
	dD=(double*)malloc(sizeof(double)*n);
	Dp=(double*)malloc(sizeof(double)*n);

	printf("Insira os valores de dA:\n");
	fflush(stdout);
	for(int i=0;i<n;i++){
		scanf("%lf",&(dA[i]));
	}

	printf("Insira os valores de dB:\n");
	fflush(stdout);
	for(int i=0;i<n;i++){
		scanf("%lf",&(dB[i]));
	}

	printf("Insira os valores de Dp:\n");
	fflush(stdout);
	for(int i=0;i<n;i++){
		scanf("%lf",&(Dp[i]));
	}

	printf("Insira os valores de dC:\n");
	fflush(stdout);
	for(int i=0;i<n;i++){
		scanf("%lf",&(dC[i]));
	}

	printf("Insira os valores de dD:\n");
	fflush(stdout);
	for(int i=0;i<n;i++){
		scanf("%lf",&(dD[i]));
	}

	free(dA);
	free(dB);
	free(dC);
	free(dD);
	free(Dp);
	return 0;
}
