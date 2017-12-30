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
		printf("pid = %d, parent pid = %d\n", getpid(), getppid());
		sleep(5);
        }
	else  {
		
		printf("In father process: pid = %d\n", getpid());
		wait(NULL);
		printf("father 2222\n");
        }
	/*
	for (; n>0; n--) {
		printf("%s", msg);
		//usleep(1000);
	}
	*/	
	return 0;

}
