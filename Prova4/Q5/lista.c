#include "lista_LSE.h"

Node* cria_node(void){

	Node *novo;
	novo = (Node*)malloc(sizeof(Node));
	novo->size = 0;

	return novo;
}

bool vazia(Node *L){
	return(L->size == 0);
}

int comprimento(Node **L){

	if((*L) == NULL)
		return 0;

	int i=1;
	Node *aux;
	aux = (*L);
	for(aux = (*L), i=1 ; (aux->next != NULL) ; aux = aux->next, i++) ;

	return i;
}

void insere_inicio(int entrada, Node **head){

	Node *novo;
	novo = (Node*)malloc(sizeof(Node));

	novo->Valor = entrada;
	novo->next = *head;
	novo->size++;
	*head = novo;

	return;
}

void insere_meio(int posicao, int entrada, Node **head_L){

	if( posicao > comprimento(head_L) || posicao < 1)
		return;

	int i = 1;
	Node *new_node, *corrente, *anterior;;
	new_node = (Node*)malloc(sizeof(Node));
	corrente = anterior = (*head_L);

	if(posicao == 1){
		insere_inicio(entrada, &(*head_L));
		return;
	}

	while(i < posicao){
		anterior = corrente;
		corrente = corrente -> next;
		i++;
	}

	new_node->Valor = entrada;
	anterior->next = new_node;
	new_node->next = corrente;
	new_node->size++;

return;

}

void insere_final(int entrada, Node **L){

	Node* novo;

	if((*L) == NULL){

		novo = cria_node();
		(*L) = novo;
		novo->Valor = entrada;
		novo->next = NULL;
		novo->size++;

		return;
	}
	else{

		Node *aux;
		aux = (*L);
		for(;aux->next != NULL;) aux = aux -> next;

		novo = cria_node();
		novo->Valor = entrada;
		novo->next = NULL;
		novo->size++;
		aux->next = novo;

		return;
	}
}

void exclui_meio(int posicao, Node **L){

	if(posicao > comprimento(L) || posicao < 1)
		return;

	int i=1;
	Node *corrente, *anterior;
	corrente = anterior = (*L);

	if(posicao == 1){
		corrente->size--;
		(*L) = corrente->next;
		free(corrente);
		return;
	}

	while(i < posicao){
		anterior = corrente;
		corrente = corrente->next ;
		i++;
	}

	corrente->size--;
	anterior->next = corrente->next ;
	free(corrente);

	return;
}

void exclui_ultimo(Node **cabeca_original){
	int posicao_ultimo = comprimento( &(*cabeca_original) );
	exclui_meio(posicao_ultimo , &(*cabeca_original));
	// &(*cabeca_original) == o endereço do ponteiro da cabeça da lista original
}

void exibe(Node *L){

	while(L->next != NULL){
		printf("%d ",L -> Valor);
		L = L -> next;
	}
	printf("\n");

	return;
}

void deleta(Node **L){

	if((*L) != NULL){

		int i=1;
		Node *aux, *prox;
		aux =(*L);

		while(aux->next != NULL){

			prox = aux->next;
			free(aux);
			aux = prox;
			i++;

		}

		free(aux);
		return;
	}

	return;
}
