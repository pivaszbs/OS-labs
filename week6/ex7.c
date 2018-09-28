#include <stdio.h>
#include <stdlib.h>
#include <signal.h>	
#include <sys/wait.h>
#include <semaphore.h>
#include <memory.h>
sem_t mutex;
sem_t size;

int create_pipe(int pipefd[2]);
int read(int pipefd, void* buf, size_t count);
int write(int pipefd, void* buf, size_t count);

int create_pipe(int pipefd[2])
{
	sem_init(&mutex, 1, 1);
	sem_init(&size, 1, 0);
	FILE* f1 = fopen("tempo1file.txt", "w");
	pipefd[0] = fileno(f1);
	pipefd[1] = fileno(f1);
}

int read(int pipefd, void* buf, size_t count)
{
	sem_wait(&mutex);
	sem_wait(&size);
	FILE* fd = fdopen(pipefd, "r");
	fgets(buf, count, fd);
	sem_post(&size);
	sem_post(&mutex);
}

int write(int pipefd, void* buf, size_t count)
{
	if (count>0)
	{
		sem_post(&size);
		sem_wait(&mutex);
		FILE* fd = fdopen(pipefd, "w");
		fprintf(fd, "%s", (char*) buf);
		sem_post(&mutex);
		fclose(fd);
	}
	else
	{
		sem_init(&size, 1, 0);	
	}
}

int main(int argc, char const *argv[])
{
	int fd[2];
	char* string = "Hello bro";
	char another_string[10];
	create_pipe(fd);
	write(fd[1], string, strlen(string) + 1);
	printf("dorow");
	read(fd[0], another_string, strlen(string) + 1);
	printf("%s\n", another_string);
	return 0;
}