#include <stdio.h>
#include <stdlib.h>
#include "lista_LSE.h"
#define par(x) (x%2 == 0)

void insere_ordenado(char Modo, int entrada, Node **Header);

int main(){

	int Input;
	Node *Lista, *Pares, *Impares, *Corrente;
	Lista = cria_node();
	Pares = cria_node();
	Pares->next = NULL;
	Impares = cria_node();
	Impares->next = NULL;

	scanf("%d", &Input);
	while(Input != -1){
		insere_final(Input, &Lista);
		scanf("%d", &Input);
	}

	for(;Lista != NULL; Lista = Lista->next){

		if(Lista->Valor != 0){

			if(par(Lista->Valor)){

				if(vazia(Pares)){
					Pares->Valor = Lista->Valor;
					Pares->next = NULL;
					Pares->size++;
				}else{
					insere_ordenado('d',Lista->Valor,&Pares);
					Pares->size++;
				}
			}else{
				if(vazia(Impares)){
					Impares->Valor = Lista->Valor;
					Impares->next = NULL;
					Impares->size++;
				}else{
					insere_ordenado('u',Lista->Valor,&Impares);
					Impares->size++;
				}
			}
		}
	}

	Corrente = Pares;
	for(;Corrente->next != NULL; Corrente = Corrente->next) ;
	//Usando uma lista auxiliar para iterar pela lista de pares
	//para concatenar a lista de pares na lista de Impares;
	Corrente->next = Impares;

	exibe(Pares);

	return 0;
}

void insere_ordenado(char Modo, int entrada, Node **Header){
	int i;
	Node *aux, *novo, *ant;
	aux = ant = (*Header);

	switch(Modo){

		case 'd': //ordenar menor p/ maior
			for(i=1;aux != NULL; ant = aux , aux = aux -> next , i++){

				if(entrada <= aux->Valor){

					novo = cria_node();
					novo->Valor = entrada;
					novo->next = aux;
					if(i == 1)
						*Header = novo;
					else
						ant->next = novo;
					return;
				}else if(entrada >= aux->Valor && aux->next == NULL){

					novo = cria_node();
					novo->Valor = entrada;
					novo->next = NULL;
					aux->next = novo;
					return;
				}

			}
		break;

		aux = ant = (*Header);
		case 'u': //ordenar maior p/ menor
			for(i=1;aux != NULL; ant = aux , aux = aux -> next , i++){

				if(entrada >= aux->Valor){
					novo = cria_node();
					novo->Valor = entrada;
					novo->next = aux;
					if(i == 1)
						*Header = novo;
					else
						ant->next = novo;
					return;

				}else if(entrada <= aux->Valor && aux->next == NULL){
					novo = cria_node();
					novo->Valor = entrada;
					novo->next = NULL;
					aux->next = novo;
					return;
				}

			}
		break;
	}

	return;
}
