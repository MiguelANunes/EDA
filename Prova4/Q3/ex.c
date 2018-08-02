#include <stdio.h>
#include <stdlib.h>
#include "listaCirc.h"

void insere_final(int Entrada, Node **Header);

int main(){

	int Input, i=1, Remover;
	Node *Maldito_Problema_do_URI;
	Maldito_Problema_do_URI = cria_node();

	scanf("%d", &Input);
	for(i=1;Input != -1; scanf("%d", &Input) , i++){

		if(i == 1){
			insere_inicio(Input, &Maldito_Problema_do_URI);
			Maldito_Problema_do_URI->Proximo = Maldito_Problema_do_URI;
			continue;
		}
		insere_final(Input, &Maldito_Problema_do_URI);
		Maldito_Problema_do_URI->Comprimento++;

	}

	scanf("%d", &Remover);

	if(Remover != 0){
		Remover %= Maldito_Problema_do_URI->Comprimento;
		remove_node(Remover, &Maldito_Problema_do_URI);
	}

	exibe(Maldito_Problema_do_URI);

	return 0;
}

void insere_final(int Entrada, Node **Header){

	Node *New_node, *Aux;
	Aux = (*Header);
	New_node = cria_node();

	for(;Aux->Proximo != (*Header); Aux = Aux->Proximo) ;

	New_node->Conteudo = Entrada;
	New_node->Proximo = (*Header);
	Aux->Proximo = New_node;
}

void remove_node(int Pos, Node **Header){

	int Aux=1;
	Node *Anterior, *Corrente;
	Anterior = Corrente = (*Header);
	//Apontando Anterior e Corrente para a cabeça da lista

	if(Pos == 1){//Excuindo a Cabeça

		//Movendo o nó anterior para o ultimo nó da lista
		for(;Anterior->Proximo != (*Header); Anterior = Anterior->Proximo) ;
		Corrente->Proximo->Comprimento = (*Header)->Comprimento;
		//Copiando o comprimento da lista para a nova cabeça
		(*Header) = Corrente->Proximo;
		Anterior->Proximo = (*Header);
		(*Header)->Comprimento--;
		free(Corrente);

	}else if(Pos != (*Header)->Comprimento){//Excuindo posição qualquer

		//Movendo Corrente para a posição que quero exlcuir
		//E Anterior para a posição antes dela
		for(;Aux != Pos; Aux++ , Anterior = Corrente , Corrente = Corrente->Proximo) ;
		Anterior->Proximo = Corrente->Proximo;
		(*Header)->Comprimento--;
		free(Corrente);

	}else{//Excluindo a Ultima posição
		for(;Corrente->Proximo != (*Header); Anterior = Corrente , Corrente = Corrente->Proximo) ;
		Anterior->Proximo = Corrente->Proximo;
		(*Header)->Comprimento--;
		free(Corrente);
	}

}
