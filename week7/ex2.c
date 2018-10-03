#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	int n = atoi(argv[1]);
	int* a = malloc(n*sizeof(int));
	for (int i = 0; i < n; ++i)
		a[i] = i;
	for (int i = 0; i < n; ++i)
		printf("%d ", a[i]);
	free(a);
	return 0;
}