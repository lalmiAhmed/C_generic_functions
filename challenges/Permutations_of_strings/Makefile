CC = gcc
CFlags = -Wall


code: code.o
	$(CC) code.o -o code 

code.o: src/code.c
	$(CC) -c $< -o $@

clean:
	rm code *.o
