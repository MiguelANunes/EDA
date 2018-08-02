#include <stdio.h>
#include <stdlib.h>

int main(){

	int Tamanho, *vetor, *ponteiro, i, saltos=0;

	scanf("%d\n", &Tamanho);

	vetor = (int*) malloc(Tamanho * sizeof(int));
	for(i=0;i<Tamanho;i++)
		scanf("%d\n", &vetor[i]);

	ponteiro = vetor;

	while(*ponteiro != 99 && *ponteiro != 0){
		vetor += *ponteiro;
		ponteiro = vetor;
		saltos++;
	}

	printf("%d\n", saltos);

	return 0;
}
