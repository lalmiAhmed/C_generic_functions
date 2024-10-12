CC = gcc
CFlags = -Wall


main: main.o
	$(CC) main.o -o main

main.o: src/main.c
	$(CC) -c $< -o $@

clean:
	rm main.o main
