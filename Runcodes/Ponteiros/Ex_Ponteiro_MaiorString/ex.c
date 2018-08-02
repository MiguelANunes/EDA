#include <stdio.h>
#include <stdlib.h>

int main(){
	char s1[100], s2[100];
	int i, j;
	fgets(s1,100,stdin);
	fgets(s2,100,stdin);
	for(i=0; *(s1+i)!= '\0'; i++) ;
	for(j=0; *(s2+j)!= '\0'; j++) ;
	if(i > j)
		printf("%s", s1);
	else
		printf("%s", s2);

	return 0;
}
