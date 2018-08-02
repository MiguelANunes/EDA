#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct No{
	int Conteudo, Comprimento;
	struct No *Proximo;
};
//Guardo o comprimento da lista
//Na cabeça dela
//Para facilitar minha vida
typedef struct No Node;

Node* cria_node(void);
bool vazia(Node *Header);
void insere_inicio(int Entrada, Node **Header);
void insere_meio(int Pos, int Entrada, Node **Header);
void insere_final(int Entrada, Node **Header);
void remove_node(int Pos, Node **Header);
void exibe(Node *Header);
void deleta(Node **Header);
