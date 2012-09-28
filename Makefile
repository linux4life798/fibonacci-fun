CC = gcc
CFLAGS = -g

.PHONY: clean

all: fib fib-th fib-lin

fib: fib.c
	$(CC) $(CFLAGS) -o fib fib.c
fib-th: fib-th.c
	$(CC) $(CFLAGS) -pthread -o fib-th fib-th.c
fib-lin: fib-lin.c
	$(CC) $(CFLAGS) -o fib-lin fib-lin.c

clean:
	$(RM) fib fib-th fib-lin
