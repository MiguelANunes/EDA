#include <stdio.h>
#include <stdlib.h>

int main(){
	int lin, col, i, j, **matriz, maior = -9999;

	scanf("%d %d", &lin, &col);
	matriz = malloc(lin * sizeof(int*));

	for(i=0;i<lin;i++)
		matriz[i] = malloc(col * sizeof(int));

	for(i=0;i<lin;i++)
		for(j=0;j<col;j++)
			scanf("%d", &matriz[i][j]);

	for(i=0;i<lin;i++)
		for(j=0;j<col;j++)
			if(matriz[i][j] >= maior)
				maior = matriz[i][j];

	printf("%d\n", maior);

	return 0;
}
