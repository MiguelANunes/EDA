#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define Size 100

typedef struct{
	int Topo;
	char Entradas[Size];
}pilha;

pilha copiar(pilha *P){
	pilha P2;
	int i=0;
	P2.Topo = P->Topo;
	for(;i<P2.Topo;i++){
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
/*
void esvaziar(pilha *P){
	char X;
	while(P->Topo >= 0){
		pop(&X, P);
	}
}
*/

int main() {

	pilha Entrada;
	bool Balanceado = true;
	char C, Input[Size];
	int i;
	inicializa(&Entrada);
	fgets(Input, Size, stdin);

	for(i=0;i<Size;i++){

		if(Input[i] == '(' || Input[i] == '['){
			push(Input[i], &Entrada);
		}
		else if((Input[i] == ')' || Input[i] == ']') && !(vazia(&Entrada))){
			pop(&C, &Entrada);
		}
		else if((Input[i] == ')' || Input[i] == ']') && vazia(&Entrada)){
			Balanceado = false;
			break;
		}
	}

	if(vazia(&Entrada) && Balanceado){
		printf("BALANCEAMENTO OK\n");
	}else{
		printf("DESBALANCEADO\n");
	}


	return 0;
}
