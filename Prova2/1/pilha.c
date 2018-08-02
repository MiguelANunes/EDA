#include "pilha.h"

void inicializa_pilha(tipo_pilha* p) {
	p->topo = -1; 
}

void push(int x, tipo_pilha* p) {
	if (pilha_cheia(p) == FALSE) { 
		p->topo++;
		p->entradas[p->topo] = x;
	}	
} 

void pop(int* x, tipo_pilha* p) {
	if (pilha_vazia(p) == FALSE) {
		*x = p->entradas[p->topo];
		p->topo--;
	}
}

int pilha_cheia(tipo_pilha* p) { 
	return p->topo == MAX-1;
}

int pilha_vazia (tipo_pilha* p) {
	return p->topo == -1;
}

void func(tipo_pilha* p) {
	int i, aux;

	for(i=0; i <= p->topo/2; i++) {
		aux = p->entradas[i];
		p->entradas[i] = p->entradas[p->topo - i];
		p->entradas[p->topo - i] = aux;
	}
}

/* ESPAÇO PARA A RESPOSTA
Ah função func recebe uma pilha como argumento e 
inverte os valores dessa pilha, ou seja,
os valores que estavam no topo da pilha são movidos
para a "base" da pilha, e os que estavam na base da pilha 
são movidos para o topo da pilha.
*/
