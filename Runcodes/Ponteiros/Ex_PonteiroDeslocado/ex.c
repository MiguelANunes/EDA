#include <stdio.h>
#include <stdlib.h>

int* deslocamento(int *Vetor, int Deslocado);

int main(){
	int tamanho, i, *vetor, *vetorDeslocado, move;
	scanf("%d", &tamanho);
	vetor = malloc(tamanho * sizeof(int));

	for(i=0;i<tamanho;i++)
		scanf("%d", &*vetor+i);

	scanf("%d", &move);

	vetorDeslocado = deslocamento(vetor, move);

	for(i=0;i<tamanho-move;i++)
		printf("%d ", *(vetorDeslocado+i));
	printf("\n");

	return 0;
}

int* deslocamento(int *Vetor, int Deslocado){
	return Vetor+Deslocado;
}
