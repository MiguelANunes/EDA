#include <stdio.h>
#include <stdlib.h>

int main(){
	int lin, col, **matriz, multiplo, i, j;

	scanf("%d %d", &lin, &col);
	//matriz = malloc(lin * col * sizeof(int**));
	matriz = malloc(lin * sizeof(int*));
	for(i=0;i<lin;i++)
		matriz[i] = malloc(col * sizeof(int**));

	for(i=0; i<lin; i++){
		for(j=0; j<col; j++){
			scanf("%d", &matriz[i][j]);
		}
	}
	scanf("%d", &multiplo);

	for(i=0; i<lin; i++){
		for(j=0; j<col; j++){
			matriz[i][j] *= multiplo;
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
	return 0;
}
