#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#define byte char
#define N 10

int main(int argc, char const *argv[])
{
	int fd1 = open("./ex1.txt", O_RDWR);
	int fd2 = open("./ex1.memcpy.txt", O_RDWR);
	struct stat buf = {};
	fstat(fd1, &buf);
	ftruncate(fd2, buf.st_size);
	void* addr1, *addr2;
	addr1 = mmap(NULL, buf.st_size, PROT_READ, MAP_PRIVATE, fd1, 0);
	addr2 = mmap(NULL, buf.st_size, PROT_WRITE, MAP_PRIVATE, fd2, 0);
	memcpy(addr2, addr1, buf.st_size);
	sync();
	return 0;
}