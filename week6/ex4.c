#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
void sig_handler_killer (int signo) 
{
	printf("What's up dude?\n");
}
void sig_handler_stop (int signo) 
{
	printf("What's up bro?\n");
}
void sig_handler_usr (int signo) 
{
	printf("What's up stuped windows monkey?\n");
}

int main (void) 
{
	signal(SIGSTOP, sig_handler_stop);
	signal(SIGKILL, sig_handler_killer);
	signal(SIGUSR1, sig_handler_usr);
	while (1)
		sleep (10);
	return EXIT_SUCCESS;
}