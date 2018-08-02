#include<stdio.h>
#include <stdlib.h>

int main(){

	int vtr[2], i=0;

	printf("i=%d\n", i);
	scanf("%d %d", &vtr[i], &vtr[++i]);
	printf("%d %d i=%d\n", vtr[--i], vtr[++i],i);

	return 0;
}
