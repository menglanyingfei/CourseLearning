#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	pid_t pid;
	char* msg;
	int n;
	pid = fork();
	if (pid < 0) {
		msg = "fork fail!!!";
		printf(msg);
		return 1;
	}
	else if (pid == 0) {
		
		printf("I AM CHILD 111111111111, pid=%d\n", getpid());
		n = 6;
		sleep(20);
		execl("/home/jkx/mytest", "mytest", NULL);
                printf(msg);
		printf("I AM CHILD 2222222222\n");
		//printf("pid = %d, parent pid = %d\n", getpid(), getppid());
        }
	else  {
		//sleep(1);
                msg = "i am father\n";
                n = 3;
                printf(msg);
		printf("pid = %d\n", getpid());
        }
	/*
	for (; n>0; n--) {
		printf("%s", msg);
		//usleep(1000);
	}
	*/	
	return 0;

}
