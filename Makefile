CC = gcc
CFLAGS = -Wall

all: main test

main: main.c lib_ppm.h
	$(CC) $(CFLAGS) main.c -o main

test: test_gerar_subpixel.c main.c lib_ppm.h
	$(CC) $(CFLAGS) test_gerar_subpixel.c main.c -o test

clean:
	rm -f main test