#include <stdio.h>
#include <stdlib.h>

void figure1(int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 2*n-1; ++j)
		{
			if (j<n-i-1||j>n+i-1)
			{
				printf("%c", ' ');
			}
			else
			{
				printf("%c", '*');
			}
		}
		printf("\n");
	}	
}

void figure2(int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 2*n-1; ++j)
		{
			if (i<=(n-1)/2)
			{
				if (j<n-i-1||j>n+i-1)
				{
					printf("%c", ' ');
				}
				else
				{
					printf("%c", '*');
				}
			}
			else 
			{
				if (j<i||j>2*n- i -2)
					printf("%c", ' ');
				else
					printf("%c", '*');
			}
		}
		printf("\n");
	}
}

void figure3(int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 2*n-1; ++j)
		{
			printf("%c", '*');
		}
		printf("\n");
	}
}

int main(int argc, char const *argv[])
{
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);
	switch (m)
	{
		case 1:
			figure1(n);
			break;
		case 2:
			figure2(n);
			break;
		case 3:
			figure3(n);
			break;
	}
	return 0;
}

