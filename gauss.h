#ifndef GAUSS_H_
#define GAUSS_H_

void pivotear(double **matriz, int i, int j){

}

void eliminacao(double *dA,double *dB,double *Dp,double *dC,double *dD, int n){
	double **matriz=(double**)malloc(sizeof(double*) *n);
		for (int i = 0; i < n; ++i) {
			matriz[i]=(double*)malloc(sizeof(double)*n);
			for (int j = 0; j < n; ++j) {
				if(i-j==2){
					matriz[i][j]=dA[i];
				}else if (i-j==1) {
					matriz[i][j]=dB[j];
				}else if (i-j==1) {
					matriz[i][j]=dB[j];
				}else if (i-j==1) {
					matriz[i][j]=dB[j];
				}else if (i-j==1) {
					matriz[i][j]=dB[j];
				}else{

				}
			}
		}
}


#endif /* GAUSS_H_ */
