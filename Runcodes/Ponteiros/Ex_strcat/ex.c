#include <stdlib.h>
#include <stdio.h>

void concatenar(char *string1, char *string2);

int main(){

	char entrada1[20], entrada2[20];
	scanf("%s %s", entrada1, entrada2);
	concatenar(entrada1, entrada2);
	//printf("%s\n", concatenar(entrada1, entrada2));

	return 0;
}

void concatenar(char *string1, char *string2){
	char result[40];
	int i, pos=0;

	for(i=0; i<40; i++)
		result[i] = '\0';

	for(i=0; string1[i]; i++)
		result[i] = string1[i];
	pos = i;

	for(i=0; string2[i]; i++ , pos++)
		result[pos] = string2[i];

	//result[pos+1] = '\0';

	printf("%s\n",result);

	//return *result;
}
