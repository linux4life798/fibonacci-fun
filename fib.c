/*
 * @author Craig Hesling
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <limits.h>
#include <assert.h>

/* uintmax_t has a max value of UINTMAX_MAX */
typedef uintmax_t fibnum;

fibnum fib (int x)
{
	if(x <= 2) return 1;
	else return (fib(x-2) + fib(x-1));
}

int main(int argc, char *argv[]) {
	int x = atoi(argv[1]);
	printf("arg is: %d\n", x);
	printf("fib(%d) = %"PRIuMAX"\n",x,fib(x));
	return 0;
}
