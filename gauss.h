#ifndef GAUSS_H_
#define GAUSS_H_

void pivotear(double **matriz, int i,int n){
	double temp,max=matriz[i][i];
	int k=i;
	for (int j = i; j < i+3 && j<n; ++j) {
		if (matriz[i][j]>max) {
			max=matriz[i][j];
			k=j;
			//operacao+1
		}
	}
	if (k!=i) {
		for (int j = i; j < i+5 && j<n; ++j) {
			temp=matriz[j][i]; matriz[j][i]=matriz[j][k]; matriz[j][k]=temp;
			//operacao+1
		}
	}
	printf("ok\n");
		fflush(stdout);

}

void eliminacao(double dA,double dB,double Dp,double dC,double dD, int n){
	double **matriz=(double**)malloc(sizeof(double*) *n);
	double *b=(double*)malloc(sizeof(double) * n);
	for (int i = 0; i < n; ++i) {
		matriz[i]=(double*)malloc(sizeof(double)*n);
		for (int j = 0; j < n; ++j) {
			if(i-j==2){
				matriz[i][j]=dA;
			}else if (i-j==1) {
				matriz[i][j]=dB;
			}else if (i==j) {
				matriz[i][j]=Dp;
			}else if (i-j==-2) {
				matriz[i][j]=dC;
			}else if (i-j==-1) {
				matriz[i][j]=dD;
			}else{
				matriz[i][j]=0;
			}
		}
	}
	printf("ok\n");
	fflush(stdout);
	for (int i = 0; i < n; ++i) {//metodo
		pivotear(matriz, i,n);
		printf("%d\n",i);
		fflush(stdout);
		for (int j = i+1; j < i+3 && j<n; ++j) { //linha
			for (int k = i; k < i+5 && k<n; ++k) { //coluna
				matriz[k][j]-=matriz[k][i]*(matriz[i][j]/matriz[i][i]);
				//Akj=Akj-Aki*Aij/Aii
				//operacao+2
			}
		}
	}
	printf("ok\n");
	fflush(stdout);
	for (int i = n-1; i >=0; --i) { //solucionar para b
		b[i]=matriz[i][i];
		for (int j = i+1; j < i+5 && j<n; ++j) {
			if (matriz[j][i]!=0) {
				b[i]-=matriz[j][i]*b[j];
				//operacao+1
			}
		}

	}
	printf("ok\n");
	fflush(stdout);
	for (int i = 0; i < n; ++i) { //printar
		for (int j = 0; j < n; ++j) {
			printf("%.2lf ",matriz[i][j]);
		}
		printf("\n");
	}
	printf("ok\n");
	fflush(stdout);
	for (int i = 0; i < n; ++i) {
		printf("%.2lf\n",b[i]);
	}
}


#endif /* GAUSS_H_ */
