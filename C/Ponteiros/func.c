#include <stdio.h>
#include <stdlib.h>

int f_soma(int A, int B);
int f_fatorial(int X);
int f_somafatorial(int (*soma) (int, int), int (*fatorial) (int), int Y, int X);

int main(){

	int X = 4, Y = 14;
	int (*ptr_soma) (int, int);
	int (*ptr_fatorial) (int);

	ptr_soma = f_soma;
	ptr_fatorial = f_fatorial;

	printf("%d\n", (*ptr_soma) (X,Y));
	printf("%d\n", (*ptr_fatorial) (X));
	printf("%d\n", f_somafatorial(ptr_soma, ptr_fatorial, Y, X));

	return 0;
}

int f_soma(int A, int B){ return A+B; }

int f_fatorial(int X){ return (X == 1)? 1 : X * f_fatorial(X-1); }

int f_somafatorial(int (*soma) (int, int), int (*fatorial) (int), int Y, int X){
	return (*soma)( (*fatorial)(Y), (*fatorial)(X) );
}
