#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

int main(){

	int qtd = 5, i=0, x;
	fila *Teste;
	Teste = criar(qtd);

	for(;i<5;i++){
		scanf("%d", &x);
		enqueue(x, Teste);
	}

	exibe(Teste);

	return 0;
}
