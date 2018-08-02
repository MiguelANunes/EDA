#include <stdio.h>
#include <stdlib.h>

int espacos(char **string, int linhas);

int main(){
	int lin, i;
	char  **matriz;

	scanf("%d\n", &lin);
	matriz = malloc(lin * sizeof(char*));
	for(i=0;i<lin;i++)
		matriz[i] = malloc(60 * sizeof(char));

	for(i=0;i<lin;i++)
		fgets(matriz[i], 60, stdin);

	printf("%d\n", espacos(matriz, lin));

	return 0;
}

int espacos(char **string, int linhas){
	int total=0, i, j;

	for(i=0;i<linhas;i++){
		for(j=0;j<60;j++){
			if(string[i][j] == 32)
				total++;
		}
	}

	return total;
}
