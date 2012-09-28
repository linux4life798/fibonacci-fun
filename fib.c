/*
 * @author Craig Hesling
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int fib (int x)
{
	if(x <= 2) return 1;
	else return (fib(x-2) + fib(x-1));
}

int main(int argc, char *argv[]) {
	int x = atoi(argv[1]);
	printf("arg is: %d\n", x);
	printf("fib(%d) = %d\n",x,fib(x));
	return 0;
}
