#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define  MAXSIZE 20

int f_posicao(char *str, char *substr);

int main(){

	char String1[MAXSIZE], String2[MAXSIZE];

	scanf("%s %s\n", String1, String2);

	printf("%d\n", f_posicao(String1,String2));

	return 0;
}

int f_posicao(char *String1, char *String2){
	int posicao=-1, i, j, k, l, total=0, size=0;

	for(i=0; isalpha(String2[i]); i++) size++;

	for(i=0; String1[i] != '\0'; i++){
		total=0;
		for(l=0; String2[l] != '\0'; l++){
			if(String1[i] == String2[l]){
				for(j=i , k=l; String1[j] != '\0' && String2[k] != '\0'; j++, k++){
					if(*(String1+j) == *(String2+k)){
						posicao = i;
						total++;
						if(total == size){
							return posicao+1;
						}
					}
				}
			}
		}
	}
	return -1;
}
