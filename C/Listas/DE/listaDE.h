#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct No{
	int Conteudo, Comprimento;
	struct No *Proximo, *Anterior;
};
//Guardo o comprimento da lista
//Na cabeça dela
//Para facilitar minha vida

//Minha implementação terá dois nós
//Especiais, que são a cabeça e a cauda
//Que servirão de guia para operar nessa lista

typedef struct No Node;

Node* cria_node(void);
bool vazia(Node *Header);
void inicializa(Node **Header);
void insere_inicio(int Entrada, Node **Header);
void insere_meio(int Pos, int Entrada, Node **Header);
void insere_final(int Entrada, Node **Header);
void remove_node(int Pos, Node **Header);
void exibe(Node *Header);
void deleta(Node **Header);
