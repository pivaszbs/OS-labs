#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
	char *command = malloc(sizeof(char)*1024);
	while (1)
	{
		scanf("%s", command);
		system(command);
	}
	return 0;
}