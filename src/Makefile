CFLAGS=-g -O3

all: main

#build
main: main.o
	cc -o main main.o $(CFLAGS)

tester.o: tester.c tokenizer.h history.h
	cc -c main.c $(CFLAGS)

clean:
	rm -f *.o main

