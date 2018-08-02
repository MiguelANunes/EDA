#include <stdio.h>
#include <stdlib.h>

int *soma(int *V1, int *V2, int size);

int main(){
	int tamanho, *vetor1, *vetor2, *vetorR, i;

	scanf("%d", &tamanho);
	vetor1 = malloc(tamanho * sizeof(int*));
	vetor2 = malloc(tamanho * sizeof(int*));
	for(i=0;i<tamanho;i++)
		scanf("%d", &vetor1[i]);
	for(i=0;i<tamanho;i++)
		scanf("%d", &vetor2[i]);

	vetorR = soma(vetor1, vetor2, tamanho);

	for(i=0;i<tamanho;i++)
		printf("%d ", vetorR[i]);

	return 0;
}

int *soma(int *V1, int *V2, int size){
	int i;
	for(i=0;i<size;i++)
		V1[i] += V2[i];
	return V1;
}
