#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;

int main(int argc, char const *argv[]){
	uint n;
	printf("Insira dimensão n\n");
	if(scanf("%u",&n)==0){
		printf("Numero inválido!");
		exit();
	}
	/* coisas */
	return 0;
}
