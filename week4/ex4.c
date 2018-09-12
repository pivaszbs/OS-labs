#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>

#define MAX_LEN 1024
#define MAX_AMOUNT_OF_STRINGS 16

char* spaces(char* s)
{
    while (*s == ' ') ++s;
    return s;
}

void split(char* cmd, char** args)
{
    cmd = spaces(cmd);
    char* next = strchr(cmd, ' ');
    int i = 0;

    while(next != NULL) {
        next[0] = '\0';
        args[i] = cmd;
        ++i;
        cmd = spaces(next + 1);
        next = strchr(cmd, ' ');
    }

    if (cmd[0] != '\0') {
        args[i] = cmd;
        next = strchr(cmd, '\n');
        next[0] = '\0';
        ++i;
	}

    args[i] = NULL;
}


int main(int argc, char const *argv[])
{
	FILE *fp;
	char* command = malloc(sizeof(char)*MAX_AMOUNT_OF_STRINGS);
	char* arg[MAX_LEN];
	for (int i = 0; i < MAX_LEN; ++i)
	{
		arg[i] = malloc(sizeof(char)*256);
	}
	while (1)
	{
		fgets(command, 1024, stdin);
		split(command, arg);
		execvp(arg[0], arg);
	}
	return 0;
}