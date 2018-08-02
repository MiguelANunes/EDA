all: exercicios.exe

exercicios.exe: funcs.o ex.o
	gcc -Wall -o exercicios.exe funcs.o ex.o

funcs.o: funcs.c
	gcc -Wall -c funcs.c

ex.o: ex.c
	gcc -Wall -c ex.c

clean:
	rm funcs.o ex.o exercicios.exe
