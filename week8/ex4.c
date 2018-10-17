#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/resource.h>

int main(int argc, char const *argv[])
{

	void* a[10];
	struct rusage usage;
	for (int i = 0; i < 10; ++i)
	{
		a[i] = malloc(10000000);
		memset(a[i], 0, 10000000);
		getrusage(RUSAGE_SELF, &usage);
		printf("%ld\n", usage.ru_maxrss);
		sleep(1);
	}

	return 0;
}