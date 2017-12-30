#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define READ_FILE "writefifo"
#define WRITE_FILE "readfifo"
#define BUF_SIZE 1024

int main() {
	int rfd, wfd, count;
	char buf[BUF_SIZE];	

	rfd = open(READ_FILE, O_RDONLY);
	wfd = open(WRITE_FILE, O_WRONLY);

	while (1) {
		count = read(rfd, buf, BUF_SIZE);
		if (count > 0) {
			printf("tom: %s\n", buf);
			fflush(stdout);
		}
		
		printf("jerry: ");
		fgets(buf, BUF_SIZE, stdin);
		// huan hang ti huan \0
		buf[strlen(buf) - 1] = '\0';
		write(wfd, buf, BUF_SIZE);
		fflush(stdin);
	}
	return 0;
}






