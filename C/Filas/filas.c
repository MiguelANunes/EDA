#include <stdlib.h>
#include <stdio.h>
#include "funcs.h"

fila* criar(int size){

	fila *Criada = malloc(sizeof(fila));
	Criada -> Capacidade = size;
	Criada -> Cabeca = -1;
	Criada -> Cauda = -1;
	Criada -> Num_Elementos = 0;
	Criada -> Entradas = malloc(Criada -> Capacidade * sizeof(int));

	return Criada;
}

bool vazia(fila *F){
	return F -> Cabeca < 0;
}

bool cheia(fila *F){
	if((F -> Cauda + 1) % (F -> Capacidade) == (F -> Cabeca)){
		return true;
	}

	return false;
}

void enqueue(int x, fila *F){
	if (cheia(F)){
		return;
	}
	else{
		F -> Cauda = ((F->Cauda) + 1) % F -> Capacidade;
		F -> Entradas[F->Cauda] = x;
		F -> Num_Elementos++;
		if(F-> Cabeca == -1)
			F-> Cabeca = F -> Cauda;
   }
}

int dequeue(fila *F){
	int Saida;

	if(vazia(F)){
	  return '\0';
	}

	else{
		Saida = F -> Entradas[F->Cabeca];
		F -> Num_Elementos--;
    	if((F -> Cabeca) == (F -> Cauda)){
    		(F -> Cabeca) = (F -> Cauda) = -1;
		}
		else{
	    	F -> Cabeca = ((F -> Cabeca) + 1) % (F -> Capacidade);
	    }
      return Saida;
    }
}

void deleta(fila *F){
	if(F){
		if(F->Entradas){
			free(F->Entradas);
		}
		free(F);
	}
}

void exibe(fila *F){
    int i;

    if(vazia(F)){
        printf("Fila Vazia\n");
	}

	else{
		printf("Estado da Fila:\n");
		printf("Posicao Cabeca: %d\n", F -> Cabeca);
		printf("Posicao Cauda: %d\n", F-> Cauda);
		printf("Coteudo: ");
		for(i = F ->Cabeca; i != F -> Cauda; i = (i+1) % F->Capacidade){
			printf("%d ", F->Entradas[i]);
		}
		printf("%d ", F->Entradas[i]);
		printf("\n");
    }
}
