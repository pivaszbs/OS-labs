#include <unistd.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
	for (int i = 0; i < 3; ++i)
	{
		fork();
		sleep(5);
	}

}
