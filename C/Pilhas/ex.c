#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "funcs.h"

int main(){

	pilha Teste;
	inicializa(&Teste);
	carrega(&Teste);
	imprime(&Teste);
	printf("Isso e um Teste\n");
	esvaziar(&Teste);

	return 0;
}
