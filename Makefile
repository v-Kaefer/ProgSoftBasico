CC = gcc
CFLAGS = -Wall
OBJ_MAIN = main.o lib_ppm.o

all: main

main: $(OBJ_MAIN)
	$(CC) $(CFLAGS) -o main $(OBJ_MAIN)

main.o: main.c lib_ppm.h
	$(CC) $(CFLAGS) -c main.c

lib_ppm.o: lib_ppm.c lib_ppm.h
	$(CC) $(CFLAGS) -c lib_ppm.c

clean:
	rm -f main *.o