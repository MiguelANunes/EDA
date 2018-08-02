#include <stdio.h>
#include <stdlib.h>
#include "listaCirc.h"

int main(){

	int Input, i, Posicao;
	Node *Lista, *Temp;
	Lista = cria_node();

	scanf("%d", &Input);
	for(i=1; Input != -1; i++ , scanf("%d", &Input)){

		if(i==1)
			insere_inicio(Input, &Lista);
		else
			insere_final(Input, &Lista);
	}
	scanf("%d", &Posicao);

	if(Posicao == 0){
		exibe(Lista);
		return 0;
	}else{
		for(Temp = Lista ;Posicao >= 1; Posicao-- , Temp = Temp->Proximo) ;
		Temp->Comprimento = Lista->Comprimento;
		//printf("Temp->Comprimento: %d\n", Temp->Comprimento);
		exibe(Temp);
	}

	return 0;
}
