#include <stdio.h>
#include <stdlib.h>
#include "lista_LSE.h"

void exibe_recursivo(Node *L);

int main(){

	int Input, i;
	Node *Lista = NULL;

	scanf("%d", &Input);
	for(i=1;Input != -1; i++){

		if(i == 1)
			Lista = cria_node();
		insere_meio(i, Input, &Lista);
		scanf("%d", &Input);
	}

	if(!(vazia(&Lista))){
		exibe_recursivo(Lista);
		printf("\n");
	}else{
		printf("VAZIA\n");
	}

	return 0;
}

void exibe_recursivo(Node *L){

	if(!(ultimo(L)))
		exibe_recursivo(L->next);

	if(!(ultimo(L)))
		printf("%d ",L->Valor);

}
