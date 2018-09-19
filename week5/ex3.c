#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <pthread.h>
#include <unistd.h>

#define N 100
#define TRUE 1

int count = 1;
int buffer[N];
int turn = 0;

void sleep_prog();
void* producer(void*);
void* consumer(void*);

void sleep_prog()
{
	int var = turn;
	while (var==turn)
	{
		//Here we do some stuff like smoking weeds
	}
}

void wakeup(void *fun())
{
	turn = 1 - turn;
	fun();
}


void* producer(void* arg)
{
	int item;
	while (TRUE) 
	{
		if (count == N) sleep_prog();
		count++;	
		if (count == 1) wakeup(consumer);
	}
}

void* consumer(void* arg)
{
	int item;
	while (TRUE) 
	{
		if (count == 0) sleep_prog();
		count--;
		if (count == N-1) wakeup(producer);
	}
}

int main(int argc, char const *argv[])
{
	pthread_t prod;
	pthread_t cons;
	pthread_create(&prod, NULL, producer, NULL);
	pthread_create(&cons, NULL, consumer, NULL);
	while(1)
	{
		printf("%d\n", count);
		sleep(60);
	}	
	pthread_join(cons, NULL);
	return 0;
}
