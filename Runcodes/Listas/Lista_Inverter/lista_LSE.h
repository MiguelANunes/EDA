#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct No{
    int  Valor;
    struct No *next;
};

typedef struct No Node;

Node* cria_node(void);
bool vazia(Node **L);
bool ultimo(Node *L);
void exibe(Node *L);
void deleta(Node **L);
void insere_inicio(int entrada, Node **L);
void insere_meio(int size, int entrada, Node **L);
void insere_final(int entrada, Node **L);
bool exclui_meio(int size, Node **L);
bool exclui_ultimo(Node **header_L);
int comprimento(Node **L);
