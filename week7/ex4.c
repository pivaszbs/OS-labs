#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* realloc(void* ptr, size_t size)
{

	void* new_p = malloc(size);
	memcpy(new_p, ptr, size);
	free(ptr);
	return new_p;
}


int main(int argc, char const *argv[])
{
	int* a = malloc(16*sizeof(int));
	for (int i = 0; i < 16; ++i)
	{
		a[i] = 100;
	}
	a = realloc(a, 8*sizeof(int));
	for (int i = 0; i < 8; ++i)
		printf("%d ", a[i]);
	return 0;
}