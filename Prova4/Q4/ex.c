#include <stdio.h>
#include <stdlib.h>
#include "lista_LSE.h"

int main(){

	char Operacao;
	int Operando;
	int Input, i;
	Node *Entradas, *Aux;
	Entradas = cria_node();

	scanf("%c %d", &Operacao, &Operando);

	scanf("%d", &Input);
	for(i=1; Input != -1 ;i++ , scanf("%d", &Input))
		insere_meio(i,Input, &Entradas);

	if(comprimento(&Entradas) > 1){

		Aux = Entradas;
		switch(Operacao){

			case '+':

				for(; Entradas->next != NULL ;Entradas = Entradas->next){
					Entradas->Valor += Operando;
				}

			break;


			case '*':

			for(; Entradas->next != NULL ;Entradas = Entradas->next){
				Entradas->Valor *= Operando;
			}

			break;
		}

		exibe(Aux);
	}else{
		printf("-1\n");
	}

	return 0;
}
