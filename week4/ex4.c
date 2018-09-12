#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>

#define MAX_LEN 1024

int main(int argc, char const *argv[])
{
	char* command = malloc(sizeof(char)*MAX_AMOUNT_OF_STRINGS);
	while(1)
	{
		fgets(command, MAX_LEN, stdin);
		system(command);
	}	
	return 0;
}