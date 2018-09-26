#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

void sig_handler (int signo) 
{
	printf("What's up dude?\n");
}
int main (void) 
{
	signal(SIGINT, sig_handler);
	while (1)
		sleep (10);
	return EXIT_SUCCESS;
}