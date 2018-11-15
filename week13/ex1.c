#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define TRUE 1
#define FALSE 0

void read_line(int* a,char* line,int m)
{
	for (int i = 0; i < m; ++i)
	{
		sscanf(line,"%d", &a[i]);
		line+=2;
	}
}

int compare(int* a, int* b, int m)
{
	for (int i = 0; i < m; ++i)
	{
		if (a[i]<b[i])
			return FALSE;
	}
	return TRUE;
}

void add(int* a, int* b, int m)
{
	for (int i = 0; i < m; ++i)
	{
		a[i]+=b[i];
	}
}

void algo(int* p, int** r, int** c, int* a, int n, int m)
{
	int counter = 0;
	int dead_counter = 0;
	int i = 0;
	FILE* f = fopen("input.txt", "r");
	FILE* f_i_ok = fopen("input_ok.txt", "a");
	FILE* f_i_dl = fopen("input_dl.txt", "a");
	FILE* f_o_ok = fopen("output_ok.txt", "a");
	FILE* f_o_dl = fopen("output_dl.txt", "a");
	char ch;
	fseek(f, 0L, SEEK_END); // file pointer at end of file
	int pos = ftell(f);
	fseek(f, 0L, SEEK_SET); // file pointer set at start
	while(counter!=n)
	{
		if (p[i] == FALSE)
		{
			if(compare(r[i],a,m))
			{
				add(c[i], a,m);
				p[i] = TRUE;
				counter++;
				dead_counter = 0;
			}
			dead_counter++;
		}
		if (dead_counter>=n)
			break;
		i++;
		if (i>=n)
			i = 0;
	}
	if (dead_counter<n)
	{
		fprintf(f_o_ok, "No deadlock\n");
		while (pos--)
		{
		    ch = fgetc(f);  // copying file character by character
		    fputc(ch, f_i_ok);
		}
		fprintf(f_i_ok, "\n");    
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			if (p[i] == FALSE)
			{
				fprintf(f_o_dl, "%d ", i);
			}
		}
		fprintf(f_o_dl, "\n");
		while (pos--)
		{
		    ch = fgetc(f);  // copying file character by character
		    fputc(ch, f_i_dl);
		}    
		fprintf(f_i_dl, "\n");
	}
}

int main(int argc, char const *argv[])
{
	FILE* f = fopen("input.txt", "r");
	char *line = NULL;
	size_t len = 0;
    ssize_t nread;
	nread = getline(&line, &len, f);
	int m = (int) nread/2;
	int* e = malloc(sizeof(int)*m);
	read_line(e,line,m);
	int* a = malloc(sizeof(int)*m);
	fgetc(f);
	fgetc(f);	
	getline(&line, &len, f);
	read_line(a,line,m);
	fgetc(f);
	fgetc(f);	
	int** c, **r;
	getline(&line, &len, f);
	int n = 0;
	c = malloc(sizeof(int));
	c[0] = malloc(sizeof(int)*m);
	while (line[0]!='\n')
	{
		c[n] = malloc(sizeof(int)*m);
		read_line(c[n],line,m);
		getline(&line, &len, f);
		n++;
	}
	n = 0;
	fgetc(f);
	r = malloc(sizeof(int));
	r[0] = malloc(sizeof(int)*m);
	getline(&line, &len, f);
	int error = 0;
	while (line[0]!='\n'&&error!=-1)
	{
		r[n] = malloc(sizeof(int)*m);
		read_line(r[n],line,m);
		error = getline(&line, &len, f);
		n++;
	}
	int* p = malloc(sizeof(int)*n);
	algo(p,r,c,a,n,m);
	free(p);
	for (int i = 0; i < n; ++i)
	{
		free(r[i]);
		free(c[i]);
	}
	free(a);
}