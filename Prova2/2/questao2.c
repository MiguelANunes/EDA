#include <stdio.h>

#define TAM 10

typedef struct pilha {
	int topo;
	int elementos[TAM];
} pilha;

void inicializa(pilha*);
void push(pilha*, int elem);
void pop(pilha*, int*);
int vazia(pilha*);
int cheia(pilha*);

/* Só o main pode ser alterado neste exercício */

int main() {
	pilha p;
	int op, x;

	inicializa(&p);

	scanf("%d", &op);
	while (op != 5) {
		if (op == 1) {
			scanf("%d", &x);
			if(cheia(&p) != 1){
				push(&p, x);
			}else{
				printf("pilha cheia\n");
				scanf("%d", &op);
				continue;
			}
		}

		if (op == 2) {
			if(vazia(&p) != 1){
				pop(&p, &x);
				printf("%d\n", x);
			}else{
				printf("pilha vazia\n");
				scanf("%d", &op);
				continue;
			}
		}

		scanf("%d", &op);
	}

	return 0;
}

void inicializa(pilha *p) {
	p->topo = -1;
}

void push(pilha *p, int elem) {
	p->topo++;
	p->elementos[p->topo] = elem;
}

void pop(pilha* p, int *x) {
	*x = p->elementos[p->topo];
	p->topo--;
}

int vazia(pilha *p) {
	return p->topo == -1;
}

int cheia(pilha *p) {
	return p->topo == TAM - 1;
}
