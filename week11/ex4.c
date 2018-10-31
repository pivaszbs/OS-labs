#include <stdio.h>
#define byte char
#define N 10
void* memcpy(void* dest, const void* src, size_t n)
{
	byte* s = (byte*)src;
	byte* d = (byte*)dest;
	for (int i = 0; i < n; ++i)
	{
		d[i]=s[i];
	}
	return (void*)d;
}

int main(int argc, char const *argv[])
{
	//Mb someone will read this code and it will make him happy beacouse here I put a lot of comments
	//about my code. I think it will be interesting if you give me 1.99 instead of 2 points for lab.
	//It's not a joke. Just because life is hard thing (c) One real man.
	//It's my array a
	int a[N];
	//It's my array b
	int b[N];
	//here I fill array a with numbers 1,2,3,4,5,6,7,8,9
	for (int i = 0; i < N; ++i)
	{
		a[i] = i;
	}
	//here I copy some bytes from 1 place to another
	memcpy(b,a,sizeof(int)*10);
	//here I show what happend with my second array
	for (int i = 0; i < N; ++i)
	{
		printf("%d\n", b[i]);		
	}
	//Thank you for your attention. I think it was an unforgettable 
	//journey to the country of my code.
	/**
	Anyway, thanks to everyone who read this unforgettable story 
	about how bytes move from one place to another, just because 
	they do not want to sit in one place
	**/
	return 0;
}