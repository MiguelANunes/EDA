#include <stdio.h>
#include <stdlib.h>
#include "lista_LSE.h"

int main(){

	char Funcao;
	int Comparador;
	int Input, i, Printou=0;
	Node *Entradas;
	Entradas = cria_node();

	scanf("%c %d", &Funcao, &Comparador);

	scanf("%d", &Input);
	for(i=1; Input != -1 ;i++ , scanf("%d", &Input))
		insere_meio(i,Input, &Entradas);

	if(comprimento(&Entradas) >= 1){

		switch(Funcao){

			case '>':

				for(;Entradas->next != NULL; Entradas = Entradas->next){
					if(Entradas->Valor > Comparador){
						printf("%d ", Entradas->Valor);
						Printou++;
					}
				}

			break;



			case '<':

			for(;Entradas->next != NULL; Entradas = Entradas->next){
				if(Entradas->Valor < Comparador){
					printf("%d ", Entradas->Valor);
					Printou++;
				}
			}

			break;
		}
		if(Printou == 0)
			printf("-1\n");
		else
			printf("\n");
	}else{
		printf("-1\n");
	}

	return 0;
}
