#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main() {
	//int fd = open("/home/jkx/file.txt", O_RDWR, 0644);
	int fd = open("file.txt", O_RDWR, 0644);
	off_t len = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);

	char a[1024];
	size_t count = read(fd, a, len / 3);

	a[count] = '\0';
	//printf("%s\n", a);
	//int fd1 = open("/home/jkx/myfile2.txt", O_RDWR | O_CREAT, 0644);
	//int fd1 = open("/home/jkx/file1.txt", O_RDWR | O_CREAT, 0644);
	int fd1 = open("file1.txt", O_RDWR | O_CREAT, 0644);
	//read(fd, a, len / 3);
	//a[count] = '\0';
	size_t count1 = write(fd1, a, len / 3);
	
	int fd2 = open("file2.txt", O_RDWR | O_CREAT, 0644);
	read(fd, a, len / 3);
	a[count] = '\0';
	size_t count2 = write(fd2, a, len / 3);

    read(fd, a, len / 3);
	a[count] = '\0';
	int fd3 = open("file3.txt", O_RDWR | O_CREAT, 0644);
	size_t count3 = write(fd3, a, len / 3);

	close(fd);
	close(fd1);
	close(fd2);
	close(fd3);
	return 0;


}
