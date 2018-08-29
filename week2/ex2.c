#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	char* str = str = (char*) malloc(255*sizeof(char));
	scanf("%s", str);
	for (int i = strlen(str); i > 0; --i)
	{
		printf("%c", str[i-1]);
	}
	return 0;
}