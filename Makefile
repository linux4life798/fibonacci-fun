CC = gcc
CFLAGS = -g

.PHONY: fib.sh clean

all: fib fib-th fib-lin fib.sh fib_go fib_go-th

fib: fib.c
	$(CC) $(CFLAGS) -o fib fib.c
fib-th: fib-th.c
	$(CC) $(CFLAGS) -pthread -o fib-th fib-th.c
fib-lin: fib-lin.c
	$(CC) $(CFLAGS) -o fib-lin fib-lin.c
fib.sh:
	chmod +x fib.sh
fib_go: fib_go.go
	go build fib_go.go
fib_go-th: fib_go-th.go
	go build fib_go-th.go

clean:
	$(RM) fib fib-th fib-lin fib_go fib_go-th
	chmod -x fib.sh # for the sake default states
