#include <stdio.h>
#include <stdlib.h>
#include "listaCirc.h"

void troca_conteudo(Node **Origem, Node **Destino);

int main(){

	int Input, i, Deslocamentos;
	Node *Anel, *Aux;
	Anel = cria_node();

	scanf("%d", &Input);
	for(i=1; Input != -1; i++ , scanf("%d", &Input)){
		if(i==1)
			insere_inicio(Input, &Anel);
		else
			insere_final(Input, &Anel);
	}

	//exibe(Anel);

	while(Anel->Conteudo != 1){
		for(Aux = Anel; Aux->Proximo != Anel; Aux = Aux->Proximo) ;
	}

	return 0;
}

void troca_conteudo(Node **Origem, Node **Destino){

	int Hold;
	Hold = (*Origem)->Conteudo;
	(*Origem)->Conteudo = (*Destino)->Conteudo;
	(*Destino)->Conteudo = Hold;

	return;
}
