#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
	int randomData = open("/dev/random", O_RDONLY);
	FILE* output = fopen("ex1.txt", "w+");
	if (randomData < 0)
	{
	    exit(-1);
	}
	else
	{
	    char myRandomData[20];
	    read(randomData, myRandomData, sizeof(myRandomData));
	    fprintf(output, "%s\n", myRandomData);
	    close(randomData);
	}
	return 0;
}