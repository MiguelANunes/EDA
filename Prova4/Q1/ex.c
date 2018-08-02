#include <stdio.h>
#include <stdlib.h>
#include "lista_LSE.h"

Node* maior_index(Node **Cabeca);

int main(){

	int Input, i;
	Node *Lista, *Maiores;
	Lista = cria_node();

	scanf("%d", &Input);
	for(i=1; Input != -1; i++){
		insere_meio(i, Input, &Lista);
		scanf("%d", &Input);
	}

	if(!vazia(Lista)){
		Maiores = maior_index(&Lista);
		exibe(Maiores);
	}else{
		printf("-1\n");
	}

	return 0;
}

Node* maior_index(Node **Cabeca){

	Node *Corrente, *Resultado;
	int *Maior, *Index, i, len , j;
	len = comprimento(&*Cabeca);
	Maior = malloc(len*sizeof(int));
	Index = malloc(len*sizeof(int));
	Resultado = cria_node();

	for(i=0;i<len;i++){
		Maior[i] = -1;
		Index[i] = -1;
	}

	for(Corrente = (*Cabeca) , i = 1 , j=0; Corrente->next != NULL; Corrente = Corrente->next , i++){

		if(Corrente->Valor > Maior[j]){
			Maior[j] = Corrente->Valor;
			Index[j] = i;
		}else if(Corrente->Valor == Maior[j]){
			j++;
			Maior[j] = Corrente->Valor;
			Index[j] = i;
			j++;
		}
	}

	for(i=1, j=0;j<len;i++, j++){
		if(Index[j] != -1){
			insere_meio(i,Index[j], &Resultado);
		}
	}

	return Resultado;
}
