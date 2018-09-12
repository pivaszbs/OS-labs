#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
	pid_t pid = fork();
	if (pid==0)
	{
		printf("Hello from child PID = %d\n", getpid());
	}
	else
	{
		printf("Hello from parent PID = %d\n", getpid());
	}
}
