#include <stdio.h>
#include <stdlib.h>
#include "lista_LSE.h"

int main(){

	Node *Lista1, *Lista2, *Corrente;
	Lista1 = cria_node();
	Lista2 = cria_node();
	int Input, i;

	scanf("%d", &Input);
	for(i=1;Input != -1;i++){
		insere_meio(i,Input, &Lista1);
		Lista1->size++;
		scanf("%d", &Input);
	}//apontar o ultimo termo para NULL
	Corrente = Lista1;
	for(;Corrente->next->next != NULL; Corrente = Corrente->next) ;
	Corrente->next = NULL;

	scanf("%d", &Input);
	for(i=1;Input != -1;i++){
		insere_meio(i,Input, &Lista2);
		Lista2->size++;
		scanf("%d", &Input);
	}
	Corrente = Lista2;
	for(;Corrente->next->next != NULL; Corrente = Corrente->next) ;
	Corrente->next = NULL;

	//printf("Lista1->size: %d\n", Lista1->size);
	//printf("Lista2->size: %d\n", Lista2->size);
	//exibe(Lista1);
	//exibe(Lista2);

	if(Lista1->size > Lista2->size){
		printf("nao\n");
		return 0;
	}

	for(;Lista1 != NULL; Lista1 = Lista1->next){
		for(Corrente = Lista2; Corrente != NULL; Corrente = Corrente->next){

			//printf("Lista1->Valor: %d\n", Lista1->Valor);
			//printf("Corrente->Valor: %d\n", Corrente->Valor);
			if(Lista1->Valor == Corrente->Valor && Corrente->Valor != -1){
				Lista1->Valor = -1;
				Corrente->Valor = -1;
				break;
			}
			if(Corrente->next == NULL && Corrente->Valor != Lista1->Valor){
				printf("nao\n");
				return 0;
			}
		}
		//printf("1\n");
	}
/*
	printf("\n");
	exibe(Lista1);
	printf("Lista1->size: %d\n", Lista1->size);
	exibe(Lista2);
	printf("Lista2->size: %d\n", Lista2->size);
*/
	printf("sim\n");

	return 0;
}
