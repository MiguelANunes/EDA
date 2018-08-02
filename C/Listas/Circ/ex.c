#include <stdio.h>
#include <stdlib.h>
#include "listaCirc.h"

int main(){

	int Input, i;
	Node *Teste;
	Teste = cria_node();

	scanf("%d", &Input);
	for(i=1;Input != -1;i++ , scanf("%d", &Input)){

		if(i == 1){
			insere_inicio(Input, &Teste);
			continue;
		}

		insere_final(Input, &Teste);
	}

	insere_inicio(5, &Teste);

	printf("Comprimento = %d\n", Teste->Comprimento);
	exibe(Teste);
	remove_node(5, &Teste);
	exibe(Teste);

	return 0;
}
