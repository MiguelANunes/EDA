#include <stdio.h>
#include <stdlib.h>
#include "listaDE.h"

int main(){

	int Input, i;
	Node *Lista;
	Lista = cria_node();
	inicializa(&Lista);

	scanf("%d", &Input);
	for(i=0;Input != -1; scanf("%d", &Input), i++){
		if(i==0)
			insere_inicio(Input, &Lista);
		else
			insere_final(Input, &Lista);
	}

	exibe(Lista);

	return 0;
}
