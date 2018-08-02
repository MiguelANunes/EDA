#include <stdio.h>
#include <stdlib.h>

int *inverte(int *original, int size);

int main(){
	int tamanho, *vetor, *newvetor, i;

	scanf("%d", &tamanho);
	vetor = malloc(tamanho * sizeof(int*));

	for(i=0;i<tamanho;i++)
		scanf("%d", &vetor[i]);

	newvetor = inverte(vetor, tamanho);

	for(i=0;i<tamanho;i++)
		printf("%d ", newvetor[i]);

	return 0;
}

int *inverte(int *original, int size){
	int temp, i, j;

	for(i=0 , j=size-1; i<j && j>i; i++ , j--){
		temp = original[i];
		original[i] = original[j];
		original[j] = temp;
	}

	return original;
}
