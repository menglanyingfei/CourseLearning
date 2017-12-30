#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void main() {
	pid_t pid;
	int i;
	int count=0;
	int fd[2];
	char buf[100];
	pipe(fd);
	pid = fork();
	if (0 == pid) {
		// child
		close(fd[0]);
		for (i = 0; i < 100; i++)
			printf("i=%d\n", i);
		write(fd[1], "finish", 100);
		exit(0);
	}
	else {
		// father
		close(fd[1]);
		while(1) {
			count=read(fd[0], buf, 100);
			if (count > 0) {
				buf[count] = '\0';
				break;
			}
		}
		printf("father receive: %s\n", buf);
	}


}










