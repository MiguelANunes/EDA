#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "listaDE.h"

Node* cria_node(void){

	Node *Novo_no;
	Novo_no = (Node*)malloc(sizeof(Node));
	Novo_no->Comprimento = 0;

	return Novo_no;
}

bool vazia(Node *Header){
	return Header->Comprimento == 0;
}

void inicializa(Node **Header){

	Node *Primeiro, *Ultimo;
	Primeiro = cria_node();
	Ultimo = cria_node();

	Primeiro->Conteudo = -100;
	Primeiro->Comprimento = -1;
	Ultimo->Conteudo = -200;
	Ultimo->Comprimento = -2;

	Primeiro->Proximo = (*Header);
	Ultimo->Anterior = (*Header);
	(*Header)->Proximo = Ultimo;
	(*Header)->Anterior = Primeiro;

}

void insere_inicio(int Entrada, Node **Header){

	if(vazia(*Header)){
		(*Header)->Conteudo = Entrada;
		(*Header)->Comprimento++;
		return;
	}

	Node *Novo_no, *Aux;
	Novo_no = cria_node();
	Novo_no->Conteudo = Entrada;
	Novo_no->Comprimento = (*Header)->Comprimento+1;
	Aux = (*Header)->Anterior;

	(*Header)->Anterior = Novo_no;
	Novo_no->Proximo = (*Header);
	Novo_no->Anterior = Aux;
	Aux->Proximo = Novo_no;
	*Header = Novo_no;

	return;
}

void insere_meio(int Pos, int Entrada, Node **Header){

	if(Pos == 1){
		insere_inicio(Entrada, &*Header);
		return;
	}
	if(Pos == (*Header)->Comprimento){
		insere_final(Entrada, &*Header);
		return;
	}

	Node *Corrente, *Prox, *Novo_no;
	Novo_no = cria_node();
	int t;

	for(t=1 , Corrente = (*Header) ; t != Pos; t++ , Corrente = Corrente->Proximo) ;
	Prox = Corrente->Proximo;

	Novo_no->Conteudo = Entrada;
	Novo_no->Anterior = Corrente;
	Novo_no->Proximo = Prox;
	Corrente->Proximo = Novo_no;
	Prox->Anterior = Novo_no;
	(*Header)->Comprimento++;

	return;
}

void insere_final(int Entrada, Node **Header){

	Node *Novo_no, *Corrente;
	Novo_no = cria_node();

	for(Corrente = (*Header); Corrente->Proximo->Conteudo != -200; Corrente = Corrente->Proximo) ;
	Novo_no->Conteudo = Entrada;
	Novo_no->Proximo = Corrente->Proximo; // ultimo
	Novo_no->Anterior = Corrente;
	Corrente->Proximo->Anterior = Novo_no;
	Corrente->Proximo = Novo_no;
	(*Header)->Comprimento++;

	return;
}

void remove_node(int Pos, Node **Header){

	Node *Corrente;
	int temp;

	if(Pos == 1){ // Excluindo a cabeça

		Corrente = (*Header);
		Corrente->Anterior->Proximo = Corrente->Proximo;
		Corrente->Proximo->Anterior = Corrente->Anterior;
		*Header = Corrente->Proximo;
		free(Corrente);

	}else if(Pos == (*Header)->Comprimento){ // Excluindo o ultimo

		for(Corrente = (*Header); Corrente->Proximo->Conteudo != -200; Corrente = Corrente->Proximo) ;
		Corrente->Anterior->Proximo = Corrente->Proximo;
		Corrente->Proximo->Anterior = Corrente->Anterior;
		free(Corrente);

	}else{ // Excluindo nó qualquer

		for(temp = 1 , Corrente = (*Header); temp != Pos; Corrente = Corrente->Proximo) ;
		Corrente->Anterior->Proximo = Corrente->Proximo;
		Corrente->Proximo->Anterior = Corrente->Anterior;
		free(Corrente);

	}

}

void exibe(Node *Header){

	int t = Header->Comprimento;

	for(;t>0; Header = Header->Proximo , t--){
		printf("%d ", Header->Conteudo);
	}
	printf("\n");

}

void deleta(Node **Header){

	Node *Temp = (*Header), *H;

	for(;Temp->Proximo->Conteudo != -200; H = Temp->Proximo , Temp = H){
		free(Temp);
	}
	free(Temp);

}
