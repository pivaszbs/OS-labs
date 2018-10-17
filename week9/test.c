#include <stdio.h>
#include <stdlib.h>
#include <signal.h>	
#include <sys/wait.h>
#include <semaphore.h>
#include <memory.h>
int main(int argc, char const *argv[])
{
	unsigned int i = 0;
	i = 1<<31;
	printf("%u\n", i);
	i>>=1;
	i+=1<<31;
	printf("%u\n", i);

	return 0;
}