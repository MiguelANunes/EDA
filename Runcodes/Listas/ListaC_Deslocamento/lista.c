#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "listaCirc.h"

Node *cria_node(void){

	Node *novo;
	novo = (Node*)malloc(sizeof(Node));
	novo->Comprimento = 0;

	return novo;
}

bool vazia(Node *Header){
	return Header->Comprimento == 0;
}

// Insere atrás da cabeça
void insere_inicio(int Entrada, Node **Header){

	Node *novo_no, *Aux = (*Header), *Temp;
	novo_no = cria_node();

	if((*Header)->Proximo != NULL){
		for(;Aux->Proximo != (*Header); Aux = Aux->Proximo) ;
		Aux->Proximo = novo_no;
		novo_no->Conteudo = Entrada;
		novo_no->Comprimento = (*Header)->Comprimento + 1;
		Temp = (*Header);
		*Header = novo_no;
		novo_no->Proximo = Temp;
		return;
	}

	novo_no->Conteudo = Entrada;
	novo_no->Comprimento = 1;
	*Header = novo_no;
	(*Header)->Proximo = novo_no;

}

void insere_meio(int Pos, int Entrada, Node **Header){

	Node *Anterior, *Corrente, *New;
	int Aux=1;
	Corrente = Anterior = (*Header);
	//Apontando Anterior e Corrente para a cabeça da lista
	New = cria_node();

	if(Pos == 1)
		insere_inicio(Entrada, &(*Header));

	//Iterando pela Lista até achar a posição para inserir
	for(;Aux != Pos; Aux++ , Anterior = Corrente , Corrente = Corrente->Proximo) ;

	if(Pos < ((*Header)->Comprimento)){
		New->Conteudo = Entrada;
		New->Proximo = Corrente;
		Anterior->Proximo = New;
	}else if(Pos == ((*Header)->Comprimento)){
		insere_final(Entrada, &(*Header));
	}
	(*Header)->Comprimento++;

}

void insere_final(int Entrada, Node **Header){

	Node *New_node, *Aux;
	Aux = (*Header);
	New_node = cria_node();
	(*Header)->Comprimento++;

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

void exibe(Node *Header){

	int t = Header->Comprimento;

	for(;t>0; Header = Header->Proximo , t--){
		printf("%d ", Header->Conteudo);
	}
	printf("\n");

}

void deleta(Node **Header){

	Node *Temp = (*Header), *H;

	for(;Temp->Proximo != NULL; H = Temp->Proximo , Temp = H){
		free(Temp);
	}
	free(Temp);

}
