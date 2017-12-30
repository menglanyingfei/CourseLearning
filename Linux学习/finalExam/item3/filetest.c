#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main() {
	int fd1 = open("file1.txt", O_RDWR, 0644);
	off_t len = lseek(fd1, 0, SEEK_END);
	lseek(fd1, 0, SEEK_SET);
	char a[1024];
	size_t count = read(fd1, a, len / 2);
	a[count] = '\0';
	
	char b[1024];
	int fd2 = open("file2.txt", O_RDWR, 0644);
	lseek(fd2, 0, SEEK_SET);
	size_t count1 = read(fd2, b, len / 2);
	
	b[count] = '\0';
	
	int fd3 = open("file3.txt", O_RDWR | O_CREAT, 0644);
	size_t count2 = write(fd3, a, len/2);
	write(fd3, b, len/2);

	close(fd1);
	close(fd2);
	close(fd3);
	return 0;
}





