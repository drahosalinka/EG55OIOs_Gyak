#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void main() {
	int fd;
	fd = open(O_RDWR);
	write(fd);
	read(fd);
	lseek(fd);
}

