#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[])
{

	void* a[10];
	for (int i = 0; i < 10; ++i)
	{
		a[i] = malloc(10000000);
		memset(a[i], 0, 10000000);
		sleep(1);
	}
	return 0;
}