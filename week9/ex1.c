#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0


struct a
{
	int page_num;
	int page_age;
	int R;
	int M;
	//And so on...
} typedef page_t;

void update_age(page_t* a, int referenced_a)
{
	for (int i = 0; i < referenced_a; ++i)
		a[i].page_age += 1<<31;
}

int check_page_in_table(page_t* a, int page_frame, int page_num)
{
	for (int i = 0; i < page_frame; ++i)
		if (a[i].page_num == page_num)
			return true;
	return false;
}

void remove_page(page_t* a, int page_frame)
{
	for (int i = 0; i < page_frame; ++i)
		if (a[i].page_num == 0)
			return;
	int s = 0;
	int min = a[0].page_age;
	for (int i = 1; i < page_frame; ++i)
	{
		if (a[i].page_age < min)
		{
			s = i;
			min = a[i].page_age;
		}
	}
	a[s].page_num = 0;
}

void insert_page(page_t* a, int page_frame, int page_num)
{
	remove_page(a, page_frame);
	for (int i = 0; i < page_frame; ++i)
		if (a[i].page_num == 0)
		{
			a[i].page_num = page_num;
			return;
		}
}

int main(int argc, char const *argv[])
{
	char* filename = "ex2-1.txt";
	int page_frame = atoi(argv[1]);
	page_t* page_list = malloc(page_frame*sizeof(page_t));
	FILE* input_file;
	//read from file
	input_file = fopen(filename, "r");
	if (input_file == NULL)
	{
		perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
	}
	//Calculate size of a number aray
	int k = 0;
	int s = 0;
	while ((fscanf(input_file, "%d",&s)!=EOF)) k++;

	int *c = (int*) malloc(k*sizeof(int)); 
	// restart read from file
	rewind(input_file);
	for(int i=0;i<k;i++)
	    fscanf(input_file, "%d",&c[i]);
	fclose(input_file);

	int hit = 0;
	int miss = 0;
	int referenced_a = 0;
	for (int i = 0; i < k; ++i)
	{
		if (check_page_in_table(page_list, page_frame, c[i]))
		{
			hit++;
			continue;
		}
		miss++;
		insert_page(page_list, page_frame, c[i]);
		if (referenced_a < page_frame)
			referenced_a++;
		update_age(page_list, referenced_a);
	}
	double result = 1.0*hit/miss;
	printf("%f\n", result);
	return 0;
}