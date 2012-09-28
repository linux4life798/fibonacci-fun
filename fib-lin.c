/*
 * @author Craig Hesling
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

long fib (long x)
{
	if(x <= 2) return 1;
	else {
		long y1 = 1, y2 = 1;
		for(;x > 2; x--){
			long tmp = y2;
			y2 += y1;
			y1 = tmp;
		}
		return y2;
	}
}

int main(int argc, char *argv[]) {
	int x = atoi(argv[1]);
	printf("arg is: %d\n", x);
	printf("fib(%d) = %ld\n",x,fib((long)x));
	return 0;
}
