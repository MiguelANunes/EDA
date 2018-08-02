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

//Substitiu a Cabeça
void insere_inicio(int Entrada, Node **Header){

	Node *novo_no;
	novo_no = cria_node();
	novo_no->Conteudo = Entrada;
	novo_no->Comprimento++;
	novo_no->Proximo = *Header;
	*Header = novo_no;

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

	if(Pos < ((*Header)->Comprimento)-1){
		New->Conteudo = Entrada;
		New->Proximo = Corrente;
		Anterior->Proximo = New;
	}else if(Pos == ((*Header)->Comprimento)-1){
		New->Conteudo = Entrada;
		New->Proximo = (*Header);
		Anterior->Proximo = New;
	}
	(*Header)->Comprimento++;

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
