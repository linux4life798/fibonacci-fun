CC = gcc
CFLAGS = -g

.PHONY: fib.sh clean

all: fib fib-th fib-lin fib.sh

fib: fib.c
	$(CC) $(CFLAGS) -o fib fib.c
fib-th: fib-th.c
	$(CC) $(CFLAGS) -pthread -o fib-th fib-th.c
fib-lin: fib-lin.c
	$(CC) $(CFLAGS) -o fib-lin fib-lin.c
fib.sh:
	chmod +x fib.sh

clean:
	$(RM) fib fib-th fib-lin
	chmod -x fib.sh # for the sake default states
