all: saida.exe

saida.exe: filas.o ex.o
	gcc -Wall -o saida.exe filas.o ex.o

filas.o: filas.c
	gcc -Wall -c filas.c

ex.o: ex.c
	gcc -Wall -c ex.c

clean:
	rm *.o *.out

run: ./saida.exe
