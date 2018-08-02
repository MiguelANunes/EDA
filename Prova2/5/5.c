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

int main(){

	int total, *empilha, *desempilha;
	int i, hold1, hold2, c1=-1, c2=-1; // c1 e c2 são os contadores dos arrays de valores que serão empilhados e desempilhados
	pilha Teste;
	inicializa(&Teste);

	scanf("%d\n", &total);
	empilha = (int*) malloc(total * sizeof(int));
	desempilha = (int*) malloc(total * sizeof(int));

	for(i=0;i<total;i++){

		scanf("%d\n", &hold1);

		if(hold1 == 1){
			c1++;
			scanf("%d\n", &empilha[c1]);
			push(empilha[c1], &Teste);
		}
		else{
			c2++;
			scanf("%d\n", &desempilha[c2]);
			pop(&hold2, &Teste);
			if(hold2 != desempilha[c2]){
				printf("N\n");
				return 0;
			}
		}
	}

	printf("S\n");

	return 0;
}
