#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define Size 50

typedef struct{
	int Topo;
	char Entradas[Size];
}pilha;

pilha copiar(pilha *P){
	pilha P2;
	int i=0;
	P2.Topo = P->Topo;
	for(;i<P->Topo;i++){
		P2.Entradas[i] = P->Entradas[i];
	}
	return P2;
}

bool cheia(pilha *P){
	return(P->Topo >= Size-1);
}

bool vazia(pilha *P){
	return(P->Topo < 0);
}

void pop(char *X, pilha *P){
	if(vazia(P)){
		printf("A Pilha esta Vazia\n");
		return;
	}
	*X = P->Entradas[P->Topo]; //X recebe o que esta no Topo do array da pilha
	--(P->Topo);
}

void push(char X, pilha *P){
	if(cheia(P)){
		//printf("A Pilha esta Cheia\n");
		return;
	}
	++(P->Topo);
	P->Entradas[P->Topo] = X;
}

void inicializa(pilha *P){
	P->Topo = -1;
}

void carrega(pilha *P){
	char Input[Size];
	int i=0;
	fgets(Input, Size, stdin);
	for(;Input[i]!='\0';i++){
		if(cheia(P)){
			break;
		}
		push(Input[i],P);
	}
}

void imprime(pilha *P){
	char Saida;
	pilha P2 = copiar(P);
	while(P2.Topo >= 0){
		pop(&Saida, &P2);
		printf("Elemento %d: %c\n",(P2.Topo)+1, Saida);
	}
}

void esvaziar(pilha *P){
	char X;
	while(P->Topo >= 0){
		pop(&X, P);
	}
}
