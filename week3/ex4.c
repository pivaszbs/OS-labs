#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

void print_arr(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

int partition(int* a, int start, int end)
{
	int pivot = a[end];
	int i = start;
	for (int j = start; j < end; j++)
	{
		if (a[j]<pivot)
		{
			swap(&a[i], &a[j]);
			i++;
		}
	}
	swap(&a[i], &a[end]);
	return i;
}

void quicksort_helper(int* a, int start, int end)
{
	if (start<end)
	{
		int p = partition(a, start, end);
		quicksort_helper(a, 0, p-1);
		quicksort_helper(a, p+1, end);
	}
}

void quicksort (int* a, int n)
{
	quicksort_helper(a,0,n-1);
}



int main(int argc, char const *argv[])
{
	int* a = malloc(sizeof(int)*20);
	srand(time(NULL));
	for (int i = 0; i < 20; ++i)
	{
		a[i] = rand();
	}		
	quicksort(a, 20);
	print_arr(a, 20);
	return 0;
}