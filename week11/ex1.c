#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

#define MAGIC_PHRASE "This is a nice day"
int main(int argc, char const *argv[])
{
	int fd = open("./ex1.txt", O_RDWR);
	struct stat buf = {};
	fstat(fd, &buf);
	char* addr;
	addr = mmap(NULL, buf.st_size, PROT_WRITE, MAP_SHARED, fd, 0);
	memcpy(addr, MAGIC_PHRASE, strlen(MAGIC_PHRASE));
	return 0;
}