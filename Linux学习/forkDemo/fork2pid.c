#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	pid_t pid1, pid2;
	pid1 = fork();	
	// child1
	if (pid1 == 0) {
		printf("I am child1, pid = %d, ppid = %d\n", getpid(), getppid());
		//sleep(5);
		exit(1); // return 5;
	} 
	// father
	else {
		pid2 = fork();
		if (pid2 == 0) {		
			printf("I am child2, pid = %d, ppid = %d\n", getpid(), getppid());
			sleep(5);
			printf("child2 sleep 5 second finish\n");
			exit(2);
		} else {
			int stat_val;
			printf("I am father, pid = %d\n", getpid());
			waitpid(pid1, &stat_val, 0);
			if (WIFEXITED(stat_val))
				printf("child1 exited with code %d\n", WEXITSTATUS(stat_val));
			int stat_val1;
			waitpid(pid2, &stat_val1, WNOHANG);
			if (WIFEXITED(stat_val1))
				printf("child2 exited with code %d\n", WEXITSTATUS(stat_val1));
		}
	}
	
	
	return 0;

}




