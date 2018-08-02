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
		pop(&Saida, P);
		printf("Elemento %d: %c\n",(P->Topo)+1, Saida);
	}
}

void esvaziar(pilha *P){
	char X;
	while(P->Topo >= 0){
		pop(&X, P);
	}
}

bool dentrode(char Ch, char* String){
	int i=0;
	for(;i<=strlen(String);i++){
		if(String[i] == Ch){
			return true;
		}
	}
	return false;
}

int main(){

	pilha Simbolos;
	char Posfixa[Size], Entrada[Size], Operadores[] = "+-*/", Parentese[] = "()";
	char Saida;
	int i, j=-1;

	inicializa(&Simbolos);
	scanf("%s\n", Entrada);

	for(i=0;i<=strlen(Entrada);i++){
		Saida='a';

		if(!(dentrode(Entrada[i], Operadores)) && !(dentrode(Entrada[i], Parentese))){
			j++;
			Posfixa[j] = Entrada[i];
			continue;
		}

		else if(dentrode(Entrada[i], Parentese)){

			if(Entrada[i] == '(' && !(cheia(&Simbolos))){
				push(Entrada[i], &Simbolos);
			}

			else if(Entrada[i] == ')' && !(vazia(&Simbolos))){
				pop(&Saida, &Simbolos);
				while(Saida != '('){
					j++;
					Posfixa[j] = Saida;
					pop(&Saida, &Simbolos);
				}
			}
		}
		else if(dentrode(Entrada[i], Operadores)){
			if(Entrada[i] == '+' || Entrada[i] == '-'){
				pop(&Saida, &Simbolos);
				while(Saida != '('){
					j++;
					Posfixa[j] = Saida;
					pop(&Saida, &Simbolos);
				}
				push(Saida, &Simbolos);
				push(Entrada[i], &Simbolos);
			}

			else if(Entrada[i] == '*' || Entrada[i] == '/'){
				pop(&Saida, &Simbolos);
				while(Saida != '(' && Saida != '+' && Saida != '-'){
					j++;
					Posfixa[j] = Saida;
					pop(&Saida, &Simbolos);
				}
				push(Saida, &Simbolos);
				push(Entrada[i], &Simbolos);
			}

		}
	}
	while(!vazia(&Simbolos)){
		pop(&Saida,&Simbolos);
	}
	j++;
	Posfixa[j] = '\0';

	printf("%s\n", Posfixa);

	return 0;
}
