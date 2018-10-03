#include <stdio.h> 
#include <stdlib.h>
int main() {
	char **s = malloc(16*16*sizeof(int));
	char foo[] = "Hello World";
	*s = foo;
	printf("s is %s\n", s[0]);
	s[0] = foo;
	printf("s[0] is %s\n",s[0]);
	return(0);
}