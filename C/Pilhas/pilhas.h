#ifndef _H_TESTE
#define _H_TESTE

#define Size 50

typedef struct{
	int Topo;
	char Entradas[Size];
}pilha;

pilha copiar(pilha *P);
bool cheia(pilha *P);
bool vazia(pilha *P);
void inicializa(pilha *P);
void carrega(pilha *P);
void imprime(pilha *P);
void esvaziar(pilha *P);
void pop(char *X, pilha *P);
void push(char X, pilha *P);
int tamanho(pilha *P);

#endif
