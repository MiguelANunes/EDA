#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
//#include "funcs.h"
#define Size 50

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

void inicializa(pilha *P){
	P->Topo = -1;
}
int main(){

	pilha Primeira;
	inicializa(&Primeira);
	char Separador[Size], L1;
	int i;

	fgets(Separador, Size, stdin);
	for(i=0;Separador[i]!='c';i++){
		push(Separador[i],&Primeira);
	}

	i++;
	for(;Separador[i] != '\n' && !(vazia(&Primeira)); i++){
		pop(&L1,&Primeira);
		if(L1 != Separador[i]){
			printf("NAO ACEITO\n");
			return 0;
		}
	}

	if(i!=strlen(Separador) && vazia(&Primeira)){
		printf("NAO ACEITO\n");
		return 0;
	}

	printf("ACEITO\n");

	return 0;
}
