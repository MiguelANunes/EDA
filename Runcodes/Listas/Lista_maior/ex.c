#include <stdio.h>
#include <stdlib.h>
#include "lista_LSE.h"

int main(){

	int Input, i, Maior = -1;
	Node *Lista = cria_node();

	scanf("%d", &Input);
	for(i=1; Input != -1; i++){
		insere_meio(i, Input, &Lista);
		scanf("%d", &Input);
	}

	for(;Lista->next != NULL; Lista = Lista->next){
		if(Lista->Valor >= Maior)
			Maior = Lista->Valor;
	}

	printf("%d\n", Maior);

	return 0;
}
