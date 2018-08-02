#include <stdio.h>
#include <stdlib.h>

int maior_valor(int Comprimento, int *Vetor);

int main(){

	int Numeros[10] = {1,2,3,4,5,999,7,8,9,10};

	printf("Maior Valor em Numeros = %d\n", maior_valor(10, Numeros));

	return 0;
}

int maior_valor(int Comprimento, int *Vetor){

	int Hold;

	if(Comprimento == 0)
		return 0;
	if(Comprimento == 1)
		return Vetor[0];

	Hold = maior_valor(Comprimento-1, &*Vetor);

	if(Hold >= Vetor[Comprimento-1])
		return Hold;

	return Vetor[Comprimento-1];
}

// Complexidade == 2*n
// Consideravlmente Ineficiente
// Sempre vai iterar duas vezes pelo vetor
