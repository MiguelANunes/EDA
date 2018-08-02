#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{			//minha implementação de fila c/ prioridade
    int Cabeca;			//usa um vetor circular bidimensional
    int Cauda;			//em que um dos termos é o conteudo
    int Capacidade;		//e o outro é a chave associada
	int Num_Elementos;
	int **Entradas;		//Entradas[N][0] = Conteudo
}fila_prioritaria;		//Entradas[N][1] = Chave

fila_prioritaria* criar(int size){

	int t;
	fila_prioritaria *Criada = malloc(sizeof(fila_prioritaria));
	Criada->Capacidade = size;
	Criada->Cabeca = -1;
	Criada->Cauda = -1;
	Criada->Num_Elementos = 0;
	Criada->Entradas = malloc(Criada->Capacidade*sizeof(int));
	for(t=0;t<Criada->Capacidade;t++){
		Criada->Entradas[t] = malloc(2*sizeof(int));
	}

	return Criada;
}

bool vazia(fila_prioritaria *F){
	return F -> Cabeca < 0;
}

bool cheia(fila_prioritaria *F){
	if((F -> Cauda + 1) % (F -> Capacidade) == (F -> Cabeca)){
		return true;
	}

	return false;
}

void enqueue(int conteudo, int chave, fila_prioritaria *F){
	if (cheia(F)){
		return;
	}
	else{
		F -> Cauda = ((F->Cauda) + 1) % F -> Capacidade;
		F -> Entradas[F->Cauda][0] = conteudo;
		F -> Entradas[F->Cauda][1] = chave;
		F -> Num_Elementos++;
		if(F-> Cabeca == -1)
			F-> Cabeca = F -> Cauda;
   }
}

void dequeue(fila_prioritaria *F, int *Saida){

	if(vazia(F)){
	  Saida[0] = -999;
	  Saida[1] = -999;
	}

	else{
		Saida[0] = F->Entradas[F->Cabeca][0];
		Saida[1] = F->Entradas[F->Cabeca][1];
		F->Num_Elementos--;
    	if((F->Cabeca) == (F->Cauda)){
    		(F->Cabeca) = (F->Cauda) = -1;
		}
		else{
	    	F->Cabeca = ((F->Cabeca) + 1) % (F->Capacidade);
	    }
    }
}

void deleta(fila_prioritaria *F){
	if(F){
		if(F->Entradas){
			free(F->Entradas);
		}
		free(F);
	}
}

void exibe(fila_prioritaria *F){
    int i;

    if(vazia(F)){
        printf("-1\n");
	}

	else{
		for(i = F->Cabeca; i != F->Cauda+1; i = (i+1) % F->Capacidade){
			printf("%d %d ", F->Entradas[i][0], F->Entradas[i][1]);
		}
		printf("\n");
    }
}

void sort_down(fila_prioritaria *F){		//Este algoritmo de ordenação se chama Gnome Sort
	int pos = F->Cabeca;					//https://en.wikipedia.org/wiki/Gnome_sort
	int holdCont, holdKey;					//É um Insertion Sort (Sort/Ordenação Simples) "mais avançado"
											//Quando um termo não ordenada é encontrado ele é movido até estar ordenado
	while(pos != F->Cauda){					//Porém o algoritmo não reitera por toda a Estrutura, somente até achar um termo ñ ordenado
											//O algoritmo para quando todos os termos são ordenados
		if(F->Entradas[pos][1] <= F->Entradas[(pos+1)%F->Capacidade][1]){
			pos = (pos+1)%F->Capacidade;
		}else{
			holdCont = F->Entradas[pos][0];
			holdKey = F->Entradas[pos][1];

			F->Entradas[pos][0] = F->Entradas[(pos+1)%F->Capacidade][0];
			F->Entradas[pos][1] = F->Entradas[(pos+1)%F->Capacidade][1];

			F->Entradas[(pos+1)%F->Capacidade][0] = holdCont;
			F->Entradas[(pos+1)%F->Capacidade][1] = holdKey;

			pos = pos == F->Cabeca? (pos+1)%F->Capacidade: (pos-1)%F->Capacidade;
		}
	}

}

int main(){

	int Key, Content, Entradas=1;
	int par=1, total=0;
	fila_prioritaria *ParesOrdenados = criar(100);

	while(true){

		if(total%2 == 0 && total != 0){
			enqueue(Content, Key, ParesOrdenados);
		}

		scanf("%d", &Entradas);

		if(Entradas == -1){
			break;
		}

		if(par>0){
			Content = Entradas;
			par *= -1;
			total++;
		}else{
			Key = Entradas;
			par *= -1;
			total++;
		}

	}//while de leitura

	sort_down(ParesOrdenados);
	exibe(ParesOrdenados);

	return 0;
}
