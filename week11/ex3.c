#include <stdio.h>
#include <unistd.h>
int main(void) {	
	printf("Hello world\n");
	sleep(10);
	fork();
	printf("\n");
	return 0;
}