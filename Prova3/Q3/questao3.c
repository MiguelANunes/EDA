#include <stdio.h>
#include <stdlib.h>

typedef struct struct_processo {
	int id;
	int t_proc;
} processo;

typedef struct struct_fila {
    int front;
    int back;
    int capacidade;
    int tam;
	processo *entrada;
} fila;

fila* cria_fila(int);
int fila_cheia(fila*);
int fila_vazia(fila*);
int tamanho_fila(fila*);
void chegada(processo, fila*);
processo partida(fila*);
void destroi_fila(fila*);

// Alterar apenas o main
int main(){

	int Total, i;
	processo Input, Remocao;

	scanf("%d", &Total);
	fila *Execucoes = cria_fila(Total);

	for(i=0;i<Total;i++){
		scanf("%d %d", &Input.id, &Input.t_proc);
		chegada(Input, Execucoes);
		//printf("id=%d t=%d\n",Execucoes->entrada[i].id, Execucoes->entrada[i].t_proc);
	}// possivel bug aqui
	//quando faço o input de alguns casos de teste fornecidos pelo professor com este print acima comentado
	//alguma coisa acontece que faz com que os valores do ultimo item do input sejam "corrompidos" (pelo menos isso ocorre na minha maquina)
	//no caso do arquivo 1.in, o item 4 1 se torna 1041 0 (na minha maquina)
	//não sei se é possível replicar isso fora da minha maquina
	//o run.codes deu erro em 3 casos de 5 nesse exercicio
	//sendo que os 3 casos dados pelo professor davam a saida correta na minha maquina com esse print
	while(!(fila_vazia(Execucoes))){
		for(i=Execucoes->front; i!=(Execucoes->back)+1; i=(i+1)%Execucoes->capacidade){

			if(Execucoes->entrada[i].t_proc == 1 && Execucoes->entrada[i].id != -1){
				printf("%d finalizado\n", Execucoes->entrada[i].id);
				Remocao = partida(Execucoes);
				Remocao.id--;
				Execucoes->entrada[i].id = -1;
				continue;
			}
			else{
				Execucoes->entrada[i].t_proc--;
				if(Execucoes->entrada[i].id != -1)
					printf("%d\n", Execucoes->entrada[i].id);
				continue;
			}
		}
	}

	return 0;
}

fila* cria_fila(int capacidade) {
	fila* f = (fila*) malloc(sizeof(fila));

	f->capacidade = capacidade;
	f->front = -1;
	f->back = -1;
	f->tam = 0;
	f->entrada = malloc(capacidade * sizeof(int));

	return f;
}

int fila_vazia(fila *f) {
	return f->tam == 0;
}

int fila_cheia(fila* f) {
	return f->tam == f->capacidade;
}

int tamanho_fila(fila* f) {
	return f->tam;
}

void chegada(processo x, fila* f) {
	if (!fila_cheia(f)) {
		f->back++;
		if (f->back == f->capacidade) {
			f->back = 0;
		}

		f->entrada[f->back] = x;

		if (fila_vazia(f)) {
			f->front = f->back;
		}

		f->tam++;
	}

}

processo partida(fila* f) {
	processo retorno;

	if (!fila_vazia(f)) {
		retorno = f->entrada[f->front];

		if((f->front) == (f->back)) {
			(f->front) = (f->back) = -1;
		}

		else {
			f->front++;
			if (f->front == f->capacidade) {
				f->front = 0;
			}
		}
		f->tam--;
	}

	return retorno;
}

void destroi_fila(fila *f) {
	if (f) {
		if (f->entrada) {
			free(f->entrada);
		}

		free(f);
	}
}
