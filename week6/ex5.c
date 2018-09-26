#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
int main(int argc, char const *argv[])
{
	pid_t child_pid;
	if ((child_pid = fork()) == 0)
	{
		while(1)
		{
			printf("I am alive\n");
			sleep(1);
		}
	}
	sleep(10);
	kill(child_pid, SIGKILL);
	return 0;
}