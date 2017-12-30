#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main() {
	//creat("/home/jkx/myfile.txt", 0644);
	int fd = open("/home/jkx/myfile1.txt", O_RDONLY);
	char a[1024];
	size_t count = read(fd, a, 1024);
	a[count] = '\0';
	//printf("%s\n", a);
	//int fd1 = open("/home/jkx/myfile2.txt", O_RDWR | O_CREAT, 0644);
	int fd1 = open("/home/jkx/myfile2.txt", O_RDWR | O_APPEND, 0644);
	size_t count1 = write(fd1, a, strlen(a));
	
	close(fd);
	close(fd1);
	return 0;


}
