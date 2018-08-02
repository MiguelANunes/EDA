all: main

main: ex.c lista.o
	gcc -Wall -o main ex.c lista.o -I.

lista.o: lista.c
	gcc -Wall -c lista.c -I.

run:
	./main

clean:
	rm -f lista.o main
