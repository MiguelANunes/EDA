#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define Size 50

/*
#################################################
# OS NESTE EXERCÍCIO A PILHA É DO TIPO INT		#
# LOGO AS FUNÇÕES TRABALHAM COM INTS, NÃO CHARS #
#################################################
*/

typedef struct{
	int Topo;
	int Entradas[Size];
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

void inicializa(pilha *P){
	P->Topo = -1;
}

void pop(int *X, pilha *P){
	if(vazia(P)){
		printf("A Pilha esta Vazia\n");
		return;
	}
	*X = P->Entradas[P->Topo]; //X recebe o que esta no Topo do array da pilha
	--(P->Topo);
}

void push(int X, pilha *P){
	if(cheia(P)){
		//printf("A Pilha esta Cheia\n");
		return;
	}
	++(P->Topo);
	P->Entradas[P->Topo] = X;
}

void carrega(pilha *P){
	int i=0, Input[Size];
	for(i=0;i<Size;i++){
		scanf("%d\n", &Input[i]);
	}
	for(i=0;i<Size;i++){
		if(cheia(P)){
			break;
		}
		push(Input[i],P);
	}
}

void imprime(pilha *P){
	int Saida;
	pilha P2 = copiar(P);
	while(P2.Topo >= 0){
		pop(&Saida, &P2);
		printf("Elemento %d: %d\n",(P2.Topo)+1, Saida);
	}
}

void esvaziar(pilha *P){
	int X;
	while(P->Topo >= 0){
		pop(&X, P);
	}
}

int tamanho(pilha *P){
	int T=0, a;
	while(!(vazia(P))){
		pop(&a,P);
		T++;
	}
	return T;
}

/* Começando o main */

int main(){

	pilha Numeros;
	char Operacao[Size], Number[Size];
	int Tam, Relevante, Offset, i, j=0;
	inicializa(&Numeros);
	while(true){

		fgets(Operacao, Size, stdin);

		if(Operacao[0] == 'F'){
			break;
		}

		if(Operacao[0] == 'E'){

			Offset = strlen(Operacao) - strlen("EMP ");
			for(i = Offset+1; i < strlen(Operacao)-1; i++){ // Extraindo os Numeros da string de Entrada para empilhar
				Number[j] = Operacao[i];
				j++;
			}

			Relevante = atoi(Number);
			push(Relevante, &Numeros);
			continue;
		}

		if(Operacao[0] == 'D'){
			pop(&Relevante, &Numeros);
			continue;
		}

	}

	Tam = tamanho(&Numeros);
	printf("%d\n", Tam);

	return 0;
}
