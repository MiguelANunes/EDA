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

fila* criar(int size);
bool cheia(fila *F);
bool vazia(fila *F);
void enqueue(int x, fila *F);
int dequeue(fila *F);
void deleta(fila *F);
void exibe(fila *F );
