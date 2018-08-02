#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int Cabeca;
    int Cauda;
    int Capacidade;
	int Num_Elementos;
	int *Entradas;
}fila;

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
	  return -999;
	}

	else{
		Saida = F->Entradas[F->Cabeca];
		F->Num_Elementos--;
    	if((F->Cabeca) == (F->Cauda)){
    		(F->Cabeca) = (F->Cauda) = -1;
		}
		else{
	    	F->Cabeca = ((F->Cabeca) + 1) % (F->Capacidade);
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
        printf("-1\n");
	}

	else{
		for(i = F->Cabeca; i != F->Cauda+1; i = (i+1) % F->Capacidade){
			if(F->Entradas[i] != 0)
				printf("%d ", F->Entradas[i]);
		}
		printf("\n");
    }
}


int main(){

	int Tamanho, QtdElementos, Termo, Furao;
	scanf("%d %d %d",&Tamanho, &Furao, &QtdElementos);
	fila *Furada = criar(Tamanho);
	Furada->Num_Elementos = QtdElementos;
	int i;

	for(i=0;i<QtdElementos;i++){
		scanf("%d", &Termo);
		enqueue(Termo, Furada);
	}

	for(i = Furada->Cauda; i != Furada->Cabeca-1; i = (i-1)%Furada->Capacidade){
		Furada->Entradas[(i+1)%Furada->Capacidade] = Furada->Entradas[i];
		Furada->Entradas[i] = Furada->Entradas[(i+1)%Furada->Capacidade];
	}
	Furada->Cauda++;
	Furada->Entradas[Furada->Cabeca] = Furao;

	exibe(Furada);

	return 0;
}
