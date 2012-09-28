/*
 * @author Craig Hesling
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <pthread.h>

//#define DEBUG

#ifdef DEBUG
	#define dprintf(format, ...) printf(format, ##__VA_ARGS__)
#else
	#define dprintf(format, ...) ((void)0)
#endif

int fib(int);
int fib_base(int);
void *fib_th1(void *);
void *fib_th2(void *);

struct th{
	pthread_t th;
	int x;
	int y;
};

int fib_base(int x)
{
	if(x <= 2) return 1;
	else return (fib_base(x-2) + fib_base(x-1));
}

void *fib_th1(void *arg)
{
	struct th *th = (struct th *)arg;
	dprintf("fib_th: th->x = %d, th->y = %d\n",th->x, th->y);
	th->y = fib(th->x);
	return ((void *) (0)) ;
}
void *fib_th2(void *arg)
{
	struct th *th = (struct th *)arg;
	dprintf("fib_th: th->x = %d, th->y = %d\n",th->x, th->y);
	th->y = fib_base(th->x);
	return ((void *) (0)) ;
}

int fib (int x)
{
	dprintf("fib(%d): started\n",x);
	if(x <= 2) return 1;
	else
	{
		struct th th1, th2;
		th1.x = (x-2);
		th2.x = (x-1);
		th1.y = th2.y = 0;

		pthread_create(&th1.th, NULL, fib_th2, (void *)(&th1));
		pthread_create(&th2.th, NULL, fib_th2, (void *)(&th2));

		pthread_join(th1.th, NULL);
		pthread_join(th2.th, NULL);
		return (th1.y + th2.y);
	}
}

int main(int argc, char *argv[]) {
	int x = atoi(argv[1]), y;
	printf("arg is: %d\n", x);
	y = fib(x);
	printf("master fib(%d) = %d\n",x, y);
	return 0;
}