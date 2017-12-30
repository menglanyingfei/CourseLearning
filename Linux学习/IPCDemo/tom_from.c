#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define WRITE_FILE "writefifo"
#define READ_FILE "readfifo"
#define BUF_SIZE 1024

int main() {
	int wfd, rfd, count;
	char buf[BUF_SIZE];	

	if (mkfifo(WRITE_FILE, 0666)) {
		printf("mkfifo1 fail\n");
		return 1;
	}
	if (mkfifo(READ_FILE, 0666)) {
		printf("mkfifo2 fail\n");
		return 1;
	}
	wfd = open(WRITE_FILE, O_WRONLY);
	rfd = open(READ_FILE, O_RDONLY);
	while(1) {
		printf("tom: ");
		fgets(buf, BUF_SIZE, stdin);
		// huan hang ti huan \0
		buf[strlen(buf) - 1] = '\0';
		write(wfd, buf, BUF_SIZE);
		fflush(stdin);

		count = read(rfd, buf, BUF_SIZE);
		if (count > 0) {
			printf("jerry: %s\n", buf);
			fflush(stdout);
		}
	}

	return 0;
}













