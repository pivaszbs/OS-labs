#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	int fd[2];
	char* string = "Hello bro";
	char another_string[10];
	pipe(fd);
	write(fd[1], string, strlen(string) + 1);
	read(fd[0], another_string, sizeof(another_string));
	printf("%s\n", another_string);
	return 0;
}