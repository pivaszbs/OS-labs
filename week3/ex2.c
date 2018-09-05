#include <stdlib.h>
#include <stdio.h>

void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void bubble_sort(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n - 1; ++j)
		{
			if (a[j]>a[j+1])
			{
				swap(&a[j], &a[j+1]);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int a [10] = {0};
	for (int i = 0; i < 10; ++i)
	{
		a[i] = 10-i;
	}
	bubble_sort(a, 10);
	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", a[i]);
	}
	return 0;
}