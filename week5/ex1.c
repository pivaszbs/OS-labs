#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <pthread.h>
#define N 100

void* print_something(void* varg)
{
	printf("Hello from thread iteration = %d\n", *(int*)varg);
}

int main(int argc, char const *argv[])
{
	int x;
	for (int i = 0; i < N; ++i)
	{
		x = i;
		pthread_t thread;
		pthread_create(&thread, NULL, print_something, &x);
	}
	return 0;
}
/*
int main(int argc, char const *argv[])
{
	int x;
	for (int i = 0; i < N; ++i)
	{
		x = i;
		pthread_t thread;
		pthread_create(&thread, NULL, print_something, &x);
	}
	return 0;
}
*/