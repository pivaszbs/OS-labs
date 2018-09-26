#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>	
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
	pid_t child_pid[2] = {}	;
	int fd[2];
	pipe(fd);
	if ((child_pid[0] = fork()) == 0)
	{
		close(fd[1]);
		read(fd[1], &child_pid[1], sizeof(child_pid[1]));
		kill(child_pid[1], SIGKILL);
	}
	else
	{
		if ((child_pid[1] = fork()) == 0)
		{
			while(1)
				sleep(1);
		}
		else
		{
			close(fd[0]);
			write(fd[0], &child_pid[1], sizeof(child_pid[1]));
			wait(NULL);
		}
	}
	return 0;
}