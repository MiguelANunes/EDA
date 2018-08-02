#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define Size 100

/*
#################################################
# NESTE EXERCÍCIO A PILHA É DO TIPO INT,	    #
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
		//printf("A Pilha esta Vazia\n");
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

void carrega(pilha *P){ // Versão alterada desta função para ler qtd desconhecida de ints
	/*
	int i;
	char Input;
	while((Input = getchar() != '\n')){
		if(cheia(P)){
			break;
		}
		i = Input-'0'; //Convertendo char p/ int
		push(i,P);
	}
	*/
	int Input=0;
	while(Input != -1){
		scanf("%d\n", &Input);
		if(cheia(P)){
			break;
		}
		push(Input,P);
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

	pilha Pesquisa;
	int Procurado, x;
	inicializa(&Pesquisa);
	carrega(&Pesquisa);
	scanf("%d\n", &Procurado);

	while(!(vazia(&Pesquisa))){
		pop(&x,&Pesquisa);
		if(x == Procurado){
			printf("SIM\n");
			return 0;
		}
	}
	printf("NAO\n");

	return 0;
}
