#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define Size 50

typedef struct{
	int Topo;
	int Entradas[Size];
}pilha;

bool cheia(pilha *P){
	return(P->Topo >= Size-1);
}

bool vazia(pilha *P){
	return(P->Topo < 0);
}

void inicializa(pilha *P){
	P->Topo = -1;
}

void pop(int *X, pilha *P){
	if(vazia(P)){
		return;
	}
	*X = P->Entradas[P->Topo];
	--(P->Topo);
}

void push(int X, pilha *P){
	if(cheia(P)){
		return;
	}
	++(P->Topo);
	P->Entradas[P->Topo] = X;
}

void esvaziar(pilha *P){
	int X;
	while(P->Topo >= 0){
		pop(&X, P);
	}
}

void top(int *elemento, pilha *P){
	*elemento = P->Entradas[P->Topo];
}

/* Começando o main */

int main(){

	int operacao, empilha, desempilha, topoPilha;
	pilha Check;
	inicializa(&Check);

	scanf("%d\n", &operacao);
	while(operacao != 5){

		if(operacao == 1){
			scanf("%d\n", &empilha);
			if(!(cheia(&Check))){
				push(empilha, &Check);
			}
		}

		if(operacao == 2){
			if(!(vazia(&Check))){
				pop(&desempilha, &Check);
			}else{
				printf("pilha vazia\n");
			}
		}

		if(operacao == 3){ // topo
			if(!(vazia(&Check))){
				top(&topoPilha, &Check);
				printf("%d\n", topoPilha);
			}else{
				printf("pilha vazia\n");
			}
		}

		if(operacao == 4){
			esvaziar(&Check);
		}

		scanf("%d\n", &operacao);
	}

	return 0;
}
