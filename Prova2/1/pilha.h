#ifndef PILHA_H
#define PILHA_H

#define MAX 50
#define TRUE 1
#define FALSE 0

typedef struct {
	int topo;
	int entradas[MAX];
} tipo_pilha;

void inicializa_pilha(tipo_pilha*);
void push(int, tipo_pilha*);
void pop(int*, tipo_pilha*);
int pilha_cheia(tipo_pilha*);
int pilha_vazia(tipo_pilha*);
void func(tipo_pilha*);

#endif
