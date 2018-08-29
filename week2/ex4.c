#include <stdlib.h>
#include <stdio.h>

void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

int main(int argc, char const *argv[])
{
	int a, b;
	scanf("%d %d", &a, &b);
	swap(&a,&b);
	printf("%d %d", a, b);
	return 0;
}