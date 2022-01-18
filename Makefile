CC=clang
CFLAGS= -Wall -O2 -g -I include

EXEC=bst
OBJ=$(SRC:src/%.c=bin/%.o)
SRC=$(wildcard src/*.c)

all: bin bst test

test: $(filter-out bin/main.o, $(OBJ))
	$(CC) -o $@ $^

bst: $(filter-out bin/test.o, $(OBJ))
	$(CC) -o $@ $^

bin/%.o: src/%.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf bin/*.o bst test
