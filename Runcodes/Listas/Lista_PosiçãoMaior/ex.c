#include <stdio.h>
#include <stdlib.h>
#include "lista_LSE.h"


int main(){

	int Maior = -1, Posicao = 0, i, Input;
	Node *Lista = cria_node();

	scanf("%d", &Input);
	for(i=1; Input != -1; i++){
		insere_meio(i, Input, &Lista);
		scanf("%d", &Input);
	}

	for(i=1; Lista->next != NULL; Lista = Lista->next , i++){

		if(Lista->Valor > Maior){
			Maior = Lista->Valor;
			Posicao = i;
		}

	}

	printf("%d\n", Posicao);

	return 0;
}
