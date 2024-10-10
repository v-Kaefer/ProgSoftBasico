CC = gcc
CFLAGS = -Wall -I.
LIBS = -lcunit

all: test

test: tests/test_main.c lib_ppm.c
    $(CC) $(CFLAGS) -o test tests/test_main.c lib_ppm.c $(LIBS)

clean:
    rm -f test