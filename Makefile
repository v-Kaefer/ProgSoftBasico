CC = gcc
CFLAGS = -Wall
OBJ_MAIN = main.o lib_ppm.o
OBJ_TEST = test_gerar_subpixel.o lib_ppm.o

all: main test

main: $(OBJ_MAIN)
	$(CC) $(CFLAGS) -o main $(OBJ_MAIN)

test: $(OBJ_TEST)
	$(CC) $(CFLAGS) -o test $(OBJ_TEST)

main.o: main.c lib_ppm.h
	$(CC) $(CFLAGS) -c main.c

lib_ppm.o: lib_ppm.c lib_ppm.h
	$(CC) $(CFLAGS) -c lib_ppm.c

clean:
	rm -f main test *.o