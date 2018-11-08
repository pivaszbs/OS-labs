#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define N 1024

int main(int argc, char const *argv[])
{
	char buffer[N];
	if (argc==1)
	{
		while (fgets(buffer, N, stdin) != NULL)
		{
			printf("%s", buffer);
		}
	}
	else if (argc==2)
	{
		FILE* output = fopen(argv[1], "w");
		while (fgets(buffer, N, stdin) != NULL)
		{
			fprintf(output, "%s\n", buffer);
			printf("%s", buffer);
		}
		fclose(output);
	}
	else
	{
		if (strcmp("-a", argv[1]))
		{
			FILE* output = fopen(argv[2], "a");
			while (fgets(buffer, N, stdin) != NULL)
			{
				fprintf(output, "%s", buffer);
				printf("%s", buffer);
			}
			fclose(output);
		}
		else
			return(-1);
	}
	return 0;
}