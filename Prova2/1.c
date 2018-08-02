#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define Size 100

typedef struct{
	int Topo;
	char Entradas[Size];
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

void pop(char *X, pilha *P){
	if(vazia(P)){
		//printf("A Pilha esta Vazia\n");
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
	while(P->Topo >= 0){
		pop(&Saida, &P);
		printf("Elemento %d: %c\n",(P->Topo)+1, Saida);
	}
}

void esvaziar(pilha *P){
	char X;
	while(P->Topo >= 0){
		pop(&X, P);
	}
}

int tamanho(pilha *P){
	int T=0, a; //mudar o tipo de "a" para se encaixar com o uso
	while(!(vazia(P))){
		pop(&a,P);
		T++;
	}
	return T;
}

int main(){

	
}
