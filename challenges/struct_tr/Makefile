CC = gcc
CFlags = -Wall
CLibs = -lm

code: code.o
	$(CC) code.o -o code $(CLibs)

code.o: src/code.c
	$(CC) -c $< -o $@ $(CLibs)

clean:
	rm code *.o
