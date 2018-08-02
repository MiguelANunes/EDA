#include <stdio.h>
#include <stdlib.h>

int* f_maior(int *A, int *B);

int main(){

	int Var1, Var2, *ptr;

	scanf("%d %d", &Var1, &Var2);
	ptr = f_maior(&Var1, &Var2);

	printf("%d\n",*ptr);

	return 0;
}

int* f_maior(int *A, int *B){

	if(A > B)
		return A;
	else
		return B;

}
